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
void instertarNodo(Nodo **start, Nodo *tarea);

int tareasId = 1000;

int main() {
    char bandera='s';
    Tarea nuevaTarea;
    Nodo *start = NULL;

    printf("Ingrese una nueva tarea\n");
    
    while(bandera == 'S' || bandera == 's') {
        nuevaTarea = cargarTarea();
        instertarNodo(&start, crearNodo(nuevaTarea));
        printf("Desea ingresar otra tarea? S/N \n");
        scanf(" %c", &bandera);
    }

    /*Nodo *aux = start;
    while(aux->Siguiente) {
        aux = aux->Siguiente;
        printf("\nTarea %d: %s\tDuracion:%d", aux->T.TareaID, aux->T.Descripcion, aux->T.Duracion);
    } muestro por pantalla
    */

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

void instertarNodo(Nodo **start, Nodo *nuevaTarea) {
    nuevaTarea->Siguiente = *start;
    *start = nuevaTarea;
}
