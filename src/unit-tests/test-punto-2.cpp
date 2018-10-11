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

dato* agregardato  (dato *l, dato *n);
dato* agregardatoCorregido  (dato *l, dato *n);

int main()
{
    
    dato *resultado;
    dato *n1, *n2, *n3, *n4, *n5;
    
    //--------------------- caso: ambos tienen un valor ---------------------

    n1 = new dato;
    n2 = new dato;
    n3 = new dato;
    n4 = new dato;
    n5 = new dato;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    resultado = agregardato(n1, n5);
    assert(resultado != NULL);

    //--------------------- caso: lista NULL ---------------------
    
    n1 = NULL;
    n2 = new dato;
    n3 = new dato;
    n4 = new dato;
    n5 = new dato;

    n2->next = n3;
    n3->next = n4;

    resultado = agregardato(n1, n5);
    assert(resultado != NULL);


    //--------------------- caso: lista y nodo NULL ---------------------

    n1 = NULL;
    n5 = NULL;

    resultado = agregardato(n1, n5); 
    assert(resultado != NULL); // FAIL

    
    //--------------------- caso: lista con valor y nodo NULL ---------------------
    
    n5 = NULL;
    n1 = new dato;
    n2 = new dato;
    n3 = new dato;
    n4 = new dato;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    resultado = agregardato(n1, n5); 
    assert(resultado != NULL);

    cout << "FIN programa" << endl;

    return 0;
}

/*  supuestamente agrega n a la lista l
    observaciones:
    1) si l es NULL entonces la lista es igual a n, pero no controla que n pueda ser NULL
*/
dato* agregardato  (dato *l, dato *n) {
  dato *aux=NULL;

  if (l==NULL) { 
    l=n;        
  }
  else {  
    aux=l;
    while(aux->next!=NULL) { 
      aux=aux->next;
    }
    aux->next=n;
  }

  return l;
} 


dato* agregardatoCorregido  (dato *l, dato *n) {
  dato *aux=NULL;
  
  if(n==NULL) {
    return NULL;
  }

  if (l==NULL) { 
    l=n;        
  }
  else {  
    aux=l;
    while(aux->next!=NULL) { 
      aux=aux->next;
    }
    aux->next=n;
  }

  return l;
} 