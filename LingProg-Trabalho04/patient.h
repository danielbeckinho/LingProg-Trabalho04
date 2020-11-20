#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <iostream>

class Patient{
  friend std::ostream &operator<<(std::ostream&, const Patient *);
  
  public:
    Patient(const std::string, const int, const std::string);

    std::string getName() const;
    void setName(const std::string);

    std::string getGender() const;
    void setGender(const std::string);

    int getAge() const;
    void setAge(const int);

    bool operator<(const Patient &);
    bool operator>(const Patient &);
    bool operator==(const Patient &);

    bool operator<(const std::string &);
    bool operator>(const std::string &);
    bool operator==(const std::string &);

    virtual void getSpecificInformation() const;

  private:
    std::string name, gender;
    int age;

};

#endif