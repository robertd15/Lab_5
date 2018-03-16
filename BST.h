#include "Person.h"

#include<iostream>

using namespace std;

template <class T>
class BST
{
    struct node
    {
        T data;
        node* left;
        node* right;
    };
    
    node* root;
    
    node* makeEmpty(node* t)
    {
        if (t == NULL)
            return NULL;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }
    
    node* insert(T x, node* t)
    {
        if (t == NULL)
        {
            t = new node;
            t->data = x;
            t->left = t->right = NULL;
        }
        
        else if (!isBirthday)
        {
            if (x < t->data)
                t->left = insert(x, t->left);
            else if (x > t->data)
                t->right = insert(x, t->right);
        }
        
        else if(isBirthday)
        {
            if (x.getBirthday() < t->data.getBirthday())
                t->left = insert(x, t->left);
            else if (x.getBirthday() > t->data.getBirthday())
                t->right = insert(x, t->right);
        }
        
        return t;
        
        /*if (t == NULL)
         {
         t = new node;
         t->data = x;
         t->left = t->right = NULL;
         }
         else if (x < t->data)
         t->left = insert(x, t->left);
         else if (x > t->data)
         t->right = insert(x, t->right);
         return t;*/
        
        
    }
    
    node* findMin(node* t)
    {
        if (t == NULL)
            return NULL;
        else if (t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }
    
    node* findMax(node* t)
    {
        if (t == NULL)
            return NULL;
        else if (t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }
    
    node* remove(T x, node* t)
    {
        node* temp;
        if (t == NULL)
            return NULL;
        else if (x < t->data)
            t->left = remove(x, t->left);
        else if (x > t->data)
            t->right = remove(x, t->right);
        else if (t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        else
        {
            temp = t;
            if (t->left == NULL)
                t = t->right;
            else if (t->right == NULL)
                t = t->left;
            delete temp;
        }
        
        return t;
    }
    
    void inorder(node* t, ofstream &outfile)
    {
        if (t == NULL)
            return;
        inorder(t->left, outfile);
        cout << t->data << " ";
        outfile << t->data << endl << endl;
        inorder(t->right, outfile);
    }
    
    void postorder(node* t, ofstream &outfile)
    {
        if (t == nullptr)
            return;
        postorder(t->left, outfile);
        postorder(t->right, outfile);
        cout << t->data << endl << endl;
        outfile << t->data << endl << endl;
    }
    
    void printHeightLevel(node* root, int treeHeightLevel, ofstream &outfile)
    {
        if(root == NULL)
            return;
        if(treeHeightLevel == 1)
        {
            std::cout << root->data << std::endl << std::endl;
            outfile << root->data << std::endl << std::endl;
        }
        
        else if(treeHeightLevel > 1)
        {
            printHeightLevel(root->left, treeHeightLevel -1, outfile);
            printHeightLevel(root->right, treeHeightLevel - 1, outfile);
        }
    }
    
    void breadthFirstTrav(node* root, ofstream &outfile)
    {
        int treeHeight = getHeight(root);
        
        for(int i = 1; i <= treeHeight; i++)
        {
            std::cout << "Level " << i << std:: endl << std::endl;
            outfile << "Level " << i << std::endl << std::endl;
            printHeightLevel(root, i, outfile);
        }
    }
    
    node* find(node* t, T x)
    {
        if (t == NULL)
            return NULL;
        else if (x < t->data)
            return find(t->left, x);
        else if (x > t->data)
            return find(t->right, x);
        else
            return t;
    }
    
    bool isBirthday;
    
public:
    BST()
    {
        root = NULL;
        isBirthday = false;
    }
    
    BST(node* cRoot)
    {
        root = cRoot;
    }
    
    BST(bool cBirthday)
    {
        root = NULL;
        isBirthday = cBirthday;
    }
    
    ~BST()
    {
        root = makeEmpty(root);
    }
    
    void insert(T x)
    {
        root = insert(x, root);
    }
    
    void remove(T x)
    {
        root = remove(x, root);
    }
    
    void displayName(ofstream &outfile)
    {
        postorder(root, outfile);
    }
    
    void displayBday(ofstream &outfile)
    {
        breadthFirstTrav(root, outfile);
    }
    
    void search(T x)
    {
        root = find(root, x);
        std::cout << root->data << " was found!" << endl << endl;
    }
    
    node* getRoot() const
    {
        return root;
    }
    
    int getHeight(node* root)
    {
        if(root == NULL)
            return 0;
        else
        {
            //Height of each subtree called recursively
            int leftHeight = getHeight(root->left);
            int rightHeight = getHeight(root->right);
            
            //Use the larger subtree's height
            if(leftHeight > rightHeight)
                return (leftHeight + 1);
            else
                return (rightHeight + 1);
        }
    }
};




//#pragma once
//
//template <class T>
//class Node {
//private:
//    T item;
//    Node<T> *left, *right;
//
//public:
//
//    Node(T item) {
//        this->item = item;
//        this->left = this->right = NULL;
//    }
//
//    void traverse(Node<T>* root) {
//        if (root != NULL) {
//            traverse(root->left);
//            printf("%d \n", root->item);
//            traverse(root->right);
//        }
//    }
//
//    Node<T>* insert(Node<T> *node, T item) {
//        if (node == NULL)
//            return newNode(key);
//
//        if (item < node->item)
//            node->left = insert(node->left, key);
//        else if (item > node->item)
//            node->right = insert(node->right, key);
//
//        return node;
//    }
//
//    Node<T>* search(Node<T>* root, T item) {
//        if (root == NULL || root->item == item)
//            return root;
//
//        if (root->item < item)
//            return search(root->right, item);
//
//        return search(root->left, item);
//    }
//};
