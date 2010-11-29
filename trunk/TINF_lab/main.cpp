#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void izvoriste(char* niz)
{
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
}



void sf(int d, int g, char** a)//prvo donja 0, gornja 6
{
	float p[] = {0.3,0.2,0.2,0.1,0.1,0.1};
	int i;
	int db=d;
	char* test = a[1];
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
		*a=(char*) malloc(sizeof(char)*(strlen(a[d])+1));
		//a[d]=(char*) realloc(&a[d],sizeof(char)*(strlen(a[d])+1));
		a[d]="1";
	}
	int x;
	for (x = i; x < g;x++)
	{
		a[x]=(char*) malloc(sizeof(char)*(strlen(a[x])+1));
		strcat(a[x],"0");
	}
	sf(db,i,a);
	sf(i,g,a);
}
void ent_kod_sf(char* niz, char** kod)
{
	sf(0,6,kod);
}
int main()
{
	char slijed_sim [10000];
	char* kodirani_niz[6] = {"b","b","b","b","b","b"};
	izvoriste(slijed_sim);
	ent_kod_sf(slijed_sim, kodirani_niz);
	return 1;
}