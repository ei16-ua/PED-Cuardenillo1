#ifndef _TPoro_H_
#define _TPoro_H_
#include <iostream>

class TPoro{
    private:
        int x;
        int y;
        double volumen;
        char* color;
    
        

    public:
        TPoro();
        TPoro(int, int, double);
        TPoro(int, int, double, char *);
        TPoro(TPoro &);
        ~TPoro();
        TPoro & operator=(TPoro &);

        bool operator==(TPoro &);
        bool operator!=(TPoro &);
        void Posicion(int, int);
        void Volumen(double);
        void Color(char *);
        bool EsVacio();


        friend ostream & operator<< (ostream &, TPoro &);friend ostream & operator<< (ostream &, TPoro &);
};

#endif
