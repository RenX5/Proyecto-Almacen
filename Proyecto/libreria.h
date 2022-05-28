#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <time.h>

void gotoxy(int x, int y){
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dWPos;
	dWPos.X = x;
	dWPos.Y = y;
	SetConsoleCursorPosition(hcon,dWPos);
}

typedef struct {
	char modelo[20];
	int existencia;
	float precio;
	char ubicacion[20]; 
}almacen;

almacen info[] = { {"EST123", 1000, 4599, "Estante A"},
				   {"EST456", 980, 7000, "Estante B"},
				   {"EST789", 3000, 5699, "Estante C"},
				   {"EST100", 2501, 2300, "Estante D"},
				   {"EST110", 3104, 4500, "Estante E"}, 
				   
				   {"HOR123", 1000, 5000, "Estante A"},
				   {"HOR456", 2000, 4000, "Estante B"},
				   {"HOR789", 3000, 3000, "Estante C"},
				   {"HOR100", 4000, 2000, "Estante D"},
				   {"HOR110", 5000, 1000, "Estante E"} };
				   
typedef struct{
	char idModelo[20];
	int existencias;
	float precio;
	char ubicacion[20];
}Modelo;

typedef struct{
	int idPedido;
	char estado[20];
	char cliente[20];
}Pedido;

typedef struct{
	int idCliente;
	char nombre[40];
	int telefono;
	char correo[40];
	
	//Docente docente;
	//Alumno alumno;
}Cliente;

typedef struct{
	int idDetalle;
	int cantidad;
	float subtotal;
}Detalle;

typedef struct
{
	Cliente cliente;
	Detalle detalle;
	Modelo modelo;
	Pedido pedido;	
}Todo;

enum MENU {OPC1=1, OPC2, OPC3, OPC4, OPC5, OPC6, OPC7};

FILE *archi = NULL;
Todo *regis = (Todo *)malloc(sizeof(Todo));

/*typedef struct{
	int matricula;
	char nombre[20];
	char carrera[20];
	float calif[3];
}Informacion;

Informacion info[] = { {111, "Juan Manuel", "ITI", 9,8,9},
				   {113, "Ana María", "ITEM", 6,7,8},
				   {115, "Marco Antonio", "ITI", 6,9,8} };
					
typedef struct{
	int idDocente;
	char nomCompleto[20];
	char correo[30];
	char NSS[20];
	char fechaIngreso[20];
}Docente;

typedef struct{
	int idAlumno;
	char direccion[20];
	char tel[20];
	char correo[30];
	Informacion inf;
}Alumno;

typedef struct{
	int idGrupo;
	char semestre[10];
	Docente docente;
	Alumno alumno;
}Grupo;

enum MENU {OPC1=1, OPC2, OPC3, OPC4, OPC5, OPC6, OPC7};

FILE *arch = NULL;
Grupo *regis = (Grupo *)malloc(sizeof(Grupo));	*/				

#include "validaciones.h"
#include "decorar.h"
#include "estructura.h"
#include "estrucApuntador.h"
#include "pedidos.h"
#include "regisEntrega.h"
#include "modiCancelado.h"
#include "menu.h"

