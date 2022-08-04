#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Validaciones.h"
#include "Prestamos.h"

//LO TUVE QUE MOVER AL .H DE PRESTAMO PORQUE ME GENERABA UNA REFERENCIA CIRCULAR
#endif // CLIENTES_H_INCLUDED

int menuPrincipal();
int iniciarClientes(Cliente clientes[], int tamClientes);
int buscarClientesVacios(Cliente clientes[], int tamClientes, int* error);
int altaClientes(Cliente clientes[],int tamClientes,int idCliente);
int menuModificar();
int cantidadPrestamosClientes(Prestamo prestamos[], int tamPrestamos, int idCliente);
void mostrarCliente(Cliente cliente,Prestamo prestamos[], int tamPrestamos);
int mostrarClientes(Cliente clientes[], int tamClientes, Prestamo prestamos[], int tamPrestamos);
int modificarCliente(Cliente clientes[], int tamClientes, Prestamo prestamos[], int tamPrestamos);
int bajaCliente(Cliente clientes[], int tamClientes, Prestamo prestamos[], int tamPrestamos);
int cargarCuilDeCliente(int idCliente, Cliente clientes[], int tamClientes);
