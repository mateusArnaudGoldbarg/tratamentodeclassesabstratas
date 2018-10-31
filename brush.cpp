#include "brush.h"
#include "screen.h"
#include<iostream>

using namespace std;

Brush::Brush(char _brush)
{
    brush = _brush;
}

void Brush::draw(Screen &tela){
    tela.setBrush(brush);
}
