#include <stdio.h>
#include "funcionesStruct.h"

int main(int argc, char *argv[])
{

    Carro carro1;
    Carro carro2;
    Carro carro3;
    Carro carro4;
    Carro carro5;

    printf("\nIngrese el tamano del carro #1: ");
    scanf("%i", &carro1.tamano);
    printf("\nTamano del carro #1: %i", carro1.tamano);

    printf("\nIngrese el tamano del carro #2: ");
    scanf("%i", &carro2.tamano);
    printf("\nTamano del carro #2: %i", carro2.tamano);

    printf("\nIngrese el tamano del carro #3: ");
    scanf("%i", &carro3.tamano);
    printf("\nTamano del carro #3: %i", carro3.tamano);

    printf("\nIngrese el tamano del carro #4: ");
    scanf("%i", &carro4.tamano);
    printf("\nTamano del carro #4: %i", carro4.tamano);

    printf("\nIngrese el tamano del carro #5: ");
    scanf("%i", &carro5.tamano);
    printf("\nTamano del carro #5: %i", carro5.tamano);
    int carrMayor = CompararMayor(carro1, carro2, carro3, carro4, carro5);

    printf("El carro con mayor tamano es: %i", carrMayor);

    return 0;
}