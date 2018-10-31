#ifndef BRUSH_H
#define BRUSH_H
#include "figurageometrica.h"
#include "screen.h"


class Brush: public FiguraGeometrica
{
private:
    char brush;
public:
    Brush(char _brush = ' ');
    void draw(Screen &tela);
};

#endif // BRUSH_H
