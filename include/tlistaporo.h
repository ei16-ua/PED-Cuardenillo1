#pragma once
#include "tporo.h"

class TListaNodo{
    private:
        TPoro e;
        TListaNodo *anterior;
        TListaNodo *siguiente;

    public:
        TListaNodo();
        TListaNodo(const TListaNodo &);
        ~TListaNodo();
        TListaNodo &operator=(const TListaNodo &);
};
class TListaPosicion {
    private:
        TListaNodo *pos;
        
    public:
        TListaPosicion();
        TListaPosicion(const TListaPosicion &);
        ~TListaPosicion();
        TListaPosicion &operator=(const TListaPosicion &);

        bool operator==(const TListaPosicion &) const;
        TListaPosicion Anterior() const;
        TListaPosicion Siguiente() const;
        bool EsVacia() const;
    };
    
class TListaPoro {
    private:
        TListaNodo *primero;
        TListaNodo *ultimo;

    public:
        TListaPoro();
        TListaPoro(const TListaPoro &);
        ~TListaPoro();
        TListaPoro &operator=(const TListaPoro &);

        bool operator==(const TListaPoro &) const;
        bool EsVacia() const;
        bool Insertar(const TPoro &);
        bool Borrar(const TPoro &);
        bool Borrar(TListaPosicion &);
        TPoro Obtener(TListaPosicion &) const;
        bool Buscar(const TPoro &) const;
        int Longitud() const;
        TListaPosicion Primera() const;
        TListaPosicion Ultima() const;
        TListaPoro ExtraerRango(int, int);
        friend ostream &operator<<(ostream &, const TListaPoro &);
};