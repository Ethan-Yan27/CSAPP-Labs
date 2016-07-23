/*
 * mm-naive.c - The fastest, least memory-efficient malloc package.
 *
 * In this naive approach, a block is allocated by simply incrementing
 * the brk pointer.  A block is pure payload. There are no headers or
 * footers.  Blocks are never coalesced or reused. Realloc is
 * implemented directly using mm_malloc and mm_free.
 *
 * NOTE TO STUDENTS: Replace this header comment with your own header
 * comment that gives a high level description of your solution.
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>

#include "mm.h"
#include "memlib.h"

/*********************************************************
 * NOTE TO STUDENTS: Before you do anything else, please
 * provide your team information in the following struct.
 ********************************************************/
team_t team =
{
    /* Team name */
    "XXXXXX",
    /* First member's full name */
    "yzf",
    /* First member's email address */
    "@Fd",
    /* Second member's full name (leave blank if none) */
    "",
    /* Second member's email address (leave blank if none) */
    ""
};

/* single word (4) or double word (8) alignment */
#define ALIGNMENT 8

/* rounds up to the nearest multiple of ALIGNMENT */
#define ALIGN(size) (((size) + (ALIGNMENT-1)) & ~0x7)


#define SIZE_T_SIZE (ALIGN(sizeof(size_t)))

#define WSIZE 4
#define DSIZE 8           /*Double word size*/
#define CHUNKSIZE (1<<12) /*the page size in bytes is 4K*/

#define MAX(x,y)    ((x)>(y)?(x):(y))

#define PACK(size,alloc)    ((size) | (alloc))

#define GET(p)  (*(unsigned int *)(p))
#define PUT(p,val)  (*(unsigned int *)(p) = (val))

#define GET_SIZE(p)  (GET(p) & ~0x7)
#define GET_ALLOC(p)    (GET(p) & 0x1)

#define HDRP(bp)    ((char *)(bp)-WSIZE)
#define FTRP(bp)    ((char *)(bp)+GET_SIZE(HDRP(bp))-DSIZE)

#define PREV_LINKNODE_RP(bp) ((char*)(bp))
#define NEXT_LINKNODE_RP(bp) ((char*)(bp)+WSIZE)

#define NEXT_BLKP(bp)   ((char *)(bp)+GET_SIZE(((char *)(bp)-WSIZE)))
#define PREV_BLKP(bp)   ((char *)(bp)-GET_SIZE(((char *)(bp)-DSIZE)))


int mm_check(char *function);
static void *extend_heap(size_t dwords);
static void *coalesce(void *bp);
static void *find_fit(size_t size);
static void place(void *bp,size_t asize);
void insert_to_Emptylist(char *p);
void fix_linklist(char *p);
static char *heap_listp = NULL;
static char *root = NULL;

/*
 * mm_init - initialize the malloc package.
 * The return value should be -1 if there was a problem in performing the initialization, 0 otherwise
 */
int mm_init(void)
{
    if((heap_listp = mem_sbrk(6*WSIZE))==(void *)-1) return -1;

    PUT(heap_listp,0);
    PUT(heap_listp+(1*WSIZE),0);
    PUT(heap_listp+(2*WSIZE),0);
    PUT(heap_listp+(3*WSIZE),PACK(DSIZE,1));
    PUT(heap_listp+(4*WSIZE),PACK(DSIZE,1));
    PUT(heap_listp+(5*WSIZE),PACK(0,1));
    root = heap_listp + (1*WSIZE);

    heap_listp += (4*WSIZE);

    if((extend_heap(CHUNKSIZE/DSIZE))==NULL) return -1;
#ifdef DEBUG
    mm_check(__FUNCTION__);
#endif // DEBUG
    return 0;
}
/*最小Block4字（16字节）*/
static void *extend_heap(size_t dwords)
{
    char *bp;
    size_t size;

    size = (dwords % 2) ? (dwords+1) * DSIZE : dwords * DSIZE;

    if((long)(bp = mem_sbrk(size))==(void *)-1)
        return NULL;

    PUT(HDRP(bp),PACK(size,0));
    PUT(FTRP(bp),PACK(size,0));
    PUT(NEXT_LINKNODE_RP(bp),0);
    PUT(PREV_LINKNODE_RP(bp),0);

    PUT(HDRP(NEXT_BLKP(bp)),PACK(0,1));

    return coalesce(bp);
}
/*
 * mm_malloc - Allocate a block by incrementing the brk pointer.
 *     Always allocate a block whose size is a multiple of the alignment.
 */
void *mm_malloc(size_t size)
{
    size_t asize;
    size_t extendsize;
    char *bp;
    if(size ==0) return NULL;

    if(size <= DSIZE)
    {
        asize = 2*(DSIZE);
    }
    else
    {
        asize = (DSIZE)*((size+(DSIZE)+(DSIZE-1)) / (DSIZE));
    }
    if((bp = find_fit(asize))!= NULL)
    {
        place(bp,asize);
#ifdef DEBUG
        mm_check(__FUNCTION__);
#endif // DEBUG
        return bp;
    }

    /*apply new block*/
    extendsize = MAX(asize,CHUNKSIZE);
    if((bp = extend_heap(extendsize/DSIZE))==NULL)
    {
        return NULL;
    }
    place(bp,asize);
#ifdef DEBUG
    mm_check(__FUNCTION__);
#endif // DEBUG
    return bp;
}

/*
 * mm_free - Freeing a block does nothing.
 */
void mm_free(void *bp)
{
    /* $end mmfree */
    if(bp == 0)
        return;

    /* $begin mmfree */
    size_t size = GET_SIZE(HDRP(bp));
    /* $end mmfree */

    /* $begin mmfree */

    PUT(HDRP(bp), PACK(size, 0));
    PUT(FTRP(bp), PACK(size, 0));
    PUT(NEXT_LINKNODE_RP(bp),0);
    PUT(PREV_LINKNODE_RP(bp),0);
    coalesce(bp);
#ifdef DEBUG
    mm_check(__FUNCTION__);
#endif // DEBUG
}
/*
 * mm_realloc - Implemented simply in terms of mm_malloc and mm_free
 */
void *mm_realloc(void *ptr, size_t size)
{
    size_t oldsize;
    void *newptr;

    /* If size == 0 then this is just free, and we return NULL. */
    if(size == 0)
    {
        mm_free(ptr);
        return 0;
    }

    /* If oldptr is NULL, then this is just malloc. */
    if(ptr == NULL)
    {
        return mm_malloc(size);
    }
    oldsize = GET_SIZE(HDRP(ptr));

    newptr = mm_malloc(size);

    /* If realloc() fails the original block is left untouched  */
    if(!newptr)
    {
        return 0;
    }

    /* Copy the old data. */
    oldsize = GET_SIZE(HDRP(ptr));
    if(size < oldsize) oldsize = size;
    memcpy(newptr, ptr, oldsize);

    /* Free the old block. */
    mm_free(ptr);

    return newptr;
}

/*coalesce the empty block*/
static void *coalesce(void *bp)
{
    size_t  prev_alloc = GET_ALLOC(FTRP(PREV_BLKP(bp)));
    size_t  next_alloc = GET_ALLOC(HDRP(NEXT_BLKP(bp)));
    size_t size = GET_SIZE(HDRP(bp));

    /*coalesce the block and change the point*/
    if(prev_alloc && next_alloc)
    {

    }
    else if(prev_alloc && !next_alloc)
    {
        size += GET_SIZE(HDRP(NEXT_BLKP(bp)));
        fix_linklist(NEXT_BLKP(bp));/*remove from empty list*/
        PUT(HDRP(bp), PACK(size,0));
        PUT(FTRP(bp), PACK(size,0));
    }
    else if(!prev_alloc && next_alloc)
    {
        size += GET_SIZE(HDRP(PREV_BLKP(bp)));
        fix_linklist(PREV_BLKP(bp));
        PUT(FTRP(bp),PACK(size,0));
        PUT(HDRP(PREV_BLKP(bp)),PACK(size,0));
        bp = PREV_BLKP(bp);
    }
    else
    {
        size +=GET_SIZE(FTRP(NEXT_BLKP(bp)))+ GET_SIZE(HDRP(PREV_BLKP(bp)));
        fix_linklist(PREV_BLKP(bp));
        fix_linklist(NEXT_BLKP(bp));
        PUT(FTRP(NEXT_BLKP(bp)),PACK(size,0));
        PUT(HDRP(PREV_BLKP(bp)),PACK(size,0));
        bp = PREV_BLKP(bp);
    }
    insert_to_Emptylist(bp);
    return bp;
}
inline void insert_to_Emptylist(char *p)
{
    /*p will be insert into the linklist ,LIFO*/
    char *nextp = GET(root);
    if(nextp != NULL)
        PUT(PREV_LINKNODE_RP(nextp),p);

    PUT(NEXT_LINKNODE_RP(p),nextp);
//    PUT(PREV_LINKNODE_RP(p),root);
    PUT(root,p);
}
inline void fix_linklist(char *p)
{
    char *prevp = GET(PREV_LINKNODE_RP(p));
    char *nextp = GET(NEXT_LINKNODE_RP(p));
    if(prevp == NULL)
    {
        if(nextp != NULL)PUT(PREV_LINKNODE_RP(nextp),0);
        PUT(root,nextp);
    }
    else
    {
        if(nextp != NULL)PUT(PREV_LINKNODE_RP(nextp),prevp);
        PUT(NEXT_LINKNODE_RP(prevp),nextp);
    }
    PUT(NEXT_LINKNODE_RP(p),0);
    PUT(PREV_LINKNODE_RP(p),0);
}
static void *find_fit(size_t size)
{
    /*first fit*/
    char *tmpP = GET(root);
    while(tmpP != NULL)
    {
        if(GET_SIZE(HDRP(tmpP))>=size) return tmpP;
        tmpP = GET(NEXT_LINKNODE_RP(tmpP));
    }
    return NULL;\

}

static void place(void *bp,size_t asize)
{
    size_t csize = GET_SIZE(HDRP(bp));
    fix_linklist(bp);/*remove from empty_list*/
    if((csize-asize)>=(2*DSIZE))
    {
        PUT(HDRP(bp),PACK(asize,1));
        PUT(FTRP(bp),PACK(asize,1));
        bp = NEXT_BLKP(bp);

        PUT(HDRP(bp),PACK(csize-asize,0));
        PUT(FTRP(bp),PACK(csize-asize,0));
        PUT(NEXT_LINKNODE_RP(bp),0);
        PUT(PREV_LINKNODE_RP(bp),0);
        coalesce(bp);
    }
    else
    {
        PUT(HDRP(bp),PACK(csize,1));
        PUT(FTRP(bp),PACK(csize,1));
    }
}
int mm_check(char *function)
{
    printf("---cur function:%s empty blocks:\n",function);
    char *tmpP = GET(root);
    int count_empty_block = 0;
    while(tmpP != NULL)
    {
        count_empty_block++;
        printf("address：%x size:%d \n",tmpP,GET_SIZE(HDRP(tmpP)));
        tmpP = GET(NEXT_LINKNODE_RP(tmpP));
    }
    printf("empty_block num: %d\n",count_empty_block);
}




