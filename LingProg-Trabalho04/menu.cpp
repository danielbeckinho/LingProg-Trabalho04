#include "menu.h"

#include <string>

int Menu::mainMenu() {
    int seletor;

    std::cout << "      Menu Principal \n" << std::endl;

    std::cout << "Selecione uma opcao: \n" 
        << "(1) Busca por paciente: \n" 
        << "(2) Novo paciente: \n" 
        << "(0) Sair \n" <<std::endl;

    std::cout << "Opcao: ";
    std::cin >> seletor;

    switch (seletor) {

        case 1: 
            std::cout << "Nome para buscar: ";
            std::string nomeSrc;
            std::cin.ignore();
            std::getline(std::cin, nomeSrc);

    }

}