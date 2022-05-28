#ifndef DLNODE_H
#define DLNODE_H
#include<iostream>

using namespace std;
/* 
   ***************************
   *     NODO FOR DL LIST    *
   ***************************
*/

template<class T>
class DLNode{
   private:
    T val;
    DLNode<T>* prev;
    DLNode<T>* next;
    
   public:
    DLNode(T v) : val(v), prev(nullptr), next(nullptr) { }

    DLNode(T v, DLNode<T>* p, DLNode<T>* n) : val(v), prev(p), next(n) { }
    
    DLNode<T>* getPrev() const { return this->prev; }    
    DLNode<T>* getNext() const { return this->next; }

    friend ostream& operator<<(ostream& out, const DLNode<T>& DLnode){
         out << "DLnode@" << &DLnode << ", value = " << DLnode.val << ", prev = " << DLnode.prev << ", next = " << DLnode.next;
         return out;
    }

    template<typename U> //dobbiamo indicare che lista è classe template, metto tipo
    friend class DLList;   //U perchè altrimenti farebbe conflitto con tipo T
};

#endif