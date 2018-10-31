#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

#include "screen.h"


class FiguraGeometrica
{
public:
    FiguraGeometrica();
    virtual void draw (Screen &tela) = 0;
};

#endif // FIGURAGEOMETRICA_H
