#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void paritetni_koder() //dodaje paritetni bit na kraj
{
	FILE *pFileR = fopen("23.txt","r");
	FILE *pFileW = fopen("34.txt","w");
	while (!feof(pFileR))
	{
		int brj = 0;
		char blok[9] = {""};	//neka privremeno velicina bloka bude 8, to je 7 podatkovnih i 1 zastitni, s tim da je zadnji velicine onoliko koliko ostane
		fscanf(pFileR,"%7c",blok);
		for (int i = 0; i < strlen(blok); i++)
		{
			if (blok[i] == '1') brj++;
		}
		//printf("%d",brj);
		if (brj % 2 == 0) strcat(blok,"0");
		else strcat(blok,"1");
		fprintf(pFileW,"%s",blok);
	}
	fclose(pFileR);
	fclose(pFileW);
}


int main()
{
	paritetni_koder(); 
	return 0;
}