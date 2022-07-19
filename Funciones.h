#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


/// PROTOTIPOS

void AgregarProducto();
void ProductoPorID();
void MostrarProductoxMarca();
void MostrarProductos();
bool AgregarStock();
void ModificarMARCA();
void ModificarMODELO();
void ModificarPRECIO();
void ModificarNstock();
int MuestraYpos();

bool EliminarProducto();

void AgregarVenta();
void disminuirStock(int IDp, int cantidad);

void VentasPorID();
void VentasPorFECHA();
void MostrarVentas();
void RecaudacionVentasPorFECHA();
float RecTotalxID(int ID);
bool CancelarVentaxID();
bool ReintegrarStock(int IDp, int cantidad);

int MuestraYposVENTAS();
void ModificarFECHA(int pos);
void ModificarNOMBRE(int pos);
void ModificarDNI(int pos);

int BuscarIDproducto(int IDprod);

void TODASrecaudacion(int Dia1_Mes2_Anio3);

void TODASVentas(int Dia1_Mes2_Anio3);

void TODASVentaEquipos(int Dia1_Mes2_Anio3);

void AgregarProducto(){
     textcolor(0,0);
     clrscr();
     recuadro(25, 3, 67, 16, cVERDE, cNEGRO);
     textcolor(cMAGENTA);

     Producto cel;
     cel.Cargar();
     if(cel.getActivo()==true){
        if(cel.grabarEnDisco()==true){
           gotoxy(28,13);
           textcolor(cVERDE_CLARO);
           cout<<"PRODUCTO AGREGADO!"<<endl;
        }
      }
       else{
            clrscr();
            recuadro(25, 3, 67, 7, cVERDE, cNEGRO);
            gotoxy(43,6);
            textcolor(cROJO);
            cout<<"EL PRODUCTO NO PUDO SER AGREGADO"<<endl;
       }
}


void ProductoPorID(){
     textcolor(0,0);
     clrscr();
     recuadro(25, 3, 67, 16, cVERDE, cNEGRO);
     textcolor(cMAGENTA);

     Producto cel;
     int pos=0, IDp;
     gotoxy(28,5);
     cout<<"INGRESAR ID DEL PRODUCTO A MOSTRAR: ";
     cin>>IDp;
     while(cel.leerDeDisco(pos++)==true){
           if(cel.getIDProducto()==IDp){
              if(cel.getActivo()==true){
                 textcolor(cBLANCO);
                 gotoxy(32,9);
                 cout<<"ID";
                 gotoxy(38,9);
                 cout<<"MARCA";
                 gotoxy(53,9);
                 cout<<"MODELO";
                 gotoxy(72,9);
                 cout<<"PRECIO U.";
                 gotoxy(83,9);
                 cout<<"STOCK";
                 textcolor(cMAGENTA);
                 cel.Mostrar(10);
                 return;
              }
                recuadro(32, 8, 55, 6, cROJO, cNEGRO);
                gotoxy(41,11);
                textcolor(cROJO);
                cout<<"NO SE ENCONTRO PRODUCTO CON ESE ID";
           }
     }
      recuadro(32, 8, 55, 6, cROJO, cNEGRO);
      gotoxy(41,11);
      textcolor(cROJO);
      cout<<"NO SE ENCONTRO PRODUCTO CON ESE ID";
}


void MostrarProductoxMarca(){
     textcolor(0,0);
     clrscr();
     recuadro(25, 3, 67, 16, cVERDE, cNEGRO);
     textcolor(cMAGENTA);

     Producto cel;
     int N=0, i=6;
     char nombreMarca[30];
     gotoxy(28,5);
     cout<<"INGRESAR LA MARCA DEL PRODUCTO: ";
     gotoxy(60,5);
     cargarCadena(nombreMarca,29);
     int pos=0;
     clrscr();


    while(cel.leerDeDisco(pos++)){
          if(strcmp(cel.getMarca(),nombreMarca)==0){
             if(cel.getActivo()==true){
                recuadro(25, 3, 67, 22, cVERDE, cNEGRO);
                textcolor(cBLANCO);
                gotoxy(32,4);
                cout<<"ID";
                gotoxy(38,4);
                cout<<"MARCA";
                gotoxy(53,4);
                cout<<"MODELO";
                gotoxy(72,4);
                cout<<"PRECIO";
                gotoxy(83,4);
                cout<<"STOCK";
                }
          }
    }
    pos=0;
     while(cel.leerDeDisco(pos++)){
          if(strcmp(cel.getMarca(),nombreMarca)==0){
             if(cel.getActivo()==true){
                textcolor(cMAGENTA);
                cel.Mostrar(i);
                N++;
                i++;
               cout<<endl;
          }
          }
     }
     if(N==0){
        clrscr();
        recuadro(25, 3, 67, 7, cVERDE, cNEGRO);
        gotoxy(44,6);
        textcolor(cROJO);
        cout<<"LA MARCA INGRESADA NO EXISTE";
     }
}


void MostrarProductos(){
     Producto cel;
     int i=6;
     FILE *pProd;
     pProd=fopen("Producto.dat", "rb");
     if(pProd==NULL){
        clrscr();
        recuadro(25, 3, 67, 7, cVERDE, cNEGRO);
        gotoxy(44,6);
        textcolor(cROJO);
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return;
      }
      clrscr();
      recuadro(25, 3, 67, 22, cVERDE, cNEGRO);
      textcolor(cBLANCO);
      gotoxy(32,4);
      cout<<"ID";
      gotoxy(38,4);
      cout<<"MARCA";
      gotoxy(53,4);
      cout<<"MODELO";
      gotoxy(72,4);
      cout<<"PRECIO";
      gotoxy(83,4);
      cout<<"STOCK";


     while(fread(&cel,sizeof cel,1,pProd)==1){
           textcolor(cMAGENTA);
           if(cel.getActivo()==true){
             cel.Mostrar(i);
             cout<<endl;
             i++;
           }
     }
     fclose(pProd);
}


bool AgregarStock(){
     textcolor(0,0);
     clrscr();
     recuadro(25, 3, 69, 16, cVERDE, cNEGRO);
     textcolor(cMAGENTA);

     int IDp,pos,Nstock;
     bool modifico;
     Producto cel;
     gotoxy(27,5);
     cout<<"INGRESAR EL ID DEL PRODUCTO AL QUE SE LE AGREGARA NUEVO STOCK: ";
     cin>>IDp;
     pos=BuscarIDproducto(IDp);
     if(pos==-1){
        recuadro(32, 8, 55, 6, cROJO, cNEGRO);
        gotoxy(41,11);
        textcolor(cROJO);
        cout<<"NO SE ENCONTRO PRODUCTO CON ESE ID"<<endl;
        return false;
    }
    cel.leerDeDisco(pos-1);

    textcolor(cBLANCO);
    gotoxy(32,9);
    cout<<"ID";
    gotoxy(38,9);
    cout<<"MARCA";
    gotoxy(53,9);
    cout<<"MODELO";
    gotoxy(72,9);
    cout<<"PRECIO";
    gotoxy(83,9);
    cout<<"STOCK";
    textcolor(cMAGENTA);
    cel.Mostrar(10);
    cout<<endl;
    gotoxy(27,14);
    cout<<"INGRESAR EL STOCK A AGREGAR: ";
    gotoxy(56,14);
    cin>>Nstock;
    if(Nstock>=1){
       cel.setStock(cel.getStock()+Nstock);
       modifico=cel.modificarEnDisco(pos-1);
       return modifico;
     }
      else{
           gotoxy(27,16);
           textcolor(cROJO);
           cout<<"[ERROR] AL AGREGAR STOCK"<<endl;
           gotoxy(27,17);
           cout<<"SOLO SE PUEDEN INGRESAR CANTIDADES POSITIVAS";
           return false;
       }
}


int MuestraYpos(){
     textcolor(0,0);
     clrscr();
     recuadro(25, 3, 67, 25, cVERDE, cNEGRO);
     textcolor(cMAGENTA);

     Producto cel;
     int IDp,pos;

     gotoxy(27,5);
     cout<<"INGRESAR ID DEL PRODUCTO A MODIFICAR: ";
     cin>>IDp;
     pos=BuscarIDproducto(IDp);
     if(pos==-1){
        recuadro(32, 8, 55, 6, cROJO, cNEGRO);
        gotoxy(41,11);
        textcolor(cROJO);
        cout<<"NO SE ENCONTRO PRODUCTO CON ESE ID";
        return -1;
     }
     cel.leerDeDisco(pos-1);
     textcolor(cBLANCO);
          gotoxy(32,9);
          cout<<"ID";
          gotoxy(38,9);
          cout<<"MARCA";
          gotoxy(53,9);
          cout<<"MODELO";
          gotoxy(72,9);
          cout<<"PRECIO";
          gotoxy(83,9);
          cout<<"STOCK";


     textcolor(cMAGENTA);
     cel.Mostrar(10);
     return pos;
}


void ModificarMARCA(int pos){
     Producto cel;
     char Nmarca[30];

     cel.leerDeDisco(pos-1);
     gotoxy(27,24);
     cout<<"MARCA: ";
     cargarCadena(Nmarca,29);
     cel.setMarca(Nmarca);
     if(cel.modificarEnDisco(pos-1)==true){
        gotoxy(27,26);
        textcolor(cVERDE_CLARO);
        cout<<"SE MODIFICO CORRECTAMENTE";
     }
 }


void ModificarMODELO(int pos){
     Producto cel;
     char Nmodelo[30];

     cel.leerDeDisco(pos-1);
     gotoxy(27,24);
     cout<<"MODELO: ";
     cargarCadena(Nmodelo,29);
     cel.setModelo(Nmodelo);;
     if(cel.modificarEnDisco(pos-1)==true){
        gotoxy(27,26);
        textcolor(cVERDE_CLARO);
        cout<<"SE MODIFICO CORRECTAMENTE ";
     }
}


void ModificarPRECIO(int pos){
     Producto cel;
     float Nprecio;

     cel.leerDeDisco(pos-1);
     gotoxy(27,24);
     cout<<"PRECIO: $";
     cin>>Nprecio;
     if(Nprecio>0){
        cel.setPrecio(Nprecio);
     }
      else{
          gotoxy(44,24);
          textcolor(cROJO);
          cout<<"[ERROR] PRECIO INGRESADO NO ADMITIDO";
          return;
      }
     if(cel.modificarEnDisco(pos-1)==true){
        gotoxy(27,26);
        textcolor(cVERDE_CLARO);
        cout<<"SE MODIFICO CORRECTAMENTE";
     }
}


void ModificarNstock(int pos){
     Producto cel;
     int Nstock;

     cel.leerDeDisco(pos-1);
     gotoxy(27,24);
     cout<<"STOCK: ";
     cin>>Nstock;
     if(Nstock>0){
        cel.setStock(Nstock);
     }
      else{
          gotoxy(44,24);
          textcolor(cROJO);
          cout<<"[ERROR] STOCK INGRESADO NO ADMITIDO";
          return;
      }
     if(cel.modificarEnDisco(pos-1)==true){
        gotoxy(27,26);
        textcolor(cVERDE_CLARO);
        cout<<"SE MODIFICO CORRECTAMENTE ";
       }
}


bool EliminarProducto(){
     textcolor(0,0);
     clrscr();
     recuadro(25, 3, 67, 21, cVERDE, cNEGRO);
     textcolor(cMAGENTA);

     Producto cel;
     int IDp,pos, opc;
     bool modifico;
     gotoxy(28,5);
     cout<<"INGRESAR ID DEL PRODUCTO A BORRAR: ";
     cin>>IDp;

     pos=BuscarIDproducto(IDp);
     if(pos==-1){
        recuadro(32, 8, 55, 6, cROJO, cNEGRO);
        gotoxy(41,11);
        textcolor(cROJO);
        cout<<"NO SE ENCONTRO PRODUCTO CON ESE ID";
        return false;
     }

     textcolor(cBLANCO);
     gotoxy(32,9);
     cout<<"ID";
     gotoxy(38,9);
     cout<<"MARCA";
     gotoxy(53,9);
     cout<<"MODELO";
     gotoxy(72,9);
     cout<<"PRECIO";
     gotoxy(83,9);
     cout<<"STOCK";

     textcolor(cMAGENTA);
     cel.leerDeDisco(pos-1);
     cel.Mostrar(10);
     cout<<endl;
     gotoxy(28,15);
     cout<<"SEGURO QUE DESEA ELIMINARLO?"<<endl;
     gotoxy(28,16);
     cout<<"1) SI       2) NO"<<endl;
     gotoxy(57,16);
     cout<<"RESPUESTA: ";
     cin>>opc;
     switch (opc){

             case 1:cel.leerDeDisco(pos-1);
                    cel.setActivo(false);
                    modifico=cel.modificarEnDisco(pos-1);
                    return modifico;
                    break;

             case 2:
                    recuadro(38, 19, 42, 4, cROJO, cNEGRO);
                    gotoxy(47,21);
                    textcolor(cROJO);
                    cout<<" NO SE ELIMINO EL PRODUCTO";
                    return false;
                    break;

             default:
                    gotoxy(68,16);
                    textcolor(cROJO);
                    cout<<"OPCION INCORRECTA";
                    return false;
                    break;
     }

}


///--////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///--////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void AgregarVenta(){
     textcolor(0,0);
     clrscr();
     recuadro(25, 3, 67, 23, cVERDE, cNEGRO);
     textcolor(cMAGENTA);

     VentaDetalle det;
     VentaCabecera cab;
     det.CargarVd();
     cout<<endl;
     if(det.getActivo()==true){
        disminuirStock(det.getIDProducto(),det.getCantidad());
        det.grabarEnDisco();
      }
       else{
            return;
       }

      cab.CargarVc();
      if(cab.getActivo()==true){
         if(cab.grabarEnDisco()==true){
            system("pause>nul");
            gotoxy(45,23);
            textcolor(cVERDE_CLARO);
            cout<<"REGISTRO DE VENTA AGREGADO"<<endl;
            pause();
         }
       }
        else{
             gotoxy(45,23);
             textcolor(cROJO);
             cout<<"NO SE PUDO AGREGAR EL REGISTRO DE VENTA"<<endl;
             pause();
        }
}


void disminuirStock(int IDp, int cantidad){
     Producto cel;
     int pos;
     pos=BuscarIDproducto(IDp);
     if(pos==-1){
        return;
     }
     cel.leerDeDisco(pos-1);
     cel.setStock(cel.getStock()- cantidad);
     cel.modificarEnDisco(pos-1);
     return;
}


void VentasPorID(){
     textcolor(0,0);
     clrscr();
     recuadro(25, 3, 70, 23, cVERDE, cNEGRO);
     textcolor(cMAGENTA);

     VentaDetalle det;
     VentaCabecera cab;
     int pos=0, IDv;
     gotoxy(27,5);
     cout<<"INGRESAR EL ID DE LA VENTA A MOSTRAR: ";
     cin>>IDv;

     while(det.leerDeDisco(pos++)==true){
           if(det.getIDVenta()==IDv){
              if(det.getActivo()==true){
                 det.MostrarVd1(6);
                 cab.leerDeDisco(pos-1);
                 if(cab.getActivo()==true){
                    cab.MostrarVc1(6);
                    return;
                 }
              }
            }
     }
     recuadro(32, 8, 55, 6, cROJO, cNEGRO);
     gotoxy(36,11);
     textcolor(cROJO);
     cout<<"[ERROR] NO SE ENCONTRO VENTA CON EL ID INGRESADO";
}


void VentasPorFECHA(){
     textcolor(0,0);
     clrscr();
     recuadro(25, 3, 67, 23, cVERDE, cNEGRO);
     textcolor(cMAGENTA);

     VentaDetalle det;
     VentaCabecera cab;
     Fecha F;
     int pos=0, muestra=0, i=0;
     gotoxy(27,5);
     cout<<"INGRESAR FECHA DE LAS VENTA A MOSTRAR: "<<endl;
     if(F.Cargar1(0)==false){
        muestra=1;
        return;
     }
     clrscr();
     while(det.leerDeDisco(pos++)==true){
          if(det.getFechaVenta().getdia()==F.getdia())
             if(det.getFechaVenta().getmes()==F.getmes())
                if(det.getFechaVenta().getanio()==F.getanio()){
                   if(det.getActivo()==true){
                      det.MostrarVd1(i);
                      cab.leerDeDisco(pos-1);
                      if(cab.getActivo()==true){
                         cab.MostrarVc1(i);
                         muestra++;
                         i=i+11;
                         cout<<endl;
                      }
                   }
                }
      }

      if(muestra==0){
         recuadro(25, 3, 67, 7, cVERDE, cNEGRO);
         gotoxy(37,6);
         textcolor(cROJO);
         cout<<"NO SE REGISTRARON VENTAS EN LA FECHA INGRESADA";
         pause();
       }
       else{
            pause();
       }

}


void MostrarVentas(){
    recuadro(25, 3, 70, 23, cVERDE, cNEGRO);
     textcolor(cMAGENTA);
     VentaDetalle det;
     VentaCabecera cab;
     int pos=0, i=0;;
     clrscr();
     while(det.leerDeDisco(pos++)==true){
          if(det.getActivo()==true){
             det.MostrarVd1(i);
             cab.leerDeDisco(pos-1);
             if(cab.getActivo()==true){
                cab.MostrarVc1(i);
                i=i+11;
                cout<<endl;

             }
           }
     }
}




float RecTotalxID(int ID){
      VentaCabecera cab;
      int pos=0;
      float Rtotal;
      while(cab.leerDeDisco(pos++)==true){
            if(cab.getIDventa()==ID){
               if(cab.getActivo()==true){
                  Rtotal=cab.getImporteTotal();
               }
            }
      }
      return Rtotal;
}


int MuestraYposVENTAS(){
     textcolor(0,0);
     clrscr();
     recuadro(25, 2, 70, 29, cVERDE, cNEGRO);
     textcolor(cMAGENTA);

     VentaDetalle det;
     VentaCabecera cab;
     int IDv,pos;

     gotoxy(27,3);
     cout<<"INGRESAR ID DE LA VENTA A MODIFICAR: ";
     cin>>IDv;
     pos=BuscarIDventa(IDv);
     if(pos==-1){
        recuadro(30, 8, 55, 6, cROJO, cNEGRO);
        gotoxy(42,11);
        textcolor(cROJO);
        cout<<"NO SE ENCONTRO VENTA CON ESE ID";
        pause();
        return -1;
     }
     det.leerDeDisco(pos);
     textcolor(cMAGENTA);
     det.MostrarVd1(2);
     cab.leerDeDisco(pos);
     cab.MostrarVc1(2);
     return pos;
}


void ModificarFECHA(int pos){
     VentaDetalle det;
     Fecha F;

     det.leerDeDisco(pos);
     gotoxy(27,25);
     cout<<"NUEVA FECHA "<<endl;

     if(F.Cargar1(19)==false){
        return;
     }

     det.setFechaVenta(F);
     if(det.modificarEnDisco(pos)==true){
        gotoxy(27,29);
        textcolor(cVERDE_CLARO);
        cout<<"SE MODIFICO CORRECTAMENTE";
        pause();
     }
}


void ModificarNOMBRE(int pos){
     VentaCabecera cab;
     char NOMBRE[30];

     cab.leerDeDisco(pos);
     gotoxy(27,27);
     cout<<"NOMBRE: ";
     cargarCadena(NOMBRE,29);
     cab.setNombreCliente(NOMBRE);;
     if(cab.modificarEnDisco(pos)==true){
        gotoxy(27,29);
        textcolor(cVERDE_CLARO);
        cout<<"SE MODIFICO CORRECTAMENTE ";
        pause();
     }
}


void ModificarDNI(int pos){
     VentaCabecera cab;
     int DNI;

     cab.leerDeDisco(pos);
     gotoxy(27,27);
     cout<<"DNI: ";
     cin>>DNI;
     cab.setDNI(DNI);
     if(cab.modificarEnDisco(pos)==true){
        gotoxy(27,29);
        textcolor(cVERDE_CLARO);
        cout<<"SE MODIFICO CORRECTAMENTE ";
        pause();
     }
}


bool CancelarVentaxID(){
     textcolor(0,0);
     clrscr();
     recuadro(25, 3, 70, 26, cVERDE, cNEGRO);
     textcolor(cMAGENTA);

     VentaDetalle det;
     VentaCabecera cab;
     int IDv,pos,opc;
     bool modifico;

     gotoxy(27,5);
     cout<<"INGRESAR ID DE LA VENTA A BORRAR: ";
     cin>>IDv;
     pos=BuscarIDventa(IDv);
     if(pos==-1){
        recuadro(32, 8, 55, 6, cROJO, cNEGRO);
        gotoxy(41,11);
        textcolor(cROJO);
        cout<<"NO SE ENCONTRO PRODUCTO CON ESE ID";
        return false;
     }

     det.leerDeDisco(pos);
     if(det.getActivo()==true)det.MostrarVd1(3);

      cab.leerDeDisco(pos);
      if(cab.getActivo()==true)cab.MostrarVc1(3);


     cout<<endl;
     gotoxy(28,18);
     cout<<"SEGURO QUE DESEA ELIMINAR?"<<endl;
     gotoxy(28,20);
     cout<<"1) SI       2) NO"<<endl;
     gotoxy(60,20);
     cout<<"RESPUESTA: ";
     cin>>opc;
     switch (opc){

             case 1:det.leerDeDisco(pos);
                    if(det.getActivo()==true){
                       ReintegrarStock(det.getIDProducto(),det.getCantidad());
                       det.setActivo(false);
                       det.modificarEnDisco(pos);
                    }
                     cab.leerDeDisco(pos);
                     if(cab.getActivo()==true){
                        cab.setActivo(false);
                        modifico=cab.modificarEnDisco(pos);
                     }
                        return modifico;
                        break;

              case 2:
                     recuadro(40, 23, 30, 4, cROJO, cNEGRO);
                     gotoxy(45,25);
                     textcolor(cROJO);
                     cout<<"NO SE ELIMINO LA VENTA";
                     return false;
                     break;

              default:
                      gotoxy(71,20);
                      textcolor(cROJO);
                      cout<<"OPCION INCORRECTA";
                      return false;
                      break;

    }
}


bool ReintegrarStock(int IDp, int cantidad){
     Producto cel;
     int pos;
     bool modifico;
     pos=BuscarIDproducto(IDp);
     if(pos==-1){
        return false;
     }
     cel.leerDeDisco(pos-1);
     cel.setStock(cel.getStock()+ cantidad);
     modifico=cel.modificarEnDisco(pos-1);
     return modifico;
}


int BuscarIDproducto(int IDprod){
    Producto cel;
    int pos=0;
    while(cel.leerDeDisco(pos++)==true){
             if(cel.getIDProducto()==IDprod){
                if(cel.getActivo()==true){
                return pos;
             }
          }
     }
     return -1;
}



void TODASrecaudacion(int Dia1_Mes2_Anio3){
     textcolor(0,0);
     clrscr();
     recuadro(25, 3, 67, 23, cVERDE, cNEGRO);
     textcolor(cMAGENTA);

     VentaDetalle det;
     Fecha F;
     int pos=0, dia, mes, anio;
     float RecTotal=0;

switch (Dia1_Mes2_Anio3){
             case 1:
                    gotoxy(27,5);
                    cout<<"INGRESA LA FECHA DE LA RECAUDACION A MOSTRAR: ";
                    if(F.Cargar1(0)==false){
                    return;
                    }
                    while(det.leerDeDisco(pos++)==true){
                         if(det.getActivo()==true)
                            if(det.getFechaVenta().getdia()==F.getdia())
                               if(det.getFechaVenta().getmes()==F.getmes())
                                  if(det.getFechaVenta().getanio()==F.getanio()){
                                     RecTotal=RecTotal+RecTotalxID(det.getIDVenta());
                                  }
                     }
                     break;

             case 2:
                    gotoxy(27,5);
                    cout<<"INGRESA EL MES Y ANIO DE LA RECAUDACION A MOSTRAR: ";
                    gotoxy(27,7);
                    cout<<"MES:       ANIO: ";
                    gotoxy(32,7);
                    cin>>mes;

                    if(mes>12 || mes<1){
                    gotoxy(32,7);
                    textcolor(cROJO);
                    cout<<"EL MES NO ES VALIDO";
                    pause();
                    return;
                    }

                    gotoxy(44,7);
                    cin>>anio;
                    if(anio>2022 || anio<1){
                        gotoxy(44,7);
                        textcolor(cROJO);
                        cout<<"EL ANIO NO ES VALIDO"<<endl;
                        system("pause>nul");
                        return;
                        }

                    while(det.leerDeDisco(pos++)==true){
                         if(det.getActivo()==true){
                            if(det.getFechaVenta().getmes()==mes)
                                  if(det.getFechaVenta().getanio()==anio){
                                     RecTotal=RecTotal+RecTotalxID(det.getIDVenta());
                                  }
                     }
                     }
                       break;

            case 3:
                  gotoxy(27,5);
                  cout<<"INGRESA EL ANIO DE LA RECAUDACION A MOSTRAR: ";
                  gotoxy(27,7);
                  cout<<"ANIO: ";
                  gotoxy(33,7);
                  cin>>anio;

                  if(anio>2022){
                   gotoxy(33,7);
                   textcolor(cROJO);
                   cout<<"EL ANIO NO ES VALIDO"<<endl;
                   system("pause>nul");
                   return;
                   }

                  while(det.leerDeDisco(pos++)==true){
                       if(det.getActivo()==true){
                          if(det.getFechaVenta().getanio()==anio){
                                   RecTotal=RecTotal+RecTotalxID(det.getIDVenta());
                                }
                   }
                  }
                  break;
}

      if(RecTotal>0){
      gotoxy(27,10);
      textcolor(cVERDE_CLARO);
      cout<<"RECAUDACION TOTAL $"<<RecTotal;
      system("pause>nul");
      }
       else{
            recuadro(30, 8, 55, 6, cROJO, cNEGRO);
            gotoxy(39,11);
            textcolor(cROJO);
            cout<<"NO SE REGISTRARON VENTAS EN LA FECHA";
            system("pause>nul");
       }
}




void TODASVentas(int Dia1_Mes2_Anio3){
     textcolor(0,0);
     clrscr();
     recuadro(25, 3, 67, 23, cVERDE, cNEGRO);
     textcolor(cMAGENTA);

     VentaDetalle det;
     Fecha F;
     int pos=0,VT=0, mes, anio;

 switch (Dia1_Mes2_Anio3){
              case 1:
              gotoxy(27,5);
              cout<<"INGRESA FECHA DE LAS VENTAS A MOSTRAR: ";
              if(F.Cargar1(0)==false){
              return;
              }
              while(det.leerDeDisco(pos++)==true){
                   if(det.getActivo()==true)
                      if(det.getFechaVenta().getdia()==F.getdia())
                          if(det.getFechaVenta().getmes()==F.getmes())
                              if(det.getFechaVenta().getanio()==F.getanio()){
                                  VT++;
                                  }
                  }
                  break;

            case 2:
            gotoxy(27,5);
            cout<<"INGRESA EL MES Y ANIO DE LAS VENTAS A MOSTRAR: ";
            gotoxy(27,7);
            cout<<"MES:        ANIO: ";
            gotoxy(32,7);
            cin>>mes;
            if(mes>12 || mes<1){
            gotoxy(32,7);
            textcolor(cROJO);
            cout<<"EL MES NO ES VALIDO";
            pause();
            return;
            }

            gotoxy(45,7);
            cin>>anio;
            if(anio>2022 || anio<1){
            gotoxy(44,7);
            textcolor(cROJO);
            cout<<"EL ANIO NO ES VALIDO"<<endl;
            system("pause>nul");
            return;
            }

            while(det.leerDeDisco(pos++)==true){
                 if(det.getActivo()==true){
                    if(det.getFechaVenta().getmes()==mes)
                          if(det.getFechaVenta().getanio()==anio){
                            VT++;
                            }
             }
            }
            break;

           case 3:
           gotoxy(27,5);
           cout<<"INGRESA EL ANIO DE LAS VENTAS A MOSTRAR: ";
           gotoxy(27,7);
           cout<<"ANIO: ";
           gotoxy(33,7);
           cin>>anio;
           if(anio>2022){
           gotoxy(33,7);
           textcolor(cROJO);
           cout<<"EL ANIO NO ES VALIDO"<<endl;
           system("pause>nul");
           return;
           }

           while(det.leerDeDisco(pos++)==true){
                if(det.getActivo()==true){
                   if(det.getFechaVenta().getanio()==anio){
                        VT++;
                        }
            }
           }
           break;
 }
      if(VT>0){
      gotoxy(27,10);
      textcolor(cVERDE_CLARO);
      cout<<"CANTIDAD DE VENTAS REALIZADAS EN LA FECHA INGRESADA: "<<VT;
      system("pause>nul");
      }
       else{
            recuadro(30, 8, 55, 6, cROJO, cNEGRO);
            gotoxy(39,11);
            textcolor(cROJO);
            cout<<"NO SE REGISTRARON VENTAS EN LA FECHA";
            system("pause>nul");
       }
}




void TODASVentaEquipos(int Dia1_Mes2_Anio3){
     textcolor(0,0);
     clrscr();
     recuadro(25, 3, 67, 23, cVERDE, cNEGRO);
     textcolor(cMAGENTA);

     VentaDetalle det;
     Fecha F;
     int pos=0,CantEquipos=0, mes, anio;

 switch (Dia1_Mes2_Anio3){
              case 1:
              gotoxy(27,5);
              cout<<"INGRESA FECHA PARA MOSTRAR LA CANTIDAD DE EQUIPOS VENDIDOS : ";
              if(F.Cargar1(0)==false){
                 return;
              }
              while(det.leerDeDisco(pos++)==true){
                   if(det.getActivo()==true)
                      if(det.getFechaVenta().getdia()==F.getdia())
                         if(det.getFechaVenta().getmes()==F.getmes())
                            if(det.getFechaVenta().getanio()==F.getanio()){
                               CantEquipos=CantEquipos+det.getCantidad();
                              }
               }
               break;

              case 2:
               gotoxy(27,5);
               cout<<"INGRESA MES Y ANIO PARA MOSTRAR LA CANTIDAD DE EQUIPOS VENDIDOS: ";
               gotoxy(27,7);
               cout<<"MES:        ANIO: ";
               gotoxy(32,7);
               cin>>mes;
               if(mes>12 || mes<1){
               gotoxy(32,7);
               textcolor(cROJO);
               cout<<"EL MES NO ES VALIDO";
               pause();
               return;
               }

               gotoxy(45,7);
               cin>>anio;
               if(anio>2022 || anio<1){
               gotoxy(44,7);
               textcolor(cROJO);
               cout<<"EL ANIO NO ES VALIDO"<<endl;
               system("pause>nul");
               return;
               }

               while(det.leerDeDisco(pos++)==true){
                    if(det.getActivo()==true){
                       if(det.getFechaVenta().getmes()==mes)
                             if(det.getFechaVenta().getanio()==anio){
                              CantEquipos=CantEquipos+det.getCantidad();
                             }
                }
               }
               break;

              case 3:
              gotoxy(27,5);
              cout<<"INGRESA EL ANIO PARA MOSTRAR LA CANTIDAD DE EQUIPOS VENDIDOS: ";
              gotoxy(27,7);
              cout<<"ANIO: ";
              gotoxy(33,7);
              cin>>anio;
              if(anio>2022 || anio<1){
              gotoxy(44,7);
              textcolor(cROJO);
              cout<<"EL ANIO NO ES VALIDO"<<endl;
              system("pause>nul");
              return;
              }

              while(det.leerDeDisco(pos++)==true){
                   if(det.getActivo()==true){
                      if(det.getFechaVenta().getanio()==anio){
                           CantEquipos=CantEquipos+det.getCantidad();
                            }
               }
              }
              break;
}

      if(CantEquipos>0){
      gotoxy(27,10);
      textcolor(cVERDE_CLARO);
      cout<<"CANTIDAD DE EQUIPOS VENDIDOS LA FECHA INGRESADA: "<<CantEquipos;
      system("pause>nul");
      }
       else{
            recuadro(30, 8, 55, 6, cROJO, cNEGRO);
            gotoxy(39,11);
            textcolor(cROJO);
            cout<<"NO SE REGISTRARON VENTAS EN LA FECHA";
            system("pause>nul");
       }
}




#endif // FUNCIONES_H_INCLUDED
