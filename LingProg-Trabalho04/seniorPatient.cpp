#include "seniorPatient.h"



SeniorPatient::SeniorPatient(const std::string nome, const int idade, const std::string generoMF, const std::string nomeAcompa, const std::string relacaoAcompa):
    Patient(nome, idade, generoMF) {
        nomeAcompanhante = nomeAcompa;
        relacaoAcompanhante = relacaoAcompa;
}

void SeniorPatient::getSpecificInformation() const {
    std::cout << "Nome e relacao com acompanhante: " << nomeAcompanhante << ", " << relacaoAcompanhante << std::endl;
}

