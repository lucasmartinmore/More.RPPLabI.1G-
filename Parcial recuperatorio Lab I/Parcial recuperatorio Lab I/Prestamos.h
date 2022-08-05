#ifndef PRESTAMOS_H_INCLUDED
#define PRESTAMOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Validaciones.h"

typedef struct
{
    int idPrestamo;
    int idCliente;
    float importe;
    int cuotas;
    char estado;
    int isEmpty;
}Prestamo;

typedef struct
{
    int idCliente;
    char nombre[50];
    char apellido[50];
    int cuil;
    int isEmpty;
}Cliente;

#endif // PRESTAMOS_H_INCLUDED

void mostrarPrestamo(Cliente clientes[], int tamCliente,Prestamo prestamo);
int mostrarPrestamos(Cliente clientes[], int tamClientes, Prestamo prestamos[], int tamPrestamos);
int iniciarPrestamos(Prestamo prestamos[], int tamPrestamos);
int buscarPrestamosVacios(Prestamo prestamos[], int tamPrestamos, int* error);
int saldarPrestamo(Cliente clientes[], int tamClientes, Prestamo prestamos[], int tamPrestamos);
