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
	printf("Universidad Polit�cnica de San Luis Potos�\n");
	gotoxy(65, 37);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
	printf("Programaci�n I Lenguaje C\n");
	gotoxy(65, 39);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
	printf("Diego Emmanuel Z��iga Rodr�guez\n");
	gotoxy(65, 40);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
	printf("Cavazos Zacar�as Rodolfo\n");
	gotoxy(65, 41);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
	printf("Cualquier tecla para iniciar...\n");
	getch();
}
