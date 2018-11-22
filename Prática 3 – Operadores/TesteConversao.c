#include <stdio.h>
#include "conversao.h"

int main ()
{
	printf("A) :%d", parteInteira(3.1415));
	printf("\nA) :%d", parteInteira(2.71));
	printf("\nA) :%d", parteInteira(0.9999));
	
	printf("\n\nB) :%f", parteFracionaria(3.1415));
	printf("\nB) :%f", parteFracionaria(2.71));
	printf("\nB) :%f", parteFracionaria(0.9999));
	
	printf("\n\nC) :%f", divInts(7,3));
	printf("\nC) :%f", divInts(10,6));
	printf("\nC) :%f", divInts(17,13));
	return 0;
}