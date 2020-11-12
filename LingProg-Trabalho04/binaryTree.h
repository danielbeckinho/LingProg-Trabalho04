#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <string>


template <class T> class Node {

    template<class O>
    friend std::ostream &operator<<(std::ostream&, const Node<O> &);
    friend class Tree;

    public:
        Node(T &); //cria novo node com key do tipo T e leftPtr e rightPtr null, como todo node vai ser inserido os ptr serao sobrescritos 
        //Node(T=NULL);

        ~Node() {
            if (this != NULL) {
                *(this->leftPtr)->~Node();
                *(this->rightPtr)->~Node();
                delete this;
            }
        }; 

        T *getKey() const {return &(this->key);};
        void setKey(T &)

        Node * getLeftPtr() const {return this->leftPtr;};
        void setLeftPtr(Node &node) {leftPtr = &node;};
        Node * getRightPtr() const {return this->rightPtr;};
        void setRightPtr(Node &node) {rightPtr = &node;};





    private:
        T key;
        Node *leftPtr;
        Node *rightPtr;



};

class Tree {
    public:
        Tree() {

        };
        ~Tree();

        template <class T> 
        Node<T> &operator() (std::string &); //busca sobrecarreagda por nome 

        template <class T> 
        Node<T> &operator+=(T &); //insere um paciente criando novo node

        template <class T>
        Node<T> &operator+=(Node<T> &); //insere novo node ou arvore de nodes

        Tree &operator+=(Tree &); //concatena as arvores adicionando os nodes de uma na outra

        template <class T>
        void insertKey(T & , Node<T> *);

    private:
        template <class T>
        Node<T> root; // = &(Node::Node());

        template <class T>
        Node<T> *root{nullptr}; // = NULL;

        Node<T> *root;


};

// Node rootNode = Node(NULL); quero ter um root com key NULL 

template <class T>
Node<T>::Node(T &key=NULL) {
    setkey(key);
    setLeftPtr(NULL);
    setRightPtr(NULL);
};

template <class T>
void Tree::insertKey(T &key,Node<T> *nodeWhereToInsert) {

};

template <class T> 
Node<T> &Tree::operator+=(T &keyToInsert) { 
    if (nodeToInsert->getKey() > this->getKey()) {
        
    }
};


#endif