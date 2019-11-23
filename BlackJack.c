#include <stdio.h>
#include <stdlib.h>

/*Estructura que representa una carta*/
struct Carta
{
	int valor; //Para saber que carta es: de el 1 al 13 
	char palo; // ♥ = C, ♦ = D, ♣ = T y ♠ = E
};

/*Pila*/
struct Pila
{
	struct Carta *carta;
	struct Pila *siguiente;
};

/*Cartas a repartir para cada jugador*/
struct ListaCartas
{
	struct Carta* carta;
	struct ListaCartas *siguiente;
};

/*Funciones para la pila*/
int push(struct Pila **Pila, struct Carta *carta);
struct Pila* pop(struct Pila **Pila);
void mostrarPila(struct Pila *Pila);  

struct Carta* PilaR(struct Carta *ArregloPila[]);
void CrearYAnadir(struct Pila **Pila);
struct Carta* CrearPila(struct Carta *ArregloPila[]);

int main()
{
	struct Pila *Pila=NULL;
	Pila=(struct Pila*)malloc(sizeof(struct Pila));
	Pila->siguiente=NULL;


	return 0;
}
	
struct Carta* PilaR(struct Carta *ArregloPila[])
{
	struct Carta *aux;
	aux=(struct Carta*)malloc(sizeof(struct Carta));
	int random;
	
	for(int j=0; j<rand()%5; j++)
	{
		for(int i=0; i<52; i++)
		{
			random=rand()%52;
			aux=ArregloPila[i];
			ArregloPila[i]=ArregloPila[random];
			ArregloPila[random]=aux;
		}
	}
	
	return *ArregloPila;
}

void CrearYAnadir(struct Pila **Pila)
{
	struct Carta *ArregloPila[52];
	
	*ArregloPila=CrearPila(ArregloPila);
	*ArregloPila=PilaR(ArregloPila);

	for(int i=0; i<52; i++)
	{
		push(Pila, ArregloPila[i]);
	}
}

struct Carta* CrearPila(struct Carta *ArregloPila[])
{
	int indice=0;

	for(int i=0; i<4; i++)
	{
		for(int j=0; j<13; j++)
		{
			/*Crea la carta*/
			struct Carta *carta=NULL;
			carta=(struct Carta*)malloc(sizeof(struct Carta));

			/*Asigna el valor a la carta*/
			carta->valor=j+1;

			/*Asigna el palo a la carta*/
			switch(i)
			{
				case 0: 
					carta->palo='C';
					break;
				case 1: 
					carta->palo='D';
					break;
				case 2: 
					carta->palo='T';
					break;
				case 3: 
					carta->palo='E';
					break;
				default:
					break;
			}
			
			ArregloPila[indice]=carta;
			indice++;
		}
	}

	return *ArregloPila;
}

int push(struct Pila **Pila,struct Carta *carta)
{
	struct Pila *nuevo=NULL;

	nuevo=(struct Pila*)malloc(sizeof(struct Pila));

	if(nuevo==NULL)
	{
		return -1;
	}

	nuevo->carta=carta;
	nuevo->siguiente=*Pila;
	*Pila=nuevo;

	return 0;
}

struct Pila* pop(struct Pila **Pila)
{
	struct Pila *aux=NULL;
	aux=*Pila;

	if(*Pila==NULL)
	{
		return NULL;
	}
	else
		{
			*Pila=aux->siguiente;
			return aux;
		}
}

void mostrarPila(struct Pila *Pila)
{
	while(Pila->siguiente!=NULL)
	{
            if( (Pila->carta)->valor <= 10)
			{
                printf("%d%c ",(Pila->carta)->valor,(Pila->carta)->palo);
            }
			else
				{
		            if((Pila->carta)->valor == 11)
					{
		                printf("J%c ",(Pila->carta)->palo);
		            }
		            if((Pila->carta)->valor == 12)
					{
		                printf("Q%c ",(Pila->carta)->palo);
		            }
		            if((Pila->carta)->valor == 13)
					{
		                printf("K%c ",(Pila->carta)->palo);
		            }
   	         	}

            Pila=Pila->siguiente;
	}
	printf("\n");
}









