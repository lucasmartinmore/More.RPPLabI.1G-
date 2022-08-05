#include "Clientes.h"
#define TAM_CLIENTE 50
#define TAM_PRESTAMO 50

int main()
{
    Cliente clientes[TAM_CLIENTE];
    int idCliente=1;
    int banderaCliente=0;
    Prestamo prestamos[TAM_PRESTAMO];
    int idPrestamo=1;
    int banderaPrestamo=0;
    int seguir=0;
    //INICIALIZO
    iniciarClientes(clientes,TAM_CLIENTE);
    iniciarPrestamos(prestamos,TAM_PRESTAMO);

    do
    {
        switch(menuPrincipal())
        {
        case 1:
            altaClientes(clientes,TAM_CLIENTE,idCliente);
            idCliente++;
            banderaCliente=1;
            break;
        case 2:
            if(banderaCliente)
            {
                modificarCliente(clientes,TAM_CLIENTE,prestamos,TAM_PRESTAMO);
            }
            else
            {
                printf("  --------- Se necesitan cargar clientes antes de modificar ! ---------  \n");
            }
            break;
        case 3:
            if(banderaCliente)
            {
                bajaCliente(clientes,TAM_CLIENTE,prestamos,TAM_PRESTAMO);
            }
            else
            {
                printf("  --------- Se necesitan cargar clientes antes de dar de baja ! ---------  \n");
            }
            break;
        case 4:
            if(banderaCliente)
            {
                altaPrestamo(prestamos,TAM_PRESTAMO,idPrestamo,clientes,TAM_CLIENTE);
                idPrestamo++;
                banderaPrestamo=1;
            }
            else
            {
                 printf("  --------- Se necesitan cargar clientes antes de dar prestamo ! ---------  \n");
            }
            break;
        case 5:
            if(banderaCliente && banderaPrestamo)
            {
                saldarPrestamo(clientes,TAM_CLIENTE,prestamos,TAM_PRESTAMO);
            }
            else
            {
                printf("  --------- Se necesitan cargar clientes antes de saldar prestamo ! ---------  \n");
            }
            break;
        case 6:
            //REANURAR PRESTAMO
            break;
        case 7:
            if(banderaCliente)
            {
                mostrarClientes(clientes,TAM_CLIENTE,prestamos,TAM_PRESTAMO);
            }
            else
            {
                printf("  --------- Se necesitan cargar clientes antes mostrarlos ! ---------  \n");
            }
            break;
        case 8:
            if(banderaPrestamo)
            {
                mostrarPrestamos(clientes,TAM_CLIENTE,prestamos,TAM_PRESTAMO);
            }
            else
            {
                printf("  --------- Se necesitan cargar prestamos antes mostrarlos ! ---------  \n");
            }
            break;
        case 9:
            //INFORMES
            break;
        case 10:
            //INFORMES
            break;
        case 11:
            seguir=1;
            break;

        }
        system("pause");
    }while(seguir==0);

    return 0;
}
