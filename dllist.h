#ifndef DLLIST_H
#define DLLIST_H
#include "dlnode.h"
#include<iostream>

using namespace std;

template<typename T>
class DLList
{
    DLNode<T> *head;
    DLNode<T> *tail;

    public:
        DLList()
        {
            head= nullptr;
            tail= nullptr;
        }
        bool isEmpty()
        {
            return (head==nullptr)&&(tail==nullptr);
        }

        void insertHead()
        {
            if(this->isEmpty())
            {
                head= new DLNode<T>(val);
                tail=head;
                return;
            }
            DLNode<T> *toInsert= new DLNode<T>(val);
            toInsert->next=head;
            head->prev=toInsert;
            head=toInsert;
        }
        void insertTail()
        {
            if(this->isEmpty())
            {
                this->insertHead(val);
                return;
            }
            DLNode<T> *toInsert=new DLNode<T>(val);
            toInsert->prev=tail;
            tail->next=toInsert;
            tail=toInsert;
        }

        void removeHead()
        {
            if(this->isEmpty())
            {
                cout<<"is empty"<<endl;
                return;
            }
            if(head==tail)
            {
                DLNode<T>*ptr=head;
                head = nullptr;
                tail=nullptr;
                delete ptr;
            }
            DLNode<T>*ptr=head;
            ptr->next->prev=nullptr;
            head=ptr->next;

            delete ptr;
        }

        void removeTail()
        {
            if(this->isEmpty())
            {
                cout<<"is empty"<<endl;
                return;
            }
            if(head==tail)
            {
                DLNode<T>*ptr=head;
                head = nullptr;
                tail=nullptr;
                delete ptr;
            }
            DLNode<T> *ptr=tail;
            ptr->prev->next=nullptr;
            tail=ptr->prev;

            delete ptr;
        }

        //implementare inserimento ordinato e la cancellazione di un elemento dato un valore 
};

#endif
