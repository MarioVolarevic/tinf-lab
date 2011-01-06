#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void paritetni_koder(char* ime_dat) //dodaje paritetni bit na kraj
{
	int brb = 0, brbit = 0;
	FILE *pFileR = fopen(ime_dat,"r");
	if (pFileR == NULL) {
		printf("\nNije nadena datoteka\n");
		exit(1);
	}
	FILE *pFileW = fopen("34.txt","w");
	while (1)
	{
		int brj = 0;
		char blok[9] = {""};	//neka velicina bloka bude 8, to je 7 podatkovnih i 1 zastitni, s tim da se zadnji odbacuje ako nije djeljivo
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


int main(int argc, char * argv[])
{
	printf("\nIme grupe: NSK24\nVarijanta 1: Parni paritet\n");
	if (argc == 2) paritetni_koder(argv[argc-1]); 
	else printf("\nNije unesen dovoljan broj argumenata, prihvaca se samo ime ulazne datoteke\n");
	return 0;
}