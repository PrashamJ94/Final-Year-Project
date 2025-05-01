#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node{
    int val;
    struct Node* next;
} Node;

typedef struct LinkedList{
    Node* head;
} LinkedList;

typedef struct FastScanner{
    FILE* stream;
    char buffer[1024];
    int ptr;
    int buflen;
} FastScanner;

void LinkedList_init(LinkedList* list){
    list->head = NULL;
}

void LinkedList_add(LinkedList* list, int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = list->head;
    list->head = newNode;
}

int* counter;
LinkedList* graph;

void dfs(int v, int par, long val){
    Node* current = graph[v].head;
    while(current != NULL){
        if(current->val != par){
            dfs(current->val, v, val + counter[v]);
        }
        current = current->next;
    }
    counter[v] += val;
}

bool hasNextByte(FastScanner* fs){
    if(fs->ptr < fs->buflen){
        return true;
    }else{
        fs->ptr = 0;
        fs->buflen = fread(fs->buffer, 1, 1024, fs->stream);
        if(fs->buflen <= 0){
            return false;
        }
    }
    return true;
}

int readByte(FastScanner* fs){
    if(hasNextByte(fs)) return fs->buffer[fs->ptr++];
    else return -1;
}

bool isPrintableChar(int c){
    return 33<=c && c<=126;
}

bool hasNext(FastScanner* fs){
    while(hasNextByte(fs) && !isPrintableChar(fs->buffer[fs->ptr])) fs->ptr++;
    return hasNextByte(fs);
}

int nextInt(FastScanner* fs){
    if(!hasNext(fs)) return -1;
    int n = 0;
    bool minus = false;
    int b = readByte(fs);
    if(b == '-'){
        minus = true;
        b = readByte(fs);
    }
    if(b < '0' || '9' < b){
        return -1;
    }
    while(true){
        if('0' <= b && b<='9'){
            n*=10;
            n+=b-'0';
        }else if(b==-1 || !isPrintableChar(b)){
            return minus ? -n : n;
        }else{
            return -1;
        }
        b = readByte(fs);
    }
}

int main(){
    FastScanner fs;
    fs.stream = stdin;
    fs.ptr = 0;
    fs.buflen = 0;

    int n = nextInt(&fs);
    int q = nextInt(&fs);
    graph = (LinkedList*)malloc(n * sizeof(LinkedList));

    for(int i=0;i<n;i++) LinkedList_init(&graph[i]);

    counter = (int*)malloc(n * sizeof(int));
    memset(counter, 0, n * sizeof(int));
    int a, b;
    for(int i=0;i<n-1;i++){
        a = nextInt(&fs)-1;
        b = nextInt(&fs)-1;
        LinkedList_add(&graph[a], b);
        LinkedList_add(&graph[b], a);
    }
    for(int i=0;i<q;i++){
        counter[nextInt(&fs)-1]+=nextInt(&fs);
    }
    dfs(0, -1, 0);

    for(int i=0;i<n;i++){
        printf("%d ", counter[i]);
    }
    printf("\n");

    for(int i=0; i<n; i++){
        Node* current = graph[i].head;
        Node* tmp;
        while (current != NULL){
            tmp = current;
            current = current->next;
            free(tmp);
        }
    }
    free(graph);
    free(counter);

    return 0;
}
// 
