#ifndef QUEUEADT_H_INCLUDED
#define QUEUEADT_H_INCLUDED



#endif // QUEUEADT_H_INCLUDED
struct node {
    char * task;
    struct node* next;
}typedef NODE;


struct node{
    char* grp;
    int hours;
    nodePrev* next;
}typedef nodePrev;

struct LinkedList{
   nodePrev* head;

}typedef prevList;

struct queue{
    NODE* front;
    NODE* rear;//rear eleman eklemek ,front elelman cikarmak icin kullanilir
}typedef QUEUE;

prevList* creatPrevList(){
    prevList* prevL=(prevList*)malloc(sizeof(prevList));
    if(!prevL){
        printf("Belleginiz prograöm olusturmak icin eterli degil\n");
        exit(1);
    }
    prevL->head=NULL;
    return prevList;
}
nodeprev* createNodeP(char* grp,int hours){
    nodePrev* nodeP=(nodePrev*)malloc(sizeof(nodePrev));
    if(!nodeP){
        printf("Belleginiz program olusturmak icin yeterli degil\n");
        exit(1);
    }
    strcpy(nodeP->grp,grp);
    nodeP->hours=hours;
    nodeP->next=NULL;
    return nodeP;
}

void addGrp(prevList* prevL,char* grp,int hour ){
    nodePrev* temp=prevL->head;
    nodePrev* prev=prevL->head;
    nodePrev* nodeP=createNodeP(grp,hour);
    while(temp!=NULL){
        if(hour>temp->hour){
            nodeP->next=temp;
            prev->next=nodeP;
        }
        prev=temp;
        temp=temp->next;
    }
}


NODE* createNODE(char* task,int key){
    //gorev olusturulur ve programa eklenir.
    NODE* newNode=(NODE*)malloc(sizeof(NODE));
    if(!newNode){
        printf("Program olusturmak icin belleginiz yeterli degil");
        exit(1);
    }
    strcpy(newNode->task,task);
    newNode->key=key;
    return newNode;
}

QUEUE* createQUEUE(){
    //pogram olusturur
    QUEUE* queue=(QUEUE*)malloc(sizeof(QUEUE));
    if(!queue){
        printf("Program olusturabilmek iicn belleginiz yeterli degil");
        exit(1);
    }
    queue->front=NULL;
    queue->rear=NULL;

    return queue;
}

void enqueue(QUEUE* queue,char task,int key){
    NODE* newNode=createNODE(task,key);
    if(!queue->rear){
        //eleman yok
        queue->rear=newNode;
        queue->front=newNode;
    }
    queue->rear->next=newNode;
    queue->rear=newNode;
}

void dequeue(QUEUE* queue){
    if(!queue->front){
        //tek eleman var
        free(queue->front);
        queue->front=NULL;
        queue->rear=NULL;
    }
    NODE* temp=queue->front;
    queue->front=temp->next;
    free(temp);

}


