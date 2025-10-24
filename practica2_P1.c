#include <stdio.h>

int main(int argc, char *argv[])
{

    char medicamentos[5][3];
    int i, j;

    for (i = 0; i < 5; i++)
    {
        printf("\nIngrese el nombre del medicamento #%i: ", i + 1);
        scanf("%c", &medicamentos[i][0]);
        for (j = 1; j < 3; j++)
        {
            do
            {
                printf("\nIngrese el precio del medicamento #%i: ", i + 1);
                scanf("%c", &medicamentos[i + 1][j]);
                
            } while (medicamentos[i + 1][j] <= 0);
        }
    }

    return 0;
}