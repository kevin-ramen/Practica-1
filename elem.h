typedef int Elem;

void ImpElemF(Elem e,FILE *out){fprintf(out,"%d\n",e);}

void ImpElem(Elem e){ImpElemF(e,stdout);}

int EsMenor(Elem x,Elem y){return x<y;}

int EsMayor(Elem x,Elem y){return x>y;}

int EsIgual(Elem x, Elem y){return x==y;}
