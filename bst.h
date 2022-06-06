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
        //fare a casa inserimento pre order e post order.
        BSTNode<T>* min()
        {
            if(isEmpty())
            {
                return NULL;
            }
            BSTNode<T>* node=root;
            while(node->left)
            {
                node=node->left;
            }
            return node;
        }
        BSTNode<T>* max()
        {
            if(isEmpty())
            {
                return NULL;
            }
            BSTNode<T>* node=root;
            while(node->rigth)
            {
                node=node->rigth;
            }
            return node;
        }
};

#endif