#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Baraja
{
	int dato;
	int cima;
};

struct Lista
{
	string carta;	
	int fin;
	string *cnombre;	
};

int agregarCartas(struct Lista *cartas, string carta)
{
	int *tmp;

	if(lista==NULL)
	{
		return -1;
	}
	
	tmp = (int *)malloc((lista->fin*2)*sizeof(int));
	
	if(tmp==NULL)
	{
		return 0;
	}

	*(tmp + (lista->fin))=carta;

	for(int i=0;i<lista->fin;i++)
	{
		*(tmp + i) = *(lista->datos + i);
	}

	free(lista->datos);
	lista->datos=tmp;
	lista->fin++;

	return 0;	
}

int posiciones(struct Baraja *baraja, int dato)
{
	baraja->dato[baraja->cima]=dato;
	baraja->cima++;
}

void barajeo(struct Baraja *baraja)
{
	int *temporal, posicion=0;
	
	temporal=(struct Baraja*)malloc(sizeof(struct Baraja));

	for(int i=0;i<=52;i++)
	{
		posicion=ran()%53;
		*(temporal + posicion)=*(baraja->dato + i);
	}

	free(baraja->dato);
	baraja->dato=temporal;
}

void repartir(struct Baraja *baraja)
{
	printf("%s ", cartas->cnombre[baraja->cima]);
	baraja->cima--;
}

int main()
{
	struct Baraja *baraja=NULL;
	baraja=(struct Baraja*)malloc(sizeof(struct Baraja));
	baraja->cima=0;  

	struct Lista *cartas=NULL;
	cartas=(struct Lista*)malloc(sizeof(struct Lista));	
	cartas->fin=0;  

	agregarCartas(cartas, "As de picas");
	agregarCartas(cartas, "2 de picas");
	agregarCartas(cartas, "3 de picas");
	agregarCartas(cartas, "4 de picas");
	agregarCartas(cartas, "5 de picas");
	agregarCartas(cartas, "6 de picas");
	agregarCartas(cartas, "7 de picas");
	agregarCartas(cartas, "8 de picas");
	agregarCartas(cartas, "9 de picas");
	agregarCartas(cartas, "10 de picas");
	agregarCartas(cartas, "J de picas");
	agregarCartas(cartas, "Q de picas");
	agregarCartas(cartas, "K de picas");
	agregarCartas(cartas, "As de corazones");
	agregarCartas(cartas, "2 de corazones");
	agregarCartas(cartas, "3 de corazones");
	agregarCartas(cartas, "4 de corazones");
	agregarCartas(cartas, "5 de corazones");
	agregarCartas(cartas, "6 de corazones");
	agregarCartas(cartas, "7 de corazones");
	agregarCartas(cartas, "8 de corazones");
	agregarCartas(cartas, "9 de corazones");
	agregarCartas(cartas, "10 de corazones");
	agregarCartas(cartas, "J de corazones");
	agregarCartas(cartas, "Q de corazones");
	agregarCartas(cartas, "K de corazones");
	agregarCartas(cartas, "As de diamantes");
	agregarCartas(cartas, "2 de diamantes");
	agregarCartas(cartas, "3 de diamantes");
	agregarCartas(cartas, "4 de diamantes");
	agregarCartas(cartas, "5 de diamantes");
	agregarCartas(cartas, "6 de diamantes");
	agregarCartas(cartas, "7 de diamantes");
	agregarCartas(cartas, "8 de diamantes");
	agregarCartas(cartas, "9 de diamantes");
	agregarCartas(cartas, "10 de diamantes");
	agregarCartas(cartas, "J de diamantes");
	agregarCartas(cartas, "Q de diamantes");
	agregarCartas(cartas, "K de diamantes");
	agregarCartas(cartas, "As de treboles");
	agregarCartas(cartas, "2 de treboles");
	agregarCartas(cartas, "3 de treboles");
	agregarCartas(cartas, "4 de treboles");
	agregarCartas(cartas, "5 de treboles");
	agregarCartas(cartas, "6 de treboles");
	agregarCartas(cartas, "7 de treboles");
	agregarCartas(cartas, "8 de treboles");
	agregarCartas(cartas, "9 de treboles");
	agregarCartas(cartas, "10 de treboles");
	agregarCartas(cartas, "J de treboles");
	agregarCartas(cartas, "Q de treboles");
	agregarCartas(cartas, "K de treboles");

	for(int i=0;i<=52;i++)
	{
		posiciones(baraja, i);	
	}


	return 0;
}
