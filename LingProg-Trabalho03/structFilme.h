#ifndef STRUCTFILME_H
#define STRUCTFILME_H

#include "catalogo.h"

#include <string>

struct Filme {

    friend Catalogo;

    friend std::istream &operator>>(std::istream &, Filme &);
    friend std::ostream &operator<<(std::ostream &, const Filme &);

    bool operator < (const Filme &);
    bool operator > (const Filme &);
    bool operator == (const Filme &);
    
    std::string titulo;
    std::string produtora;
    double nota;

};

#endif