int main ()
{
    struct Pila *Pila=NULL;                                        
	Pila=(struct Pila*)malloc(sizeof(struct Pila));              
	Pila->siguiente=NULL;                                             

    struct Lista *orden_turnos=NULL;                               
    orden_turnos=(struct Lista*)malloc(sizeof(struct Lista));   

    Crear_Pilar_Y_Anadir(&Pila);   

    system("cls");

    titulo(); 

    anadirjugadores(orden_turnos);

    int control=0;
    do{
        system("cls");
        titulo();
        printf("Comienza el juego!\nLista de jugadores: \n");
        mostrarLista(orden_turnos,1);
        printf("\nEmpezar o anadir otro jugador? [0 Empezar][1 Anadir jugador]\n");
        int op=0;
        scanf("%d",&op);
        switch (op)
        {
        case 0:
            control=1;
            break;
        case 1:
            anadirjugadores(orden_turnos);
            break;
        default:
            break;
        }

    }while(control==0);

    pushCrupier(orden_turnos);

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
                
                printf("Cuanto quieres apostar?\n");
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
    printf("Las cartas se repartieron asi de la siguete forma.\n\n");
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

     struct Lista* aux7=orden_turnos;
     int jug_act=0;
     int cartas_mano=2;
     int opcion=0;
     int parar = 1;
     int suma=0;

     /* aqui va el switch
     *
     *
     *
     *
     *
     *
     **
     *
     *
     *
     *
     *
     **
     *
     *
     *
     *
     **
     *
     *
     *
     *
     *
     *
     */

     system("cls");
    titulo();
    printf("\n \n\n ");
     printf(" Es turno del %s \n",aux7->nombre);
     printf(" Su mano es\n");
     cartas_mano=2;
     suma=0;
            for(int i=0;i<cartas_mano;i++){
                suma=suma+aux7->lista_de_cartas[i]->valor;
                printf(" %d%c",aux7->lista_de_cartas[i]->valor,aux7->lista_de_cartas[i]->palo);
            }
            if(suma>21){
                aux7->estado=1;
                printf("\n\n  Game Over!  ");
            }else{
                while(suma<=16){
                    printf("\n\n");
                    struct Pila* carta=pop(&Pila);  
                    aux7->lista_de_cartas[cartas_mano]=carta->carta;
                    cartas_mano++; 
                    printf(" Su nueva mano es: \n",aux7->nombre);
                    suma=0;
                    for(int i=0;i<cartas_mano;i++){
                        int valor=aux7->lista_de_cartas[i]->valor;
                        if(valor>=10){
                            valor=10;
                        }
                        suma=suma+valor;
                        printf(" %d%c",aux7->lista_de_cartas[i]->valor,aux7->lista_de_cartas[i]->palo);
                    }
                    
                }
                printf("\n\n");
            }




    return 0;
}