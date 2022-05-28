void leer_dos(){
	bool bandera=true;
	
	if(!(archi=fopen("encabezado.txt", "r"))){
		printf("Error al leer el archivo");
		exit(1);
		
	}
	while(!feof(archi)){
		fscanf(archi, "%d\t", &regis->pedido.idPedido);
		fscanf(archi, "%[^\t]\t", regis->pedido.estado);
		fscanf(archi, "%[^\t]\t", regis->cliente.nombre);
		fscanf(archi, "%[^\t]\t", regis->cliente.correo);
		fscanf(archi, "%d\n", &regis->cliente.telefono);
		if(strcmp(regis->pedido.estado, "Estado: Activo")==0){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
			printf("%d\t", regis->pedido.idPedido);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
			printf("%s\t", regis->pedido.estado);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			printf("%s\t", regis->cliente.nombre);
			printf("%s\t", regis->cliente.correo);
			printf("%d\n", regis->cliente.telefono);	
		}	
	}
	fclose(archi);
}

void cancelado(){
	setlocale(LC_CTYPE, "Spanish");
	FILE *archi4;
	bool bandera=false;
	int resp=0;
	int pedido=0;
	
	if(!(archi=fopen("encabezado.txt", "r"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	
	if(!(archi4=fopen("copiaEncabezado2.txt", "a+"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	
	pedido=validaEntero("Cual número de pedido quieres modificar: ");
	
	while(!feof(archi)){
		fscanf(archi, "%d\t", &regis->pedido.idPedido);
		fscanf(archi, "%[^\t]\t", regis->pedido.estado);
		fscanf(archi, "%[^\t]\t", regis->cliente.nombre);
		fscanf(archi, "%[^\t]\t", regis->cliente.correo);
		fscanf(archi, "%d\n", &regis->cliente.telefono);
		
		if(pedido==regis->pedido.idPedido){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
			printf("%d\t", regis->pedido.idPedido);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
			printf("%s\t", regis->pedido.estado);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			printf("%s\t", regis->cliente.nombre);
			printf("%s\t", regis->cliente.correo);
			printf("%d\n", regis->cliente.telefono);
			
			do{
				bandera=true;
				//regis->pedido.idPedido=validaEntero("Cual pedido quieres modificar: ");
				//resp=regis->pedido.idPedido
				if(regis->pedido.idPedido==regis->pedido.idPedido){
					strcpy(regis->pedido.estado,"Estado: Cancelado");
				}
			}while(!(bandera));
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		fprintf(archi4,"%d\t", regis->pedido.idPedido);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		fprintf(archi4,"%s\t", regis->pedido.estado);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		fprintf(archi4,"%s\t", regis->cliente.nombre);
		fprintf(archi4,"%s\t", regis->cliente.correo);
		fprintf(archi4,"%d\n", regis->cliente.telefono);
	}
	if(bandera==false)printf("No se encuentra el registro");
	else printf("\nDatos Actualizados\n");
	fclose(archi4);
	fclose(archi);
	remove("encabezado.txt");
	rename("copiaEncabezado2.txt", "encabezado.txt");
}

void leer_tres(){
	bool bandera=true;
	
	if(!(archi=fopen("encabezado.txt", "r"))){
		printf("Error al leer el archivo");
		exit(1);
		
	}
	while(!feof(archi)){
		fscanf(archi, "%d\t", &regis->pedido.idPedido);
		fscanf(archi, "%[^\t]\t", regis->pedido.estado);
		fscanf(archi, "%[^\t]\t", regis->cliente.nombre);
		fscanf(archi, "%[^\t]\t", regis->cliente.correo);
		fscanf(archi, "%d\n", &regis->cliente.telefono);
		if(strcmp(regis->pedido.estado, "Estado: Cancelado")==0){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
			printf("%d\t", regis->pedido.idPedido);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
			printf("%s\t", regis->pedido.estado);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			printf("%s\t", regis->cliente.nombre);
			printf("%s\t", regis->cliente.correo);
			printf("%d\n", regis->cliente.telefono);	
		}	
	}
	fclose(archi);
}

void activadosDos(){
	setlocale(LC_CTYPE, "Spanish");
	FILE *archi5;
	bool bandera=false;
	int resp=0;
	int pedido=0;
	
	if(!(archi=fopen("encabezado.txt", "r"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	
	if(!(archi5=fopen("copiaEncabezado3.txt", "a+"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	
	pedido=validaEntero("Cual número de pedido quieres modificar: ");
	
	while(!feof(archi)){
		fscanf(archi, "%d\t", &regis->pedido.idPedido);
		fscanf(archi, "%[^\t]\t", regis->pedido.estado);
		fscanf(archi, "%[^\t]\t", regis->cliente.nombre);
		fscanf(archi, "%[^\t]\t", regis->cliente.correo);
		fscanf(archi, "%d\n", &regis->cliente.telefono);
		
		if(pedido==regis->pedido.idPedido){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
			printf("%d\t", regis->pedido.idPedido);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
			printf("%s\t", regis->pedido.estado);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			printf("%s\t", regis->cliente.nombre);
			printf("%s\t", regis->cliente.correo);
			printf("%d\n", regis->cliente.telefono);
			
			do{
				bandera=true;
				//regis->pedido.idPedido=validaEntero("Cual pedido quieres modificar: ");
				//resp=regis->pedido.idPedido
				if(regis->pedido.idPedido==regis->pedido.idPedido){
					strcpy(regis->pedido.estado,"Estado: Activo");
				}
			}while(!(bandera));
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		fprintf(archi5,"%d\t", regis->pedido.idPedido);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		fprintf(archi5,"%s\t", regis->pedido.estado);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		fprintf(archi5,"%s\t", regis->cliente.nombre);
		fprintf(archi5,"%s\t", regis->cliente.correo);
		fprintf(archi5,"%d\n", regis->cliente.telefono);
	}
	if(bandera==false)printf("No se encuentra el registro");
	else printf("\nDatos Actualizados\n");
	fclose(archi5);
	fclose(archi);
	remove("encabezado.txt");
	rename("copiaEncabezado3.txt", "encabezado.txt");
}

/*void juntos(){
	int resp=0, resp2=0, salir=0;
	//resp=validaEntero("1 Para continuar/ 2 para salir: ");
	resp2=validaEntero("¿Quieres cancelar o activar? 1->Para cancelar 2->Para activar: ");
	if(resp2==1){
		do{
			leer_dos();
			cancelado();
			salir=validaEntero("Desea salir 1->Si 2->No: ");
			if(salir==2){
				system("cls");
				//leer_dos();
			}
		}while(salir==2);
		system("cls");
		juntos();
	}else{
		do{
			leer_tres();
			activadosDos();
			salir=validaEntero("Desea salir 1->Si 2->No: ");
			if(salir==2){
				system("cls");
			}	
		}while(salir==2);
		system("cls");
		juntos();	
	}
}*/






