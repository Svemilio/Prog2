#include<iostream>

using namespace std;

template<typename T>
class Node
{
    T val;
    Node<T>* next;
    template<typename U>
    friend class List;  //per poter accedere ai suoi memebri privati e naturalmente devo metterla template.
    public:
        Node(T val):val(val)
        {
            this->next=nullptr;
        }
        friend ostream& operator<<(ostream& out,const Node<T> &node) //metto friend per accedere ai campi privati di node
        {
            out<<"node val="<<node.val<<"- next="<<node.next;  //operatore di redirezione dell'output.
            return out;
        }
        Node<T>* getNext()const {return this->next;}  //mettendo const li diciamo che è un valore immodificabile
};
