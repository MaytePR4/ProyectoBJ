#include <stdio.h>
#include <stdlib.h>

typedef struct BlackJack 
{
	char *nombre, *carta;
    int *players, *puntos, *Suma;
	struct BlackJack *siguiente;
}Turnos;

Turnos *CrearNodo(int valor)
{
	Turnos *newNode = (Turnos *) malloc (sizeof(Turnos));
	newNode->players = valor;
	newNode->siguiente = NULL;
	return newNode;
}

Turnos *newPartida (int numPLayer)
{
	Turnos *primero = NULL;
	Turnos *newNode = NULL;
	int i;
	char nom;
	for (i=1; i<=numPLayer; i++)
	{
		printf ("Cual es el nombre o el alias del jugador %d",i);
		scanf ("%c",&nom)
		newNode = CrearNodo (nom);
		if (primero == NULL)
		{
			primero = newNode;
		}
		else
		{
			Turnos *turnoActual = primero;
			while (turnoActual -> siguiente != NULL)
			{
				turnoActual = turnoActual->siguiente;
			}
			turnoActual -> siguiente = newNode;
		}
	}
	return primero;
}

void Imprimir(Turnos *list)
{
	Turnos *turnoActual = list;
	while (turnoActual->siguiente != NULL)
	{
		printf ("%d",turnoActual->players);
		turnoActual = turnoActual->siguiente;
	}
}

int main ()
{
	int opMenu=0, numPLayer;
	printf ( " *********Menú Principal*********\ n " );
	printf ( " 1.Nuevo Juego \ n " );
	printf ( " 2.Salir \ n " );
	scanf("%d",&opMenu);
	switch (opMenu)
	{
		case 1: printf ("Dime el numero de jugadores (1-6)");
				scanf ("%d", &numPLayer);
				Turnos *myList = newPartida(numPLayer);
   				printList(myList);
    			printf("\n\n");
		break;
		case 2: exit (-1);
		break;
	}
	 
} 
 