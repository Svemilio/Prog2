#ifndef LIST_H
#define LIST_H
#include<iostream>
#include "node.h"

using namespace std;

template<typename T>
class List
{
    protected:
        Node<T>* head;
    private:
        short num_el;
    public:
        List(){
	    this->head=nullptr;
	    this->num_el=0;
        }
        bool isEmpty()
        {
            return head==nullptr;
        }
        void insert(T val)
        {
            if(this->isEmpty())
            {
                head=new Node<T>(val);
		        this->num_el++;
            }
        }
        void insertHead(T val)
        {
            if(this->isEmpty())
            {
                this->insert(val);
                return;
            }

            Node<T> *temp= new Node<T>(val);
	        this->num_el++;
            temp->next=head;
            this->head=temp;
        }
        Node<T> getHeand() const
        {
            return head;
        }
        void insertTail(T val)
        {
            if(this->isEmpty())
            {
                this->insertHead(val);
                return;
            }
            Node<T>* ptr=head;
            while(ptr->getNext()!=nullptr)
            {
                ptr=ptr->getNext();
            }
            Node<T>*temp=new Node<T>(val);
            ptr->next=temp;
	        this->num_el++;
        }
	short getNumEl()
	{
	    return this->num_el;
	}
	void insertInOrderAscendant(T val)
        {
            if(this->isEmpty())
            {
                this->insertHead(val);
                return;
            }
            if(val<= head->val)
            {
                this->insertHead(val);
                return;
            }
            Node<T> *ptr=head;
            while(ptr->getNext() && (val >= ptr->val))
            {
                if(val <= ptr->next->val)
                    break;
                ptr= ptr->getNext();
            }
            if(ptr->next==nullptr)
            {
                this->insertTail(val);
                return;
            }
            Node<T> *toInsert= new Node<T>(val);
            toInsert->next=ptr->next;
            ptr->next=toInsert;
	        this->num_el++;
        }
	void insertInOrderDescendant(T val)
        {
            if(this->isEmpty())
            {
                this->insertHead(val);
                return;
            }
            if(val>=head->val)
            {
                this->insertHead(val);
                return;
            }
            Node<T>* ptr=head;
            while(ptr->getNext() && (val<= ptr->val))
            {
                if(val>=ptr->next->val)
                    break;
                ptr=ptr->getNext();
            }
            if(ptr->next==nullptr)
            {
                this->insertTail(val);
                return;
            }
            Node<T>* toInsert= new Node<T>(val);
            toInsert->next=ptr->next;
            ptr->next=toInsert;
	        this->num_el++;
        }
	void removeHead()
        {
            if(this->isEmpty())
            {
                cout<<"empty list"<<endl;
                return;
            }
            Node<T> *temp= head;
            head= head->next;
	        this->num_el--;
            delete temp;
        }
	void removeTail()
        {
           if(this->isEmpty())
            {
                cout<<"empty list"<<endl;
                return;
            }
            Node<T> *cur=head;
            Node<T> *prev=nullptr;
            while(cur->next)
            {
                prev=cur;
                cur= cur->next;
            }
            prev->next=nullptr;
	        this->num_el--;
            delete cur;
        }
	void removeNode(T val)
        {
            if(this->isEmpty())
            {
                cout<<"empty list"<<endl;
                return;
            }
            if(head->val==val)
            {
                this->removeHead();
                return;
            }
            Node<T> *cur=head;
            Node<T> *prev=nullptr;
            while(cur->next && cur->val !=val)
            {
                prev=cur;
                cur=cur->next;
                
            }
            if(!(cur->next) && cur->val!= val)
            {
                cout<<"element not found!"<<endl;
                return;
            }
            prev->next=cur->next;
	        this->num_el--;
            delete cur;
        }
	int operator[](int a)
	{
	    if(a>this->num_el)
	    {
		cout<<"inalid input"<<endl;
		return -1;
	    }
	    Node<T>* ptr=head;
	    for(int i=0;i<a-1;i++)
	    {
		ptr=ptr->next;
	    }
	    return ptr->val;
	    
	}
        friend ostream& operator<<(ostream& out,const List<T> &list)
        {
            out<<"list head="<<list.head<<endl;
            Node<T> *ptr=list.head;
            while(ptr!=nullptr)
            {
                out<<"\t"<<*ptr<<endl;
                ptr=ptr->getNext();
            }
            return out;
        }
};

#endif

