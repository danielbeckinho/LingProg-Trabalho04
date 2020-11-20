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

        else {std::cin.ignore(); std::cout << "Opcao invalida, tente novamente." << std::endl;}

    this->mainMenu();

}

void Menu::setExitProgramTrigger(int val) {exitProgramTrigger = val;}

int Menu::getExitProgramTrigger() const {
    return exitProgramTrigger;
}

void Menu::demoConcatCad() {
    std::cout << "Bem-vindo aa demonstracao de concatenacao de arvores de pacientes!" << std::endl;

    Cadastro cadastroEsq, cadastroDir;

    cadastroEsq.treeCad = new Node<Patient>(NULL);
    cadastroDir.treeCad = new Node<Patient>(NULL);

    Patient *patEsq1 = new PediatricPatient("Joazinho da Silva", 12, "M", "Rogerio da Silva", "Bola");    
    Patient *patEsq2 = new SeniorPatient("Juracy", 77, "F", "Jurandir", "esposo");
    Patient *patEsq3 = new SeniorPatient("Valterlucio", 67, "M", "Wanderleya", "filha");

    Patient *patDir1 = new PediatricPatient("Marizinha", 11, "F", "Flavio", "Estilingue");
    Patient *patDir2 = new PediatricPatient("Artur", 8, "M", "Dulce", "Boneco");
    Patient *patDir3 = new SeniorPatient("Samara", 81, "F", "Janice", "esposa");

    cadastroEsq.addCad(patEsq1); cadastroEsq.addCad(patEsq2); cadastroEsq.addCad(patEsq3);
    cadastroDir.addCad(patDir1); cadastroDir.addCad(patDir2); cadastroDir.addCad(patDir3);

    std::cout << "      CadastroEsq: " << std::endl;
    cadastroEsq.showCad();
    std::cout << "\n\n\n";

    std::cout << "      CadastroDir: " << std::endl;
    cadastroDir.showCad();
    std::cout << "\n\n\n";

    std::cout << "\n\n\n\n\n"; 

    std::cout << "      Cadastros concatenados: " << std::endl;
    cadastroEsq.concatCad(cadastroDir);
    cadastroEsq.showCad();

    std::cout << "\n\n\n" << "****************Fim da Demonstracao****************" << std::endl;

}