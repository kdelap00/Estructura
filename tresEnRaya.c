/*
------------------------------------------------------------------------------------------------------
---------                                                                                    ---------
---------                                          TRES EN RAYA                              ---------
---------                                                                                    ---------
------------------------------------------------------------------------------------------------------
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int menu();//Desplegar menu de opciones y seleccion de opcion
void inicializarTablero(int tablero[][3]);//Inicializar a vacio el tablero
void desplegarTablero(int tablero[][3]);//Desplegar el tablero actual
void seleccionarCasilla(int tablero[][3], int numeroJugador);//Seleccionar casilla y cambiar el valor de esa casilla por el del jugador
void seleccionarCasillaCPU(int tablero[][3]);//Seleccion de casilla de forma aleatoria para el juego VS computadora
int finJuego(int tablero[][3]);//Analiza si algun jugador ha hecho tres en raya, o el juego ha acabado en tablas y devuelve win (0, 1, 2, 3)
int main(){
	
	srand(time(NULL));
	int tablero[3][3];
	int opcion, win=0, numeroJugador=0, aux=0;
	opcion=menu();
		if(opcion==1){//Opcion de Jugador Vs Jugador
		
			inicializarTablero(tablero);
			printf("--------------------------------\nHas seleccionado Jugador VS Jugador");
			printf("Comienza el juego\n--------------------------------");	
			numeroJugador=(rand()%2)+1;//Selecciona el jugador que comienza de forma aleatoria
			while(win==0){//Desarrollo del juego mientras no hay un ganador
				desplegarTablero(tablero);
				printf("\nTurno del jugador %d\n", numeroJugador);
				seleccionarCasilla(tablero, numeroJugador);
				if(numeroJugador==1){
					aux=2;
				}
				if(numeroJugador==2){
					aux=1;
				}
				numeroJugador=aux;
				win=finJuego(tablero);
			}
			
		}
		switch(win){
			case 1: desplegarTablero(tablero);
					printf("\nFIN DEL JUEGO\n");
					printf("HA GANADO EL JUGADOR 1\n");
					break;
			case 2: desplegarTablero(tablero);
					printf("\nFIN DEL JUEGO\n");
					printf("HA GANADO EL JUGADOR 2\n");
					break;
			case 3: desplegarTablero(tablero);
					printf("\nFIN DEL JUEGO\n");
					printf("EL JUEGO HA ACABADO EN TABLAS\n");
					break;
		}
		
		
		if(opcion==2){//Opcion de Jugador Vs Computador
		
			inicializarTablero(tablero);
			printf("--------------------------------\nHas seleccionado Jugador VS Jugador");
			printf("Comienza el juego\n--------------------------------");
			numeroJugador=rand()%2;//Selecciona si comienza el jugador o la CPU de forma aleatoria
			while(win==0){//Desarrollo del juego mientras no hay un ganador
				//Cuando numeroJugador=0, es el turno de la CPU
				desplegarTablero(tablero);
				if(numeroJugador==1){
					printf("\nTurno del jugador\n");
					seleccionarCasilla(tablero, numeroJugador);
				}
				if(numeroJugador==0){
					printf("Turno de la computadora\n");
					seleccionarCasillaCPU(tablero);
				}
				if(numeroJugador==1){
					aux=0;
				}
				if(numeroJugador==0){
					aux=1;
				}
				numeroJugador=aux;
				win=finJuego(tablero);
			}
			switch(win){
			case 1: desplegarTablero(tablero);
					printf("\nFIN DEL JUEGO\n");
					printf("HA2 GANADO\n");
					break;
			case 2: desplegarTablero(tablero);
					printf("\nFIN DEL JUEGO\n");
					printf("HAS PERDIDO\n");
					break;
			case 3: desplegarTablero(tablero);
					printf("\nFIN DEL JUEGO\n");
					printf("EL JUEGO HA ACABADO EN TABLAS\n");
					break;
		}
		
		}
		
	return 0;
}
int menu(){//Desplegar menu de opciones y seleccion de opcion

	int opcion=0;
	printf("---------------------\nTRES EN RAYA\n---------------------\n");
	printf("1. Jugador vs Jugador\n");
	printf("2. Jugador vs Computadora\n");
	printf("3. Salir\n");
	printf("\nIntroduce el numero de la opcion que deseas seleccionar: ");
	while((opcion!=1)&&(opcion!=2)&&(opcion!=3)){
		scanf("%d", &opcion);
		if((opcion!=1)&&(opcion!=2)&&(opcion!=3)){
			printf("ERROR. Introduce una opcion valida: ");
		}
	}
	
	return opcion;
}

void inicializarTablero(int tablero[][3]){//Inicializar a vacio el tablero

	int i, j;
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			tablero[i][j]=0;
		}
	}

}

void desplegarTablero(int tablero[][3]){//Desplegar el tablero actual

	int i, j;
	for(i=0; i<3; i++){
		printf("\n\n");
		for(j=0; j<3; j++){
			printf("%d    ", tablero[i][j]);
		}
	}
	printf("\n");

}

void seleccionarCasilla(int tablero[][3], int numeroJugador){//Seleccionar casilla y cambiar el valor de esa casilla por el del jugador

	int n=0, m=0;
	do{
		printf("Selecciona la fila: ");
		while((n!=1)&&(n!=2)&&(n!=3)){
			scanf("%d", &n);
			if((n!=1)&&(n!=2)&&(n!=3)){
				printf("ERROR. Introduce un valor valido: ");
			}
		}
		printf("Selecciona la columna: ");
		while((m!=1)&&(m!=2)&&(m!=3)){
			scanf("%d", &m);
			if((m!=1)&&(m!=2)&&(m!=3)){
				printf("ERROR. Introduce un valor valido: ");
			}
		}
		if(tablero[n-1][m-1]!=0){
			printf("ERROR. La casilla que has seleccionado ya esta ocupada\n");
			m=4;
			n=4;
		}
	}while(tablero[n-1][m-1]!=0);
	tablero[n-1][m-1]=numeroJugador;
}

void seleccionarCasillaCPU(int tablero[][3]){

	int n, m;
	do{
		n=rand()%3;
		m=rand()%3;
		if(tablero[n][m]!=0){
			n=3;
			m=3;
		}
	}while(tablero[n][m]!=0);
	tablero[n][m]=2;
	
}

int finJuego(int tablero[][3]){//Analiza si algun jugador ha hecho tres en raya, o el juego ha acabado en tablas y devuelve win (0, 1, 2, 3)

	int i, j, n0=0, tresenraya=0;//n0-->Numero de ceros que hay
	int win=0;//Variable que devuelve
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			if(tablero[i][j]!=0){
				n0++;
			}
		}
	}
	for(j=0; j<3; j++){
		if((tablero[0][j]==tablero[1][j])&&(tablero[1][j]==tablero[2][j])){
			if(tablero[0][j]==1){
				tresenraya=1;
			}
			if(tablero[0][j]==2){
				tresenraya=2;
			}
		}
	}
	for(i=0; i<3; i++){
		if((tablero[i][0]==tablero[i][1])&&(tablero[i][1]==tablero[i][2])){
			if(tablero[i][0]==1){
				tresenraya=1;
			}
			if(tablero[i][0]==2){
				tresenraya=2;
			}
		}
	}
	if((tablero[0][0]==tablero[1][1])&&(tablero[1][1]==tablero[2][2])){
		if(tablero[0][0]==1){
			tresenraya=1;
		}
		if(tablero[0][0]==2){
			tresenraya=2;
		}
	}
	if((tablero[2][0]==tablero[1][1])&&(tablero[1][1]==tablero[0][2])){
		if(tablero[1][1]==1){
			tresenraya=1;
		}
		if(tablero[1][1]==2){
			tresenraya=2;
		}
	}
	if(tresenraya==1){
		n0=0;
		win=1;
	}
	if(tresenraya==2){
		n0=0;
		win=2;
	}
	if(n0==9){
		win=3;
	}
	
	
	return win;
	//Win=0-->Juego continua...Win=1-->Gana Jugador 1...Win=2-->Gana Jugador 2...Win=3-->Juego acaba en tablas
}
















