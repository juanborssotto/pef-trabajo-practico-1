#include <iostream>
#include <assert.h>
#include <cmath>
using namespace std;

struct dato{
 int hora, min, seg, dest, num;
 float tam;
 dato *next;
};
float cincoOriginal(dato *f, int cant);
float* cincoCorregida(dato *f);
void sumarMinutos(int *h, int *m, int minutosSumar);
bool horaMenor(int h1, int m1, int s1, int h2, int m2, int s2);

int main () {
  dato *d1, *d2, *d3, *d4;
  d1 = new dato;
  d2 = new dato;
  d3 = new dato;
  d4 = new dato;

  d1->hora = 12;
  d1->min = 0;
  d1->seg = 0;
  d1->tam = 1000.0;
  d1->dest = 0;
  d1->num = 100;
  d1->next = d2;

  d2->hora = 12;
  d2->min = 3;
  d2->seg = 0;
  d2->tam = 2000.0;
  d2->dest = 0;
  d2->num = 100;
  d2->next = d3;

  d3->hora = 12;
  d3->min = 17;
  d3->seg = 0;
  d3->tam = 2500.0;
  d3->dest = 0;
  d3->num = 100;
  d3->next = d4;

  d4->hora = 12;
  d4->min = 24;
  d4->seg = 0;
  d4->tam = 3000.0;
  d4->dest = 0;
  d4->num = 100;
  d4->next = NULL;
  int i, tamArray = 5;

  //No se puede correr con la original ya que no retorna el tipo correcto.
  // float* resultado = cincoOriginal(d1, 5);
  float* resultado = cincoCorregida(d1);
  float *resultadoEsperado = new float[tamArray];
  resultadoEsperado[0] = 10.0;
  resultadoEsperado[1] = 0.0;
  resultadoEsperado[2] = 0.0;
  resultadoEsperado[3] = 2.0833333;
  resultadoEsperado[4] = 2.0;
  for(i = 0; i < tamArray; i++) {
    assert(resultado[i] == resultadoEsperado[i]);
  }
}


float cincoOriginal(dato *f, int cant){
  float *v=NULL,difh=0.0,tamvector=0.0,difm=0.0,difs=0.0,totalsegundos=0.0,hinicial=0.0,hfinal=0.0,minicial=0.0,mfinal=0.0,sinicial=0.0,sfinal=0.0;
  int i=0;
  hinicial=f->hora;
  minicial=f->min;
  sinicial=f->seg;

  for(i=0;i<cant-2;i++){
   f=f->next;
   hfinal=f->hora;
   mfinal=f->min;
   sfinal=f->seg;
 }
 difh=hfinal - hinicial;
 difm=mfinal - minicial;
 difs=sfinal - sinicial;
 totalsegundos=difh*36000 + difm*60 + difs;
 cout<<"hora inicial"<<totalsegundos<<"hora final"<<hfinal<<endl;
 tamvector=totalsegundos/5;
 v=new float[int(tamvector)];
}

float* cincoCorregida(dato *f){
  float *v = NULL;
  float difh = 0, difm = 0, difs = 0;
  float hinicial=0, hfinal=0, minicial=0, mfinal=0, sinicial=0, sfinal=0;
  dato *aux;

  hinicial=f->hora;
  minicial=f->min;
  sinicial=f->seg;

  aux = f;
  do {
    aux = aux->next;
    hfinal = aux->hora;
    mfinal = aux->min;
    sfinal = aux->seg;
  } while(aux->next != NULL);

  difh = hfinal - hinicial;
  difm = mfinal - minicial;
  difs = sfinal - sinicial;

  int intervalos = ceil(((difh * 3600 + difm * 60 + difs) / 60) / 5);
  v = new float[intervalos];

  aux = f;
  int hPeriodo = aux->hora, mPeriodo = aux->min, sPeriodo = aux->seg;
  float bytesAcum;
  int contadorNodosProcesados = 0;
  int i, j;
  for(i = 0; i < intervalos; i++) {
    aux = f;
    for(j = 0; j < contadorNodosProcesados; j++)
      aux = aux->next; 
    bytesAcum = 0.0;
    sumarMinutos(&hPeriodo, &mPeriodo, 5);
    do {
      if(horaMenor(aux->hora, aux->min, aux->seg, hPeriodo, mPeriodo, sPeriodo)) {
        bytesAcum += aux->tam;
        contadorNodosProcesados++;
      }
      aux = aux->next;
    }
    while(aux != NULL);
    v[i] = bytesAcum / ((i + 1) * 5 * 60);
  }
  return v;
}

void sumarMinutos(int *h, int *m, int minutosSumar) {
  *m += 5;
  if(*m >= 60) {
    *h = *h + 1;
    *m = *m - 60;
    if(*h == 23) {
      *h = 0;
    }
  }
}

bool horaMenor(int h1, int m1, int s1, int h2, int m2, int s2) {
  if (h1 < h2) {
    return true;
  }
  else if (h1 == h2) {
    if (m1 < m2) {
      return true;
    }
    else if (m1 == m2) {
      if (s1 < s2) {
        return true;
      }
    }
  }
  return false;
}