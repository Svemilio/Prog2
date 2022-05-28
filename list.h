#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include "node.h"
using namespace std;

/* 
   ***************************
   *          LISTA          *
   ***************************
*/

//LISTA LINKATA SEMPLICE
template<class T>
class List{
   protected: 
    Node<T>* head;
   private:
    Node<T>* tail;
    int counter = 0;
   public:
    List() { head = nullptr; tail = nullptr;}
     
    List(Node<T>* h) : head(h), tail(h) { }

    List(Node<T>* h, Node<T>* t) : head(h), tail(t) { }
    
    int getCounter() const{ return this->counter; }
    
    Node<T>* getHead() const { return this->head; }
    
    bool isEmpty() const { return (head == nullptr) && (tail == nullptr); }
    
    void insert(T val){ //inserimento lista vuota
        if(this->isEmpty()){
          head = new Node<T>(val);
          tail = head;
        }

        counter++;
    }

    void insertHead(T val){
        if(this->isEmpty()){
            this->insert(val);
            return;
        }
        
        Node<T>* temp = new Node<T>(val); //creo nodo
        temp->next = head;  //imposto il successivo dell nodo alla vecchia testa
        this->head = temp;  //aggiorno la testa della lista col nuovo nodo
        
        counter++;
    }
    
    void insertTail(T val){
        if(this->isEmpty()){
            this->insert(val);
            return;
        }
        
        /* SENZA PUNTATORE A CODA
        Node<T>* ptr = this->head; //scorro tutta la lista partendo dalla testa
        while(ptr->getNext() != nullptr) //mi fermo all'ultimo nodo
         ptr = ptr->getNext(); 
        
        Node<T>* temp = new Node<T>(val); //creo nuovo nodo
        ptr->next = temp; //imposto il successivo dell'ultimo elemento al nuovo nodo
        */

        // CON PUNTATORE A CODA
        Node<T>* temp = new Node<T>(val); //creo nuovo nodo
        tail->next = temp; //imposto il successivo dell'ultimo elemento al nuovo nodo
        tail = temp; //aggiorno la coda

        counter++;
    }
    
    void insertAscending(T val){
        if(val <= head->val){
           this->insertHead(val);
           return; 
        }

        Node<T>* ptr = head;
        while(ptr->getNext() && (val >= ptr->val)){
           if(val <= ptr->getNext()->val)
            break;
           
           ptr = ptr->getNext();
        }

        if(!ptr->next){
            this->insertTail(val);
            return;
        }

        Node<T>* toInsert = new Node<T>(val);
        toInsert->next = ptr->next;
        ptr->next = toInsert;
        
        counter++;
    }
    
    void insertDescending(T val){
        if(val >= head->val){
           this->insertHead(val);
           return; 
        }

        Node<T>* ptr = head;
        while(ptr->getNext() && (val <= ptr->val)){
           if(val >= ptr->getNext()->val)
            break;
           
           ptr = ptr->getNext();
        }

        if(!ptr->next){
            this->insertTail(val);
            return;
        }

        Node<T>* toInsert = new Node<T>(val);
        toInsert->next = ptr->next;
        ptr->next = toInsert;
        
        counter++;
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
         std::cerr << "ERROR, NOT A TIPE OF SORTING" << "\n\n";
    }

    void removeHead(){
        if(this->isEmpty()){
            std::cout << "EMPTY LIST!" << std::endl;
            return;
        }
        
        Node<T>* temp = head;
        
        if(head == tail){
            tail = nullptr;
        }
        
        head = head->next; //se ho solo nodo head, allora head->next ritorna nullptr
        
        delete temp;

        counter--;
    }
    
    void remove(T val){
         if(this->isEmpty()){
            std::cout << "EMPTY LIST!" << std::endl;
            return;
        }
    
        if(head->val == val) {
            this->removeHead();
            return;
        }

        Node<T>* cur = head; //current
        Node<T>* prev = nullptr; //previous
        while(cur->next && cur->val != val) {
                prev = cur;
                cur = cur->next;
        }

        if(cur == tail && cur->val == val){ //se l'elemento cercato è la coda
            this->removeTail();
            return;
        }
        else if(!(cur->next) && cur->val != val) {
            std::cerr << "Element with value " << val << " not found!" << "\n\n";
            return;
        }

        prev->next = cur->next; //eliminazione elemento (il nodo precedente punta al
                                //successivo dell'elemento corrente)
        delete cur;

        counter--;
    }

    void removeTail(){
        if(this->isEmpty()){
            std::cout << "EMPTY LIST!" << std::endl;
            return;
        }
        
        //anche se abbiamo puntatore a coda siamo costretti a scorrere tutta la lista
        //perchè ci serve il nodo precedente
        Node<T>* cur = head; //current
        Node<T>* prev = nullptr; //previous
        
        if(head == tail){
            head = nullptr;
            tail = nullptr;
        }
        else{
            while(cur->next){
                prev = cur;
                cur = cur->next;
            }

            prev->next = nullptr;
            tail = prev; //aggiorna la coda
        }

        delete cur; 

        counter--;              
    }
    
    Node<T>* operator[](int index){
         if(this->isEmpty()){
           std::cerr << "ERROR, List EMPTY!\n\n"; 
           return nullptr;
         }
         
         if(index >= this->getCounter()){
          std::cerr << "ERROR, ELEMENT AT POS " << index << " DOESN'T EXIST!" << "\n\n";
          return nullptr;
         }
         else if(index == this->getCounter() - 1){ //se l'elemento cercato è la coda
             return tail;
         }

        int count = 0; 
        Node<T>* ptr = head;
        while(ptr->getNext() && count < index){
           ptr = ptr->getNext();
           count++;
        }
        
        return ptr;
    } 

    friend std::ostream& operator<<(std::ostream& out, const List<T> &list){
         if(!list.isEmpty()){
            out << "List head = " << list.head << ", List tail = " << list.tail 
                << ", number of elements = " << list.getCounter() << " --->" << std::endl; 
            Node<T>* ptr = list.head;
            while(ptr != nullptr){
                out << "\t [ " << *ptr << " ]" << std::endl; //stampa info nodo
                ptr = ptr->getNext();
            }
         }
         else{
            out << "List EMPTY!" << std::endl;
         }

         return out;
    }
};

/*Le differenze sostanziali tra la lista con puntatore alla coda (LCPC) e senza puntatore 
  alla coda (LSPC) sono:
   - nell'inserimento in coda in LSPC dobbiamo scorrere tutta la lista [O(n)], mentre in LCPC
     l'operazione è istantanea [O(1)];
   - qualche riga di codice in più nella versione LCPC.

  
*/

#endif