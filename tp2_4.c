#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
struct
{
    int Velocidad_GHz;
    int anioFabricacion;
    char Procesador[50];
    int CantNucleos;
}typedef PC;
void listarPC(PC *comp);
void mostrarPCMasVieja(PC *comp);
void mostrarPCMasVeloz(PC *comp);
int main(){

    PC compu[5];
    char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    PC *punt = &compu;
    
    for (size_t i = 0; i < 5; i++)
    {
        int proc = rand() % 6;
        punt->Velocidad_GHz = (rand() % 3) + 1;
        punt->anioFabricacion = (rand() % 10) + 2015;
        punt->CantNucleos = (rand() % 8) + 1;
        strcpy(punt->Procesador, tipos[proc]);

        punt++;
    }

    listarPC(&punt);
    mostrarPCMasVieja(&punt);
    mostrarPCMasVeloz(&punt);
    return 0;
}

void listarPC(PC *comp){

    for (size_t i = 0; i < 5; i++)
    {
        printf("*** Datos de la pc numero: %d ***\n\n",i);

        printf("velocidad de GHz: %d\n", comp->Velocidad_GHz);
        printf("anio de fabricacion: %d\n",comp->anioFabricacion);
        printf("Cantidad de Nucleos: %d\n",comp->CantNucleos);
        printf("el procesador es: %s\n",comp->Procesador);
        comp++;
    } 
}

void mostrarPCMasVieja(PC *comp){

    PC *pcMasVieja = comp;
    for (size_t i = 1; i < 5; i++)
    {
        
        if (comp->anioFabricacion < pcMasVieja->anioFabricacion) {
            pcMasVieja = comp;
        }
        comp++;
    }

    printf("*** Datos de la PC más vieja ***\n\n");
    printf("Velocidad de GHz: %d\n", pcMasVieja->Velocidad_GHz);
    printf("Año de fabricación: %d\n",pcMasVieja->anioFabricacion);
    printf("Cantidad de Núcleos: %d\n",pcMasVieja->CantNucleos);
    printf("El procesador es: %s\n",pcMasVieja->Procesador);
}

void mostrarPCMasVeloz(PC *comp){
    PC *pcMasVeloz = comp;
    for (size_t i = 1; i < 5; i++)
    {
        comp++;
        if (comp->Velocidad_GHz > pcMasVeloz->Velocidad_GHz) {
            pcMasVeloz = comp;
        }
    }

    printf("*** Datos de la PC más veloz ***\n\n");
    printf("Velocidad de GHz: %d\n", pcMasVeloz->Velocidad_GHz);
    printf("Año de fabricación: %d\n",pcMasVeloz->anioFabricacion);
    printf("Cantidad de Núcleos: %d\n",pcMasVeloz->CantNucleos);
    printf("El procesador es: %s\n",pcMasVeloz->Procesador);
}