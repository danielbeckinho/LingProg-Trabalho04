#include <stdexcept>
//#include <exception>


class ExceptionPatientAlreadyExists: public std::runtime_error {
    public:
        ExceptionPatientAlreadyExists::ExceptionPatientAlreadyExists()
        : runtime_error("\n Paciente ja existe. Cadastramento duplicado impedido. \n") {}
};

class ExceptionPatientNotFound: public std::runtime_error {
    public:
        ExceptionPatientNotFound::ExceptionPatientNotFound()
        : runtime_error("\n Paciente nao encontrado. Tente novamente. \n") {}
};

