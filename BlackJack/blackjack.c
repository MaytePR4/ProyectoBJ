#include "blackjack.h"

struct Carta *
PilaR (struct Carta *ArregloPila[])
{
  struct Carta *aux;
  aux = (struct Carta *) malloc (sizeof (struct Carta));
  int random;
  srand (time (NULL));

  for (int i = 0; i < 52; i++)
    {
      random = rand () % 52;
      aux = ArregloPila[i];
      ArregloPila[i] = ArregloPila[random];
      ArregloPila[random] = aux;
    }

  return *ArregloPila;
}

struct Carta *
CrearPila (struct Carta *ArregloPila[])
{
  int indice = 0;

  for (int i = 0; i < 4; i++)
    {
      for (int j = 0; j < 13; j++)
	{
	  /*Crea la carta */
	  struct Carta *carta = NULL;
	  carta = (struct Carta *) malloc (sizeof (struct Carta));

	  /*Asigna el valor a la carta */
	  carta->valor = j + 1;

	  /*Asigna el palo a la carta */
	  switch (i)
	    {
	    case 0:
	      carta->palo = 'C';
	      break;
	    case 1:
	      carta->palo = 'D';
	      break;
	    case 2:
	      carta->palo = 'T';
	      break;
	    case 3:
	      carta->palo = 'E';
	      break;
	    default:
	      break;
	    }

	  ArregloPila[indice] = carta;
	  indice++;
	}
    }

  return *ArregloPila;
}

void
CrearYAnadir (struct Pila **Pila)
{
  struct Carta *ArregloPila[52];

  *ArregloPila = CrearPila (ArregloPila);
  *ArregloPila = PilaR (ArregloPila);

  for (int i = 0; i < 52; i++)
    {
      push (Pila, ArregloPila[i]);
    }
}

int
push (struct Pila **Pila, struct Carta *carta)
{
  struct Pila *nuevo = NULL;

  nuevo = (struct Pila *) malloc (sizeof (struct Pila));

  if (nuevo == NULL)
    {
      return -1;
    }

  nuevo->carta = carta;
  nuevo->siguiente = *Pila;
  *Pila = nuevo;

  return 0;
}

struct Pila *
pop (struct Pila **Pila)
{
  struct Pila *aux = NULL;
  aux = *Pila;

  if (*Pila == NULL)
    {
      return NULL;
    }
  else
    {
      *Pila = aux->siguiente;
      return aux;
    }
}

void
titulo ()
{
  // Pagar de 3 a 2 es pagar x1.5 el valor de tu apuesta
  // Pagar 2 a 1 es pagar x1 el valor de tu apuesta
  printf ("--------------------------------------------\n");
  printf ("|                 BLACKJACK                |\n");
  printf ("|          Blackjack se paga 3 a 2         |\n");
  printf ("|  Croupier pide en 16 y se planta en 17   |\n");
  printf ("--------------------------------------------\n");
  printf ("****           Se paga 2 a 1            ****\n\n");
}

void
anadirjugadores (struct Lista **orden_turnos)
{
  system ("clear");

  titulo ();

  printf ("Añadir jugadores\n");
  int stop = 1;
  do
    {
      printf ("Añade el nombre del nuevo jugador\n");
      pushLista (orden_turnos);
      printf ("¿Añadir mas jugadores? [1 Si][0 No]\n");
      scanf ("%d", &stop);
    }
  while (stop != 0);
}

void
pushLista (struct Lista **lista)
{
  struct Lista *nuevo;
  nuevo = (struct Lista *) malloc (sizeof (struct Lista));
  printf ("Nombre: ");
  scanf ("%s", nuevo->nombre);

  nuevo->apuesta = 100;
  nuevo->estado = 0;
  nuevo->siguiente = NULL;

  if (*lista == NULL)
    {
      *lista = nuevo;
      printf ("Lista estaba vacia");
      printf ("Jugador %s anadido\n", nuevo->nombre);
    }
  else
    {
      struct Lista *sig = *lista;
      struct Lista *actual = *lista;

      while ((sig != NULL))
	{
	  actual = sig;
	  sig = sig->siguiente;
	}

      if (actual == sig)
	{
	  nuevo->siguiente = *lista;
	  *lista = nuevo;
	}
      else
	{
	  actual->siguiente = nuevo;
	  nuevo->siguiente = sig;
	}
      printf ("Jugador %s anadido\n", nuevo->nombre);
    }
}

void
popLista (struct Lista **lista, char nombre[50])
{
  if (*lista == NULL)
    {
      printf ("\nLista vacia");
    }
  else
    {
      struct Lista *sig = *lista;
      struct Lista *actual = *lista;

      while ((sig != NULL) && ((*lista)->nombre != nombre))
	{
	  actual = sig;
	  sig = sig->siguiente;
	}

      if (sig == NULL)
	{
	  printf ("\nEste jugador %s no esta jugando\n", nombre);
	}

      if (actual == sig)
	{
	  *lista = sig->siguiente;
	  printf ("\nElemento %s eliminado\n", nombre);
	}
      else
	{
	  actual->siguiente = sig->siguiente;
	  printf ("\nElemento %s eliminado\n", nombre);
	}
    }
}

void
mostrarLista (struct Lista *lista, int flg)
{
  if (flg == 1)
    {
      lista = lista->siguiente;
    }
  struct Lista *aux = lista;
  if (lista == NULL)
    {
      printf ("\nLista vacia\n");
    }
  else
    {
      while (aux->siguiente != NULL)
	{
	  printf ("- %s\n", aux->nombre);
	  aux = aux->siguiente;
	}
      printf ("- %s\n", aux->nombre);
    }
}

int
tamanoLista (struct Lista *lista)
{
  struct Lista *aux = lista;
  int pos = 0;
  while (aux->siguiente != NULL)
    {
      aux = aux->siguiente;
      pos++;
    }
  pos++;

  return pos;
}

void
imprimirCartas (int valor, char palo)
{
  if (valor > 10)
    {
      switch (valor)
	{
	case 11:
	  printf (" J%c", palo);
	  break;
	case 12:
	  printf (" Q%c", palo);
	  break;
	case 13:
	  printf (" K%c", palo);
	  break;
	case 15:
	  printf (" X");
	}
    }
  else
    {
      printf (" %d%c ", valor, palo);
    }

}

void
pushCrupier (struct Lista **lista)
{

  char banca[8] = "Crupier";
  for (int i = 0; i < 7; i++)
    {
      (*lista)->nombre[i] = banca[i];
    }
  (*lista)->apuesta = 1000;
  (*lista)->estado = 0;

  struct Lista *aux = *lista;
  *lista = (*lista)->siguiente;
  struct Lista *aux2 = *lista;
  while (aux2->siguiente != NULL)
    {
      aux2 = aux2->siguiente;
    }
  aux->siguiente = NULL;
  aux2->siguiente = aux;
}

