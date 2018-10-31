#include "line.h"
#include "screen.h"

#include <iostream>
#include <cmath>

using namespace std;

Line::Line(int _x0, int _y0, int _x, int _y)
{
    x0 = _x0;
    y0 = _y0;
    x = _x;
    y = _y;
}

void Line::draw(Screen &tela){

int yv[100],xv[100];
int cont =0,cont1 =0,cont2=0,j;
float fim = x-x0;
float fim2 = y-y0;
float fim3 = x0-x;

            if(x0 == x){

                for (int i = 0; i<fim2;i++){

                    xv[i] = x0;
                    yv[i] = y0+ cont;
                    cont++;
                         tela.setPixel(yv[i],xv[i]);
                }
            }
            else if (y==y0){

                for (int i = 0; i<fim;i++){

                    xv[i] = x0+cont1;
                    yv[i] = y0;
                    cont1++;
                         tela.setPixel(yv[i],xv[i]);
                }
            }
            else if ((y !=y0) && (x0 !=x)){

                    float  m = fim2/fim;
                    float b = y0 - m*x0 ;

                    if (fim>0){

                    for (int i = 0; i<fim;i++){
                         xv[i] = x0+cont2;
                         yv[i] = m*xv[i]+b;
                         cont2++;
                         tela.setPixel(yv[i],xv[i]);
                        }
                    } else if(fim<0){
                        for (int i = 0; i<fim3;i++){
                             xv[i] = x0+cont2;
                             yv[i] = m*xv[i]+b;
                             cont2--;
                         tela.setPixel(yv[i],xv[i]);
                            }
                    }
            }
}
