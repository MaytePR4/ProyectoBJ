/*Este menu es para los jugadores que tienen puntuación menor a 21*/
#include <stdio.h>

if(score<21)
{
	printf("Menú \n");
	printf("1.Plantarse \n");
	printf("2.Pedir otra carta \n");
	printf("3.Doblar la apuesta \n");
	printf("4.Jugar con 2 manos \n");

	switch(opcion)
	{
		case 1:/*Se recorre una posicion el nodo actual de la lista*/; 
		break;
		case 2: pop(pila); score=score+valorcarta; /*se le vuelve a mostrar el menú al jugador*/ 
		break;
		case 3: apuesta*2; pop(pila); score=score+valorcarta;
		break;
		case 4:/*Primero se evalua si se tienen 2 cartas del mismo valor*/;
		break;
	}	
}
