#include "../include/tporo.h"
#include "tporo.h"

void TPoro::Copiar(const TPoro &p)
{
    x = p.x;
    y = p.y;
    volumen = p.volumen;
    if (p.color != NULL) {
        color = new char[strlen(p.color) + 1];
        strcpy(color, p.color);
    } else {
        color = NULL;
    }
}

void TPoro::ConvertirMinusculas(char *c)
{
    for (int i = 0; c[i] != '\0'; i++) {
        c[i] = tolower(c[i]);
    }
}

TPoro::TPoro()
{
    this->x = 0;
    this->y = 0;
    this->volumen = 0;
    this->color = nullptr;

}

TPoro::TPoro(int px, int py, double v)
{
    this->x = px;
    this->y = py;
    this->volumen = v;
}

TPoro::TPoro(int px, int py, double v, const char* c)
{
    this->x = px;
    this->y = py;
    this->volumen = v;
    if (c != NULL)
    {
        color = new char[strlen(c) + 1];
        strcpy(color, c);
        ConvertirMinusculas(color);
    }
    else{
        color = nullptr;
    }    
}

TPoro::TPoro(const TPoro &tporo ) 
{
    Copiar(tporo);
}

TPoro::~TPoro()
{
    delete[] color;
}

TPoro &TPoro::operator=(const TPoro &tporo)
{
    if(this != &tporo){
        delete[] color;
        Copiar(tporo);
    }
    return *this;
}

bool TPoro::operator==(const TPoro &tporo ) const
{
    return this->x == tporo.x &&
        this->y == tporo.y &&
        this->volumen == tporo.volumen && 
        ((this->color == nullptr && tporo.color == nullptr) || 
        (this->color != nullptr && tporo.color != nullptr && 
            strcmp(this->color, tporo.color) == 0));
}

bool TPoro::operator!=(const TPoro &tporo) const
{
    return !(*this == tporo);
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

void TPoro::Color(const char * c)
{
    delete[] color;
    if (c != nullptr)
    {
        color = new char[strlen(c) + 1];
        strcpy(color, c);
        ConvertirMinusculas(this->color);
    }
    else{
        color = nullptr;
    }
}

int TPoro::PosicionX() const
{
    return x;
}

int TPoro::PosicionY() const
{
    return y;
}

double TPoro::Volumen() const
{
    return volumen;
}

char *TPoro::Color() const
{
    return color;
}

bool TPoro::EsVacio() const
{
    return x == 0 && y == 0 && volumen == 0 && color == nullptr;
}

ostream &operator<<(ostream &os, const TPoro &obj)
{
    if (obj.EsVacio()) {
        os << "()";
    } else {
        os.setf(ios::fixed);
        os.precision(2);
        os << "(" << obj.x << ", " << obj.y << ") ";

        /*para imprimir los números sin decimales
        if (obj.Volumen() == (int)obj.Volumen()) {
            os << (int)obj.Volumen();
        } else {
            os << obj.Volumen();
        }*/
        os << obj.Volumen();

        if (obj.Color() == nullptr || obj.Color()[0] == '\0') {
            os << " -";
        } else {
            os << " " << obj.Color();
        }
    }
    return os;
}


