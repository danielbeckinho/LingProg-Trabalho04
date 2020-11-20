#ifndef PEDIRATRICPATIENT_H
#define PEDIRATRICPATIENT_H


#include "patient.h"
#include <string>

class PediatricPatient: public Patient {
    public:
        PediatricPatient(const std::string, const int, const std::string, const std::string, const std::string);

        virtual void getSpecificInformation() const;

    private:

        std::string brinquedoFavorito, nomeAcompanhante, relacaoAcompanhante = "Responsavel";


};

#endif