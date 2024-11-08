#include <malloc.h>
#include "turno.h"

struct nodo
{
    turno Vipd;
    struct nodo *Next;
};

typedef struct nodo Nodo;

typedef struct
{
    Nodo *Acesso;
    Nodo *Cursor;
    Nodo *CursorAux;
} Lista_de_Turnos;

// Inicializador //

void ListD_Starter (Lista_de_Turnos *Aux)
{
    (*Aux).Acesso = NULL;
    (*Aux).Cursor = NULL;
    (*Aux).CursorAux = NULL;
}

// Operadores sin retorno //

void ListD_Pusher (Lista_de_Turnos *Aux, turno Aux2)
{
    Nodo *A = (Nodo*)malloc (sizeof(Nodo));
    if ((*Aux).Cursor == (*Aux).Acesso)
    {
        (*Aux).Acesso = A;
        (*A).Next = (*Aux).Cursor;
        (*Aux).CursorAux = (*Aux).Acesso;
        (*Aux).Cursor = (*Aux).Acesso;
    }
    else
    {
        (*Aux).CursorAux ->Next = A;
        A->Next = (*Aux).Cursor;
        (*Aux).Cursor = A;
    }
    (*A).Vipd = Aux2;
}

void ListD_Suppresor (Lista_de_Turnos *Aux)
{
    if ((*Aux).Cursor == (*Aux).Acesso)
    {
        (*Aux).Acesso = (*Aux).Acesso->Next;
        free ((*Aux).Cursor);
        (*Aux).CursorAux = (*Aux).Acesso;
        (*Aux).Cursor = (*Aux).Acesso;
    }
    else
    {
    (*Aux).Cursor = (*Aux).Cursor->Next;
    free ((*Aux).CursorAux->Next);
    (*Aux).CursorAux->Next = (*Aux).Cursor;
    }
}

void ListD_Reset (Lista_de_Turnos *Aux)
{
    (*Aux).Cursor = (*Aux).Acesso;
    (*Aux).CursorAux = (*Aux).Acesso;
}

void ListD_Forward (Lista_de_Turnos *Aux)
{
    (*Aux).CursorAux = (*Aux).Cursor;
    (*Aux).Cursor = (*Aux).Cursor->Next;
}

// Operadores con reotrno //

turno ListD_Copy (Lista_de_Turnos Aux)
{
    return Aux.Cursor->Vipd;
}

int ListD_IsEmpty (Lista_de_Turnos Aux)
{
if (Aux.Acesso == NULL)
return 1;
else
return 0;
}

int ListD_IsOos (Lista_de_Turnos Aux)
{
if (Aux.Cursor == NULL)
return 1;
else
return 0;
}

int ListD_IsFull ()
{
Nodo *Aux;
Aux = (Nodo*)malloc(sizeof (Nodo));
if (Aux == NULL)
{
    free (Aux);
    return 1;
}
else
{
    free (Aux);
    return 0;
}
}