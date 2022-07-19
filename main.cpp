#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>


using namespace std;

#include"rlutil.h"
#include"Class.h"
#include"Funciones.h"
#include "SubMenus.h"
#include"SSmenu.h"




int main(){
    int opc;
    while (true){
    textcolor(0,0);
    clrscr();
    recuadro(25, 3, 67, 16, cVERDE, cNEGRO);
    textcolor(cMAGENTA);

    gotoxy(53,7);
    cout<<"MENU PRINCIPAL"<<endl;
    gotoxy(43,8);
    cout<<"--------------------------------"<<endl;
    gotoxy(43,9);
    cout<<"1) MENU PRODUCTOS"<<endl;
    gotoxy(43,10);
    cout<<"2) MENU VENTAS"<<endl;
    gotoxy(43,11);
    cout<<"3) REPORTES"<<endl;
    gotoxy(43,12);
    cout<<"--------------------------------"<<endl;
    gotoxy(43,13);
    cout<<"0) FIN DEL PROGRAMA"<<endl<<endl;
    gotoxy(27,16);
    cout<<"SELECCIONE UNA DE LAS OPCIONES: ";
    cin>>opc;

switch(opc){
            case 1: SubMenuProductos();
                   break;

            case 2:SubMenuVentas();
                   break;

            case 3:Reportes();
                   break;

            case 0:clrscr();
                   recuadro(25, 3, 67, 6, cVERDE, cNEGRO);
                   gotoxy(50,6);
                   textcolor(cMAGENTA);
                   cout<<"FIN DEL PROGRAMA"<<endl;
                   gotoxy(1,20);
                   return 0;
                   break;

            default:
                    gotoxy(59,16);
                    textcolor(cROJO);
                    cout<<"OPCION INCORRECTA";
                    system("pause>nul");
                    system("cls");
          }
   }
        return 0;
}

