#include <stdio.h>
#include <stdlib.h>


void use_err_vec()
{
	char bit, err_b;
	int b, e_b;
	FILE *pFileR1 = fopen("34.txt","r");
	FILE *pFileR2 = fopen("err_vec.txt","r");
	FILE *pFileW = fopen("45.txt","w");
	while (1)
	{
		fscanf(pFileR1,"%c",&bit);
		fscanf(pFileR2,"%c",&err_b);
		if (feof(pFileR1) || feof(pFileR2)) break;
		b = atoi(&bit);
		if (err_b == '1') b = !b; //zbog neceg xor nije radio kad prebacim compile na release pa zato radim inverziju ovako
		fprintf(pFileW,"%d",b);
	}
	fclose(pFileR1);
	fclose(pFileR2);
	fclose(pFileW);
	printf("\nerr_vec.txt primijenjen na 34.txt\n");
}
int main()
{
	printf("\nIme grupe: NSK24\nVarijanta 1: p(greske) = 1/10\n");
	use_err_vec();
	return 0;
}
