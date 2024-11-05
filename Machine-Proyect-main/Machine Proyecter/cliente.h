#include <string.h>
#include <malloc.h>

typedef struct{
    int Id_Cliente;
    char Nombre [51];
    char Apellido [51];
    int Cant_Tratamientos;
    int Nivel; // 0 si tratamientos 0
} Cliente;

// inicializacion //

void clienteInit (Cliente *client){
    (*client).Id_Cliente=0;
    strcpy(client->Nombre, "NULL");
    strcpy(client->Apellido,"NULL");
    (*client).Cant_Tratamientos=0;
    (*client).Nivel=0;
}

// sets //
void set_ID_Cliente(Cliente *client, int ID){
    (*client).Id_Cliente=ID;
}

void set_Nombre(Cliente *client, char Name[]){
    strcpy(client->Nombre,Name);
}

void set_Apellido(Cliente *client, char Ape[]){
    strcpy(client->Apellido,Ape);
}

void set_CantTratamientos(Cliente *client, int CantTreatments){
    (*client).Cant_Tratamientos=CantTreatments;
}

void set_Nivel(Cliente *client, int Nivel){
    (*client).Nivel=Nivel;
}

// gets //
int get_ID_Cliente(Cliente client){
    return client.Id_Cliente;
}

char* get_Nombre(Cliente client){
    char *caracter;
    caracter=(char*)malloc(sizeof(client.Nombre)+1);
    strcpy(caracter,client.Nombre);
    return caracter;
}

char* get_Apellido(Cliente client){
    char *caracter;
    caracter=(char*)malloc(sizeof(client.Apellido)+1);
    strcpy(caracter,client.Apellido);
    return caracter;
}

int get_CantTratamientos(Cliente client){
    return client.Cant_Tratamientos;
}

int get_Nivel(Cliente client){
    return client.Nivel;
}