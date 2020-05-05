#include <math.h>
//TDA
typedef struct Nodo{
	Elem dato;
	struct Nodo *sig;	
}*Lista;

Lista vacia(){return NULL;}

Lista cons(Elem e,Lista l){
	Lista t = (Lista)malloc(sizeof(struct Nodo));
	t->dato=e;
	t->sig=l;
	return t;
}

Elem cabeza(Lista l){return l->dato;}

int esvacia(Lista l){return l==NULL;}

Lista resto(Lista l){
	Lista p = (Lista)malloc(sizeof(struct Nodo));
	p = l->sig;
	return p; 
}

//Mas Funciones

int NumElemLista(Lista l){
	if(esvacia(l)){
		return 0;
	}else{
		return 1+NumElemLista(resto(l));
	}
}

void ImpListaF(Lista l,FILE *out ){
	if(!esvacia(l)){
		ImpElemF(cabeza(l),out);
		ImpListaF(resto(l),out);
	}
}

void ImpLista(Lista l){ImpListaF(l,stdout);}

Lista PegaListas(Lista x,Lista y){
	if(esvacia(x)){
		return y;
	}else{
		return cons(cabeza(x),PegaListas(resto(x),y));
	}
}

Lista InvLista(Lista l){
	if(esvacia(l)){
		return l;
	}else{
		return PegaListas(InvLista(resto(l)),cons(cabeza(l),vacia()));
	}	
}

Lista InsOrd(Elem e,Lista l){
	if(esvacia(l)){
		return cons(e,l);
	}else{
		if(EsMenor(e,cabeza(l))){
			return cons(e,l);
		}else{
			return cons(cabeza(l),InsOrd(e,resto(l)));
		}

	}
}

Lista OrdLista(Lista l){
	if(esvacia(l)){
		return l;
	}else{
		return InsOrd(cabeza(l),OrdLista(resto(l)));
	}
}

int Contiene(Elem e, Lista l){
	if(esvacia(l)){
		return 0;
	}else{
		if(EsIgual(e,cabeza(l))){
			return 1;
		}else{
			Contiene(e,resto(l));
		}
	}
}

int Igual(Lista x, Lista y){
	if(esvacia(x)&&esvacia(y)){
		return 1;
	}else{
		if(EsIgual(cabeza(x),cabeza(y))){
			Igual(resto(x),resto(y));
		}else{
			return 0;
		}
	}
}

int Palito(Lista x){return Igual(x,InvLista(x));}


//TAREA PRACTICA 1

int EsPar(float p){
	return fmod(p,2.0)==0.0;
}

Lista Mezclar(Lista a,Lista b){
	Lista lo=vacia();
	while(!esvacia(a) && !esvacia(b)){
		ImpElem(cabeza(a));
		ImpElem(cabeza(b));
		if(EsMayor(cabeza(a),cabeza(b))){
			lo = cons(cabeza(b),cons(cabeza(a),lo));
		}
		if(EsMenor(cabeza(a),cabeza(b))){
			lo = cons(cabeza(a),cons(cabeza(b),lo));
		}
		a=resto(a);
		b=resto(b);	
	}
	if(!esvacia(a)){
		lo = cons(cabeza(a),lo);
	}
	return lo;
}

Lista MitadIzq(Lista l){
	Lista izq = l;
	int i=0,t = NumElemLista(l)/2;
	for(i;i<t;i++){
		izq=resto(izq);
	}
	return izq;
}

Lista MitadDer(Lista l){
	Lista der = InvLista(l);
	int i=0,t = NumElemLista(l)/2;
	float p = NumElemLista(l)-NumElemLista(l)/2.0;
	if(!EsPar(p)){
		t=t+1;
	}
	for(i;i<t;i++){
		der=resto(der);
	}
	return der;
}

Lista OrdenaListaMezcla(Lista l){return Mezclar(InvLista(OrdLista(MitadIzq(l))),InvLista(OrdLista(MitadDer(l))));}
