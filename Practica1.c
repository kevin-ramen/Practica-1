#include <stdio.h>
#include <stdlib.h>
#include "elem.h"
#include "lista.h"

int main(){
	Lista l = cons(8,cons(4,cons(6,cons(1,cons(3,cons(0,cons(2,cons(7,cons(9,vacia())))))))));
	ImpLista(OrdenaListaMezcla(l));
	return 0;
}
