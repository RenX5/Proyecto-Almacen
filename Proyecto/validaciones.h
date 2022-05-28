float validaFlotante(const char mensaje[]){
	int continuar=0;
	float flotante=0;
	
	do{
		printf("\n%s", mensaje);
		continuar = scanf("%f", &flotante);
		fflush(stdin);
	}while (continuar !=1);
	
	return flotante;
}

/*int validaEntero(const char mensaje[]){
	int continuar=0;
	int entero=0;
	bool bandera=true;
	
	do{
		printf("\n%s", mensaje);
		continuar = scanf("%d", &entero);
		fflush(stdin);
		
	}while (continuar !=1);
	
	return entero;
}*/

int validaEntero(const char mensaje[]){
	int entero=0;
	bool bandera2 = true;
	
	while (bandera2){
		printf("\n%s", mensaje);
		scanf("%d", &entero);
		fflush(stdin);
		
		if(entero <=-1 or entero==0){
			continue;
		}
		else{
				bandera2=false;	
				}
			}
	return entero;
}



void validaCadena(const char mensaje[], char cadena[]){
SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	bool bandera = true;
	
	while(bandera){
		printf("\n%s", mensaje);
		scanf("%[^\n]", cadena);
		fflush(stdin);
		if(strlen(cadena)>20){
			continue;
		}else{
			for(int i = 0; i<strlen(cadena); i++){
				if(cadena[i]==' ' || isalpha(cadena[i])){
					if (i== (strlen(cadena)-1)){
						bandera=false;
					}
				}else{
					break;
				}
			}
		}
	}
}

void validaModelo (const char mensaje[], char modelo[]){
	bool bandera=true;
	while(bandera){
		int cont=0, cont_2=0;
		printf("\n%s", mensaje);
		scanf("%[^\n]", modelo);
		fflush(stdin);
		if(strlen(modelo)==6){
			for(int i=0; i<3; i++){
				if((modelo[i] == ' ' or isdigit(modelo[i]) == 0 && modelo[i]>=65 && modelo[i]<=90)){
					cont++;
				}else{
					break;
					}
				}
				for(int i=3; i<6; i++){
					if(isdigit(modelo[i]) && !(modelo[i]==' ')){
						cont_2++;
				}else{
					break;
					}
				}
				if(cont==3 && cont_2==3){
				bandera=false;
			}
		}else{
			continue;
		}
	}
}

	
void validaCorreo(const char mensaje[], char cadena[]){
SetConsoleCP(1252);
SetConsoleOutputCP(1252);
bool bandera = true;
int cont=0;

while(bandera){
cont=0;
printf("\n%s", mensaje);
scanf("%[^\n]",cadena);
fflush(stdin);

for(int i = 0; i<strlen(cadena); i++){
if(cadena[i]=='@'){
cont++;
}else if(cadena[i]=='@' and cont==1)
continue;

if((i==(strlen(cadena)-1)) && cont==1){
bandera=false;
break;
}

}
}
}
	

