#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void izvoriste()
{
	char niz [10001] = {0};
	int bra = 0, brb = 0, brc = 0;
	srand(time(NULL));
	int n, i;
	for (int i=0; i<10000; i++)
	{
		n = rand() % 10;
		if (n >= 0 && n < 2){
			bra++;
			niz[i] = 'a';
		}
		else if (n >= 2 && n < 4){
			brb++;
			niz[i] = 'b';
		}
		else {
			brc++;
			niz[i] = 'c';
		}
	}
	FILE* pFile;
	pFile = fopen("12.txt","w");
	fprintf(pFile,niz);
	fclose(pFile);
	printf("\nGenerirano 10000 simbola\nbroj a = %d\nbroj b = %d\nbroj c = %d\n",bra,brb,brc);
}


int main()
{
	printf("\nIme grupe: NSK24\nVarijanta 1: p(a) = 0.2; p(b) = 0.2; p(c) = 0.6\n");
	izvoriste(); //generiranje simbola
	return 0;
}