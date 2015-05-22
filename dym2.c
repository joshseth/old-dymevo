#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_blas.h>

double vectors_dot_prod(double *x, double *y, int n)
{
    double res = 0.0;
    int i;
    for (i = 0; i < n; i++) {
        res += x[i] * y[i];
    
	}

	printf ("%.f\n", res); 
    return res;
}

void matrix_vector_mult(double mat[][], double *vec, double *result, int rows, int cols)
{ // in matrix form: result = mat * vec;
	int i;
		for (i = 0; i < rows; i++) {
        	result[i] = vectors_dot_prod(mat[i], vec, cols);
	//	printf ("%.f\n", result[i]);
		}
}

typedef struct {
	int gene_size;
	int *regulator;
	int *protein;

	} gene;
typedef struct {

      gene allele[5]; 
      
	} genome;


int  main () {
	
	genome XYZ;
	
	double *GRN[];
	int count; 
	for (count = 0; count < 5; count++) {
  
 
//		gene allele; 
		XYZ.allele[count].gene_size = 9;
		XYZ.allele[count].regulator = malloc (XYZ.allele[count].gene_size * sizeof(int));
		XYZ.allele[count].protein = malloc (XYZ.allele[count].gene_size * sizeof(int));

		int i;
		int p_rand[XYZ.allele[count].gene_size];
		int r_rand[XYZ.allele[count].gene_size]; 
		printf ("GENE %d\n", count); 

			for (i = 0; i <= XYZ.allele[count].gene_size; i++) {
			p_rand[i] = rand()%4;
			r_rand[i] = rand()%4;
			XYZ.allele[count].regulator[i] = r_rand[i];
			XYZ.allele[count].protein[i] = p_rand[i];	
//			free (allele.regulator);
//			free (allele.protein);
	
			printf ("%d\t%d\n", XYZ.allele[count].regulator[i], XYZ.allele[count].protein[i] );
	
			}
	}
	int h;	
	int j; 
	int k; 
	for (h = 0; h < 5; h++) {
		for (j = 0; j < 5; j++) {
			for (k = 0; k <= 9; k++) {
				if (XYZ.allele[h].regulator[k] == XYZ.allele[j].protein[k]) {
				  GRN[h][j] = GRN[h][j] + 1;
				}
			}
		}
	}

	int q, r; 
	for (q = 0; q < 5; q++) {
		for (r = 0; r <= 5; r++) {
		printf ("%.f ", GRN[q][r]);
		}
	printf ("\n"); 
	}

double y[5] = {1};
double ans[5] = {0};


//int pnt;
//double *rows[5];
//for (pnt = 0; pnt < 5; pnt++) {
//	rows[pnt] = &GRN[pnt];
//
//	}


//vectors_dot_prod (&GRN[1], &y, 5); 
matrix_vector_mult (GRN, y, ans, 5, 5);
//printf ("%.f\n", ans[1]); 
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
