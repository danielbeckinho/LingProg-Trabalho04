#ifndef SENIORPATIENT_H
#define SENIORPATIENT_H

#include "patient.h"
#include <string>


class SeniorPatient: public Patient {
    public:

        SeniorPatient(const std::string, const int, const std::string, const std::string, const std::string);

        virtual void getSpecificInformation() const;


    private:

        std::string nomeAcompanhante, relacaoAcompanhante;


};


#endif