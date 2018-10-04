#include <iostream>
#include <assert.h>
using namespace std;

struct dato{
 float hora,min,seg,tam,dest,num;
 dato *next;
};
float cinco(dato *f,int cant);

int main () {
  dato *d1, *d2;
  d1 = new dato;
  d2 = new dato;
  d1->hora = 12;
  d1->min = 00;
  d1->seg = 00;
  d1->tam = 1000;
  d1->dest = 00;
  d1->num = 100;

  d2->hora = 12;
  d2->min = 03;
  d2->seg = 00;
  d2->tam = 2000;
  d2->dest = 00;
  d2->num = 100;

  d1->next = d2;


  float resultado = cinco(d1, 3);
  float resultadoEsperado[2];
  resultadoEsperado[0] = 1.0;
  resultadoEsperado[1] = 1.0;
  assert(resultado == resultadoEsperado);
}

float cinco(dato *f,int cant){
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
 return 0.5; 
}