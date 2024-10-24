#include "cliente.h"
#define Max 100

typedef struct
{
    Cliente Vipd[Max];
    int Cursor;
    int Ultimo;
} Lista_de_Clientes;

// Inicializador //

void ListE_Starter (Lista_de_Clientes *Aux)
{
    (*Aux).Cursor = 0;
    (*Aux).Ultimo = -1;
}

// Operadores sin retorno //

void ListE_Insert (Lista_de_Clientes *Aux, Cliente Aux2)
{
    int Counter;
    for (Counter=(*Aux).Ultimo+1;Counter>(*Aux).Cursor;Counter--)
    {
        (*Aux).Vipd[Counter] = (*Aux).Vipd[Counter-1];
    }
    (*Aux).Ultimo += 1;
    (*Aux).Vipd[(*Aux).Cursor] = Aux2;
}

void ListE_Suppres (Lista_de_Clientes *Aux)
{
    int Counter;
    for (Counter=(*Aux).Cursor;Counter<(*Aux).Ultimo;Counter++)
    {
        (*Aux).Vipd[Counter] = (*Aux).Vipd[Counter+1];
    }
    (*Aux).Ultimo -= 1;
}

void ListE_Reset (Lista_de_Clientes *Aux)
{
    (*Aux).Cursor=0;
}

void ListE_Forward (Lista_de_Clientes *Aux)
{
    (*Aux).Cursor += 1;
}

// Operadores con retorno //

Cliente ListE_Copy (Lista_de_Clientes Aux)
{
    return Aux.Vipd[Aux.Cursor];
}

int ListE_IsEmpty (Lista_de_Clientes Aux)
{
    if (Aux.Ultimo < 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int ListE_IsFull (Lista_de_Clientes Aux)
{
    if (Aux.Ultimo >= Max-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int ListE_IsOos (Lista_de_Clientes Aux)
{
    if (Aux.Cursor > Aux.Ultimo)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}