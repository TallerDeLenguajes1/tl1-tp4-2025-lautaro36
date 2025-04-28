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
void mostrarNodos(Nodo *nodo, char *texto);
Nodo *quitarNodo(Nodo **lista, int id);
void eliminarNodo(Nodo *nodo);
void interfaz(int *opcion);
void otraIteracion(int *bandera, char *texto);

int tareasId = 1000;

int main() {
    int bandera=1, opcion;
    Nodo *lista = NULL, *listaRealizadas = NULL;

    while(bandera) {
        interfaz(&opcion);
        switch (opcion) {
        case 0:
            int banderaCase0=1;
            while(banderaCase0) {
                insertarNodo(&lista, crearNodo(cargarTarea() ));
                otraIteracion(&banderaCase0, "Desea cargar otra tarea?");
            }
            otraIteracion(&bandera, "Desea realizar otra operacion");
            break;
        case 1:
            int id;
            puts("Ingrese el ID de la tarea que sera transferida");
            scanf("%d", &id);
            Nodo *nodoQuitado = quitarNodo(&lista, id);
            insertarNodo(&listaRealizadas, nodoQuitado);
            eliminarNodo(nodoQuitado);
            otraIteracion(&bandera, "Desea realizar otra operacion?");
            break;
        case 2:
        mostrarNodos(lista, "\n ---Lista pendientes: ---");
        mostrarNodos(listaRealizadas, "\n ---Lista realizadas: ---");
        otraIteracion(&bandera, "Desea realizar otra operacion?");
            break;
        case 3:
            
        break;
        case 4:
        }
    }

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
        aux = &(*aux)->Siguiente;
    }
    return *aux;
}

//Nodo *quitarNodo(Nodo *lista) {
Nodo *quitarNodo(Nodo **lista, int id) {
//como hago para hquitar usando la fn buscar
    Nodo **aux = lista;
    while(*aux && (*aux)->T.TareaID != id) {
        aux = &(*aux)->Siguiente;
    }

    if(*aux) {
        Nodo *temp = *aux;
        *aux = (*aux)->Siguiente;
        temp->Siguiente = NULL;
        return temp;
    }
    /*if(nodo) {
        Nodo *temp = nodo;
        nodo = nodo->Siguiente;
        temp->Siguiente = NULL;
        return temp;
    }*/
    return NULL;
}

void mostrarNodos(Nodo *lista, char *texto) {
    printf("%s", texto);
    while(lista) {
        printf("\nTarea %d: %s\tDuracion:%d", lista->T.TareaID, lista->T.Descripcion, lista->T.Duracion);
        lista = lista->Siguiente;
    }
}

void eliminarNodo(Nodo *nodo) {
    free(nodo);
}

void interfaz(int *opcion) {
    int valor;
        printf("-----------Bienvenido-----------\n");
        printf("Digite una de las siguentes opciones\n");
        printf("0. Crear tarea\n");
        printf("1. Cambiar estado de la tarea\n");
        printf("2. Listar tareas.\n");
        printf("3. Buscar tarea por ID\n");
        printf("4. Buscar tarea por palabra clave\n");
        printf("5. Salir\n");

        scanf("%d", &valor);
        *opcion = valor;
} 

void otraIteracion(int *bandera, char *texto) {
    int opcion;
    printf("\n%s", texto);
    printf("\n 0. No.");
    printf("\n 1. Si.\n");
    scanf("%d", &opcion);

    *bandera=opcion;
}

