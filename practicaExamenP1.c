#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Funcion de validacion de ingresos de caracteres
int VerificacionDigitos(char string[])
{

    if (strlen(string) == 0)
    {
        return 0; // Comprobar que la cadena no este vacia
    }

    for (int i = 0; i < 5; i++)
    {
        if (!isdigit(string[i]))
        {
            return 0; // Si el elemento de la cadena no es caracter retorna 0
        }
    }
    return 1; // Si la cadena son solo digitos entonces se retorna verdadero
}

// Funcion para validar un flotante valido
int VerificacionFloat(char string[])
{
    int nPuntos = 0;
    if (strlen(string) == 0)
    {
        return 0; // Comprobar que la cadena no este vacia
    }

    for (int i = 0; i < 5; i++)
    {
        char c = string[i];
        if (isdigit(c))
        {
            continue; // Si el elemento de la cadena es digito continua el bucle
        }
        else if (c == '.')
        {
            nPuntos++;
        }
        else
        {
            return 0; // Si no es digito o punto, es invalido
        }
    }
    return 1; // Si la cadena son solo digitos entonces se retorna verdadero
}

int main(int argc, char *argv[])
{

    int libros[5][3];                       // Inicializacion de la matriz de libros
    float precios[5], subTotal, totalVenta; // Inicializacion del vector de precios
    char entradaStr[25];
    bool verificacion;

    // i para filas; j para columnas

    // Ingreso de ID de libros
    for (int i = 0; i < 5; i++)
    {

        printf("\nIngrese el ID del libro #%i: ", i + 1);
        scanf("%i", &libros[i][0]);
    }

    // Ingreso de stock inicial
    for (int i = 0; i < 5; i++)
    {
        do
        {
            printf("\nIngrese el stock inicial del libro #%i: ", i + 1);
            scanf("%i", &libros[i][1]);
        } while (libros[i][1] < 0);
    }

    // Ingreso de precios unitarios por libro
    for (int i = 0; i < 5; i++)
    {
        do
        {
            printf("\nIngrese el precio unitario del libro #%i: ", i + 1);
            scanf("%f", &precios[i]);
        } while (precios[i] <= 0);
    }

    // Cantidad vendida

    for (int i = 0; i < 5; i++)
    {

        do
        {
            printf("\nIngrese la cantidad vendida del libro #%i: ", i + 1);
            scanf("%i", &libros[i][2]);
        } while (libros[i][2] < 0);

        if (libros[i][2] > libros[i][1])
        {
            printf("\nLa cantidad de libros supero el stock disponible. Saliendo...");
            return 1;
        }
    }

    // Impresion de datos:
    for (int i = 0; i < 5; i++)
    {
        subTotal = precios[i] * libros[i][2];
        printf("\nEl subtotal de la venta del libro #%i es: %f", i + 1, subTotal);
        totalVenta += subTotal;
    }

    printf("\nEl total de la venta de todos los libros fue: %.2f", totalVenta);
}
