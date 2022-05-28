/*void ImprimirEstructura(){
	setlocale(LC_CTYPE, "Spanish");
	
	printf("\n\n------------Registros en la Estructura-----------------\n\n");
	
	for(int i=0; i<3; i++){
		printf("%d\t", info[i].matricula);
		printf("%s\t", info[i].nombre);
		printf("%s\t", info[i].carrera);
		printf("%.2f\t", info[i].calif[0]);
		printf("%.2f\t", info[i].calif[1]);
		printf("%.2f\n", info[i].calif[2]);
	}
}

void crear_archivo(){
	if(!(arch=fopen("informacion.txt", "w"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	for(int i=0; i<3; i++){
		fprintf(arch,"%d\t", info[i].matricula);
		fprintf(arch,"%s\t", info[i].nombre);
		fprintf(arch,"%s\t", info[i].carrera);
		fprintf(arch,"%f\t", info[i].calif[0]);
		fprintf(arch,"%f\t", info[i].calif[1]);
		fprintf(arch,"%f\n", info[i].calif[2]);
	}
	
	fclose(arch);
}

void leer_archivo(){
	setlocale(LC_CTYPE, "Spanish");
	Informacion dato;
	
	if(!(arch=fopen("informacion.txt", "r"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	
	printf("\n\n------------Registros del archivo-----------------\n\n");
	
	while(!feof(arch)){
		fscanf(arch,"%d\t", &dato.matricula);
		fscanf(arch,"%[^\t]\t", dato.nombre);
		fscanf(arch,"%[^\t]\t", dato.carrera);
		fscanf(arch,"%f\t", &dato.calif[0]);
		fscanf(arch,"%f\t", &dato.calif[1]);
		fscanf(arch,"%f\n", &dato.calif[2]);
		
		printf("%d\t", dato.matricula);
		printf("%s\t", dato.nombre);
		printf("%s\t", dato.carrera);
		printf("%.2f\t", dato.calif[0]);
		printf("%.2f\t", dato.calif[1]);
		printf("%.2f\n", dato.calif[2]);
	}
	fclose(arch);	
}*/

void ImprimirEstructura(){
	setlocale(LC_CTYPE, "Spanish");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
	printf("\n\n------------Registros del Almacen-----------------\n\n");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
	for(int i=0; i<10; i++){
		printf("%s\t", info[i].modelo);
		printf("%d\t", info[i].existencia);
		printf("%.2f\t", info[i].precio);
		printf("%s\n", info[i].ubicacion);
	}
}

void crear_archivo(){
	if(!(archi=fopen("almacen.txt", "w"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	for(int i=0; i<10; i++){
		fprintf(archi,"%s\t", info[i].ubicacion);
		fprintf(archi,"%s\t", info[i].modelo);
		fprintf(archi,"%d\t", info[i].existencia);
		fprintf(archi,"%f\n", info[i].precio);
	}
	
	fclose(archi);
}

void leer_archivo(){
	setlocale(LC_CTYPE, "Spanish");
	almacen dato;
	
	if(!(archi=fopen("almacen.txt", "r"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("\n\n------------Registros del archivo-----------------\n\n");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	while(!feof(archi)){
		fscanf(archi,"%[^\t]\t", dato.ubicacion);
		fscanf(archi,"%[^\t]\t", dato.modelo);
		fscanf(archi,"%d\t", &dato.existencia);
		fscanf(archi,"%f\n", &dato.precio);
		
		printf("%s\t", dato.modelo);
		printf("%d\t", dato.existencia);
		printf("%.2f\t", dato.precio);
		printf("%s\n", dato.ubicacion);
	}
	fclose(archi);	
}

void leer_estufa(){
	setlocale(LC_CTYPE, "Spanish");
	almacen dato;
	
	if(!(archi=fopen("almacen.txt", "r"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	printf("\n\n------------Registros de Estufas-----------------\n\n");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	while(!feof(archi)){
		fscanf(archi,"%[^\t]\t", dato.ubicacion);
		fscanf(archi,"%[^\t]\t", dato.modelo);
		fscanf(archi,"%d\t", &dato.existencia);
		fscanf(archi,"%f\n", &dato.precio);
		
		if(dato.modelo[0] == 'E' && dato.modelo[1] == 'S' && dato.modelo[2] == 'T'){
			printf("%s\t", dato.modelo);
			printf("%d\t", dato.existencia);
			printf("%.2f\t", dato.precio);
			printf("%s\n", dato.ubicacion);
		}
	}
	fclose(archi);	
}

void leer_hornos(){
	setlocale(LC_CTYPE, "Spanish");
	almacen dato;
	
	if(!(archi=fopen("almacen.txt", "r"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	printf("\n\n------------Registros de Hornos-----------------\n\n");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	while(!feof(archi)){
		fscanf(archi,"%[^\t]\t", dato.ubicacion);
		fscanf(archi,"%[^\t]\t", dato.modelo);
		fscanf(archi,"%d\t", &dato.existencia);
		fscanf(archi,"%f\n", &dato.precio);
		
		if(dato.modelo[0] == 'H' && dato.modelo[1] == 'O' && dato.modelo[2] == 'R'){
			printf("%s\t", dato.modelo);
			printf("%d\t", dato.existencia);
			printf("%.2f\t", dato.precio);
			printf("%s\n", dato.ubicacion);
		}
	}
	fclose(archi);	
}

void modifica(){
	setlocale(LC_CTYPE, "Spanish");
	almacen dato;
	FILE *archi2;
	char modelo[20];
	bool bandera=false;
	int resp=0, salir=0;
	
	//resp = validaEntero("1 Para continuar/ 2 para salir: ");
	//if(resp==1){
		
	do{	
	if(!(archi=fopen("almacen.txt", "r"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	
	if(!(archi2=fopen("copia.txt", "a+"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	
	validaModelo("Modelo a modificar: ", modelo);
	
	while(!feof(archi)){
		fscanf(archi,"%[^\t]\t", dato.ubicacion);
		fscanf(archi,"%[^\t]\t", dato.modelo);
		fscanf(archi,"%d\t", &dato.existencia);
		fscanf(archi,"%f\n", &dato.precio);
		
		if(!(strcmp(dato.modelo,modelo))){
			//printf("\nModelo a modificar\n\n");
			printf("%s\t", dato.modelo);
			printf("%d\t", dato.existencia);
			printf("%.2f\t", dato.precio);
			printf("%s\n\n", dato.ubicacion);
			
			
			dato.existencia = validaEntero("Nueva existencia: ");
			//dato.precio = validaFlotante("Nuevo precio: ");
			//validaCadena("\nNueva ubicación: ", dato.ubicacion);		
			bandera=true;
		}
		fprintf(archi2,"%s\t", dato.ubicacion);
		fprintf(archi2,"%s\t", dato.modelo);
		fprintf(archi2,"%d\t", dato.existencia);
		fprintf(archi2,"%f\n", dato.precio);
	}
	//salir=validaEntero("Desea salir 1->Si 2->No: ");
	/*if(salir==2){
		system("cls");
		remove("almacen.txt");
		rename("copia.txt", "almacen.txt");
		leer_estufa();
	}*/
	}while(salir==2);
	if(bandera==false)printf("No se encuentra el registro");
	else printf("\nDatos Actualizados\n");
	fclose(archi2);
	fclose(archi);
	remove("almacen.txt");
	rename("copia.txt", "almacen.txt");
/*}else{
}*/
}

void modifica_dos(){
	setlocale(LC_CTYPE, "Spanish");
	almacen dato;
	FILE *archi2;
	char modelo[20];
	bool bandera=false;
	int resp=0;
	
	resp = validaEntero("1 Para continuar/ 2 para salir: ");
	if(resp==1){
		
	if(!(archi=fopen("almacen.txt", "r"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	
	if(!(archi2=fopen("copia.txt", "a+"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	
	validaModelo("Modelo a modificar: ", modelo);
	
	while(!feof(archi)){
		fscanf(archi,"%[^\t]\t", dato.ubicacion);
		fscanf(archi,"%[^\t]\t", dato.modelo);
		fscanf(archi,"%d\t", &dato.existencia);
		fscanf(archi,"%f\n", &dato.precio);
		
		if(!(strcmp(dato.modelo,modelo))){
			//printf("\nModelo a modificar\n\n");
			printf("%s\t", dato.modelo);
			printf("%d\t", dato.existencia);
			printf("%.2f\t", dato.precio);
			printf("%s\n\n", dato.ubicacion);
			
			
			//dato.existencia = validaEntero("Nueva existencia: ");
			dato.precio = validaFlotante("Nuevo precio: ");
			//validaCadena("\nNueva ubicación: ", dato.ubicacion);		
			bandera=true;
		}
		fprintf(archi2,"%s\t", dato.ubicacion);
		fprintf(archi2,"%s\t", dato.modelo);
		fprintf(archi2,"%d\t", dato.existencia);
		fprintf(archi2,"%f\n", dato.precio);
	}
	if(bandera==false)printf("No se encuentra el registro");
	else printf("\nDatos Actualizados\n");
	fclose(archi2);
	fclose(archi);
	remove("almacen.txt");
	rename("copia.txt", "almacen.txt");
}else{
}
}

void modifica_tres(){
	setlocale(LC_CTYPE, "Spanish");
	almacen dato;
	FILE *archi2;
	char modelo[20];
	bool bandera=false;
	int resp=0;
	
	resp = validaEntero("1 Para continuar/ 2 para salir: ");
	if(resp==1){
		
	if(!(archi=fopen("almacen.txt", "r"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	
	if(!(archi2=fopen("copia.txt", "a+"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	
	validaModelo("Modelo a modificar: ", modelo);
	
	while(!feof(archi)){
		fscanf(archi,"%[^\t]\t", dato.ubicacion);
		fscanf(archi,"%[^\t]\t", dato.modelo);
		fscanf(archi,"%d\t", &dato.existencia);
		fscanf(archi,"%f\n", &dato.precio);
		
		if(!(strcmp(dato.modelo,modelo))){
			//printf("\nModelo a modificar\n\n");
			printf("%s\t", dato.modelo);
			printf("%d\t", dato.existencia);
			printf("%.2f\t", dato.precio);
			printf("%s\n\n", dato.ubicacion);
			
			
			//dato.existencia = validaEntero("Nueva existencia: ");
			//dato.precio = validaFlotante("Nuevo precio: ");
			validaCadena("\nNueva ubicación: ", dato.ubicacion);		
			bandera=true;
		}
		fprintf(archi2,"%s\t", dato.ubicacion);
		fprintf(archi2,"%s\t", dato.modelo);
		fprintf(archi2,"%d\t", dato.existencia);
		fprintf(archi2,"%f\n", dato.precio);
	}
	if(bandera==false)printf("No se encuentra el registro");
	else printf("\nDatos Actualizados\n");
	fclose(archi2);
	fclose(archi);
	remove("almacen.txt");
	rename("copia.txt", "almacen.txt");
}else{
}
}















void agregar(){
	setlocale(LC_CTYPE, "Spanish");
	almacen dato;
	char modelo[20];
	bool bandera=true;
	int salir=0;
	int resp=0;
	
	if(!(archi=fopen("almacen.txt", "a+"))){
		printf("Error al intentar crear archivo");
		exit(1);
	}
	
	resp = validaEntero("1 Para continuar/ 2 para salir: ");
	if(resp==1){
	
	
	printf("\nAgregar registro: ");
	do{
		validaModelo("Dame un nuevo modelo: ", modelo);
		salir=0;
		
		while(!feof(archi)){
			fscanf(archi,"%[^\t]\t", dato.ubicacion);
			fscanf(archi,"%[^\t]\t", dato.modelo);
			fscanf(archi,"%d\t", &dato.existencia);
			fscanf(archi,"%f\n", &dato.precio);
			
		if(strcmp(dato.modelo, modelo)==0){
			salir++;
		}
	}
	if(salir==0){
		bandera=false;
	}else{
		printf("Ya existe");
	}
}while(bandera);
	
	dato.existencia=validaEntero("Nueva existencia: ");
	dato.precio=validaEntero("Nuevo precio: ");
	validaCadena("Nueva ubicación: ", dato.ubicacion);
	
	fprintf(archi,"%s\t", dato.ubicacion);
	fprintf(archi,"%s\t", modelo);
	fprintf(archi,"%d\t", dato.existencia);
	fprintf(archi,"%f\n", dato.precio);
	
	printf("\nRegistro agregado\n\n");
	
	fclose(archi);
}else{
	fclose(archi);
}
}

/*void agregar(){
	setlocale(LC_CTYPE, "Spanish");
	almacen dato;
	
	if(!(archi=fopen("almacen.txt", "a+"))){
		printf("Error al intentar crear archivo");
		exit(1);
	}
	printf("\nAgregar registro: ");
	
	printf("\nNuevo modelo: ");
	scanf("%s", dato.modelo);
	dato.existencia=validaEntero("Nueva existencia: ");
	dato.precio=validaEntero("Nuevo precio: ");
	validaCadena("Nueva ubicación: ", dato.ubicacion);
	
	fprintf(archi,"%s\t", dato.ubicacion);
	fprintf(archi,"%s\t", dato.modelo);
	fprintf(archi,"%d\t", dato.existencia);
	fprintf(archi,"%f\n", dato.precio);
	
	printf("\nRegistro agregado\n\n");
	
	fclose(archi);
}*/

/*void agregar(){
	setlocale(LC_CTYPE, "Spanish");
	almacen dato;
	FILE *archi2;
	char modelo[20];
	bool bandera=true;
	int salir=0;
	
	if(!(archi=fopen("almacen.txt", "r"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	
	if(!(archi2=fopen("copia.txt", "a+"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	
	printf("\nAgregar registro: ");
	do{
		
		printf("\nNuevo modelo: ");
		scanf("%s", modelo);
		//validaModelo("Dame un nuevo modelo: ", dato.modelo);
		salir=0;
		
		while(!feof(archi)){
			fscanf(archi,"%[^\t]\t", dato.ubicacion);
			fscanf(archi,"%[^\t]\t", dato.modelo);
			fscanf(archi,"%d\t", &dato.existencia);
			fscanf(archi,"%f\n", &dato.precio);
			
		if((strcmp(dato.modelo, modelo))==0){
			salir++;
		}
	}
	if(salir==0){
		bandera=false;
	}else{
		printf("Ya existe");
	}
	
}while(bandera);

	dato.existencia=validaEntero("Nueva existencia: ");
	dato.precio=validaEntero("Nuevo precio: ");
	validaCadena("Nueva ubicación: ", dato.ubicacion);
	
	fprintf(archi,"%s\t", dato.ubicacion);
	fprintf(archi,"%s\t", dato.modelo);
	fprintf(archi,"%d\t", dato.existencia);
	fprintf(archi,"%f\n", dato.precio);
	
	printf("\nRegistro agregado\n\n");

	fclose(archi);
	fclose(archi2);
	
	remove("almacen.txt");
	rename("copia.txt", "almacen.txt");
}*/

/*void agregar(){
	setlocale(LC_CTYPE, "Spanish");
	almacen dato;
	bool bandera=true;
	int salir=0;
	char modelo[7];
	if(!(archi=fopen("almacen.txt", "a+"))){
		printf("Error al intentar crear archivo");
		exit(1);
		}
		printf("\nAgregar registro: ");
	
		do{
		salir=0;
		validaModelo("Nuevo modelo: ", modelo);
		while(!feof(archi)){
	
		fscanf(archi,"%[^\t]\t", dato.modelo);
		fscanf(archi,"%d\t", &dato.existencia);
		fscanf(archi,"%f\n", &dato.precio);
		fscanf(archi,"%[^\t]\t", dato.ubicacion);
	
		if(!(strcmp(dato.modelo,modelo))){
		salir++;
		}
	}
	
	if(salir==0){
		bandera=false;
	}else{
		printf("Ya existe");
	}
	
	}while(bandera);
	
	dato.existencia=validaEntero("Nueva existencia: ");
	dato.precio=validaEntero("Nuevo precio: ");
	validaCadena("Nueva ubicación: ", dato.ubicacion);
	
	fprintf(archi,"%s\t", dato.modelo);
	fprintf(archi,"%d\t", dato.existencia);
	fprintf(archi,"%f\t", dato.precio);
	fprintf(archi,"%s\n", dato.ubicacion);
	
	printf("\nRegistro agregado\n\n");
	
	fclose(archi);
}*/




