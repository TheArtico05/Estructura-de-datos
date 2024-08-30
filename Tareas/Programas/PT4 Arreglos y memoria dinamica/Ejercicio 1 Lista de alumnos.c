#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRE 25

typedef struct {
    char nombre[MAX_NOMBRE];
    int edad;
    int calificacion;
} Alumno;

int main() {
    int num_alumnos;
    Alumno *alumnos;
    int i;
    int total_edad = 0;
    int total_calificacion = 0;
    float promedio_edad, promedio_calificacion;

    printf("Ingrese el numero de alumnos: ");
    scanf("%d", &num_alumnos);

    while (getchar() != '\n');

    alumnos = (Alumno *)malloc(num_alumnos * sizeof(Alumno));
    if (alumnos == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    for (i = 0; i < num_alumnos; i++) {
        system("cls");
        printf("Ingrese el nombre del alumno %d (max. %d caracteres): ", i + 1, MAX_NOMBRE - 1);
        fgets(alumnos[i].nombre, MAX_NOMBRE, stdin);
        alumnos[i].nombre[strcspn(alumnos[i].nombre, "\n")] = '\0';
        
        printf("Ingrese la edad del alumno %d: ", i + 1);
        scanf("%d", &alumnos[i].edad);
        
        printf("Ingrese la calificacion del alumno %d: ", i + 1);
        scanf("%d", &alumnos[i].calificacion);
        
        while (getchar() != '\n');
        
        total_edad += alumnos[i].edad;
        total_calificacion += alumnos[i].calificacion;
    }

    promedio_edad = (float)total_edad / num_alumnos;
    promedio_calificacion = (float)total_calificacion / num_alumnos;

    system("cls");

    printf("| %-25s | %4s | %12s |\n", "Nombre", "Edad", "Calificacion");
    printf("|---------------------------|------|--------------|\n");

    for (i = num_alumnos - 1; i >= 0; i--) {
        printf("| %-25s | %4d | %12d |\n", alumnos[i].nombre, alumnos[i].edad, alumnos[i].calificacion);
    }

    printf("|---------------------------|------|--------------|\n");
    printf("| Promedio                  |      | %12.2f |\n", promedio_calificacion);
    printf("| Promedio de edad          |%4.2f |              |\n", promedio_edad);

    free(alumnos);

    system("pause");

    return 0;
}

