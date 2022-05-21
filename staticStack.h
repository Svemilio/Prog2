#ifndef STATIC_STACK_H
#define STATIC_STACK_H

#include<iostream>

using namespace std;

template<typename T>
class StaticStack
{
    T* array;
    int top=-1;
    int size=0;
    int maxSize=-1;

    public:
        StaticStack(int _maxSize):maxSize(_maxSize)
        {
            array=new T[maxSize];
        }

        T GetTop()
        {
            if(isEmpty())
                return -1;
            return array[top];
        }

        void push(T val)
        {
            if(top==maxSize-1)
                return;
            this->array[++top]=val;
        }

        T pop()
        {
            if(isEmpty())
                return -1;
            return array[top--]; //ritorno top e lo decremento
        }

        bool isEmpty()
        {
            return top==-1;
        }

        friend ostream& operator<<(ostream& out,StaticStack<T> s)
        {
            out<<"StaticStack: maxSize= "<<s.maxSize<<endl;
            out<<"---------------"<<endl;
            for(int i=s.top;i>=0;i--)
            {
                out<<s.array[i]<<"-"<<endl;
            }
            return out;
        }
};

//la complessita delle operazioni potrebbe dipendere da come implementiamo le cose
//push -> O(1);
//pop -> O(1);
//top -> O(1);

#endif
