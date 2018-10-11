#include <iostream>
#include <fstream>
#include <iomanip>
#include <assert.h>

using namespace std;

struct dato
{
    float hora, min, seg, tam, dest, num;
    dato *next;
};

void mostrar(dato *d, int cant);
void mostrarCorregido(dato *d, int cant);

int main()
{
    dato *resultado;
    dato *n1, *n2, *n3, *n4, *n5;

    n1 = new dato;
    n2 = new dato;
    n3 = new dato;


    n1->next = n2;
    n1->hora = 11;
    n1->min = 11;
    n1->seg = 11;
    n1->tam = 11;
    n1->dest = 11;
    n1->num = 11;


    n2->next = n3;
    n2->hora = 22;
    n2->min = 22;
    n2->seg = 22;
    n2->tam = 22;
    n2->dest = 22;
    n2->num = 22;


    n3->next = n4;
    n3->hora = 33;
    n3->min =  33;
    n3->seg =  33;
    n3->tam =  33;
    n3->dest = 33;
    n3->num =  33;

    cout << "---------------------mostrar---------------------" << endl;
    mostrar(n1, 7);
    cout << "---------------------mostrarCorregido---------------------" << endl;
    mostrarCorregido(n1, 7);


    cout << "FIN programa" << endl;

    return 0;
}

/* observaciones: 1) la funcion muestra cant-1 datos, no es claro, podria directamente mostrar cant valores
                  2) no controla que cant sea mayor que la cantidad de datos enlistados
*/
void mostrar(dato *d, int cant)
{
    int i = 0;
    for (i = 0; i < cant - 1; i++)
    {
        cout << setw(7) << d->hora << setw(7) << d->min << setw(7) << d->seg << setw(7) << d->tam << setw(7) << d->dest << endl;
        d = d->next;
    }
}

/* correccion: 2) ahora solo muestra hasta donde puede
*/
void mostrarCorregido(dato *d, int cant)
{
    int i = 0;
    for (i = 0; i < cant - 1; i++)
    {
        cout << setw(7) << d->hora << setw(7) << d->min << setw(7) << d->seg << setw(7) << d->tam << setw(7) << d->dest << endl;
        d = d->next;
        if (d == NULL) break;
    }
}