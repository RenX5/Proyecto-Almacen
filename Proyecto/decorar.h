void portada(){
	int aux = 0;
	FILE *archivo = fopen("colores.txt", "r");
	
	for(int i=0; i<56; i++){
		for(int j=0; j<37; j++){
			fscanf(archivo,"%d\t", &aux);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),aux);
			printf("%c", 1);
		}
		printf("\n");
	}
	fclose(archivo);
}

void datos(){
	setlocale(LC_CTYPE, "Spanish");
	gotoxy(65, 35);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
	printf("Universidad Politécnica de San Luis Potosí\n");
	gotoxy(65, 37);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
	printf("Programación I Lenguaje C\n");
	gotoxy(65, 39);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
	printf("Diego Emmanuel Zúñiga Rodríguez\n");
	gotoxy(65, 40);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
	printf("Cavazos Zacarías Rodolfo\n");
	gotoxy(65, 41);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
	printf("Cualquier tecla para iniciar...\n");
	getch();
}
