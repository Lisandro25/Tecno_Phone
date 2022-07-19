#ifndef SUBMENUS_H_INCLUDED
#define SUBMENUS_H_INCLUDED

#include"SSmenu.h"
void SubMenuProductos();
void SubMenuVentas();
void Reportes();




void SubMenuProductos(){
     textcolor(0,0);
     clrscr();
     recuadro(25, 3, 67, 22, cVERDE, cNEGRO);
     textcolor(cMAGENTA);

     int opc1;

     gotoxy(53,7);
     cout<<"MENU PRODUCTOS"<<endl;
     gotoxy(43,8);
     cout<<"--------------------------------"<<endl;
     gotoxy(43,9);
     cout<<"1) AGREGAR PRODUCTO"<<endl;
     gotoxy(43,10);
     cout<<"2) MOSTRAR PRODUCTOS"<<endl;
     gotoxy(43,11);
     cout<<"3) AGREGAR STOCK "<<endl;
     gotoxy(43,12);
     cout<<"4) MODIFICAR PRODUCTO"<<endl;
     gotoxy(43,13);
     cout<<"5) ELIMINAR PRODUCTO "<<endl;
     gotoxy(43,14);
     cout<<"--------------------------------"<<endl;
     gotoxy(43,15);
     cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl<<endl;
     gotoxy(27,17);
     cout<<"SELECCIONE UNA DE LAS OPCIONES: ";
     cin>>opc1;

switch(opc1){

        case 1:AgregarProducto();
               system("pause>nul");
               system("cls");
               SubMenuProductos();
               break;

        case 2:MostrarP_x();
               system("pause>nul");
               system("cls");
               SubMenuProductos();
               break;

        case 3:if(AgregarStock()==true){
               gotoxy(27,16);
               textcolor(cVERDE_CLARO);
               cout<<"SE AGREGO CORRECTAMENTE EL STOCK";
               }
               system("pause>nul");
               system("cls");
               SubMenuProductos();
               break;

        case 4:ModificarProducto();
               system("pause>nul");
               system("cls");
               SubMenuProductos();
               break;

        case 5:if(EliminarProducto()==true){
               recuadro(38, 19, 42, 4, cVERDE, cNEGRO);
               gotoxy(41,21);
               textcolor(cVERDE_CLARO);
                cout<<" SE ELIMINO CORRECTAMENTE EL PRODUCTO";
               }
               system("pause>nul");
               system("cls");
               SubMenuProductos();
               break;


        case 0:
            return;
               break;

        default:
               gotoxy(59,17);
               textcolor(cROJO);
               cout<<"OPCION INCORRECTA";
               system("pause>nul");
               system("cls");
               SubMenuProductos();

}
}




void SubMenuVentas(){
     textcolor(0,0);
     clrscr();
     recuadro(25, 3, 67, 22, cVERDE, cNEGRO);
     textcolor(cMAGENTA);

     int opc2;

     gotoxy(53,7);
     cout<<"MENU DE VENTAS"<<endl;
     gotoxy(43,8);
     cout<<"-----------------------------------"<<endl;
     gotoxy(43,9);
     cout<<"1) REGISTRAR VENTA"<<endl;
     gotoxy(43,10);
     cout<<"2) MOSTRAR VENTAS"<<endl;
     gotoxy(43,11);
     cout<<"3) MODIFICAR DATOS DE VENTA"<<endl;
     gotoxy(43,12);
     cout<<"4) ANULAR VENTA POR ID"<<endl;
     gotoxy(43,13);
     cout<<"-----------------------------------"<<endl;
     gotoxy(43,14);
     cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl<<endl;
     gotoxy(27,16);
     cout<<"SELECCIONE UNA DE LAS OPCIONES: ";
     cin>>opc2;

switch(opc2){
        case 1:AgregarVenta();
               system("cls");
               SubMenuVentas();
               break;

        case 2:MostrarV_x();
               system("pause>nul");
               system("cls");
               SubMenuVentas();
               break;

        case 3:ModificarVENTA();
               system("cls");
               SubMenuVentas();
               break;

        case 4:if(CancelarVentaxID()==true){
               recuadro(40, 23, 33, 4, cVERDE, cNEGRO);
               gotoxy(45,25);
               textcolor(cVERDE_CLARO);
               cout<<"VENTA CANCELADA CON EXITO";
          }
               system("pause>nul");
               system("cls");
               SubMenuVentas();
               break;

        case 0:return;
               break;

        default:
               gotoxy(59,16);
               textcolor(cROJO);
               cout<<"OPCION INCORRECTA";
               system("pause>nul");
               system("cls");
               SubMenuVentas();
    }
}


void Reportes(){
     textcolor(0,0);
     clrscr();
     recuadro(25, 3, 67, 22, cVERDE, cNEGRO);
     textcolor(cMAGENTA);

     int opc3;

     gotoxy(53,7);
     cout<<"REPORTES"<<endl;
     gotoxy(43,8);
     cout<<"-----------------------------------"<<endl;
     gotoxy(43,9);
     cout<<"1) RECAUDACIONES"<<endl;
     gotoxy(43,10);
     cout<<"2) VENTAS TOTALES"<<endl;
     gotoxy(43,11);
     cout<<"3) TOTAL DE EQUIPOS VENDIDOS"<<endl;
     gotoxy(43,12);
     cout<<"-----------------------------------"<<endl;
     gotoxy(43,13);
     cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl<<endl;
     gotoxy(27,15);
     cout<<"SELECCIONE UNA DE LAS OPCIONES: ";
     cin>>opc3;

switch(opc3){
        case 1:Recaudaciones();
               break;

        case 2:VentasTotales();
               break;

        case 3:TotalEquiposVendidos();
               break;

        case 0:return;
               break;

        default:
               gotoxy(59,16);
               textcolor(cROJO);
               cout<<"OPCION INCORRECTA";
               system("pause>nul");
               system("cls");
    }
}




#endif // SUBMENUS_H_INCLUDED
