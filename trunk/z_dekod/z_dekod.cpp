#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void paritetni_dek() //dodaje paritetni bit na kraj
{
	FILE *pFileR = fopen("45.txt","r");
	FILE *pFileW = fopen("56.txt","w");
	int brg = 0, brb = 0;

	while (!feof(pFileR))
	{
		int brj = 0;
		brb++;
		char blok[9] = {""};	//neka privremeno velicina bloka bude 8, to je 7 podatkovnih i 1 zastitni, s tim da je zadnji velicine onoliko koliko ostane
		char blokn[8] = {""};
		fscanf(pFileR,"%8c",blok);
		for (int i = 0; i < strlen(blok); i++)
		{
			if (blok[i] == '1') brj++;
		}
		if (brj % 2 != 0) 
			brg++;		
		else strncpy(blokn,blok,strlen(blok)-1);
		fprintf(pFileW,"%s",blokn);
	}
	printf("\nbroj detektiranih gresaka/broj blokova: %d/%d\n",brg,brb);

	fclose(pFileR);
	fclose(pFileW);
}


int main()
{
	paritetni_dek(); 
	return 0;
}