#include "../include/tvectorporo.h"
#include "tvectorporo.h"

TVectorPoro::TVectorPoro()
{
    this->dimension = 0;
    this->datos = NULL;
    this->error = TPoro();
}

TVectorPoro::TVectorPoro(int dimension)
{
    this->dimension = dimension;
    this->datos = new TPoro[dimension];
    this->error = TPoro();
}

TVectorPoro::TVectorPoro(const TVectorPoro &tvectorporo)
{
    this->dimension = tvectorporo.dimension;
    this->datos = new TPoro[tvectorporo.dimension];
    for (int i = 0; i < tvectorporo.dimension; i++) {
        this->datos[i] = tvectorporo.datos[i];
    }
    this->error = tvectorporo.error;
}

TVectorPoro::~TVectorPoro()
{
    delete[] this->datos;
    this->dimension = 0;
    this->datos = nullptr;
}

TVectorPoro &TVectorPoro::operator=(const TVectorPoro &tvectorporo)
{
    if (this != &tvectorporo) {
        delete[] this->datos;
        this->dimension = tvectorporo.dimension;
        this->datos = new TPoro[tvectorporo.dimension];
        for (int i = 0; i < tvectorporo.dimension; i++) {
            this->datos[i] = tvectorporo.datos[i];
        }
        this->error = tvectorporo.error;
    }
    return *this;
}

bool TVectorPoro::operator==(const TVectorPoro &tvectorporo) const
{
    if (this->dimension != tvectorporo.dimension) {
        return false;
    }
    for (int i = 0; i < this->dimension; i++) {
        if (this->datos[i] != tvectorporo.datos[i]) {
            return false;
        }
    }
    return true;
}
