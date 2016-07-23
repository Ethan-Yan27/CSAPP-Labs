/*
 *  segragated free list +  best fit + improved realloc function
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

#define WSIZE 4                     /*word size*/
#define DSIZE 8                     /*Double word size*/
#define CHUNKSIZE (1<<12)           /*the page size in bytes is 4K*/
#define MINFB_SIZE 2

#define MAX(x,y)    ((x)>(y)?(x):(y))

/* Pack a size and allocated bit into a word */
#define PACK(size,alloc)    ((size) | (alloc))

/* Read the size and allocated fields from address p */
#define GET(p)  (*(unsigned int *)(p))              /*get value of 4 sizes memory */
#define PUT(p,val)  (*(unsigned int *)(p) = (val))  /*put val into 4 sizes memory */


/* Read the size and allocated fields from address p */
#define GET_SIZE(p)  (GET(p) & ~0x7)      /*size of block*/
#define GET_ALLOC(p)    (GET(p) & 0x1)    /*block is alloc?*/

/* Given block ptr bp, compute address of its header and footer */
#define HDRP(bp)    ((char *)(bp)-WSIZE)                    /*head of block*/
#define FTRP(bp)    ((char *)(bp)+GET_SIZE(HDRP(bp))-DSIZE) /*foot of block*/

/*Given free block ptr bp ,compute addredss of next ane previous free block */
#define PREV_LINKNODE_RP(bp) ((char*)(bp))          /*prev free block*/
#define NEXT_LINKNODE_RP(bp) ((char*)(bp)+WSIZE)    /*next free block*/
/* Given block ptr bp, compute address of next and previous blocks */
#define NEXT_BLKP(bp)   ((char *)(bp)+GET_SIZE(((char *)(bp)-WSIZE))) /*next block*/
#define PREV_BLKP(bp)   ((char *)(bp)-GET_SIZE(((char *)(bp)-DSIZE))) /*prev block*/


static void *extend_heap(size_t dwords);
static void *coalesce(void *bp);
static void *find_fit(size_t size);
static void place(void *bp,size_t asize);
/*inline function*/
void insert_free_block(char *p);
void remove_free_block(char *p);
char *get_freeCategory_root(size_t size);

/*aux function for mm_realloc*/
static void *realloc_coalesce(void *bp,size_t newSize,int *isNextFree);
static void realloc_place(void *bp,size_t asize);

static char *heap_listp = NULL;
static char *block_list_start = NULL;


/*********************************************************
 * Auxiliary Function 
 ********************************************************/
 /*
 *	get_freeCategory_root - get the free list category fit the given size
 */
inline char *get_freeCategory_root(size_t size)
{
    int i = 0;
    if(size<=8) i=0;
    else if(size<=16) i= 0;
    else if(size<=32) i= 0;
    else if(size<=64) i= 1;
    else if(size<=128) i= 2;
    else if(size<=256) i= 3;
    else if(size<=512) i= 4;
    else if(size<=2048) i= 5;
    else if(size<=4096) i= 6;
    else i= 7;
    /*find the index of bin which will put this block */
    return block_list_start+(i*WSIZE);
}
/*
 *extend_heap - Extend heap with free block and return its block pointer.
 */
static void *extend_heap(size_t dwords)
{
    char *bp;
    size_t size;

    size = (dwords % 2) ? (dwords+1) * DSIZE : dwords * DSIZE; /*compute the size fit the 16 bytes alignment*/

    if((long)(bp = mem_sbrk(size))==(void *)-1)		/*move the brk pointer for bigger heap*/
        return NULL;

    /*init the head and foot fields*/
    PUT(HDRP(bp),PACK(size,0));
    PUT(FTRP(bp),PACK(size,0));

    /*init the prev and next free pointer fields*/
    PUT(NEXT_LINKNODE_RP(bp),NULL);
    PUT(PREV_LINKNODE_RP(bp),NULL);

    /*the  epilogue header*/
    PUT(HDRP(NEXT_BLKP(bp)),PACK(0,1));

    return coalesce(bp);
}
/*
*coalesce - Boundary tag coalescing. Return ptr to coalesced block
*/
static void *coalesce(void *bp)
{
    size_t  prev_alloc = GET_ALLOC(FTRP(PREV_BLKP(bp)));
    size_t  next_alloc = GET_ALLOC(HDRP(NEXT_BLKP(bp)));
    size_t size = GET_SIZE(HDRP(bp));


    /*coalesce the block and change the point*/
    if(prev_alloc && next_alloc){		//case1
    }
    else if(prev_alloc && !next_alloc)  //case2
    {
        size += GET_SIZE(HDRP(NEXT_BLKP(bp)));
        remove_free_block(NEXT_BLKP(bp)); /*remove the next free block from the free list */
        PUT(HDRP(bp), PACK(size,0));
        PUT(FTRP(bp), PACK(size,0));
    }
    else if(!prev_alloc && next_alloc)	//case 3
    {
        size += GET_SIZE(HDRP(PREV_BLKP(bp)));
        remove_free_block(PREV_BLKP(bp)); /*remove the prev free block from the free list */
        PUT(FTRP(bp),PACK(size,0));
        PUT(HDRP(PREV_BLKP(bp)),PACK(size,0));
        bp = PREV_BLKP(bp);
    }
    else	//case 4
    {
        size +=GET_SIZE(FTRP(NEXT_BLKP(bp)))+ GET_SIZE(HDRP(PREV_BLKP(bp)));
        remove_free_block(PREV_BLKP(bp));
        remove_free_block(NEXT_BLKP(bp));
        PUT(FTRP(NEXT_BLKP(bp)),PACK(size,0));
        PUT(HDRP(PREV_BLKP(bp)),PACK(size,0));
        bp = PREV_BLKP(bp);
    }
    /*insert the new free block*/
    insert_free_block(bp);
    return bp;
}
/*
*insert_free_block - insert the free point into segragated free list.
*	In each category the free list is ordered by the free size for small to big.
*   When find a fit free block ,just find for begin to end ,the first fit one is the best fit one.
*/
inline void insert_free_block(char *p)
{
    char *root = get_freeCategory_root(GET_SIZE(HDRP(p)));
    char *prevp = root;
    char *nextp = GET(root);

    /*find the postion to insert, smaller < p < bigger*/
    while(nextp!=NULL){
        if(GET_SIZE(HDRP(nextp))>=GET_SIZE(HDRP(p))) break;
        prevp = nextp;
        nextp = GET(NEXT_LINKNODE_RP(nextp));
    }
    /*insert*/
    if(prevp == root){
        PUT(root,p);
        PUT(NEXT_LINKNODE_RP(p),nextp);
        PUT(PREV_LINKNODE_RP(p),NULL);
        if(nextp!=NULL) PUT(PREV_LINKNODE_RP(nextp),p);
    }else{
        PUT(NEXT_LINKNODE_RP(prevp),p);
        PUT(PREV_LINKNODE_RP(p),prevp);
        PUT(NEXT_LINKNODE_RP(p),nextp);
        if(nextp!=NULL) PUT(PREV_LINKNODE_RP(nextp),p);
    }

}
/*
*remove_free_block - remove the free point from segragated free list.
*/
inline void remove_free_block(char *p)
{
    char *root = get_freeCategory_root(GET_SIZE(HDRP(p)));
    char *prevp = GET(PREV_LINKNODE_RP(p));
    char *nextp = GET(NEXT_LINKNODE_RP(p));

    if(prevp == NULL){
        if(nextp != NULL)PUT(PREV_LINKNODE_RP(nextp),0);
        PUT(root,nextp);
    }
    else{
        if(nextp != NULL)PUT(PREV_LINKNODE_RP(nextp),prevp);
        PUT(NEXT_LINKNODE_RP(prevp),nextp);
    }
    /*set the next and prev pointers to NULL*/
    PUT(NEXT_LINKNODE_RP(p),NULL);
    PUT(PREV_LINKNODE_RP(p),NULL);
}
/* 
 * find_fit - Find a fit for a block with asize bytes .(best fit alogrithm)
 *       	  Because the free list is order by size, so find the first fit one is the same as the best fit one.
 */
static void *find_fit(size_t size)
{
    
    char *root = get_freeCategory_root(size);
    char *tmpP = GET(root);
    for(root; root!=(heap_listp-(2*WSIZE)); root+=WSIZE)
    {
        char *tmpP = GET(root);
        while(tmpP != NULL)
        {
            if(GET_SIZE(HDRP(tmpP))>=size) return tmpP;
            tmpP = GET(NEXT_LINKNODE_RP(tmpP));
        }
    }
    return NULL;
}
/* 
 * place - Place block of asize bytes at start of free block bp 
 *         and split if remainder would be at least minimum block size
 */
static void place(void *bp,size_t asize)
{
    size_t csize = GET_SIZE(HDRP(bp));
    remove_free_block(bp);/*remove from empty_list*/
    if((csize-asize)>=(MINFB_SIZE*DSIZE))
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

/*
 * mm_init - initialize the malloc package.
 * The return value should be -1 if there was a problem in performing the initialization, 0 otherwise
 */
int mm_init(void)
{
    if((heap_listp = mem_sbrk(12*WSIZE))==(void *)-1) return -1;

    PUT(heap_listp,0);              /*block size list<=32*/
    PUT(heap_listp+(1*WSIZE),0);    /*block size list<=64*/
    PUT(heap_listp+(2*WSIZE),0);    /*block size list<=128*/
    PUT(heap_listp+(3*WSIZE),0);    /*block size list<=256*/
    PUT(heap_listp+(4*WSIZE),0);    /*block size list<=512*/
    PUT(heap_listp+(5*WSIZE),0);    /*block size list<=2048*/
    PUT(heap_listp+(6*WSIZE),0);    /*block size list<=4096*/
    PUT(heap_listp+(7*WSIZE),0);    /*block size list>4096*/
    PUT(heap_listp+(8*WSIZE),0);	/* for alignment*/
    PUT(heap_listp+(9*WSIZE),PACK(DSIZE,1));
    PUT(heap_listp+(10*WSIZE),PACK(DSIZE,1));
    PUT(heap_listp+(11*WSIZE),PACK(0,1));

    block_list_start = heap_listp;
    heap_listp += (10*WSIZE);

    if((extend_heap(CHUNKSIZE/DSIZE))==NULL) return -1;

    return 0;
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

    if(size <= DSIZE){
        asize = 2*(DSIZE);
    }else{
        asize = (DSIZE)*((size+(DSIZE)+(DSIZE-1)) / (DSIZE));
    }
    
    if((bp = find_fit(asize))!= NULL){
        place(bp,asize);
        return bp;
    }

    /*apply new block*/
    extendsize = MAX(asize,CHUNKSIZE);
    if((bp = extend_heap(extendsize/DSIZE))==NULL){
        return NULL;
    }
    place(bp,asize);
    return bp;
}

/*
 * mm_free - Freeing a block does nothing.
 */
void mm_free(void *bp){

    if(bp == 0)
        return;
    size_t size = GET_SIZE(HDRP(bp));

    PUT(HDRP(bp), PACK(size, 0));
    PUT(FTRP(bp), PACK(size, 0));
    PUT(NEXT_LINKNODE_RP(bp),NULL);
    PUT(PREV_LINKNODE_RP(bp),NULL);
    coalesce(bp);
}

/*
 * mm_realloc 
 * 1. Given size is equal to 0 ,just free the given ptr
 * 2. Given ptr is equal to NULL ,just new malloc a space which size is given size
 * 
 * 3. oldsize is smaller than new size (asize),than call realloc_coalesce to coalesce the previous and next free block, 
 *    if realloc_coalesce success ,just move the payload into new address.
 *    if not success, mm_alloc a new space.
 *
 * 4.oldsize is bigger than new size (asize),just call realloc_place to change the size of ptr.
 */
void *mm_realloc(void *ptr, size_t size){
    size_t oldsize = GET_SIZE(HDRP(ptr));
    void *newptr;
    size_t asize;

    if(size == 0){
        mm_free(ptr);
        return 0;
    }

    if(ptr == NULL) return mm_malloc(size);

    /*compute the total size,which contanins header + footer + payload and fit the alignment requirement*/
    if(size <= DSIZE){
        asize = 2*(DSIZE);
    }else{
        asize = (DSIZE)*((size+(DSIZE)+(DSIZE-1)) / (DSIZE));
    }

    if(oldsize==asize) return ptr;

    if(oldsize<asize)
    {
        int isnextFree;
        char *bp = realloc_coalesce(ptr,asize,&isnextFree);
        if( isnextFree==1){ /*next block is free*/
            realloc_place(bp,asize);
            return bp;
        } else if(isnextFree ==0 && bp != ptr){ /*previous block is free, move the point to new address,and move the payload*/
            memcpy(bp, ptr, size);
            realloc_place(bp,asize);
            return bp;
        }else{
     	/*realloc_coalesce is fail*/
            newptr = mm_malloc(size);
            memcpy(newptr, ptr, size);
            mm_free(ptr);
            return newptr;
        }
    }
    else
    {/*just change the size of ptr*/
        realloc_place(ptr,asize);
        return ptr;
    }
}
/*********************************************************
 * Auxiliary Function for mm_realloc 
 ********************************************************/
static void realloc_place(void *bp,size_t asize)
{
    size_t csize = GET_SIZE(HDRP(bp));
   /*improve the utils for realloc-bal.rep and realloc2-bal.rep, so i comment it*/
   // if((csize-asize)>=(MINFB_SIZE*DSIZE))
   // {
   //     PUT(HDRP(bp),PACK(asize,1));
   //     PUT(FTRP(bp),PACK(asize,1));
   //     bp = NEXT_BLKP(bp);
   //     PUT(HDRP(bp),PACK(csize-asize,0));
   //     PUT(FTRP(bp),PACK(csize-asize,0));
   //     PUT(NEXT_LINKNODE_RP(bp),0);
   //     PUT(PREV_LINKNODE_RP(bp),0);
   //     coalesce(bp);
   // }
   // else
   // {
   //      PUT(HDRP(bp),PACK(csize,1));
   //      PUT(FTRP(bp),PACK(csize,1));
   // }

   PUT(HDRP(bp),PACK(csize,1));
   PUT(FTRP(bp),PACK(csize,1));
}
static void *realloc_coalesce(void *bp,size_t newSize,int *isNextFree)
{
    size_t  prev_alloc = GET_ALLOC(FTRP(PREV_BLKP(bp)));
    size_t  next_alloc = GET_ALLOC(HDRP(NEXT_BLKP(bp)));
    size_t size = GET_SIZE(HDRP(bp));
    *isNextFree = 0;
    /*coalesce the block and change the point*/
    if(prev_alloc && next_alloc)
    {

    }
    else if(prev_alloc && !next_alloc)
    {
        size += GET_SIZE(HDRP(NEXT_BLKP(bp)));
        if(size>=newSize)
        {
            remove_free_block(NEXT_BLKP(bp));
            PUT(HDRP(bp), PACK(size,1));
            PUT(FTRP(bp), PACK(size,1));
            *isNextFree = 1;
            return bp;
        }
    }
    else if(!prev_alloc && next_alloc)
    {
        size += GET_SIZE(HDRP(PREV_BLKP(bp)));
        if(size>=newSize)
        {
            remove_free_block(PREV_BLKP(bp));
            PUT(FTRP(bp),PACK(size,1));
            PUT(HDRP(PREV_BLKP(bp)),PACK(size,1));
            bp = PREV_BLKP(bp);
            return bp;
        }

    }
    else
    {
        size +=GET_SIZE(FTRP(NEXT_BLKP(bp)))+ GET_SIZE(HDRP(PREV_BLKP(bp)));
        if(size>=newSize)
        {
            remove_free_block(PREV_BLKP(bp));
            remove_free_block(NEXT_BLKP(bp));
            PUT(FTRP(NEXT_BLKP(bp)),PACK(size,1));
            PUT(HDRP(PREV_BLKP(bp)),PACK(size,1));
            bp = PREV_BLKP(bp);
        }

    }
    return bp;
}


/*********************************************************
 * END--Auxiliary Function for mm_realloc 
 ********************************************************/

int mm_check(char *function)
{
//    printf("---cur function:%s empty blocks:\n",function);
//    char *tmpP = GET(root);
//    int count_empty_block = 0;
//    while(tmpP != NULL)
//    {
//        count_empty_block++;
//        printf("address：%x size:%d \n",tmpP,GET_SIZE(HDRP(tmpP)));
//        tmpP = GET(NEXT_LINKNODE_RP(tmpP));
//    }
//    printf("empty_block num: %d\n",count_empty_block);
}

