#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int area;
void menu(void); //prototipo de la funcion menu
void almacen(void);


char letra = 164; //letra ? en minuscula (ASCII)
char letraM = 165; //letra ? en mayuscula (ASCII)
/*Estructura principal*/
struct lista
{ //estructura lista
 float nro;
 struct lista *sgte;

 string plr;
 struct lista *sgteP;

};
/*fin de la estructura principal*/

typedef struct lista *ptrLista;
typedef struct lista *ptrListaS;

void agrega_productoC(ptrLista &p, int valor)
{ //agrega el precio del producto
  ptrLista aux;
  aux = new (struct lista);
  aux -> nro = valor;
  aux ->sgte = p;
  p = aux;
}

void agrega_productoN(ptrListaS &s,string palabra)
{ //agrega el nombre del producto

  ptrListaS auxs;
  auxs = new (struct lista);
  auxs -> plr = palabra;
  auxs -> sgteP = s;
  s = auxs;
}

void cancelar_productoC(ptrLista &p,int valor)
{//cancela los productos de manera individual (elimina el precio)
  ptrLista aux, antN;
  aux = p;
   if(p != NULL)
   {
     while(aux != NULL)
     {
       if(aux -> nro == valor)
       {
          if(aux == p)
           p = p -> sgte;
           else
            antN -> sgte = aux -> sgte;
            delete (aux);
            return;
       }
       antN = aux;
       aux = aux -> sgte;
     }
     cout<<"su lista de productos no tiene ningun producto Actualmente "<<endl;
   }
}

void cancelar_productoS(ptrListaS &s, string palabra)
{//cancela los productos de manera individual (elimina el nombre del producto)
  ptrListaS auxs, antP;
   auxs = s;
    if(s != NULL)
    {
      while(auxs != NULL)
      {
         if(auxs -> plr == palabra)
         {
           if(auxs == s)
           s = s -> sgteP;
           else
            antP -> sgteP = auxs -> sgteP;
            delete (auxs);
            return;
         }
         antP = auxs;
         auxs = auxs -> sgteP;
      }
      cout<<"no tiene Actualmente ningun producto en su carrito"<<endl;
    }
}

void cancelar_productoNT(ptrListaS &s, string palabra)
{ //elimina la lista total de nombres de los articulos
  ptrListaS aux;
     if(s != NULL)
     {
       while(s -> sgteP != s)
       {
         aux = s -> sgteP;
         s -> sgteP = s -> sgteP;
         delete(s);
       }
     }
}

void cancelar_productoCT(ptrLista &p,int valor)
{//elimina la lista total de los costos de los articulos
 ptrLista aux;
 if(p != NULL)
 {
   while(p -> sgte != p)
   {
     aux = p -> sgte;
     p -> sgte = p -> sgte;
     delete(p);
   }
 }
}

void lista_productosC(ptrLista &p, ptrListaS &s)
{//muestra el precio de los articulos
  ptrLista aux;
  ptrListaS auxs;

  aux = p;
  auxs = s;

  while(aux != NULL && auxs != NULL){
    cout<<"\t"<<auxs -> plr<<"\t\t["<<aux -> nro<<"]"<<"\n";
    auxs = auxs -> sgteP;
    aux = aux -> sgte;
  }
}

float Sumar_costoT(ptrLista &p)
{ //suma el costo total de la compra
  float adition = 0;
   while(p != NULL){
    adition = adition + p -> nro;
    p = p -> sgte;
   }
   return adition;
}


class Tienda_matriz
{
  friend void agrega_productoC(ptrLista &p, int valor);
  friend void agrega_productoN(ptrListaS &s,string palabra);
  friend void cancelar_productoC(ptrLista &p, int valor);
  friend void cancelar_productoS(ptrListaS &s,string palabra);
  friend void lista_productosC(ptrLista &p,ptrListaS &s);
  friend float Sumar_costoT(ptrLista &p);
  friend float Sumar_costoT_descuento(ptrLista &p);
  friend void cancelar_productoNT(ptrListaS &s, string palabra);
  friend void cancelar_productoCT(ptrLista &p,int valor);
public:
  float codigo;       //atributo de tipo unidad (int) para cada articulo
  float costo;      //precio asignado para cada articulo
  float costoT;     //precio total de la compra (tambien puede aplicarse la compra al meyoreo)
  float T_pagar;    //total de articulos seleccionados
  float TC_descuento_Aplicado; //que descuento se esta aplicando a cada departamento y/o producto
  string nombre_producto;
  ptrLista p = NULL;
  ptrListaS s = NULL;
  ~Tienda_matriz(); //DESTRUCTOR ESTANDAr
   Tienda_matriz(); //CONSTRCUTOR ESTANDAR
   void Tipo_Articulo(); //QUE ARTICULO SE SELECCIONO POR CADA DEPARTAMENTO
   void Cancelar_compra(); //metodo que elimina producto por producto
   void CantidadT(); //cantidad total por todos los articulos
   void Cancelar_compra_Total();
  //virtual int codigo_articulo(); //codigo por cada articulo
  // void oferta(); //que oferta se le dara al cliente, nota se despliega una lista de descuentos RECUERDALO
  // int descuento(); //aplica el descuento a cada articulo comprado
  //virtual void total_pagar_Descuento(); //CANTIDAD A PAGAR CON DESCUENTO APLICADO/*
   void listaCompra();}; //fin de mi clase Tienda_matriz


/*----------------------inicio de la declaracion de metodos de la funcion--------------------------*/
/*-------------------------------------junto con  constructores-----------------------------------*/

/*********** CONSTRUCTORES y DESTRUCTORES **************/
Tienda_matriz::Tienda_matriz(){}  //constructor estandar

Tienda_matriz::~Tienda_matriz(){} //destructor estandar
/******** FIN DE LOS CONSTRUCTORES  Y DESTRUCTORES ***********/


void Tienda_matriz::Tipo_Articulo()
{ //ingresa un articulo a la lista de compras
  int agregar;

  do{
   cout<<"INGRESE EL NOMBRE DEL ARTICULO"<<endl;
   cout<<"(EJEMPLO DE COMO INGRESAR EL NOMBRE) -> [ \"JEANS_STONE_BLANCOS\" ] "<<endl;
   cout<<"NOMBRE DEL PRODUCTO A COMPRAR: ";
    cin>>nombre_producto;
    agrega_productoN(s,nombre_producto);
   cout<<"producto: "<<nombre_producto<<" agregado a su lista."<<endl;
   cout<<"precio del articulo: ";
    cin>>costo;
    agrega_productoC(p,costo);
   cout<<"desea agregar otro articulo a su lista: \n";
   cout<<"1. SI \n";
   cout<<"0. NO \n";
   cout<<"$> ";
    cin>>agregar;
 }while(agregar != 0);
}
void Tienda_matriz::Cancelar_compra()
{ //este metodo solo cancela un producto
  if(p != NULL && s != NULL){
  cout<<"INGRESE EL NOMBRE DEL ARTICULO"<<endl;
  cout<<"(EJEMPLO DE COMO INGRESAR EL NOMBRE) -> [ \"JEANS_STONE_BLANCOS\" ] "<<endl;
   cout<<"nombre del producto que desea cancelar: ";
   cin>>nombre_producto;
   cancelar_productoS(s,nombre_producto);
   cout<<"costo del producto: ";
   cin>>costo;
   cancelar_productoC(p,costo);
 }else{
   cout<<"\t\t NO SE PUEDE CANCELAR NINGUN PRODUCTO... ACTUALMENTE NO TIENE PRODUCTOS EN SU LISTA DE COMPRAS! \n"<<endl;
 }
}

void Tienda_matriz::listaCompra()
{
  if(p != NULL && s != NULL){
  cout<<"su lista de compras total es: "<<endl;
  lista_productosC(p,s);
}else{
  cout<<"ACTUALMENTE SU LISTA ESTA VACIA...!"<<endl;
}
}

void Tienda_matriz::CantidadT()
{ //metodo que me muestra la cantidad total a pagar de la compra (es el ticket)
  if(p != NULL && s != NULL){
  cout<<"\t\t\t"<<endl;
  cout<<"\t\t\t                              THE POWER RANGER                                "<<endl;
  cout<<"\t\t\t                              ticket de compra                                "<<endl;
  cout<<"\t\t\t                            CIUDAD DE MEXICO, CDMX                            "<<endl;
  cout<<"\t\t\t                               TEL: 5562047220                                "<<endl;
  cout<<"\t\t\t"<<endl;
  cout<<"\n \n"<<endl;

  cout<<"sus siguientes articulos son:"<<endl;
  lista_productosC(p,s);
  cout<<"\t el total a pagar sera de: "<<Sumar_costoT(p)<<endl;
}else{
 cout<<"\t SU LISTA ESTA ACTUALMENTE VACIA...IMPOSIBLE PROCEDER AL PAGO!"<<endl;
 }
}

void Tienda_matriz::Cancelar_compra_Total()
{
  if(p == NULL && s == NULL)
  {
    cancelar_productoNT(s,nombre_producto);
    cancelar_productoCT(p,costo);
  }else{
    cout<<"actualmente no hay productos en su lista... imposible realizar operacion \n"<<endl;
  }
}

class caballeros
{
public:
		caballeros();
		~caballeros();
		virtual void jeans();
		virtual void playeras();
        virtual void chamarras();
        virtual void sudaderas();
        virtual void calcetines();
        virtual void ropa_interior();
        virtual void calzado();
};

caballeros::caballeros(){}
caballeros::~caballeros(){}

void caballeros::jeans()
{
	cout<<"JEANS PARA HOMBRES \n";
  cout<<"\t\t\t modelos \t\t\t"<<endl;
  cout<<"\t\t -------------------------------------------------------------------- \t\t"<<endl;
  cout<<"\t\t| JEANS RECTO \"STONE\"                                                |\t\t"<<endl;
  cout<<"\t\t| JEANS BLACK                                                        |\t\t"<<endl;
  cout<<"\t\t| JEANS \"STONE\" BLANCOS                                              |\t\t"<<endl;
  cout<<"\t\t| JEANS RECTO BLACK                                                  |\t\t"<<endl;
  cout<<"\t\t| JEANS RECTO BLUE                                                   |\t\t"<<endl;
  cout<<"\t\t| JEANS \"STONE\" SILVER                                               |\t\t"<<endl;
  cout<<"\t\t| JEANS \"RASGADOS\"                                                   |\t\t"<<endl;
  cout<<"\t\t| JEANS \"SKINNY\"                                                     |\t\t"<<endl;
  cout<<"\t\t| JEANS \"BASICOS\"                                                    |\t\t"<<endl;
  cout<<"\t\t| JEANS \"BIKER\"                                                      |\t\t"<<endl;
  cout<<"\t\t -------------------------------------------------------------------- \t\t"<<endl;
}
void caballeros::playeras()
{
	cout<<"PLAYERAS PARA HOMBRE "<<endl;
  cout<<"\t\t\t modelos \t\t\t"<<endl;
  cout<<"\t\t -------------------------------------------------------------------- \t\t"<<endl;
  cout<<"\t\t| PLAYERA SIN MANGAS                                                 |\t\t"<<endl;
  cout<<"\t\t| MANGA LARGA                                                        |\t\t"<<endl;
  cout<<"\t\t| PLAYERA BLANCA                                                     |\t\t"<<endl;
  cout<<"\t\t| PLAYERA NEGRA                                                      |\t\t"<<endl;
  cout<<"\t\t| PLAYERA CUELLO REDONDO                                             |\t\t"<<endl;
  cout<<"\t\t| PLAYERA VERDE                                                      |\t\t"<<endl;
  cout<<"\t\t| PLAYERA BASICA                                                     |\t\t"<<endl;
  cout<<"\t\t| PLAYERA MANGA CORTA                                                |\t\t"<<endl;
  cout<<"\t\t| PLAYERA ROSA                                                       |\t\t"<<endl;
  cout<<"\t\t| PLAYERA GRIS                                                       |\t\t"<<endl;
  cout<<"\t\t| PLAYERA \"AWAY\"                                                     |\t\t"<<endl;
  cout<<"\t\t| PLAYERA CON ESTAMPADO                                              |\t\t"<<endl;
  cout<<"\t\t| PLAYERA MANGA LARGA AZUL                                           |\t\t"<<endl;
  cout<<"\t\t| PLAYERA CUELLO V                                                   |\t\t"<<endl;
  cout<<"\t\t -------------------------------------------------------------------- \t\t"<<endl;
}
void caballeros::chamarras()
{
	  cout<<"CHAMARRAS"<<endl;
  cout<<"\t\t\t modelos \t\t\t"<<endl;
  cout<<"\t\t  -----------------------------------------------------------------  \t\t"<<endl;
  cout<<"\t\t | CHAMARRA \"FRENCH\"                                               | \t\t"<<endl;
  cout<<"\t\t | CHAMARRA \"BOMBER\"                                               | \t\t"<<endl;
  cout<<"\t\t | CAMISA MEZCLILLA                                                | \t\t"<<endl;
  cout<<"\t\t | CHAMARRA AZUL                                                   | \t\t"<<endl;
  cout<<"\t\t | CHAMARRA PIEL                                                   | \t\t"<<endl;
  cout<<"\t\t | CAMISA TELA                                                     | \t\t"<<endl;
  cout<<"\t\t  -----------------------------------------------------------------  \t\t"<<endl;
}
void caballeros::sudaderas()
{
	  cout<<"SUDADERAS"<<endl;
  cout<<"\t\t\t modelos \t\t\t"<<endl;
  cout<<"\t\t  ----------------------------------------------------------------- \t\t"<<endl;
  cout<<"\t\t | SUDADERA NEGRA                                                  |\t\t"<<endl;
  cout<<"\t\t | SUDADERA IPN                                                    |\t\t"<<endl;
  cout<<"\t\t | SUDADERA UNAM                                                   |\t\t"<<endl;
  cout<<"\t\t | SUDADERA BUAP                                                   |\t\t"<<endl;
  cout<<"\t\t | SUDADERA UAM                                                    |\t\t"<<endl;
  cout<<"\t\t | SUDADERA WHITE                                                  |\t\t"<<endl;
  cout<<"\t\t | SUDADERA BLUE                                                   |\t\t"<<endl;
  cout<<"\t\t  ----------------------------------------------------------------- \t\t"<<endl;
}
void caballeros::calcetines()
{
	cout<<"CALCETINES"<<endl;
  cout<<"\t\t\t modelos \t\t\t"<<endl;
  cout<<"\t\t  ------------------------------------------------------------------- \t\t"<<endl;
  cout<<"\t\t | CALCETINES PACK BASICO                                            |\t\t"<<endl;
  cout<<"\t\t | CALCETINES \"ONE PACK\"                                             |\t\t"<<endl;
  cout<<"\t\t | CALCETINES LARGOS                                                 |\t\t"<<endl;
  cout<<"\t\t | TINES BASICOS                                                     |\t\t"<<endl;
  cout<<"\t\t | CALCETINES DEPORTIVOS                                             |\t\t"<<endl;
  cout<<"\t\t | CALCETINES \"CROSS\"                                                |\t\t"<<endl;
  cout<<"\t\t  ------------------------------------------------------------------- \t\t"<<endl;
}
void caballeros::ropa_interior()
{
	cout<<"ROPA INTERIOR"<<endl;
  cout<<"\t\t\t modelos \t\t\t"<<endl;
  cout<<"\t\t  ------------------------------------------------------------------- \t\t"<<endl;
  cout<<"\t\t | BOXER ALGODON                                                     |\t\t"<<endl;
  cout<<"\t\t | BOXER TELA                                                        |\t\t"<<endl;
  cout<<"\t\t | BOXER CORTO ALGODON                                               |\t\t"<<endl;
  cout<<"\t\t  ------------------------------------------------------------------- \t\t"<<endl;
}

void caballeros::calzado()
{
  cout<<"TENIS Y ZAPATOS "<<endl;
  cout<<"\t\t\t modelos \t\t\t"<<endl;
  cout<<"\t\t  -------------------------------------------------------------------- \t\t"<<endl;
  cout<<"\t\t | NIKE                                                               |\t\t"<<endl;
  cout<<"\t\t | PUMA                                                               |\t\t"<<endl;
  cout<<"\t\t | ADIDAS                                                             |\t\t"<<endl;
  cout<<"\t\t | REEBOK                                                             |\t\t"<<endl;
  cout<<"\t\t | PUMA                                                               |\t\t"<<endl;
  cout<<"\t\t | VANS                                                               |\t\t"<<endl;
  cout<<"\t\t | JEEP                                                               |\t\t"<<endl;
  cout<<"\t\t | CATERPILLAR                                                        |\t\t"<<endl;
  cout<<"\t\t  -------------------------------------------------------------------- \t\t"<<endl;
}

class Damas:public caballeros{
	public:
		Damas();
		~Damas();
		void jeans();
		void playeras();
		void chamarras();
		void sudaderas();
		void calcetines();
		void ropa_interior();
		void calzado();
};

Damas::Damas():caballeros(){}
Damas::~Damas(){}

void Damas::jeans()
{
  cout<<"JEANS PARA MUJERES\n";
  cout<<"\t\t\t modelos \t\t\t"<<endl;
  cout<<"\t\t -------------------------------------------------------------------- \t\t"<<endl;
  cout<<"\t\t| JEANS SKINNY                                                       |\t\t"<<endl;
  cout<<"\t\t| JEANS TIRO REGULAR                                                 |\t\t"<<endl;
  cout<<"\t\t| JEANS \"MOM\" FIT                                                    |\t\t"<<endl;
  cout<<"\t\t| JEANS TIRO ALTO                                                    |\t\t"<<endl;
  cout<<"\t\t| JEANS \"WIDE\" NEGRO                                                 |\t\t"<<endl;
  cout<<"\t\t| JEANS \"GIRLFRIEND\"                                                 |\t\t"<<endl;
  cout<<"\t\t| JEANS \"BONNY\" RASGADOS                                             |\t\t"<<endl;
  cout<<"\t\t| JEANS \"MARIPOSAS\"                                                  |\t\t"<<endl;
  cout<<"\t\t| JEANS \"ACID\" BLANCOS                                               |\t\t"<<endl;
  cout<<"\t\t| JEANS \"BIKER\" (PARA MUJER)                                         |\t\t"<<endl;
  cout<<"\t\t| FALDA \"VINTAGE\"                                                    |\t\t"<<endl;
  cout<<"\t\t| FALDA GUINDA IPN (PORRISTAS)                                       |\t\t"<<endl;
  cout<<"\t\t -------------------------------------------------------------------- \t\t"<<endl;
}
void Damas::playeras()
{
  cout<<"PLAYERAS PARA MUJER "<<endl;
  cout<<"\t\t\t modelos \t\t\t"<<endl;
  cout<<"\t\t -------------------------------------------------------------------- \t\t"<<endl;
  cout<<"\t\t| PLAYERA SIN MANGAS                                                 |\t\t"<<endl;
  cout<<"\t\t| MANGA LARGA                                                        |\t\t"<<endl;
  cout<<"\t\t| PLAYERA FIUSHA                                                     |\t\t"<<endl;
  cout<<"\t\t| PLAYERA ENCAJE                                                     |\t\t"<<endl;
  cout<<"\t\t| PLAYERA ASIMETRICA                                                 |\t\t"<<endl;
  cout<<"\t\t| PLAYERA AZUL \"OSITO\"                                               |\t\t"<<endl;
  cout<<"\t\t| PLAYERA BASICA                                                     |\t\t"<<endl;
  cout<<"\t\t| PLAYERA CUELLO ALTO                                                |\t\t"<<endl;
  cout<<"\t\t| PLAYERA ROSA                                                       |\t\t"<<endl;
  cout<<"\t\t| PLAYERA CORSET                                                     |\t\t"<<endl;
  cout<<"\t\t| PLAYERA \"FRENCH\"                                                   |\t\t"<<endl;
  cout<<"\t\t| PLAYERA CON ESTAMPADO                                              |\t\t"<<endl;
  cout<<"\t\t| PLAYERA COLOR VINO                                                 |\t\t"<<endl;
  cout<<"\t\t| PLAYERA CUELLO V                                                   |\t\t"<<endl;
  cout<<"\t\t -------------------------------------------------------------------- \t\t"<<endl;
}
void Damas::chamarras()
{
  cout<<"CHAMARRAS"<<endl;
cout<<"\t\t\t modelos \t\t\t"<<endl;
cout<<"\t\t  -----------------------------------------------------------------  \t\t"<<endl;
cout<<"\t\t | CHALECO \"TWEED\"                                                 | \t\t"<<endl;
cout<<"\t\t | CHAMARRA \"BIKER\" HOMBRE                                         | \t\t"<<endl;
cout<<"\t\t | CAMISA MEZCLILLA                                                | \t\t"<<endl;
cout<<"\t\t | CHAMARRA AZUL                                                   | \t\t"<<endl;
cout<<"\t\t | CHAMARRA \"BOMBER\"                                               | \t\t"<<endl;
cout<<"\t\t | CAMISA TELA                                                     | \t\t"<<endl;
cout<<"\t\t  -----------------------------------------------------------------  \t\t"<<endl;
}
void Damas::sudaderas()
{
  cout<<"SUDADERAS"<<endl;
cout<<"\t\t\t modelos \t\t\t"<<endl;
cout<<"\t\t  ----------------------------------------------------------------- \t\t"<<endl;
cout<<"\t\t | SUDADERA NEGRA                                                  |\t\t"<<endl;
cout<<"\t\t | SUDADERA IPN                                                    |\t\t"<<endl;
cout<<"\t\t | SUDADERA UNAM                                                   |\t\t"<<endl;
cout<<"\t\t | SUDADERA BUAP                                                   |\t\t"<<endl;
cout<<"\t\t | SUDADERA UAM                                                    |\t\t"<<endl;
cout<<"\t\t | SUDADERA WHITE                                                  |\t\t"<<endl;
cout<<"\t\t | SUDADERA BLUE                                                   |\t\t"<<endl;
cout<<"\t\t  ----------------------------------------------------------------- \t\t"<<endl;
}
void Damas::calcetines()
{
  cout<<"CALCETINES Y MEDIAS"<<endl;
  cout<<"\t\t\t modelos \t\t\t"<<endl;
  cout<<"\t\t  ------------------------------------------------------------------- \t\t"<<endl;
  cout<<"\t\t | CALCETAS PACK BASICO                                              |\t\t"<<endl;
  cout<<"\t\t | CALCETINES \"UNICORNIO\"                                            |\t\t"<<endl;
  cout<<"\t\t | CALCETINES PAQUETE DAMA 5PZ                                       |\t\t"<<endl;
  cout<<"\t\t | TINES BASICOS ROSA                                                |\t\t"<<endl;
  cout<<"\t\t | \"PROTECTOPIE\"                                                     |\t\t"<<endl;
  cout<<"\t\t | MEDIAS                                                            |\t\t"<<endl;
  cout<<"\t\t  ------------------------------------------------------------------- \t\t"<<endl;
}

void Damas::ropa_interior()
{
  cout<<"ROPA INTERIOR"<<endl;
  cout<<"\t\t\t modelos \t\t\t"<<endl;
  cout<<"\t\t  ------------------------------------------------------------------- \t\t"<<endl;
  cout<<"\t\t | SHORT                                                             |\t\t"<<endl;
  cout<<"\t\t | PIJAMA \"TERRY\"                                                    |\t\t"<<endl;
  cout<<"\t\t | BIKYNI \"ENCANJE\"                                                  |\t\t"<<endl;
  cout<<"\t\t | TANGA AMARILLA                                                    |\t\t"<<endl;
  cout<<"\t\t | BIKYNI ROJO                                                       |\t\t"<<endl;
  cout<<"\t\t | BRALETTE                                                          |\t\t"<<endl;
  cout<<"\t\t | BRASIER AZUL                                                      |\t\t"<<endl;
  cout<<"\t\t | PANTYMEDIAS                                                       |\t\t"<<endl;
  cout<<"\t\t | BOXER                                                             |\t\t"<<endl;
  cout<<"\t\t | PANTALETA \"ENCANJE\"                                               |\t\t"<<endl;
  cout<<"\t\t  ------------------------------------------------------------------- \t\t"<<endl;
}
void Damas::calzado()
{
  cout<<"TENIS Y ZAPATOS "<<endl;
  cout<<"\t\t\t modelos \t\t\t"<<endl;
  cout<<"\t\t  -------------------------------------------------------------------- \t\t"<<endl;
  cout<<"\t\t | SANDALIAS                                                          |\t\t"<<endl;
  cout<<"\t\t | BOTAS DE TRABAJO PARA MUJER                                        |\t\t"<<endl;
  cout<<"\t\t | TENIS CASUALES                                                     |\t\t"<<endl;
  cout<<"\t\t | TACONES                                                            |\t\t"<<endl;
  cout<<"\t\t | TENIS DE PLATAFORMA                                                |\t\t"<<endl;
  cout<<"\t\t | VANS                                                               |\t\t"<<endl;
  cout<<"\t\t | JEEP                                                               |\t\t"<<endl;
  cout<<"\t\t | ZAPATOS (PARA OFICINA)                                             |\t\t"<<endl;
  cout<<"\t\t  -------------------------------------------------------------------- \t\t"<<endl;
}

class infantes:public caballeros
{ //tanto ni�os como ni�as
public:
  infantes();
  ~infantes();
  void pantalones(); //metodo de infantes
  void calcetines();
  void sudaderas();
  void playeras();
  void chamarras();
  void paniales();
};
infantes::infantes():caballeros(){}
infantes::~infantes(){}

void infantes::pantalones()
{
  cout<<"PANTALONES (JAGGERS) PARA BEBES \n";
  cout<<"\t\t\t modelos \t\t\t"<<endl;
  cout<<"\t\t -------------------------------------------------------------------- \t\t"<<endl;
  cout<<"\t\t| JAGGER GRIS                                                        |\t\t"<<endl;
  cout<<"\t\t| JAGGER DE MEZCLILLA                                                |\t\t"<<endl;
  cout<<"\t\t| JAGGER \"RAYAS\"                                                     |\t\t"<<endl;
  cout<<"\t\t| OVEROL                                                             |\t\t"<<endl;
  cout<<"\t\t| JAGGER AZUL                                                        |\t\t"<<endl;
  cout<<"\t\t| JAGGER \"OXFORD\"                                                    |\t\t"<<endl;
  cout<<"\t\t -------------------------------------------------------------------- \t\t"<<endl;
}

void infantes::playeras()
{
  cout<<"PLAYERAS PARA BEBES"<<endl;
  cout<<"\t\t\t modelos \t\t\t"<<endl;
  cout<<"\t\t -------------------------------------------------------------------- \t\t"<<endl;
  cout<<"\t\t| PLAYERA RAYAS \"PARCHES\"                                            |\t\t"<<endl;
  cout<<"\t\t| PLAYERA JASPE                                                      |\t\t"<<endl;
  cout<<"\t\t| PLAYERA BUGS BUNNY                                                 |\t\t"<<endl;
  cout<<"\t\t| PLAYERA MICKEY MOUSE                                               |\t\t"<<endl;
  cout<<"\t\t| PLAYERA MINIOMS                                                    |\t\t"<<endl;
  cout<<"\t\t| PLAYERA THE SIMPSONS                                               |\t\t"<<endl;
  cout<<"\t\t| PLAYERA BASICA                                                     |\t\t"<<endl;
  cout<<"\t\t| PLAYERA \"GATO FELIX\"                                               |\t\t"<<endl;
  cout<<"\t\t| PLAYERA ROSA                                                       |\t\t"<<endl;
  cout<<"\t\t| PLAYERA GRIS                                                       |\t\t"<<endl;
  cout<<"\t\t| PLAYERA CARS                                                       |\t\t"<<endl;
  cout<<"\t\t| PLAYERA TOY-STORY                                                  |\t\t"<<endl;
  cout<<"\t\t| PLAYERA \"REY LEON\"                                                 |\t\t"<<endl;
  cout<<"\t\t| PLAYERA \"DINO\"                                                     |\t\t"<<endl;
  cout<<"\t\t -------------------------------------------------------------------- \t\t"<<endl;
}

void infantes::chamarras()
{
  cout<<"CHAMARRAS"<<endl;
cout<<"\t\t\t modelos \t\t\t"<<endl;
cout<<"\t\t  -----------------------------------------------------------------  \t\t"<<endl;
cout<<"\t\t | CHAMARRA LIGERA NARANJA                                         | \t\t"<<endl;
cout<<"\t\t | CHAMARRA MARIO-BROS                                             | \t\t"<<endl;
cout<<"\t\t | CHAMARRA \"PARKA\"                                                | \t\t"<<endl;
cout<<"\t\t | CHAMARRA FELPA OSO                                              | \t\t"<<endl;
cout<<"\t\t | CHAMARRA LIGERA AZUL                                            | \t\t"<<endl;
cout<<"\t\t | CHAMARRA CAMUFLAJE                                              | \t\t"<<endl;
cout<<"\t\t  -----------------------------------------------------------------  \t\t"<<endl;
}

void infantes::sudaderas()
{
  	cout<<"SUDADERAS"<<endl;
    cout<<"\t\t\t modelos \t\t\t"<<endl;
    cout<<"\t\t  ----------------------------------------------------------------- \t\t"<<endl;
    cout<<"\t\t | SUDADERA NEGRA                                                  |\t\t"<<endl;
    cout<<"\t\t | SUDADERA IPN                                                    |\t\t"<<endl;
    cout<<"\t\t | SUDADERA UNAM                                                   |\t\t"<<endl;
    cout<<"\t\t | SUDADERA BUAP                                                   |\t\t"<<endl;
    cout<<"\t\t | SUDADERA UAM                                                    |\t\t"<<endl;
    cout<<"\t\t | SUDADERA WHITE                                                  |\t\t"<<endl;
    cout<<"\t\t | SUDADERA BLUE                                                   |\t\t"<<endl;
    cout<<"\t\t  ----------------------------------------------------------------- \t\t"<<endl;
}

void infantes::calcetines()
{
  cout<<"CALCETINES"<<endl;
  cout<<"\t\t\t modelos \t\t\t"<<endl;
  cout<<"\t\t  ------------------------------------------------------------------- \t\t"<<endl;
  cout<<"\t\t | CALCETINES PACK BASICO                                            |\t\t"<<endl;
  cout<<"\t\t | CALCETINES \"ONE PACK\"                                             |\t\t"<<endl;
  cout<<"\t\t | CALCETINES LARGOS                                                 |\t\t"<<endl;
  cout<<"\t\t  ------------------------------------------------------------------- \t\t"<<endl;
}

void infantes::paniales()
{
  char car = 165;
  cout<<"PA"<<car<<"ALES"<<endl;
  cout<<"\t\t\t modelos \t\t\t"<<endl;
  cout<<"\t\t  ------------------------------------------------------------------- \t\t"<<endl;
  cout<<"\t\t | PA"<<car<<"ALES KLEEN                                                    |\t\t"<<endl;
  cout<<"\t\t | PA"<<car<<"ALES HUGGIES                                                  |\t\t"<<endl;
  cout<<"\t\t | PA"<<car<<"ALES PAMPERS                                                  |\t\t"<<endl;
  cout<<"\t\t  ------------------------------------------------------------------- \t\t"<<endl;
}

class ninos_ninas:protected caballeros
{
public:
  ninos_ninas(){}
  ~ninos_ninas(){}
  void jeans();
  void playeras();
  void chamarras();
  void sudaderas();
  void calcetines();
  void ropa_interior();
  void calzado();
};

void ninos_ninas::jeans()
{
  cout<<"JEANS PARA  NI"<<letraM<<"OS Y NI"<<letraM<<"AS \t\t \t       "<<endl;
  cout<<"\t\t\t modelos \t\t\t"<<endl;
  cout<<"\t\t  -------------------------------------------------------------- \t\t"<<endl;
  cout<<"\t\t | JEANS RECTO \"STONE\"                                        |\t\t"<<endl;
  cout<<"\t\t | JEANS BLACK                                                  |\t\t"<<endl;
  cout<<"\t\t | JEANS \"STONE\" BLANCOS                                      |\t\t"<<endl;
  cout<<"\t\t | JEANS RECTO BLACK                                            |\t\t"<<endl;
  cout<<"\t\t | JEANS RECTO BLUE                                             |\t\t"<<endl;
  cout<<"\t\t | JEANS \"WIDE\" NEGRO                                         |\t\t"<<endl;
  cout<<"\t\t | JEANS \"GIRLFRIEND\"                                         |\t\t"<<endl;
  cout<<"\t\t | JEANS \"BONNY\" RASGADOS                                     |\t\t"<<endl;
  cout<<"\t\t | JEANS \"MARIPOSAS\"                                          |\t\t"<<endl;
  cout<<"\t\t  -------------------------------------------------------------- \t\t"<<endl;
}

void ninos_ninas::playeras()
{
  cout<<"PLAYERAS PARA  NI"<<letraM<<"OS Y NI"<<letraM<<"AS \t\t \t       "<<endl;
  cout<<"\t\t\t modelos \t\t\t"<<endl;
  cout<<"\t\t --------------------------------------------------------------------------- \t\t"<<endl;
  cout<<"\t\t| PLAYERA THE SIMPSONS                                                      |\t\t"<<endl;
  cout<<"\t\t| PLAYERA BASICA                                                            |\t\t"<<endl;
  cout<<"\t\t| PLAYERA \"GATO FELIX\"                                                      |\t\t"<<endl;
  cout<<"\t\t| PLAYERA ROSA                                                              |\t\t"<<endl;
  cout<<"\t\t| PLAYERA GRIS                                                              |\t\t"<<endl;
  cout<<"\t\t| PLAYERA CARS                                                              |\t\t"<<endl;
  cout<<"\t\t| PLAYERA TOY-STORY                                                         |\t\t"<<endl;
  cout<<"\t\t| PLAYERA \"REY LEON\"                                                        |\t\t"<<endl;
  cout<<"\t\t| PLAYERA DISNEY PRINCESAS                                                  |\t\t"<<endl;
  cout<<"\t\t| PLAYERA \"MY LITTLE PONY \"                                                 |\t\t"<<endl;
  cout<<"\t\t| PLAYERA \"LADYBUG\"                                                         |\t\t"<<endl;
  cout<<"\t\t| PLAYERA CATARINA                                                          |\t\t"<<endl;
  cout<<"\t\t --------------------------------------------------------------------------- \t\t"<<endl;
}

void ninos_ninas::chamarras()
{
  cout<<"CHAMARRAS PARA  NI"<<letraM<<"OS Y NI"<<letraM<<"AS \t\t \t       "<<endl;
  cout<<"\t\t\t modelos \t\t\t"<<endl;
  cout<<"\t\t  --------------------------------------------------------- \t\t"<<endl;
  cout<<"\t\t| CHAMARRA LIGERA NARANJA                                 |\t\t"<<endl;
  cout<<"\t\t| CHAMARRA MARIO-BROS                                     |\t\t"<<endl;
  cout<<"\t\t| CHAMARRA \"PARKA\"                                        |\t\t"<<endl;
  cout<<"\t\t| CHAMARRA FELPA OSO                                      |\t\t"<<endl;
  cout<<"\t\t| CHAMARRA AZUL                                           |\t\t"<<endl;
  cout<<"\t\t| CHAMARRA \"BOMBER\"                                       |\t\t"<<endl;
  cout<<"\t\t| CAMISA TELA                                             |\t\t"<<endl;
  cout<<"\t\t --------------------------------------------------------- \t\t"<<endl;
}

void ninos_ninas::sudaderas()
{
  cout<<"SUDADERAS"<<endl;
  cout<<"\t\t\t modelos \t\t\t"<<endl;
  cout<<"\t\t ---------------------------------------------------- \t\t"<<endl;
  cout<<"\t\t| SUDADERA NEGRA                                     |\t\t"<<endl;
  cout<<"\t\t| SUDADERA IPN                                       |\t\t"<<endl;
  cout<<"\t\t| SUDADERA UNAM                                      |\t\t"<<endl;
  cout<<"\t\t| SUDADERA BUAP                                      |\t\t"<<endl;
  cout<<"\t\t| SUDADERA UAM                                       |\t\t"<<endl;
  cout<<"\t\t| SUDADERA WHITE                                     |\t\t"<<endl;
  cout<<"\t\t| SUDADERA BLUE                                      |\t\t"<<endl;
  cout<<"\t\t ---------------------------------------------------- \t\t"<<endl;
}

void ninos_ninas::calcetines()
{
  cout<<"CALCETINES PARA  NI"<<letraM<<"OS Y NI"<<letraM<<"AS \t\t \t       "<<endl;
  cout<<"\t\t\t modelos \t\t\t "<<endl;
  cout<<"\t\t -------------------------------------------- \t\t"<<endl;
  cout<<"\t\t| CALCETINES PACK BASICO                     |\t\t"<<endl;
  cout<<"\t\t| CALCETINES \"ONE PACK\"                      |\t\t"<<endl;
  cout<<"\t\t| CALCETAS PACK BASICO                       |\t\t"<<endl;
  cout<<"\t\t| CALCETINES \"UNICORNIO\"                     |\t\t"<<endl;
  cout<<"\t\t -------------------------------------------- \t\t"<<endl;
}

void ninos_ninas::ropa_interior()
{
  cout<<"ROPA INTERIOR PARA  NI"<<letraM<<"OS Y NI"<<letraM<<"AS \t\t \t       "<<endl;
  cout<<"\t\t\t modelos \t\t\t"<<endl;
  cout<<"\t\t -------------------------------------------------- \t\t"<<endl;
  cout<<"\t\t| BOXER ALGODON                                    |\t\t"<<endl;
  cout<<"\t\t| BOXER TELA                                       |\t\t"<<endl;
  cout<<"\t\t| BOXER CORTO ALGODON                              |\t\t"<<endl;
  cout<<"\t\t| BRASIER ROSA                                     |\t\t"<<endl;
  cout<<"\t\t| PANTYMEDIAS                                      |\t\t"<<endl;
  cout<<"\t\t| PIJAMA OSITOS                                    |\t\t"<<endl;
  cout<<"\t\t -------------------------------------------------- \t\t"<<endl;
}

void ninos_ninas::calzado()
{
  cout<<"CALZADO PARA  NI"<<letraM<<"OS Y NI"<<letraM<<"AS \t\t \t "<<endl;
  cout<<"\t\t\t modelos \t\t\t"<<endl;
  cout<<"\t\t ------------------------------------------------------ \t\t"<<endl;
  cout<<"\t\t| NIKE                                                 |\t\t"<<endl;
  cout<<"\t\t| PUMA                                                 |\t\t"<<endl;
  cout<<"\t\t| ADIDAS                                               |\t\t"<<endl;
  cout<<"\t\t| REEBOK                                               |\t\t"<<endl;
  cout<<"\t\t| VANS                                                 |\t\t"<<endl;
  cout<<"\t\t| JEEP                                                 |\t\t"<<endl;
  cout<<"\t\t| SANDALIAS                                            |\t\t"<<endl;
  cout<<"\t\t| BOTAS PARA EXPLORACION                               |\t\t"<<endl;
  cout<<"\t\t ------------------------------------------------------ \t\t"<<endl;
}

class AdolescentesH:public caballeros
{
public:
  AdolescentesH();
  ~AdolescentesH();
};

AdolescentesH::AdolescentesH():caballeros(){}
AdolescentesH::~AdolescentesH(){}

class AdolescentesM:public Damas
{
public:
  AdolescentesM(){}
  ~AdolescentesM(){}
};

class Electronica
{ //esta es una clase virtual pura
public:
    virtual void producto() = 0;
};

class Television:protected Electronica
{
public:
  Television();
  ~Television();
  void producto();
};

Television::Television(){}
Television::~Television(){}

void Television::producto()
{
  cout<<"\t\t\t DEPARTAMENTO DE ELECTRONICA \t\t\t"<<endl;
  cout<<"\t\t\t PANTALLAS \t\t\t "<<endl;
  cout<<"\t\t modelos \t\t"<<endl;
  cout<<"\t\t ------------------------------------------------- \t\t"<<endl;
  cout<<"\t\t| PANTALLA LED HISENSE 55P ULTRA HD               |\t\t"<<endl;
  cout<<"\t\t| PANTALLA LED HISENSE 60P ULTRA HD               |\t\t"<<endl;
  cout<<"\t\t| PANTALLA LED LG 50 4K SMART                     |\t\t"<<endl;
  cout<<"\t\t| PANTALLA LED SAMSUNG 65                         |\t\t"<<endl;
  cout<<"\t\t| PANTALLA LED LG 50 ULTRA HD                     |\t\t"<<endl;
  cout<<"\t\t| PANTALLA LED HISENS 43 HD                       |\t\t"<<endl;
  cout<<"\t\t| PANTALLA NANO CELL LG 50  4K                    |\t\t"<<endl;
  cout<<"\t\t| PANTALLA LED 75 ULTRA HD                        |\t\t"<<endl;
  cout<<"\t\t| PANTALLA LED TLC 50 ULTRA HD                    |\t\t"<<endl;
  cout<<"\t\t| PANTALLA LED SAMSUNG 58 HD                      |\t\t"<<endl;
  cout<<"\t\t ------------------------------------------------- \t\t"<<endl;
}

class computadoras:private Electronica
{
public:
  computadoras();
  ~computadoras();
  void producto();
};

computadoras::computadoras(){}
computadoras::~computadoras(){}

void computadoras::producto()
{
  cout<<"\t\t\t DEPARTAMENTO DE ELECTRONICA \t\t\t"<<endl;
  cout<<"\t\t\t LAPTOPS \t\t\t "<<endl;
  cout<<"\t\t modelos \t\t"<<endl;
  cout<<"\t\t --------------------------------------------- \t\t"<<endl;
	cout<<"\t\t| LAPTOP HP 14 AMD ATHLON                     |\t\t"<<endl;
  cout<<"\t\t| LAPTOP HP 15 AMD RYZEN                      |\t\t"<<endl;
  cout<<"\t\t| LAPTOP HP 14 INTEL CELERON                  |\t\t"<<endl;
  cout<<"\t\t| LAPTOP DELL 15.6 AMD                        |\t\t"<<endl;
  cout<<"\t\t| LAPTOP ASUS INTEL CELERON                   |\t\t"<<endl;
  cout<<"\t\t| LAPTOP HP 13 AMD RYZEN 3                    |\t\t"<<endl;
  cout<<"\t\t| LAPTOP HUAWEI MT INTEL CORE                 |\t\t"<<endl;
  cout<<"\t\t| LAPTOP ASUS INTEL CELERON                   |\t\t"<<endl;
  cout<<"\t\t| MACBOOK PRO 13                              |\t\t"<<endl;
  cout<<"\t\t --------------------------------------------- \t\t"<<endl;
}

class celulares
{
public:
  celulares();
  ~celulares();
  void producto();
};

celulares::celulares(){}
celulares::~celulares(){}

void celulares::producto()
{
  cout<<"\t\t\t DEPARTAMENTO DE ELECTRONICA \t\t\t"<<endl;
  cout<<"\t\t\t CELULARES \t\t\t"<<endl;
  cout<<"\t\t\t modelos \t\t\t"<<endl;
  cout<<"\t\t ------------------------------------------------------------------------ \t\t"<<endl;
  cout<<"\t\t| XIAOMI REDMI 9A                                                        |\t\t"<<endl;
  cout<<"\t\t| MOTOROLA MOTOG60s                                                      |\t\t"<<endl;
  cout<<"\t\t| XIAMOMI REDMI                                                          |\t\t"<<endl;
  cout<<"\t\t| APPLE IPHONE 11 64GB                                                   |\t\t"<<endl;
  cout<<"\t\t| HISENSE E50-LITE                                                       |\t\t"<<endl;
  cout<<"\t\t| MOTOROLA EDGE20                                                        |\t\t"<<endl;
  cout<<"\t\t| SAMSUNG GALAXY A12                                                     |\t\t"<<endl;
  cout<<"\t\t| MOTOROLA ONE-FUSION                                                    |\t\t"<<endl;
  cout<<"\t\t| XIAOMI REDMI-NOTE                                                      |\t\t"<<endl;
  cout<<"\t\t| SAMSUNG GALAXY-A72                                                     |\t\t"<<endl;
  cout<<"\t\t| IPHONE XR 64GB                                                         |\t\t"<<endl;
  cout<<"\t\t| OPPO   A53                                                             |\t\t"<<endl;
  cout<<"\t\t| MOTOROLA MOTO G60                                                      |\t\t"<<endl;
  cout<<"\t\t| XIAOMI REDMI 10                                                        |\t\t"<<endl;
  cout<<"\t\t| HUAWEI Y9A PLATEADO                                                    |\t\t"<<endl;
  cout<<"\t\t ------------------------------------------------------------------------ \t\t"<<endl;
}

int main(void)
{
  menu();
  return 0;
}


void menu(void)
{

  string Empleado,passwrd;
  int day,month,year,codigo;
  int opcionP;

  Tienda_matriz objtiendaMatriz;
  caballeros objcaballeros;
  Damas objdamas;
  infantes objinfantes;
  ninos_ninas objninios;
  AdolescentesH objadolescentesh;
  AdolescentesM objadolescentesm;
  Television objtelevision;
  computadoras objcomputadoras;
  celulares objcelulares;

  menu_principal();
  cin>>area;
  do
  {
  cout<<"\t\t\t ******************************************************************************"<<endl;
  cout<<"\t\t\t *                               TIENDA OFICIAL                               *"<<endl;
  cout<<"\t\t\t *                               ESIME CULHUACAN                              *"<<endl;
  cout<<"\t\t\t *                           CIUDAD DE MEXICO, CDMX                           *"<<endl;
  cout<<"\t\t\t *                              TEL: 5562047220                               *"<<endl;
  cout<<"\t\t\t ******************************************************************************"<<endl;
  cout<<"\t\t\t"<<endl;
  cout<<"\n \n"<<endl;

  cout<<"\t\t\t\t ************************************************************"<<endl;
  cout<<"\t\t\t\t *              SELECCIONE UN DEPARTAMENTO:                 *"<<endl;
  cout<<"\t\t\t\t ************************************************************"<<endl;
  cout<<"\t\t\t\t * 1. HOMBRE                                                *"<<endl;
  cout<<"\t\t\t\t *----------------------------------------------------------*"<<endl;
  cout<<"\t\t\t\t * 2. MUJER                                                 *"<<endl;
  cout<<"\t\t\t\t *----------------------------------------------------------*"<<endl;
  cout<<"\t\t\t\t * 3. BEBES DE 0-24 MESES                                   *"<<endl;
  cout<<"\t\t\t\t *----------------------------------------------------------*"<<endl;
  cout<<"\t\t\t\t * 4. NI"<<letraM<<"OS Y NI"<<letraM<<"AS \t\t \t \t            *"<<endl;
  cout<<"\t\t\t\t *----------------------------------------------------------*"<<endl;
  cout<<"\t\t\t\t * 5. ADOLESCENTES                                          *"<<endl;
  cout<<"\t\t\t\t *----------------------------------------------------------*"<<endl;
  cout<<"\t\t\t\t * 6. ELECTRONICA                                           *"<<endl;
  cout<<"\t\t\t\t *----------------------------------------------------------*"<<endl;
  cout<<"\t\t\t\t * 7. CANCELAR PRODUCTOS                                    *"<<endl;
  cout<<"\t\t\t\t *----------------------------------------------------------*"<<endl;
  cout<<"\t\t\t\t * 8. VER LISTA DE COMPRAS                                  *"<<endl;
  cout<<"\t\t\t\t *----------------------------------------------------------*"<<endl;
  cout<<"\t\t\t\t * 9. REALIZAR COMPRA                                       *"<<endl;
  cout<<"\t\t\t\t *----------------------------------------------------------*"<<endl;
  cout<<"\t\t\t\t * 10. VOLVER AL MENU PRINCIPAL                             *"<<endl;
  cout<<"\t\t\t\t ************************************************************"<<endl;
  cout<<"\n"<<endl;

  cout<<"\t\t\t"<<endl;

  cout<<"\t\t\t su opcion es $>: ";
  cin>>opcionP; //opcionP == opcion principal
  system("cls");
  switch (opcionP) {
    case 1:{//DEPARTAMENTO DE HOMBRES
        int opcHombre; //opcion de entrada para el departamento hombre
        cout<<"\t \t \t DEPARTAMENTO DE ROPA Y ACCESORIOS PARA HOMBRE \n";
        cout<<"novedades: "<<endl;
        cout<<"1. JEANS"<<endl;
        cout<<"2. PLAYERAS"<<endl;
        cout<<"3. CHAMARRAS"<<endl;
        cout<<"4. SUDADERAS"<<endl;
        cout<<"5. CALCETINES"<<endl;
        cout<<"6. ROPA INTERIOR"<<endl;
        cout<<"7. CALZADO"<<endl;
        cout<<"a que tipo de articulos desea entrar: "; cin>>opcHombre;

        switch (opcHombre) {
          case 1:{
          	 objcaballeros.jeans();
             objtiendaMatriz.Tipo_Articulo();
            break;
          }

          case 2:{
          	objcaballeros.playeras();
          	objtiendaMatriz.Tipo_Articulo();
            break;
          }

          case 3:{
          	objcaballeros.chamarras();
          	objtiendaMatriz.Tipo_Articulo();
            break;
          }

          case 4:{
          	objcaballeros.sudaderas();
          	objtiendaMatriz.Tipo_Articulo();
            break;
          }

          case 5:{
          	objcaballeros.calcetines();
          	objtiendaMatriz.Tipo_Articulo();
            break;
          }

          case 6:{
          	objcaballeros.ropa_interior();
          	objtiendaMatriz.Tipo_Articulo();
            break;
          }

          case 7:{
            objcaballeros.calzado();
    		  	objtiendaMatriz.Tipo_Articulo();
			     break;
		     }
     }
        system("pause");
        system("cls");
        break;
}

    case 2:{//DEPARTAMENTO DE MUJERES
      system("cls");
      cout<<"\t \t \t DEPARTAMENTO DE ROPA Y ACCESORIOS PARA MUJER \n";
      int opcMujer;
      cout<<"novedades: "<<endl;
      cout<<"1. JEANS y FALDAS"<<endl;
      cout<<"2. PLAYERAS"<<endl;
      cout<<"3. CHAMARAS"<<endl;
      cout<<"4. SUDADERAS"<<endl;
      cout<<"5. CALCETINES"<<endl;
      cout<<"6. ROPA INTERIOR"<<endl;
      cout<<"7. CALZADO"<<endl;
      cout<<"a que tipo de articulos desea comprar: "; cin>>opcMujer;

      switch (opcMujer) {
        case 1:{
           objdamas.jeans();
           objtiendaMatriz.Tipo_Articulo();
          break;
        }

        case 2:{
          objdamas.playeras();
          objtiendaMatriz.Tipo_Articulo();
          break;
        }

        case 3:{
          objdamas.chamarras();
          objtiendaMatriz.Tipo_Articulo();
          break;
        }

        case 4:{
          objdamas.sudaderas();
          objtiendaMatriz.Tipo_Articulo();
          break;
        }

        case 5:{
          objdamas.calcetines();
          objtiendaMatriz.Tipo_Articulo();
          break;
        }

        case 6:{
          objdamas.ropa_interior();
          objtiendaMatriz.Tipo_Articulo();
          break;
        }

        case 7:{
          objdamas.calzado();
          objtiendaMatriz.Tipo_Articulo();
          break;
         }

         default:
          cout<<"opcion no encointrada..."<<endl;
          break;
      }
      system("pause");
      system("cls");
      break;
}

    case 3:{//DEPARTAMENTO DE BEBES
      char car = 165;
      int opcbebe;

      system("cls");
      cout<<"\t \t \t DEPARTAMENTO DE BEBES DE 0-24 MESES \n";
      cout<<"novedades: "<<endl;
      cout<<"1. PANTALONES"<<endl;
      cout<<"2. PLAYERAS"<<endl;
      cout<<"3. CHAMARRAS"<<endl;
      cout<<"4. SUDADERAS"<<endl;
      cout<<"5. CALCETINES"<<endl;
      cout<<"6. PA"<<car<<"ALES"<<endl;
      cout<<"a que tipo de articulos desea entrar: "; cin>>opcbebe;

      switch (opcbebe) {
        case 1:{
           objinfantes.pantalones();
           objtiendaMatriz.Tipo_Articulo();
          break;
        }

        case 2:{
          objinfantes.playeras();
          objtiendaMatriz.Tipo_Articulo();
          break;
        }

        case 3:{
          objinfantes.chamarras();
          objtiendaMatriz.Tipo_Articulo();
          break;
        }

        case 4:{
          objinfantes.sudaderas();
          objtiendaMatriz.Tipo_Articulo();
          break;
        }

        case 5:{
          objinfantes.calcetines();
          objtiendaMatriz.Tipo_Articulo();
          break;
        }

        case 6:{
          objinfantes.paniales();
          objtiendaMatriz.Tipo_Articulo();
          break;
        }
      }
      system("pause");
      system("cls");
      break;
    }

    case 4:{//DEPARTAMENTO DE NINOS Y NINAS
      int opcninos;

      system("cls");
      cout<<"DEPARTAMENTO DE NI"<<letraM<<"OS Y NI"<<letraM<<"AS \t\t \t       "<<endl;
      cout<<"novedades: "<<endl;
      cout<<"1. PANTALONES"<<endl;
      cout<<"2. PLAYERAS"<<endl;
      cout<<"3. CHAMARRAS"<<endl;
      cout<<"4. SUDADERAS"<<endl;
      cout<<"5. CALCETINES"<<endl;
      cout<<"6. ROPA INTERIOR "<<endl;
      cout<<"7. CALZADO"<<endl;
      cout<<"a que tipo de articulos desea entrar: "; cin>>opcninos;

      switch (opcninos) {
        case 1:{
           objinfantes.pantalones();
           objtiendaMatriz.Tipo_Articulo();
          break;
        }

        case 2:{
          objninios.playeras();
          objtiendaMatriz.Tipo_Articulo();
          break;
        }

        case 3:{
          objninios.chamarras();
          objtiendaMatriz.Tipo_Articulo();
          break;
        }

        case 4:{
          objninios.sudaderas();
          objtiendaMatriz.Tipo_Articulo();
          break;
        }

        case 5:{
          objninios.calcetines();
          objtiendaMatriz.Tipo_Articulo();
          break;
        }

        case 6:{
          objninios.ropa_interior();
          objtiendaMatriz.Tipo_Articulo();
          break;
        }

        case 7:{
          objninios.calzado();
          objtiendaMatriz.Tipo_Articulo();
          break;}
      }
      system("pause");
      system("cls");
      break;}

    case 5:{//DEPARTAMNETO DE ADOLESCENTES
        int decHM;
          int opcadh, opcadm; //opcion de entrada para el departamento hombre y tambien para el departamento de mujeres
        cout<<"a que seccion quieres entrar: "<<endl;
        cout<<"1. hombres \n2. mujeres "<<endl;
        cout<<"opcion: "; cin>>decHM;

        if(decHM == 1 ){
            cout<<"DEPARTAMENTO DE ROPA Y ACCESORIOS PARA ADOLESCENTES (SECCION HOMBRES) \n";
            cout<<"novedades: "<<endl;
            cout<<"1. JEANS"<<endl;
            cout<<"2. PLAYERAS"<<endl;
            cout<<"3. CHAMARRAS"<<endl;
            cout<<"4. SUDADERAS"<<endl;
            cout<<"5. ROPA INTERIOR"<<endl;
            cout<<"6. CALCETINES"<<endl;
            cout<<"7. CALZADO"<<endl;
            cout<<"a que tipo de articulos desea entrar: "; cin>>opcadh;

          switch (opcadh) {
          case 1:{
             objadolescentesh.jeans();
             objtiendaMatriz.Tipo_Articulo();
            system("pause");
            break;
          }

          case 2:{
            objadolescentesh.playeras();
            objtiendaMatriz.Tipo_Articulo();
            break;
          }

          case 3:{
            objadolescentesh.chamarras();
            objtiendaMatriz.Tipo_Articulo();
            break;
          }

          case 4:{
            objadolescentesh.sudaderas();
            objtiendaMatriz.Tipo_Articulo();
            break;
          }

          case 5:{
            objadolescentesh.calcetines();
            objtiendaMatriz.Tipo_Articulo();
            break;
          }

          case 6:{
            objadolescentesh.ropa_interior();
            objtiendaMatriz.Tipo_Articulo();
            break;
          }

          case 7:{
            objadolescentesh.ropa_interior();
            objtiendaMatriz.Tipo_Articulo();
      break;
      }
      case 8:{
        objadolescentesh.calzado();
        objtiendaMatriz.Tipo_Articulo();
      break;
    }
    break;
  }
         }if(decHM == 2)
         {
           cout<<"DEPARTAMENTO DE ROPA Y ACCESORIOS PARA ADOLESCENTES (SECCION MUJERES) \n";
           cout<<"novedades: "<<endl;
           cout<<"1. JEANS"<<endl;
           cout<<"2. PLAYERAS"<<endl;
           cout<<"3. CHAMARRAS"<<endl;
           cout<<"4. SUDADERAS"<<endl;
           cout<<"5. ROPA INTERIOR"<<endl;
           cout<<"6. CALCETINES"<<endl;
           cout<<"7. CALZADO"<<endl;
           cout<<"a que tipo de articulos desea entrar: "; cin>>opcadm;
           switch (opcadm) {
           case 1:{
              objadolescentesm.jeans();
              objtiendaMatriz.Tipo_Articulo();
             system("pause");
             break;
           }

           case 2:{
             objadolescentesm.playeras();
             objtiendaMatriz.Tipo_Articulo();
             break;
           }

           case 3:{
             objadolescentesm.chamarras();
             objtiendaMatriz.Tipo_Articulo();
             break;
           }

           case 4:{
             objadolescentesm.sudaderas();
             objtiendaMatriz.Tipo_Articulo();
             break;
           }

           case 5:{
             objadolescentesm.calcetines();
             objtiendaMatriz.Tipo_Articulo();
             break;
           }

           case 6:{
             objadolescentesm.ropa_interior();
             objtiendaMatriz.Tipo_Articulo();
             break;
           }

           case 7:{
             objadolescentesm.ropa_interior();
             objtiendaMatriz.Tipo_Articulo();
       break;
       }
       case 8:{
         objadolescentesm.calzado();
         objtiendaMatriz.Tipo_Articulo();
       break;
       }
    break;
   }
         }
         system("pause");
         system("cls");
        break;}

    case 6:{ //departamento electronica
          int opcElec; //opcion de entrada para el departamento hombre
          cout<<"DEPARTAMENTO DE ELECTRONICA \n";
          cout<<"novedades: "<<endl;
          cout<<"1. TELEVISIONES"<<endl;
          cout<<"2. COMPUTADORAS"<<endl;
          cout<<"3. CELULARES"<<endl;
          cout<<"a que tipo de articulos desea entrar: "; cin>>opcElec;

          switch (opcElec) {
            case 1:{
              objtelevision.producto();
              objtiendaMatriz.Tipo_Articulo();
              break;
            }

            case 2:{
              objcomputadoras.producto();
              objtiendaMatriz.Tipo_Articulo();
              break;
            }

            case 3:{
              objcelulares.producto();
              objtiendaMatriz.Tipo_Articulo();
            break;}
          }
          system("pause");
          system("cls");
          break;
         }

    case 7:{ //CANCELA PRODUCTO (PRODUCTOS POR SEPARADO)
       cout<<" SELECCIONE DE SU LISTA LOS PRODUCTOS QUE DESEA CANCELAR \t\t \n\n"<<endl;
       objtiendaMatriz.listaCompra();
       cout<<"\n"<<endl;
       objtiendaMatriz.Cancelar_compra();
       system("pause");
       system("cls");
      break;}

    case 8:{//LISTA DE COMPRAS (CARRITO)
  	  system("cls");
      cout<<"\t \t \t LISTA DE COMPRAS \n";
      objtiendaMatriz.listaCompra();
      system("pause");
      system("cls");
  break;}

    case 9:{//REALIZAR COMPRA
      objtiendaMatriz.CantidadT();
      system("pause");
      objtiendaMatriz.Cancelar_compra_Total();
      system("cls");
      cout<<"REALIZANDO COMPRA...ESPERE UN MOMENTO"<<endl;
      cout<<"COMPRA EXITOSA! GRACIAS POR SU VISITA"<<endl;
      system("pause");
      system("cls");
      break;}

  /*  case 10:{//volver al menu principal
      menu_principal();
      cout<<"AREA A INGRESAR>>";
      cin>>area;
      if(area == 1){
        menu();
      }if(area == 2){

       system("cls");
       almacen();
      }
      system("pause");
      system("cls");
    break;} */

    default:
    cout<<"OPCION NO VALIDA \n"<<endl;
    break;

  }
 }while(opcionP != 0);
} //fin del menu

void almacen(void)
{
  cout<<"\t\t\t ******************************************************************* \t\t\t"<<endl;
  cout<<"\t\t\t *       BIENVENIDO AL SISTEMA DE CONTROL PARA SU TIENDA           * \t\t\t"<<endl;
  cout<<"\t\t\t ******************************************************************* \t\t\t"<<endl;
  cout<<"\n\n\n"<<endl;
  cout<<"\t\t\t\t A QUE SECCION QUIERE INGRESAR \t\t\t"<<endl;
  cout<<"\t\t\t\t **************************************** \t\t\t"<<endl;
  cout<<"\t\t\t\t *  [1] AREA DE VENTA AL CLIENTE        * \t\t\t"<<endl;
  cout<<"\t\t\t\t *--------------------------------------* \t\t\t"<<endl;
  cout<<"\t\t\t\t *  [2]    AREA DEL ALMACEN             * \t\t\t"<<endl;
  cout<<"\t\t\t\t **************************************** \t\t\t"<<endl;

  cout<<"\t\t\t\t AREA A INGREAR>> ";
}
