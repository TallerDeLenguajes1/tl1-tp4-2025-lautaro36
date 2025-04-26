#include <stdio.h>
#include <stdlib.h>

struct {
    int TareaID;//Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion; // entre 10 – 100
    }typedef Tarea;

struct Nodo {
    Tarea T;
    struct Nodo *Siguiente;
    }typedef Nodo;

Tarea cargarTarea();
Nodo *crearNodo(Tarea tarea);
void insertarNodo(Nodo **start, Nodo *tarea);
Nodo *buscarNodo(Nodo **start, int id);
void quitarNodo(Nodo **start, Nodo *nodo);

int tareasId = 1000;

int main() {
    char bandera='s';
    Tarea nuevaTarea;
    Nodo *start = NULL;

    printf("Ingrese una nueva tarea\n");
    
    while(bandera == 'S' || bandera == 's') {
        nuevaTarea = cargarTarea();
        insertarNodo(&start, crearNodo(nuevaTarea));
        printf("Desea ingresar otra tarea? S/N \n");
        scanf(" %c", &bandera);
    }

    Nodo *startRealizadas = NULL;
    int idRealizada;
    puts("pasar alguna tarea pendiente a la lista de realizadas ?S/N");
    scanf(" %c", &bandera);
    while(bandera == 'S' || bandera == 's') {
        puts("Ingrese el ID de la tarea realizada.");
        scanf("%d", &idRealizada);
        insertarNodo(&startRealizadas, buscarNodo(&start, idRealizada));
    }

    /*Nodo *aux = start;
    while(aux->Siguiente) {
        aux = aux->Siguiente;
        printf("\nTarea %d: %s\tDuracion:%d", aux->T.TareaID, aux->T.Descripcion, aux->T.Duracion);
    } muestro por pantalla
    */

    /*if(buscarNodo(&start, idRealizada)) 
    printf("\nTarea %d: %s\tDuracion:%d",buscarNodo(&start, idRealizada)->T.TareaID, buscarNodo(&start, idRealizada)->T.Descripcion, buscarNodo(&start, idRealizada)->T.Duracion);
    muestro por pantalla buscar nodo*/ 

    return 0;
}

Tarea cargarTarea() {
    Tarea nuevaTarea;
    nuevaTarea.Descripcion = (char *) malloc (sizeof(char)*100);
    printf("Ingrese una descripcion de la tarea:");
    fflush(stdin);
    gets(nuevaTarea.Descripcion);
    
    printf("Ingrese una duracion de la tarea:");
    scanf("%d", &nuevaTarea.Duracion);
    fflush(stdin);
    
    nuevaTarea.TareaID = tareasId;
    tareasId++;

    return nuevaTarea;
}

Nodo *crearNodo(Tarea nuevaTarea) {
    Nodo *nuevoNodo = (Nodo *) malloc(sizeof(Nodo));
    nuevoNodo->T = nuevaTarea;
    nuevoNodo->Siguiente = NULL;
    return nuevoNodo;
}

void insertarNodo(Nodo **start, Nodo *nuevaTarea) {
    nuevaTarea->Siguiente = *start;
    *start = nuevaTarea;
}

Nodo *buscarNodo(Nodo **start, int id) {
    Nodo **aux = start;
    while(aux && (*aux)->T.TareaID != id){
        *aux = (*aux)->Siguiente;
    }
    return *aux;
}

void quitarNodo(Nodo **start, Nodo *nodo) {
    Nodo **aux = start;

    if(*aux) {

    }

}
