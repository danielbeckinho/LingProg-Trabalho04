#include "cadastro.h"


void Cadastro::addCad(Patient &patient) {
    (*treeCad)+=patient;
}

void Cadastro::srcCad(std::string &nomePaciente) {
    (*treeCad)(nomePaciente);
}

void Cadastro::showCad() {
    std::cout << *(this->treeCad);
}

Tree<Patient> Cadastro::getTreeCad() {
    return *(this->treeCad);
}

void Cadastro::concatCad(Cadastro &cadastroToConcat) { //essa implementacao ta idiota, arrumar
    (*treeCad) += (cadastroToConcat.getTreeCad());
}