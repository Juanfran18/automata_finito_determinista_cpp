#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct lista_elementos
{
  int estado;
  struct lista_elementos *a;
  struct lista_elementos *b;
};

typedef struct lista_elementos nodo;
 
void crear(nodo *q0,nodo *q1,nodo *q2,nodo *q3,
nodo *actual, nodo *anterior);
void mostrar(nodo *pt,nodo *pt2,int j,char i);

main()
{
		nodo *q0,*q1,*q2,*q3,*actual,*anterior;
		int j=0,i=0,tamano=0,novalido=0; char cadena[100];
		actual=(nodo*)malloc(sizeof(nodo));
		q0=(nodo*)malloc(sizeof(nodo));
		q1=(nodo*)malloc(sizeof(nodo));
		q2=(nodo*)malloc(sizeof(nodo));
		q3=(nodo*)malloc(sizeof(nodo));
		crear(q0,q1,q2,q3,actual,anterior);

		printf("\n\t Automata Finito Determinista \n");
		printf("\t===============================\n");
		printf("\t Carolina cayetano 0900-08-842 \n");
		printf("\t===============================\n");
		printf("  Ingrese Cadena: ");
		gets(cadena);
		tamano = strlen(cadena);

		while (i < tamano && novalido==0){
			j=i+1;
			switch(cadena[i]){
				case 'a':
					if(actual->a==NULL){
						anterior=q0;
						actual=anterior->a;
						mostrar(anterior,actual,j,cadena[i]);
					}else{
						anterior=actual;
						actual=anterior->a;
						mostrar(anterior,actual,j,cadena[i]);
					}                        
					break;
				case 'b':
					if(actual->b==NULL){
						anterior=q0;
						actual=anterior->b;
						mostrar(anterior,actual,j,cadena[i]);
					}else{
						anterior=actual;
						actual=anterior->b;
						mostrar(anterior,actual,j,cadena[i]);}                        
					break;
				  default:
					  novalido=1;
					  printf("\n\n\t caracter no valido: %c",cadena[i]);
					  break;
				   }
				   i++;
		}
		/*if(actual->estado==1||actual->estado==2||actual->estado==3||novalido==1){
				  printf("\n\n\t ------------------------- ");
				 printf("\n\t --- Cadena Rechazada! --- \n");
				  printf("\t ------------------------- \n\n");
				  }
		else{
				 printf("\n\n\t ------------------------ ");
				 printf("\n\t --- Cadena Aceptada! --- \n");
				  printf("\t ------------------------ \n\n");
			}*/
	
		if(actual->estado==3){
			printf("\n\n\t ------------------------ ");
			printf("\n\t --- Cadena Aceptada! --- \n");
			printf("\t ------------------------ \n\n");
		}else{
			printf("\n\n\t ------------------------- ");
			printf("\n\t --- Cadena Rechazada! --- \n");
			printf("\t ------------------------- \n\n");
				  }
		}
		getchar();
}

void crear(nodo *q0,nodo *q1,nodo *q2,nodo *q3,nodo *actual, nodo *anterior)
{

      q0->a=q1;
	   q1->a=q0;
	   q1->b=q3;
      q0->b=q2;
	   q2->a=q2;
	   q2->b=q3;
	   q3->a=q2;
	   q3->b=q3;
      q0->estado=1;
      q1->estado=2;
      q2->estado=3;
      q3->estado=4;
      actual->a=NULL;
      actual->b=NULL;
}

void mostrar(nodo *pt,nodo *pt2, int j,char i)
{     int fuente=0,destino=0;
      fuente=pt->estado;destino=pt2->estado;
      fuente=fuente-1;destino=destino-1;
      printf("\n\n Movimiento: %d",j);
      printf("  Para el simbolo: %c",i);
      if(j==0){
      printf("\n\n\t Desde el Inicio");}
      else{
        printf("\n\n\t Del Estado: q%d",fuente);
        printf("\t A el Estado: q%d",destino);
        }
}
