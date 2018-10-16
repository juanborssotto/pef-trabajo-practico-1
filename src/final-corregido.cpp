#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;
struct dato
{
    float hora, min, seg, tam, dest, num;

    dato *next;
};
dato *lee(char nombre[30], int &cant, int &error);
dato *creardato(void);
dato *agregardato(dato *l, dato *n);
float *cinco(dato *f, int &length);
void sumarMinutos(int *h, int *m, int minutosSumar);
bool horaMenor(int h1, int m1, int s1, int h2, int m2, int s2);

void mostrar(dato *d, int cant);
void borrar(dato *l);
int cuarto(dato *f, float &total);
int main()
{
    dato info, *aux = NULL, *lista = NULL;
    int cant = 0, error = 0, i = 0, paquetes = 0, len = 0;
    float total = 0.0, *vec;
    char nombre[30];

    cout << "ingrese nombre archivo: " << endl;
    cin >> nombre;
    lista = lee(nombre, cant, error);

    if (error == 1)
    {
        cerr << "hubo algun problema interno." << endl;
    }

    cout << "lista length -> " << cant << endl;

    cout << "*********** CONTENIDO LISTA ***************" << endl;
    mostrar(lista, cant);

    paquetes = cuarto(lista, total);

    vec = cinco(lista, len);    
    for (i = 0; i < len; i++)
    {
        cout << "vec[" << i << "] = " << vec[i] << " bytes" << endl;
    }
    delete vec;

    borrar(lista);

    borrar(lista);

    return 0;
}

dato *lee(char nombre[30], int &cant, int &error)
{

    dato *aux = NULL, *lista = NULL;
    ifstream entrada;
    float total = 0.0;

    entrada.open(nombre);

    if (entrada.fail())
    {
        error = 1;
    }
    else
    {

        while (!entrada.eof())
        {
            cant++;
            aux = creardato();

            entrada >> aux->hora;

            entrada >> aux->min;

            entrada >> aux->seg;

            entrada >> aux->tam;

            entrada >> aux->dest;

            lista = agregardato(lista, aux);
        }
        entrada.close();
    }
    return lista;
}

dato *creardato(void)
{
    dato *aux = NULL;

    aux = new dato;
    if (aux == NULL)
    {
        cerr << "Memoria insuficiente" << endl;
    }
    else
    {

        aux->next = NULL;
    }
    // cout << "creando dato" << endl;
    return aux;
}

dato *agregardato(dato *l, dato *n)
{
    dato *aux = NULL;

    if (n == NULL)
    {
        return NULL;
    }

    if (l == NULL)
    {
        l = n;
    }
    else
    {
        aux = l;
        while (aux->next != NULL)
        {
            aux = aux->next;
        }
        aux->next = n;
    }

    return l;
}
void mostrar(dato *d, int cant)
{
    int i = 0;
    for (i = 0; i < cant; i++)
    {
        // cout << setw(7) << d->hora << setw(7) << d->min << setw(7) << d->seg << setw(7) << d->tam << setw(7) << d->dest << endl;
        d = d->next;
        if (d == NULL)
            break;
    }
}
void borrar(dato *l)
{
    dato *aux = NULL;
    while (l != NULL)
    {
        aux = l;
        l = l->next;
        delete aux;
    }
}
int cuarto(dato *f, float &total)
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

float *cinco(dato *f, int &length)
{    
    float *v = NULL;
    float difh = 0, difm = 0, difs = 0;
    float hinicial = 0, hfinal = 0, minicial = 0, mfinal = 0, sinicial = 0, sfinal = 0;
    dato *aux;    
    hinicial = f->hora;
    minicial = f->min;
    sinicial = f->seg;

    aux = f;
    do
    {
        aux = aux->next;
        hfinal = aux->hora;
        mfinal = aux->min;
        sfinal = aux->seg;
    } while (aux->next != NULL);
    

    difh = hfinal - hinicial;
    difm = mfinal - minicial;
    difs = sfinal - sinicial;

    int intervalos = ceil(((difh * 3600 + difm * 60 + difs) / 60) / 5);         
    length = intervalos;
    v = new float[intervalos];    

    aux = f;
    int hPeriodo = aux->hora, mPeriodo = aux->min, sPeriodo = aux->seg;
    float bytesAcum;
    int contadorNodosProcesados = 0;
    int i, j;
    for (i = 0; i < intervalos; i++)
    {
        aux = f;
        for (j = 0; j < contadorNodosProcesados; j++)
            aux = aux->next;
        bytesAcum = 0.0;
        sumarMinutos(&hPeriodo, &mPeriodo, 5);
        do
        {
            if (horaMenor(aux->hora, aux->min, aux->seg, hPeriodo, mPeriodo, sPeriodo))
            {
                bytesAcum += aux->tam;
                contadorNodosProcesados++;
            }
            else 
              break;
            aux = aux->next;
        } while (aux != NULL);
        v[i] = bytesAcum / ((i + 1) * 5 * 60);
    }
    return v;
}

void sumarMinutos(int *h, int *m, int minutosSumar)
{
    *m += 5;
    if (*m >= 60)
    {
        *h = *h + 1;
        *m = *m - 60;
        if (*h == 23)
        {
            *h = 0;
        }
    }
}

bool horaMenor(int h1, int m1, int s1, int h2, int m2, int s2)
{
    if (h1 < h2)
    {
        return true;
    }
    else if (h1 == h2)
    {
        if (m1 < m2)
        {
            return true;
        }
        else if (m1 == m2)
        {
            if (s1 < s2)
            {
                return true;
            }
        }
    }
    return false;
}