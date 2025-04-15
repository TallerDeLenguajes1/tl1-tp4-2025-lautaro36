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
void instertarNodo(Nodo **primerTarea, Nodo *tarea);

int main() {
    char bandera;
    Tarea nuevaTarea;
    Nodo *primerTarea = NULL;

    printf("Desea ingresar una tarea? S/N \n");
    scanf(" %c", &bandera);

    while(bandera == 'S' || bandera == 's') {
        nuevaTarea = cargarTarea();
        instertarNodo(&primerTarea, crearNodo(nuevaTarea));
        printf("Desea ingresar otra tarea? S/N \n");
        scanf(" %c", &bandera);
    }

    return 0;
}

Tarea cargarTarea() {
    Tarea nuevaTarea;
    nuevaTarea.Descripcion = (char *) malloc (sizeof(char)*100);
    printf("Ingrese una descripcion de la tarea:");
    scanf("%s", &nuevaTarea.Descripcion);
    
    printf("Ingrese una duracion de la tarea:");
    scanf("%d", &nuevaTarea.Duracion);
    
    if(nuevaTarea.TareaID != 1000) {
        nuevaTarea.TareaID = rand() %999 + 1;
    } else {
        nuevaTarea.TareaID++;
    }

    return nuevaTarea;
}

Nodo *crearNodo(Tarea nuevaTarea) {
    Nodo *nuevoNodo = (Nodo *) malloc(sizeof(Nodo));
    nuevoNodo->T = nuevaTarea;
    nuevoNodo->Siguiente = NULL;
    return nuevoNodo;
}

void instertarNodo(Nodo **primerTarea, Nodo *nuevaTarea) {
    nuevaTarea->Siguiente = *primerTarea;
    *primerTarea = nuevaTarea;
}
