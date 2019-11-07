#include <stdio.h>
#include <stdlib.h>

typedef struct BlackJack 
{
	char *nombre, *carta;
    int *puntos, *Suma;
	struct nodo *siguiente;
}Turnos;

Turnos *CrearNodo(int valor)
{
	Turnos *newNode = (Turnos *) malloc (sizeof(Turnos));
	newNode -> data = nombre;
	newNode ->siguiente = NULL;
	return newNode;
}

Turnos *Partida (int numPLayer, int alias, int nomCarta, int points, int Z)
{
	Turnos *head = NULL;
	Turnos *newNode = NULL;
	int i;
	for (i=0; i<=numPLayer; i++)
	{
		newNode = CrearNodo (i);
		if (head == NULL)
		{
			head = newNode;
		}
		else
		{
			Turnos *turnoActual = head;
			while (turnoActual -> siguiente != NULL)
			{
				turnoActual = turnoActual->siguiente;
			}
			turnoActual -> siguiente = newNode;
		}
	}
	return head;
}

void Imprimir(Turnos *list)
{
	Turnos *turnoActual = list;
	while (turnoActual->siguiente != NULL)
	{
		
	}
}
int main ()
{
	 
} 
 