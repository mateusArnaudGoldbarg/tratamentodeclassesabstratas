#ifndef RETANGLE_H
#define RETANGLE_H

#include "figurageometrica.h"
#include "screen.h"


class Retangle: public FiguraGeometrica
{
private:
    int x,y,larg,alt;
    bool p;
    char br;
public:
    Retangle(int _x=0, int _y=0, int _larg=0, int _alt=0, bool _p = false, char _br = ' ');
    void draw(Screen &tela);
};

#endif // RETANGLE_H
