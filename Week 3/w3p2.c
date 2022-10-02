#include <stdio.h>
#include <stdlib.h>



struct Node
{
    int data;
    struct Node *prev, *next;
};
int isEmpty(struct Node *queue);
int front(struct Node *queue);
/*
    function initLinkList will initialize the head of a linked list.
    parameter head represent the head of a linked list.
*/
void initLinkList(struct Node **head)
{
    *(head)=0;
}
/*
    function addToHead will insert a node which hold data into linked list from head of the linked list.
    parameter head represent the head of a linked list.
    parameter data represent the data to insert.
*/
void addToHead(struct Node **head, int data)
{
    struct Node *temp=(struct Node*) malloc (sizeof(struct Node));
    temp->data=data;
    temp->next=*head;
    temp->prev=0;
    if(*head!=0){
        (*head)->prev=temp;
    }
    *(head)=temp;
    
}
/*
    function addToHead will insert a node which hold data into linked list from tail of the linked list.
    parameter head represent the head of a linked list.
    parameter data represent the data to insert.
*/
void addToTail(struct Node **head, int data)
{
    if(*head==0)
    {
        addToHead(head, data);
    }
    else{
        struct Node *temp=(struct Node*) malloc (sizeof(struct Node));
        temp->data=data;
        struct Node* curr=*head;
        while(curr)
        {
            if(curr->next==0)
            {
                curr->next=temp;
                temp->prev=curr;
                temp->next=0;
                break;
            }
            curr=curr->next;
        }
    }
    

}
/*
    function deleteData will search from head to find the first node which hold the data and remove it.
    parameter head represent the head of a linked list.
    parameter data represent the data to be search.
*/
void deleteData(struct Node **head, int data)
{
    struct Node* curr=*head;
    if((*head)->next==0)
    {
        free(curr);
        *head=0;
    }
    while(curr)
    {
        if(curr->data==data)
        {
            if(curr==*head)
            {
                *head=curr->next;
                (*head)->prev=0;
            }
            else if(curr->next==0)
            {
                curr->prev->next=0;
            }
            else{
                curr->prev->next=curr->next;
                curr->next->prev=curr->prev;
            }
            free(curr);
            break;
        }
        curr=curr->next;
    }
}
/*
    function deleteData will search from head to find the first n node which hold the data and remove it.
    parameter head represent the head of a linked list.
    parameter data represent the data to be search.
    parameter n represent the max number of node to be removed.
*/
void deleteDatas(struct Node **head, int data, int n)
{
    for(int i=0;i<n;i++)
    {
        deleteData(head, data);
    }
}
/*
    function display will print out all the data in the linked list from the head
    there is a \n in the end of each print
    output example:
    if your linked list data is 5, 4, 3, 2, 1
    then you should print out "(5, 4, 3, 2, 1)" with the content in quotes but without the quotes
    parameter head represent the head of a linked list.
*/
void display(struct Node *head)
{
    printf("(");
    struct Node *curr=head;
    while(curr)
    {
        if(curr->next==0)
        {
            printf("%d)", curr->data);
        }
        else{
            printf("%d, ", curr->data);
        }
        curr=curr->next;
    }
    printf("\n");
}


   /* function enqueue will insert a data into queue
    parameter queue represent the queue
    parameter data represent the data to be insert
*/
void enqueue(struct Node **queue, int data)
{
    addToTail(queue, data);
}
/*
    function dequeue will remove a data from queue
    parameter queue represent the queue
    this function should return the data that be removed
*/
int dequeue(struct Node **queue)
{
    if(isEmpty(*queue)==1)
    {
        return 0;
    }
    else{
        int val=front(*queue);
        deleteData(queue,val);
        return val;
    }
}
/*
    function front will give the next remove data in the given queue
    parameter queue represent the queue
    this function should return the next remove data
*/
int front(struct Node *queue)
{
    return queue->data;
}
/*
    function isEmpty will determine if the given queue is empty or not
    parameter queue represent the queue
    this function should return 1 if the given queue is empty, 0 if not
*/
int isEmpty(struct Node *queue)
{
    if(queue==0)
        return 1;
    else
        return 0;
}

//APPEND BEGIN
int main() {
  struct Node *queue;

  initLinkList(&queue);

  enqueue(&queue, 1);
  enqueue(&queue, 2);
  enqueue(&queue, 3);
  enqueue(&queue, 4);
  enqueue(&queue, 5);
  display(queue);
  printf("%d", dequeue(&queue));
  printf("%d", front(queue));
  printf("%d", dequeue(&queue));
  printf("%d", dequeue(&queue));
  printf("%d", dequeue(&queue));
  printf("%d", dequeue(&queue));

  return 0;
}