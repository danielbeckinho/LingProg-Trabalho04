#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <string>
#include "customExceptions.h"


template <class U> class Node {

    template<class U>
    friend std::ostream &operator<<(std::ostream&, const Node<U> &);
    
    friend class Tree;

    public:
        Node(U &key = NULL) {
            setkey(key);
            setLeftPtr(NULL);
            setRightPtr(NULL);
        }
            
        ~Node() {
            if (this->key != NULL) {
                *(this->leftPtr)->~Node();
                *(this->rightPtr)->~Node();
                delete this;
            }
        } 

        U *getKey() const {return &(this->key);}
        void setKey(U &key) {this->key = key;}

        Node * getLeftPtr() const {return this->leftPtr;}
        void setLeftPtr(Node &node) {leftPtr = &node;}

        Node * getRightPtr() const {return this->rightPtr;}
        void setRightPtr(Node &node) {rightPtr = &node;}


    private:
        U key;
        Node *leftPtr;
        Node *rightPtr;


};

template <class U> class Tree {
    
    template<class U>
    friend std::ostream &operator<<(std::ostream &, const Tree<U> &); 

    public:
        //Tree() ;

        ~Tree() {
            root->leftPtr->~Node();
            root->rightPtr->~Node();
            delete this;
        };

        Node<U> *operator() (std::string &); //busca sobrecarreagda por nome 

        Node<U> *operator+=(U &); //insere um paciente criando novo node

        Tree<U> *operator+=(Tree &); //concatena as arvores adicionando os nodes de uma na outra


    private:
        Node<U> *root;

        Node<U> *insertKey(U & , Node<U> *);

        Node<U> *searchKey(std::string &, Node<U> *);

        void insertTree(Node<U> &, Tree<U> *);

};


template <class U>
Node<U> *Tree<U>::insertKey(U &keyToInsert, Node<U> *nodeWhereToInsert) {
    if (nodeWhereToInsert == NULL) { //caso root == NULL ,ie, arvore vazia
        nodeWhereToInsert = new Node(keyToInsert);
        return &nodeWhereToInsert;
        }

    else if (keyToInsert < nodeWhereToInsert->key) { //se menor olha esquerda
        if (nodeWhereToInsert->leftPtr == NULL) {
            nodeWhereToInsert->leftPtr = &(new (Node<U>(keyToInsert)));
            /*nodeWhereToInsert->leftPtr = &(new (Node<U>()));
            nodeWhereToInsert->leftPtr.setKey(keyToInsert); */
            return nodeWhereToInsert->leftPtr;
        } 
        else { insertKey(keyToInsert, nodeWhereToInsert->leftPtr); }
    }

    else if (keyToInsert > nodeWhereToInsert->key) {
        if (nodeWhereToInsert->rightPtr == NULL) {
            nodeWhereToInsert->rightPtr = &(new (Node<U>(keyToInsert)));
            /*nodeWhereToInsert->rightPtr = &(new (Node<U>()));
            nodeWhereToInsert->rightPtr.setKey(keyToInsert); */
            return nodeWhereToInsert->rightPtr;
        }
        else { insertKey(keyToInsert, nodeWhereToInsert->rightPtr); }
    }

    else { return NULL; } //se a key nao eh maior nem menor ela eh igual
};

template <class U> 
Node<U> *Tree<U>::operator+=(U &keyToInsert) { 
    Node<U> *nodeInsertedPtr = insertKey(keyToInsert, this->root);
    if (nodeInsertedPtr == NULL) {throw ExceptionPatientAlreadyExists();}
    else {return nodeInsertedPtr;}
};




template <class U>
void Tree<U>::insertTree(Node<U> &nodeToInsert, Tree<U> *hostTree) {
    //vai de node em node inserindo as keys na hostTree
    if (nodeToInsert->key != NULL) { insertKey(nodeToInsert->key, hostTree->root); }
    if (nodeToInsert->leftPtr != NULL) { insertTree(nodeToInsert->leftPtr, hostTree); }
    if (nodeToInsert->rightPtr != NULL) { insertTree(nodeToInsert->rightPtr, hostTree); }
    else if (nodeToInsert->leftPtr == NULL) && (nodeToInsert->rightPtr == NULL) {;}
}

template <class U>
Tree<U> *Tree<U>::operator+= (Tree &treeToConcat) {
    insertTree(treeToConcat.root, this); //usa this como hostTree e chama a func no root da arvore a ser inserida
}




template <class U> 
Node<U> *Tree<U>::searchKey(std::string &key, Node<U> *nodeWhereToSearch) {
    /*should only be called internally by overloaded search operator */

    if (nodeWhereToSearch->key == key) {return nodeWhereToSearch;}

    if (nodeWhereToSearch->leftPtr == NULL) && (nodeWhereToSearch->rightPtr == NULL) {return NULL;}

    else if (nodeWhereToSearch->key > key) {return searchKey(key, nodeWhereToSearch->leftPtr);}

    else {return searchKey(key, nodeWhereToSearch->rightPtr);}

};

template <class U>
Node<U> *Tree<U>::operator() (std::string &key) {
    Node<U> * nodeFoundPtr = searchKey(key, this->root);
    if (nodeFoundPtr == NULL) {throw ExceptionPatientNotFound();} 
    else {return nodeFoundPtr;}
}




template<class U>
std::ostream &operator<<(std::ostream &out, const Node<U> &node) {
    if (node->leftPtr != NULL) {out << *(node->leftPtr);}
    out << (node->key);
    if (node->rightPtr != NULL) {out << *(node->rightPtr);}

    return out;
};



template<class U>
std::ostream &operator<<(std::ostream &out, const Tree<U> &tree) {
    out << *(tree->root);

    return out;
};


#endif