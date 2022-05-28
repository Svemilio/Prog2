#ifndef NODE_H
#define NODE_H

using namespace std;
/* 
   ***************************
   *          NODO           *
   ***************************
*/

template<class T>
class Node{
   private:
    T val;
    Node<T>* next;
   public:
    Node(T v) : val(v), next(nullptr) { }

    Node(T v, Node<T>* n) : val(v), next(n) { }
    
    Node<T>* getNext() const { return this->next; }
    
    friend std::ostream& operator<<(std::ostream& out, const Node<T>& node){
         out << "node@" << &node << ", value = " << node.val << ", next = " << node.next;
         return out;
    }

    template<typename U> //dobbiamo indicare che lista è classe template, metto tipo
    friend class List;   //U perchè altrimenti farebbe conflitto con tipo T
};

#endif