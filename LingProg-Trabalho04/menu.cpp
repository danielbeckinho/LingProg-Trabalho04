#include "menu.h"

#include <string>


int Menu::mainMenu() {
    int seletor;

    std::cout << "      Menu Principal \n" << std::endl;

    std::cout << "Selecione uma opcao: \n" 
        << "(1) Busca por paciente \n" 
        << "(2) Novo paciente \n"
        << "(3) Exibir todos os cadastros \n" 
        << "(0) Sair \n" <<std::endl;

    std::cout << "Opcao: ";
    std::cin >> seletor;
    std::cout << std::endl;


        if (seletor == 1) { 
            std::cout << "Nome para buscar: ";
            std::string nomeSrc;
            std::cin.ignore();
            std::getline(std::cin, nomeSrc);
            this->cadastro->srcCad(nomeSrc);
            
        }

        else if (seletor == 2){
            int tipoPaciente;
            std::cout << "Digite 1 para cadastrar Paciente Pediatrico ou 2 para Paciente Geriatrico. \n"
                    << "Opcao: " ;
            std::cin >> tipoPaciente;

            std::cout << "Nome: ";
            std::string nomePac;
            std::cin.ignore();
            std::getline(std::cin, nomePac);
            std::cout << std::endl;

            std::cout << "Idade: ";
            int idadePac;
            std::cin >> idadePac;
            std::cout << std::endl;

            std::cout << "Genero (M ou F): ";
            std::string generoPac;
            std::cin.ignore();
            std::getline(std::cin, generoPac);
            std::cout << std::endl;

            std::cout << "Nome do acompanhante: ";
            std::string nomeAcompPac;
            //std::cin.ignore();
            std::getline(std::cin, nomeAcompPac);

            if (tipoPaciente == 1) { //pediatrico
                std::cout << "Brinquedo favorito: ";
                std::string nomeBrinquedoPac;
                //std::cin.ignore();
                std::getline(std::cin, nomeBrinquedoPac);
                std::cout << std::endl;

                Patient *pac = new PediatricPatient(nomePac, idadePac, generoPac, nomeAcompPac, nomeBrinquedoPac);
                std::cout << pac;
                this->cadastro->addCad(pac);
                std::cout << std::endl;
                //this->cadastro->addCad(new PediatricPatient(nomePac, idadePac, generoPac, nomeAcompPac, nomeBrinquedoPac));
            }

            else if (tipoPaciente == 2) { //geriatrico
                std::cout << "Tipo de relacao com acompanhante: ";
                std::string relacaoAcompPac;
                std::getline(std::cin, relacaoAcompPac);
                std::cout << std::endl;

                Patient *pac = new SeniorPatient(nomePac, idadePac, generoPac, nomeAcompPac, relacaoAcompPac);
                std::cout << pac;
                this->cadastro->addCad(pac);
                std::cout << std::endl;

                //this->cadastro->addCad(new SeniorPatient(nomePac, idadePac, generoPac, nomeAcompPac, relacaoAcompPac));
            }

            else {std::cout << "Opcao invalida, tente novamente." <<std::endl;}
        }

        else if (seletor == 3) {
            this->cadastro->showCad();
        }

        else if (seletor == 0) {
            this->setExitProgramTrigger(1);
            return 0;
        }

        else {std::cout << "Opcao invalida, tente novamente." << std::endl;}

    this->mainMenu();

}

void Menu::setExitProgramTrigger(int val) {exitProgramTrigger = val;}

int Menu::getExitProgramTrigger() const {
    return exitProgramTrigger;
}
