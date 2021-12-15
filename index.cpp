#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

char  letra  = 164; //letra � en minuscula (ASCII)
char  letraM  = 165; //letra � en mayuscula (ASCII)
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

void lista_productosC(ptrLista &p, ptrListaS &s)
{//muestra el precio de los articulos
  ptrLista aux;
  ptrListaS auxs;

  aux = p;
  auxs = s;

  while(aux != NULL && auxs != NULL){
    cout<<"\t"<<auxs -> plr<<" ===============================  \t\t["<<aux -> nro<<"]"<<"\n";
    auxs = auxs -> sgteP;
    aux = aux -> sgte;
  }
}

float Sumar_costoT(ptrLista &p)
{ //suma el costo total de la compra
  int adition = 0;
   while(p != NULL){
    adition = adition + p -> nro;
    p = p -> sgte;
   }
   return adition;
}

/*float Sumar_costoT_descuento(ptrLista &p)
{
  int aditionDesc = 0, opDesc;
  cout<<"que tipo de descuento aplicara: ";
  cin>>opDesc;

  switch (opDesc) {
   case 1:{
      while(p != NULL){
        aditionDesc = aditionDesc + (p -> nro);
        p = p ->sgte;
      }
      return aditionDesc*0.25;
      break;}

    case 2:{
      while(p != NULL){
        aditionDesc = aditionDesc + (p -> nro);
        p = p ->sgte;
      }
      return aditionDesc*0.30;
      break;}

    case 3:{
      while(p != NULL){
        aditionDesc = aditionDesc + (p -> nro);
        p = p ->sgte;
      }
      return aditionDesc*0.50;
      break;}

    case 4:{
      while(p != NULL){
        aditionDesc = aditionDesc + (p -> nro);
        p = p ->sgte;
      }
      return aditionDesc*0.50;
      break;}
    case 5:{
      while(p != NULL){
        aditionDesc = aditionDesc + (p -> nro);
        p = p ->sgte;
      }
      return aditionDesc*0.30;
      break;}
  }
}*/   //--revisar funcionalidad--//

class Power_Ranger
{
  friend void agrega_productoC(ptrLista &p, int valor);
  friend void agrega_productoN(ptrListaS &s,string palabra);
  friend void cancelar_productoC(ptrLista &p, int valor);
  friend void cancelar_productoS(ptrListaS &s,string palabra);
  friend void lista_productosC(ptrLista &p,ptrListaS &s);
  friend float Sumar_costoT(ptrLista &p);
  friend float Sumar_costoT_descuento(ptrLista &p);
public:
  float codigo;       //atributo de tipo unidad (int) para cada articulo
  float costo;      //precio asignado para cada articulo
  float costoT;     //precio total de la compra (tambien puede aplicarse la compra al meyoreo)
  float T_pagar;    //total de articulos seleccionados
  float TC_descuento_Aplicado; //que descuento se esta aplicando a cada departamento y/o producto
  string nombre_producto;
  ptrLista p = NULL;
  ptrListaS s = NULL;
  Power_Ranger(); //DESTRUCTOR ESTANDAr
   ~Power_Ranger(); //CONSTRCUTOR ESTANDAR
   void Tipo_Articulo(); //QUE ARTICULO SE SELECCIONO POR CADA DEPARTAMENTO
   void Cancelar_compra(); //metodo que sera implementado con clase virtual
   void CantidadT(); //cantidad total por todos los articulos
  //virtual int codigo_articulo(); //codigo por cada articulo
   void oferta(); //que oferta se le dara al cliente, nota se despliega una lista de descuentos RECUERDALO
   int descuento(); //aplica el descuento a cada articulo comprado
  //virtual void total_pagar_Descuento(); //CANTIDAD A PAGAR CON DESCUENTO APLICADO/*
   void listaCompra();}; //fin de mi clase Tienda_matriz


/*----------------------inicio de la declaracion de metodos de la funcion--------------------------*/
/*-------------------------------------junto con  constructores-----------------------------------*/

/*********** CONSTRUCTORES y DESTRUCTORES **************/
Power_Ranger::Power_Ranger(){}  //constructor estandar

Power_Ranger::~Power_Ranger(){} //destructor estandar
/******** FIN DE LOS CONSTRUCTORES  Y DESTRUCTORES ***********/


void Power_Ranger::Tipo_Articulo()
{
  int agregar;

  do{
   cout<<"Que articulo va a agregar a su lista: ";
    cin>>nombre_producto;
    agrega_productoN(s,nombre_producto);
   cout<<"producto: "<<nombre_producto<<" agregado a su lista."<<endl;
   cout<<"precio: ";
    cin>>costo;
    agrega_productoC(p,costo);
   cout<<"desea agregar otro articulo a su lista: \n";
   cout<<"1. SI \n";
   cout<<"0. NO \n";
   cout<<"$> ";
    cin>>agregar;
 }while(agregar != 0);
}
void Power_Ranger::Cancelar_compra()
{ //este metodo solo cancela un producto
   cout<<"que producto desea cancelar: ";
   cin>>nombre_producto;
   cancelar_productoS(s,nombre_producto);
   cout<<"costo del producto: ";
   cin>>costo;
   cancelar_productoC(p,costo);
}

void Power_Ranger::oferta()
{

  cout<<"\t                                                   "<<endl;
  cout<<"\t                   DESCUENTOS DEL MES              "<<endl;
  cout<<"\t"<<endl;
  cout<<"\n \t sujeto a disponiblilidad"<<endl;
  cout<<"\n"<<endl;


  cout<<"\t\t  aplicable para                         descuentos        "<<endl;
  cout<<"\t\t                                                           "<<endl;
  cout<<"\t\t  1. Estudiantes                          [ 25 %]          "<<endl;
  cout<<"\t\t                                                           "<<endl;
  cout<<"\t\t  2. ADULTOS MAYORES                      [ 30 %]          "<<endl;
  cout<<"\t\t                                                           "<<endl;
  cout<<"\t\t  3. ESTUDIANTES IPN                      [ 50 %]          "<<endl;
  cout<<"\t\t                                                           "<<endl;
  cout<<"\t\t  4. DOCTORES Y ENFERMER@S                [ 5O %]          "<<endl;
  cout<<"\t\t                                                           "<<endl;
  cout<<"\t\t  5. MAESTR@S                              [ 30 %]          "<<endl;
  cout<<"\t\t                                                           "<<endl;
}

int Power_Ranger::descuento()
{ //verificar la funcionalidad de este metodo

  int opcDesc; //opcion de Descuento
  float x = Sumar_costoT(p);
  cout<<"Desea aplicar un descuento a su compra: "<<endl;
  cout<<"1. SI \n 0. NO "<<endl;
  cout<<"su opcion es: ";
  cin>>opcDesc;

  switch (opcDesc) {
    case 1:{
      cout<<"el descuento se ha aplicado: \n";
      cout<<"el total a pagar es : "<<(x*0.25)<<endl;
      break;
    }

    case 2:{
      cout<<"el descuento de ha aplicado \n";
      cout<<"el total a pagar sera de: "<<(x*0.3)<<endl;
      break;
    }

    case 3:{
      cout<<"el descuento se ha aplicado \n";
      cout<<"el total a pagar sera de: "<<(x*0.5)<<endl;
      break;
    }

    case 4:{
      cout<<"el descuento se ha aplicado \n";
      cout<<"el total a pagar sera de: "<<(x*0.5)<<endl;
      break;
    }

    case 5:{
      cout<<"el descuento se ha aplicado \n";
      cout<<"el total a pagar sera de: "<<(x*0.3)<<endl;
      break;
    }
    default:
     cout<<"no se ingreso ninguna opcion correcta \n";
  }
}  //ferificar muy bien el proceso de descuento

void Power_Ranger::listaCompra()
{
  cout<<"su lista de compras total es: "<<endl;
  lista_productosC(p,s);
}

void Power_Ranger::CantidadT()
{ //metodo que me muestra la cantidad total a pagar de la compra (es el ticket)
  cout<<"\t\t\t"<<endl;
  cout<<"THE POWER RANGER                                "<<endl;
  cout<<"ticket de compra                                "<<endl;
  cout<<"CIUDAD DE MEXICO, CDMX                            "<<endl;
  cout<<"\n \n"<<endl;

  cout<<"sus siguientes articulos son:"<<endl;
  lista_productosC(p,s);
  cout<<"\t\t\t el total a pagar sera de: "<<Sumar_costoT(p)<<endl;
  cout<<"\t\t\t gracias por su compra \n";
}

class caballeros: public Power_Ranger
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
  cout<<"modelos"<<endl;
  cout<<"JEANS RECTO \"STONE\"   "<<endl;
  cout<<"JEANS BLACK             "<<endl;
  cout<<"JEANS \"STONE\" BLANCOS "<<endl;
  cout<<"JEANS RECTO BLACK       "<<endl;
  cout<<"JEANS RECTO BLUE        "<<endl;
  cout<<"JEANS \"STONE\" SILVER  "<<endl;
  cout<<"JEANS \"RASGADOS\"      "<<endl;
  cout<<"JEANS \"SKINNY\"        "<<endl;
  cout<<"JEANS \"BASICOS\"       "<<endl;
  cout<<"JEANS \"BIKER\"         "<<endl;
}
void caballeros::playeras()
{
	cout<<"PLAYERAS PARA HOMBRE "<<endl;
  cout<<"modelos"<<endl;
  cout<<"PLAYERA SIN MANGAS             "<<endl;
  cout<<"MANGA LARGA                    "<<endl;
  cout<<"PLAYERA BLANCA                 "<<endl;
  cout<<"PLAYERA NEGRA                  "<<endl;
  cout<<"PLAYERA CUELLO REDONDO         "<<endl;
  cout<<"PLAYERA VERDE                  "<<endl;
  cout<<"PLAYERA BASICA                 "<<endl;
  cout<<"PLAYERA MANGA CORTA            "<<endl;
  cout<<"PLAYERA ROSA                   "<<endl;
  cout<<"PLAYERA GRIS                   "<<endl;
  cout<<"PLAYERA \"AWAY\"               "<<endl;
  cout<<"PLAYERA CON ESTAMPADO          "<<endl;
  cout<<"PLAYERA MANGA LARGA AZUL       "<<endl;
  cout<<"PLAYERA CUELLO V               "<<endl;
}
void caballeros::chamarras()
{
	  cout<<"CHAMARRAS"<<endl;
  cout<<"modelos"<<endl;
  cout<<"CHAMARRA \"FRENCH\"             "<<endl;
  cout<<"CHAMARRA \"BOMBER\"             "<<endl;
  cout<<"CAMISA MEZCLILLA         "<<endl;
  cout<<"CHAMARRA AZUL            "<<endl;
  cout<<"CHAMARRA PIEL            "<<endl;
  cout<<"CAMISA TELA              "<<endl;
}
void caballeros::sudaderas()
{
	  cout<<"SUDADERAS"<<endl;
  cout<<"modelos"<<endl;
  cout<<"SUDADERA NEGRA      "<<endl;
  cout<<"SUDADERA IPN        "<<endl;
  cout<<"SUDADERA UNAM       "<<endl;
  cout<<"SUDADERA BUAP       "<<endl;
  cout<<"SUDADERA UAM        "<<endl;
  cout<<"SUDADERA WHITE      "<<endl;
  cout<<"SUDADERA BLUE       "<<endl;
}
void caballeros::calcetines()
{
	cout<<"CALCETINES"<<endl;
  cout<<"modelos"<<endl;
  cout<<"CALCETINES PACK BASICO      "<<endl;
  cout<<"CALCETINES \"ONE PACK\"     "<<endl;
  cout<<"CALCETINES LARGOS           "<<endl;
  cout<<"TINES BASICOS               "<<endl;
  cout<<"CALCETINES DEPORTIVOS       "<<endl;
  cout<<"CALCETINES \"CROSS\"        "<<endl;
}
void caballeros::ropa_interior()
{
	cout<<"ROPA INTERIOR"<<endl;
  cout<<"modelos"<<endl;
  cout<<"BOXER ALGODON                  "<<endl;
  cout<<"BOXER TELA                     "<<endl;
  cout<<"BOXER CORTO ALGODON            "<<endl;
}
void menu(void); //prototipo de la funcion menu

void caballeros::calzado()
{
  cout<<"TENIS Y ZAPATOS "<<endl;
  cout<<"modelos "<<endl;
  cout<<"NIKE                       "<<endl;
  cout<<"PUMA                       "<<endl;
  cout<<"ADIDAS                     "<<endl;
  cout<<"REEBOK                     "<<endl;
  cout<<"PUMA                       "<<endl;
  cout<<"VANS                       "<<endl;
  cout<<"JEEP                       "<<endl;
  cout<<"CATERPILLAR                "<<endl;
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
  cout<<"modelos"<<endl;
  cout<<"JEANS SKINNY                          "<<endl;
  cout<<"JEANS TIRO REGULAR                    "<<endl;
  cout<<"JEANS \"MOM\" FIT                     "<<endl;
  cout<<"JEANS TIRO ALTO                       "<<endl;
  cout<<"JEANS \"WIDE\" NEGRO                  "<<endl;
  cout<<"JEANS \"GIRLFRIEND\"                  "<<endl;
  cout<<"JEANS \"BONNY\" RASGADOS              "<<endl;
  cout<<"JEANS \"MARIPOSAS\"                   "<<endl;
  cout<<"JEANS \"ACID\" BLANCOS                "<<endl;
  cout<<"JEANS \"BIKER\" (PARA MUJER)          "<<endl;
  cout<<"FALDA \"VINTAGE\"                     "<<endl;
  cout<<"FALDA GUINDA IPN (PORRISTAS)          "<<endl;
}
void Damas::playeras()
{
  cout<<"PLAYERAS PARA MUJER "<<endl;
  cout<<"modelos"<<endl;
  cout<<"PLAYERA SIN MANGAS         "<<endl;
  cout<<"MANGA LARGA                "<<endl;
  cout<<"PLAYERA FIUSHA             "<<endl;
  cout<<"PLAYERA ENCAJE             "<<endl;
  cout<<"PLAYERA ASIMETRICA         "<<endl;
  cout<<"PLAYERA AZUL \"OSITO\"     "<<endl;
  cout<<"PLAYERA BASICA             "<<endl;
  cout<<"PLAYERA CUELLO ALTO        "<<endl;
  cout<<"PLAYERA ROSA               "<<endl;
  cout<<"PLAYERA CORSET             "<<endl;
  cout<<"PLAYERA \"FRENCH\"         "<<endl;
  cout<<"PLAYERA CON ESTAMPADO      "<<endl;
  cout<<"PLAYERA COLOR VINO         "<<endl;
  cout<<"PLAYERA CUELLO V           "<<endl;
}
void Damas::chamarras()
{
  cout<<"CHAMARRAS"<<endl;
cout<<"modelos"<<endl;
cout<<"CHALECO \"TWEED\"                 "<<endl;
cout<<"CHAMARRA \"BIKER\" MUJER         "<<endl;
cout<<"CAMISA MEZCLILLA                  "<<endl;
cout<<"CHAMARRA AZUL                     "<<endl;
cout<<"CHAMARRA \"BOMBER\"               "<<endl;
cout<<"CAMISA TELA                       "<<endl;
}
void Damas::sudaderas()
{
  cout<<"SUDADERAS"<<endl;
cout<<"modelos"<<endl;
cout<<"SUDADERA NEGRA              "<<endl;
cout<<"SUDADERA IPN                "<<endl;
cout<<"SUDADERA UNAM               "<<endl;
cout<<"SUDADERA BUAP               "<<endl;
cout<<"SUDADERA UAM                "<<endl;
cout<<"SUDADERA WHITE              "<<endl;
cout<<"SUDADERA BLUE               "<<endl;
}
void Damas::calcetines()
{
  cout<<"CALCETINES Y MEDIAS"<<endl;
  cout<<"modelos"<<endl;
  cout<<"CALCETAS PACK BASICO                  "<<endl;
  cout<<"CALCETINES \"UNICORNIO\"              "<<endl;
  cout<<"CALCETINES PAQUETE DAMA 5PZ           "<<endl;
  cout<<"TINES BASICOS ROSA                    "<<endl;
  cout<<"\"PROTECTOPIE\"                       "<<endl;
  cout<<"MEDIAS                                "<<endl;
}

void Damas::ropa_interior()
{
  cout<<"ROPA INTERIOR"<<endl;
  cout<<"modelos"<<endl;
  cout<<"SHORT                         "<<endl;
  cout<<"PIJAMA \"TERRY\"              "<<endl;
  cout<<"BIKYNI \"ENCANJE\"            "<<endl;
  cout<<"TANGA AMARILLA                "<<endl;
  cout<<"BIKYNI ROJO                   "<<endl;
  cout<<"BRALETTE                      "<<endl;
  cout<<"BRASIER AZUL                  "<<endl;
  cout<<"PANTYMEDIAS                   "<<endl;
  cout<<"BOXER                         "<<endl;
  cout<<"PANTALETA \"ENCANJE\"         "<<endl;
}
void Damas::calzado()
{
  cout<<"TENIS Y ZAPATOS "<<endl;
  cout<<"modelos"<<endl;
  cout<<"SANDALIAS                     "<<endl;
  cout<<"BOTAS DE TRABAJO PARA MUJER   "<<endl;
  cout<<"TENIS CASUALES                "<<endl;
  cout<<"TACONES                       "<<endl;
  cout<<"TENIS DE PLATAFORMA           "<<endl;
  cout<<"VANS                          "<<endl;
  cout<<"JEEP                          "<<endl;
  cout<<"ZAPATOS (PARA OFICINA)        "<<endl;
}

class infantes:public caballeros
{ //tanto niños como niñas
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
  cout<<"modelos"<<endl;
  cout<<"JAGGER GRIS           "<<endl;
  cout<<"JAGGER DE MEZCLILLA   "<<endl;
  cout<<"JAGGER \"RAYAS\"      "<<endl;
  cout<<"OVEROL                "<<endl;
  cout<<"JAGGER AZUL           "<<endl;
  cout<<"JAGGER \"OXFORD\"     "<<endl;
}

void infantes::playeras()
{
  cout<<"PLAYERAS PARA BEBES"<<endl;
  cout<<"modelos "<<endl;
  cout<<"PLAYERA RAYAS \"PARCHES\"             "<<endl;
  cout<<"PLAYERA JASPE                         "<<endl;
  cout<<"PLAYERA BUGS BUNNY                    "<<endl;
  cout<<"PLAYERA MICKEY MOUSE                  "<<endl;
  cout<<"PLAYERA MINIOMS                       "<<endl;
  cout<<"PLAYERA THE SIMPSONS                  "<<endl;
  cout<<"PLAYERA BASICA                        "<<endl;
  cout<<"PLAYERA \"GATO FELIX\"                "<<endl;
  cout<<"PLAYERA ROSA                          "<<endl;
  cout<<"PLAYERA GRIS                          "<<endl;
  cout<<"PLAYERA CARS                          "<<endl;
  cout<<"PLAYERA TOY-STORY                     "<<endl;
  cout<<"PLAYERA \"REY LEON\"                  "<<endl;
  cout<<"PLAYERA \"DINO\"                      "<<endl;
}

void infantes::chamarras()
{
  cout<<"CHAMARRAS"<<endl;
cout<<"modelos"<<endl;
cout<<"CHAMARRA LIGERA NARANJA   "<<endl;
cout<<"CHAMARRA MARIO-BROS       "<<endl;
cout<<"CHAMARRA \"PARKA\"        "<<endl;
cout<<"CHAMARRA FELPA OSO        "<<endl;
cout<<"CHAMARRA LIGERA AZUL      "<<endl;
cout<<"CHAMARRA CAMUFLAJE        "<<endl;
}

void infantes::sudaderas()
{
  	cout<<"SUDADERAS"<<endl;
    cout<<"modelos "<<endl;
    cout<<"SUDADERA NEGRA                 "<<endl;
    cout<<"SUDADERA IPN                   "<<endl;
    cout<<"SUDADERA UNAM                  "<<endl;
    cout<<"SUDADERA BUAP                  "<<endl;
    cout<<"SUDADERA UAM                   "<<endl;
    cout<<"SUDADERA WHITE                 "<<endl;
    cout<<"SUDADERA BLUE                  "<<endl;
}

void infantes::calcetines()
{
  cout<<"CALCETINES"<<endl;
  cout<<"modelos "<<endl;
  cout<<"CALCETINES PACK BASICO              "<<endl;
  cout<<"CALCETINES \"ONE PACK\"             "<<endl;
  cout<<"CALCETINES LARGOS                   "<<endl;
}

void infantes::paniales()
{
  char car = 165;
  cout<<"PA"<<car<<"ALES"<<endl;
  cout<<"modelos"<<endl;
  cout<<"PA"<<car<<"ALES KLEEN            "<<endl;
  cout<<"PA"<<car<<"ALES HUGGIES          "<<endl;
  cout<<"PA"<<car<<"ALES PAMPERS          "<<endl;
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
  cout<<"modelos"<<endl;
  cout<<"JEANS RECTO \"STONE\"   "<<endl;
  cout<<"JEANS BLACK             "<<endl;
  cout<<"JEANS \"STONE\" BLANCOS "<<endl;
  cout<<"JEANS RECTO BLACK       "<<endl;
  cout<<"JEANS RECTO BLUE        "<<endl;
  cout<<"JEANS \"WIDE\" NEGRO                  "<<endl;
  cout<<"JEANS \"GIRLFRIEND\"                  "<<endl;
  cout<<"JEANS \"BONNY\" RASGADOS              "<<endl;
  cout<<"JEANS \"MARIPOSAS\"                   "<<endl;
}

void ninos_ninas::playeras()
{
  cout<<"PLAYERAS PARA  NI"<<letraM<<"OS Y NI"<<letraM<<"AS \t\t \t       "<<endl;
  cout<<"PLAYERA THE SIMPSONS                  "<<endl;
  cout<<"PLAYERA BASICA                        "<<endl;
  cout<<"PLAYERA \"GATO FELIX\"                "<<endl;
  cout<<"PLAYERA ROSA                          "<<endl;
  cout<<"PLAYERA GRIS                          "<<endl;
  cout<<"PLAYERA CARS                          "<<endl;
  cout<<"PLAYERA TOY-STORY                     "<<endl;
  cout<<"PLAYERA \"REY LEON\"                  "<<endl;
  cout<<"PLAYERA DISNEY PRINCESAS              "<<endl;
  cout<<"PLAYERA \"MY LITTLE PONY \"           "<<endl;
  cout<<"PLAYERA \"LADYBUG\"                   "<<endl;
  cout<<"PLAYERA CATARINA                      "<<endl;
}

void ninos_ninas::chamarras()
{
  cout<<"CHAMARRAS PARA  NI"<<letraM<<"OS Y NI"<<letraM<<"AS \t\t \t       "<<endl;
  cout<<"CHAMARRA LIGERA NARANJA   "<<endl;
  cout<<"CHAMARRA MARIO-BROS       "<<endl;
  cout<<"CHAMARRA \"PARKA\"        "<<endl;
  cout<<"CHAMARRA FELPA OSO        "<<endl;
  cout<<"CHAMARRA AZUL                     "<<endl;
  cout<<"CHAMARRA \"BOMBER\"               "<<endl;
  cout<<"CAMISA TELA                       "<<endl;
}

void ninos_ninas::sudaderas()
{
  cout<<"SUDADERAS"<<endl;
  cout<<"modelos "<<endl;
  cout<<"SUDADERA NEGRA                 "<<endl;
  cout<<"SUDADERA IPN                   "<<endl;
  cout<<"SUDADERA UNAM                  "<<endl;
  cout<<"SUDADERA BUAP                  "<<endl;
  cout<<"SUDADERA UAM                   "<<endl;
  cout<<"SUDADERA WHITE                 "<<endl;
  cout<<"SUDADERA BLUE                  "<<endl;
}

void ninos_ninas::calcetines()
{
  cout<<"CALCETINES PARA  NI"<<letraM<<"OS Y NI"<<letraM<<"AS \t\t \t       "<<endl;
  cout<<"modelos"<<endl;
  cout<<"CALCETINES PACK BASICO      "<<endl;
  cout<<"CALCETINES \"ONE PACK\"     "<<endl;
  cout<<"CALCETAS PACK BASICO        "<<endl;
  cout<<"CALCETINES \"UNICORNIO\"    "<<endl;
}

void ninos_ninas::ropa_interior()
{
  cout<<"ROPA INTERIOR PARA  NI"<<letraM<<"OS Y NI"<<letraM<<"AS \t\t \t       "<<endl;
  cout<<"modelos"<<endl;
  cout<<"BOXER ALGODON                  "<<endl;
  cout<<"BOXER TELA                     "<<endl;
  cout<<"BOXER CORTO ALGODON            "<<endl;
  cout<<"BRASIER ROSA                   "<<endl;
  cout<<"PANTYMEDIAS                    "<<endl;
  cout<<"PIJAMA OSITOS                  "<<endl;
}

void ninos_ninas::calzado()
{
  cout<<"CALZADO PARA  NI"<<letraM<<"OS Y NI"<<letraM<<"AS \t\t \t       "<<endl;
  cout<<"modelos "<<endl;
  cout<<"NIKE                       "<<endl;
  cout<<"PUMA                       "<<endl;
  cout<<"ADIDAS                     "<<endl;
  cout<<"REEBOK                     "<<endl;
  cout<<"VANS                          "<<endl;
  cout<<"JEEP                          "<<endl;
  cout<<"SANDALIAS                     "<<endl;
  cout<<"BOTAS PARA EXPLORACION        "<<endl;
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
protected:

   float p_precio;
   string p_marca;
   string p_nombre_producto;
public:
    virtual void marca() = 0;
    virtual void precio() = 0;
    virtual void nombre_producto() = 0;
};
class Television:protected Electronica
{
public:
  Television();
  Television(float);
  Television(string);
  ~Television();

  void marca();
  void precio();
  void nombre_producto();
};

Television::Television(){}
Television::Television(float _precio)
{p_precio = _precio;}
Television::Television(string _marca)
{p_marca = _marca;}
Television::~Television(){}


void Television::marca()
{
  cout<<"marca del producto:"<<p_marca<<endl;
}

void Television::precio(){}

void Television::nombre_producto(){}

int main(void)
{
  menu();
  return 0;
}
void menu(void)
{


  Power_Ranger objPR;
  caballeros objcaballeros;
  Damas objdamas;
  infantes objinfantes;
  ninos_ninas objninios;
  AdolescentesH objadolescentesh;
  AdolescentesM objadolescentesm;

  float costo;
  string nombre_marca;

  Television objTelevision;
  Television objTelevisionf(costo);
  Television objTelevisions(nombre_marca);

  int opcionP;
  do{
  cout<<"\t\t\t"<<endl;
  cout<<"THE POWER RANGER               "<<endl;
  cout<<"CIUDAD DE MEXICO, CDMX         "<<endl;
  cout<<"TEL: 5562047220"<<endl;
  cout<<"\n \n"<<endl;

  cout<<"SELECCIONE UN DEPARTAMENTO: "<<endl;
  cout<<"\n"<<endl;
  cout<<"1. HOMBRE                                    "<<endl;
  cout<<"2. MUJER                                     "<<endl;
  cout<<"3. BEBES DE 0-24 MESES                       "<<endl;
  cout<<"4. NI"<<letraM<<"OS Y NI"<<letraM<<"AS \t\t \t       "<<endl;
  cout<<"5. ADOLESCENTES                              "<<endl;
  cout<<"6. ELEACTRONICA                              "<<endl;
  cout<<"7. VARIOS   (COMPRA AL MAYOREO)              "<<endl;
  cout<<"8. CANCELAR PRODUCTOS                        "<<endl;
  cout<<"9. REALIZAR COMPRA                           "<<endl;
  cout<<"10. VER LISTA DE COMPRAS                     "<<endl;
  cout<<"\n"<<endl;

  cout<<"\n\n"<<endl;
  cout<<"ATENCION                     "<<endl;
  cout<<"O bien ingrese la contrase"<<letra<<"a para acceder al area de control...     "<<endl;
  cout<<"puede ingresar la contrase"<<letra<<"a en entrada de opcion \t       "<<endl;

  cout<<"su opcion es $>: ";
  cin>>opcionP; //opcionP == opcion principal
  system("cls");
  switch (opcionP) {
    case 1:{
        int opcHombre; //opcion de entrada para el departamento hombre
        cout<<"DEPARTAMENTO DE ROPA Y ACCESORIOS PARA HOMBRE \n";
        cout<<"novedades: "<<endl;
        cout<<"1. JEANS"<<endl;
        cout<<"2. PLAYERAS"<<endl;
        cout<<"3. FIESTA"<<endl;
        cout<<"4. SUDADERAS"<<endl;
        cout<<"5. ROPA INTERIOR"<<endl;
        cout<<"6. CALCETINES"<<endl;

        cout<<"a que tipo de articulos desea entrar: "; cin>>opcHombre;

        switch (opcHombre) {
          case 1:{
          	 objcaballeros.jeans();
             objPR.Tipo_Articulo();
            system("pause");
            break;
          }

          case 2:{
          	objcaballeros.playeras();
          	objPR.Tipo_Articulo();
            break;
          }

          case 3:{
          	objcaballeros.chamarras();
          	objPR.Tipo_Articulo();
            break;
          }

          case 4:{
          	objcaballeros.sudaderas();
          	objPR.Tipo_Articulo();
            break;
          }

          case 5:{
          	objcaballeros.calcetines();
          	objPR.Tipo_Articulo();
            break;
          }

          case 6:{
          	objcaballeros.ropa_interior();
          	objPR.Tipo_Articulo();
            break;
          }

          case 7:{
          	objcaballeros.ropa_interior();
          	objPR.Tipo_Articulo();
			break;
		  }
		  case 8:{
		  	objcaballeros.calzado();
		  	objPR.Tipo_Articulo();
			break;
		  }

        }
        system("pause");
        system("cls");
      break;}

    case 2:{
      system("cls");
      cout<<"DEPARTAMENTO DE ROPA Y ACCESORIOS PARA MUJER \n";
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
           objPR.Tipo_Articulo();
          system("pause");
          break;
        }

        case 2:{
          objdamas.playeras();
          objPR.Tipo_Articulo();
          break;
        }

        case 3:{
          objdamas.chamarras();
          objPR.Tipo_Articulo();
          break;
        }

        case 4:{
          objdamas.sudaderas();
          objPR.Tipo_Articulo();
          break;
        }

        case 5:{
          objdamas.calcetines();
          objPR.Tipo_Articulo();
          break;
        }

        case 6:{
          objdamas.ropa_interior();
          objPR.Tipo_Articulo();
          break;
        }

        case 7:{
          objdamas.calzado();
          objPR.Tipo_Articulo();
          break;
         }

      }
      system("pause");
      system("cls");
      break;}

    case 3:{
      char car = 165;
      int opcbebe;

      system("cls");
      cout<<"DEPARTAMENTO DE BEBES DE 0-24 MESES \n";
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
           objPR.Tipo_Articulo();
          system("pause");
          break;
        }

        case 2:{
          objinfantes.playeras();
          objPR.Tipo_Articulo();
          break;
        }

        case 3:{
          objinfantes.chamarras();
          objPR.Tipo_Articulo();
          break;
        }

        case 4:{
          objinfantes.sudaderas();
          objPR.Tipo_Articulo();
          break;
        }

        case 5:{
          objinfantes.calcetines();
          objPR.Tipo_Articulo();
          break;
        }

        case 6:{
          objinfantes.paniales();
          objPR.Tipo_Articulo();
          break;
        }
      }
      system("pause");
      system("cls");
      break;}

    case 4:{
      //char car = 165;
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
           objPR.Tipo_Articulo();
          system("pause");
          break;
        }

        case 2:{
          objninios.playeras();
          objPR.Tipo_Articulo();
          break;
        }

        case 3:{
          objninios.chamarras();
          objPR.Tipo_Articulo();
          break;
        }

        case 4:{
          objninios.sudaderas();
          objPR.Tipo_Articulo();
          break;
        }

        case 5:{
          objninios.calcetines();
          objPR.Tipo_Articulo();
          break;
        }

        case 6:{
          objninios.ropa_interior();
          objPR.Tipo_Articulo();
          break;
        }

        case 7:{
          objninios.calzado();
          objPR.Tipo_Articulo();
          break;}
      }
      system("pause");
      system("cls");
      break;}

    case 5:{
      int decHM;
        int opcadh, opcadm; //opcion de entrada para el departamento hombre y tambien para el departamento de mujeres
      cout<<"a que seccion quieres entrar: "<<endl;
      cout<<"1. hombres \n 2. mujeres "<<endl;
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
           objPR.Tipo_Articulo();
          system("pause");
          break;
        }

        case 2:{
          objadolescentesh.playeras();
          objPR.Tipo_Articulo();
          break;
        }

        case 3:{
          objadolescentesh.chamarras();
          objPR.Tipo_Articulo();
          break;
        }

        case 4:{
          objadolescentesh.sudaderas();
          objPR.Tipo_Articulo();
          break;
        }

        case 5:{
          objadolescentesh.calcetines();
          objPR.Tipo_Articulo();
          break;
        }

        case 6:{
          objadolescentesh.ropa_interior();
          objPR.Tipo_Articulo();
          break;
        }

        case 7:{
          objadolescentesh.ropa_interior();
          objPR.Tipo_Articulo();
    break;
    }
    case 8:{
      objadolescentesh.calzado();
      objPR.Tipo_Articulo();
    break;
    }
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
            objPR.Tipo_Articulo();
           system("pause");
           break;
         }

         case 2:{
           objadolescentesm.playeras();
           objPR.Tipo_Articulo();
           break;
         }

         case 3:{
           objadolescentesm.chamarras();
           objPR.Tipo_Articulo();
           break;
         }

         case 4:{
           objadolescentesm.sudaderas();
           objPR.Tipo_Articulo();
           break;
         }

         case 5:{
           objadolescentesm.calcetines();
           objPR.Tipo_Articulo();
           break;
         }

         case 6:{
           objadolescentesm.ropa_interior();
           objPR.Tipo_Articulo();
           break;
         }

         case 7:{
           objadolescentesm.ropa_interior();
           objPR.Tipo_Articulo();
     break;
     }
     case 8:{
       objadolescentesm.calzado();
       objPR.Tipo_Articulo();
     break;
     }
 }
       }
       system("pause");
       system("cls");
      break;}

    case 6:{
      int opcElec; //opcion de entrada para el departamento hombre
      cout<<"DEPARTAMENTO DE Electronica \n";
      cout<<"novedades: "<<endl;
      cout<<"1. TELEVASIONES";
      cout<<"2. COMPUTADORAS"<<endl;
      cout<<"3. CELULARES Y TABLES"<<endl;
      cout<<"4. BOCINAS Y ENTRETENIMIENTO"<<endl;
      cout<<"a que tipo de articulos desea entrar: "; cin>>opcElec;

      switch (opcElec) {
        case 1:{
           cout<<"cual es la marca del producto: ";
           cin>>nombre_marca;
           objTelevision.marca();
           objPR.Tipo_Articulo();
          system("pause");
          break;
        }

        case 2:{
          break;
        }

        case 3:{
        break;}
      }
    }
    case 7:{
      break;}

    case 8:{
    //  objtiendaMatriz.Tipo_Articulo();
      break;}

  case 9:{

    break;}

  case 10:{
    int aplicarDes;
  	system("cls");
  	objPR.CantidadT();
    cout<<"o bien, quiere plicar un descuento a su compra? : \n";
    cout<<" SI -> 1 \n NO -> 0"<<endl;
    cout<<"desea aplicar descuento: ";
    cin>>aplicarDes;
    if(aplicarDes == 1){
    objPR.oferta();
    cout<<"el total a pagar sera de : "<<objPR.descuento()<<endl;
    system("pause");
  }else{
    cout<<"entonces su compra seria de: ";
    objPR.CantidadT();
    system("pause");
  }
	break;}

  case 11:{
  	  system("cls");
      cout<<"\t \t \t LISTA DE COMPRAS \n";
      objPR.listaCompra();
      system("pause");
  break;}

  }
}while(opcionP != 0);
}
