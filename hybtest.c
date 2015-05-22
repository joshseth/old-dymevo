#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

double* matrix_vector_mult(double mat[5][5], double *vec, int rows, int cols)
{ // in matrix form: result = mat * vec;
        int i;
        double *result = (double*) malloc (cols* sizeof (double));
                for (i = 0; i < rows; i++) {
                result[i] = vectors_dot_prod(mat[i], vec, cols);
                }
        return result;
}
double* vec_add (double *vec1, double *vec2) {
   double *result = (double*) malloc (5 * sizeof(double));
   for (int i = 0; i < 5; i++) {
    result[i] = vec1[i] + vec2[i];
      if (result[i] < 0) {
        result[i] = 0;
      }
      if (result[i] > 20) {
        result[i] = 20;
      }
    }
  return result;
}

double* mat_power(double mat[5][5], double *vec, int rows, int cols, int power) {
  if (power == 0) {
    return vec;
  } else {
    double *solution =  matrix_vector_mult(mat, vec, rows, cols);
    double *solution2 = vec_add (mat_power (mat, solution, rows, cols, (power - 1)), solution) ;
   /* for (int i = 0; i < 5; i++) {
      solution2[i] = solution2[i] + solution[i];
        if (solution2[i] < 0) {
          solution2[i] = 0;
        }
        if (solution2[i] > 10) {
          solution2[i] = 10;
        }
    }*/
    return solution2;
  }

}
typedef struct {
        int regulator[10];
        int protein[10];
        int reg_direction;
        int pro_direction;

        } gene;

typedef struct {

      gene allele[5];
      double GRN[5][5];
      double *phenotype;
      double fitness;

        } genome;

typedef struct {

  genome organism[100];

} population;

typedef struct {

 population *generation;

} lineage;

int main () {

  double optimal_phenotype[5] = {10, 5, 10, 0, 5};
  double y[5] = {1, 1, 1, 1, 1};
  /* optimal and initial protein vectors are EXTREMLY important -- check to make sure same as lin1 and lin2 */
  
  lineage lin1;
  lineage lin2;
  genome hybrid; 
  
  lin1.generation = (population*) malloc (10000 * sizeof(population));
  lin2.generation = (population*) malloc (10000 * sizeof(population));
  
  FILE *op = fopen ("lineage1.dat", "rb"); 
  fread (lin1.generation, sizeof (population), 10000, op);
  FILE *ope = fopen ("lineage2.dat" , "rb");
  fread (lin2.generation, sizeof (population), 10000, ope); 

  printf ("organism 0 from lineage 1 has fitness %f\n", lin1.generation[9990].organism[0].fitness);   
  printf ("organism 0 from lineage 2 has fitness %f\n", lin1.generation[6000].organism[0].fitness);   

  hybrid.allele[0] = lin1.generation[6000].organism[0].allele[0];
  hybrid.allele[1]= lin1.generation[9990].organism[0].allele[1];
  hybrid.allele[2]= lin1.generation[6000].organism[0].allele[2];
  hybrid.allele[3]= lin1.generation[9990].organism[0].allele[3];
  hybrid.allele[4]= lin1.generation[6000].organism[0].allele[4];

  for (int i = 0; i < 5; i++) {
    printf ("\n Gene %d\n", i);
    for (int j = 0; j < 10; j++) {
      printf ("%d\t%d\n", hybrid.allele[i].regulator[j], hybrid.allele[i].protein[j]); 
    }
  }
 
for (int h = 0; h < 5; h++) {
    for (int j = 0; j < 5; j++) {
hybrid.GRN[h][j] = 0;         
      
    }
}

  for (int h = 0; h < 5; h++) {
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 10; k++) {
        if (hybrid.allele[h].regulator[k] == hybrid.allele[j].protein[k]) {
          hybrid.GRN[h][j] = hybrid.GRN[h][j] + 1;
        }
      }
        if (hybrid.allele[h].reg_direction == 0) {
          hybrid.GRN[h][j] = (hybrid.GRN[h][j] * (-1));
        }
    }
  }
  
  for (int i = 0; i < 5; i++) {
    printf ("\n"); 
    for (int j = 0; j < 5; j++) {
      printf ("%f  ", hybrid.GRN[i][j]);
    }
  }
  
  hybrid.phenotype = mat_power (hybrid.GRN, y, 5, 5, 100);
  
  printf ("\n hybrid phenotype: \n");
  for (int r = 0; r < 5; r++) {
    printf ("%f\n", hybrid.phenotype[r]); 
  }

  double euc_dist = sqrt (vectors_dot_prod (hybrid.phenotype, hybrid.phenotype, 5) + vectors_dot_prod (optimal_phenotype, optimal_phenotype, 5) - (2 * vectors_dot_prod (optimal_phenotype, hybrid.phenotype, 5) ) );

  hybrid.fitness = exp ((-1) * pow ((euc_dist), 1));
  printf ("\n"); 
  printf ("Hybrid fitness is %f\n", hybrid.fitness);
  
  free (lin1.generation); 
  free (lin2.generation);  
}
