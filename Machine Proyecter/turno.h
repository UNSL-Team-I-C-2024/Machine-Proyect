#include <string.h>
#include <stdlib.h>

typedef struct
{
    int Dia;
    int Mes;
    int Anio;
    int Hora;
}fecha;

typedef struct
{
    int Idturno;
    char Nombre[31];
    int IdCliente;
    int Tratatamiento[10]; // 0 no y 1 si //
    int Forma_de_pago; // codificar tipos
    float Total;
    fecha Fecha_de_turno;
    int Realizado; // 0 si esta pendiente y 1 si fue a hacerlo //
}turno;

// INICIALIZADO

void init_Turno(turno *turno){
    int i;
    (*turno).Idturno=0;
    strcpy((*turno).Nombre,"NULL");
    (*turno).IdCliente=0;
    for(i=0;i<10;i++){
        (*turno).Tratatamiento[i]=0;
    }
    (*turno).Forma_de_pago=0;
    (*turno).Total=0;
    (*turno).Fecha_de_turno.Dia=0;
    (*turno).Fecha_de_turno.Mes=0;
    (*turno).Fecha_de_turno.Anio=0;
    (*turno).Fecha_de_turno.Hora=0;
    (*turno).Realizado=0;
}

// SETS

void set_Idturno (turno *turno,int Idturno){
    (*turno).Idturno=Idturno;
}

void set_Nombre_Turno (turno *turno,char Nombre[])
{
    strcpy((*turno).Nombre,Nombre);
}

void set_IdCliente_turno(turno *turno,int IdCLiente){
    (*turno).IdCliente=IdCLiente;
}

void set_Tratamiento(turno *turno,int i){
(*turno).Tratatamiento[i] = 1;
}

void set_Forma_de_pago(turno *turno,int Forma_de_pago){
    (*turno).Forma_de_pago=Forma_de_pago;
}

void set_Total(turno *turno,int Total){
    (*turno).Total=Total;
}

void set_Fecha_Dia(turno *turno,int Dia){
    (*turno).Fecha_de_turno.Dia=Dia;
}

void set_Fecha_mes(turno *turno,int Mes){
    (*turno).Fecha_de_turno.Mes=Mes;
}

void set_Fecha_Anio(turno *turno,int Anio){
    (*turno).Fecha_de_turno.Anio=Anio;
}

void set_Fecha_Hora(turno *turno,int Hora){
    (*turno).Fecha_de_turno.Hora=Hora;
}

void set_Realizado(turno *turno,int Realizado){
    (*turno).Realizado=Realizado;
}

// GETS

int get_IdTurno(turno turno){
    return turno.Idturno;
}

char* get_Nombre_Turno(turno turno){
    char *caracter=(char*)malloc(sizeof(turno.Nombre));
    strcpy(caracter,turno.Nombre);
    return caracter;
}

int get_IdCliente_turno(turno turno){
    return turno.IdCliente;
}

int* get_Tratamiento(turno turno){
    int i;
    int *entero=(int*)malloc(sizeof(turno.Tratatamiento));
    for(i=0;i<10;i++){
        entero[i]=turno.Tratatamiento[i];
    }
    return entero;
}

int get_Forma_de_pago(turno turno){
    return turno.Forma_de_pago;
}

float get_Total(turno turno){
    return turno.Total;
}

int get_Fecha_Anio(turno turno){
    return turno.Fecha_de_turno.Anio;
}

int get_Fecha_Mes(turno turno){
    return turno.Fecha_de_turno.Mes;
}

int get_Fecha_Dia(turno turno){
    return turno.Fecha_de_turno.Dia;
}

int get_Fecha_Hora(turno turno){
    return turno.Fecha_de_turno.Hora;
}

int get_Realizado(turno turno){
    return turno.Realizado;
}