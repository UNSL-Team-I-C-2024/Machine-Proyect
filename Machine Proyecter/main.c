#include <stdio.h>
#include <stdlib.h>
#include "listaE_Cliente.h"
#include "listaD_Turno.h"

int GenTurno = 1;
typedef char Treat[51];
Treat NameTreat [10] = {"Depilacion completa", "Bronceado", "Maquillaje", "Drenaje linfatico  manual", "Masaje", "Tratamiento con Botox", "implantes faciales con acido hialuronico", "Radiofrecuencia facial", "Limpieza facial", "Peeling quimico"};
int PriceTreat [8]= {60000,8000,5000,40000,10000,150000,200000,30000,}; // precio de los tratamientos

void CargaTurno(Lista_de_Turnos *ListTurn, Lista_de_Clientes *ListClient); // A // EL ACABADO

int BuscarTurnoPorIdcliente (Lista_de_Turnos *Lturno, int IdCliente); // B // EL ACABADO interna (ubica cursor)

void MuestraAllTurnosMes (Lista_de_Turnos Lturno, int Mes); // C // EL ACABADO

void BuscarMostrarTurnoPorNombre (Lista_de_Turnos Lturno, char Nombre[]); // D // EL ACABADO requiere paginado

void MuestraTurnoPorIdCliente (Lista_de_Turnos Lturno, turno Aux, int ID); // E // EL ACABADO recursiva, muestra fecha, total e idturno

float CalcularGananciaMensual (Lista_de_Turnos Lturnos,int mes, float cont); // F // EL ACABADO recursiva

void MuestraAllTurnos (Lista_de_Turnos Lturno); // G // EL ACABADO

turno ModificarCantidadTratamientos (); // H //

void ModificarMetPago (Lista_de_Turnos *Lturno); // I // EL ACABADO

void CancelarTurnoIdcliente(Lista_de_Turnos *Lturno); // J // necesita archivo

void AlmacenarAllTurnosPorPagoArchivos(); // K // necesita archivo

void RegistrarCliente(Lista_de_Clientes *Lcliente); // L

void MuestraTurnosPorTratamiento (Lista_de_Turnos Lturno, int Treatment); // M // codificar segun la posicion deseada

void PrecargaAutomatica (Lista_de_Clientes *Lclientes); // N // el ACABADO...   (el que lo critica)

void MuestraAllClientes (Lista_de_Clientes Listclient); // Ñ

void EliminarClienteSegunIdcliente(Lista_de_Clientes *Lcliente); // O

void ConfirmaturnoIdcliente(Lista_de_Clientes Lcliente); // P // Marcar realizado con 1, modificar cantidad de tratamientos y nivel (supongo qsy) // P

void MuestraAllTurnosNoRealizado (Lista_de_Turnos ListTurn); // Q

int main()
{
    Lista_de_Clientes Lclientes;
    // Lista_de_Turnos Lturnos;
    PrecargaAutomatica(&Lclientes);


    // int Option, Control; if control == 2 salir else relanzar menu //
    /*Lista_de_Clientes ListClient;
    Lista_de_Turnos ListTurn;
    turno AuxTurn;
    Cliente AuxClient;

    do
    {

    } while (Control!=2);*/
    return 0;
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

void CargaTurno (Lista_de_Turnos *ListTurn,Lista_de_Clientes *ListClient)
{
    turno TurnoAuxiliar;
    Cliente ClienteAuxiliar;
    int IDbuscar, Opcion, Counter = 0, TotalAux=0, *Treatments;
    char MasTratamientos,OpcionChar;

    init_Turno(&TurnoAuxiliar);
    set_Idturno(&TurnoAuxiliar,GenTurno);
    printf("Ingrese la ID del cliente");
    scanf("%d",&IDbuscar);
    ListE_Reset(ListClient);
    while (get_ID_Cliente(ListE_Copy(*ListClient)) != IDbuscar && !ListE_IsOos(*ListClient))
    {
        ListE_Forward(ListClient);
    }
    if (ListE_IsOos(*ListClient))
    {
        printf("No se ha encontrado el ID del cliente, por favor registre al cliente antes de continuar \n");
        return;
    }
    if(BuscarTurnoPorIdcliente(ListTurn, IDbuscar)){
        printf("Este cliente ya tiene un turno no realizado\n");
        return;
    }
    set_IdCliente_turno(&TurnoAuxiliar,IDbuscar);
    ClienteAuxiliar = ListE_Copy(*ListClient);
    set_Nombre_Turno(&TurnoAuxiliar,get_Nombre(ClienteAuxiliar));
    do{
        if (Counter<=4)
        {
         printf("Que tratamientos desea?\n(1)Depilacion completa $60.000\n(2)Bronceado $8000\n(3)Maquillaje $5000\n(4)Drenaje linfatico  manual $40.000\n(5)Masaje $10.000\n(6)Tratamiento con botox $150.000\n(7)implantes faciales con ácido hialurónico $200.000\n(8)Radiofrecuencia facial $30.000\n(9)Limpieza facial $5.000\n(10)10 Peeling químico $40.000\n");
         scanf("%d",&Opcion);
         while (Opcion<1||Opcion>10)
          {
             printf("Opcion invalida (1-10)");
            scanf("%d",&Opcion);
          }
          set_Tratamiento (&TurnoAuxiliar, Opcion-1);
         printf("Desea aniadir otro tratamiento?(Y/N)\n");
         scanf(" %c",&MasTratamientos);
         while(MasTratamientos!='Y'||MasTratamientos!='N')
         {
             printf("Opcion invalida (Y/N)\n");
             scanf(" %c",&MasTratamientos);
         }
        }
        else
        {
            printf("Limite de tratamientos alcanzado (4)\n");
            MasTratamientos = 'N';
        }
    }
    while(MasTratamientos == 'Y');
    printf("Ingrese la forma de pago:\n(1) Debito\n(2) Credito\n(3) QR\n(4) Efectivo\n");
    scanf("%d",&Opcion);
    while(Opcion<1 || Opcion>4)
    {
        printf("Opcion invalida (1-4)\n");
        scanf("%d",&Opcion);
    }
    Treatments = get_Tratamiento(ListD_Copy(*ListTurn));
   if(Treatments[0])
    TotalAux+= PriceTreat[0];
   if(Treatments[1])
    TotalAux+= PriceTreat[1];
   if(Treatments[2] || Treatments[8])
    TotalAux+= PriceTreat[2];
   if(Treatments[3] || Treatments[9])
    TotalAux+= PriceTreat[3];
   if(Treatments[4])
    TotalAux+= PriceTreat[4];
   if(Treatments[5])
    TotalAux+= PriceTreat[5];
   if(Treatments[6])
    TotalAux+= PriceTreat[6];
   if(Treatments[7])
   {
    TotalAux+= PriceTreat[7];
   }
    IDbuscar = get_Nivel(ClienteAuxiliar);
   if (IDbuscar == 1)
    TotalAux -= (TotalAux*0.05);
   if (IDbuscar == 2)
    TotalAux -= (TotalAux*0.1);
   if (IDbuscar == 3)
    TotalAux -= (TotalAux*0.15);
   set_Total(&TurnoAuxiliar,TotalAux);
   printf("Ingrese el anio: \n");
   scanf("%d", &Treatments[0]);
   while (Treatments[0] != 2024)
   {
        printf("Fecha invalida(2024): \n");
        scanf("%d",&Treatments[0]);
   }
   while(Treatments[1]<11||Treatments[1]>12)
   {
        printf("Fecha invalida(11-12): \n");
        scanf("%d", &Treatments[1]);
   }
   printf("Ingrese el dia: \n");
   scanf("%d", &Treatments[2]);
   switch (Treatments[1])
   {
        case 11:{
            while (Treatments[2]<1 || Treatments[2]>30 || Treatments[2] == 3 || Treatments[2] == 10 || Treatments[2]==17 || Treatments[2] == 24)
            {
                if(Treatments[2] == 3 || Treatments[2] == 10 || Treatments[2]==17 || Treatments[2] == 24)
                printf("(No hay turnos los domingos)\n");
                else
                printf("Fecha invalida(1-30): \n");
                scanf("%d",&Treatments[2]);
            }
            break;
        }
        case 12:{
            while (Treatments[2]<1||Treatments[2]>31)
            {
                
                if(Treatments[2] == 1 || Treatments[2] == 8 || Treatments[2] == 15 || Treatments[2] == 22 || Treatments[2] == 29)
                printf("(No hay turnos los domingos)\n");
                else
                printf("Fecha invalida(1-30): \n");
                scanf("%d", &Treatments[2]);
            }
            break;
        }
   }
   printf("Ingrese la hora(9-20): ");
   scanf("%d", &Treatments[3]);
   while (Treatments[3]<9 || Treatments[3]>20)
   {
    printf("Hora invalida(9-20): \n");
    scanf("%d", &Treatments[3]);
   }
    set_Fecha_Anio(&TurnoAuxiliar,Treatments[0]);
    set_Fecha_mes(&TurnoAuxiliar,Treatments[1]);
    set_Fecha_Dia(&TurnoAuxiliar,Treatments[2]);
    set_Fecha_Hora(&TurnoAuxiliar,Treatments[3]);
    int *Aux;
    printf("Resumen del turno:\n");
        printf ("Nombre: %s \n", get_Nombre_Turno(TurnoAuxiliar));
        printf ("ID Cliente: %d \n", get_IdCliente_turno(TurnoAuxiliar));
        printf ("ID Turno: %d \n", get_IdTurno(TurnoAuxiliar));
        printf ("Fecha del turno %d %d/%d/%d\n", get_Fecha_Hora(TurnoAuxiliar), get_Fecha_Dia(TurnoAuxiliar), get_Fecha_Mes(TurnoAuxiliar), get_Fecha_Anio(TurnoAuxiliar));
            Aux = get_Tratamiento (TurnoAuxiliar);
            if (Aux[0] == 1)
            printf ("%s $%d \n",NameTreat[0],PriceTreat[0]);
            if (Aux[1] == 1)
            printf ("%s $%d \n", NameTreat[1], PriceTreat[1]);
            if (Aux[2] == 1)
            printf ("%s $%d \n",NameTreat[2],PriceTreat[2]);
            if (Aux[3] == 1)
            printf ("%s $%d \n", NameTreat[3], PriceTreat[3]);
            if (Aux[4] == 1)
            printf ("%s $%d \n",NameTreat[4],PriceTreat[4]);
            if (Aux[5] == 1)
            printf ("%s $%d \n",NameTreat[5],PriceTreat[5]);
            if (Aux[6] == 1)
            printf ("%s $%d \n", NameTreat[6], PriceTreat[6]);
            if (Aux[7] == 1)
            printf ("%s $%d \n",NameTreat[7],PriceTreat[7]);
            if (Aux[8] == 1)
            printf ("%s $%d \n", NameTreat[8], PriceTreat[2]);
            if (Aux[9] == 1)
            printf ("%s $%d \n",NameTreat[9],PriceTreat[3]);
            Treatments[4] = get_Forma_de_pago(TurnoAuxiliar);
            if ( Treatments[4] == 1)
            printf("Metodo de pago: Debito\n");
             if (Treatments[4] == 2)
            printf("Metodo de pago: Credito\n");
             if (Treatments[4] == 3)
            printf("Metodo de pago: QR\n");
            else
            printf("Metodo de pago: Efectivo\n");
            printf ("Total a pagar: %f \n", get_Total(TurnoAuxiliar));
            printf("Turno no realizado");
    printf("Desea guardar este turno?(Y/N) \n");
    scanf(" %c",&OpcionChar);
    while (OpcionChar!='Y'&&OpcionChar!='N')
    {
        printf("Opcion invalida(Y/N): \n");
        scanf(" %c",&OpcionChar);
    }
    if(OpcionChar=='Y')
    {
        ListD_Pusher(ListTurn,TurnoAuxiliar);
        GenTurno+=1;
    }
}

int BuscarTurnoPorIdcliente (Lista_de_Turnos *Lturno, int IdCliente)
{
    ListD_Reset (Lturno);
    while ( !ListD_IsOos (*Lturno) )
{
if ( !get_Realizado(ListD_Copy(*Lturno)) && get_IdCliente_turno(ListD_Copy(*Lturno)) == IdCliente )
return 1;
ListD_Forward (Lturno);
}
return 0;
}

void MuestraAllTurnosMes (Lista_de_Turnos Lturno, int Mes)  // falta ordenar //
{
    int Counter = 0, *Aux;
    turno TAuxiliar;
    ListD_Reset (&Lturno);
    while (!ListD_IsOos(Lturno))
    {
        if (get_Fecha_Mes(ListD_Copy(Lturno)) == Mes)
        {
            TAuxiliar = ListD_Copy(Lturno);
            printf ("Nombre: %s \n", get_Nombre_Turno(TAuxiliar));
            printf ("ID Cliente: %d \n", get_IdCliente_turno(TAuxiliar));
            printf ("ID Turno: %d \n", get_IdTurno(TAuxiliar));
            printf ("Fecha del turno %d %d/%d/%d\n", get_Fecha_Hora(TAuxiliar), get_Fecha_Dia(TAuxiliar), get_Fecha_Mes(TAuxiliar), get_Fecha_Anio(TAuxiliar));
            Aux = get_Tratamiento (TAuxiliar);
            if (Aux[0])
            printf ("%s $%d \n",NameTreat[0],PriceTreat[0]);
            if (Aux[1])
            printf ("%s $%d \n", NameTreat[1], PriceTreat[1]);
            if (Aux[2])
            printf ("%s $%d \n",NameTreat[2],PriceTreat[2]);
            if (Aux[3])
            printf ("%s $%d \n", NameTreat[3], PriceTreat[3]);
            if (Aux[4])
            printf ("%s $%d \n",NameTreat[4],PriceTreat[4]);
            if (Aux[5])
            printf ("%s $%d \n",NameTreat[5],PriceTreat[5]);
            if (Aux[6])
            printf ("%s $%d \n", NameTreat[6], PriceTreat[6]);
            if (Aux[7])
            printf ("%s $%d \n",NameTreat[7],PriceTreat[7]);
            if (Aux[8])
            printf ("%s $%d \n", NameTreat[8], PriceTreat[2]);
            if (Aux[9])
            printf ("%s $%d \n",NameTreat[9],PriceTreat[3]);
            if (get_Forma_de_pago(TAuxiliar) == 1)
            printf("Metodo de pago: Debito\n");
             if (get_Forma_de_pago(TAuxiliar) == 2)
            printf("Metodo de pago: Credito\n");
             if (get_Forma_de_pago(TAuxiliar) == 3)
            printf("Metodo de pago: QR\n");
            else
            printf("Metodo de pago: Efectivo\n");
            printf ("Total a pagar: %f \n", get_Total(TAuxiliar));
            if (get_Realizado(TAuxiliar))
                printf("Turno Realizado\n\n");
                else
                printf("Turno no realizado\n\n");
            Counter += 1;
        }
        ListD_Forward (&Lturno);
    }
    if (Counter == 0)
    printf("No se encontro ningun turno para el mes consultado \n");
}

void BuscarMostrarTurnoPorNombre (Lista_de_Turnos Lturno, char Nombre[])
{
    int Counter=0, *Aux;
    char extra;
    turno TAuxiliar;
    ListD_Reset(&Lturno);
    while (!ListD_IsOos(Lturno))
    {
        if (strcmp(get_Nombre_Turno(ListD_Copy(Lturno)), Nombre))
        {
            TAuxiliar = ListD_Copy(Lturno);
            printf ("Nombre: %s \n", get_Nombre_Turno(TAuxiliar));
            printf ("ID Cliente: %d \n", get_IdCliente_turno(TAuxiliar));
            printf ("ID Turno: %d \n", get_IdTurno(TAuxiliar));
            printf ("Fecha del turno %d %d/%d/%d\n", get_Fecha_Hora(TAuxiliar), get_Fecha_Dia(TAuxiliar), get_Fecha_Mes(TAuxiliar), get_Fecha_Anio(TAuxiliar));
            Aux = get_Tratamiento (TAuxiliar);
            if (Aux[0])
            printf ("%s $%d \n",NameTreat[0],PriceTreat[0]);
            if (Aux[1])
            printf ("%s $%d \n", NameTreat[1], PriceTreat[1]);
            if (Aux[2])
            printf ("%s $%d \n",NameTreat[2],PriceTreat[2]);
            if (Aux[3])
            printf ("%s $%d \n", NameTreat[3], PriceTreat[3]);
            if (Aux[4])
            printf ("%s $%d \n",NameTreat[4],PriceTreat[4]);
            if (Aux[5])
            printf ("%s $%d \n",NameTreat[5],PriceTreat[5]);
            if (Aux[6])
            printf ("%s $%d \n", NameTreat[6], PriceTreat[6]);
            if (Aux[7])
            printf ("%s $%d \n",NameTreat[7],PriceTreat[7]);
            if (Aux[8])
            printf ("%s $%d \n", NameTreat[8], PriceTreat[2]);
            if (Aux[9])
            printf ("%s $%d \n",NameTreat[9],PriceTreat[3]);
            if (get_Forma_de_pago(TAuxiliar) == 1)
            printf("Metodo de pago: Debito\n");
             if (get_Forma_de_pago(TAuxiliar) == 2)
            printf("Metodo de pago: Credito\n");
             if (get_Forma_de_pago(TAuxiliar) == 3)
            printf("Metodo de pago: QR\n");
            else
            printf("Metodo de pago: Efectivo\n");
            printf ("Total a pagar: %f \n", get_Total(TAuxiliar));
            if (get_Realizado(TAuxiliar))
                printf("Turno Realizado\n\n");
                else
                printf("Turno no realizado\n\n");
            Counter += 1;
            if ((Counter % 3) == 0)
        {
            printf ("Presione cualquier tecla para continuar...");
            scanf("%c", &extra);
            system("cls");
        }
        }

    }
   if(Counter == 0)
    printf("No se encontro ningun turno para el nombre consultado\n");
}

void MuestraTurnoPorIdCliente (Lista_de_Turnos Lturno, turno Aux,int ID)
{
    if (ListD_IsOos(Lturno))
    {

    }
    else
    {
        if (get_IdCliente_turno(Aux) == ID)
        {
            printf ("ID Turno: %d \n", get_IdTurno(Aux));
            printf ("Total a pagar: %f \n", get_Total(Aux));
            printf ("Fecha del turno %d hs %d/%d/%d\n \n", get_Fecha_Hora(Aux), get_Fecha_Dia(Aux), get_Fecha_Mes(Aux), get_Fecha_Anio(Aux));
        }
        ListD_Forward(&Lturno);
        Aux = ListD_Copy(Lturno);
        MuestraTurnoPorIdCliente ( Lturno, Aux, ID);
    }
}

float CalcularGananciaMensual (Lista_de_Turnos Lturno, int mes, float Cont)
{
    if (ListD_IsOos(Lturno))
    {
        return Cont;
    }
    else
    {
        if (get_Fecha_Mes(ListD_Copy(Lturno)) == mes && get_Realizado(ListD_Copy(Lturno)))
        {
            Cont += get_Total(ListD_Copy(Lturno));
        }
        ListD_Forward (&Lturno);
        CalcularGananciaMensual (Lturno, mes, Cont);
    }
    return 0;
}

void MuestraAllTurnos(Lista_de_Turnos Lturno)
{
    int *Aux;
    turno TAuxiliar;
    ListD_Reset(&Lturno);
    while (!ListD_IsOos(Lturno))
    {
    TAuxiliar = ListD_Copy(Lturno);
            printf ("Nombre: %s \n", get_Nombre_Turno(TAuxiliar));
            printf ("ID Cliente: %d \n", get_IdCliente_turno(TAuxiliar));
            printf ("ID Turno: %d \n", get_IdTurno(TAuxiliar));
            printf ("Fecha del turno %d %d/%d/%d\n", get_Fecha_Hora(TAuxiliar), get_Fecha_Dia(TAuxiliar), get_Fecha_Mes(TAuxiliar), get_Fecha_Anio(TAuxiliar));
            Aux = get_Tratamiento (TAuxiliar);
            if (Aux[0])
            printf ("%s $%d \n",NameTreat[0],PriceTreat[0]);
            if (Aux[1])
            printf ("%s $%d \n", NameTreat[1], PriceTreat[1]);
            if (Aux[2])
            printf ("%s $%d \n",NameTreat[2],PriceTreat[2]);
            if (Aux[3])
            printf ("%s $%d \n", NameTreat[3], PriceTreat[3]);
            if (Aux[4])
            printf ("%s $%d \n",NameTreat[4],PriceTreat[4]);
            if (Aux[5])
            printf ("%s $%d \n",NameTreat[5],PriceTreat[5]);
            if (Aux[6])
            printf ("%s $%d \n", NameTreat[6], PriceTreat[6]);
            if (Aux[7])
            printf ("%s $%d \n",NameTreat[7],PriceTreat[7]);
            if (Aux[8])
            printf ("%s $%d \n", NameTreat[8], PriceTreat[2]);
            if (Aux[9])
            printf ("%s $%d \n",NameTreat[9],PriceTreat[3]);
            if (get_Forma_de_pago(TAuxiliar) == 1)
            printf("Metodo de pago: Debito\n");
             if (get_Forma_de_pago(TAuxiliar) == 2)
            printf("Metodo de pago: Credito\n");
             if (get_Forma_de_pago(TAuxiliar) == 3)
            printf("Metodo de pago: QR\n");
            else
            printf("Metodo de pago: Efectivo\n");
            printf ("Total a pagar: %f \n", get_Total(TAuxiliar));
            if (get_Realizado(TAuxiliar))
                printf("Turno Realizado\n\n");
                else
                printf("Turno no realizado\n\n");
            ListD_Forward(&Lturno);
    }
}

void ModificarMetPago (Lista_de_Turnos *Lturno)
{
    int IDbuscar, MetPagoAc;
    turno TurnoAux;
    printf("Ingrese la ID del cliente para modificar su turno: \n");
    scanf("%d",&IDbuscar);
    if(!BuscarTurnoPorIdcliente(Lturno, IDbuscar))
    {
        printf("No se han encontrado turnos pendientes \n");
        return;
    }
    else
    {
        MetPagoAc = get_Forma_de_pago (ListD_Copy(*Lturno));
        switch (MetPagoAc){
        case 1:
        {
            printf("metodo de pago actual: debito\n");
            break;
        }
        case 2:
        {
            printf("metodo de pago actual: credito\n");
            break;
        }
        case 3:
        {
            printf("metodo de pago actual: QR\n");
            break;
        }
        case 4:
        {
            printf("metodo de pago actual: efectivo\n");
            break;
        }
        }
        printf("Cual va a ser el nuevo metodo de pago? (1)debito (2)credito (3)QR (4)efectivo\n");
        scanf("%d",&MetPagoAc);
        while(MetPagoAc<1 || MetPagoAc>4)
        {
        printf("Opcion invalida (1-4)\n");
        scanf("%d",&MetPagoAc);
        }
        TurnoAux = ListD_Copy (*Lturno);
        set_Forma_de_pago (&TurnoAux,MetPagoAc);
        ListD_Suppresor (Lturno);
        ListD_Pusher (Lturno,TurnoAux);
    }
}

void CancelarTurnoIdcliente(Lista_de_Turnos *Lturno)
{
    int *Aux, Aux2;
    turno TAuxiliar;
    printf ("Ingrese el ID de cliente");
    scanf ("%d", &Aux2);
    if (BuscarTurnoPorIdcliente(Lturno, Aux2))
    {
        printf("No se han encontrado turnos pendientes \n");
        return;
    }
    else
    {
        TAuxiliar = ListD_Copy(*Lturno);
        printf ("Turno encontrado \n \n");
            printf ("Nombre: %s \n", get_Nombre_Turno(TAuxiliar));
            printf ("ID Cliente: %d \n", get_IdCliente_turno(TAuxiliar));
            printf ("ID Turno: %d \n", get_IdTurno(TAuxiliar));
            printf ("Fecha del turno %d %d/%d/%d\n", get_Fecha_Hora(TAuxiliar), get_Fecha_Dia(TAuxiliar), get_Fecha_Mes(TAuxiliar), get_Fecha_Anio(TAuxiliar));
            Aux = get_Tratamiento (TAuxiliar);
            if (Aux[0])
            printf ("%s $%d \n",NameTreat[0],PriceTreat[0]);
            if (Aux[1])
            printf ("%s $%d \n", NameTreat[1], PriceTreat[1]);
            if (Aux[2])
            printf ("%s $%d \n",NameTreat[2],PriceTreat[2]);
            if (Aux[3])
            printf ("%s $%d \n", NameTreat[3], PriceTreat[3]);
            if (Aux[4])
            printf ("%s $%d \n",NameTreat[4],PriceTreat[4]);
            if (Aux[5])
            printf ("%s $%d \n",NameTreat[5],PriceTreat[5]);
            if (Aux[6])
            printf ("%s $%d \n", NameTreat[6], PriceTreat[6]);
            if (Aux[7])
            printf ("%s $%d \n",NameTreat[7],PriceTreat[7]);
            if (Aux[8])
            printf ("%s $%d \n", NameTreat[8], PriceTreat[2]);
            if (Aux[9])
            printf ("%s $%d \n",NameTreat[9],PriceTreat[3]);
            if (get_Forma_de_pago(TAuxiliar) == 1)
            printf("Metodo de pago: Debito\n");
             if (get_Forma_de_pago(TAuxiliar) == 2)
            printf("Metodo de pago: Credito\n");
             if (get_Forma_de_pago(TAuxiliar) == 3)
            printf("Metodo de pago: QR\n");
            else
            printf("Metodo de pago: Efectivo\n");
            printf ("Total a pagar: %f \n", get_Total(TAuxiliar));
            if (get_Realizado(TAuxiliar))
                printf("Turno Realizado\n\n");
                else
                printf("Turno no realizado\n\n");
    }
}

void PrecargaAutomatica (Lista_de_Clientes *Lclientes)
{
    Cliente Caux;
    int i,Vid,Vcanttrat,Vnivel;
    char Vnomb[31], Vape[31];
    FILE *Fp;
    ListE_Starter(Lclientes);
    Fp = fopen("Clientes.txt","r");
    if (Fp==NULL)
    {
        printf("Ha ocurrido un error en la precarga de los clientes...\n");
        return;
     }
    else
    {
        for (i=0;i<10;i++){
         fscanf(Fp,"%d %s %s %d %d",&Vid,Vnomb,Vape,&Vcanttrat,&Vnivel);
         set_ID_Cliente(&Caux,Vid);
         set_Nombre(&Caux,Vnomb);
         set_Apellido(&Caux,Vape);
         set_CantTratamientos(&Caux,Vcanttrat);
         set_Nivel(&Caux,Vnivel);
         ListE_Insert(Lclientes, Caux);
         ListE_Forward(Lclientes);
         }
         fclose(Fp);
    }
}
