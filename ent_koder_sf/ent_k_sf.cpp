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
	char simbol;
	char* kod[3] = {"","",""};
	sf(0,3,kod);
	int brb = 0;
	FILE *pFileR;
	FILE *pFileW;
	pFileR = fopen("12.txt","r");
	pFileW = fopen("23.txt","w");
	while (1)
	{
		fscanf(pFileR,"%c",&simbol);
		if (feof(pFileR)) break;
		switch (simbol)
		{
		case 'a':{fprintf(pFileW,"%s",kod[2]); brb+=2;
			break;}
		case 'b':{fprintf(pFileW,"%s",kod[1]); brb+=2;
			break;}
		case 'c':{fprintf(pFileW,"%s",kod[0]); brb++;
			break;}
		}
	}
	fclose(pFileR);
	fclose(pFileW);
	printf("\n10000 simbola je kodirano sa %d bitova\n",brb);

}

int main()
{
	printf("\nIme grupe: NSK24\nVarijanta 1: Shannon-Fanoovo kodiranje\n");
	ent_kod_sf(); //entropijsko kodiranje koristeci sf
	return 0;
}