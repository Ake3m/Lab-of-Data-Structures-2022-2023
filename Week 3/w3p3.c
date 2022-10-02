#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev, *next;
};
/*
    function initLinkList will initialize the head of a linked list.
    parameter head represent the head of a linked list.
*/
void initLinkList(struct Node **head)
{
    *head=NULL;
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
    temp->prev=NULL;
    if(*head!=NULL){
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
    struct Node *temp=(struct Node*) malloc (sizeof(struct Node));
    temp->data=data;
    struct Node* curr=*head;
    while(curr)
    {
        if(curr->next==NULL)
        {
            curr->next=temp;
            temp->prev=curr;
            temp->next=NULL;
        }
        curr=curr->next;
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
        if(curr->next==NULL)
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
/*
    function push will insert a data into stack
    parameter stack represent the stack
    parameter data represent the data to be insert
*/
void push(struct Node **stack, int data)
{
    addToHead(stack, data);
}
/*
    function dequeue will remove a data from stack
    parameter stack represent the stack
    this function should return the data that be removed
*/
int pop(struct Node **stack)
{
    if(isEmpty(*stack)==1)
    {
        return 0;
    }
    else
    {
        int val=top(*stack);
        deleteData(stack, val);
        return val;
    }
}
/*
    function top will give the next remove data in the given stack
    parameter stack represent the stack
    this function should return the next remove data
*/
int top(struct Node *stack)
{
    return stack->data;
}
/*
    function isEmpty will determine if the given stack is empty or not
    parameter stack represent the stack
    this function should return 1 if the given stack is empty, 0 if not
*/
int isEmpty(struct Node *stack)
{
    if(stack==NULL)
    {
        return 1;
    }
    else{
        return 0;
    }
}
/*
    function size will give the number of data in the given stack
    this function should return the number of data in the stack
*/
int size(struct Node *stack)
{
    int count=0;
    struct Node *curr=stack;
    while(curr)
    {
        count++;
        curr=curr->next;
    }
    return count;
}