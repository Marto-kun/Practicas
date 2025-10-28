#include <stdio.h>
#include <string.h>
#include <stdbool.h>


bool ValidacionCaracteres(int precio){
    if (precio < ){

    }
}

int main(int argc, char *argv[])
{
    int j, precio;
    char nombre[25][5]; // inicializa la matriz de Nombres
    int precios[5];     // Inicializa el vector de precios

    for (int i = 0; i < 5; i++)
    {
        fgets(nombre[i], sizeof(nombre), stdin);
    }


    for (int i = 0; i < 5; i++)
    {
        do
        {
            printf("Ingrese el precio de %s: ", nombre[i]);
            scanf("%i", &precio);
        } while (precio <= 0);
    }


    for (int i = 0; i < 5; i++)
    {
        printf("%s", nombre[i]);
    }
}
