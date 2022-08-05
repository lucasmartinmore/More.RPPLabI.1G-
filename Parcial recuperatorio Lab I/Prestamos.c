#include "Prestamos.h"
#include "Validaciones.h"

void mostrarPrestamo(Cliente clientes[], int tamCliente,Prestamo prestamo)
{
    int cuil;
    cuil=cargarCuilDeCliente(prestamo.idCliente,clientes,tamCliente);

    if(prestamo.isEmpty==0)
    {
        printf("  %3d     %7f  %3d  %3d %9d \n",prestamo.idPrestamo,prestamo.importe,prestamo.cuotas,
        prestamo.idCliente,cuil);
        printf("_______________________________________________________________________________\n");
    }
}

int mostrarPrestamos(Cliente clientes[], int tamClientes, Prestamo prestamos[], int tamPrestamos)
{
    int error=-1;
    int flagPrestamosCargados=-1;

    if(clientes!=NULL && tamClientes>0 &&prestamos!=NULL && tamPrestamos>0)
    {
        system("cls");
        printf("  ----- ***** LISTADO DE PRESTAMOS ***** -----  \n");
        printf("______________________________________________________________________________\n");
        printf("ID PRE    PRECIO        CUOTA       ID CLI      CUIL                          \n");
        printf("______________________________________________________________________________\n");
        for(int i=0; i<tamPrestamos; i++)
        {
            if(prestamos[i].isEmpty==0)
            {
                mostrarPrestamo(clientes,tamClientes,prestamos[i]);
                flagPrestamosCargados=0;
                error=0;
            }
        }
    }

    if(flagPrestamosCargados==-1)
    {
        printf("\n  --------- No se encuentran prestamos cargados en el sistema ! ---------  \n\n");
    }
    return error;
}

int iniciarPrestamos(Prestamo prestamos[], int tamPrestamos)
{
    int error=-1;
    if(prestamos!=NULL && tamPrestamos>0)
    {
        for(int i=0; i<tamPrestamos; i++)
        {
            prestamos[i].isEmpty=1;
            error=1;
        }
    }
    return error;
}

int buscarPrestamosVacios(Prestamo prestamos[], int tamPrestamos, int* error)
{
    *error=-1;
    int posicion=-1;
    if(prestamos!=NULL && tamPrestamos>0)
    {
        for(int i=0; i<tamPrestamos; i++)
        {
            if(prestamos[i].isEmpty==1)
            {
                posicion=i;
                *error=1;
                break;
            }
        }
    }
    return posicion;
}

int altaPrestamo(Prestamo prestamos[],int tamPrestamos,int idPrestamos,Cliente clientes[], int tamClientes)
{
    int posicion;
    int lugarVacio;

    posicion=buscarPrestamosVacios(prestamos,tamPrestamos,&lugarVacio);//BUSCO
    if(lugarVacio==-1)
    {
        printf("  --------- No se encuentra lugar vacio ! ---------  \n");
        return -1;
    }
    else if(prestamos!=NULL && tamPrestamos>0 && posicion!=-1)
    {
        system("cls");
        printf("  --------- ***** ALTA PRESTAMO ***** ----------  \n\n");

        prestamos[posicion].isEmpty=0;

        prestamos[posicion].idPrestamo = idPrestamos;

        mostrarClientes(clientes,tamClientes,prestamos,tamPrestamos);
        prestamos[posicion].idCliente=validarEntero("Ingrese id del cliente: ", "Error. Ingrese id del cliente: ",1,50);

        prestamos[posicion].importe=validarFlotante("Ingrese importe del prestamo: ","Error. Ingrese importe del prestamo: ",1,9999999);

        prestamos[posicion].cuotas=validarEntero("Ingrese cuotas del prestamo: ","Error. Ingrese cuotas del prestamo: ",1,999);

        strcpy(prestamos[posicion].estado,"ACTIVO");

        printf("\n  --------- Alta de prestamo exitosa ! ---------  \n");
    }
    return 0;
}

int saldarPrestamo(Cliente clientes[], int tamClientes, Prestamo prestamos[], int tamPrestamos)
{
    int posicion;
    char confirmacion;
    int error=-1;

    if(clientes!=NULL && tamClientes>0 && prestamos!=NULL && tamPrestamos>0)
    {
        if(mostrarPrestamos(clientes,tamClientes,prestamos,tamPrestamos)!=-1)
        {
            posicion=validarEntero("Ingrese id del prestamo a saldar: ","Error. Ingrese id del prestamo a saldar: ",1,50);
        }
        else
        {
            return -1;
        }

        for(int i=0; i<tamClientes; i++)
        {
            if(prestamos[i].idPrestamo==posicion)
            {
                printf("Deseas continuar con el saldado(Y/N): ");
                fflush(stdin);
                scanf("%c", &confirmacion);
                confirmacion = toupper(confirmacion);
                while(confirmacion!='Y' && confirmacion!='N')
                {
                    printf("Error. Deseas continuar con el saldado(Y/N): ");
                    fflush(stdin);
                    scanf("%c", &confirmacion);
                    confirmacion = toupper (confirmacion);
                }
                if(confirmacion=='Y')
                {
                    error=1;
                    strcpy(prestamos[i].estado,"SALDADO");

                    printf("\n  --------- Saldado de prestamo exitosa ! ---------  \n");
                    break;
                }
                else
                {
                    printf("\n  --------- Saldado de prestamo cancelada ! ---------  \n");
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






