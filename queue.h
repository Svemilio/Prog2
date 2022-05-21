////////////utilizziamo una struttura dati che già conosciamo.
#ifndef QUEUE_H
#define QUEUE_H
#include "dllist.h"
#include<iostream>

using namespace std;

template<typename T>
class Queue: protected DLList<T>
{
    protected:
        int size=0;

    public:
        Queue():DLList<T>()
        {

        }
        bool isEmpty()
        {
            return size==0;
        }
        void Enqueue(T val)
        {
            DLList<T>::insertTail(val);
        }
        DLNode<T>* Dequeue()
        {
            if(isEmpty())
                return 0;

            DLNode<T>* ptr=*(DLList<T>::head);
            DLList<T>::removeHead();
            size--;
            return ptr;
        }
        friend operator<<(ostream& out,Queue<T> queue)
        {
            out<<"queue starting at "<< &(queue.head);
            DLNode<T> *ptr=queue.head;
            while(ptr)
            {
                out<<*ptr<<endl;
                ptr=ptr->getNext();
            }
            return out;
        }
};

#endif
