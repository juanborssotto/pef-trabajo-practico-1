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

int cuartoOriginal(dato *f, int cant, float &registro);
int cuartoCorregido(dato *f, int cant, float &registro);
int main()
{
    int cant = 0;
    float total = 0.0;
    // creo la lista y creando todos los nodos de la misma
    dato *a, *b, *c, *d, *e;
    a = new dato;
    b = new dato;
    c = new dato;
    d = new dato;
    e = new dato;

    a->dest = 101;
    a->tam = 10000;
    a->next = b;

    b->dest = 20;
    b->tam = 20000;
    b->next = c;

    c->dest = 101;
    c->tam = 20000;
    c->next = d;

    d->dest = 10;
    d->tam = 10000;
    d->next = e;

    e->dest = 20;
    e->tam = 10000;
    e->next = NULL;

    int cantidad = cuartoOriginal(a,cant,total);
    assert(cantidad == 2); // cantidad de paquetes enviados al primer destino
    cout << "La cantidad de datos enviados al primer destino en la lista es " << cantidad << endl;
    assert(total == 70); // suma total de kilobytes transmitidos hacia todos los destinos
    cout << "El total de kilobytes transmitidos a todos los destinos es " << total << endl;

    return 0;
}

int cuartoOriginal(dato *f, int cant, float &total)
{
    int c = 0, i = 0;
    float tam = 0.0, dest = 0.0;
    dest = f->dest;

    while (f != NULL)
    {
        if (f->dest == dest)
        {
            c++;
            tam += f->tam;
        }
        total = tam / 1000;

        f = f->next;
    }
    return c;
}

int cuartoCorregido(dato *f, int cant, float &total)
{
    int c = 0, i = 0;
    float tam = 0.0, dest = 0.0;
    dest = f->dest;

    while (f != NULL)
    {
        if (f->dest == dest)
        {
            c++;
        }
        tam += f->tam;
        total = tam / 1000;

        f = f->next;
    }
    return c;
}