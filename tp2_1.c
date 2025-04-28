#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
Nodo *crearNodo(Tarea nuevaTarea);
void insertarNodo(Nodo **lista, Nodo *nuevoNodo);
Nodo *buscarNodo(Nodo **lista, int id);
Nodo *quitarNodo(Nodo *nodo);
void mostrarNodos(Nodo *lista);

int tareasId = 1000;

int main() {
    char bandera='s';
    Nodo *lista = NULL;
    while(bandera == 'S' || bandera == 's') {
        insertarNodo(&lista, crearNodo(cargarTarea() ));
        printf("Desea ingresar otra tarea? S/N \n");
        scanf(" %c", &bandera);
    }
    mostrarNodos(lista);

    /*if(buscarNodo(&start, idRealizada)) 
    printf("\nTarea %d: %s\tDuracion:%d",buscarNodo(&start, idRealizada)->T.TareaID, buscarNodo(&start, idRealizada)->T.Descripcion, buscarNodo(&start, idRealizada)->T.Duracion);
    muestro por pantalla buscar nodo*/ 

    return 0;
}

Tarea cargarTarea() {
    char *buff;
    Tarea nuevaTarea;
    buff = (char *) malloc (sizeof(char)*100);
    printf("Ingrese una descripcion de la tarea:");
    scanf("%s", buff);
    nuevaTarea.Descripcion = (char *) malloc (sizeof(char)*(strlen(buff)) +1);
    strcpy(nuevaTarea.Descripcion, buff);
    
    printf("Ingrese una duracion de la tarea:");
    scanf("%d", &nuevaTarea.Duracion);
    
    nuevaTarea.TareaID = tareasId;
    tareasId++;

    return nuevaTarea;
}

Nodo *crearNodo(Tarea nuevaTarea) {
    Nodo *nuevoNodo = (Nodo *) malloc(sizeof(Nodo));
    nuevoNodo->T.Descripcion = (char *) malloc (sizeof(char)*(strlen(nuevaTarea.Descripcion)) +1);
    strcpy(nuevoNodo->T.Descripcion, nuevaTarea.Descripcion);
    nuevoNodo->T.Duracion = nuevaTarea.Duracion;
    nuevoNodo->T.TareaID = nuevaTarea.TareaID;
    nuevoNodo->Siguiente = NULL;
    return nuevoNodo;
}

void insertarNodo(Nodo **lista, Nodo *nuevoNodo) {
    nuevoNodo->Siguiente = *lista;
    *lista = nuevoNodo;
}

Nodo *buscarNodo(Nodo **lista, int id) {
    Nodo **aux = lista;
    while(aux && (*aux)->T.TareaID != id){
        *aux = (*aux)->Siguiente;
    }
    return *aux;
}

Nodo *quitarNodo(Nodo *nodo) {
    if(nodo) {
        Nodo *temp = nodo;
        nodo = nodo->Siguiente;
        temp->Siguiente = NULL;
        return temp;
    }
    return NULL;
}

void mostrarNodos(Nodo *lista) {
    while(lista) {
        printf("\nTarea %d: %s\tDuracion:%d", lista->T.TareaID, lista->T.Descripcion, lista->T.Duracion);
        lista = lista->Siguiente;
    }
}