#ifndef LINE_H
#define LINE_H

#include "figurageometrica.h"
#include "screen.h"

#include <iostream>

using namespace std;


class Line: public FiguraGeometrica
{
private:
    int x0,y0,x,y;
public:
    Line(int _x0,int _y0, int _x, int _y);
    void draw(Screen &tela);
};

#endif // LINE_H
