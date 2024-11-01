#include <stdio.h>
#include <malloc.h>
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

void ModificarCantidadTratamientos (Lista_de_Clientes Lcliente); // H // EL ACABADO

void ModificarMetPago (Lista_de_Turnos *Lturno); // I // EL ACABADO

void CancelarTurnoIdcliente(Lista_de_Turnos *Lturno); // J // EL ACABADO necesita archivo

void AlmacenarAllTurnosPorPagoArchivos(Lista_de_Turnos Lturno, int Metdepago); // K // EL ACABADO necesita archivo

void RegistrarCliente(Lista_de_Clientes *Lcliente); // L EL ACABADO

void MuestraTurnosPorTratamiento (Lista_de_Turnos Lturno, int Treatment); // M // EL ACABADO codificar segun la posicion deseada

void PrecargaAutomatica (Lista_de_Clientes *Lclientes); // N // el ACABADO...   (el que lo critica)

void MuestraAllClientes (Lista_de_Clientes Listclient); // Ñ (lucas)

void EliminarClienteSegunIdcliente(Lista_de_Clientes *Lcliente); // O

void ConfirmaturnoIdcliente(Lista_de_Clientes *Lcliente, Lista_de_Turnos *Lturno); // P // Marcar realizado con 1, modificar cantidad de tratamientos y nivel (supongo qsy) // P

void MuestraAllTurnosNoRealizado (Lista_de_Turnos ListTurn); // EL ACABADO Q

int main()
{
    Lista_de_Clientes Lclientes;
    Lista_de_Turnos Lturnos;
    PrecargaAutomatica(&Lclientes);
    int Option;

    // Crear un control en caso de que la lista esté vacia o llena (Para ambas listas). la integracion va por tu cuenta pero que afecte a todas las funciones
    
    // Apartir de acá abajo va todo adentro del do-while

    printf("(1)Acciones con turnos\n(2)Acciones con clientes\n");
    scanf("%d",&Option);
    while(Option<1 || Option>2)
    {
    printf("Opcion invalida(1-2)\n");
    scanf("%d",&Option);
    }
    switch(Option)
    {
        case 1:
        {
          printf ("(1)Cargar un turno\n(2)Mostrar todos los turnos (por mes)\n(3)Mostrar todos los turnos (por nombre)\n(4)Mostrar un turno (por ID cliente)\n(5)Calcular ganancia (por mes)\n(6)Mostrar todos los turnos\n(7)Modificar metodo de pago\n(8)Cancelar turno (por ID cliente)\n(9)Archivar turnos (por metodo de pago)\n(10)Mostrar todos los turnos (por tratamiento)\n(11)Confirmar turno (por ID cliente)\n(12)Mostrar todos los turnos (no realizados)\n");
          scanf("%d",&Option);
          while (Option<1 || Option>12)
          {
                printf("Opcion invalida(1-11)\n");
                scanf("%d",&Option);
                }
                switch (Option)
                {
                case 1:
                {
                }
                case 2:
                {
                }
                case 3:
                {
                }
                case 4:
                {
                }
                case 5:
                {
                }
                case 6:
                {
                }
                case 7:
                {
                }
                case 8:
                {
                }
                case 9:
                {
                }
                case 10:
                {
                }
                case 11:
                {
                }
                case 12:
                {
                }
         }
        }
        case 2:
        {
           printf("1)Modificar cantidad de tratamientos\n2)Registrar cliente\n3)Mostrar todos los clientes\n4)Eliminar cliente (por ID)\n");
           scanf("%d",&Option);
           while (Option<1 || Option>5)
           {
              printf("Opcion invalida(1-4)\n");
              scanf("%d",&Option);
           }
           switch (Option)
           {
              case 1:{}
              case 2:{}
              case 3:{}
              case 4:{}
           }
        }
    }


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
printf ("Menu \n ...\n);
scanf ("%d", &Option);
switch (Option)
{
 case 1:
 {
    printf ("SubMenu \n ...\n);
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
 case 2:
 {
    printf ("SubMenu \n ...\n);
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
    set_Forma_de_pago (&TurnoAuxiliar, Opcion);
    Treatments = get_Tratamiento(TurnoAuxiliar);
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
    free (Aux);
    free (Treatments);
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
    free (Aux);
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
    {
    printf("No se encontro ningun turno para el nombre consultado\n");
    }
    free (Aux);
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
    free (Aux);
}

void ModificarCantidadTratamientos (Lista_de_Clientes Lcliente)
{
    Cliente Laux;
    int IDbuscar, NuevaCant;
    printf("Ingrese el ID del cliente para modificar sus tratamientos");
    scanf("%d",&IDbuscar);
    ListE_Reset(&Lcliente);
    while (get_ID_Cliente(ListE_Copy(Lcliente)) != IDbuscar && !ListE_IsOos(Lcliente))
    {
        ListE_Forward(&Lcliente);
    }
    if (ListE_IsOos(Lcliente))
    {
        printf("No se ha encontrado el ID del cliente, por favor registre al cliente antes de continuar \n");
        return;
    }
    Laux = ListE_Copy(Lcliente);
    printf("Cantidad actual de tratamientos del/la cliente %s: %d\nEscriba la nueva cantidad de tratamientos: ",get_Nombre(Laux),get_CantTratamientos(Laux));
    scanf("%d",&NuevaCant);
    while (NuevaCant<0){
        printf("Opcion invalida(debe ser una cantidad positiva)\n");
        scanf("%d",&NuevaCant);
    }
    set_CantTratamientos(&Laux, NuevaCant);
    if(NuevaCant==0)
    set_Nivel(&Laux,0);
    if(NuevaCant>0&&NuevaCant<5)
    set_Nivel(&Laux,1);
    if(NuevaCant>4&&NuevaCant<11)
    set_Nivel(&Laux,2);
    if(NuevaCant>10)
    set_Nivel(&Laux,3);
    ListE_Suppres(&Lcliente);
    ListE_Insert(&Lcliente,Laux);
}

void ModificarMetPago (Lista_de_Turnos *Lturno) // optimizar
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
    char AuxChar;
    turno TAuxiliar;
    FILE *Fp;
    printf ("Ingrese el ID de cliente");
    scanf ("%d", &Aux2);
    if (!BuscarTurnoPorIdcliente(Lturno, Aux2))
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
            printf("Turno no realizado\n\n");
            printf ("\n\n Desea eliminar este turno? (Y/N)\n");
            scanf ("%c", &AuxChar);
            while (AuxChar != 'Y' && AuxChar != 'N')
            {
                printf ("Opcion incorrecta (Y/N) \n");
                scanf ("%c", &AuxChar);
            }
            if (AuxChar == 'N')
                return;
            if ((Fp = fopen ("Turnos Eliminados.txt", "a")) == NULL)
            {
                printf ("No se pudo eliminar el turno \n");
                return;
            }
            fprintf (Fp,"%s \n", get_Nombre_Turno(TAuxiliar));
            fprintf (Fp,"%d \n", get_IdCliente_turno(TAuxiliar));
            fprintf (Fp,"%d \n", get_IdTurno(TAuxiliar));
            fprintf (Fp,"%d %d/%d/%d\n", get_Fecha_Hora(TAuxiliar), get_Fecha_Dia(TAuxiliar), get_Fecha_Mes(TAuxiliar), get_Fecha_Anio(TAuxiliar));
            Aux = get_Tratamiento (TAuxiliar);
            if (Aux[0])
            fprintf (Fp,"%s %d \n",NameTreat[0],PriceTreat[0]);
            if (Aux[1])
            fprintf (Fp,"%s %d \n", NameTreat[1], PriceTreat[1]);
            if (Aux[2])
            fprintf (Fp,"%s %d \n",NameTreat[2],PriceTreat[2]);
            if (Aux[3])
            fprintf (Fp,"%s %d \n", NameTreat[3], PriceTreat[3]);
            if (Aux[4])
            fprintf (Fp,"%s %d \n",NameTreat[4],PriceTreat[4]);
            if (Aux[5])
            fprintf (Fp,"%s %d \n",NameTreat[5],PriceTreat[5]);
            if (Aux[6])
            fprintf (Fp,"%s %d \n", NameTreat[6], PriceTreat[6]);
            if (Aux[7])
            fprintf (Fp,"%s %d \n",NameTreat[7],PriceTreat[7]);
            if (Aux[8])
            fprintf (Fp,"%s %d \n", NameTreat[8], PriceTreat[2]);
            if (Aux[9])
            fprintf (Fp,"%s %d \n",NameTreat[9],PriceTreat[3]);
            if (get_Forma_de_pago(TAuxiliar) == 1)
            fprintf(Fp,"Metodo de pago: Debito\n");
             if (get_Forma_de_pago(TAuxiliar) == 2)
            fprintf(Fp,"Metodo de pago: Credito\n");
             if (get_Forma_de_pago(TAuxiliar) == 3)
            fprintf(Fp,"Metodo de pago: QR\n");
            else
            fprintf(Fp,"Metodo de pago: Efectivo\n");
            fprintf (Fp,"Total a pagar: %f \n", get_Total(TAuxiliar));
            printf("Turno eliminado \n\n");
            fclose (Fp);
            ListD_Suppresor(Lturno);
           
    } 
    free (Aux);
}

void AlmacenarAllTurnosPorPagoArchivos(Lista_de_Turnos Lturno, int Metdepago)
{
    int X=0, *Aux;
    turno TAuxiliar;
    FILE *Fp;
            if ((Fp = fopen ("Turnos Pagados.txt", "w")) == NULL)
            {
                printf ("No se pueden archivar los turnos correctamente \n");
                return;
            }
            while (!ListD_IsOos(Lturno))
            {
                TAuxiliar = ListD_Copy (Lturno);
                if (get_Forma_de_pago (TAuxiliar) == Metdepago && get_Realizado(TAuxiliar))
                {
            fprintf (Fp,"Nombre %s \n", get_Nombre_Turno(TAuxiliar));
            fprintf (Fp,"ID %d \n", get_IdCliente_turno(TAuxiliar));
            fprintf (Fp,"ID turno %d \n", get_IdTurno(TAuxiliar));
            fprintf (Fp,"Fecha %d %d/%d/%d\n", get_Fecha_Hora(TAuxiliar), get_Fecha_Dia(TAuxiliar), get_Fecha_Mes(TAuxiliar), get_Fecha_Anio(TAuxiliar));
            Aux = get_Tratamiento (TAuxiliar);
            fprintf (Fp, "Tratamientos elegidos: \n");
            if (Aux[0])
            fprintf (Fp,"%s %d \n",NameTreat[0],PriceTreat[0]);
            if (Aux[1])
            fprintf (Fp,"%s %d \n", NameTreat[1], PriceTreat[1]);
            if (Aux[2])
            fprintf (Fp,"%s %d \n",NameTreat[2],PriceTreat[2]);
            if (Aux[3])
            fprintf (Fp,"%s %d \n", NameTreat[3], PriceTreat[3]);
            if (Aux[4])
            fprintf (Fp,"%s %d \n",NameTreat[4],PriceTreat[4]);
            if (Aux[5])
            fprintf (Fp,"%s %d \n",NameTreat[5],PriceTreat[5]);
            if (Aux[6])
            fprintf (Fp,"%s %d \n", NameTreat[6], PriceTreat[6]);
            if (Aux[7])
            fprintf (Fp,"%s %d \n",NameTreat[7],PriceTreat[7]);
            if (Aux[8])
            fprintf (Fp,"%s %d \n", NameTreat[8], PriceTreat[2]);
            if (Aux[9])
            fprintf (Fp,"%s %d \n",NameTreat[9],PriceTreat[3]);
            if (get_Forma_de_pago(TAuxiliar) == 1)
            fprintf(Fp,"Metodo de pago: Debito\n");
             if (get_Forma_de_pago(TAuxiliar) == 2)
            fprintf(Fp,"Metodo de pago: Credito\n");
             if (get_Forma_de_pago(TAuxiliar) == 3)
            fprintf(Fp,"Metodo de pago: QR\n");
            else
            fprintf(Fp,"Metodo de pago: Efectivo\n");
            fprintf (Fp,"Total pagado: %f \n", get_Total(TAuxiliar));
                }
        ListD_Forward (&Lturno);
        X ++;
    }
    printf ("Se archivaron con exito %d turnos \n", X);
    free (Aux);
    fclose (Fp);
}

void RegistrarCliente(Lista_de_Clientes *Lcliente)
{
    Cliente ClienteAux;
    int IDAux;
    char NombAux[51],ApeAux[51];
    clienteInit(&ClienteAux);
    printf("Ingrese el ID del cliente: ");
    scanf("%d",&IDAux);
    while (IDAux<0)
    {
        printf("ID invalida\n");
        scanf("%d",&IDAux);
    }
    ListE_Reset (Lcliente);
    while (!ListE_IsOos(*Lcliente))
    {
        if (get_ID_Cliente(ListE_Copy(*Lcliente)) == IDAux)
        {
            printf("Ya hay un cliente registrado con esa ID\n");
            return;
        }
        ListE_Forward (Lcliente);
    }
    printf("Ingrese el nombre del cliente: ");
    scanf(" %51s",NombAux);
    printf("Ingrese el apellido del cliente: ");
    scanf(" %51s",ApeAux);
    set_ID_Cliente(&ClienteAux,IDAux);
    set_Nombre(&ClienteAux,NombAux);
    set_Apellido(&ClienteAux,ApeAux);
    ListE_Insert(Lcliente,ClienteAux);
}

void MuestraTurnosPorTratamiento (Lista_de_Turnos Lturno, int Treatment) // revisar
{
    turno TAuxiliar;
    int *Aux;
    printf("Ingrese el tratamiento a ver en los turnos: \n");
    printf ("1)%s \n", NameTreat[0]);
    printf ("2) %s \n", NameTreat[1]);
    printf ("3)%s \n", NameTreat[2]);
    printf ("4)%s \n", NameTreat[3]);
    printf ("5)%s \n", NameTreat[4]);
    printf ("6)%s \n", NameTreat[5]);
    printf ("7)%s \n", NameTreat[6]);
    printf ("8)%s \n", NameTreat[7]);
    printf ("9)%s \n", NameTreat[8]); 
    printf ("10)%s \n", NameTreat[9]);
    scanf("%d",&Treatment);
    while (Treatment<1||Treatment>10)
    {
        printf("Opcion invalida(1-10)\n");
        scanf("%d",&Treatment);
    }
    ListD_Reset (&Lturno);
    while (!ListD_IsOos(Lturno))
    {
        
        Aux = get_Tratamiento (ListD_Copy(Lturno));
        if(Aux[Treatment-1])
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
    free (Aux);
}

void PrecargaAutomatica (Lista_de_Clientes *Lclientes)
{
    Cliente Caux;
    int Vid,Vcanttrat,Vnivel;
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
        while (!feof(Fp))
        {
         fscanf (Fp,"%d",&Vid);
         fscanf (Fp,"%s",Vnomb);
         fscanf (Fp,"%s",Vape);
         fscanf (Fp,"%d",&Vcanttrat);
         fscanf (Fp,"%d",&Vnivel);
         set_ID_Cliente(&Caux,Vid);
         set_Nombre(&Caux,Vnomb);
         set_Apellido(&Caux,Vape);
         set_CantTratamientos(&Caux,Vcanttrat);
         set_Nivel(&Caux,Vnivel);
         ListE_Insert(Lclientes, Caux);
         }
         fclose(Fp);
    }
}

void MuestraAllClientes (Lista_de_Clientes Listclient)
{
    Cliente Aux;
    ListE_Reset (&Listclient);
    while (!ListE_IsOos(Listclient))
    {
        Aux = ListE_Copy(Listclient);
        printf ("ID cliente: %d \n", get_ID_Cliente(Aux));
        printf ("Nombre: %s \n", get_Nombre(Aux));
        printf ("Apellido: %s \n", get_Apellido(Aux));
        printf ("Cantidad de tratamientos: %d \n", get_CantTratamientos(Aux));
        printf ("Nivel: %d \n \n", get_Nivel(Aux));
        ListE_Forward(&Listclient);
    }
}

void EliminarClienteSegunIdcliente (Lista_de_Clientes *Lcliente)
{
    int IDaux;
    char AuxChar;
    Cliente ClientAux;
    printf("Ingrese la ID del cliente a eliminar: ");
    scanf("%d",&IDaux);
    while (!ListE_IsOos(*Lcliente) && get_ID_Cliente(ListE_Copy(*Lcliente)) != IDaux)
    {
        ListE_Forward(Lcliente);
    }
    if (ListE_IsOos(*Lcliente))
    {
        printf ("No se encontro un cliente con ese ID \n");
        return;
    }
        ClientAux = ListE_Copy(*Lcliente);
        printf ("ID cliente: %d \n", get_ID_Cliente(ClientAux));
        printf ("Nombre: %s \n", get_Nombre(ClientAux));
        printf ("Apellido: %s \n", get_Apellido(ClientAux));
        printf ("Cantidad de tratamientos: %d \n", get_CantTratamientos(ClientAux));
        printf ("Nivel: %d \n \n", get_Nivel(ClientAux));
        printf ("\n\n Desea eliminar este cliente? (Y/N)\n");
        scanf ("%c", &AuxChar);
    while (AuxChar != 'Y' && AuxChar != 'N')
    {
        printf ("Opcion incorrecta (Y/N) \n");
        scanf ("%c", &AuxChar);
    }
    if (AuxChar == 'N')
        return;
    ListE_Suppres (Lcliente);
    printf ("El cliente fue borrado con exito \n");
}

void ConfirmaturnoIdcliente(Lista_de_Clientes *Lcliente, Lista_de_Turnos *Lturno)
{
    int SumTrat = 0,IDaux;
    Cliente ClienteAux;
    turno TurnoAux;
    int *Aux;
    ListE_Reset(Lcliente);
    printf("Ingrese la ID del cliente para cambiar su turno a realizado: ");
    scanf("%d",&IDaux);
    if(!BuscarTurnoPorIdcliente(Lturno,IDaux))
    {
        printf("No se ha encontrado un turno no realizado para esa ID\n");
        return;
        }
    while (!ListE_IsOos(*Lcliente) && get_ID_Cliente(ListE_Copy(*Lcliente)) != IDaux)
    {
        ListE_Forward(Lcliente);
    }
    if (ListE_IsOos(*Lcliente))
    {
        TurnoAux = ListD_Copy(*Lturno);
        if (get_Forma_de_pago(TurnoAux) == 1)
        {
            printf("Metodo de pago: Debito\n");
            printf ("presione cualquier tecla para continuar \n");
            getchar ();
        }
        if (get_Forma_de_pago(TurnoAux) == 2)
        {
            printf("Metodo de pago: Credito\n");
            printf ("presione cualquier tecla para continuar \n");
            getchar ();
        }
        if (get_Forma_de_pago(TurnoAux) == 3)
        {
            printf("Metodo de pago: QR\n");
            printf ("\n ------ \n|@ Code|\n| QR @ |\n ------ \n");
            printf ("presione cualquier tecla para continuar \n");
            getchar ();
        }
        else
            {
            printf("Metodo de pago: Efectivo\n");
            printf ("presione cualquier tecla para continuar \n");
            getchar ();
            }
        set_Realizado(&TurnoAux);
        printf("Turno modificado correctamente\n");
        ListD_Suppresor (Lturno);
        ListD_Pusher (Lturno, TurnoAux);
    }
    else
    {
        TurnoAux = ListD_Copy(*Lturno);
        ClienteAux= ListE_Copy(*Lcliente);
        Aux = get_Tratamiento(TurnoAux);
        if (get_Forma_de_pago(TurnoAux) == 1)
        {
            printf("Metodo de pago: Debito\n");
            printf ("presione cualquier tecla para continuar \n");
            getchar ();
        }
        if (get_Forma_de_pago(TurnoAux) == 2)
        {
            printf("Metodo de pago: Credito\n");
            printf ("presione cualquier tecla para continuar \n");
            getchar ();
        }
        if (get_Forma_de_pago(TurnoAux) == 3)
        {
            printf("Metodo de pago: QR\n");
            printf ("\n ------ \n|@ Code|\n| QR @ |\n ------ \n");
            printf ("presione cualquier tecla para continuar \n");
            getchar ();
        }
        else
            {
            printf("Metodo de pago: Efectivo\n");
            printf ("presione cualquier tecla para continuar \n");
            getchar ();
            }
        set_Realizado(&TurnoAux);
        ListD_Suppresor (Lturno);
        ListD_Pusher (Lturno, TurnoAux);
        for (IDaux=0;IDaux<10;IDaux++)
            SumTrat += Aux[IDaux];
        Aux[0]=get_CantTratamientos (ClienteAux);
        SumTrat+=Aux[0];
        set_CantTratamientos(&ClienteAux, SumTrat);
        if (SumTrat<5)
            set_Nivel(&ClienteAux, 1);
        if (SumTrat>4&&SumTrat<11)
            set_Nivel(&ClienteAux, 2);
        if (SumTrat>10)
            set_Nivel(&ClienteAux, 3);
        printf("Turno y cliente modificado correctamente\n");
        ListE_Suppres(Lcliente);
        ListE_Insert(Lcliente,ClienteAux);
    }
    free(Aux);
}

void MuestraAllTurnosNoRealizado (Lista_de_Turnos Lturno)
{
    turno TAuxiliar;
    int *Aux;
    ListD_Reset (&Lturno);
    printf("Turnos sin realizar:\n\n");
    while (!ListD_IsOos(Lturno))
    {
        if(get_Realizado(ListD_Copy(Lturno))==0)
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
    free(Aux);
}