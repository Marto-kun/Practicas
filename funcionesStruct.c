#include "funcionesStruct.h"

int CompararMayor(Carro carro1, Carro carro2, Carro carro3, Carro carro4, Carro carro5)
{
    int carroMayor;
    int carro;

    carroMayor = carro1.tamano;
    carro = 1;

    if (carroMayor < carro2.tamano)
    {
        carroMayor = carro2.tamano;
        carro = 2;
    }
    if (carroMayor < carro3.tamano)
    {
        carroMayor = carro3.tamano;
        carro = 3;
    }
    if (carroMayor < carro4.tamano)
    {
        carroMayor = carro4.tamano;
        carro = 4;
    }
    if (carroMayor < carro5.tamano)
    {
        carroMayor = carro5.tamano;
        carro = 5;
    }

    return carro;
}