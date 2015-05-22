#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int gene_size;
	int *regulator;
	int *protein;

	} gene;

void gene_gen () {
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
	free (allele.regulator);
	free (allele.protein);

	}
}

// typedef struct {
	
//	gene gene1;
//	gene gene2;
//	gene gene3;
//	gene gene4;
//	gene gene5;
//	} organism;

int main (void) {
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
	
	gene_gen();
	printf ("%d\n", allele.regulator[1]);
	

	// organism z; 
	// z.gene1.protein[1] = 4;
	// printf ("%d", z.gene1.protein[1]);
	return 0; 
}
