almacen buscaModelo(char modelo[20]){
	setlocale(LC_CTYPE, "Spanish");
	bool bandera = true;
	almacen dato;
	
	if(!(archi=fopen("almacen.txt", "r"))){
		printf("Error al leer el archivo");
		exit(1);
	}
	
	while(!feof(archi)){
		fscanf(archi,"%[^\t]\t", dato.ubicacion);
		fscanf(archi,"%[^\t]\t", dato.modelo);
		fscanf(archi,"%d\t", &dato.existencia);
		fscanf(archi,"%f\n", &dato.precio);
		
		if(strcmp(dato.modelo, modelo)==0){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
			printf("\nDatos actuales: \n\n");
			printf("%s\t", dato.modelo);
			printf("%d\t", dato.existencia);
			printf("%.2f\t", dato.precio);
			printf("%s\n", dato.ubicacion);
			fclose(archi);
			return dato;
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	if(bandera==false)printf("No se encuentra el registro");
	//return dato;
}

void agregarDinamico(){
	int resp=0;
	int resp2=0;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	resp = validaEntero("1 Para continuar/ 2 para salir: ");
	if(resp==1){
	//do{
		system("cls");
		float total=0;
		float subtotal=0;
		int resta=0;
		bool bandera2=true;
		int pedido=0;
	srand(time(NULL));
	setlocale(LC_CTYPE, "Spanish");
	almacen dato = {};
	
	//printf("\nRegistro Dinamico ");
	
	regis->pedido.idPedido = 1+rand()%(1000-1);
	//validaCadena("Estado (poner Activo): ", regis->pedido.estado);
	strcpy(regis->pedido.estado,"Estado: Activo");
	//printf("\nPedido: Activo\n", regis->pedido.estado);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	validaCadena("Nombre: ", regis->cliente.nombre);
	regis->cliente.telefono=validaEntero("Teléfono: ");
	validaCorreo("Correo: ", regis->cliente.correo);
	
	system("cls");
	do{
	system("cls");
	leer_archivo();
	validaModelo("Modelo: ", regis->modelo.idModelo);
	dato = buscaModelo(regis->modelo.idModelo);
	do{
		bandera2=true;
		regis->detalle.cantidad=validaEntero("Cúantos quieres? ");
		if(regis->detalle.cantidad > dato.existencia){
			printf("Piezas insuficientes");
			bandera2=false;
		}else{
			resta=dato.existencia-regis->detalle.cantidad; 
			dato.existencia=resta;
		}
	}while(!(bandera2));
	
	//dato.existencia = regis->detalle.cantidad - dato.existencia;
	regis->detalle.subtotal = regis->detalle.cantidad * dato.precio;
	strcpy(regis->modelo.idModelo, dato.modelo);
	regis->modelo.existencias = dato.existencia;
	subtotal = regis->detalle.subtotal;
	
	total+=subtotal;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	resp2=validaEntero("¿Agregar otro registro? 1 para SI 2 para NO: ");
	
	if(!(archi=fopen("detalle.txt", "a+"))){
		printf("Error al crear el archivo");
		exit(1);
	}
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
	fprintf(archi, "%d\t", regis->pedido.idPedido);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	fprintf(archi, "%s\t", regis->modelo.idModelo);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	fprintf(archi, "%d\t", regis->modelo.existencias);
	fprintf(archi, "%d\t", regis->detalle.cantidad);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	fprintf(archi, "%.2f\n", regis->detalle.subtotal);

	fclose(archi);
	}while(resp2==1);
	
	if(!(archi=fopen("encabezado.txt", "a+"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
	fprintf(archi, "%d\t", regis->pedido.idPedido);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	fprintf(archi, "%s\t", regis->pedido.estado);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	fprintf(archi, "%s\t", regis->cliente.nombre);
	fprintf(archi, "%s\t", regis->cliente.correo);
	fprintf(archi, "%d\n", regis->cliente.telefono);
	fclose(archi);
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	printf("Numero de pedido: %d\n", regis->pedido.idPedido);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	pedido=regis->pedido.idPedido;
	printf("%s\n", regis->pedido.estado);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	printf("Nombre del cliente: %s\n", regis->cliente.nombre);
	printf("Teléfono: %d\n", regis->cliente.telefono);
	printf("Correo Electrónico: %s\n", regis->cliente.correo);
	//printf("Modelo: %s\t", regis->modelo.idModelo);

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
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			printf("%d\t", regis->modelo.existencias);
			printf("%d\t", regis->detalle.cantidad);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			printf("%.2f\n", regis->detalle.subtotal);
		}
	}
	fclose(archi);

	printf("Total: %.2f\n", total);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	printf("\nRegistro agregado\n\n");
	/*resp2=validaEntero("¿Agregar otro registro? 1 para SI 2 para NO: ");
	}while(resp2==1);*/
	}else{
		fclose(archi);
	}
}
	
void resta(){
	setlocale(LC_CTYPE, "Spanish");
	almacen dato;
	FILE *archi10;
	int resta=0;
	bool bandera=false;
	if(!(archi=fopen("almacen.txt", "r"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	
	if(!(archi10=fopen("copiaResta.txt", "a+"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	
		while(!feof(archi)){
		fscanf(archi,"%[^\t]\t", dato.ubicacion);
		fscanf(archi,"%[^\t]\t", dato.modelo);
		fscanf(archi,"%d\t", &regis->modelo.existencias);
		fscanf(archi,"%f\n", &dato.precio);
		
		resta=dato.existencia-regis->detalle.cantidad; 
		dato.existencia=resta;
			
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);	
		fprintf(archi10,"%s\t", dato.ubicacion);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
		fprintf(archi10,"%s\t", dato.modelo);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		fprintf(archi10,"%d\t", regis->modelo.existencias);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		fprintf(archi10,"%f\n", dato.precio);
	}
	fclose(archi10);
	fclose(archi);
	remove("almacen.txt");
	rename("copiaResta.txt", "almacen.txt");
}	
	
	//printf("\nRegistro agregado\n\n");

/*Informacion buscaMatricula(int matricula){
	setlocale(LC_CTYPE, "Spanish");
	bool bandera = false;
	Informacion dato;
	
	if(!(arch=fopen("informacion.txt", "r"))){
		printf("Error al leer el archivo");
		exit(1);
	}
	
	while(!feof(arch)){
		fscanf(arch,"%d\t", &dato.matricula);
		fscanf(arch,"[^\t]\t", dato.nombre);
		fscanf(arch,"[^\t]\t", dato.carrera);
		fscanf(arch,"%f\t", &dato.calif[0]);
		fscanf(arch,"%f\t", &dato.calif[1]);
		fscanf(arch,"%f\n", &dato.calif[2]);
		
		if(dato.matricula == matricula){
			printf("\nCalificaciones actuales del alumno: \n\n");
			printf("%d\t", dato.matricula);
			printf("%s\t", dato.nombre);
			printf("%s\t", dato.carrera);
			printf("%.2f\t", dato.calif[0]);
			printf("%.2f\t", dato.calif[1]);
			printf("%.2f\n\n", dato.calif[2]);
			fclose(arch);
			return dato;
		}
	}
	if(bandera==false)printf("No se encuentra el registro");
	return dato;
}

void agregarDinamico(){
	setlocale(LC_CTYPE, "Spanish");
	Informacion dato;
	
	printf("Nombre: Zúñiga Rodríguez Diego Emmanuel");
	printf("\nRegistro Dinamico ");
	
	regis->idGrupo = validaEntero("Id grupo: ");
	validaCadena("Semestre: ", regis->semestre);
	
	regis->docente.idDocente = validaEntero("Id docente: ");
	validaCadena("Nombre: ", regis->docente.nomCompleto);
	validaCadena("Correo: ", regis->docente.correo);
	validaCadena("NSS: ", regis->docente.NSS);
	validaCadena("Fecha de ingreso: ", regis->docente.fechaIngreso);
	
	leer_archivo();
	//validaModelo("Modelo: ", regis->alumno.idAlumno);
	regis->alumno.idAlumno = validaEntero("Matrícula: ");
	dato = buscaMatricula(regis->alumno.idAlumno);
	
	regis->alumno.inf.matricula = dato.matricula;
	strcpy(regis->alumno.inf.nombre, dato.nombre);
	strcpy(regis->alumno.inf.carrera, dato.carrera);
	regis->alumno.inf.calif[0] = dato.calif[0];
	regis->alumno.inf.calif[1] = dato.calif[1];
	regis->alumno.inf.calif[2] = dato.calif[2];
	
	if(!(arch=fopen("informacion.txt", "w"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	
	fprintf(arch,"%d\t", regis->idGrupo);
	fprintf(arch,"%s\t", regis->semestre);
	fprintf(arch,"%d\t", regis->docente.idDocente);
	fprintf(arch,"%s\t", regis->docente.nomCompleto);
	fprintf(arch,"%s\t", regis->docente.correo);
	fprintf(arch,"%s\t", regis->docente.NSS);
	fprintf(arch,"%s\t", regis->docente.fechaIngreso);
	
	fprintf(arch,"%d\t", regis->alumno.inf.matricula);
	fprintf(arch,"%s\t", regis->alumno.inf.nombre);
	fprintf(arch,"%s\t", regis->alumno.inf.carrera);
	fprintf(arch,"%.2f\t", regis->alumno.inf.calif[0]);
	fprintf(arch,"%.2f\t", regis->alumno.inf.calif[1]);
	fprintf(arch,"%.2f\n", regis->alumno.inf.calif[2]);
	
	printf("\nRegistro agregado\n\n");
}*/
