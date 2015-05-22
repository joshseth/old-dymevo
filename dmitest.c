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

int main (int argc, char *argv[]) {

  double optimal_phenotype[5] = {10, 5, 10, 0, 5};
  double y[5] = {1, 1, 1, 1, 1};
  /* optimal and initial protein vectors are EXTREMLY important -- check to make sure same as lin1 and lin2 */
  
  lineage lin1;
  lineage lin2;
  genome hybrid[10000]; 
  double incompatibility[10000];
  
  lin1.generation = (population*) malloc (10000 * sizeof(population));
  lin2.generation = (population*) malloc (10000 * sizeof(population));
  
  FILE *op = fopen (argv[1], "rb"); 
  fread (lin1.generation, sizeof (population), 10000, op);
  FILE *ope = fopen (argv[2] , "rb");
  fread (lin2.generation, sizeof (population), 10000, ope); 

  for (int hyb = 0; hyb < 10000; hyb++) {
//  printf ("HYBRIDIZATION GENERATION %d\n", hyb);
    printf ("%f\n", lin1.generation[hyb].organism[0].fitness);   
//  printf ("organism 0 from lineage 2 has fitness %f\n", lin2.generation[hyb].organism[0].fitness);   
    hybrid[hyb].allele[0] = lin1.generation[hyb].organism[0].allele[0];
    hybrid[hyb].allele[1]= lin2.generation[hyb].organism[0].allele[1];
    hybrid[hyb].allele[2]= lin1.generation[hyb].organism[0].allele[2];
    hybrid[hyb].allele[3]= lin2.generation[hyb].organism[0].allele[3];
    hybrid[hyb].allele[4]= lin1.generation[hyb].organism[0].allele[4];
  
  /*  for (int i = 0; i < 5; i++) {
      printf ("\n Gene %d\n", i);
      for (int j = 0; j < 10; j++) {
        printf ("%d\t%d\n", hybrid.allele[i].regulator[j], hybrid.allele[i].protein[j]); 
      }
    } */
 
    for (int h = 0; h < 5; h++) {
      for (int j = 0; j < 5; j++) {
       hybrid[hyb].GRN[h][j] = 0;         
      
      }
    }

    for (int h = 0; h < 5; h++) {
      for (int j = 0; j < 5; j++) {
        for (int k = 0; k < 10; k++) {
          if (hybrid[hyb].allele[h].regulator[k] == hybrid[hyb].allele[j].protein[k]) {
            hybrid[hyb].GRN[h][j] = hybrid[hyb].GRN[h][j] + 1;
        }
      }
        if (hybrid[hyb].allele[h].reg_direction == 0) {
          hybrid[hyb].GRN[h][j] = (hybrid[hyb].GRN[h][j] * (-1));
        }
    }
  }
// printf("Matrix %d\n", hyb); 
//    printf ("\n"); 
  for (int i = 0; i < 5; i++) {
//    printf ("\n"); 
    for (int j = 0; j < 5; j++) {
//      printf ("%f  ", hybrid[hyb].GRN[i][j]);
//        printf ("%f,  ", lin2.generation[hyb].organism[0].GRN[i][j]);
    }
  }
  
  hybrid[hyb].phenotype = mat_power (hybrid[hyb].GRN, y, 5, 5, 100);
  
//  printf ("\n hybrid phenotype: \n");
  for (int r = 0; r < 5; r++) {
//    printf ("%f\n", hybrid[hyb].phenotype[r]); 
  }

  double euc_dist = sqrt (vectors_dot_prod (hybrid[hyb].phenotype, hybrid[hyb].phenotype, 5) + vectors_dot_prod (optimal_phenotype, optimal_phenotype, 5) - (2 * vectors_dot_prod (optimal_phenotype, hybrid[hyb].phenotype, 5) ) );

  hybrid[hyb].fitness = exp ((-1) * (euc_dist));
//  printf ("\n"); 
// printf ("%f\n", hybrid[hyb].fitness);
  int fix_diff1[10000] = {0}; 
  int fix_diff2[10000] = {0};
  int K_tot[10000] = {0};
  for (int al = 0; al < 5; al++) {
    for (int q = 0; q < 10; q++) {
      if (lin1.generation[hyb].organism[0].allele[al].regulator[q] != lin1.generation[0].organism[0].allele[al].regulator[q]) {
        fix_diff1[hyb] = fix_diff1[hyb] + 1;
      } 
      if (lin1.generation[hyb].organism[0].allele[al].protein[q] != lin1.generation[0].organism[0].allele[al].protein[q]) {
        fix_diff1[hyb] = fix_diff1[hyb] +1;
      }
    }
    if (lin1.generation[hyb].organism[0].allele[al].reg_direction != lin1.generation[0].organism[0].allele[al].reg_direction) {
      fix_diff1[hyb] = fix_diff1[hyb] + 1;
    }
  }

  for (int al = 0; al < 5; al++) {
    for (int q = 0; q < 10; q++) {
      if (lin2.generation[hyb].organism[0].allele[al].regulator[q] != lin2.generation[0].organism[0].allele[al].regulator[q]) {
        fix_diff2[hyb] = fix_diff2[hyb] + 1;
      } 
      if (lin2.generation[hyb].organism[0].allele[al].protein[q] != lin2.generation[0].organism[0].allele[al].protein[q]) {
        fix_diff2[hyb] = fix_diff2[hyb] +1;
      }
    }
    if (lin2.generation[hyb].organism[0].allele[al].reg_direction != lin2.generation[0].organism[0].allele[al].reg_direction) {
      fix_diff2[hyb] = fix_diff2[hyb] + 1;
    }
  }
  K_tot[hyb] = fix_diff1[hyb] + fix_diff2[hyb];
//  printf ("%d\n", K_tot[hyb]); 

  incompatibility[hyb] = 1 - (2 / (lin1.generation[hyb].organism[0].fitness + lin2.generation[hyb].organism[0].fitness)) * hybrid[hyb].fitness;

// printf ("%f\n", incompatibility[hyb]);
}

  free (lin1.generation); 
  free (lin2.generation);  
}
