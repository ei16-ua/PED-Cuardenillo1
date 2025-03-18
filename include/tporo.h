#ifndef _TPoro_H_
#define _TPoro_H_
#include <iostream>
using namespace std;

class TPoro{
    private:
        int x;
        int y;
        double volumen;
        char* color;
    
        

    public:
        TPoro();
        TPoro(int , int, double);
        TPoro(int, int, double, char *);
        TPoro(const TPoro &);
        ~TPoro();
        TPoro & operator=(const TPoro & );

        bool operator==(const TPoro & ) const;
        bool operator!=(const TPoro & ) const;
        void Posicion(int, int);
        void Volumen(double);
        void Color(char *);
        int PosicionX() const;
        int PosicionY() const;
        double Volumen() const;
        char * Color() const;
        bool EsVacio() const;



        friend ostream & operator<< (ostream &, TPoro &);
};

#endif
