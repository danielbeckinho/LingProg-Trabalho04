#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <string>
#include "customExceptions.h"


template <class U> class Node {

    template<class O>
    friend std::ostream &operator<<(std::ostream&, const Node<O> *);
    

    public:
        Node(U *key) {
            Node<U>::key = key;
            Node<U>::leftPtr = NULL;
            Node<U>::rightPtr = NULL;
        }
            
        ~Node() {
            this->leftPtr->~Node();
            this->rightPtr->~Node();
            delete this;
        } 

        U *getKey() {return (this->key);}
        void setKey(U &key) {this->key = key;}

        Node *getLeftPtr() const {return this->leftPtr;}
        void setLeftPtr(Node &node) {leftPtr = &node;}

        Node *getRightPtr() const {return this->rightPtr;}
        void setRightPtr(Node &node) {rightPtr = &node;}

        Node *operator() (std::string &); //busca sobrecarreagda por nome 

        Node *operator+=(U *); //insere um paciente criando novo node (U = Patient)

        void operator+=(Node *); //concatena as arvores adicionando os nodes de uma na outra


    private:
        U *key;
        Node *leftPtr;
        Node *rightPtr;
        
        Node<U> *searchKey(std::string &, Node<U> *); //retorna ptr pra node de key igual, comeca busca pelo Node<U> * e continua recursivamente;    metodo ref ao operator()(std::string)
        
        Node<U> *insertKey(U * , Node<U> *); //retorna ptr pra node inserido;    metodo ref ao operator+=(U &)
        
        void insertTree(Node<U> *, Node<U> *); //olhar essa impl;    metodo ref ao operator+=(Node &)


};



template <class U>
Node<U> *Node<U>::insertKey(U *keyToInsert, Node<U> *nodeWhereToInsert) {
    if (nodeWhereToInsert->key == NULL) { //caso root == NULL ,ie, arvore vazia
        nodeWhereToInsert->key = keyToInsert;
        return nodeWhereToInsert;
    }

    else if (*keyToInsert == *nodeWhereToInsert->key) {throw ExceptionPatientAlreadyExists();}

    else if (*keyToInsert < *nodeWhereToInsert->key) { //se menor olha esquerda
        if (nodeWhereToInsert->leftPtr == NULL) {
            nodeWhereToInsert->leftPtr = new Node(keyToInsert);

            return nodeWhereToInsert->leftPtr;
        } 
        else { insertKey(keyToInsert, nodeWhereToInsert->leftPtr); }
    }

    else if (*keyToInsert > *nodeWhereToInsert->key) {
        if (nodeWhereToInsert->rightPtr == NULL) {
            nodeWhereToInsert->rightPtr = new Node(keyToInsert);

            return nodeWhereToInsert->rightPtr;
        }
        else { insertKey(keyToInsert, nodeWhereToInsert->rightPtr); }
    }

    else { return NULL; } //soh por precaucao, nap eh pra chegar aqui
};

template <class U> 
Node<U> *Node<U>::operator+=(U *keyToInsert) { 
    return insertKey(keyToInsert, this); //insertKey que dispara o erro quando se faz necessario, pra colocar o erro aqui envolveria mudar muito codigo
};




template <class U>
void Node<U>::insertTree(Node<U> *nodeToInsert, Node<U> *hostTree) {
    //vai de node em node inserindo as keys na hostTree
    insertKey(nodeToInsert->key, hostTree);
    if (nodeToInsert->leftPtr != NULL) { insertTree(nodeToInsert->leftPtr, hostTree); }
    if (nodeToInsert->rightPtr != NULL) { insertTree(nodeToInsert->rightPtr, hostTree); }
    else if ((nodeToInsert->leftPtr == NULL) && (nodeToInsert->rightPtr == NULL)) {;}
}

template <class U>
void Node<U>::operator+= (Node<U> *treeToConcat) {
    insertTree(treeToConcat, this); //usa this como hostTree, assume que esta recebendo arvore por root
}




template <class U> 
Node<U> *Node<U>::searchKey(std::string &key, Node<U> *nodeWhereToSearch) {
    /*should only be called internally by overloaded search operator */

    if (*nodeWhereToSearch->key == key) {return nodeWhereToSearch;}

    else if ((nodeWhereToSearch->leftPtr == NULL) && (nodeWhereToSearch->rightPtr == NULL)) {return NULL;}

    else if (*nodeWhereToSearch->key > key) {return searchKey(key, nodeWhereToSearch->leftPtr);}

    else {return searchKey(key, nodeWhereToSearch->rightPtr);}

};

template <class U>
Node<U> *Node<U>::operator() (std::string &key) {
    Node<U> * nodeFoundPtr = searchKey(key, this);
    if (nodeFoundPtr == NULL) {throw ExceptionPatientNotFound();} 

    else {return nodeFoundPtr;}
}




template<class O>
std::ostream &operator<<(std::ostream &out, const Node<O> *node) {
    if (node->leftPtr != NULL) {out << (node->leftPtr);}
    out << (node->key);
    if (node->rightPtr != NULL) {out << (node->rightPtr);}

    return out;
};




#endif