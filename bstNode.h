#ifndef BST_NODE_H
#define BST_NODE_H

#include<iostream>

template<typename T>
class BSTNode
{
    protected:
        T key;
        BSTNode<T>* left;
        BSTNode<T>* rigth;

        template<typename U>
        friend class BST;
    public:
        BSTNode(T key) :key(key)
        {
            left=nullptr;
            rigth=nullptr;
        }

        void setLeft(BSTNode<T>* left)
        {
            this->left=left;
        }
         void setRigth(BSTNode<T>* left)
        {
            this->rigth=rigth;
        }
        BSTNode<T>* getRigth()
        {
            return this->rigth;
        }
        BSTNode<T>* getleft()
        {
            return this->left;
        }
        void setKey(T key)
        {
            this->key=key;
        }
        T getKey()
        {
            return this->key;
        }

        friend std::ostream& operator<<(std::ostream& out, BSTNode<T>& node)
        {
            out<<"BSTNode:"<< &node <<"-key "<< node.key<<"-left="<<node.left<<"-rigt="<<node.rigth;
            return out;
        }
        /*
        ~BSTNode()
        {
            delete left;
            delete rigth;
        }
        non fare perchè dichiarati in maniera statica
        */
};

#endif