#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


void gen_err(char * ime_dat)
{
	int n,br=0,bru=0;
	char bit;	

	srand(time(NULL));
	FILE *pFileR = fopen(ime_dat,"r");
	if (pFileR == NULL) {
		printf("\nNije nadena datoteka\n");
		exit(1);
	}
	FILE *pFileW = fopen("err_vec.txt","w");
	while (1)
	{
		fscanf(pFileR,"%c",&bit);
		if (feof(pFileR)) break;
		bru++;
		n = rand() % 10;
		if (n == 5){ fprintf(pFileW,"%d",1); br++;}
		else fprintf(pFileW,"%d",0);
	}
	printf("\nGenerirano %d/%d bitova greske\n",br,bru);
	fclose(pFileR);
	fclose(pFileW);
}
void gen_zer(char * ime_dat)
{
	char bit;	

	FILE *pFileR = fopen(ime_dat,"r");
	if (pFileR == NULL) {
		printf("\nNije nadena datoteka\n");
		exit(1);
	}

	FILE *pFileW = fopen("err_vec.txt","w");
	while (1)
	{
		fscanf(pFileR,"%c",&bit);
		if (feof(pFileR)) break;
		fprintf(pFileW,"%d",0);
	}
	printf("\nGeneriran vektor bez greske\n");
	fclose(pFileR);
	fclose(pFileW);
}
int main(int argc, char * argv[])
{
	if (argc == 3)
	{
		if (!strcmp(argv[argc-1], "-s")) gen_err(argv[argc-2]);
		else if (!strcmp(argv[argc-1], "-b")) gen_zer(argv[argc-2]);
		else printf("\nArgument -s za vektor s greskama ili -b za vektor bez gresaka\n");
	}
	else printf("\nNije unesen dovoljan broj argumenata, prihvacaju se samo ime ulazne datoteke i opcija\n");
	return 0;
}
