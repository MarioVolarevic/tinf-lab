#include <stdio.h>
#include <stdlib.h>

char inverzija(char b)
{
	if (b=='0') b='1';
	else if (b=='1') b='0';
	return b;
}

void use_err_vec(char* ime_dat, char* vek_gr_dat)
{
	char bit, err_b;
	FILE *pFileR1 = fopen(ime_dat,"r");
	FILE *pFileR2 = fopen(vek_gr_dat,"r");
	if (pFileR1 == NULL || pFileR2 == NULL) {
		printf("\nNije nadena datoteka\n");
		exit(1);
	}
	FILE *pFileW = fopen("45.txt","w");
	while (1)
	{
		char bit, err_b;
		fscanf(pFileR1,"%c",&bit);
		fscanf(pFileR2,"%c",&err_b);
		if (feof(pFileR1) || feof(pFileR2)) break;
		if (err_b == '1') bit = inverzija(bit); //zbog neceg xor nije radio kad prebacim compile na release pa zato radim inverziju ovako
		fprintf(pFileW,"%c",bit);
	}
	fclose(pFileR1);
	fclose(pFileR2);
	fclose(pFileW);
	printf("\n%s primijenjen na %s\n", vek_gr_dat,ime_dat);
}
int main(int argc, char * argv[])
{
	printf("\nIme grupe: NSK24\nVarijanta 1: p(greske) = 1/10\n");
	if (argc == 3) use_err_vec(argv[argc-2],argv[argc-1]); 
	else printf("\nNije unesen dovoljan broj argumenata, prihvacaju se samo imena ulazne datoteke i vektora greske\n");
	return 0;
}
