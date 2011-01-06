#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sf(int d, int g, char** k) //testirao na primjeru iz slajdova i radilo je
	//d - donja granica, g - gornja granica, k - niz kodova
{
	float p[] = {0.6,0.2,0.2};
	char* temps;
	int i;
	int db=d;
	float zb=0;
	int j;	
	if (g-d == 1) return;
	for (d;d<g;d++)
	{
		zb += p[d];
		float zb2=0;
		for (j=d+1;j<g;j++)			
			zb2 += p[j];
		if (zb >= zb2) {
			i = d+1; 
			break;
		}
	}
	for (d=db; d<i;d++)
	{
		temps = (char*) malloc(strlen(k[d]) + 1);
		strcpy(temps,k[d]);
		strcat(temps,"0");
		k[d] =(char*) malloc(strlen(k[d]) + 1);
		strcpy(k[d],temps);
	}
	int x;
	for (x = i; x < g;x++)
	{
		temps = (char*) malloc(strlen(k[x]) + 1);
		strcpy(temps,k[x]);
		strcat(temps,"1");
		k[x] =(char*) malloc(strlen(k[x]) + 1);
		strcpy(k[x],temps);
	}
	sf(db,i,k);
	sf(i,g,k);
}

void ent_dekod_sf(char* ime_dat)
{
	char bit[2] = {""};
	char* kod[3] = {"","",""};
	sf(0,3,kod);
	int brzn = 0, brb = 0;
	int na = 0, nb = 0, nc = 0;
	FILE *pFileR;
	FILE *pFileW;
	pFileR = fopen(ime_dat,"r");
	if (pFileR == NULL) {
		printf("\nNije nadena datoteka\n");
		exit(1);
	}
	pFileW = fopen("67.txt","w");
	while (1)
	{
		char kodf[3]={""};
		fscanf(pFileR,"%c",bit);
		if (feof(pFileR)) break;
		brb++;
		strcat(kodf,bit);
		if (!strcmp(kodf, kod[0])) {
			fprintf(pFileW,"%c",'c');
			nc++;
			brzn++;
		}
		else 
		{
			fscanf(pFileR,"%c",bit);	//kod[0] = c, kod[1] = b, kod[2] = a
			if (feof(pFileR)) break;
			brb++;
			strcat(kodf,bit);
			if (!strcmp(kodf, kod[1])){
				fprintf(pFileW,"%c",'b');
				brzn++;
				nb++;
			}
			else if (!strcmp(kodf, kod[2])){
				fprintf(pFileW,"%c",'a');
				brzn++;
				na++;
			}
		}
	}
	fclose(pFileR);
	fclose(pFileW);
	printf("\nUcitano %d bitova\nDekodirano %d/10000 simbola\n",brb,brzn);
	printf("\nbroj a = %d\nbroj b = %d\nbroj c = %d\n",na,nb,nc);
}

int main(int argc, char* argv[])
{
	printf("\nIme grupe: NSK24\nVarijanta 1: Shannon-Fanoovo kodiranje\n");
	if (argc == 2) ent_dekod_sf(argv[argc-1]); //entropijsko dekodiranje koristeci sf	
	else printf("\nNije unesen dovoljan broj argumenata, prihvaca se samo ime ulazne datoteke\n");
	return 0;
}