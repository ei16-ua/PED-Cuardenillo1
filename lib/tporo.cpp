#include "../include/tporo.h"
#include "tporo.h"

TPoro::TPoro()
{
    this->x = 0;
    this->y = 0;
    this->volumen = 0;
    this->color = NULL;

}

TPoro::TPoro(int, int, double)
{
    this->x = x;
    this->y = y;
    this->volumen = volumen;
}

TPoro::TPoro(int, int, double, char *)
{
    this->x = x;
    this->y = y;
    this->volumen = volumen;
    this->color = color;
}

TPoro::TPoro(const TPoro &tporo ) 
{
    this->x = tporo.x;
    this->y = tporo.y;
    this->volumen = tporo.volumen;
    this->color = tporo.color;
}

TPoro::~TPoro()
{
    delete[] this->color;
    
    this->x = 0;
    this->y = 0;
    this->volumen = 0.0;
    this->color = nullptr;
}

TPoro &TPoro::operator=(const TPoro &tporo)
{
    this->x = tporo.x;
    this->y = tporo.y;
    this->volumen = tporo.volumen;
    this->color = tporo.color;
    return *this;
}

bool TPoro::operator==(const TPoro &tporo ) const
{
    return this->x == tporo.x && this->y == tporo.y && this->volumen == tporo.volumen && this->color == tporo.color;
}

bool TPoro::operator!=(const TPoro &tporo) const
{
    return this->x != tporo.x || this->y != tporo.y || this->volumen != tporo.volumen || this->color != tporo.color;
}

void TPoro::Posicion(int, int)
{
    this->x = x;
    this->y = y;
}

void TPoro::Volumen(double)
{
    this->volumen = volumen;
}

void TPoro::Color(char *)
{
    this->color = color;
}

int TPoro::PosicionX() const
{
    return this->x;
}

int TPoro::PosicionY() const
{
    return this->y;
}

double TPoro::Volumen() const
{
    return this->volumen;
}

char *TPoro::Color() const
{
    return this->color;
}

bool TPoro::EsVacio() const
{
    if(this->x == NULL){
        return true;
    }
    return false;
}

ostream & operator<<(ostream &os, const TPoro &obj)
{
    if (obj.EsVacio()) {
        os << "()";
    } else {
        os << "(" << obj.PosicionX() << ", " << obj.PosicionY() << ") " << obj.Volumen();
        if (obj.Color() == NULL) {
            os << " -";
        } else {
            os << " " << obj.Color();
        }
    }
    return os;
}

