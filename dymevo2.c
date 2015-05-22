#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int gene_size;
	int *regulator;
	int *protein;

	} gene;
typedef struct {

      gene allele[5]; 
      
	} organism;

int  main () {
	gene allele; 
	allele.gene_size = 10;
	allele.regulator = malloc (allele.gene_size * sizeof(int));
	allele.protein = malloc (allele.gene_size * sizeof(int));

	int i;
	int p_rand[allele.gene_size];
	int r_rand[allele.gene_size]; 
	for (i = 1; i < allele.gene_size; i++) {
	p_rand[i] = rand()%4;
	r_rand[i] = rand()%4;
	allele.regulator[i] = r_rand[i];
	allele.protein[i] = p_rand[i];	
//	free (allele.regulator);
//	free (allele.protein);
	
	printf ("%d\t%d\n", allele.regulator[i], allele.protein[i] );
	
	}
}

// typedef struct {
	
//	gene allele1;
//	gene allele2;
//	gene allele3;
//	gene allele4;
//	gene allele5;
//	} organism;

// int main () {
//	int n = 10;
//	gene x;
//	x.regulator = malloc (n * sizeof(int));
//	x.protein = malloc (n * sizeof(int));
//	int n = sizeof(x.regulator)/sizeof(*x.regulator);		
//	int i;

//	for (i = 1; i < n; i++) {
//	x.regulator[i] = i;
//	x.protein[i] = 3;
//	}
//	printf("%d", x.protein[8]);
	
//	free (x.regulator);
	
//	int org1 = gene_gen();
//	printf ("%d\n", org1);
	

	// organism z; 
	// z.gene1.protein[1] = 4;
	// printf ("%d", z.gene1.protein[1]);
//	return 0; 
//}
