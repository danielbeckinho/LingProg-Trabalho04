#include "cadastro.h"


void Cadastro::addCad(Patient *patient) {
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


void Cadastro::concatCad(Cadastro &cadastroToConcat) { 
    (*treeCad) += (cadastroToConcat.treeCad);
}
