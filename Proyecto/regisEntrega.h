void leer(){
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
		
		
		/*fscanf(archi,"%d\t", &regis->pedido.idPedido);
		fscanf(archi,"%s\t", regis->modelo.idModelo);
		fscanf(archi,"%d\t", &regis->modelo.existencias);
		fscanf(archi,"%d\t", &regis->detalle.cantidad);
		fscanf(archi,"%.2f\n", &regis->detalle.subtotal);
		
		printf("%d\t", regis->pedido.idPedido);
		printf("%s\t", regis->modelo.idModelo);
		printf("%d\t", regis->modelo.existencias);
		printf("%d\t", regis->detalle.cantidad);
		printf("%.2f\n", regis->detalle.subtotal);*/
	/*}
		
	fclose(archi);
	regis->pedido.idPedido=validaEntero("Cual pedido quieres modificar: ");
	//resp=regis->pedido.idPedido;
	
	
	
	
	//if(regis->pedido.idPedido==resp)
	strcpy(regis->pedido.estado,"Estado: Entregado");*/
	
	
/*	do{
		bandera=true;
		regis->pedido.idPedido=validaEntero("Cual pedido quieres modificar: ");
		//resp=regis->pedido.idPedido
		if(regis->pedido.idPedido==regis->pedido.idPedido){
			strcpy(regis->pedido.estado,"Estado: Entregado");
		}
	}while(!(bandera));
	
	if(!(archi=fopen("encabezado.txt", "a+"))){
	printf("Error al intentar crear el archivo");
	exit(1);
	}
	
	fprintf(archi, "%d\t", regis->pedido.idPedido);
	fprintf(archi, "%s\t", regis->pedido.estado);
	fprintf(archi, "%s\t", regis->cliente.nombre);
	fprintf(archi, "%s\t", regis->cliente.correo);
	fprintf(archi, "%d\n", regis->cliente.telefono);
	fclose(archi);
}*/
void entregado(){
	setlocale(LC_CTYPE, "Spanish");
	FILE *archi3;
	bool bandera=false;
	int resp=0;
	int pedido=0;
	
	if(!(archi=fopen("encabezado.txt", "r"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	
	if(!(archi3=fopen("copiaEncabezado.txt", "a+"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	
	//resp = validaEntero("1 Para continuar/ 2 para salir: ");
	//if(resp==1){
	pedido=validaEntero("Cual pedido quieres modificar: ");
	
	while(!feof(archi)){
		fscanf(archi, "%d\t", &regis->pedido.idPedido);
		fscanf(archi, "%[^\t]\t", regis->pedido.estado);
		fscanf(archi, "%[^\t]\t", regis->cliente.nombre);
		fscanf(archi, "%[^\t]\t", regis->cliente.correo);
		fscanf(archi, "%d\n", &regis->cliente.telefono);
		
		if(pedido==regis->pedido.idPedido){
			printf("%d\t", regis->pedido.idPedido);
			printf("%s\t", regis->pedido.estado);
			printf("%s\t", regis->cliente.nombre);
			printf("%s\t", regis->cliente.correo);
			printf("%d\n", regis->cliente.telefono);
			
			do{
				bandera=true;
				//regis->pedido.idPedido=validaEntero("Cual pedido quieres modificar: ");
				//resp=regis->pedido.idPedido
				if(regis->pedido.idPedido==regis->pedido.idPedido){
					strcpy(regis->pedido.estado,"Estado: Entregado");
				}
			}while(!(bandera));
		}
		fprintf(archi3,"%d\t", regis->pedido.idPedido);
		fprintf(archi3,"%s\t", regis->pedido.estado);
		fprintf(archi3,"%s\t", regis->cliente.nombre);
		fprintf(archi3,"%s\t", regis->cliente.correo);
		fprintf(archi3,"%d\n", regis->cliente.telefono);
	}
	if(bandera==false)printf("No se encuentra el registro");
	else printf("\nDatos Actualizados\n");
	fclose(archi3);
	fclose(archi);
	remove("encabezado.txt");
	rename("copiaEncabezado.txt", "encabezado.txt");
/*}else{
	fclose(archi3);
	fclose(archi);
}*/
}



