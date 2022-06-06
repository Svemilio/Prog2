#ifndef BST_H
#define BST_H
#include "bstNode.h"
#include<iostream>

template<typename T>
class BST
{
    BSTNode<T>* root;

    public:
        BST()
        {
            root= nullptr;
        }
        bool isEmpty()
        {
            return root==nullptr;
        }
        void insert(T val)
        {
            if(this->isEmpty())
            {
                root= new BSTNode<T>(key);
                return;
            }
            insert(root,key);
            

        }
        //la mia procedura ricorsiva deve avere due parametri 
        //il valore da inserire e la radice del sottoalbero
        //corregere queso metodo insert!!!!!!!!
        //scrivere anche la parte dove inseriamo il parent
        void insert(BSTNode<T>* ptr,T key)
        {
            if(ptr==nullptr)
                ptr=new BSTNode<T>(key);
            else if(key<=ptr->key)
                insert(ptr->left,key);
            else
                insert(ptr->rigth,key);
        }
        void visit(BSTNode<T>* node)
        {
            str::cout<<*node <<std::endl;
        }
        void inorder(BSTNode<T>* ptr)
        {
            if(ptr==nullptr)
                return;
            inorder(ptr->left);
            visit(ptr);
            inorder(ptr->rigth);
        }
        void inorder()
        {
            inorder(root);
        }
        BSTNode<T>* min()
        {
            return min(this->root);
        }
        //fare a casa inserimento pre order e post order.
        BSTNode<T>* min(BSTNode<T>* from)
        {
            if(isEmpty())
            {
                return NULL;
            }
            BSTNode<T>* from=root;
            while(from->left)
            {
                from=from->left;
            }
            return from;
        }

        BSTNode<T>* max(BSTNode<T>* from)
        {
            if(isEmpty())
            {
                return NULL;
            }
            BSTNode<T>* from=root;
            while(from->rigth)
            {
                from=from->rigth;
            }
            return from;
        }

        BSTNode<T>* max()
        {
            return max(this->root);
        }

        BSTNode<T>* successore(BSTNode<T>* x)
        {
            if(this->isEmpty())
                return nullptr;
            
            if(x==max())
                return nullptr;
            //primo caso x ha un sottoalbero destro.
            if(x->rigth)
                return this->min(x->rigth);
            //secondo caso x non ha un sottoalbero destro
            //il successore di x è l'antenato piu prossimo di x
            //il cui figlio sinistro è un antenato di x;
            BSTNode<T>* y=x->parent;
            while(x!=nullptr && x==y->rigth)
            {
                x=y;
                y=y->parent;
            }

            return y;
        }

        BSTNode<T>* predecessore(BSTNode<T>* x)
        {
            if(x==min())
                return nullptr;
            if(this->isEmpty())
                return nullptr;
            
            if(x->left)
                return this->max(x->left);

            BSTNode<T>* y=x->parent;
            while(x!=nullptr && x==y->left)
            {
                x=y;
                y=y->parent;
            }
            return y;
        }
        BSTNode<T>* search(T key)
        {
            return search(root,key);
        }
        BSTNode<T>* search(BSTNode<T>* ptr,T key)
        {
            if(ptr==nullptr)
                return nullptr;
            if(ptr->key==key)
                return ptr;
            if(key<=ptr->key)
                return search(ptr->left,key);
            else
                return search(ptr->rigth,key);

            return nullptr;

        }
};

#endif