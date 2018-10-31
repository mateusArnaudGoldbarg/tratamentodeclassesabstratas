#ifndef CIRCLE_H
#define CIRCLE_H

#include "figurageometrica.h"
#include "screen.h"

class Circle: public FiguraGeometrica
{
private:
    int x;
    int y;
    float r;
    bool fm;
    char br;
public:
    Circle(int _x =0 , int _y = 0, int r = 0, bool _fm = false, char _br = ' ');
    void draw(Screen &t);

    void pontos(int x1, int y1, Screen &t);
};



#endif // CIRCLE_H
