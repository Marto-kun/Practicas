#include <stdio.h>

int main(int argc, char *argv[])
{
    int cursos;
    int i = 4;
    int xd[3] = {3,2,4};

    do
    {
        printf("\nIngrese la cantidad de cursos ofrecidos: ");
        scanf("%d", &cursos);
    } while (cursos <= 0);

    //const int n = cursos;
    int cupos[i];
    //int estudiantesIns[n];
    //float costos[n];
    printf("%i",xd);
    printf("%d",cursos);
    return 0;
}