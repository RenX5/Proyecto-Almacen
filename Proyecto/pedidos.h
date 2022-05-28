void leer_activos(){
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

void leer_entregas(){
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
		if(strcmp(regis->pedido.estado, "Estado: Entregado")==0){
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

void leer_cancelados(){
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

void leer_todos(){
	int pedido=0;
	
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
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		printf("%d\t", regis->pedido.idPedido);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		printf("%s\t", regis->pedido.estado);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		printf("%s\t", regis->cliente.nombre);
		printf("%s\t", regis->cliente.correo);
		printf("%d\n", regis->cliente.telefono);
	}
	fclose(archi);
	
	pedido=validaEntero("Pedido a buscar: ");
	if(!(archi=fopen("detalle.txt", "r"))){
		printf("Error al leer el archivo");
		exit(1);
	}
	while(!feof(archi)){
		fscanf(archi, "%d\t", &regis->pedido.idPedido);
		fscanf(archi, "%[^\t]\t", regis->modelo.idModelo);
		fscanf(archi, "%d\t", &regis->modelo.existencias);
		fscanf(archi, "%d\t", &regis->detalle.cantidad);
		fscanf(archi, "%f\n", &regis->detalle.subtotal);
		
		if(pedido==regis->pedido.idPedido){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
			printf("%d\t", regis->pedido.idPedido);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
			printf("%s\t", regis->modelo.idModelo);
			printf("%d\t", regis->modelo.existencias);
			printf("%d\t", regis->detalle.cantidad);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			printf("%.2f\n", regis->detalle.subtotal);
		}
	}
	fclose(archi);
}
