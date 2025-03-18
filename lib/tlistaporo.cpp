#include "tlistaporo.h"

// Implementación de TListaNodo
TListaNodo::TListaNodo() : anterior(nullptr), siguiente(nullptr) {}

TListaNodo::TListaNodo(const TListaNodo &n) : e(n.e), anterior(nullptr), siguiente(nullptr) {}

TListaNodo::~TListaNodo() {}

TListaNodo &TListaNodo::operator=(const TListaNodo &n) {
    if (this != &n) {
        e = n.e;
    }
    return *this;
}

// Implementación de TListaPosicion
TListaPosicion::TListaPosicion() : pos(nullptr) {}

TListaPosicion::TListaPosicion(const TListaPosicion &p) : pos(p.pos) {}

TListaPosicion::~TListaPosicion() {}

TListaPosicion &TListaPosicion::operator=(const TListaPosicion &p) {
    pos = p.pos;
    return *this;
}

bool TListaPosicion::operator==(const TListaPosicion &p) const {
    return pos == p.pos;
}

TListaPosicion TListaPosicion::Anterior() const {
    TListaPosicion nuevaPos;
    if (pos && pos->anterior)
        nuevaPos.pos = pos->anterior;
    return nuevaPos;
}

TListaPosicion TListaPosicion::Siguiente() const {
    TListaPosicion nuevaPos;
    if (pos && pos->siguiente)
        nuevaPos.pos = pos->siguiente;
    return nuevaPos;
}

bool TListaPosicion::EsVacia() const {
    return pos == nullptr;
}

// Implementación de TListaPoro
TListaPoro::TListaPoro() : primero(nullptr), ultimo(nullptr) {}

TListaPoro::TListaPoro(const TListaPoro &l) {
    Copiar(l);
}

TListaPoro::~TListaPoro() {
    while (!EsVacia()) {
        Borrar(Primera());
    }
}

TListaPoro &TListaPoro::operator=(const TListaPoro &l) {
    if (this != &l) {
        while (!EsVacia()) {
            Borrar(Primera());
        }
        Copiar(l);
    }
    return *this;
}

bool TListaPoro::operator==(const TListaPoro &l) const {
    TListaPosicion p1 = Primera(), p2 = l.Primera();
    while (!p1.EsVacia() && !p2.EsVacia()) {
        if (!(Obtener(p1) == l.Obtener(p2)))
            return false;
        p1 = p1.Siguiente();
        p2 = p2.Siguiente();
    }
    return p1.EsVacia() && p2.EsVacia();
}

bool TListaPoro::EsVacia() const {
    return primero == nullptr;
}

TListaPosicion TListaPoro::Primera() const {
    TListaPosicion p;
    p.pos = primero;
    return p;
}

TListaPosicion TListaPoro::Ultima() const {
    TListaPosicion p;
    p.pos = ultimo;
    return p;
}

std::ostream &operator<<(std::ostream &os, const TListaPoro &l) {
    os << "(";
    TListaPosicion p = l.Primera();
    while (!p.EsVacia()) {
        os << l.Obtener(p);
        p = p.Siguiente();
        if (!p.EsVacia()) os << " ";
    }
    os << ")";
    return os;
}
