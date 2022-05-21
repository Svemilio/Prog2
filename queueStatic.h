#ifndef STATIC_QUEUE
#define STATIC_QUEUE
#define MAX_SIZE 1000
#include<iostream>

using namespace std;

template<typename T>
class StaticQueue
{
    T* array;
    int size=0;
    int maxSize= MAX_SIZE;
    int head=-1;
    int tail=-1;

    public:
        StaticQueue(int maxsize): maxSize(maxsize)
        {
            this->array=new T[maxSize];
        }
        void enqueue(T val)
        {
            if(size==maxSize)
            {
                cout<<" queue is full"<<endl;
                return;
            }
            if(head==-1)
                head=0;

            array[++tail%maxSize]=val;
            size++;
        }

        T dequeue()
        {
            if(size==0)
            {
                cout<<"queue is empty"<<endl;
                return -1;
            }
            T val=array[head];
            return array[++head%maxSize];
            size--;
            return val;
        }
        friend ostream& operator<<(ostream& out,StaticQueue<T>& queue)
        {
            if(queue.size==0)
            {
                out<<"queue is empty"<<endl;
            }
            out<<"static queue-size "<<queue.size<<", maxsize-"<<queue.maxSize<<endl;
            for(int i=queue.head, count=0;count<queue.size;count++)
            {
                out<<queue.array[i]<<endl;
                i=(1+i)%queue.maxSize;
            }
            return out;
        }
};

#endif