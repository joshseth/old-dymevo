#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_blas.h>
#include <time.h>

double vectors_dot_prod(double *x, double *y, int n)
{
    double res = 0.0;
    int i;
    for (i = 0; i < n; i++) {
        res += x[i] * y[i];
    
	}

    return res;
}

double* matrix_vector_mult(double **mat, double *vec, int rows, int cols)
{ // in matrix form: result = mat * vec;
	int i;
	double *result = malloc (cols* sizeof (double));
		for (i = 0; i < rows; i++) {
        	result[i] = vectors_dot_prod(mat[i], vec, cols);
		}
	return result; 
}

double* mat_power(double **mat, double *vec, int rows, int cols, int power) {
  if (power == 0) {
    return vec;
  } else {
    double *solution =  matrix_vector_mult(mat, vec, rows, cols); 
    double *solution2 = mat_power (mat, solution, rows, cols, (power - 1));
    return solution2; 
      
     
  }

}
typedef struct {
	int gene_size;
	int *regulator;
	int *protein;
	int reg_direction; 

	} gene;
typedef struct {

      gene allele[5];
      
	} genome;


int  main () {

	time_t time;
	srand ((unsigned) (&time)); 	
	genome XYZ;
	double GRN[5][5];
	int count; 
	for (count = 0; count < 5; count++) {
  
 
		XYZ.allele[count].gene_size = 9;
		XYZ.allele[count].regulator = malloc (XYZ.allele[count].gene_size * sizeof(int));
		XYZ.allele[count].protein = malloc (XYZ.allele[count].gene_size * sizeof(int));
		XYZ.allele[count].reg_direction = rand()%2; 
		
		int i;
		int p_rand[XYZ.allele[count].gene_size];
		int r_rand[XYZ.allele[count].gene_size]; 
		printf ("GENE %d\n", count); 

			for (i = 0; i <= XYZ.allele[count].gene_size; i++) {
			p_rand[i] = rand()%4;
			r_rand[i] = rand()%4;
			XYZ.allele[count].regulator[i] = r_rand[i];
			XYZ.allele[count].protein[i] = p_rand[i];	
	
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
				  GRN[h][j] = (GRN[h][j] + 0.1);
				if (XYZ.allele[h].reg_direction == 1) {
				  GRN[h][j] = (GRN[h][j] * (-1));
				}
				}
			}
		}
	}
	
	int q, r; 
	for (q = 0; q < 5; q++) {
		for (r = 0; r < 5; r++) {
		printf ("%f ", GRN[q][r]);
		}
	printf ("\n"); 
	}

double y[5] = {1, 1, 1, 1, 1};

double *Mat[] = {GRN[0], GRN[1], GRN[2], GRN[3], GRN[4]};


int i; 
double *ans =  matrix_vector_mult (Mat, y, 5, 5);
printf ("\n"); 
for (i = 0; i < 5; i++) {
  printf ("%f\n", ans[i]); 
}
printf("\nMatrix iteration:\n");
double *final_result = mat_power(Mat, y, 5, 5, 20);
for (i = 0; i < 5; i++) {
  printf ("%f\n", final_result[i]);
}
free(final_result);


free(ans); 
}



	
