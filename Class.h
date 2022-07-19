#ifndef CLASS_H_INCLUDED
#define CLASS_H_INCLUDED


int BuscarIDproducto1(int IDprod);
int BuscarIDventa(int IDVent);
float PrecioxID(int IDprod);
int StockxID(int IDprod);

float ImpTotalxIDventa(int IDvent);


void BuscarMarca1(int IDp, int i);
void BuscarModelo1(int IDp, int i);

void BuscarMarca(int IDp);
void BuscarModelo(int IDp);

int AutonumericoProducto();
int AutonumericoVentas();
int AutonumericoVentas1();

void cargarCadena(char *pal, int tam){
  int i;
  fflush(stdin);
  for(i=0;i<tam;i++){
      pal[i]=cin.get();
	  if(pal[i]=='\n') break;
	  }
  pal[i]='\0';
  fflush(stdin);
}









class Fecha{
  private:
          int dia, mes, anio;
  public:
         Fecha (int d=0, int m=0, int a=0){
         dia=d;
         mes=m;
         anio=a;
         }

  ///________SETS_________________________
  bool setdia(int d){
        if(d>0 && d<=31){
           dia=d;
        return true;
        }
        return false;
        }

  bool setmes(int m){
        if(m>0 && m<=12){
           mes=m;
           return true;
        }
           return false;
        }

  bool setanio(int a){
        if(a>0 && a<=2022){
           anio=a;
           return true;
        }
           return false;
        }


bool ValidarFecha(){
int DiaPorMes[12]={31,28,31,30,31,30,31,31,30,31,30,31};
if(dia>DiaPorMes[mes-1]) return false;
return true;
}

///_______GETS__________________________
    int getdia(){return dia;}
    int getmes(){return mes;}
    int getanio(){return anio;}

 bool Cargar1(int i){
     textcolor(cMAGENTA);
     int dia,mes,anio;
 gotoxy(27,7+i);
 cout<<"DIA: ";
 cin>>dia;
 if(setdia(dia)==false){
 gotoxy(32,7+i);
 textcolor(cROJO);
 cout<<"EL DIA NO ES VALIDO"<<endl;
 system("pause>nul");
 return false;
 }

 gotoxy(37,7+i);
 cout<<"MES: ";
 cin>>mes;
 if(setmes(mes)==false){
 gotoxy(42,7+i);
 textcolor(cROJO);
 cout<<"EL MES NO ES VALIDO"<<endl;
 system("pause>nul");
 return false;
 }

 gotoxy(47,7+i);
 cout<<"ANIO: ";
 cin>>anio;
 if(setanio(anio)==false){
 gotoxy(53,7+i);
 textcolor(cROJO);
 cout<<"EL ANIO NO ES VALIDO"<<endl;
 system("pause>nul");
 return false;
 }

 return ValidarFecha();
 }


void Mostrar(){
cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}

};

///---///---///---///---///---///---///---///---///---///---///---///---///---///---///---///---///---///---///---///---//

class Producto{
  private:
         int IDProducto;
         char Marca[30];
         char Modelo[30];
         float Precio;
         int Stock;
         bool Activo;

  public:
        void Cargar();
        void Mostrar(int i);

         bool grabarEnDisco(){
              FILE *pProd;
              pProd=fopen("Producto.dat", "ab");
              if(pProd==NULL){
                 clrscr();
                 recuadro(25, 3, 67, 7, cVERDE, cNEGRO);
                 gotoxy(44,6);
                 textcolor(cROJO);
              cout<<"NO SE PUDO CREAR/ABRIR EL ARCHIVO"<<endl;
              return false;
              }

              bool grabo=fwrite(this,sizeof(Producto),1,pProd);
              fclose(pProd);
              return grabo;
              }


         bool leerDeDisco(int pos){
              FILE *p;
              p=fopen("Producto.dat","rb");
              if(p==NULL){
                clrscr();
                recuadro(25, 3, 67, 7, cVERDE, cNEGRO);
                gotoxy(44,6);
                textcolor(cROJO);
              cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
              return false;
              }
              fseek(p,sizeof(Producto)*pos,0);
              bool leyo=fread(this, sizeof(Producto), 1, p);
              fclose(p);
              return leyo;
              }

    bool modificarEnDisco(int pos){
        FILE *p;
        p=fopen("Producto.dat","rb+");
        if(p==NULL){
          clrscr();
          recuadro(25, 3, 67, 7, cVERDE, cNEGRO);
          gotoxy(44,6);
          textcolor(cROJO);
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
        }
        fseek(p,sizeof(Producto)*pos,0);
        bool leyo=fwrite(this, sizeof(Producto), 1, p);
        fclose(p);
        return leyo;
        }



///___________SETS_______________________________
void setIDProducto(int IDp){IDProducto=IDp;}
void setMarca(const char *M){strcpy(Marca,M);}
void setModelo(const char *Mod){strcpy(Modelo,Mod);}
void setPrecio(float P){Precio=P;}
void setStock(int Stk){Stock=Stk;}
void setActivo (bool A){Activo=A;}

///____________GETS________________________________
int getIDProducto(){return IDProducto;}
const char *getMarca(){return Marca;}
const char *getModelo(){return Modelo;}
float getPrecio(){return Precio;}
int getStock(){return Stock;}
bool getActivo(){return Activo;}

};

void Producto::Cargar(){
     if(AutonumericoProducto()==-1){
        IDProducto=1;
        gotoxy(50,6);
        cout<<"ID PRODUCTO: "<<IDProducto<<endl;
     }
     else{
         IDProducto=AutonumericoProducto()+1;
         gotoxy(50,6);
         cout<<"ID PRODUCTO: "<<IDProducto<<endl;
     }

     gotoxy(50,7);
     cout<<"MARCA: ";
     cargarCadena(Marca,29);
     gotoxy(50,8);
     cout<<"MODELO: ";
     cargarCadena(Modelo,29);
     gotoxy(50,9);
     cout<<"PRECIO: $ ";
     cin>>Precio;
     if(Precio<=0){
        recuadro(30, 12, 55, 6, cROJO, cNEGRO);
        gotoxy(37,15);
        textcolor(cROJO);
        cout<<"[ERROR] EL PRECIO INGRESADO NO ES PERMITIDO";
        system("pause>nul");
        Activo=false;
        return;
     }
     gotoxy(50,10);
     cout<<"STOCK: ";
     cin>>Stock;
     if(Stock<=0){
        recuadro(30, 12, 55, 6, cROJO, cNEGRO);
        gotoxy(37,15);
        textcolor(cROJO);
        cout<<"[ERROR] EL STOCK INGRESADO NO ES PERMITIDO";
        system("pause>nul");
        Activo=false;
        return;
     }
      Activo=true;
     }


void Producto::Mostrar(int i){
       if(Activo==true){
          gotoxy(33,i);
          cout<<IDProducto;
          gotoxy(38,i);
          cout<<Marca;
          gotoxy(53,i);
          cout<<Modelo;
          gotoxy(72,i);
          cout<<"$ "<<Precio;
          gotoxy(85,i);
          cout<<Stock;


       }
       }

///---///---///---///---///---///---///---///---///---///---///---///---///---///---///---///---///---///---///---///---//

class VentaDetalle{
  private:
          int IDVenta;
          int IDProducto;
          int stock;
          float PrecioU;
          int Cantidad;
          Fecha FechaVenta;
          bool Activo;

  public:
        void CargarVd();
        void MostrarVd1(int i);

 bool grabarEnDisco(){
         FILE *pVentaDet;
         bool grabo;
         pVentaDet=fopen("VentaDetalle.dat", "ab");
         if(pVentaDet==NULL){
            clrscr();
            recuadro(25, 3, 67, 7, cVERDE, cNEGRO);
            gotoxy(44,6);
            textcolor(cROJO);
         cout<<"NO SE PUDO CREAR/ABRIR EL ARCHIVO"<<endl;
         return false;
         }
         grabo=fwrite(this,sizeof(VentaDetalle),1,pVentaDet);
         fclose(pVentaDet);
         return grabo;
         }


bool leerDeDisco(int pos){
        FILE *p;
        p=fopen("VentaDetalle.dat","rb");
        if(p==NULL){
           clrscr();
           recuadro(25, 3, 67, 7, cVERDE, cNEGRO);
           gotoxy(44,6);
           textcolor(cROJO);
           cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
           return false;
        }
        fseek(p,sizeof(VentaDetalle)*pos,0);
        bool leyo=fread(this, sizeof(VentaDetalle), 1, p);
        fclose(p);
        return leyo;
        }


bool modificarEnDisco(int pos){
     FILE *p;
     p=fopen("VentaDetalle.dat","rb+");
     if(p==NULL){
       clrscr();
       recuadro(25, 3, 67, 7, cVERDE, cNEGRO);
       gotoxy(44,6);
       textcolor(cROJO);
       cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
       return false;
     }
     fseek(p,sizeof(VentaDetalle)*pos,0);
     bool leyo=fwrite(this, sizeof(VentaDetalle), 1, p);
     fclose(p);
     return leyo;
     }


///______________SETS__________________________
void setIDVenta(int IDv){IDVenta=IDv;}
void setIDProducto(int IDp){IDProducto=IDp;}
void setstock(int stk){stock=stk;}
void setPrecioU(float PreU){PrecioU=PreU;}
void setCantidad(int Cant){Cantidad=Cant;}
void setFechaVenta(Fecha F){FechaVenta=F;}
void setActivo(bool Act){Activo=Act;}

///____________GETS________________________________
int getIDVenta(){return IDVenta;}
int getIDProducto(){return IDProducto;}
int getstock(){return stock;}
float getPrecioU(){return PrecioU;}
int getCantidad(){return Cantidad;}
Fecha getFechaVenta(){return FechaVenta;}
bool getActivo(){return Activo;}

};

void VentaDetalle::CargarVd(){
     if(AutonumericoVentas()==-1){
        IDVenta=1;
        gotoxy(28,6);
        cout<<"ID VENTA: "<<IDVenta<<endl;
     }
     else{
         IDVenta=AutonumericoVentas()+1;
         gotoxy(28,6);
         cout<<"ID VENTA: "<<IDVenta<<endl;
     }

     gotoxy(28,7);
     cout<<"ID PRODUCTO: ";
     cin>>IDProducto;
     if(BuscarIDproducto1(IDProducto)==-1){
        gotoxy(31,10);
        textcolor(cROJO);
        cout<<"[ERROR] EL ID INGRESADO NO CORRESPONDE A NINGUN PRODUCTO";
        pause();
        Activo=false;
        return;
     }
     gotoxy(28,8);
     BuscarMarca(IDProducto);
     gotoxy(28,9);
     BuscarModelo(IDProducto);

     stock=StockxID(IDProducto);
     gotoxy(28,10);
     cout<<"STOCK: "<<stock<<endl;
     if(stock==0){
        gotoxy(28,12);
        textcolor(cROJO);
        cout<<"PERDONE, ACTUALMENTE EL PRODUCTO SE ENCUENTRA SIN STOCK";
        pause();
        Activo=false;
        return;
     }

     PrecioU=PrecioxID(IDProducto);
     gotoxy(28,11);
     cout<<"PRECIO: "<<PrecioU<<endl;
     gotoxy(28,12);
     cout<<"CANTIDAD: ";
     cin>>Cantidad;
     if(Cantidad<1){
        gotoxy(28,14);
        textcolor(cROJO);
        cout<<"[ERROR] CANTIDAD INGRESADA NO PERMITIDA";
        pause();
        Activo=false;
        return;
     }

     if(Cantidad>stock){
        gotoxy(28,14);
        textcolor(cROJO);
        cout<<"[ERROR] LA CANTIDAD INGRESADA SUPERA EL STOCK EXISTENTE"<<endl;
        pause();
        Activo=false;
        return;
     }
     gotoxy(28,13);
     cout<<"FECHA DE VENTA "<<endl;

     if(FechaVenta.Cargar1(7)==false){
        gotoxy(28,19);
        textcolor(cROJO);
        Activo=false;
        return;
    }
     Activo=true;
}



void VentaDetalle::MostrarVd1(int i){
    if(Activo==true){
        textcolor(cBLANCO);
        gotoxy(27,4+i);
        cout<<"ID VENTA: ";
        textcolor(cMAGENTA);
        cout<<IDVenta;

        textcolor(cBLANCO);
        gotoxy(27,9+i);
        cout<<"ID";
        textcolor(cMAGENTA);
        gotoxy(27,10+i);
        cout<<IDProducto;

        textcolor(cBLANCO);
        gotoxy(58,9+i);
        cout<<"PRECIO U. ";
        textcolor(cMAGENTA);
        gotoxy(59,10+i);
        cout<<"$"<<PrecioU;

        textcolor(cBLANCO);
        gotoxy(70,9+i);
        cout<<"CANTIDAD";
        textcolor(cMAGENTA);
        gotoxy(73,10+i);
        cout<<Cantidad;

        textcolor(cBLANCO);
        gotoxy(27,5+i);
        cout<<"FECHA:    ";
        textcolor(cMAGENTA);
        FechaVenta.Mostrar();

        BuscarMarca1(IDProducto,i);
        BuscarModelo1(IDProducto,i);

        gotoxy(26,12+i);
        textcolor(cCIAN_CLARO);
        cout<<"=====================================================================";
        }
        }

///---///---///---///---///---///---///---///---///---///---///---///---///---///---///---///---///---///---///---///---//

class VentaCabecera{
  private:
          int IDVenta;
          char NombreCliente[30];
          int DNI;
          float ImporteTotal;
          bool Activo;

  public:
        void CargarVc();
        ///void MostrarVc();
        void MostrarVc1(int i);

         bool grabarEnDisco(){
         FILE *pVentaCab;
         bool grabo;
         pVentaCab=fopen("VentaCabecera.dat", "ab");
         if(pVentaCab==NULL){
            clrscr();
            recuadro(25, 3, 67, 7, cVERDE, cNEGRO);
            gotoxy(44,6);
            textcolor(cROJO);
            cout<<"NO SE PUDO CREAR/ABRIR EL ARCHIVO"<<endl;
            return false;
         }
         grabo=fwrite(this,sizeof(VentaCabecera),1,pVentaCab);
         fclose(pVentaCab);
         return grabo;
         }

bool leerDeDisco(int pos){
     FILE *p;
     p=fopen("VentaCabecera.dat","rb");
     if(p==NULL){
        clrscr();
        recuadro(25, 3, 67, 7, cVERDE, cNEGRO);
        gotoxy(44,6);
        textcolor(cROJO);
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
     }
     fseek(p,sizeof(VentaCabecera)*pos,0);
     bool leyo=fread(this, sizeof(VentaCabecera), 1, p);
     fclose(p);
     return leyo;
}

bool modificarEnDisco(int pos){
     FILE *p;
     p=fopen("VentaCabecera.dat","rb+");
     if(p==NULL){
        clrscr();
        recuadro(25, 3, 67, 7, cVERDE, cNEGRO);
        gotoxy(44,6);
        textcolor(cROJO);
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
     }
     fseek(p,sizeof(VentaCabecera)*pos,0);
     bool leyo=fwrite(this, sizeof(VentaCabecera), 1, p);
     fclose(p);
     return leyo;
}


///______________SETS__________________________
void setIDVenta (int IDv){IDVenta=IDv;}
void setNombreCliente(const char *Nc){strcpy(NombreCliente,Nc);}
void setDNI(int dni){DNI=dni;}
void setImporteTotal(float ImT){ImporteTotal=ImT;}
void setActivo(bool A){Activo=A;}

///____________GETS________________________________
int getIDventa(){return IDVenta;}
const char *getNombreCliente(){return NombreCliente;}
int getDNI(){return DNI;}
float getImporteTotal(){return ImporteTotal;}
bool getActivo(){return Activo;}

};

void VentaCabecera::CargarVc(){
     if(AutonumericoVentas1()==-1){
        IDVenta=1;
        gotoxy(50,18);
        cout<<"ID VENTA: "<<IDVenta<<endl;
     }
     else{
         IDVenta=AutonumericoVentas1()+1;
         gotoxy(50,18);
         cout<<"ID VENTA: "<<IDVenta<<endl;
     }

    gotoxy(50,19);
    cout<<"NOMBRE DEL CLIENTE: ";
    cargarCadena(NombreCliente,29);
    gotoxy(50,20);
    cout<<"DNI: ";
    cin>>DNI;
    ImporteTotal=ImpTotalxIDventa(IDVenta);
    gotoxy(50,21);
    cout<<"IMPORTE TOTAL: "<<ImporteTotal<<endl;
    Activo=true;
}


void VentaCabecera::MostrarVc1(int i){
    if(Activo==true){
        textcolor(cBLANCO);
        gotoxy(27,6+i);
        cout<<"CLIENTE:  ";
        textcolor(cMAGENTA);
        cout<<NombreCliente<<endl;

        textcolor(cBLANCO);
        gotoxy(27,7+i);
        cout<<"DNI:      ";
        textcolor(cMAGENTA);
        cout<<DNI;

        textcolor(cBLANCO);
        gotoxy(81,9+i);
        cout<<"IMPORTE TOTAL";
        textcolor(cMAGENTA);
        gotoxy(84,10+i);
        cout<<"$"<<ImporteTotal;
    }
}

///---///---///---///---///---///---///---///---///---///---///---///---///---///---///---///---///---///---///---///---///

///---///---///---///---///---///---///---///---///---///---///---///---///---///---///---///---///---///---///---///---//




int BuscarIDventa(int IDVent){
    VentaDetalle det;
    int pos=0;
    while(det.leerDeDisco(pos)==true){
          if(det.getIDVenta()==IDVent)
          if(det.getActivo()==true){
             return pos;
          }
             pos++;
          }
    return -1;
}




int BuscarIDproducto1(int IDprod){
    Producto cel;
    int pos=0;
    while(cel.leerDeDisco(pos)==true){
          if(cel.getActivo()==true){
             if(cel.getIDProducto()==IDprod){
                return pos;
             }
          }
    pos++;
    }
    return -1;
}


void BuscarMarca1(int IDp, int i){
     Producto cel;
     int pos=0;
     char Marca[30];
     while(cel.leerDeDisco(pos++)==true){
           if(cel.getIDProducto()==IDp){
              strcpy(Marca,cel.getMarca());
           }
     }
     textcolor(cBLANCO);
     gotoxy(31,9+i);
     cout<<"MARCA";
     textcolor(cMAGENTA);
     gotoxy(31,10+i);
     cout<<Marca;
}

void BuscarModelo1(int IDp, int i){
     Producto cel;
     int pos=0;
     char Modelo[30];
     while(cel.leerDeDisco(pos++)==true){
           if(cel.getIDProducto()==IDp){
              strcpy(Modelo,cel.getModelo());
           }
     }
     textcolor(cBLANCO);
     gotoxy(45,9+i);
     cout<<"MODELO";
     textcolor(cMAGENTA);
     gotoxy(45,10+i);
     cout<<Modelo;
}


void BuscarMarca(int IDp){
     Producto cel;
     int pos=0;
     char Marca[30];
     while(cel.leerDeDisco(pos++)==true){
           if(cel.getIDProducto()==IDp){
              strcpy(Marca,cel.getMarca());
           }
     }
     gotoxy(28,8);
     cout<<"MARCA: ";
     cout<<Marca;
}

void BuscarModelo(int IDp){
     Producto cel;
     int pos=0;
     char Modelo[30];
     while(cel.leerDeDisco(pos++)==true){
           if(cel.getIDProducto()==IDp){
              strcpy(Modelo,cel.getModelo());
           }
     }
     gotoxy(28,9);
     cout<<"MODELO: ";
     cout<<Modelo;
}



float PrecioxID(int IDprod){
    Producto cel;
    int pos=0;
    float precio;
    while(cel.leerDeDisco(pos++)==true){
          if(cel.getIDProducto()==IDprod){
             precio=cel.getPrecio();
             return precio;
          }
    }
}

int StockxID(int IDprod){
     Producto cel;
     int pos=0,stock;
     while(cel.leerDeDisco(pos++)){
           if(cel.getIDProducto()==IDprod){
              stock=cel.getStock();
              return stock;
           }
     }
}



float ImpTotalxIDventa(int IDvent){
      VentaDetalle det;
      int pos=0;
      float ImpTotal;
      while(det.leerDeDisco(pos++)==true){
            if(det.getIDVenta()==IDvent){
               ImpTotal=det.getPrecioU()*det.getCantidad();
               return ImpTotal;
            }
      }
}


int AutonumericoProducto(){
    FILE *p;
    p=fopen("Producto.dat", "rb");
    if(p==NULL) return -1;
    fseek(p,0,2);
    int cantByte=ftell(p);
    fclose(p);
    return cantByte/sizeof(Producto);
}

int AutonumericoVentas(){
    FILE *p;
    p=fopen("VentaDetalle.dat", "rb");
    if(p==NULL) return -1;
    fseek(p,0,2);
    int cantByte=ftell(p);
    fclose(p);
    return cantByte/sizeof(VentaDetalle);
}

int AutonumericoVentas1(){
    FILE *p;
    p=fopen("VentaCabecera.dat", "rb");
    if(p==NULL) return -1;
    fseek(p,0,2);
    int cantByte=ftell(p);
    fclose(p);
    return cantByte/sizeof(VentaCabecera);
}

#endif // CLASS_H_INCLUDED
