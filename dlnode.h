#ifndef DLNODE_H
#define DLNODE_H
#include<iostream>

using namespace std;

template<typename T>
class DLNode
{
    T val;
    DLNode<T> *next;
    DLNode<T> *prev;

    template<typename U>
    friend class DLList;

    public:
        DLNode(T val):val(val), next(nullptr),prev(nullptr){}
        DLNode<T>* getNext() const {return this->next;}
        DLNode<T>* getPrev() const {return this->prev;}
        friend ostream& operator<<(ostream& out,const DLNode<T> &node) //metto friend per accedere ai campi privati di node
        {
            out<<"node val="<<node.val<<"- next="<<node.next;  //operatore di redirezione dell'output.
            return out;
        }

};

#endif
