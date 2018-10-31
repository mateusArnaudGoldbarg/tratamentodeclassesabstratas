#include "circle.h"
#include "screen.h"
#include <cmath>

#include <iostream>


Circle::Circle(int _x, int _y, int _r, bool _fm, char _br){
    x = _x;
    y = _y;
    r = _r;
    fm = _fm;
    br = _br;
}



void Circle::draw(Screen &tela){

    if (fm == true){
        for (int i=x-r;i<x+r;i++){
            for(int j =y-r;j<y+r;j++){
                if((i-x)*(i-x) + (j-y)*(j-y) <= (r*r)){
                    tela.setPixel(i,j);
                }
            }
        }

    } else{
        for (int i=x-r;i<x+r+1;i++){
            for(int j =y-r;j<y+r+1;j++){
                int R = sqrt((i-x)*(i-x) + (j-y)*(j-y));
                if(R==r){
                    tela.setPixel(i,j);
                }
            }
        }
        }
    }

