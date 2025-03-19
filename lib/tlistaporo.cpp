#include "tlistaporo.h"

TListaNodo::TListaNodo()
{
    this->e = TPoro();
    this->anterior = NULL;
    this->siguiente = NULL;
}

TListaNodo::TListaNodo(const TListaNodo &)
{
    this->e = e;
    this->anterior = anterior;
    this->siguiente = siguiente;
}

TListaNodo::~TListaNodo()
{
    delete this->anterior;
    delete this->siguiente;
    this->e.~TPoro();
}

TListaNodo &TListaNodo::operator=(const TListaNodo &)
{
    return *this;
}

TListaPosicion::TListaPosicion()
{

}

TListaPosicion::TListaPosicion(const TListaPosicion &)
{
}

TListaPosicion::~TListaPosicion()
{
}

TListaPosicion &TListaPosicion::operator=(const TListaPosicion &)
{
    return *this;
}

bool TListaPosicion::operator==(const TListaPosicion &) const
{
    return false;
}

TListaPosicion TListaPosicion::Anterior() const
{
    TListaPosicion p;
    if(pos && pos->anterior){
        p.pos = pos->anterior;
    }
    return p;
}

TListaPosicion TListaPosicion::Siguiente() const
{
    TListaPosicion p;
    if(pos && pos->siguiente){
        p.pos = pos->siguiente;
    }
    return p;
}

bool TListaPosicion::EsVacia() const
{
    return pos == nullptr;
}

TListaPoro::TListaPoro()
{
    primero = NULL;
    ultimo = NULL;
}

TListaPoro::TListaPoro(const TListaPoro &)
{
    this->primero = primero;
    this->ultimo = ultimo;
}

TListaPoro::~TListaPoro()
{
    while (!EsVacia)
    {
        Borrar(Primera());
    }
    
}

TListaPoro &TListaPoro::operator=(const TListaPoro &tlistaporo)
{
    if(this != &tlistaporo){
        while (!EsVacia)
        {
            Borrar(Primera());
        }
        TListaPosicion p = tlistaporo.Primera();
        while (!p.EsVacia())
        {
            Insertar(tlistaporo.Obtener(p));
            p = p.Siguiente();
        }
    }
    return *this;
}

bool TListaPoro::operator==(const TListaPoro &) const
{
    return false;
}

bool TListaPoro::EsVacia() const
{
    return false;
}

bool TListaPoro::Insertar(const TPoro &)
{
    return false;
}

bool TListaPoro::Borrar(const TPoro &)
{
    return false;
}

bool TListaPoro::Borrar(TListaPosicion &)
{
    return false;
}

TPoro TListaPoro::Obtener(TListaPosicion &) const
{
    return TPoro();
}

bool TListaPoro::Buscar(const TPoro &) const
{
    return false;
}

int TListaPoro::Longitud() const
{
    return 0;
}

TListaPosicion TListaPoro::Primera() const
{
    TListaPosicion p;
    p.pos = primero;
    return p;
}

TListaPosicion TListaPoro::Ultima() const
{
    TListaPosicion p;
    p.pos = ultimo;
    return p;
}

TListaPoro TListaPoro::ExtraerRango(int, int)
{
    return TListaPoro();
}

ostream &operator<<(ostream &os, const TListaPoro &tlistaposicion)
{
    os << "(";
    TListaPosicion p = tlistaposicion.Primera();
    while (!p.EsVacia()) {
        os << tlistaposicion.Obtener(p);
        p = p.Siguiente();
        if (!p.EsVacia()) {
            os << " ";
        }
    }
    os << ")";
    return os;
}


