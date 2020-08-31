#include "ordenamiento.h"
#include <stdio.h>

void ord_burbujeo(int* v,int cantElem)
{
    int i=1,j; //i ES LA CANTIDAD DE PASADAS
    int huboIntercambios=1; //VARIABLE BOOLEANA

        while(huboIntercambios && i<cantElem)
        {
            huboIntercambios=0;
                for(j=0;j<cantElem-i;j++)
                {
                    if(v[j] > v[j+1])
                    {
                        intercambiar (&v[j],&v[j+1]);
                        huboIntercambios=1;
                    }
                }

                i++;
        }

}

/*void ord_seleccion(int* v, int cantElem)
{
    int m;
        for(int i=0;i<cantElem-1;i++)
        {
            m=buscar_menor(v,i,cantElem-1);
                if(m!=i)
                    intercambiar(&v[m],&v[i]);
        }
}

void ord_insercion(int* v,int cantElem)
{
    int j, elemAIns;
        for(int i=1;i<cantElem;i++)
        {
            elemAIns=v[i];
            j=i-1;
                while(j>=0 && elemAIns < v[j])
                {
                    v[j+1]=v[j];
                    j--;
                }

            v[j+1]=elemAIns;
        }
}*/

void ord_seleccion(int* v, int cantElem) //CON ARITMETICA DE PUNTEROS, SOLO ORDENA VECTORES DE ENTEROS
{
    int* m;
    int* ult= v + cantElem-1; ///ult= v + (cantElem-1) + sizeof(int)
        for(int* i=v;i<ult;i++) ///SE COMPARA DIRECCIONES DE MEMORIA, NO CONTENIDOS.
        {
            m=buscar_menor(i,ult); ///ME DEVUELVE LA DIRECCION DEL MENOR. ///MAS EFICIENTE, YA QUE TIENE UN PARAMETRO MENOS.
                if(m!=i)
                    intercambiar(m,i); ///INTERCAMBIA DIRECCIONES, NO HACE FALTA EL &.
        }
}

void ord_insercion(int* v,int cantElem) //CON ARITMETICA DE PUNTEROS
{
    int* j;
    int* elemAIns;
    int* ult= v + cantElem-1;

        for(int* i=v;i<ult;i++)
        {
            elemAIns=i;
            j=i-1;
                while(j>=0 && elemAIns < j)
                {
                    j=j-1;
                    j--;
                }

            j=elemAIns-1;
        }
}

void intercambiar(int* a,int* b)
{
    int aux = *a; //aux=x
    *a = *b; //x=y
    *b = aux; //y=aux

}
/*int buscar_menor(int* a,int desde,int hasta)
{
    int m = desde;

        for(int j=desde+1; j<=hasta; j++)
        {
            if(a[j] < a[m])
                m=j;
        }

        return m;
}*/

int* buscar_menor(int *desde,int *hasta) //CON ARITMETICA DE PUNTEROS
{
    int* m = desde;

        for(int* j=desde+1; j<=hasta; j++)
        {
            if(*j < *m)
                m=j;
        }

        return m;
}

void mostrar_vec(int* v,int cantElem) //CON ARITMETICA DE PUNTEROS
{
    int* ult= v + cantElem-1;

    for(int* i = v; i <= ult; i++)
    {
        printf("\n%d",*i);
    }
}
