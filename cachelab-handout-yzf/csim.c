#include "cachelab.h"
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#define MAGIC_LRU_NUM 999
typedef struct{
    int valid;       //有效位
    int tag;          //标识位
    int LruNumber;   //LRU算法需要位
} Line;

typedef struct{
    Line* lines;    //一组中所有的行
} Set;

typedef struct {
    int set_num;    //组数
    int line_num;   //行数
    Set* sets;      //模拟cache
} Sim_Cache;

void printHelpMenu();                                                                       //打印Help帮助文档
void checkOptarg(char *curOptarg);                                                          //检查参数是否非法，初步检测是否是‘-’开头参数
int get_Opt(int argc,char **argv,int *s,int *E,int *b,char *tracefileName,int *isVerbose);  //读取用户输入参数
void init_SimCache(int s,int E,int b,Sim_Cache *cache);                                     //初始化模拟缓存
int getSet(int addr,int s,int b);                                                           //得到组号
int getTag(int addr,int s,int b);                                                           //得到标记

void loadData(Sim_Cache *sim_cache,int addr,int size,int setBits,int tagBits ,int isVerbose);                                                          //得到标记号
void storeData(Sim_Cache *sim_cache,int addr,int size,int setBits,int tagBits ,int isVerbose);                                                          //得到标记号
void modifyData(Sim_Cache *sim_cache,int addr,int size,int setBits,int tagBits ,int isVerbose);                                                          //得到标记号

int misses;
int hits;
int evictions;
int main(int argc,char **argv){
    int s,E,b,isVerbose=0;
    char tracefileName[100],opt[10];

    int addr,size;
    misses = hits = evictions =0;

    Sim_Cache cache;

    get_Opt(argc,argv,&s,&E,&b,tracefileName,&isVerbose);
    init_SimCache(s,E,b,&cache);
    FILE *tracefile = fopen(tracefileName,"r");

    while(fscanf(tracefile,"%s %x,%d",opt,&addr,&size) != EOF){
        if(strcmp(opt,"I")==0)continue;
        int setBits = getSet(addr,s,b);
        int tagBits = getTag(addr,s,b);
//        printf("----------------------------------\n");
//        printf("setBits:%x  tagBits:%x\n",setBits,tagBits);
        if(isVerbose == 1) printf("%s %x,%d ",opt,addr,size);
        if(strcmp(opt,"S")==0) {
            storeData(&cache,addr,size,setBits,tagBits,isVerbose);
        }
        if(strcmp(opt,"M")==0) {
            modifyData(&cache,addr,size,setBits,tagBits,isVerbose);
        }
        if(strcmp(opt,"L")==0) {
            loadData(&cache,addr,size,setBits,tagBits,isVerbose);
        }
        if(isVerbose == 1) printf("\n");
    }
    printSummary(hits,misses,evictions);
    return 0;
}

/*获取地址中的组号*/
int getSet(int addr,int s,int b){
    addr = addr >> b;
    int mask =  (1<<s)-1;
    return addr &mask;
}

/*获取地址中的标识号*/
int getTag(int addr,int s,int b){
    int mask = s+b;
    return addr >> mask;
}

/*查找某组中当前最小的LruNumber行，作为牺牲行 */
int findMinLruNumber(Sim_Cache *sim_cache,int setBits){
    int i;
    int minIndex=0;
    int minLru = MAGIC_LRU_NUM;
    for(i=0;i<sim_cache->line_num;i++){
        if(sim_cache->sets[setBits].lines[i].LruNumber < minLru){
            minIndex = i;
            minLru = sim_cache->sets[setBits].lines[i].LruNumber;
        }
    }
    return minIndex;
}

/*更新Lru，hit的为最大的MAGIC_LRU_NUM,其他LRU均减一*/
void updateLruNumber(Sim_Cache *sim_cache,int setBits,int hitIndex){
        sim_cache->sets[setBits].lines[hitIndex].LruNumber = MAGIC_LRU_NUM;
        int j;
        for(j=0;j<sim_cache->line_num;j++){//更新其他行的LruNumber
            if(j!=hitIndex) sim_cache->sets[setBits].lines[j].LruNumber--;
        }
}

/*判断是否命中*/
int isMiss(Sim_Cache *sim_cache,int setBits,int tagBits){
    int i;
    int isMiss = 1;
    for(i=0;i<sim_cache->line_num;i++){
        if(sim_cache->sets[setBits].lines[i].valid == 1 && sim_cache->sets[setBits].lines[i].tag == tagBits){
            isMiss = 0;
            updateLruNumber(sim_cache,setBits,i);
        }
    }
    return isMiss;
}

/*更新内存数据*/
int updateCache(Sim_Cache *sim_cache,int setBits,int tagBits){
    int i;
    int isfull = 1;
    for(i=0;i<sim_cache->line_num;i++){
        if(sim_cache->sets[setBits].lines[i].valid == 0){
            isfull = 0; //该组未满
            break;
        }
    }
    if(isfull == 0){
        sim_cache->sets[setBits].lines[i].valid = 1;
        sim_cache->sets[setBits].lines[i].tag = tagBits;
        updateLruNumber(sim_cache,setBits,i);
    }else{
        //组已经满，需要牺牲行
        int evictionIndex = findMinLruNumber(sim_cache,setBits);
        sim_cache->sets[setBits].lines[evictionIndex].valid = 1;
        sim_cache->sets[setBits].lines[evictionIndex].tag = tagBits;
        updateLruNumber(sim_cache,setBits,evictionIndex);
    }
    return isfull;
}

void loadData(Sim_Cache *sim_cache,int addr,int size,int setBits,int tagBits ,int isVerbose){

    if(isMiss(sim_cache,setBits,tagBits)==1){ //没有命中
        misses++;
        if(isVerbose == 1) printf("miss ");
        if(updateCache(sim_cache,setBits,tagBits) == 1){//该组已满，需要牺牲行
            evictions++;
            if(isVerbose==1) printf("eviction ");
        }
    }else{ //命中
       hits++;
       if(isVerbose == 1) printf("hit ");
    }
}

void storeData(Sim_Cache *sim_cache,int addr,int size,int setBits,int tagBits ,int isVerbose){
    loadData(sim_cache,addr,size,setBits,tagBits,isVerbose);
}

void modifyData(Sim_Cache *sim_cache,int addr,int size,int setBits,int tagBits ,int isVerbose){
    loadData(sim_cache,addr,size,setBits,tagBits,isVerbose);
    storeData(sim_cache,addr,size,setBits,tagBits,isVerbose);
}
/*初始化模拟内存*/
void init_SimCache(int s,int E,int b,Sim_Cache *cache){
    if(s < 0){
        printf("invaild cache sets number\n!");
        exit(0);
    }
    cache->set_num = 2 << s; //2^s 组
    cache->line_num = E;
    cache->sets = (Set *)malloc(cache->set_num * sizeof(Set));
    if(!cache->sets){
        printf("Set Memory error\n");
        exit(0);
    }
    int i ,j;
    for(i=0; i< cache->set_num; i++)
    {
        cache->sets[i].lines = (Line *)malloc(E*sizeof(Line));
        if(!cache->sets){
            printf("Line Memory error\n");
            exit(0);
        }
        for(j=0; j < E; j++){
            cache->sets[i].lines[j].valid = 0;
            cache->sets[i].lines[j].LruNumber = 0;
        }
    }
    return ;
}
/*分析输入参数*/
int get_Opt(int argc,char **argv,int *s,int *E,int *b,char *tracefileName,int *isVerbose){
    int c;
    while((c = getopt(argc,argv,"hvs:E:b:t:"))!=-1)
    {
        switch(c)
        {
        case 'v':
            *isVerbose = 1;
            break;
        case 's':
            checkOptarg(optarg);
            *s = atoi(optarg);
            break;
        case 'E':
            checkOptarg(optarg);
            *E = atoi(optarg);
            break;
        case 'b':
            checkOptarg(optarg);
            *b = atoi(optarg);
            break;
        case 't':
            checkOptarg(optarg);
            strcpy(tracefileName,optarg);
            break;
        case 'h':
        default:
            printHelpMenu();
            exit(0);
        }
    }
    return 1;
}
/*打印帮助文档*/
void printHelpMenu(){
    printf("Usage: ./csim-ref [-hv] -s <num> -E <num> -b <num> -t <file>\n");
    printf("Options:\n");
    printf("-h         Print this help message.\n");
    printf("-v         Optional verbose flag.\n");
    printf("-s <num>   Number of set index bits.\n");
    printf("-E <num>   Number of lines per set.\n");
    printf("-b <num>   Number of block offset bits.\n");
    printf("-t <file>  Trace file.\n\n\n");
    printf("Examples:\n");
    printf("linux>  ./csim -s 4 -E 1 -b 4 -t traces/yi.trace\n");
    printf("linux>  ./csim -v -s 8 -E 2 -b 4 -t traces/yi.trace\n");
}
/*检查参数合法性*/
void checkOptarg(char *curOptarg){
    if(curOptarg[0]=='-'){
        printf("./csim :Missing required command line argument\n");
        printHelpMenu();
        exit(0);
    }
}

