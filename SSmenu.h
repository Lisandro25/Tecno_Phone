#ifndef SSMENU_H_INCLUDED
#define SSMENU_H_INCLUDED



void MostrarP_x();
void ModificarProducto();

void MostrarV_x();

void Reportes();
void Recaudaciones();
void VentasTotales();
void TotalEquiposVendidos();



void MostrarP_x(){
     textcolor(0,0);
     clrscr();
     recuadro(25, 3, 67, 22, cVERDE, cNEGRO);
     textcolor(cMAGENTA);

     int opc;

     gotoxy(53,8);
     cout<<"PRODUCTOS"<<endl;
     gotoxy(43,9);
     cout<<"-----------------------------"<<endl;
     gotoxy(43,10);
     cout<<"1) LISTAR POR ID"<<endl;
     gotoxy(43,11);
     cout<<"2) LISTAR POR MARCA"<<endl;
     gotoxy(43,12);
     cout<<"3) LISTAR TODOS"<<endl;
     gotoxy(43,13);
     cout<<"-----------------------------"<<endl;
     gotoxy(43,14);
     cout<<"0) VOLVER AL MENU ANTERIOR"<<endl<<endl;
     gotoxy(27,16);
     cout<<"SELECCIONE UNA DE LAS OPCIONES: ";
     cin>>opc;

    switch(opc){

        case 1:ProductoPorID();
               system("pause>nul");
               MostrarP_x();
               break;

        case 2:MostrarProductoxMarca();
               system("pause>nul");
               MostrarP_x();
               break;


        case 3:MostrarProductos();
               system("pause>nul");
               MostrarP_x();
               break;

        case 0:return;
               break;

        default:
               gotoxy(59,16);
               textcolor(cROJO);
               cout<<"OPCION INCORRECTA";
               system("pause>nul");
               MostrarP_x();

}
}


void ModificarProducto(){
     int pos, opc;
     pos=MuestraYpos();
     if(pos==-1)return;

     gotoxy(43,14);
     cout<<"-----------------------------"<<endl;
     gotoxy(43,15);
     cout<<"1) MODIFICAR MARCA"<<endl;
     gotoxy(43,16);
     cout<<"2) MODIFICAR MODELO"<<endl;
     gotoxy(43,17);
     cout<<"3) MODIFICAR PRECIO"<<endl;
     gotoxy(43,18);
     cout<<"4) MODIFICAR STOCK"<<endl;
     gotoxy(43,19);
     cout<<"-----------------------------"<<endl;
     gotoxy(43,20);
     cout<<"0) VOLVER AL MENU ANTERIOR"<<endl<<endl;
     gotoxy(27,22);
     cout<<"SELECCIONE UNA DE LAS OPCIONES: ";
     cin>>opc;

 switch(opc){

        case 1:ModificarMARCA(pos);
               break;

        case 2:ModificarMODELO(pos);
               break;

        case 3:ModificarPRECIO(pos);
               break;

        case 4:ModificarNstock(pos);
               break;


       case 0:
              return;
               break;

        default:
               gotoxy(59,22);
               textcolor(cROJO);
               cout<<"OPCION INCORRECTA";
      }
 }





void MostrarV_x(){
     textcolor(0,0);
     clrscr();
     recuadro(25, 3, 67, 22, cVERDE, cNEGRO);
     textcolor(cMAGENTA);

     int opc;

     gotoxy(53,8);
     cout<<"VENTAS"<<endl;
     gotoxy(43,9);
     cout<<"-----------------------------"<<endl;
     gotoxy(43,10);
     cout<<"1) LISTAR POR ID"<<endl;
     gotoxy(43,11);
     cout<<"2) LISTAR POR FECHA"<<endl;
     gotoxy(43,12);
     cout<<"3) LISTAR TODAS"<<endl;
     gotoxy(43,13);
     cout<<"-----------------------------------"<<endl;
     gotoxy(43,14);
     cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl<<endl;
     gotoxy(27,16);
     cout<<"SELECCIONE UNA DE LAS OPCIONES: ";
     cin>>opc;

switch(opc){
        case 1:VentasPorID();
               system("pause>nul");
               MostrarV_x();
               break;

        case 2:VentasPorFECHA();
               MostrarV_x();
               break;

        case 3:MostrarVentas();
               system("pause>nul");
               MostrarV_x();
               break;

        case 0:
              return;
               break;

        default:
               gotoxy(59,16);
               textcolor(cROJO);
               cout<<"OPCION INCORRECTA";
               pause();
               MostrarV_x();
}

}






void ModificarVENTA(){
     int pos, opc;
     pos=MuestraYposVENTAS();
     if(pos==-1){
        return;
     }
     gotoxy(43,17);
     cout<<"1) MODIFICAR FECHA"<<endl;
      gotoxy(43,18);
     cout<<"2) MODIFICAR NOMBRE DEL CLIENTE"<<endl;
      gotoxy(43,19);
     cout<<"3) MODIFICAR DNI"<<endl;
     gotoxy(43,20);
     cout<<"-----------------------------"<<endl;
     gotoxy(43,21);
     cout<<"0) VOLVER AL MENU ANTERIOR"<<endl<<endl;
     gotoxy(27,23);
     cout<<"SELECCIONE UNA DE LAS OPCIONES: ";
     cin>>opc;

 switch(opc){

        case 1:ModificarFECHA(pos);
               break;

        case 2:ModificarNOMBRE(pos);
               break;

        case 3:ModificarDNI(pos);
               break;

        case 0:
              return;
               break;

        default:
               gotoxy(59,23);
               textcolor(cROJO);
               cout<<"OPCION INCORRECTA";
               pause();
}
 }




 void Recaudaciones(){
     textcolor(0,0);
     clrscr();
     recuadro(25, 3, 67, 22, cVERDE, cNEGRO);
     textcolor(cMAGENTA);

     int opc;

     gotoxy(53,8);
     cout<<"RECAUDACIONES"<<endl;
     gotoxy(43,9);
     cout<<"-----------------------------"<<endl;
     gotoxy(43,10);
     cout<<"1) TOTAL X DIAS"<<endl;
     gotoxy(43,11);
     cout<<"2) TOTAL X MES"<<endl;
     gotoxy(43,12);
     cout<<"3) TOTAL X ANIO"<<endl;
     gotoxy(43,13);
     cout<<"-----------------------------"<<endl;
     gotoxy(43,14);
     cout<<"0) VOLVER AL MENU ANTERIOR"<<endl<<endl;
     gotoxy(27,16);
     cout<<"SELECCIONE UNA DE LAS OPCIONES: ";
     cin>>opc;

    switch(opc){

        case 1:TODASrecaudacion(1);
               Recaudaciones();
               break;

        case 2:TODASrecaudacion(2);
               Recaudaciones();
               break;


        case 3:TODASrecaudacion(3);
               Recaudaciones();
               break;

        case 0:Reportes();
               break;

        default:
               gotoxy(59,16);
               textcolor(cROJO);
               cout<<"OPCION INCORRECTA";
               system("pause>nul");
               Reportes();

}
}



void VentasTotales(){
     textcolor(0,0);
     clrscr();
     recuadro(25, 3, 67, 22, cVERDE, cNEGRO);
     textcolor(cMAGENTA);

     int opc;

     gotoxy(50,8);
     cout<<"VENTAS TOTALES"<<endl;
     gotoxy(43,9);
     cout<<"-----------------------------"<<endl;
     gotoxy(43,10);
     cout<<"1) TOTAL X DIAS"<<endl;
     gotoxy(43,11);
     cout<<"2) TOTAL X MES"<<endl;
     gotoxy(43,12);
     cout<<"3) TOTAL X ANIO"<<endl;
     gotoxy(43,13);
     cout<<"-----------------------------"<<endl;
     gotoxy(43,14);
     cout<<"0) VOLVER AL MENU ANTERIOR"<<endl<<endl;
     gotoxy(27,16);
     cout<<"SELECCIONE UNA DE LAS OPCIONES: ";
     cin>>opc;

    switch(opc){

        case 1:TODASVentas(1);
               VentasTotales();
               break;

        case 2:TODASVentas(2);
               VentasTotales();
               break;


        case 3: TODASVentas(3);
               VentasTotales();
               break;

        case 0:Reportes();
               break;

        default:
               gotoxy(59,16);
               textcolor(cROJO);
               cout<<"OPCION INCORRECTA";
               system("pause>nul");
               Reportes();

}
}



void TotalEquiposVendidos(){
     textcolor(0,0);
     clrscr();
     recuadro(25, 3, 67, 22, cVERDE, cNEGRO);
     textcolor(cMAGENTA);

     int opc;

     gotoxy(50,8);
     cout<<"EQUIPOS VENDIDOS"<<endl;
     gotoxy(43,9);
     cout<<"-----------------------------"<<endl;
     gotoxy(43,10);
     cout<<"1) TOTAL X DIAS"<<endl;
     gotoxy(43,11);
     cout<<"2) TOTAL X MES"<<endl;
     gotoxy(43,12);
     cout<<"3) TOTAL X ANIO"<<endl;
     gotoxy(43,13);
     cout<<"-----------------------------"<<endl;
     gotoxy(43,14);
     cout<<"0) VOLVER AL MENU ANTERIOR"<<endl<<endl;
     gotoxy(27,16);
     cout<<"SELECCIONE UNA DE LAS OPCIONES: ";
     cin>>opc;

    switch(opc){

        case 1:TODASVentaEquipos(1);
               TotalEquiposVendidos();
               break;

        case 2:TODASVentaEquipos(2);
               TotalEquiposVendidos();
               break;


        case 3:TODASVentaEquipos(3);
               TotalEquiposVendidos();
               break;

        case 0:Reportes();
               break;

        default:
               gotoxy(59,16);
               textcolor(cROJO);
               cout<<"OPCION INCORRECTA";
               system("pause>nul");
               Reportes();

}
}




#endif // SSMENU_H_INCLUDED
