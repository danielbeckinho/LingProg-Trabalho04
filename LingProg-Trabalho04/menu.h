#ifndef MENU_H
#define MENU_H

#include "patient.h"
#include "pediatricPatient.h"
#include "seniorPatient.h"
#include "binaryTree.h"
#include "cadastro.h"

#include <string>
#include <iostream>

class Menu {

    public:

        Menu() {exitProgramTrigger = 0;}

        int mainMenu() ;

        Cadastro *cadastro;

        int getExitProgramTrigger() const;
        void setExitProgramTrigger(int);
        int exitProgramTrigger;
        
        void demoConcatCad();

    private:

};








#endif