#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Funcion de validacion de ingresos de caracteres
int VerificacionDigitos(char string[])
{

    if (strlen(string) == 0)
    {
        return 0; // Comprobar que la cadena no este vacia
    }

    for (int i = 0; i < strlen(string); i++)
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

    for (int i = 0; i < strlen(string); i++)
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

    if (nPuntos > 1)
    {
        return 0; // No pueden haber mas de 1 punto en el numero decimal
    }

    if (strlen(string) == 1 && (string[0] == '.'))
    {
        return 0; // Cadena invalida si solo es un punto
    }

    return 1; // Si la cadena son digitos validos entonces se retorna verdadero
}

// Limpiar buffer
void LimpiarBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int main(int argc, char *argv[])
{

    int libros[5][3];                       // Inicializacion de la matriz de libros
    float precios[5], subTotal, totalVenta; // Inicializacion del vector de precios
    char entradaStr[25];

    // i para filas; j para columnas

    // Ingreso de ID de libros
    for (int i = 0; i < 5; i++)
    {
        int idValida = 0;

        do
        {
            printf("\nIngrese el ID del libro #%i: ", i + 1);

            if (fgets(entradaStr, 25, stdin) == NULL)
            {
                LimpiarBuffer();
                continue;
            }

            // Eliminar el salto de línea al final de la cadena
            entradaStr[strcspn(entradaStr, "\n")] = '\0';

            if (VerificacionDigitos(entradaStr) == 1)
            {
                libros[i][0] = atoi(entradaStr);
                idValida = 1;
            }
            else
            {
                printf("\nSolo se permiten numeros enteros. Intentelo de nuevo.");
            }

        } while (idValida == 0);
    }

    printf("\nId's ingresadas correctamente.");

    // Ingreso de stock inicial
    for (int i = 0; i < 5; i++)
    {
        int stockValido = 0;

        do
        {
            printf("\nIngrese el stock inicial del libro (mayor a 0) #%i: ", i + 1);

            if (fgets(entradaStr, 25, stdin) == NULL)
            {
                LimpiarBuffer();
                continue;
            }

            // 2. Eliminar el salto de línea al final de la cadena
            entradaStr[strcspn(entradaStr, "\n")] = '\0';

            if (VerificacionDigitos(entradaStr))
            {
                int stockIngresado = atoi(entradaStr);
                if (stockIngresado > 0)
                {
                    libros[i][1] = stockIngresado;
                    stockValido = 1;
                }
            }
            else
            {
                printf("\nSolo se permiten enteros positivos. Intentelo de nuevo.");
            }

        } while (stockValido == 0);
    }
    printf("\nStocks ingresados correctamente.");

    // Ingreso de precios unitarios por libro
    for (int i = 0; i < 5; i++)
    {
        int precioValido = 0;
        do
        {
            printf("\nIngrese el precio unitario del libro #%i: ", i + 1);
            if (fgets(entradaStr, 25, stdin) == NULL)
            {
                LimpiarBuffer();
                continue;
            }

            // Eliminar el salto de línea al final de la cadena
            entradaStr[strcspn(entradaStr, "\n")] = '\0';

            if (VerificacionFloat(entradaStr) == 1)
            {
                int precioIngresado = atof(entradaStr);

                if (precioIngresado > 0)
                {
                    precios[i] = precioIngresado;
                    precioValido = 1;
                }
            }
            else
            {
                printf("\nSolo se permiten numeros positivos. Intentelo de nuevo.");
            }

        } while (precioValido == 0);
    }

    printf("\nPrecios unitarios ingresados correctamente.");

    // Cantidad vendida

    for (int i = 0; i < 5; i++)
    {
        int cantidadValida = 0;
        do
        {
            printf("\nIngrese la cantidad vendida del libro #%i: ", i + 1);

            if (fgets(entradaStr, 25, stdin) == NULL)
            {
                LimpiarBuffer();
                continue;
            }

            // 2. Eliminar el salto de línea al final de la cadena
            entradaStr[strcspn(entradaStr, "\n")] = '\0';
            if (VerificacionDigitos(entradaStr))
            {

                libros[i][2] = atoi(entradaStr);
                cantidadValida = 1;
            }
            else
            {
                printf("\nSolo se permiten numeros enteros. Intentelo de nuevo.");
            }

        } while (cantidadValida == 0);

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
