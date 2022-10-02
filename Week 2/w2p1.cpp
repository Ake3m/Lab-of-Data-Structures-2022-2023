#include <iostream>

using namespace std; 
/**
 * A Node class of Doublely Linked List class
 */
template<class T>
class Node {
  public:

  /**
   * Construct a new Node object with no parameter
   */
  Node() {
    prev=NULL;
    next=NULL;
  }

  /**
   * Construct a new Node object with parameter
   * @param data: data to put in
   */
  Node(T d) {
    prev=NULL;
    next=NULL;
    data=d;
  }

  /**
   * Construct a new Node object with parameters
   * @param data: data to put in
   * @param prev: pointer to the previous node
   * @param next: pointer to the next node
   */
  Node(T d, Node<T> *p, Node<T> *n) {
    data=d;
    prev=p;
    next=n;
  }

  Node<T>* getPrev()
  {
    return prev;
  }

  Node<T>* getNext()
  {
    return next;
  }

  T getData()
  {
    return data;
  }

  void setPrev(Node<T> *pv)
  {
    prev=pv;
  }

  void setNext(Node<T> *nx)
  {
    next=nx;
  }

  void setData(T d)
  {
    data=d;
  }

  private: 
    Node<T> *prev;
    Node<T> *next;
    T data;
};

/**
 * A Doublely Linked List class
 */
template<class T>
class LinkedList {
  public:

  /**
   * Construct a new LinkedList object with no parameter
   */
  LinkedList() {
    head=NULL;
    tail=NULL;
  }

  /**
   * Add a node to the tail of the linked list
   * @param data: data to put in
   */
  void addToTail(T data) {
    Node<T> *temp=new Node<T>(data);
    if(head==NULL)
    {
        head=temp;
        tail=temp;
    }
    else{
        tail->setNext(temp);
        temp->setPrev(tail);
        tail=temp;
    }
  }

  /**
   * Add a node to the head of the linked list
   * @param data: data to put in
   */
  void addToHead(T data) {
     Node<T> *temp=new Node<T>(data);
    if(head==NULL)
    {
        head=temp;
        tail=temp;
    }
    else{
        temp->setNext(head);
        head->setPrev(temp);
        head=temp;
    }
  }

  /**
   * Delete a node from the linked list with the given data from the head
   * If there are no data to be deleted, then do nothing
   * @param data: data to delete
   */
  void deleteData(T data) {
    Node<T> *curr=head;
    while(curr)
    {
        if(curr->getData()==data)
        {
            if(curr==head)
            {
                head=curr->getNext();
                curr->setNext(0);
                curr->setPrev(0);
            }
            else if(curr==tail){
                tail=curr->getPrev();
                curr->setPrev(0);
            }
            else
            {
                curr->getPrev()->setNext(curr->getNext());
                curr->getNext()->setPrev(curr->getPrev());
                curr->setNext(0);
                curr->setPrev(0);
            }
            break;
        }
        curr=curr->getNext();
    }
  }

  /**
   * Delete valid n nodes from the linked list with the given data from the head
   * If there are no more data to be deleted, then just skip
   * @param data: data to delete
   * @param n: max number of nodes to delete
   */
  void deleteData(T data, int n) {
    {
        for(int i=0;i<n;i++)
        {
            deleteData(data);
        }
    }
  } 

  /**
   * Overload the operator << to print out all the data in the linked list from the head
   * There is a \n in the end of each print
   * 
   * Output example: 
   * If your linked list data is 5, 4, 3, 2, 1
   * then you should print out "(5, 4, 3, 2, 1)" with the content in quotes but without the quotes
   */
  friend std::ostream &operator<<(std::ostream &out, LinkedList * n) {
    Node<T> *curr=n->head;
    out<<"(";
    while(curr!=NULL)
    {
        if(curr->getNext()==NULL)
        {
            out<<curr->getData();
        }
        else
        {
            out<<curr->getData()<<", ";
        }
        curr=curr->getNext();
    }
    out<<")"<<endl;
    return out;
  }

  private: 
    Node<T> *head;
    Node<T> *tail;
};