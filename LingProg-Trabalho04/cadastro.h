#ifndef CADASTRO_H
#define CADASTRO_H

#include "patient.h"
#include "pediatricPatient.h"
#include "seniorPatient.h"
#include "binaryTree.h"
//#include "menu.h"

class Cadastro {
    public:
        void addCad(Patient *);

        void srcCad(std::string &);

        void showCad();

        void concatCad(Cadastro &);

        Node<Patient> getTreeCad() ;

    private:
        Node<Patient> *treeCad;

};











#endif