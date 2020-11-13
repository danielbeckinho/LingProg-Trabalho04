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

template <class T> class Tree {
    public:
        Tree() {

        };
        ~Tree();

        Node<T> *operator() (std::string &); //busca sobrecarreagda por nome 

        Node<T> *operator+=(T &); //insere um paciente criando novo node

        //Node<T> &operator+=(Node<T> &); //insere novo node ou arvore de nodes

        Tree<T> &operator+=(Tree &); //concatena as arvores adicionando os nodes de uma na outra


    private:
        static Node<T> *root = NULL;

        Node<T> *insertKey(T & , Node<T> *);

        Node<T> *searchKey(T &, Node<T> *, bool);

};

// Node rootNode = Node(NULL); quero ter um root com key NULL 

template <class T>
Node<T>::Node(T &key=NULL) {
    setkey(key);
    setLeftPtr(NULL);
    setRightPtr(NULL);
};

template <class T>
Node<T> *Tree<T>::insertKey(T &keyToInsert, Node<T> *nodeWhereToInsert = root) {
    if (keyToInsert < nodeWhereToInsert->key) { //se menor olha esquerda
        if (nodeWhereToInsert->leftPtr == NULL) {
            nodeWhereToInsert->leftPtr = &(new (Node<T>(keyToInsert)));
            /*nodeWhereToInsert->leftPtr = &(new (Node<T>()));
            nodeWhereToInsert->leftPtr.setKey(keyToInsert); */
            return nodeWhereToInsert->leftPtr;
        } 
        else { insertKey(keyToInsert, nodeWhereToInsert->leftPtr); }
    }

    else if (keyToInsert > nodeWhereToInsert->key) {
        if (nodeWhereToInsert->rightPtr == NULL) {
            nodeWhereToInsert->rightPtr = &(new (Node<T>(keyToInsert)));
            /*nodeWhereToInsert->rightPtr = &(new (Node<T>()));
            nodeWhereToInsert->rightPtr.setKey(keyToInsert); */
            return nodeWhereToInsert->rightPtr;
        }
        else { insertKey(keyToInsert, nodeWhereToInsert->rightPtr); }
    }

    else { return nullptr; }
};

template <class T> 
Node<T> *Tree<T>::operator+=(T &keyToInsert) { 
    insertKey(keyToInsert);
};

template <class T> 
Node<T> *Tree<T>::searchKey(T &key, Node<T> *nodeWhereToSearch = root, bool nodeIsRoot = true) {
    /*should only be called internally by overloaded search operator 
    nodeIsRoot is to avoid returning NULL on the first call
    added so the func can be recursively called recursively with ease*/
    if (nodeWhereToSearch->key == NULL) { nodeIsRoot ? (nodeIsRoot = false) : (return NULL;) } //if this is the first NULL encountered, ie, node is in fact root then change nodeIsRoot variable and continue 

    else {
        if (key == nodeWhereToSearch->key) {return nodeWhereToSearch;}

        if (key < nodeWhereToSearch->key) {return searchKey(key, nodeWhereToSearch->leftPtr, nodeIsRoot);}

        else {return searchKey(key, nodeWhereToSearch->rightPtr, nodeIsRoot);}
    } 
};

template <class T>
Node<T> *Tree<T>::operator() (std::string &key) {
    
}














#endif