#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Estructura que representa una carta*/
struct Carta
{
	int valor; //Para saber que carta es: de el 1 al 13 
	char palo; // ♥ = C, ♦ = D, ♣ = T y ♠ = E
};

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

/* Orden de turnos y Jugadores */
struct Lista
{
	char nombre[50];
    int apuesta;
    int estado;                 		// 0 = In Game 1 = Game Over
    struct Carta *lista_de_cartas[10];
	struct Lista *siguiente;
};

/*Funciones que tienen datos que se ocuparan en la pila*/
struct Carta* PilaR(struct Carta *ArregloPila[]);
struct Carta* CrearPila(struct Carta *ArregloPila[]);
void CrearYAnadir(struct Pila **Pila);

/*Funciones para la pila*/
int push(struct Pila **Pila, struct Carta *carta);
struct Pila* pop(struct Pila **Pila);
void mostrarPila(struct Pila *Pila);  

/*Funciones de la Lista*/
void pushLista(struct Lista **lista);
void popLista(struct Lista **lista,char nombre[]);
void mostrarLista(struct Lista *lista, int flg);
int tamanoLista(struct Lista *lista);

/*Otras funciones*/
void pushCrupier(struct Lista **lista);
void anadirjugadores(struct Lista **orden_turnos);
	
struct Carta* PilaR(struct Carta *ArregloPila[])
{
	struct Carta *aux;
	aux=(struct Carta*)malloc(sizeof(struct Carta));
	int random;
	srand(time(NULL));	

	for(int i=0; i<52; i++)
	{
		random=rand()%52;
		aux=ArregloPila[i];
		ArregloPila[i]=ArregloPila[random];
		ArregloPila[random]=aux;
	}
	
	return *ArregloPila;
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

void titulo(){
    // Pagar de 3 a 2 es pagar x1.5 el valor de tu apuesta
    // Pagar 2 a 1 es pagar x1 el valor de tu apuesta
    printf("--------------------------------------------\n");
    printf("|                 BLACKJACK                |\n");
    printf("|          Blackjack se paga 3 a 2         |\n");
    printf("|  Croupier pide en 16 y se planta en 17   |\n");
    printf("--------------------------------------------\n");
    printf("****           Se paga 2 a 1            ****\n\n");
}

void anadirjugadores(struct Lista **orden_turnos){
    system("cls");

    titulo();

    printf("Añadir jugadores\n");
    int stop=1;
    do{
        printf("Añade el nombre del nuevo jugador\n");
        pushLista(orden_turnos);
        printf("¿Añadir mas jugadores? [1 Si][0 No]\n");
        scanf("%d",&stop);
    }while(stop!=0);
}
void pushLista(struct Lista **lista){                           
    struct Lista* nuevo;                                  
    nuevo=(struct Lista*)malloc(sizeof(struct Lista));
    printf("Nombre: ");
    scanf("%s",nuevo->nombre);

    nuevo->apuesta=100;
    nuevo->estado=0;       
    nuevo->siguiente=NULL;     

    if(*lista==NULL){                                       
        *lista=nuevo;
        printf("Lista estaba vacia");              
        printf("Jugador %s anadido\n",nuevo->nombre);
    }else{                                                                                  
        struct Lista* sig=*lista;                                  
        struct Lista* actual=*lista;                                 
        
        while((sig!=NULL)){                                    
            actual=sig;
            sig=sig->siguiente;
        }
                                                            
        if(actual==sig){                                    
            nuevo->siguiente=*lista;                     
            *lista=nuevo;    
        }else{
            actual->siguiente=nuevo;                      
            nuevo->siguiente=sig;
        }
        printf("Jugador %s anadido\n",nuevo->nombre);
    }
}

void popLista(struct Lista **lista,char nombre[50]){
    if(*lista==NULL){
        printf("\nLista vacia");
    }else{
        struct Lista* sig=*lista;                                     
        struct Lista* actual=*lista;                                 
        
        while((sig!=NULL)&&((*lista)->nombre!=nombre)){              
            actual=sig;
            sig=sig->siguiente;
        }

        if(sig==NULL){                                              
            printf("\nEste jugador %s no esta jugando\n",nombre);
        }

        if(actual==sig){                                           
            *lista=sig->siguiente;
            printf("\nElemento %s eliminado\n",nombre);
        }else{                                                      
            actual->siguiente=sig->siguiente;
            printf("\nElemento %s eliminado\n",nombre);
        }
    }
}

void mostrarLista(struct Lista *lista, int flg){     
    if(flg==1){
        lista=lista->siguiente;
    }
    struct Lista* aux=lista;                                         
    if(lista==NULL){
        printf("\nLista vacia\n");
    }else{
        while(aux->siguiente!=NULL){                        
            printf("- %s\n",aux->nombre);
            aux=aux->siguiente;                            
        }
        printf("- %s\n",aux->nombre);                          
    }
}

int tamanoLista(struct Lista *lista){                                     
    struct Lista* aux=lista;                                         
    int pos=0;
    while(aux->siguiente!=NULL){                            
        aux=aux->siguiente;                                 
        pos++;
    }
    pos++;                                                  
    
    return pos;
}

void pushCrupier(struct Lista **lista){

   char banca[8]="Crupier";
   for(int i=0;i<7;i++){
       (*lista)->nombre[i]=banca[i];
   }
   (*lista)->apuesta=1000;
   (*lista)->estado=0;                                

   struct Lista* aux=*lista;
   *lista=(*lista)->siguiente;
   struct Lista* aux2=*lista;
   while(aux2->siguiente!=NULL){
       aux2=aux2->siguiente;
   }
   aux->siguiente=NULL;
   aux2->siguiente=aux;
}


int main()
{
	struct Pila *Pila=NULL;
	Pila=(struct Pila*)malloc(sizeof(struct Pila));
	Pila->siguiente=NULL;
	
	struct Lista *orden_turnos=NULL;                               
    orden_turnos=(struct Lista*)malloc(sizeof(struct Lista));

	CrearYAnadir(&Pila);	

    system("cls");

    titulo(); 

    anadirjugadores(&orden_turnos);

    printf("Comienza el juego\nLista de jugadores: \n");
    mostrarLista(orden_turnos,1);

    pushCrupier(&orden_turnos);

    /*Comienza el juego
        Fases del turno
        1° Se hacen apuestas
        2° Se reparten las cartas a todos
        3° Inician jugadores
            - Separa
            - Dobla
            - Pide o planta
        4° Juega el crupier
        5° Se pagan apuestas
    */

   /* 1° Se hacen apuestas */
    system("cls");
    titulo();
    printf("\nHagan sus apuestas\n");
    mostrarLista(orden_turnos,0);
    struct Lista *aux2=orden_turnos;
    int apuestas[tamanoLista(orden_turnos)-1];
    int pos=0;

    
    while(aux2->siguiente!=NULL){
        printf("\n%s tienes para apostar: %d creditos\n",aux2->nombre,aux2->apuesta);
        int flg=1;
        do{
                
                printf("¿Cuanto quieres apostar?\n");
                int apu_actual=0;
                scanf("%d",&apu_actual);
                if(apu_actual > aux2->apuesta){
                    printf("\nNo puedes apostar mas de lo que tienes.\n");
                    flg=1;
                }else{
                    flg=0;
                    apuestas[pos]=apu_actual;
                    aux2->apuesta=aux2->apuesta-apu_actual;
                    pos++;
                }
        }while(flg!=0);
        
        aux2=aux2->siguiente;
    }

    for(int i=0;i<tamanoLista(orden_turnos)-1;i++){
        printf("%d ",apuestas[i]);
    }

    /* 2° Se reparten las cartas a todos */
    system("cls");
    titulo();
    printf("\nReparticion de cartas\n");
    printf("Las cartas se repartieron asi de la siguiente forma\n\n");
    //mostrarPila(Pila);   

    struct Lista* aux5=orden_turnos;
    struct ListaCartas* mano;
    while(aux5->siguiente!=NULL){
        mano=NULL;
        struct Pila* carta=pop(&Pila);
        aux5->lista_de_cartas[0]=carta->carta;
        carta=pop(&Pila);
        aux5->lista_de_cartas[1]=carta->carta;
        aux5=aux5->siguiente;
    }
    mano = NULL;
    struct Pila* carta=pop(&Pila);                    
    aux5->lista_de_cartas[0]=carta->carta;
    carta=pop(&Pila);
    aux5->lista_de_cartas[1]=carta->carta;

    struct Lista* aux6=orden_turnos;
     while(aux6->siguiente!=NULL){
         printf("La mano de %s es: \n",aux6->nombre);
         struct Carta* mano=aux6->lista_de_cartas[0];
         printf("%d%c ",mano->valor,mano->palo);
         mano=aux6->lista_de_cartas[1];
         printf("%d%c \n\n",mano->valor,mano->palo);
         aux6=aux6->siguiente;
     }
     printf("La mano del %s es: \n",aux6->nombre);
    struct Carta* mano2=aux6->lista_de_cartas[0];
     printf("%d%c ",mano2->valor,mano2->palo);
     mano2=aux6->lista_de_cartas[1];
     printf("%d%c \n\n",mano2->valor,mano2->palo);
     char contin;
     printf("Presiona una tecla...\n");
     fflush(stdin);
     scanf("%c",&contin);

	/*3 Inician jugadores*/
	struct Lista* auxop=orden_turnos;
	int jug_act=0;
    int cartas_mano=2;
    int opcion=0;
    int parar = 1;
    int suma=0;

    while(auxop->siguiente!=NULL)
	{
    	system("cls");
        titulo();
        printf("\nComienza el juego\n\n ");

        printf("Es turno de %s\n",auxop->nombre);
        printf(" Mano actual\n");
        for(int i=0;i<cartas_mano;i++){
             printf(" %d%c",auxop->lista_de_cartas[i]->valor,auxop->lista_de_cartas[i]->palo);
         }
         printf("\n\n¿Que quieres hacer?\n\n 1. Doblar apuesta\n 2. Pedir carta\n 3. Plantarse\n\n Elige una opcion: ");
         opcion=0;
         parar=1;
         fflush(stdin);
         scanf("%d",&opcion);
         
         switch (opcion){
            case 1:
                    system("cls");
                    titulo();
                    printf("\nComienza el juego %s\n\n ",auxop->nombre);

                if(apuestas[jug_act]>auxop->apuesta){
                    printf("\nNo tienes creditos suficientes\n\n Creditos actuales: %d",auxop->apuesta);
                }else{
                    printf("\nHas doblado tu apuesta inicial, solo recibiras una carta mas.\n");
                    auxop->apuesta=auxop->apuesta-apuestas[jug_act];
                    apuestas[jug_act]=apuestas[jug_act]+apuestas[jug_act];
                    printf(" Creditos restantes: %d\n Nueva apuesta: %d\n\n",auxop->apuesta,apuestas[jug_act]);
                    struct Pila* carta=pop(&Pila);  
                    auxop->lista_de_cartas[cartas_mano]=carta->carta;
                    cartas_mano++; 
                    printf("Tu nueva mano es: %s\n",auxop->nombre);
                    suma=0;
                    for(int i=0;i<cartas_mano;i++){
                        int valor=auxop->lista_de_cartas[i]->valor;
                        if(valor>=10){
                            valor=10;
                        }
                        suma=suma+valor;
                        printf(" %d%c",auxop->lista_de_cartas[i]->valor,auxop->lista_de_cartas[i]->palo);
                    }
                    if(suma>21){
                        auxop->estado=1;
                        printf("\n\n  Game Over!  ");
                    }
                        printf("\n\nPresiona una tecla...\n");
                        fflush(stdin);
                        scanf("%c",&contin);
                    

                    
                    jug_act++;
                    cartas_mano=2;
                    suma=0;

                }
                break;
            case 2:
                system("cls");
                titulo();
                printf("\nComienza el juego %s\n\n ",auxop->nombre);
                
                printf("Pide las cartas que quieras\n");
                while(parar!=0){
                    struct Pila* carta=pop(&Pila);  
                    auxop->lista_de_cartas[cartas_mano]=carta->carta;
                    cartas_mano++; 
                    printf("Tu nueva mano es: %s\n",auxop->nombre);
                    suma=0;
                    for(int i=0;i<cartas_mano;i++){
                        int valor=auxop->lista_de_cartas[i]->valor;
                        if(valor>=10){
                            valor=10;
                        }
                        suma=suma+valor;
                        printf(" %d%c",auxop->lista_de_cartas[i]->valor,auxop->lista_de_cartas[i]->palo);
                    }

                    if(suma>21){
                        auxop->estado=1;
                        printf("\n\n  Game Over  ");
                        parar=0;
                    }else{
                        printf("\n\n¿Pedir otra? [1/Si] [0/Plantarse]\n");
                        fflush(stdin);
                        scanf("%d",&parar);
                    }
                }

                printf("\n\nPresiona una tecla...\n");
                fflush(stdin);
                scanf("%c",&contin);
                jug_act++;
                cartas_mano=2;
                parar=1;
                suma=0;
                break;
            case 3:
                system("cls");
                titulo();
                printf("\nTe has plantado %s\n\n ",auxop->nombre);
                    printf(" Tu mano es\n");
                    suma=0;
                    for(int i=0;i<cartas_mano;i++){
                        int valor=auxop->lista_de_cartas[i]->valor;
                        if(valor>=10){
                            valor=10;
                        }
                        suma=suma+valor;
                        printf(" %d%c",auxop->lista_de_cartas[i]->valor,auxop->lista_de_cartas[i]->palo);
                    }

                    if(suma>21){
                        auxop->estado=1;
                        printf("\n\n  Game Over  ");
                    }
                        printf("\n\nPresiona una tecla...\n");
                        fflush(stdin);
                        scanf("%c",&contin);
                    

                    jug_act++;
                    cartas_mano=2;
                    suma=0;
                break;
            default:
                break;
         }
         auxop=auxop->siguiente;
     }

	system("cls");
	titulo();
    printf("\n \n\n ");
     printf(" Es turno de %s \n",auxop->nombre);
     printf(" Su mano es \n");
     cartas_mano=2;
     suma=0;
            for(int i=0;i<cartas_mano;i++){
                suma=suma+auxop->lista_de_cartas[i]->valor;
                printf(" %d%c",auxop->lista_de_cartas[i]->valor,auxop->lista_de_cartas[i]->palo);
            }
            if(suma>21){
                auxop->estado=1;
                printf("\n\n  Game Over  ");
            }else{
                while(suma<=16){
                    printf("\n\n");
                    struct Pila* carta=pop(&Pila);  
                    auxop->lista_de_cartas[cartas_mano]=carta->carta;
                    cartas_mano++; 
                    printf(" Su nueva mano es: %s\n",auxop->nombre);
                    suma=0;
                    for(int i=0;i<cartas_mano;i++){
                        int valor=auxop->lista_de_cartas[i]->valor;
                        if(valor>=10){
                            valor=10;
                        }
                        suma=suma+valor;
                        printf(" %d%c",auxop->lista_de_cartas[i]->valor,auxop->lista_de_cartas[i]->palo);
                    }
                    
                }
                printf("\n\n");
            }

	/*4 Juega el crupier */

	/*5 Se pagan apuestas */


	return 0;
}


