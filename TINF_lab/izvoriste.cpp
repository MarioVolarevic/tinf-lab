#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void izvoriste()
{
	char niz [10001] = {0};

	srand(time(NULL));
	int n, i;
	for (int i=0; i<10000; i++)
	{
		n = rand() % 10;
		if (n >= 0 && n < 2)
			niz[i] = 'a';
		else if (n >= 2 && n < 4)
			niz[i] = 'b';
		else niz[i] = 'c';
	}
	FILE* pFile;
	pFile = fopen("12.txt","w");
	fprintf(pFile,niz);
	fclose(pFile);
	printf("\nGenerirano 10000 simbola\n");
}


int main()
{
	//char* kodirani_niz;
	izvoriste(); //generiranje simbola
	//kodirani_niz = ent_kod_sf(slijed_simbola); //entropijsko kodiranje koristeci sf
	return 0;
}