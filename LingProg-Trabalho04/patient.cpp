#include "patient.h"

#include <string>
#include <iostream>

Patient::Patient(std::string nome, int idade, std::string generoMF) {
    setName(nome);
    setAge(idade);
    setGender(generoMF);
}

void Patient::setName(std::string nome) {name = nome;}

std::string Patient::getName() const {return name;} 


void Patient::setGender(std::string generoMF) {gender = generoMF;}

std::string Patient::getGender() const {return gender;}


int Patient::getAge() const {return age;}

void Patient::setAge(int idade) {age = idade;}


bool Patient::operator<(const Patient &patient) {return (this->name < patient.getName());}
bool Patient::operator>(const Patient &patient) {return !(*this<patient);}
bool Patient::operator==(const Patient &patient) {return (this->name == patient.getName());}

bool Patient::operator<(const std::string &nome) {return (this->name < nome);}
bool Patient::operator>(const std::string &nome) {return !(*this < nome);}
bool Patient::operator==(const std::string &nome) {return (this->name == nome);}

void Patient::getSpecificInformation() const {;}

std::ostream &operator<<(std::ostream &out, const Patient &patient) {
    out << "    Dados do paciente:" << std::endl; 
    
    out << "Nome: " << patient.getName() << " (" << patient.getGender() << ") \n" 
        << "Idade: " << patient.getAge() << std::endl;
    
    patient.getSpecificInformation();
    
    out << std::endl;
}