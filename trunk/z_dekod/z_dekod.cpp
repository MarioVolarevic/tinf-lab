#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void paritetni_dek(char* ime_dat) //dodaje paritetni bit na kraj
{
	//FILE *pFileR = fopen("45.txt","r");
	FILE *pFileR = fopen(ime_dat,"r");
	if (pFileR == NULL) {
		printf("\nNije nadena datoteka\n");
		exit(1);
	}
	FILE *pFileW = fopen("56.txt","w");
	int brg = 0, brb = 0;

	while (1)
	{
		int brj = 0;
		char blok[9] = {""};	//neka privremeno velicina bloka bude 8, to je 7 podatkovnih i 1 zastitni, s tim da je zadnji velicine onoliko koliko ostane
		char blokn[8] = {""};
		fscanf(pFileR,"%8c",blok);
		if (feof(pFileR)) break;
		for (int i = 0; i < strlen(blok); i++)
		{
			if (blok[i] == '1') brj++;
		}
		if (brj % 2 != 0) 
			brg++;		
		else strncpy(blokn,blok,strlen(blok)-1);
		brb++;
		fprintf(pFileW,"%s",blokn);
	}
	printf("\nOmjer detektirane greske/broj blokova: %d/%d\n",brg,brb);

	fclose(pFileR);
	fclose(pFileW);
}


int main(int argc, char * argv[])
{
	printf("\nIme grupe: NSK24\nVarijanta 1: Parni paritet\n");
	if (argc == 2) paritetni_dek(argv[argc-1]); //entropijsko kodiranje koristeci sf	
	else printf("\nNije unesen dovoljan broj argumenata, prihvaca se samo ime ulazne datoteke\n");
	return 0;
}