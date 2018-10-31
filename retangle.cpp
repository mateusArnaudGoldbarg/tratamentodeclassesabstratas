#include "retangle.h"
#include "screen.h"
#include "line.h"

#include<iostream>

using namespace std;

Retangle::Retangle(int _x, int _y, int _larg, int _alt, bool _p, char _br)
{
    x = _x;
    y = _y;
    larg = _larg;
    alt = _alt;
    p = _p;
    br = _br;
}

void Retangle::draw(Screen &tela)
{
    int a,b;
    a = alt +y;
    b = larg +x;
    if(p == 1){
        cout<<"o brush aqui eh : " << br << endl;
        for (int i = y;i<a;i++){
            for(int j = x;j<b ; j++){
                tela.setPixel(i,j);
            }
        }
    }
    else{
        Line l1(x,y,b,y);
            l1.draw(tela);
        Line l2(b,y,b,a);
            l2.draw(tela);
        Line l3(x,a,b,a);
            l3.draw(tela);
        Line l4(x,y,x,a);
            l4.draw(tela);

    }
}


