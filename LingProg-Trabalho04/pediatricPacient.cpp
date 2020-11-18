# include "pediatricPatient.h"

PediatricPatient::PediatricPatient(const std::string nome, const int idade, const std::string generoMF, const std::string nomeAcompa, const std::string brinquedoFav): 
    Patient(nome, idade, generoMF) {
        nomeAcompanhante = nomeAcompa;
        brinquedoFavorito = brinquedoFav;
}

void PediatricPatient::getSpecificInformation() const {
    std::cout << "Nome e relacao com acompanhante: " << nomeAcompanhante << ", " << relacaoAcompanhante << std::endl;
    std::cout << "Brinquedo favorito: " << brinquedoFavorito <<std::endl;
}