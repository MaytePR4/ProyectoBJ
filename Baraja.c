#include <stdio.h>
#include <stdlib.h>

struct Baraja
{
	char carta[30];
	int cima;
};

int cartas(struct Baraja *baraja, char carta[])
{
	baraja->carta[baraja->cima]=carta;
	baraja->cima++;
}

void barajeo(struct Baraja *baraja)
{
	int *temporal, posicion=0;
	
	temporal=(struct Baraja*)malloc(sizeof(struct Baraja));

	for(int i=0;i<=52;i++)
	{
		posicion=ran()%53;
		*(temporal + posicion)=*(baraja->carta + i);
	}

	free(baraja->carta);
	baraja->carta=temporal;
}

void repartir(struct Baraja *baraja)
{
	printf("%s ", baraja->carta[baraja->cima]);
	baraja->cima--;
}

int main()
{
	struct Baraja *baraja=NULL;
	baraja=(struct Baraja*)malloc(sizeof(struct Baraja));

	baraja->cima=0;  

	cartas(baraja, "As de picas");
	cartas(baraja, "2 de picas");
	cartas(baraja, "3 de picas");
	cartas(baraja, "4 de picas");
	cartas(baraja, "5 de picas");
	cartas(baraja, "6 de picas");
	cartas(baraja, "7 de picas");
	cartas(baraja, "8 de picas");
	cartas(baraja, "9 de picas");
	cartas(baraja, "10 de picas");
	cartas(baraja, "J de picas");
	cartas(baraja, "Q de picas");
	cartas(baraja, "K de picas");
	cartas(baraja, "As de corazones");
	cartas(baraja, "2 de corazones");
	cartas(baraja, "3 de corazones");
	cartas(baraja, "4 de corazones");
	cartas(baraja, "5 de corazones");
	cartas(baraja, "6 de corazones");
	cartas(baraja, "7 de corazones");
	cartas(baraja, "8 de corazones");
	cartas(baraja, "9 de corazones");
	cartas(baraja, "10 de corazones");
	cartas(baraja, "J de corazones");
	cartas(baraja, "Q de corazones");
	cartas(baraja, "K de corazones");
	cartas(baraja, "As de diamantes");
	cartas(baraja, "2 de diamantes");
	cartas(baraja, "3 de diamantes");
	cartas(baraja, "4 de diamantes");
	cartas(baraja, "5 de diamantes");
	cartas(baraja, "6 de diamantes");
	cartas(baraja, "7 de diamantes");
	cartas(baraja, "8 de diamantes");
	cartas(baraja, "9 de diamantes");
	cartas(baraja, "10 de diamantes");
	cartas(baraja, "J de diamantes");
	cartas(baraja, "Q de diamantes");
	cartas(baraja, "K de diamantes");
	cartas(baraja, "As de treboles");
	cartas(baraja, "2 de treboles");
	cartas(baraja, "3 de treboles");
	cartas(baraja, "4 de treboles");
	cartas(baraja, "5 de treboles");
	cartas(baraja, "6 de treboles");
	cartas(baraja, "7 de treboles");
	cartas(baraja, "8 de treboles");
	cartas(baraja, "9 de treboles");
	cartas(baraja, "10 de treboles");
	cartas(baraja, "J de treboles");
	cartas(baraja, "Q de treboles");
	cartas(baraja, "K de treboles");


	return 0;
}
