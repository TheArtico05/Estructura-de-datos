#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Definición de nodo para el árbol
typedef struct Nodo {
    struct Nodo *izquierda;
    int hijosizquierdos;
    struct Nodo *padre;
    char info[10]; // Cambiado a cadena para soportar números grandes
    int hijosderechos;
    struct Nodo *derecha;
} Nodo;

// Función para crear un nuevo nodo
Nodo* nuevoNodo(const char* info) {
    Nodo *opc = (Nodo*)malloc(sizeof(Nodo));
    opc->izquierda = NULL;
    opc->derecha = NULL;
    opc->padre = NULL;
    opc->hijosizquierdos = 0;
    opc->hijosderechos = 0;
    strcpy(opc->info, info);
    return opc;
}

// Definición de estructura para el árbol
typedef struct Arbolito {
    int cantIzq;
    int cantDer;
    Nodo *raiz;
} Arbolito;

// Función para inicializar el árbol
Arbolito* MiArbolito() {
    Arbolito *opc = (Arbolito*)malloc(sizeof(Arbolito));
    opc->raiz = NULL;
    opc->cantIzq = 0;
    opc->cantDer = 0;
    return opc;
}

// Función para verificar si el árbol está vacío
int Vacio(Arbolito *h) {
    return (h->raiz == NULL);
}

// Función para tokenizar la expresión (separar números y operadores)
char** tokenizarExpresion(char* expresion, int* cantidadTokens) {
    char** tokens = malloc(100 * sizeof(char*)); // Máximo 100 tokens
    *cantidadTokens = 0;

    int i = 0, len = strlen(expresion);
    while (i < len) {
        if (isdigit(expresion[i])) {
            // Leer número completo
            int inicio = i;
            while (i < len && isdigit(expresion[i])) {
                i++;
            }
            tokens[*cantidadTokens] = malloc((i - inicio + 1) * sizeof(char));
            strncpy(tokens[*cantidadTokens], &expresion[inicio], i - inicio);
            tokens[*cantidadTokens][i - inicio] = '\0';
            (*cantidadTokens)++;
        } else if (strchr("+-*/()", expresion[i])) {
            // Leer operador o paréntesis
            tokens[*cantidadTokens] = malloc(2 * sizeof(char));
            tokens[*cantidadTokens][0] = expresion[i];
            tokens[*cantidadTokens][1] = '\0';
            (*cantidadTokens)++;
            i++;
        } else {
            i++; // Ignorar espacios u otros caracteres
        }
    }
    return tokens;
}

// Función para construir el árbol a partir de tokens
Nodo* construirArbolConTokens(char** tokens, int inicio, int fin) {
    if (inicio > fin) return NULL;

    // Encontrar el operador principal con menor prioridad
    int nivelPrioridad = 0;
    int indicePrincipal = -1;
    for (int i = inicio; i <= fin; i++) {
        if (strcmp(tokens[i], "(") == 0) nivelPrioridad++;
        else if (strcmp(tokens[i], ")") == 0) nivelPrioridad--;
        else if (nivelPrioridad == 0 && (strcmp(tokens[i], "+") == 0 || strcmp(tokens[i], "-") == 0)) {
            indicePrincipal = i;
        } else if (nivelPrioridad == 0 && (strcmp(tokens[i], "*") == 0 || strcmp(tokens[i], "/") == 0)) {
            if (indicePrincipal == -1 || strcmp(tokens[indicePrincipal], "+") == 0 || strcmp(tokens[indicePrincipal], "-") == 0) {
                indicePrincipal = i;
            }
        }
    }

    // Si no se encuentra operador, es un operando
    if (indicePrincipal == -1) {
        if (strcmp(tokens[inicio], "(") == 0 && strcmp(tokens[fin], ")") == 0) {
            return construirArbolConTokens(tokens, inicio + 1, fin - 1);
        }
        return nuevoNodo(tokens[inicio]);
    }

    // Crear nodo para el operador principal
    Nodo *nodo = nuevoNodo(tokens[indicePrincipal]);
    nodo->izquierda = construirArbolConTokens(tokens, inicio, indicePrincipal - 1);
    nodo->derecha = construirArbolConTokens(tokens, indicePrincipal + 1, fin);

    return nodo;
}

// Funciones de recorrido
void recorrerInorden(Nodo *nodo) {
    if (nodo == NULL) return;
    recorrerInorden(nodo->izquierda);
    printf("%s ", nodo->info);
    recorrerInorden(nodo->derecha);
}

void recorrerPreorden(Nodo *nodo) {
    if (nodo == NULL) return;
    printf("%s ", nodo->info);
    recorrerPreorden(nodo->izquierda);
    recorrerPreorden(nodo->derecha);
}

void recorrerPostorden(Nodo *nodo) {
    if (nodo == NULL) return;
    recorrerPostorden(nodo->izquierda);
    recorrerPostorden(nodo->derecha);
    printf("%s ", nodo->info);
}

// Función para evaluar el árbol paso a paso
int evaluarArbol(Nodo *nodo) {
    if (nodo == NULL) return 0;

    // Si es una hoja, devuelve el valor numérico
    if (nodo->izquierda == NULL && nodo->derecha == NULL) {
        return atoi(nodo->info); // Convertir cadena a número
    }

    // Evaluar subárboles
    int izquierdo = evaluarArbol(nodo->izquierda);
    int derecho = evaluarArbol(nodo->derecha);

    // Realizar operación correspondiente
    printf("Evaluando: %d %s %d\n", izquierdo, nodo->info, derecho);
    if (strcmp(nodo->info, "+") == 0) return izquierdo + derecho;
    if (strcmp(nodo->info, "-") == 0) return izquierdo - derecho;
    if (strcmp(nodo->info, "*") == 0) return izquierdo * derecho;
    if (strcmp(nodo->info, "/") == 0) return izquierdo / derecho;

    return 0;
}

// Menú principal
int main() {
    char operacion[100];
    int opcion;

    do {
        printf("\n--- Men%c ---\n", 163);
        printf("1. Ingresar operaci%cn\n", 162);
        printf("2. Mostrar recorrido inorden\n");
        printf("3. Mostrar recorrido preorden\n");
        printf("4. Mostrar recorrido postorden\n");
        printf("5. Evaluar operaci%cn\n", 162);
        printf("6. Salir\n");
        printf("Selecciona una opci%cn: ", 162);
        scanf("%d", &opcion);

        static Arbolito *arbol = NULL; // Mantener referencia al árbol entre iteraciones

        switch (opcion) {
            case 1: {
                printf("Introduce la operaci%cn en notaci%cn infija: ", 162, 162);
                scanf("%s", operacion);
                arbol = MiArbolito();
                int cantidadTokens;
                char** tokens = tokenizarExpresion(operacion, &cantidadTokens);
                arbol->raiz = construirArbolConTokens(tokens, 0, cantidadTokens - 1);
                printf("Operación cargada con %cxito.\n", 130);
                break;
            }
            case 2:
                if (arbol == NULL || Vacio(arbol)) {
                    printf("No hay operaci%cn cargada.\n", 162);
                } else {
                    printf("Recorrido inorden: ");
                    recorrerInorden(arbol->raiz);
                    printf("\n");
                }
                break;

            case 3:
                if (arbol == NULL || Vacio(arbol)) {
                    printf("No hay operaci%cn cargada.\n", 162);
                } else {
                    printf("Recorrido preorden: ");
                    recorrerPreorden(arbol->raiz);
                    printf("\n");
                }
                break;

            case 4:
                if (arbol == NULL || Vacio(arbol)) {
                    printf("No hay operaci%cn cargada.\n", 162);
                } else {
                    printf("Recorrido postorden: ");
recorrerPostorden(arbol->raiz);
printf("\n");
}
break;

case 5:
if (arbol == NULL || Vacio(arbol)) {
printf("No hay operaci%cn cargada.\n", 162);
} else {
printf("Resultado paso a paso:\n");
int resultado = evaluarArbol(arbol->raiz);
printf("Resultado final: %d\n", resultado);
}
break;

case 6:
printf("Saliendo del programa.\n");
break;

default:
printf("Opci%cn no v%clida.\n", 162, 160);
}
} while (opcion != 6);

return 0;
}
