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

void ent_kod_sf()
{
	char* simboli;
	simboli = (char*)malloc (10001*sizeof(char));
	FILE *pFileR;
	pFileR = fopen("12.txt","r");
	fscanf(pFileR,"%s",simboli);
	fclose(pFileR);

	FILE *pFileW;
	char* kod_niz;
	char* kod[3] = {"","",""};
	sf(0,3,kod);
	int brc = 0,brb = 0,bra = 0;
	for (int i = 0;i<10000;i++)
	{
		switch (simboli[i])
		{
		case 'a':bra++;
			break;
		case 'b':brb++;
			break;
		case 'c':brc++;
			break;
		}
	}
	kod_niz = (char*)malloc (strlen(kod[0])*brc+strlen(kod[1])*brb+strlen(kod[2])*bra);
	*(kod_niz) = 0;
	for (int i = 0;i<10000;i++)
	{
		switch (simboli[i])
		{
		case 'a':strcat(kod_niz,kod[2]);
			break;
		case 'b':strcat(kod_niz,kod[1]);
			break;
		case 'c':strcat(kod_niz,kod[0]);
			break;
		}
	}
	pFileW = fopen("23.txt","w");
	fprintf(pFileW,kod_niz);
	fclose(pFileW);
}

int main()
{
	ent_kod_sf(); //entropijsko kodiranje koristeci sf
	return 0;
}