#ifndef CUSTOMEXCEPTIONS_H
#define CUSTOMEXCEPTIONS_H

#include <stdexcept>


class ExceptionPatientAlreadyExists: public std::runtime_error {
    public:
        ExceptionPatientAlreadyExists()
        : runtime_error("\n Paciente ja existe. Cadastramento duplicado impedido. \n") {}
};

class ExceptionPatientNotFound: public std::runtime_error {
    public:
        ExceptionPatientNotFound()
        : runtime_error("\n Paciente nao encontrado. Tente novamente. \n") {}
};

#endif