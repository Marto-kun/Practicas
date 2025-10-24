#include <stdio.h>

int main(int argc, char *argv[])
{
    int cursos;
    int i = 4;
    int dif;
    float rec, total;

    do
    {
        printf("\nIngrese la cantidad de cursos ofrecidos: ");
        scanf("%d", &cursos);
    } while (cursos <= 0);

    // Declaracion de arreglos
    int n = cursos;
    int cupos[n];
    int estudiantesIns[n];
    float costos[n];

    for (i = 0; i < n; i++) // Arreglo para cupos
    {
        do
        {
            printf("\nIngrese los cupos del curso %i: ", i + 1);
            fflush(stdin);
            scanf("%i", &cupos[i]);
        } while (cupos[i] <= 0);
    }

    for (i = 0; i < n; i++) // Arreglo para Estudiantes Inscritos
    {
        do
        {
            printf("\nIngrese los estudiantes inscritos del curso #%i: ", i + 1);
            scanf("%i", &estudiantesIns[i]);
        } while (estudiantesIns[i] <= 0);

        if (cupos[i] < estudiantesIns[i])
        {
            printf("\nError: El total de estudiantes inscritos es mayor a la cantidad de cupos ofrecidos. \nSaliendo...");
            return 1;
        }
    }

    for (i = 0; i < n; i++) // Arreglo para costos del curso
    {
        do
        {
            printf("\nIngrese los costos del curso #%i: ", i + 1);
            scanf("%f", &costos[i]);
        } while (costos[i] <= 0);
    }

    // Impresion de Informacion

    for (i = 0; i < n; i++)
    {

        dif = cupos[i] - estudiantesIns[i];
        rec = estudiantesIns[i] * costos[i];
        total += rec;
        printf("\nEn el curso #%i, sobraron %i cupos.", i + 1, dif);
        printf("\nEl total recaudado en el curso #%f fue: ", i + 1, rec);
    }

    printf("\nEl total de recaudacion entre todos los cursos fue: %f", total);

    return 0;
}