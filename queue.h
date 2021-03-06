#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
#include "DLList.h"

/* 
   ***************************
   *         QUEUE           *
   ***************************
*/
using namespace std;

template <typename T>
class Queue : protected DLList<T>{
     private:
      int size = 0;
     public: 
      Queue() : DLList<T>() { }
      
      bool isEmpty() const{  return size == 0; }

      void enqueue(T val){
          DLList<T>::insertTail(val);
          size++;
      }

      DLNode<T> dequeue(){
          if(this->isEmpty()){
                cout << "EMPTY QUEUE!" <<endl <<endl;
            return 0;
          }
          
          DLNode<T> ptr = *(this->head);
          DLList<T>::removeHead();
          size--;
          return ptr;
      }
      
      friend ostream& operator <<(ostream& out, const Queue<T>& q){
         //out << (DLList<T>)q; //cast per chiamare overload di superclasse
         
         if(!q.isEmpty()){
            out << "Queue head = " << q.head << ", Queue tail = " << q.tail 
                << ", size = " << q.size << " ---->" <<endl;

            DLNode<T>* ptr = q.head;
            while(ptr != nullptr){
                out << "\t [ " << *ptr << " ]" <<endl; //stampa info nodo
                ptr = ptr->getNext();
            }
         }
         else{
            out << "Queue EMPTY!" <<endl;
         }

         return out;
     }
      
};


#endif