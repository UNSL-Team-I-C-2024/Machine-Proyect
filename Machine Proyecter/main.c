#include <stdio.h>
#include <stdlib.h>
#include "listaE_Cliente.h"
#include "listaD_Turno.h"
int GenTurno = 1;
float PriceTreat [10]= {60000,8000,5000,40000,10000,150000,200000,30000,5000,40000}; // precio de los tratamientos

void CargaTurno(Lista_de_Turnos *ListTurn, Lista_de_Clientes *ListClient); // A (pendiente)

int BuscarTurnoPorIdcliente (Lista_de_Turnos *Lturno, int IdCliente); // B // interna (ubica cursor)

void MuestraAllTurnosMes (Lista_de_Turnos Lturno, int Mes); // C

void BuscarMostrarTurnoPorNombre (Lista_de_Turnos Lturno, char Nombre[]); // D // requiere paginado

void MuestraTurnoPorIdCliente (Lista_de_Turnos Lturno); // E // recursiva, muestra fecha, total e idturno

void CalcularGananciaMensual (Lista_de_Turnos Lturnos,int mes); // F // recursiva

void MuestraAllTurnos (Lista_de_Turnos Lturno); // G

turno ModificarCantidadTratamientos (); // H

turno ModificarMetPago (Lista_de_Turnos Lturnos); // I

void CancelarTurnoIdcliente(Lista_de_Turnos Lturno); // J // necesita archivo

void AlmacenarAllTurnosPorPagoArchivos(); // K // necesita archivo

void RegistrarCliente(Lista_de_Clientes *Lcliente); // L

void MuestraTurnosPorTratamiento (Lista_de_Turnos Lturno, int Treatment); // M // codificar segun la posicion deseada

void PrecargaAutomatica (); // N // interna (necesita archivo)

void MuestraAllClientes (Lista_de_Clientes Listclient); // Ñ

void EliminarClienteSegunIdcliente(Lista_de_Clientes *Lcliente); // O

void ModificarTurnoConfirmadoIdcliente(Lista_de_Clientes Lcliente); // Marcar realizado con 1, modificar cantidad de tratamientos y nivel (supongo qsy) // P

void MuestraAllTurnosNoRealizado (Lista_de_Turnos ListTurn); // Q

int main()
{
    // int Option, Control; if control == 2 salir else relanzar menu //
    /*Lista_de_Clientes ListClient;
    Lista_de_Turnos ListTurn;
    turno AuxTurn;
    Cliente AuxClient;
    return 0;
    do
    {
        
    } while (Control!=2);*/
}

/* Estructura Menu 2 Capas
printf ("Menu \n ...\n)
    scanf ("%d", &Option);
switch (Option)
{
 case 1:
  {
    printf ("SubMenu \n ...\n)
    scanf ("%d", &Option);
    switch (Option)
    {
     case 1:
     { 
      break;
     }
    }
    break;
}
}

printf ("\n ------ \n|@ Code|\n| QR @ |\n ------ \n");
*/

void CargaTurno (Lista_de_Turnos *ListTurn,Lista_de_Clientes *ListClient){
    turno TurnoAuxiliar;
    int IDbuscar;
    set_Idturno(&TurnoAuxiliar,GenTurno);
    printf("Ingrese la ID del cliente: ");
    scanf("%d",&IDbuscar);
    ListE_Reset(ListClient);
    while (get_ID_Cliente(ListE_Copy(*ListClient))!=IDbuscar){
        if (!ListE_IsOos(*ListClient)){
            ListE_Forward(ListClient);
        }
        else{
            printf("No se ha encontrado el ID del cliente");
            return;
        }
    }
    set_IdCliente_turno(&TurnoAuxiliar,IDbuscar);
    set_Nombre_Turno(&TurnoAuxiliar,get_Nombre(ListE_Copy(*ListClient)));
    int Opcion, Counter = 0;
    char MasTratamientos;
    do{
        if (Counter<=4)
        {
         printf("Que tratamientos desea?\n(1)Depilacion completa 60.000\n(2)Bronceado 8000\n(3)Maquillaje 5000\n(4)Drenaje linfatico  manual 40.000\n(5)Masaje 10.000\n(6)Tratamiento con botox 150.000\n(7)implantes faciales con ácido hialurónico 200.000\n(8)Radiofrecuencia facial 30.000\n(9)Limpieza facial 5.000\n(10)10 Peeling químico 40.000\n");
         scanf("%d",&Opcion);
         while (Opcion<1||Opcion>10)
          {
             printf("Opcion invalida(1-10)");
            scanf("%d",&Opcion);
          }
         TurnoAuxiliar.Tratatamiento[Opcion-1] = 1;
         printf("Desea aniadir otro tratamiento?(Y/N)\n");
         scanf(" %c",&MasTratamientos);
         getchar();
         while(MasTratamientos!='Y'||MasTratamientos!='N')
         {
             printf("Opcion invalida(Y/N)\n");
             scanf(" %c",&MasTratamientos);
             getchar();
         }
        }
        else
        {
            printf("Limite de tratamientos alcanzado (4)\n");
            MasTratamientos = 'N';
        }
    }
    while(MasTratamientos == 'Y');

    printf("Ingrese la forma de pago:\n(1)Debito\n(2)Cretido\n(3)QR\n(4)Efectivo\n");
    scanf("%d",&Opcion);
    while(Opcion<1&&Opcion>4)
    {
        printf("Opcion invalida(1-4)\n");
        scanf("%d",&Opcion);
    }
    
   int TotalAux;
   if(get_Tratamiento(ListD_Copy(*ListTurn))[0]==1)  //agregar total y descuento
    
    GenTurno+=1;
}

int BuscarTurnoPorIdcliente (Lista_de_Turnos *Lturno, int IdCliente)
{
    ListD_Reset (Lturno);
    while (get_IdCliente_turno(ListD_Copy(*Lturno)) != IdCliente && !ListD_IsOos(*Lturno))
    {
        ListD_Forward (Lturno);
    }
    if (ListD_IsOos(*Lturno))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void MuestraAllTurnosMes (Lista_de_Turnos Lturno, int Mes)
{
    int Counter = 0, *Aux;
    ListD_Reset (&Lturno);
    while (!ListD_IsOos(Lturno))
    {
        if (get_Fecha_Mes(ListD_Copy(Lturno)) == Mes)
        {
            printf ("Nombre: %s \n", get_Nombre_Turno(ListD_Copy(Lturno)));
            printf ("ID Cliente: %d \n", get_IdCliente_turno(ListD_Copy(Lturno)));
            printf ("ID Turno: %d \n", get_IdTurno(ListD_Copy(Lturno)));
            printf ("Fecha del turno %d %d/%d/%d\n", get_Fecha_Hora(ListD_Copy(Lturno)), get_Fecha_Dia(ListD_Copy(Lturno)), get_Fecha_Mes(ListD_Copy(Lturno)), get_Fecha_Anio(ListD_Copy(Lturno)));
            Aux = get_Tratamiento (ListD_Copy(Lturno));
            if (Aux[0] == 1)
            printf ("Depilacion completa $60000 \n");
            if (Aux[1] == 1)
            printf ("Bronceado  $8000 \n");
            if (Aux[2] == 1)
            printf ("Maquillaje $5000 \n");
            if (Aux[3] == 1)
            printf ("Drenaje linfatico  manual $40000 \n");
            if (Aux[4] == 1)
            printf ("Masaje $10000 \n");
            if (Aux[5] == 1)
            printf ("Tratamiento con botox $150000 \n");
            if (Aux[6] == 1)
            printf (" implantes faciales con acido hialurónico $200000 \n");
            if (Aux[7] == 1)
            printf ("Radiofrecuencia facial $30000 \n");
            if (Aux[8] == 1)
            printf ("Limpieza facial $5000 \n");
            if (Aux[9] == 1)
            printf ("Peeling quimico $40000 \n");
            if (get_Forma_de_pago(ListD_Copy(Lturno)) == 1)
            printf("Metodo de pago: Debito\n");
            else
             if (get_Forma_de_pago(ListD_Copy(Lturno)) == 2)
            printf("Metodo de pago: Credito\n");
            else
             if (get_Forma_de_pago(ListD_Copy(Lturno)) == 3)
            printf("Metodo de pago: QR\n");
            else
            printf("Metodo de pago: Efectivo\n");
            printf ("Total a pagar: %f \n", get_Total(ListD_Copy(Lturno)));
            Counter += 1;
        }
        ListD_Forward (&Lturno);
    }
    if (Counter == 0)
    printf("No se encontro ningun turno para el mes consultado \n");
}


void BuscarMostrarTurnoPorNombre (Lista_de_Turnos Lturno, char Nombre[]) //Falta paginar de a 3 clientes //
{
    int Counter=0, *Aux;
    char extra;
    ListD_Reset(&Lturno);
    while (!ListD_IsOos(Lturno))
    {
        if (strcmp(get_Nombre_Turno(ListD_Copy(Lturno)), Nombre))
        {
            printf ("Nombre: %s \n", get_Nombre_Turno(ListD_Copy(Lturno)));
            printf ("ID Cliente: %d \n", get_IdCliente_turno(ListD_Copy(Lturno)));
            printf ("ID Turno: %d \n", get_IdTurno(ListD_Copy(Lturno)));
            printf ("Fecha del turno %d %d/%d/%d\n", get_Fecha_Hora(ListD_Copy(Lturno)), get_Fecha_Dia(ListD_Copy(Lturno)), get_Fecha_Mes(ListD_Copy(Lturno)), get_Fecha_Anio(ListD_Copy(Lturno)));
            Aux = get_Tratamiento (ListD_Copy(Lturno));
            if (Aux[0] == 1)
            printf ("Depilacion completa $60000 \n");
            if (Aux[1] == 1)
            printf ("Bronceado  $8000 \n");
            if (Aux[2] == 1)
            printf ("Maquillaje $5000 \n");
            if (Aux[3] == 1)
            printf ("Drenaje linfatico  manual $40000 \n");
            if (Aux[4] == 1)
            printf ("Masaje $10000 \n");
            if (Aux[5] == 1)
            printf ("Tratamiento con botox $150000 \n");
            if (Aux[6] == 1)
            printf (" implantes faciales con acido hialurónico $200000 \n");
            if (Aux[7] == 1)
            printf ("Radiofrecuencia facial $30000 \n");
            if (Aux[8] == 1)
            printf ("Limpieza facial $5000 \n");
            if (Aux[9] == 1)
            printf ("Peeling quimico $40000 \n");
            if (get_Forma_de_pago(ListD_Copy(Lturno)) == 1)
            printf("Metodo de pago: Debito\n");
            else
             if (get_Forma_de_pago(ListD_Copy(Lturno)) == 2)
            printf("Metodo de pago: Credito\n");
            else
             if (get_Forma_de_pago(ListD_Copy(Lturno)) == 3)
            printf("Metodo de pago: QR\n");
            else
            printf("Metodo de pago: Efectivo\n");
            printf ("Total a pagar: %f \n", get_Total(ListD_Copy(Lturno)));
            if (get_Realizado(ListD_Copy(Lturno)) == 1)
                printf("Turno Realizado");
                else
                printf("Turno no realizado");
            Counter += 1;
            if ((Counter % 3) == 0)
        {
            printf ("Presione cualquier tecla para continuar...");
            scanf("%c", &extra);
        }
        }
        
    }
   if(Counter==1)
    printf("No se encontro ningun turno para el mes consultado \n");  
}
