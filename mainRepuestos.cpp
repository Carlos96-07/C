#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>  
#include <ctype.h>
#include <iostream>
#include <time.h> 
#include <algorithm>
#include <vector>
using namespace std;
///////////////////////////////////Librerias//////////////////////////////////////////////////////////////////////////////////////////////////

int opcion = 0;
int opcionA = 0;
int opcionB = 0;
char cliente;
string Cedula_cliente = "";
string Cedula_AD = "";
int contadorAdministrador = 0;
int contadorCliente = 0;
////////////////////////////////////////Variable Locales//////////////////////////////////////////////////////////////////////////////////////

#define User "c1000"
#define Pass "123ps"
///////////////////////////////////////Definiciones para login////////////////////////////////////////////////////////////////////////////// 
 
void gotoxy(int x,int y);//Metodo Go to X Y, Mueve el cursor de la ventana de texto a la posición según las coordenadas especificadas por los argumentos x e y
void Menu(); ////////Metodo Menu Principal//////////
int login(); ///////Metodo Login///////////////////////////
void Productos();////////Metodo Productos//////////////////
	
void SubMenu();
void IngresarClientes();
void MostrarCliente();
void MostrarCliente_id();
void ClienteModificar();
int Elemento_C(string moff);
void Eliminar();
int Buscar(string x);

void SubMenuAD();
void Administrador_Datos();
void MostrarDatosAD();
void Buscar_AD_ID();
void M_Administrador();
int CambioAD(string admi);
int Search(string p);


//////////////////////////////////Estructuras Globales/////////////////////////////////////////

	struct Dcliente{
		string Cedula;
		string Nombre;
		string Apellidos;
		string dia;
		string mes;
		string anno;
		int edad;
		string EstadoSalud;
		string Estado;	
	};
	
	Dcliente *persona = new Dcliente[15];
	
	struct Administrador{
		string Codigo_AD;
		string cedula_AD;
		string Nombre_AD;
		string Apellidos_AD;
		string NumeroTel;
		string email;
	};
	Administrador *jefe = new Administrador[5];


/////////////////////////////Main Principal///////////////////////////////////////////

int main() {
	Menu();	
	return 0;
}

 int login(){
	string usuario;
	string password;
	int contador_n = 0;
	bool ingresa = false;
	
	do {
		system("cls");
		cout << "\t\t\tLOGIN DE USUARIO" << endl;
		cout << " \t\t\t---------------" << endl;
		cout << "\n\tUsuario: ";
		getline(cin,usuario);
		cout << "\tPassword: ";
		getline(cin,password);
		
		if(usuario == User && password == Pass ){
			ingresa = true;
		}else{
			cout << "\n\tEl usuario y/o contraseña son incorrectos" << endl;
			cin.get();
			contador_n++;
		}
		
	}while(ingresa == false && contador_n < 3);
	
	if(ingresa == false){
		cout << "\n\tNo se ha podido ingresar. Regrese mas tarde o intentelo de nuevo!" << endl;
		
	}else{
		cout << "\n\tHola Bienvenido/a al sistema!" << endl;
	}
	
	return 0;
}

////////////////////////////////////Finaliza metodo de login//////////////////////////////////////////////

void Menu(){
	do{
	gotoxy(15,3);cout << "*************1.Ingresar Credenciales**********" << endl;
	gotoxy(15,4);cout << "*************2.Mantenimiento de Clientes******" << endl;
	gotoxy(15,5);cout << "*************3.Datos Administrador************" << endl;
   gotoxy(15,6);cout << "*************4.Productos**********************" << endl;
	gotoxy(15,7);cout << "**************5.Salir****************************" << endl;
	cin >> opcion;
	switch(opcion){
		case 1:login();
			getch();
		 break;
		case 2: SubMenu();
	   	getch();
		break;
		case 3: SubMenuAD();
		   getch();
		break;  
		case 4: Productos();
			getch();
		break; 
	}
  }while(opcion != 5);
}

////////////////////////////Finaliza Metodo Menu//////////////////////////////////////////

 void SubMenu(){
do{
	system("cls");
opcion=0;
 cout<< "Menu Clientes" << endl;
 cout<< "1.Ingresar Clientes" << endl;
 cout<< "2.MostrarCliente" << endl;
 cout<< "3.MostrarClientes" << endl;
 cout<< "4.Modificar"  << endl;
 cout<< "5.Eliminar" << endl;
 cin>> opcionA;
	switch(opcionA){
		case 1:IngresarClientes();
		 cout<< "Ingresar Cliente" << endl;
			getch();
			break;
		case 2:MostrarCliente();
			getch();
			break;
		case 3:MostrarCliente_id();
			getch();
			break;
		case 4:ClienteModificar();
		  getch();
	     break;	
		case 5:Eliminar();
			getch();
			break;
		default:{
   		cout<< "default" << endl;
   		getch();
			break;
		}		
   	}
   	}while(opcionA != 6);
}

 void IngresarClientes()
 {
 system ("cls");
	char respuesta;
	for(int i=contadorCliente;i<=15;i++){
	gotoxy(2,2);cout<<"Cliente # "<<i<<endl;
	gotoxy(2,3);cout<<"Ingrese la cedula del cliente"<<endl;
	cin>>persona[i].Cedula;
	gotoxy(2,6);cout<<"Ingrese nombre del cliente"<<endl;
	cin>>persona[i].Nombre;
	gotoxy(2,9);cout<<"Ingrese el  Apellido del cliente"<<endl;
	cin>>persona[i].Apellidos;
	gotoxy(2,12);cout<<"Ingrese la edad del cliente"<<endl;
	cin>>persona[i].edad;
	gotoxy(2,15);cout<<"Ingrese la fecha de nacimiento dia del cliente"<<endl;
	cin>> persona[i].dia;
	gotoxy(2,18);cout<<"Ingrese la fecha de nacimiento mes del cliente"<<endl;
	cin>>persona[i].mes;
	gotoxy(2,21);cout<<"Ingrese la fecha de nacimiento anno del cliente"<<endl;
	cin>>persona[i].anno;
	gotoxy(2,25);cout<<"Ingrese el estado de salud"<<endl;
	cin>> persona[i].EstadoSalud;
	gotoxy(2,28);cout<<"Ingrese el estado de cliente"<<endl;
	cin>> persona[i].Estado;
	contadorCliente++;
	system("cls");
	gotoxy(15,3);cout<<"Desea Agregar otro cliente?"<<endl;
	cin>>respuesta;
		if(respuesta=='N'){
		i=15;
		}
	}
	system("cls");
	gotoxy(15,4);cout<<"Registrado con exito"<<endl;
}

void MostrarCliente(){
		system("cls"); 
	gotoxy(2,1);cout<<"---------------------------------------------------------------------------------------";
	gotoxy(3,2);cout<<"Cedula";
	gotoxy(13,2);cout<<"Nombre";
	gotoxy(21,2);cout<<"Apellidos";
	gotoxy(34,2);cout<<"DD-MM-AAAA";
	gotoxy(46,2);cout<<"Edad";
	gotoxy(62,2);cout<<"Estado Salud";
	gotoxy(75,2);cout<<"Estado";
	gotoxy(2,3);cout<<"---------------------------------------------------------------------------------------";	
	      
	int posiciony=0;
	for(int i=0;i<=contadorCliente;i++){
	    posiciony=4+i;
		gotoxy(3,posiciony);cout<<persona[i].Cedula;			
		gotoxy(13,posiciony);cout<<persona[i].Nombre;
		gotoxy(21,posiciony);cout<<persona[i].Apellidos;
		gotoxy(34,posiciony);cout<<persona[i].dia;
		gotoxy(36,posiciony);cout<<persona[i].mes;
		gotoxy(38,posiciony);cout<<persona[i].anno;
		gotoxy(47,posiciony);cout<<persona[i].edad;
		gotoxy(54,posiciony);cout<<persona[i].EstadoSalud;
		gotoxy(60,posiciony);cout<<persona[i].Estado;
     }
}


void MostrarCliente_id(){
		system("cls");
	string cedulaBuscar="";
	int posicionBuscada=0;
	cout<<"Favor ingrese el # de Cedula a buscar"<<endl;
	cin>>cedulaBuscar;
	system("cls");
	for(int i=0;i<=15;i++){
		if(persona[i].Cedula==cedulaBuscar){
		posicionBuscada=i;	
		}
		
		
	gotoxy(2,1);cout<<"--------------------------------------------------------------------------------------------------";
	gotoxy(3,2);cout<<"Cedula";
	gotoxy(13,2);cout<<"Nombre";
	gotoxy(21,2);cout<<"Apellido";
	gotoxy(34,2);cout<<"Dia";
	gotoxy(46,2);cout<<"Mes";
	gotoxy(62,2);cout<<"anno";
	gotoxy(75,2);cout<<"Edad";
	gotoxy(86,2);cout<<"Estado Salud";
	gotoxy(95,2);cout<<"Estado";
	gotoxy(2,3);cout<<"--------------------------------------------------------------------------------------------------";	
	      
		
	gotoxy(3,4);cout<<persona[posicionBuscada].Cedula;			
	gotoxy(13,4);cout<<persona[posicionBuscada].Nombre;
	gotoxy(21,4);cout<<persona[posicionBuscada].Apellidos;
	gotoxy(34,4);cout<<persona[posicionBuscada].dia;
	gotoxy(46,4);cout<<persona[posicionBuscada].mes;
	gotoxy(58,4);cout<<persona[posicionBuscada].anno;
	gotoxy(75,4);cout<<persona[posicionBuscada].edad;
	gotoxy(78,4);cout<<persona[posicionBuscada].EstadoSalud;
	gotoxy(81,4);cout<<persona[posicionBuscada].Estado;
	gotoxy(2,5);cout<<"------------------------------------------------------------------------------------------------";	
		
	}
	
}

 void ClienteModificar(){
	system("cls");
	int t = 0;
	cout << "Realice los cambios a modificar por favor!!!" << endl;
	cin >> Cedula_cliente ;
	int q =  Elemento_C(Cedula_cliente);
	if(q > -1){
		cout << "Ingrese los nuevos datos por favor!:" << endl;
		cout << "Ingrese el cambio de cedula correcto" << endl;
		cin >> persona[q].Cedula;
		cout << "Ingrese el cambio de nombre correcto " << endl;
		cin >> persona[q].Nombre;
		cout << "Ingrese el cambio de apellido correcto " << endl;
		cin >> persona[q].Apellidos;
		cout << "ingrese el cambio de edad correcto" << endl;
		cin >> persona[q].edad;
		cout << "ingrese el cambio de Fecha dia correcto" << endl;
		cin >> persona[q].dia;
		cout << "ingrese el cambio de Fecha mes correcto" << endl;
		cin >> persona[q].mes;
		cout << "ingrese el cambio de Fecha anno correcto" << endl;
		cin >> persona[q].anno;
		cout << "ingrese el cambio de E.Salud correcto" << endl;
		cin >> persona[q].EstadoSalud;
		cout << "ingrese el cambio de Estado correcto" << endl;
		cin >> persona[q].Estado;
	}
	else{
		cout << "Desea modificar otro elemento?" << endl;
		cout << "Desea ingresar una nueva cedula ?" << endl;
		cout << "1. Si" << endl;
		cout << "2. NO" << endl;
		cin >> t ;
		if(t==1){
			ClienteModificar();
		}
	else{
		SubMenu();
	}
}
}

int Elemento_C(string moff){
		for(int i= 0; i <= 15 ; i++){	
		if(persona[i].Cedula == moff){
			return i;
		}
	}
	return -1;
}

  
void Eliminar(){
	int continuar=0;
	cout << "Escriba el numero de cedula que desea eliminar por favor" << endl;
	cin >> Cedula_cliente ;
	int x = Buscar(Cedula_cliente);
	if(x>-1){
		persona[x].Cedula == "" ;
		persona[x].Nombre == "" ;
		persona[x].Apellidos == "" ;
		persona[x].edad == 0;
		persona[x].dia == "";
		persona[x].mes == "";
		persona[x].anno == "";
		persona[x].EstadoSalud == "";
		persona[x].Estado == "";
	}
	else{
		cout << "Persona no esta en la lista" << endl;
		cout << "Desea ingresar una nueva cedula ?" << endl;
		cout << "1. Si" << endl;
		cout << "2. NO" << endl;
		cin >> continuar ;
		if(continuar==1){
			Eliminar();
		}
		else{
			SubMenu();
		}
		}
	}

int Buscar(string x){
	for(int i= 0; i <= 15 ; i++){	
		if(persona[i].Cedula==x){
			return i;
		}
	}
	return -1;	
}

///////////////////////////////Finaliza proceso de clientes////////////////////////////////////////////////////////////////

 void SubMenuAD(){
	do{
		system("cls");
	gotoxy(15,3);cout << "************ Menu de opciones para el Administrador ***************" << endl;
	gotoxy(15,6);cout << "************ 1.Datos del Administrador ************************" << endl;
	gotoxy(15,9);cout << "************ 2.Mostrar Datos de Administrador *****************" << endl;
	gotoxy(15,12);cout << "*********** 3.Buscar ID administrador ************************" << endl;
	gotoxy(15,15);cout << "*********** 4.Modificar Administrador *************************" << endl;
	gotoxy(15,18);cout << "*********** 5.Eliminar Datos de Administrador *********************" << endl;
		cin >> opcionB;
		switch(opcionB){
			case 1:Administrador_Datos();
						getch();
			 break;
			case 2:MostrarDatosAD();
					   getch();
			 break;
			case 3:Buscar_AD_ID();
			 break;
			case 4:M_Administrador();
			 break;
			case 5:
			 break;
		}
	}while(opcionB != 6);
}

void Administrador_Datos(){
	system("cls");
	char respuesta2;
	for(int i=contadorAdministrador;i<=5;i++){
	gotoxy(2,2);cout<<"Cliente # "<<i<<endl;
	gotoxy(2,4);cout<<"Ingrese el codigo de registro por favor"<<endl;
	cin>>jefe[i].Codigo_AD;
	gotoxy(2,7);cout<<"Ingrese el numero de cedula"<<endl;
	cin>>jefe[i].cedula_AD;
	gotoxy(2,10);cout<<"Ingrese el nombre del cliente"<<endl;
	cin>>jefe[i].Nombre_AD;
	gotoxy(2,13);cout<<"Ingrese el segundo Apellido del cliente"<<endl;
	cin>>jefe[i].Apellidos_AD;
	gotoxy(2,16);cout<<"Ingrese el numero telefonico "<<endl;
	cin>>jefe[i].NumeroTel;
	gotoxy(2,19);cout<<"Ingrese el email "<<endl;
	cin>>jefe[i].email;
	contadorAdministrador++;
	system("cls");
	gotoxy(15,3);cout<<"Desea Agregar otro Administrador ?"<<endl;
	cin>> respuesta2;
	if(respuesta2 == 'N'){
		i=5;
	}
   }
   system("cls");
	gotoxy(15,4);cout<<"Registrado con exito"<<endl;
}

void MostrarDatosAD(){
		system("cls"); 
	gotoxy(2,1);cout<<"--------------------------------------------------------------------------------------------------";
	gotoxy(3,2);cout<<"Codigo";
	gotoxy(13,2);cout<<"Cedula";
	gotoxy(21,2);cout<<"Nombre";
	gotoxy(34,2);cout<<"Apellidos";
	gotoxy(46,2);cout<<"Telefono";
	gotoxy(62,2);cout<<"Email";
	gotoxy(2,3);cout<<"--------------------------------------------------------------------------------------------------";	
	      
	int posiciony=0;
	for(int i=0;i<=contadorAdministrador;i++){
	    posiciony=4+i;
		gotoxy(3,posiciony);cout<<jefe[i].Codigo_AD;			
		gotoxy(13,posiciony);cout<<jefe[i].cedula_AD;
		gotoxy(21,posiciony);cout<<jefe[i].Nombre_AD;
		gotoxy(34,posiciony);cout<<jefe[i].Apellidos_AD;
		gotoxy(46,posiciony);cout<<jefe[i].NumeroTel;
		gotoxy(58,posiciony);cout<<jefe[i].email;
     }
}


void Buscar_AD_ID(){
		system("cls");
	string cedulaBuscar="";
	int posicionBuscada=0;
	cout<<"Favor ingrese el # de Cedula a buscar"<<endl;
	cin>>cedulaBuscar;
	system("cls");
	for(int i=0;i<=9;i++){
		if(jefe[i].cedula_AD==cedulaBuscar){
		posicionBuscada=i;	
		}
		
	gotoxy(2,1);cout<<"-------------------------------------------------------------------------------------------------------";
	gotoxy(3,2);cout<<"Codigo";
	gotoxy(13,2);cout<<"Cedula";
	gotoxy(21,2);cout<<"Nombre";
	gotoxy(34,2);cout<<"Apellido";
	gotoxy(46,2);cout<<"Telefono";
	gotoxy(62,2);cout<<"Email";
	gotoxy(2,3);cout<<"-------------------------------------------------------------------------------------------------------";	
	      
		
		gotoxy(3,4);cout<<jefe[posicionBuscada].Codigo_AD;			
		gotoxy(13,4);cout<<jefe[posicionBuscada].cedula_AD;
		gotoxy(21,4);cout<<jefe[posicionBuscada].Nombre_AD;
		gotoxy(34,4);cout<<jefe[posicionBuscada].Apellidos_AD;
		gotoxy(46,4);cout<<jefe[posicionBuscada].NumeroTel;
		gotoxy(58,4);cout<<jefe[posicionBuscada].email;
		gotoxy(2,5);cout<<"--------------------------------------------------------------------------------------------------------";	
		
	}
}

void M_Administrador(){
	system("cls");
	int t = 0;
	cout << "Realice los cambios a modificar por favor!!!" << endl;
	cin >> Cedula_AD ;
	int q =  CambioAD(Cedula_AD);
	if(q > -1){
		cout << "Ingrese los nuevos datos por favor!:" << endl;
		cout << "Ingrese el cambio de cedula correcto" << endl;
		cin >> jefe[q].Codigo_AD;
		cout << "Ingrese el cambio de nombre correcto " << endl;
		cin >> jefe[q].cedula_AD;
		cout << "Ingrese el cambio de apellido correcto " << endl;
		cin >> jefe[q].Nombre_AD;
		cout << "ingrese el cambio de edad correcto" << endl;
		cin >> jefe[q].Apellidos_AD;
		cout << "ingrese el cambio de Fecha correcto" << endl;
		cin >> jefe[q].NumeroTel;
		cout << "ingrese el cambio de E.Salud correcto" << endl;
		cin >> jefe[q].email;
	}
	else{
		cout << "Desea modificar otro elemento?" << endl;
		cout << "Desea ingresar una nueva cedula ?" << endl;
		cout << "1. Si" << endl;
		cout << "2. NO" << endl;
		cin >> t ;
		if(t==1){
			M_Administrador();
		}
	else{
		SubMenuAD();
	}
 }
} 

int CambioAD(string admi){
		for(int i= 0; i <= 5 ; i++){	
		if(persona[i].Cedula == admi){
			return i;
		}
	}
	return -1;
}


void AD_Eliminado(){
		int continuar=0;
	cout << "Escriba el numero de cedula que desea eliminar por favor" << endl;
	cin >> Cedula_AD ;
	int x = Buscar(Cedula_AD);
	if(x>-1){
		jefe[x].Codigo_AD == "" ;
		jefe[x].cedula_AD == "" ;
		jefe[x].Nombre_AD == "" ;
		jefe[x].Apellidos_AD == "";
		jefe[x].NumeroTel == "";
		jefe[x].email == "";
	}
	else{
		cout << "Persona no esta en la lista" << endl;
		cout << "Desea ingresar una nueva cedula ?" << endl;
		cout << "1. Si" << endl;
		cout << "2. NO" << endl;
		cin >> continuar ;
		if(continuar==1){
			AD_Eliminado();
		}
		else{
			SubMenuAD();
		}
		}
}
int Search(string p){
	for(int i= 0; i <= 5 ; i++){	
		if(persona[i].Cedula== p){
			return i;
		}
	}
	return -1;	
}

/////////////////////////////////Finaliza Proceso Administrador////////////////////////////////////////////////////

void gotoxy(int x, int y) 
{
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

//////////////////////////Proceso de Productos///////////////////////////////////////////////////////

 void Productos(){
	system("cls");
	
	int Producto[10]= {80,22,18,250,19,20,925,50,160,800};
	
	cout << "\t\t\tProductos Disponible\n ";
	
	string x_producto;
	int ventas ,t_cliente ,productos ,i , arr, suma;
	float precio_pro;
//	char cliente, x_producto;
	
	cout << "Desea agregar otro usuario de compra: ?" << endl;
	cin >> cliente;
	while(cliente == 'S')
	{
		t_cliente = 0;
		cout << "Desea agregar un producto: ?" << endl;
		cin >> x_producto;
		while(x_producto == "S")
		{
			cout << "1.-Frenos:$80.00" << endl;
			cout << "2.-volantes:$22.00" << endl;
			cout << "3.-bielas:$18.00" << endl;
			cout << "4.-asientos:$250.00" << endl;
		   cout << "5.-mangueras:$19.00" << endl;
			cout << "6.-Filtros:$20.00" << endl;
			cout << "7.-turbo:$925.00" << endl;
			cout << "8.-Led:$50.00" << endl;
			cout << "9.-Suspension:$160.00" << endl;
			cout << "10.-Cambios:$800.00" << endl;
			cout << "Elige su opcion de compra! Gracias" << endl;
			cin >> productos;
			{
				 arr = Producto[productos-1];
		}
		   t_cliente = t_cliente+arr;
		   cout << "Desea Agregar otro usuario de compra? " << endl;
		   cin >> x_producto;
	} 
         cout << "Total: " << t_cliente << endl;
         ventas = t_cliente + ventas;
         cout << "Desea agregar otro cliente? " << endl;
         cin >> cliente;
   }
         cout << "Corte: " << ventas << endl;
         
}

