#include <stdio.h>
#include <stdlib.h>
#include "elem.h"
#include "lista.h"

int main(){
	Lista l;
	Lista x = cons(8,cons(4,cons(6,cons(1,cons(3,vacia())))));
	Lista y = cons(0,cons(2,cons(7,cons(9,vacia()))));
	l = OrdenaListaMezcla(x,y);
	ImpLista(l);
	return 0;
}
