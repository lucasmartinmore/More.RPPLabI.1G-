#include "Clientes.h"

int menuPrincipal()
{
    system("cls");
    int opcion;
    printf(" ___******** ABM PARCIAL *********___\n");
    printf("|      1) Alta de Cliente            |\n");
    printf("|      2) Modificar Cliente          |\n");
    printf("|      3) Baja Cliente               |\n");
    printf("|      4) Alta prestamo              |\n");
    printf("|      5) Saldar prestamo            |\n");
    printf("|      6) Ranurar prestamo           |\n");
    printf("|      7) Imprimir Cliente           |\n");
    printf("|      8) Imprimir Prestamo          |\n");
    printf("|      9) Informar cliente           |\n");
    printf("|     10) Informar prestamo          |\n");
    printf("|     11) Salir                      |\n");
    printf("|____________________________________|\n\n");
    printf("-------------------------------------\n");
    opcion=validarEntero("         Ingrese opcion: ","Reingrese opcion: ",1,11);
    return opcion;
}

int iniciarClientes(Cliente clientes[], int tamClientes)
{
    int error=-1;
    if(clientes!=NULL && tamClientes>0)
    {
        for(int i=0; i<tamClientes; i++)
        {
            clientes[i].isEmpty=1;
            error=1;
        }
    }
    return error;
}

int buscarClientesVacios(Cliente clientes[], int tamClientes, int* error)
{
    *error=-1;
    int posicion=-1;
    if(clientes!=NULL && tamClientes>0)
    {
        for(int i=0; i<tamClientes; i++)
        {
            if(clientes[i].isEmpty==1)
            {
                posicion=i;
                *error=1;
                break;
            }
        }
    }
    return posicion;
}

int altaClientes(Cliente clientes[],int tamClientes,int idCliente)
{
    int posicion;
    int lugarVacio;

    posicion=buscarClientesVacios(clientes,tamClientes,&lugarVacio);//BUSCO
    if(lugarVacio==-1)
    {
        printf("  --------- No se encuentra lugar vacio ! ---------  \n");
        return -1;
    }
    else if(clientes!=NULL && tamClientes>0 && posicion!=-1)
    {
        system("cls");
        printf("  --------- ***** ALTA CLIENTE ***** ----------  \n\n");

        clientes[posicion].isEmpty=0;

        clientes[posicion].idCliente = idCliente;

        validarCadena("Ingrese nombre del cliente: ","Error. Ingrese nombre del cliente: ",50,clientes[posicion].nombre);

        validarCadena("Ingrese apellido del cliente: ","Error. Ingrese apellido del cliente: ",50,clientes[posicion].apellido);

        clientes[posicion].cuil=validarEntero("Ingrese numero de cuil: ","Reingrese numero de cuil: ",1,11111111);

        printf("\n  --------- Alta de cliente exitosa ! ---------  \n");
    }
    return 0;
}

int menuModificar()
{
    system("cls");
    int opcion;
    printf("|---- MODIFICAR -----|\n");
    printf("|  1) Nombre         |\n");
    printf("|  2) Apellido       |\n");
    printf("|  3) Cuil           |\n");
    printf("|--------------------|\n\n");
    printf("----------------------\n");
    opcion=validarEntero("   Ingrese opcion: ","Reingrese opcion: ",1,3);
    return opcion;
}

int cantidadPrestamosClientes(Prestamo prestamos[], int tamPrestamos, int idCliente)
{
    int cantidadDePrestamos=0;

    if(prestamos!=NULL && tamPrestamos>0)
    {
        for(int i=0; i<tamPrestamos; i++)
        {
            if(prestamos[i].idCliente == idCliente)
            {
                cantidadDePrestamos++;
            }
        }
    }
    return cantidadDePrestamos;
}


void mostrarCliente(Cliente cliente,Prestamo prestamos[], int tamPrestamos)
{
    int cantidadPrestamos;

    cantidadPrestamos=cantidadPrestamosClientes(prestamos, tamPrestamos, cliente.idCliente);

    if(cliente.isEmpty==0)
    {
        printf("  %3d     %-11s  %-11s %9d     %2d\n",cliente.idCliente,cliente.nombre,cliente.apellido,
        cliente.cuil,cantidadPrestamos);
        printf("_______________________________________________________________________________\n");
    }
}

int mostrarClientes(Cliente clientes[], int tamClientes, Prestamo prestamos[], int tamPrestamos)
{
    int error=-1;
    int flagClientesCargados=-1;

    if(clientes!=NULL && tamClientes>0 &&prestamos!=NULL && tamPrestamos>0)
    {
        system("cls");
        printf("  ----- ***** LISTADO DE CLIENTES ***** -----  \n");
        printf("______________________________________________________________________________\n");
        printf("ID CLI    NOMBRE        APELLIDO       CUIL      C.PREST                      \n");
        printf("______________________________________________________________________________\n");
        for(int i=0; i<tamClientes; i++)
        {
            if(clientes[i].isEmpty==0)
            {
                mostrarCliente(clientes[i],prestamos,tamPrestamos);
                flagClientesCargados=0;
                error=0;
            }
        }
    }

    if(flagClientesCargados==-1)
    {
        printf("\n  --------- No se encuentran clientes cargados en el sistema ! ---------  \n\n");
    }
    return error;
}

int modificarCliente(Cliente clientes[], int tamClientes, Prestamo prestamos[], int tamPrestamos)
{
    int posicion;
    char nuevoNombre[50];
    char nuevoApellido[50];
    int nuevoCuil;
    int error=-1;

    if(clientes!=NULL && tamClientes>0 && prestamos!=NULL && tamPrestamos>0)
    {
        if(mostrarClientes(clientes,tamClientes,prestamos,tamPrestamos)!=-1)
        {
            printf("Ingrese id a modificar: ");
            scanf("%d", &posicion);
        }
        else
        {
            return -1;
        }

        for(int i=0; i<tamClientes; i++)
        {
            if(clientes[i].idCliente==posicion && clientes[i].isEmpty==0)
            {
                switch(menuModificar())
                {
                case 1:
                    validarCadena("Ingrese nuevo nombre del cliente: ","Error. Ingrese nuevo nombre del cliente: ",50,nuevoNombre);
                    strcpy(clientes[i].nombre,nuevoNombre);
                    printf("\n  --------- Cambio de nombre del cliente exitoso ---------  \n");
                    error=1;
                    break;
                case 2:
                    validarCadena("Ingrese nuevo apellido del cliente: ","Error. Ingrese nuevo apellido del cliente: ",50,nuevoApellido);
                    strcpy(clientes[i].apellido,nuevoApellido);
                    printf("\n  --------- Cambio de apellido del cliente exitoso ---------  \n");
                    error=1;
                    break;
                case 3:
                    nuevoCuil=validarEntero("Ingrese nuevo cuil: ","Reingrese nuevo cuil: ",1,111111111);
                    clientes[i].cuil = nuevoCuil;
                    printf("\n  --------- Cambio de cuil del cliente exitoso ---------  \n");
                    break;
                }
            }
        }
        if(error==-1)
        {
            printf("\n  --------- Id del cliente ingresado no valido ! ---------  \n\n");
        }
    }
    return error;
}

int bajaCliente(Cliente clientes[], int tamClientes, Prestamo prestamos[], int tamPrestamos)
{
    int posicion;
    char confirmacion;
    int error=-1;

    if(clientes!=NULL && tamClientes>0 && prestamos!=NULL && tamPrestamos>0)
    {
        if(mostrarClientes(clientes,tamClientes,prestamos,tamPrestamos)!=-1)
        {
            posicion=validarEntero("Ingrese id de cliente a dar de baja: ","Error. Ingrese id de cliente dar de baja: ",1,50);
        }
        else
        {
            return -1;
        }

        for(int i=0; i<tamClientes; i++)
        {
            if(clientes[i].idCliente==posicion)
            {
                printf("Deseas continuar con la baja(Y/N): ");
                fflush(stdin);
                scanf("%c", &confirmacion);
                confirmacion = toupper(confirmacion);
                while(confirmacion!='Y' && confirmacion!='N')
                {
                    printf("Error. Deseas continuar con la baja(Y/N): ");
                    fflush(stdin);
                    scanf("%c", &confirmacion);
                    confirmacion = toupper (confirmacion);
                }
                if(confirmacion=='Y')
                {
                    error=1;
                    clientes[i].isEmpty=1;
                    clientes[i].idCliente=-1;

                    for(int i=0; i<tamPrestamos; i++)
                    {
                        if(prestamos[i].idCliente == clientes[i].idCliente)
                        {
                            prestamos[i].idPrestamo=-1;
                            prestamos[i].isEmpty=1;
                        }
                    }
                    printf("\n  --------- Baja de cliente y prestamo exitosa ! ---------  \n");
                    break;
                }
                else
                {
                    printf("\n  --------- Baja de cliente y prestamo cancelada ! ---------  \n");
                    error=1;
                    break;
                }
            }
        }
        if(error==-1)
        {
            printf("\n  --------- Id del cliente ingresado no valido ! ---------  \n\n");
        }
    }
    return error;
}

int cargarCuilDeCliente(int idCliente, Cliente clientes[], int tamClientes)
{
    int numeroCuil;
    if(clientes!=NULL && tamClientes>0)
    {
        for(int i=0; i<tamClientes; i++)
        {
            if(clientes[i].idCliente==idCliente)
            {
                numeroCuil=clientes[i].cuil;
                break;
            }
        }
    }
    return numeroCuil;
}
