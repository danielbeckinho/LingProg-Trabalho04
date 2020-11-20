#include "cadastro.h"


void Cadastro::addCad(Patient *patient) {
    std::cout << "addcad()" << std::endl;
    (*treeCad)+=patient;
}

void Cadastro::srcCad(std::string &nomePaciente) {
    std::cout << (*treeCad)(nomePaciente)->getKey();
}

void Cadastro::showCad() {
    std::cout << (this->treeCad);
}

Node<Patient> Cadastro::getTreeCad() {
    return *(this->treeCad);
}

//void Cadastro::setTreeCad(Node<Patient> *treePtr) {this->treeCad = treePtr;};

void Cadastro::concatCad(Cadastro &cadastroToConcat) { 
    (*treeCad) += (cadastroToConcat.treeCad);
}

//Cadastro::Cadastro(Node<Patient> *treePtr) {
//    treeCad = treePtr;
//}
