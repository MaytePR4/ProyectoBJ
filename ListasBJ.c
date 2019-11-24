#include <stdio.h>
#include <stdlib.h>


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
    int estado;                 // 0 = In Game 1 = Game Over
    struct Carta* lista_de_cartas[10];
	struct Lista *siguiente;
};

int tamano(struct Lista *lista){                                     
                                                                       
    int pos=0;
    while(lista->siguiente!=NULL){                                        
        lista=lista->siguiente;                                             
        pos++;
    }
    pos++;                                                              
    
    return pos;
}

void titulo(){
    // Pagar de 3 a 2 es pagar x1.5 el valor de tu apuesta
    // Pagar 2 a 1 es pagar x1 el valor de tu apuesta
    printf("--------------------------------------------\n");
    printf("|             BLACKJACK ESCOM              |\n");
    printf("|          Blackjack se paga 3 a 2         |\n");
    printf("|  Croupier pide en 16 y se planta en 17   |\n");
    printf("--------------------------------------------\n");
    printf("****           Se paga 2 a 1            ****\n\n");
}

void anadirjugadores(struct Lista* orden_turnos){
    system("cls");

    titulo();

    printf("Anadir jugadores\n");
    int stop=1;
    do{
        printf("Anade el nombre del nuevo jugador\n");
        pushLista(orden_turnos);
        printf("Anadir mas jugadores? [1/Si][0/No]\n");
        scanf("%d",&stop);
    }while(stop!=0);
}
void pushLista(struct Lista* lista){                           
    struct Lista* nuevo;                                  
    nuevo=(struct Lista*)malloc(sizeof(struct Lista));
    printf("Nombre: ");
    scanf("%s",nuevo->nombre);

    nuevo->apuesta=100;
    nuevo->estado=0;       
    nuevo->siguiente=NULL;     

    if(lista==NULL){                                       
        lista=nuevo;
        printf("Lista estaba vacia");              
        printf("Jugador %s anadido\n",nuevo->nombre);
    }else{                                                                                  
        struct Lista* sig=lista;                                  
        struct Lista* actual=lista;                                 
        
        while((sig!=NULL)){                                    
            actual=sig;
            sig=sig->siguiente;
        }
                                                            
        if(actual==sig){                                    
            nuevo->siguiente=lista;                     
            lista=nuevo;    
        }else{
            actual->siguiente=nuevo;                      
            nuevo->siguiente=sig;
        }
        printf("Jugador %s anadido\n",nuevo->nombre);
    }
}

void popLista(struct Lista* lista,char nombre[50]){
    if(lista==NULL){
        printf("\nLista vacia");
    }else{
        struct Lista* sig=lista;                                     
        struct Lista* actual=lista;                                 
        
        while((sig!=NULL)&&(lista->nombre!=nombre)){              
            actual=sig;
            sig=sig->siguiente;
        }

        if(sig==NULL){                                              
            printf("\nEste jugador %s no esta jugando\n",nombre);
        }

        if(actual==sig){                                           
            lista=sig->siguiente;
            printf("\nElemento %s eliminado\n",nombre);
        }else{                                                      
            actual->siguiente=sig->siguiente;
            printf("\nElemento %s eliminado\n",nombre);
        }
    }
}

void mostrarLista(struct Lista* lista, int flg){     
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

int tamanoLista(struct Lista* lista){                                     
    struct Lista* aux=lista;                                         
    int pos=0;
    while(aux->siguiente!=NULL){                            
        aux=aux->siguiente;                                 
        pos++;
    }
    pos++;                                                  
    
    return pos;
}

void pushCrupier(struct Lista* lista){

   char banca[8]="Crupier";
   for(int i=0;i<7;i++){
       lista->nombre[i]=banca[i];
   }
   lista->apuesta=1000;
   lista->estado=0;                                          
   //printf("Jugador %s anadido\n",lista->nombre);

   struct Lista* aux=lista;
   lista=lista->siguiente;
   struct Lista* aux2=lista;
   while(aux2->siguiente!=NULL){
       aux2=aux2->siguiente;
   }
   aux->siguiente=NULL;
   aux2->siguiente=aux;
}

int main ()
{
    struct Lista *orden_turnos=NULL;                               
    orden_turnos=(struct Lista*)malloc(sizeof(struct Lista));
    system("cls");

    titulo(); 

    anadirjugadores(orden_turnos);
}

