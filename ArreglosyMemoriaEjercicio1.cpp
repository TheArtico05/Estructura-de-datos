#include <stdio.h>
#include <stdlib.h>

int Digitofinal;
int main(){
printf("Programa de dynamic array por Emiliano Ruiz Garcia y Moreno Vigueras Arturo Tadeo :) \n");
printf ("ARREGLO UNIDIMENSIONAL \n");
int *punto=(int*) malloc(10 * sizeof(int));
for (int construpar=0; construpar<10; construpar++){
punto[construpar] = (construpar+1)*2;
}
for(int riki= 9;riki>=0; riki--){
printf("%d", punto[riki]);
printf("|"); //raya para separar la lista
}
printf("\nEstos son los numeros antes del cambio");
//424126694, 9 digitos
printf ("\nAhora, ingresa tu numero de cuenta por favor\n");
int NumCuenta;
scanf("%d", &NumCuenta);//error "process exited after 6.617 seconds with return value 3221225477"

Digitofinal = NumCuenta % 10;

if(Digitofinal<0){
	printf("Ha ocurrido un error inesperado, asegurate de haber insertado bien tu numero de cuenta ");
	return 2;
}
punto[Digitofinal] = -1;
printf("El numero de cuenta ingresado fue %d, por lo que el ultmo digito va a ser %d \n", NumCuenta, Digitofinal);
printf("Ahora, la posicion del ultimo digito de tu numero de cuenta debe cambiar :)) ");
for (int Heropon = 9; Heropon >= 0; Heropon--) {
	printf("%d|", punto[Heropon]);
}
printf("\n");
if (punto == NULL){
printf("Ha ocurrido un error SUPER RARO, trata de intentarlo de nuevo, ¿o puede que este mal el codigo?");
return -1;
}
free(punto);

return 0;

}
