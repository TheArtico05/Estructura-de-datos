#include <stdio.h>
#include <stdlib.h>
typedef struct Nodo{
    struct Nodo *izquierda;
    int hijosizquierdos;
    struct Nodo *padre;
    int info;
    int hijosderechos;
    struct Nodo *derecha;
}Nodo;

Nodo* nuevoNodo(int info){
    Nodo *opc=(Nodo*)malloc(sizeof(Nodo));
    opc->izquierda=NULL;
    opc->derecha=NULL;
    opc->padre=NULL;
    opc->hijosizquierdos=0;
    opc->hijosderechos=0;
    opc->info=info;
    return opc;
}

typedef struct arbolito{
int cantIzq;
int cantDer;
Nodo *raiz;
}Arbolito;

Arbolito* MiArbolito(){
    Arbolito *opc=(Arbolito*)malloc(sizeof(Arbolito));
    opc->raiz=NULL;
    
    opc->cantIzq=0;
    opc->cantDer=0;
    return opc;
}

int Vacio(Arbolito *h){
    if(h->raiz=NULL){
        return 1;
    }else{
        return 0;
    }
}

void insertaNodo(Arbolito *h,Nodo *n){
    Nodo *opc, *prev;
    if(Vacio(h)){
        h->raiz=n;
    }else{
        opc=h->raiz;
        while(opc!=NULL){
        prev=opc;
            if(n->info > opc->info){
                opc=opc->derecha;
            }else{
                opc=opc->izquierda;
            }
        }
        n->padre=prev;
        if(n->info > opc->info){
                opc=opc->derecha;
            }else{
                opc=opc->izquierda;
            }
    }
}

int main()
{
    // Cambiar el tipo de dato a una cadena para capturar la operación
    char operacion[100]; // Tamaño suficiente para almacenar la operación ingresada

    // Solicitar al usuario que ingrese una operación
    printf("Introduce la operación a resolver: ");
    
    // Leer la operación ingresada como una cadena
    scanf("%99s", operacion); // %99s evita desbordamientos (máximo 99 caracteres + 1 para '\0')

    // Mostrar lo que el usuario ingresó
    printf("La operación ingresada es: %s\n", operacion);

    return 0;
}