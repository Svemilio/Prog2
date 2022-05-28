#ifndef DLLIST_H
#define DLLIST_H

#include <iostream>
#include <string>
#include "DLNode.h"

using namespace std;

/* 
   ***************************
   *        DL LIST          *
   ***************************
*/

//LISTA DOPPIAMENTE LINKATA 
template<class T>
class DLList{
   protected:
    DLNode<T>* head;
    DLNode<T>* tail;
   public:
    DLList() { head = nullptr; tail = nullptr; }

    DLList(DLNode<T>* h) : head(h), tail(h) { }
     
    DLList(DLNode<T>* h, DLNode<T>* t) : head(h), tail(t)  { }
    
    bool isEmpty() const { return (head == nullptr) && (tail == nullptr); }
    
    
    void insert(T val){
        if(this->isEmpty()){
          head = new DLNode<T>(val);
          tail = head;
        }
    }

    void insertHead(T val){
        if(this->isEmpty()){
            this->insert(val);
            return;
        }

        DLNode<T>* toInsert = new DLNode<T>(val); // creo nodo
        toInsert->next = head;  //imposto il successivo dell nodo alla vecchia testa
        head->prev = toInsert;  //imposto il precedente della vecchia testa al nuovo nodo
        head = toInsert; //aggiorno la testa della lista col nuovo nodo
    }
    
    void insertTail(T val){
        if(this->isEmpty()){
            this->insertHead(val);
            return;
        }
        
        DLNode<T>* toInsert = new DLNode<T>(val); //creo nuovo nodo
        toInsert->prev = tail; //imposto il precedente del nodo alla vecchia coda
        tail->next = toInsert; //imposto il successivo della vecchia coda al nuovo nodo
        tail = toInsert; //aggiorno la coda
    }
    
     void insertAscending(T val){
        if(val <= head->val){
           this->insertHead(val);
           return; 
        }

        DLNode<T>* ptr = head;
        while(ptr->getNext() && (val >= ptr->val)){
           if(val <= ptr->getNext()->val)
            break;
           
           ptr = ptr->getNext();
        }

        if(!ptr->next){
            this->insertTail(val);
            return;
        }

        DLNode<T>* toInsert = new DLNode<T>(val);
        ptr->prev->next = toInsert; //imposto il successivo del nodo precedente al new nodo
        toInsert->prev = ptr->prev; //imposto il prec del new nodo al prec del nodo corrent
        ptr->prev = toInsert; //imposto il precedente del nodo corrente al nuovo nodo
        toInsert->next = ptr; //imposto il successivo del nuovo nodo al nodo corrente
    }
    
    void insertDescending(T val){
        if(val >= head->val){
           this->insertHead(val);
           return; 
        }

        DLNode<T>* ptr = head;
        while(ptr->getNext() && (val <= ptr->val)){
           if(val >= ptr->getNext()->val)
            break;
           
           ptr = ptr->getNext();
        }

        if(!ptr->next){
            this->insertTail(val);
            return;
        }

        DLNode<T>* toInsert = new DLNode<T>(val);
        ptr->prev->next = toInsert; //imposto il successivo del nodo precedente al new nodo
        toInsert->prev = ptr->prev; //imposto il prec del new nodo al prec del nodo corrent
        ptr->prev = toInsert; //imposto il precedente del nodo corrente al nuovo nodo
        toInsert->next = ptr; //imposto il successivo del nuovo nodo al nodo corrente
    }

    void insertInOrder(T val, std::string choice){
        if(this->isEmpty()){
            this->insert(val);
            return;
        }
        
        if(choice == "Asc")
         this->insertAscending(val);
        else if(choice == "Desc")
         this->insertDescending(val);
        else
            cerr << "ERROR, NOT A TIPE OF SORTING" << "\n\n";
    }

    void removeHead(){
        if(this->isEmpty()){
            cout << "EMPTY LIST!" <<endl;
            return;
        }
        
        DLNode<T>* temp = head;

        if(head == tail){
           head = nullptr;
           tail = nullptr;       
        }
        else{
           temp->next->prev = nullptr; //imposto il precedente del nodo successivo 
                                       //alla vecchia testa a nullptr
           head = temp->next;  //aggiorno la testa
        }

        delete temp;
    }
    
    void remove(T val){
         if(this->isEmpty()){
            cout << "EMPTY LIST!" <<endl;
            return;
        }
        
        if(head->val == val) {
            this->removeHead();
            return;
        }

        DLNode<T> *cur = head;
        while(cur->next && cur->val != val)
          cur = cur->next;
        
        if(cur == tail && cur->val == val){ //se l'elemento cercato è la coda
            this->removeTail();
            return;
        }
        else if(!(cur->next) && cur->val != val) {
                cout << "Element with value " << val << " not found" << "\n\n";
                return;
        }
        
        cur->prev->next = cur->next; 
        cur->next->prev = cur->prev;
        
        delete cur;
    }
    
    void removeTail(){
        if(this->isEmpty()){
            cout << "EMPTY LIST!" <<endl;
            return;
        }
        
        DLNode<T>* temp = tail;

        if(head == tail){
           head = nullptr;
           tail = nullptr;      
        }
        else{
           temp->prev->next = nullptr;
           tail = temp->prev;
        }

         delete temp;
    }
    
    friend ostream& operator<<(ostream& out, const DLList<T> &DLList){
         if(!DLList.isEmpty()){
            out << "List head = " << DLList.head << ", List tail = " << DLList.tail <<endl; 
            DLNode<T>* ptr = DLList.head;
            while(ptr != nullptr){
                out << "\t [ " << *ptr << " ]" <<endl; //stampa info nodo
                ptr = ptr->getNext();
            }
         }
         else{
            out << "List EMPTY!" <<endl;
         }
         return out;
    }
};

#endif