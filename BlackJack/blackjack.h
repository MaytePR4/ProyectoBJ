#ifndef _Blackjack_
#define _Blackjack_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Estructura que representa una carta*/
struct Carta
{
  int valor;			//Para saber que carta es: de el 1 al 13 
  char palo;			// ♥ = C, ♦ = D, ♣ = T y ♠ = E
};

struct Pila
{
  struct Carta *carta;
  struct Pila *siguiente;
};

/*Cartas a repartir para cada jugador*/
struct ListaCartas
{
  struct Carta *carta;
  struct ListaCartas *siguiente;
};

/* Orden de turnos y Jugadores */
struct Lista
{
  char nombre[50];
  int apuesta;
  int estado;			// 0 = En juego 1 = Game Over
  int valor;
  struct Carta *lista_de_cartas[10];
  struct Lista *siguiente;
};

/*Funciones que tienen datos que se ocuparan en la pila*/
struct Carta *PilaR (struct Carta *[]);
struct Carta *CrearPila (struct Carta *[]);
void CrearYAnadir (struct Pila **);

/*Funciones para la pila*/
int push (struct Pila **, struct Carta *);
struct Pila *pop (struct Pila **);

/*Funciones de la Lista*/
void pushLista (struct Lista **);
void popLista (struct Lista **, char []);
void mostrarLista (struct Lista *, int);
int tamanoLista (struct Lista *);

/*Otras funciones*/
void pushCrupier (struct Lista **);
void anadirjugadores (struct Lista **);
void titulo ();
void imprimirCartas (int , char);

#endif

