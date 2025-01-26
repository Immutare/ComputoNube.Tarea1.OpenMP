// Trea1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

// #include "pch.h"
#include <omp.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

#define N 10000
#define CHUNK 100
#define MOSTRAR 100

float randomFloat(float lowest, float highest) {
    float random = ((float)rand()) / (float)RAND_MAX;
    float diff = highest - lowest;
    float r = random * diff;
    return lowest + r;
}

void imprimeArreglo(float* arr, char arreglo) {
    std::cout << "Imprimiendo los primeros " << MOSTRAR << " valores del arreglo " << arreglo << ": " << std::endl;
    for (int i = 0; i < MOSTRAR; i++) {
        std::cout << arr[i] << " - ";
    }
    std::cout << std::endl;
}

int main()
{
    srand((unsigned int)time(NULL) + 2158);
    std::cout << "Sumar arreglos en paralelo!\n";
    float a[N], b[N], c[N];
    int i;

    for (i = 0; i < N; i++) {
        float num = randomFloat(1.0, 100.0);
        a[i] = num * 10;
        b[i] = (num + 3) * 3.7;
    }

    int pedazos = CHUNK;

    #pragma omp parallel for \
    shared(a, b, c, pedazos) private (i) \
    schedule(static, pedazos)

    for (i = 0; i < N; i++) {
        c[i] = a[i] + b[i];
    }

    imprimeArreglo(a, 'a');
    imprimeArreglo(b, 'b');
    imprimeArreglo(c, 'c');
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
