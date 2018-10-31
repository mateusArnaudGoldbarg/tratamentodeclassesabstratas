#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>


#include "screen.h"
#include "figurageometrica.h"
#include "line.h"
#include "brush.h"
#include "retangle.h"
#include "circle.h"

using namespace std;

int main()
{

    ifstream fin;
    ofstream fout;
    string arquivo, linha, cmd,arquivo2;
    int x,y,larg,alt,x0,y0;
    int xr,yr,largr,altr;
    int xc,yc,r;
    char brushc;
    char brushr;
    char brush;
    bool tipo,fm;
    Screen tela;
    stringstream ss;

    vector < FiguraGeometrica* > fig;
    vector < FiguraGeometrica* >::iterator it;

    cout <<"Digite o nome do arquivo que deseja abrir"<<endl;
    cin >> arquivo;
    fin.open(arquivo);


    if(fin.is_open()==true){
        cout << "arquivo aberto com sucesso" << endl << endl;
    } else{
        cout << "O arquivo nao pode ser aberto" << endl;
        exit(0);
    }



    while(fin.good()){
        getline(fin,linha);
        if(!fin.good()){
            break;
        }

        linha += " ";
        ss = stringstream (linha);
        ss >> cmd;

//================================dim======================================
        if (cmd.compare("dim")==0){
            ss >> larg >> alt;
            cout << cmd<<endl<<endl;

            tela = Screen(larg,alt);
//================================brush====================================
        }else if(cmd.compare("brush") == 0){

            ss >> brush;
            cout << cmd << endl<<endl;

            if(ss.good()){
                fig.push_back(new Brush(brush));
            } else{
                fig.push_back(new Brush(' '));
            }
            cout << brush << endl;

//================================Line=====================================
        } else if(cmd.compare("line") == 0){

            ss >> x0 >> y0 >> x >> y;
            cout << cmd << endl<<endl;

            fig.push_back(new Line(x0,y0,x,y));
//===============================Retangle==================================
        } else if(cmd.compare("retangle") ==0){
            cout <<cmd<< endl <<endl;
            ss >> xr >> yr >> largr >> altr >> tipo;


            ss>>brushr;
            cout << "brush = " <<brushr << endl;

            if(ss.good()){
                fig.push_back(new Brush(brushr));
            } else{
                fig.push_back(new Brush(' '));
            }



            fig.push_back(new Retangle(xr,yr,largr,altr,tipo,brushr));

            if(ss.good()){
                fig.push_back(new Brush(brush));
            } else{
                fig.push_back(new Brush(' '));
            }


//================================Circle===================================
        } else if (cmd.compare("circle")==0){
            cout <<cmd<< endl <<endl;
            ss >> xc >>yc>>r>>fm>>brushc;


            if(ss.good()){
                fig.push_back(new Brush(brushc));
            } else{
                fig.push_back(new Brush(' '));
            }

            fig.push_back(new Circle(xc,yc,r,fm,brushc));

           if(ss.good()){
               fig.push_back(new Brush(brush));
           } else{
               fig.push_back(new Brush(' '));
           }

        }

    }

    for (it=fig.begin();it!=fig.end();it++){
        (*it)->draw(tela);
    }
    cout << tela;

    fin.close();

    cout<<"Digite o nome do arquivo que deseja salvar" << endl;
    cin>>arquivo2;

    fout.open(arquivo2);

    if(fout.is_open()){
        cout <<"Arquivo criado com sucesso" <<endl;
    } else{
        cout <<"O arquivo nao pode ser criado" << endl;
    }

    fout << tela;

    fout.close();

    cout <<"Arquivo salvo com sucesso" << endl;

    return 0;
}
