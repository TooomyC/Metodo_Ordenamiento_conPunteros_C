#include <stdio.h>
#include "ordenamiento.h"
#define TAM_VEC 7

int main()
{
    int v[TAM_VEC]={3,10,1,4,6,8,2};


    //ord_burbujeo(v,TAM_VEC);
   // printf("\nOrdenamiento por Burbujeo");
    //mostrar_vec(v,TAM_VEC);


    ord_seleccion(v,TAM_VEC);
    printf("\n\nOrdenamiento por Seleccion");
    mostrar_vec(v,TAM_VEC);


    ord_insercion(v,TAM_VEC);
    printf("\n\nOrdenamiento por Insercion");
    mostrar_vec(v,TAM_VEC);

    getch();
}
