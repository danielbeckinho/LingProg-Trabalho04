#include "patient.h"
#include "pediatricPatient.h"
#include "seniorPatient.h"
#include "binaryTree.h"
#include "cadastro.h"
#include "menu.h"
#include "customExceptions.h"

int main() {

    Cadastro cadastroMain;

    Menu menu = Menu();

    menu.cadastro = &cadastroMain;

    menu.setExitProgramTrigger(0);

    while (menu.getExitProgramTrigger() == 0) { //exitProgramTrigger eh controlado pela mainMenu e vai pra 1 quando o usuario corretamente acessa a opcao de saida
    
        try {
        menu.mainMenu();
        }

        catch (ExceptionPatientAlreadyExists &err) { //erro de insercao disparado por Tree<U>::operator+=(U &keyToInsert) de binaryTree.h
            std::cout << err.what();
        }

        catch (ExceptionPatientNotFound &err) { //erro de busca disparado por Tree<U>::operator()(.) de binaryTree.h
            std::cout << err.what();
        }
    }


}