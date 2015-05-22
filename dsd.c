#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_blas.h>
#include <time.h>
#include <math.h>

double weight_rand (double *fitnesses) {

 double sum_of_weight = 0;
 int i; 
  for (int i = 0; i < 100; i++) {
     sum_of_weight += fitnesses[i];
  }
    double rnd = fmod((double)rand()/((double)RAND_MAX), sum_of_weight);
  for (i = 0; i < 100; i++) {
    if (rnd < fitnesses[i]){
      return i;
      break;
      }
      rnd -= fitnesses[i];
  }
}

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
//	int gene_size;
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

// population generation[1000]; 
 population *generation; 
} lineage; 

int  main (int argc, char * argv[]) {

  time_t time;
  srand ((unsigned) (&time)); 	
  double y[5] = {1, 1, 1, 1, 1};  
  double optimal_phenotype[5] = {10, 5, 10, 0, 5}; 

  lineage ancestral_lin;
  lineage lin1;

  ancestral_lin.generation = (population*) malloc (10000 * sizeof(population)); 
  lin1.generation = (population*) malloc (10000 * sizeof(population));

  FILE *op = fopen ("lineage1.dat", "rb");
  fread (ancestral_lin.generation, sizeof (population), 10000, op);

  lin1.generation[0] = ancestral_lin.generation[9999]; 

/* END OF GEN-0 creation --> Next mutate and recombine to make GEN-1 through GEN-N */

  int gen;
  int hap; 

  for (gen = 1; gen < 10000; gen ++) {
    double fitnesses[100]; 
      for (int org = 0; org < 100; org++) {
        fitnesses[org] = lin1.generation[gen-1].organism[org].fitness;
      }
      for (int org = 0; org < 100; org++) {
        int parent1 = weight_rand(fitnesses);
        int parent2 = weight_rand(fitnesses);
  //      printf ("organism %d has parent 1 = %d and parent 2 = %d\n" , org, parent1, parent2);     
        for (hap = 0; hap < 5; hap++){
          if (hap == 0 || hap == 2 || hap == 3) {
            lin1.generation[gen].organism[org].allele[hap] = lin1.generation[gen-1].organism[parent1].allele[hap]; 
        }
          if (hap == 1 || hap == 4) {
            lin1.generation[gen].organism[org].allele[hap] = lin1.generation[gen-1].organism[parent2].allele[hap]; 
          }
          for (int nuc = 0; nuc < 10; nuc++) {
            int mut_reg1 = rand()%10000;
            int mut_reg2 = rand()%4; 
            int mut_pro1 = rand()%10000;
            int mut_pro2 = rand()%4; 
            
            if (mut_reg1 == 1 && mut_reg2 == 0) {  
              lin1.generation[gen].organism[org].allele[hap].regulator[nuc] = 0; 
            } 
            if (mut_reg1 == 1 && mut_reg2 == 1) {
              lin1.generation[gen].organism[org].allele[hap].regulator[nuc] = 1; 
            }
            if (mut_reg1 == 1 && mut_reg2 == 2) {
              lin1.generation[gen].organism[org].allele[hap].regulator[nuc] = 2; 
            }
            if (mut_reg1 == 1 && mut_reg2 == 3) {
              lin1.generation[gen].organism[org].allele[hap].regulator[nuc] = 3;
            }

            if (mut_pro1 == 1 && mut_pro2 == 0) {
              lin1.generation[gen].organism[org].allele[hap].protein[nuc] = 0; 
            }
            if (mut_pro1 == 1 && mut_pro2 == 1) {
              lin1.generation[gen].organism[org].allele[hap].protein[nuc] = 1; 
            }
            if (mut_pro1 == 1 && mut_pro2 == 2) {
              lin1.generation[gen].organism[org].allele[hap].protein[nuc] = 2;
            }
            if (mut_pro1 == 1 && mut_pro2 == 3) {
              lin1.generation[gen].organism[org].allele[hap].protein[nuc] = 3;
            }

//      printf ("%d\t%d\n", lin1.generation[0].organism[0].allele[hap].protein[nuc], lin1.generation[gen].organism[org].allele[hap].protein[nuc] );
          }
//      printf ("\n"); 
            int mut_dir = rand()%10000;
          //  int mut_dir2 = rand()%10000;  
          if (mut_dir == 1 && lin1.generation[gen].organism[org].allele[hap].reg_direction == 1) {
            lin1.generation[gen].organism[org].allele[hap].reg_direction = 0; 
          }
          if (mut_dir == 1 && lin1.generation[gen].organism[org].allele[hap].reg_direction == 0) {
            lin1.generation[gen].organism[org].allele[hap].reg_direction = 1;
          }
      /*    if (mut_dir2 == 1 && lin1.generation[gen].organism[org].allele[hap].pro_direction %2 == 1) {
            lin1.generation[gen].organism[org].allele[hap].reg_direction = 0;
          }
          if (mut_dir2 == 1 && lin1.generation[gen].organism[org].allele[hap].pro_direction %2 == 0) {
            lin1.generation[gen].organism[org].allele[hap].reg_direction = 1;
          }
    */   

        }
      
        int h, j, k; 
        for (h = 0; h < 5; h++) {
          for (j = 0; j < 5; j++) {
            lin1.generation[gen].organism[org].GRN[h][j] = 0;
            for (k = 0; k < 10; k++) {
              if (lin1.generation[gen].organism[org].allele[h].regulator[k] == lin1.generation[gen].organism[org].allele[j].protein[k]) {
                lin1.generation[gen].organism[org].GRN[h][j] = (lin1.generation[gen].organism[org].GRN[h][j] + 1);
   /*           if (lin1.generation[gen].organism[org].allele[h].reg_direction == 1) {
                lin1.generation[gen].organism[org].GRN[h][j] = (abs (lin1.generation[gen].organism[org].GRN[h][j]) * (-1));
              }   
     */         }
            } 
             
 //         lin1.generation[gen].organism[org].GRN[h][j] = ((1/50) * ( exp (lin1.generation[gen].organism[org].GRN[h][j] - 3)));
          if (lin1.generation[gen].organism[org].allele[h].reg_direction == 0) {
            lin1.generation[gen].organism[org].GRN[h][j] = (lin1.generation[gen].organism[org].GRN[h][j] * (-1));
          }
        }   
       }
       lin1.generation[gen].organism[org].phenotype = mat_power (lin1.generation[gen].organism[org].GRN, y, 5, 5, 100);  

       double euc_dist = sqrt (vectors_dot_prod (lin1.generation[gen].organism[org].phenotype, lin1.generation[gen].organism[org].phenotype, 5) + vectors_dot_prod (optimal_phenotype, optimal_phenotype, 5) - (2 * vectors_dot_prod (optimal_phenotype, lin1.generation[gen].organism[org].phenotype, 5) ) );
//  printf ("norm = %f\n", euc_dist);

       lin1.generation[gen].organism[org].fitness = exp ((-1) * pow ((euc_dist), 2));
       if ( gen % 100 == 0 && org == 0 ){
       printf ("GENERATION %d fitness-%d = %f\n", gen, org, lin1.generation[gen].organism[org].fitness);  
         int q, r;
          for (q = 0; q < 5; q++) {
            for (r = 0; r < 5; r++) {
              printf ("%f ", lin1.generation[gen].organism[org].GRN[q][r]);
            }
            printf ("\n");
          }
   /*   for (hap = 0; hap < 5; hap++) {
        printf ("Gene %d\n", hap); 
        for (int i = 0; i < 10; i++) {

          printf ("%d\t%d\n", lin1.generation[gen].organism[org].allele[hap].regulator[i], lin1.generation[gen].organism[org].allele[hap].protein[i] );

          }
       } */ 
     }
    }
  }


  FILE *f; 
  f = fopen (argv[1], "wb"); 
  fwrite (lin1.generation, sizeof(population), 10000, f); 
  fclose(f);
  free (lin1.generation); 
}  



	
