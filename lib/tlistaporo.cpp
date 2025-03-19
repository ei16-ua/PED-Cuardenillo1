#include "tlistaporo.h"

TListaNodo::TListaNodo()
{
    anterior = nullptr;
    siguiente = nullptr;
}

TListaNodo::TListaNodo(const TListaNodo &listanodo)
{
    e = listanodo.e;
    anterior = nullptr;
    siguiente = nullptr;
}

TListaNodo::~TListaNodo()
{
    anterior = nullptr;
    siguiente = nullptr;
}

TListaNodo &TListaNodo::operator=(const TListaNodo &listanodo)
{
    if(this != &listanodo){
        e = listanodo.e;
        //anterior = listanodo.anterior;
        //siguiente = listanodo.siguiente;
    }
    return *this;
}

TListaPosicion::TListaPosicion()
{
    pos = nullptr;
}

TListaPosicion::TListaPosicion(const TListaPosicion &listaposicion)
{
    pos = listaposicion.pos;
}

TListaPosicion::~TListaPosicion()
{
    pos = nullptr;
}

TListaPosicion &TListaPosicion::operator=(const TListaPosicion &listaposicion)
{
    if(this != &listaposicion){
        pos = listaposicion.pos;
    }
    return *this;
}

bool TListaPosicion::operator==(const TListaPosicion &listaposicion) const
{
    return pos == listaposicion.pos;
}

TListaPosicion TListaPosicion::Anterior() const
{
    TListaPosicion anterior;
    if(pos != nullptr && pos->anterior != nullptr){
        anterior.pos = pos->anterior;
    }
    return anterior;
}

TListaPosicion TListaPosicion::Siguiente() const
{
    TListaPosicion siguiente;
    if(pos != nullptr && pos->siguiente != nullptr){
        siguiente.pos = pos->siguiente;
    }
    return siguiente;
}

bool TListaPosicion::EsVacia() const
{
    return pos == nullptr;
}

TListaPoro::TListaPoro()
{
    primero = nullptr;
    ultimo = nullptr;
}

TListaPoro::TListaPoro(const TListaPoro &listaporo)
{
    primero = nullptr;
    ultimo = nullptr;


    TListaNodo *nodo = listaporo.primero;
    while (nodo != nullptr)
    {
        Insertar(nodo->e);
        nodo = nodo->siguiente;
    }
}

TListaPoro::~TListaPoro()
{
    TListaNodo *nodo;
    while (primero != nullptr)
    {
        nodo = primero;
        primero = primero->siguiente;
        delete nodo;
    }

    primero = nullptr;
    ultimo = nullptr;
}

TListaPoro &TListaPoro::operator=(const TListaPoro &tlistaporo)
{
    if(this != &tlistaporo){
        while (!EsVacia())
        {
            TListaPosicion pos = Primera();
            Borrar(pos);
        }
        
        TListaNodo *nodo = tlistaporo.primero;
        while (nodo != nullptr)
        {
            Insertar(nodo->e);
            nodo = nodo->siguiente;
        }
    }
    return *this;
}

bool TListaPoro::operator==(const TListaPoro &listaporo) const
{
    if(Longitud() != listaporo.Longitud()){
        return false;
    }

    TListaNodo *nodo1 = primero;
    TListaNodo *nodo2 = listaporo.primero;
    while (nodo1 != nullptr && nodo2 != nullptr)
    {
        if(nodo1->e != nodo2->e){
            return false;
        }
        nodo1 = nodo1->siguiente;
        nodo2 = nodo2->siguiente;
    }
    return true;
}

TListaPoro TListaPoro::operator+(const TListaPoro &listaporo) const
{
    TListaPoro resultado(*this);
    TListaNodo *nodo = listaporo.primero;
    while (nodo != nullptr)
    {
        resultado.Insertar(nodo->e);
        nodo = nodo->siguiente;
    }
    return resultado;
}

TListaPoro TListaPoro::operator-(const TListaPoro &listaporo) const
{
    TListaPoro resultado;
    TListaNodo *nodo = primero;
    while (nodo != nullptr)
    {
        if(!listaporo.Buscar(nodo->e)){
            resultado.Insertar(nodo->e);
        }
        nodo = nodo->siguiente;
    }
    return resultado;
}

bool TListaPoro::EsVacia() const
{
    return primero == nullptr;
}

bool TListaPoro::Insertar(const TPoro &poro)
{
    if(Buscar(poro)){
        return false;
    }

    TListaNodo *nodo = new TListaNodo();
    nodo->e = poro;

    if(EsVacia()){
        primero = nodo;
        ultimo = nodo;
        return true;
    }

    TListaNodo *nodo_actual = primero;
    if(nodo->e.Volumen() < nodo_actual->e.Volumen()){
        nodo->siguiente = nodo_actual;
        nodo_actual->anterior = nodo;
        primero = nodo;
        return true;
    }

    while (nodo_actual != nullptr)
    {
        if(nodo->e.Volumen() <= nodo_actual->e.Volumen()){
            if(nodo->e.Volumen() <= nodo_actual ->e.Volumen()){
                while (nodo_actual->siguiente != nullptr && 
                    nodo_actual->siguiente->e.Volumen() == nodo->e.Volumen())
                {
                    nodo_actual = nodo_actual->siguiente;
                }
                
            }

            nodo->siguiente = nodo_actual->siguiente;
            nodo->anterior = nodo_actual;

            if (nodo_actual->siguiente != nullptr)
            {
                nodo_actual->siguiente->anterior = nodo;
            }
            else
            {
                ultimo = nodo;
            }

            nodo_actual->siguiente = nodo;
            return true;
        }

        if(nodo_actual->siguiente == nullptr){
            nodo_actual->siguiente = nodo;
            nodo->anterior = nodo_actual;
            ultimo = nodo;
            return true;
        }
        nodo_actual = nodo_actual->siguiente;
    }

    return true;
}

bool TListaPoro::Borrar(const TPoro &poro)
{
    if(EsVacia()){
        return false;
    }

    TListaNodo *nodo = primero;

    while (nodo != nullptr)
    {
        if(nodo->e == poro){
            if(nodo == primero){
                primero = nodo->siguiente;
                if(primero != nullptr){
                    primero->anterior = nullptr;
                }else{
                    ultimo = nullptr;
                }
            } else if(nodo == ultimo){
                ultimo = nodo->anterior;
                ultimo->siguiente = nullptr;
            } else {
                nodo->anterior->siguiente = nodo->siguiente;
                nodo->siguiente->anterior = nodo->anterior;
            }

            delete nodo;
            return true;
        }
        nodo = nodo->siguiente;
    }
    return false;
}

bool TListaPoro::Borrar(TListaPosicion &listaposicion)
{
    if(listaposicion.EsVacia()){
        return false;
    }

    TListaNodo *nodo = listaposicion.pos;

    if(nodo == primero){
        primero = nodo->siguiente;
        if(primero != nullptr){
            primero->anterior = nullptr;
        }else{
            ultimo = nullptr;
        }
    } else if(nodo == ultimo){
        ultimo = nodo->anterior;
        ultimo->siguiente = nullptr;
    } else {
        nodo->anterior->siguiente = nodo->siguiente;
        nodo->siguiente->anterior = nodo->anterior;
    }

    delete nodo;
    listaposicion.pos = nullptr;
    return true;
}

TPoro TListaPoro::Obtener(TListaPosicion &listaposicion) const
{
    if(listaposicion.EsVacia()){
        return TPoro();
    }
    return listaposicion.pos->e;
}

bool TListaPoro::Buscar(const TPoro &poro) const
{
    TListaNodo *nodo = primero;
    while (nodo != nullptr)
    {
        if(nodo->e == poro){
            return true;
        }
        nodo = nodo->siguiente;
    }
    return false;
}

int TListaPoro::Longitud() const
{
    int longitud = 0;
    TListaNodo *nodo = primero;
    while (nodo != nullptr)
    {
        longitud++;
        nodo = nodo->siguiente;
    }
    return longitud;
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

TListaPoro TListaPoro::ExtraerRango(int num1, int num2)
{
    TListaPoro resultado;

    if(num1 > num2){
        return resultado;
    }

    int longuitud = Longitud();

    if(num1 <= 0){
        num1 = 1;
    }

    if (num2 > longuitud)
    {
        num2 = longuitud;
    }

    if (num1 > longuitud || num2 < 1)
    {
        return resultado;
    }
    
    TListaNodo *inicio = primero;
    for(int i = 1; i < num1; i++){
        inicio = inicio->siguiente;
    }

    TListaNodo *final = inicio;
    for(int i = num1; i < num2; i++){
        final = final->siguiente;
    }
    
    TListaNodo *nodo = inicio;
    while (nodo != final->siguiente)
    {
        resultado.Insertar(nodo->e);
        nodo = nodo->siguiente;
    }

    if(num1 == 1){
        if(num2 == longuitud){
            while (primero != nullptr)
            {
                TListaNodo *nodo = primero;
                primero = primero->siguiente;
                delete nodo;
            }
            primero = nullptr;
            ultimo = nullptr;
        }else{
            primero = final->siguiente;
            if(primero != nullptr){
                primero->anterior = nullptr;
            }
            nodo = inicio;
            while (nodo != final->siguiente)
            {
                TListaNodo *aux = nodo;
                nodo = nodo->siguiente;
                delete aux;
            }
        }
    }else if(num2 == longuitud){
        ultimo = inicio->anterior;
        ultimo->siguiente = nullptr;
        nodo = inicio;
        while (nodo != nullptr)
        {
            TListaNodo *aux = nodo;
            nodo = nodo->siguiente;
            delete aux;
        }
    }else{
        inicio->anterior->siguiente = final->siguiente;
        final->siguiente->anterior = inicio->anterior;
        nodo = inicio;
        while (nodo != final->siguiente)
        {
            TListaNodo *aux = nodo;
            nodo = nodo->siguiente;
            delete aux;
        }
    }
    return resultado;
}

ostream &operator<<(ostream &os, const TListaPoro &tlistaposicion)
{
    os << "(";
    if(tlistaposicion.primero != nullptr){
        TListaNodo *nodo = tlistaposicion.primero;
        while (nodo != nullptr)
        {
            os << nodo->e;
            if(nodo->siguiente != nullptr){
                os << " ";
            }
            nodo = nodo->siguiente;
        }
    }
    os << ")";
    return os;
}


