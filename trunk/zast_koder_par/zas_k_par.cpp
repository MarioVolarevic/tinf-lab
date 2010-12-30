#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void paritetni_koder() //dodaje paritetni bit na kraj
{
	int brb = 0, brbit = 0;
	FILE *pFileR = fopen("23.txt","r");
	FILE *pFileW = fopen("34.txt","w");
	while (1)
	{
		int brj = 0;
		char blok[9] = {""};	//neka privremeno velicina bloka bude 8, to je 7 podatkovnih i 1 zastitni, s tim da je zadnji velicine onoliko koliko ostane
		fscanf(pFileR,"%7c",blok);
		if (feof(pFileR)) break;
		for (int i = 0; i < strlen(blok); i++)
		{
			if (blok[i] == '1') brj++;
		}
		if (brj % 2 == 0) strcat(blok,"0");
		else strcat(blok,"1");
		fprintf(pFileW,"%s",blok);
		brbit+=strlen(blok);
		brb++;
	}
	fclose(pFileR);
	fclose(pFileW);
	printf("\nGenerirano %d 8-bitnih blokova pomocu %d bitova\n",brb,brbit);
}


int main()
{
	printf("\nIme grupe: NSK24\nVarijanta 1: Parni paritet\n");
	paritetni_koder(); 
	return 0;
}