void menuProyecto();
void menu1();
void menu2();
void menu3();
void menu4();
void menu5();
void menu6();
void menu7();
void menu(int, int, int &);
void menu_1(int x, int y, int &opc);
void menu_2(int x, int y, int &opc);
void menu_3(int x, int y, int &opc);
void menu_4(int x, int y, int &opc);
void menu_5(int x, int y, int &opc);
void menu_6(int x, int y, int &opc);
void menu_7(int x, int y, int &opc);


void menu(int x, int y, int &opc){
	char tecla='\0';
	opc = 1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	gotoxy(x,y);
	printf("%c",16);
	do{
		if(kbhit()) {
			tecla=getch();
			//printf("%d", tecla);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
			gotoxy(x,y);
			printf("%c",16);
			if(opc>1&&tecla==72){//Flecha arriba
				y--;
				opc--;
			}
			if(opc<7&&tecla==80){//Flecha abajo
				y++;
				opc++;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			gotoxy(x,y);
			printf("%c",16);
		}
	}while(tecla!=13);
}

void menuProyecto(){
	setlocale(LC_CTYPE, "Spanish");
	int opc =0;
	int x = 0;
	int y = 0;
	int resp=0, salir=0;
	
	while(opc!=7){
		system("color 0A");
		x = 25;
		y = 5;
		
		system("cls");
		
		gotoxy(x,y);
		printf("1. Consulta de almacén\n");
		gotoxy(x,++y);
		printf("2. Actualizar almacén\n");
		gotoxy(x,++y);
		printf("3. Registrar Pedido\n");
		gotoxy(x,++y);
		printf("4. Consultar Pedido\n");
		gotoxy(x,++y);
		printf("5. Registrar Entrega\n");
		gotoxy(x,++y);
		printf("6. Modificar estado de pedido\n");
		gotoxy(x,++y);
		printf("7. Salir del sistema\n");
		gotoxy(x,++y);
		menu(22,5,opc);
		system("cls");
		gotoxy(10,4);
		switch(opc){
			case OPC1:
				//printf("Opción 1\n");
				menu1();
				getch();
				break;
			case OPC2:
				//printf("Opción 2\n");
				menu2();
				getch();
				break;
			case OPC3:
				//printf("Opción 3\n");
				agregarDinamico();
				getch();
				break;
			case OPC4:
				//printf("Opción 4\n");
				menu4();
				getch();
				break;
			case OPC5:
				//printf("Opción 5\n");
				leer();
				resp=validaEntero("1 para continuar / 2 para salir: ");
				if(resp==1){
					do{
						entregado();
						salir=validaEntero("Desea salir 1->Si 2->No: ");
						if(salir==2){
							system("cls");
							leer();
						}
					}while(salir==2);
				}
				getch();
				break;
			case OPC6:
				//printf("Opción 6\n");
				//leer_dos();
				//cancelado();
				/*resp=validaEntero("1 para continuar / 2 para salir: ");
				if(resp==1){
					juntos();
				}*/
				//juntos();
				menu7();
				getch();
				break;
			case OPC7:
				system("color 50");
				printf("Adiós:(");
				exit(0);
		}
	}
	
	getch();
}
void menu_1(int x, int y, int &opc){
	char tecla='\0';
	opc = 1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	gotoxy(x,y);
	printf("%c",16);
	do{
		if(kbhit()) {
			tecla=getch();
			//printf("%d", tecla);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
			gotoxy(x,y);
			printf("%c",16);
			if(opc>1&&tecla==72){//Flecha arriba
				y--;
				opc--;
			}
			if(opc<4&&tecla==80){//Flecha abajo
				y++;
				opc++;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			gotoxy(x,y);
			printf("%c",16);
		}
	}while(tecla!=13);
}
void menu1(){
	setlocale(LC_CTYPE, "Spanish");
	int opc = 0;
	int x = 0;
	int y = 0;
	while(opc!=4){
		system("color 03");
		x = 25;
		y = 5;	
		system("cls");
		gotoxy(x,y);
		printf("Consulta general\n");
		gotoxy(x,++y);
		printf("a) Estufas\n");
		gotoxy(x,++y);
		printf("b) Hornos de microondas\n");
		gotoxy(x,++y);
		printf("Regresar\n");
		gotoxy(x,++y);
		menu(22,5,opc);
		system("cls");
		gotoxy(10,4);
		switch(opc){
			case OPC1:
				printf("Consulta General\n");
				ImprimirEstructura();
				leer_archivo();
				getch();
				break;
			case OPC2:
				printf("Modelos de Estufas\n");
				leer_estufa();
				getch();
				break;
			case OPC3:
				printf("Modelos de Microondas\n");
				leer_hornos();
				getch();
				break;
			case OPC4:
				menuProyecto();
				getch();
				break;
		}
	}
	
	
}
void menu_2(int x, int y, int &opc){
	char tecla='\0';
	opc = 1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	gotoxy(x,y);
	printf("%c",16);
	do{
		if(kbhit()) {
			tecla=getch();
			//printf("%d", tecla);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
			gotoxy(x,y);
			printf("%c",16);
			if(opc>1&&tecla==72){//Flecha arriba
				y--;
				opc--;
			}
			if(opc<4&&tecla==80){//Flecha abajo
				y++;
				opc++;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			gotoxy(x,y);
			printf("%c",16);
		}
	}while(tecla!=13);
}
void menu2(){
	setlocale(LC_CTYPE, "Spanish");
	int opc = 0;
	int x = 0;
	int y = 0;
	while(opc!=4){
		system("color 03");
		x = 25;
		y = 5;	
		system("cls");
		gotoxy(x,y);
		printf("a) Estufas\n");
		gotoxy(x,++y);
		printf("b) Hornos de microondas\n");
		gotoxy(x,++y);
		printf("c)Agregar registros\n");
		gotoxy(x,++y);
		printf("Regresar\n");
		gotoxy(x,++y);
		menu(22,5,opc);
		system("cls");
		gotoxy(10,4);
		switch(opc){
			case OPC1:
				printf("Modelos de estufa: \n");
				//leer_estufa();
				menu5();
				//leer_estufa();
				getch();
				break;
			case OPC2:
				printf("Modelos de microondas: \n");
				//leer_hornos();
				menu6();
				//leer_hornos();
				getch();
				break;
			case OPC3:
				printf("Agregar registro: \n");
				leer_archivo();
				agregar();
				//leer_archivo();
				getch();	
				break;
			case OPC4:
				menuProyecto();
				getch();
				break;
		}
	}	
}

void menu_4(int x, int y, int &opc){
	char tecla='\0';
	opc = 1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	gotoxy(x,y);
	printf("%c",16);
	do{
		if(kbhit()) {
			tecla=getch();
			//printf("%d", tecla);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
			gotoxy(x,y);
			printf("%c",16);
			if(opc>1&&tecla==72){//Flecha arriba
				y--;
				opc--;
			}
			if(opc<5&&tecla==80){//Flecha abajo
				y++;
				opc++;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			gotoxy(x,y);
			printf("%c",16);
		}
	}while(tecla!=13);
}

void menu4(){
	setlocale(LC_CTYPE, "Spanish");
	int opc = 0;
	int x = 0;
	int y = 0;
	int salir=0;
	while(opc!=5){
		system("color 03");
		x = 25;
		y = 5;	
		system("cls");
		gotoxy(x,y);
		printf("1.- Pedidos Activos\n");
		gotoxy(x,++y);
		printf("2.- Pedidos Entregados\n");
		gotoxy(x,++y);
		printf("3.- Pedidos Cancelados\n");
		gotoxy(x,++y);
		printf("4.- Numero de pedidos\n");
		gotoxy(x,++y);
		printf("Regresar\n");
		gotoxy(x,++y);
		menu(22,5,opc);
		system("cls");
		gotoxy(10,4);
		switch(opc){
			case OPC1:
				printf("Pedidos Activos\n");
				leer_activos();
				getch();
				break;
			case OPC2:
				printf("Pedidos Entregados\n");
				leer_entregas();
				getch();
				break;
			case OPC3:
				printf("Pedidos Cancelados\n");
				leer_cancelados();
				getch();
				break;
			case OPC4:
				printf("Numero de pedidos\n");
				do{
					leer_todos();
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
					salir=validaEntero("Desea salir 1->Si 2->No: ");
					if(salir==2){
						system("cls");
					}
				}while(salir==2);
				
				
				//leer_todos();
				getch();
				break;
			case OPC5:
				menuProyecto();
				getch();
				break;
		}
	}	
}

void menu_5(int x, int y, int &opc){
	char tecla='\0';
	opc = 1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	gotoxy(x,y);
	printf("%c",16);
	do{
		if(kbhit()) {
			tecla=getch();
			//printf("%d", tecla);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
			gotoxy(x,y);
			printf("%c",16);
			if(opc>1&&tecla==72){//Flecha arriba
				y--;
				opc--;
			}
			if(opc<5&&tecla==80){//Flecha abajo
				y++;
				opc++;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			gotoxy(x,y);
			printf("%c",16);
		}
	}while(tecla!=13);
}


void menu5(){
	setlocale(LC_CTYPE, "Spanish");
	int opc = 0;
	int x = 0;
	int y = 0;
	int salir=0, resp=0;
	while(opc!=5){
		system("color 03");
		x = 25;
		y = 5;	
		system("cls");
		gotoxy(x,y);
		printf("1.- Modificar existencia\n");
		gotoxy(x,++y);
		printf("2.- Modificar precio\n");
		gotoxy(x,++y);
		printf("3.- Modificar ubicación\n");
		gotoxy(x,++y);
		printf("Regresar\n");
		gotoxy(x,++y);
		menu(22,5,opc);
		system("cls");
		gotoxy(10,4);
		switch(opc){
			case OPC1:
				//printf("Pedidos Activos\n");
				//leer_activos();
				leer_estufa();
				resp = validaEntero("1 Para continuar/ 2 para salir: ");
				if(resp==1){
					do{
						modifica();
						salir=validaEntero("Desea salir 1->Si 2->No: ");
					}while(salir==2);
				}
				getch();
				break;
			case OPC2:
				//printf("Pedidos Entregados\n");
				//leer_entregas();
				leer_estufa();
				resp = validaEntero("1 Para continuar/ 2 para salir: ");
				if(resp==1){
					do{
						modifica_dos();
						salir=validaEntero("Desea salir 1->Si 2->No: ");
					}while(salir==2);
				}
				getch();
				break;
			case OPC3:
				//printf("Pedidos Cancelados\n");
				//leer_cancelados();
				leer_estufa();
				resp = validaEntero("1 Para continuar/ 2 para salir: ");
				if(resp==1){
					do{
						modifica_tres();
						salir=validaEntero("Desea salir 1->Si 2->No: ");
					}while(salir==2);
				}
				getch();
				break;
			case OPC4:
				menu2();
				getch();
				break;
		}
	}	
}

void menu_6(int x, int y, int &opc){
	char tecla='\0';
	opc = 1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	gotoxy(x,y);
	printf("%c",16);
	do{
		if(kbhit()) {
			tecla=getch();
			//printf("%d", tecla);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
			gotoxy(x,y);
			printf("%c",16);
			if(opc>1&&tecla==72){//Flecha arriba
				y--;
				opc--;
			}
			if(opc<5&&tecla==80){//Flecha abajo
				y++;
				opc++;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			gotoxy(x,y);
			printf("%c",16);
		}
	}while(tecla!=13);
}


void menu6(){
	setlocale(LC_CTYPE, "Spanish");
	int opc = 0;
	int x = 0;
	int y = 0;
	int salir=0, resp=0;
	while(opc!=5){
		system("color 03");
		x = 25;
		y = 5;	
		system("cls");
		gotoxy(x,y);
		printf("1.- Modificar existencia\n");
		gotoxy(x,++y);
		printf("2.- Modificar precio\n");
		gotoxy(x,++y);
		printf("3.- Modificar ubicación\n");
		gotoxy(x,++y);
		printf("Regresar\n");
		gotoxy(x,++y);
		menu(22,5,opc);
		system("cls");
		gotoxy(10,4);
		switch(opc){
			case OPC1:
				//printf("Pedidos Activos\n");
				//leer_activos();
				leer_hornos();
				resp = validaEntero("1 Para continuar/ 2 para salir: ");
				if(resp==1){
					do{
						modifica();
						salir=validaEntero("Desea salir 1->Si 2->No: ");
					}while(salir==2);
				}
				getch();
				break;
			case OPC2:
				//printf("Pedidos Entregados\n");
				//leer_entregas();
				leer_hornos();
				resp = validaEntero("1 Para continuar/ 2 para salir: ");
				if(resp==1){
					do{
						modifica_dos();
						salir=validaEntero("Desea salir 1->Si 2->No: ");
					}while(salir==2);
				}
				getch();
				break;
			case OPC3:
				//printf("Pedidos Cancelados\n");
				//leer_cancelados();
				leer_hornos();
				resp = validaEntero("1 Para continuar/ 2 para salir: ");
				if(resp==1){
					do{
						modifica_tres();
						salir=validaEntero("Desea salir 1->Si 2->No: ");
					}while(salir==2);
				}
				getch();
				break;
			case OPC4:
				menu2();
				getch();
				break;
		}
	}	
}

void menu_7(int x, int y, int &opc){
	char tecla='\0';
	opc = 1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	gotoxy(x,y);
	printf("%c",16);
	do{
		if(kbhit()) {
			tecla=getch();
			//printf("%d", tecla);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
			gotoxy(x,y);
			printf("%c",16);
			if(opc>1&&tecla==72){//Flecha arriba
				y--;
				opc--;
			}
			if(opc<5&&tecla==80){//Flecha abajo
				y++;
				opc++;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			gotoxy(x,y);
			printf("%c",16);
		}
	}while(tecla!=13);
}


void menu7(){
	setlocale(LC_CTYPE, "Spanish");
	int opc = 0;
	int x = 0;
	int y = 0;
	int salir=0, resp=0;
	while(opc!=5){
		system("color 03");
		x = 25;
		y = 5;	
		system("cls");
		gotoxy(x,y);
		printf("1.- Cancelar\n");
		gotoxy(x,++y);
		printf("2.- Activar\n");
		gotoxy(x,++y);
		printf("Regresar\n");
		gotoxy(x,++y);
		menu(22,5,opc);
		system("cls");
		gotoxy(10,4);
		switch(opc){
			case OPC1:
				//printf("Pedidos Activos\n");
				//leer_activos();
				/*resp = validaEntero("1 Para continuar/ 2 para salir: ");
				if(resp==1){
					leer_dos();
					cancelado();
				}*/
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
				resp = validaEntero("1 Para continuar/ 2 para salir: ");
				if(resp==1){
					do{
						leer_dos();
						cancelado();
						salir=validaEntero("Desea salir 1->Si 2->No: ");
						if(salir==2){
							system("Cls");
						}
					}while(salir==2);
				}
				getch();
				break;
			case OPC2:
				//printf("Pedidos Entregados\n");
				//leer_entregas();
				/*leer_hornos();
				resp = validaEntero("1 Para continuar/ 2 para salir: ");
				if(resp==1){
					do{
						modifica_dos();
						salir=validaEntero("Desea salir 1->Si 2->No: ");
					}while(salir==2);
				}*/
				resp = validaEntero("1 Para continuar/ 2 para salir: ");
				if(resp==1){
					do{
						leer_tres();
						activadosDos();
						salir=validaEntero("Desea salir 1->Si 2->No: ");
						if(salir==2){
							system("cls");
						}
					}while(salir==2);
				}
				getch();
				break;
			case OPC3:
				menuProyecto();
				getch();
				break;
		}
	}	
}
