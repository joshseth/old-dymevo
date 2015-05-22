#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_blas.h>
#include <time.h>
#include <math.h>

float weight_rand (float *fitnesses) {

 float sum_of_weight = 0;
 int i; 
  for (int i = 0; i < 100; i++) {
     sum_of_weight += fitnesses[i];
  }
    float rnd = fmod((double)rand()/((double)RAND_MAX), sum_of_weight);
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
double* mat_power(double mat[5][5], double *vec, int rows, int cols, int power) {
  if (power == 0) {
    return vec;
  } else {
    double *solution =  matrix_vector_mult(mat, vec, rows, cols); 
    double *solution2 = mat_power (mat, solution, rows, cols, (power - 1));
    return solution2; 
  }

}


/* double* mat_power(double **mat, double *vec, int rows, int cols, int power) {
   double *solution = matrix_vector_mult (mat, vec, rows, cols); 
    if (power > 1) {
     solution = matrix_vector_mult (mat, solution, rows, cols);
     power--; 
    return solution; 
    }   
    else {
      return solution;
    }  
  }
*/

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

// population generation[100]; 
 population *generation; 
} lineage; 

//float weight_random (lineage lin.generation.organism.fitness) {

 /* lin.generation[0].organism[org].fitness */

//  time_t t;
//  srand ((unsigned) (&t));
//  int num_choices = 10;

  //float sum_of_weight = 0;
  //for (int i = 0; i < num_choices; i++) {
//     sum_of_weight += lin.generation[0].organism[i].fitness;
//     printf ("sum of weight = %f\n" , sum_of_weight);
//  }
  //  float rnd = fmod((double)rand()/((double)RAND_MAX), sum_of_weight);
//  printf ("rnd = %f\n", rnd);
//  for (int i = 0; i < num_choices; i++) {
  //  if (rnd < lin.generation[0].organism[i].fitness){
//      printf ("%d\n", i);
    //  return i;
     // break;
     // }
    //  rnd -= lin.generation[0].organism[i].fitness;
 // }

//}


int  main () {

  time_t time;
  srand ((unsigned) (&time)); 	
//  population pop;
  lineage lin;  
  lin.generation = (population*) malloc (1000000 * sizeof(population)); 
  int count;
  double y[5] = {1, 1, 1, 1, 1};  
  double optimal_phenotype[5] = {2, 1, 1, 1, 1}; 
  int org; 
  for (org = 0; org < 100; org++) { 

    for (count = 0; count < 5; count++) {
  
 
    //  lin.generation[0].organism[org].allele[count].gene_size = 10;
    //  lin.generation[0].organism[org].allele[count].regulator = malloc (lin.generation[0].organism[org].allele[count].gene_size * sizeof(int));
    //  lin.generation[0].organism[org].allele[count].protein = malloc (lin.generation[0].organism[org].allele[count].gene_size * sizeof(int));
      lin.generation[0].organism[org].allele[count].reg_direction = rand()%2;
      lin.generation[0].organism[org].allele[count].pro_direction = rand()%2;  
		
      int i;
      printf ("GENE %d\n", count); 
 
lin.generation[0].organism[org].allele[0].regulator[0] = 1;
lin.generation[0].organism[org].allele[0].regulator[1] = 2;
lin.generation[0].organism[org].allele[0].regulator[2] = 1;
lin.generation[0].organism[org].allele[0].regulator[3] = 1;
lin.generation[0].organism[org].allele[0].regulator[4] = 3;
lin.generation[0].organism[org].allele[0].regulator[5] = 1;
lin.generation[0].organism[org].allele[0].regulator[6] = 1;
lin.generation[0].organism[org].allele[0].regulator[7] = 0;
lin.generation[0].organism[org].allele[0].regulator[8] = 1;
lin.generation[0].organism[org].allele[0].regulator[9] = 2;

lin.generation[0].organism[org].allele[1].regulator[0] = 1;
lin.generation[0].organism[org].allele[1].regulator[1] = 2;
lin.generation[0].organism[org].allele[1].regulator[2] = 2;
lin.generation[0].organism[org].allele[1].regulator[3] = 1;
lin.generation[0].organism[org].allele[1].regulator[4] = 2;
lin.generation[0].organism[org].allele[1].regulator[5] = 2;
lin.generation[0].organism[org].allele[1].regulator[6] = 2;
lin.generation[0].organism[org].allele[1].regulator[7] = 0;
lin.generation[0].organism[org].allele[1].regulator[8] = 0;
lin.generation[0].organism[org].allele[1].regulator[9] = 0;

lin.generation[0].organism[org].allele[2].regulator[0] = 0;
lin.generation[0].organism[org].allele[2].regulator[1] = 0;
lin.generation[0].organism[org].allele[2].regulator[2] = 2;
lin.generation[0].organism[org].allele[2].regulator[3] = 3;
lin.generation[0].organism[org].allele[2].regulator[4] = 3;
lin.generation[0].organism[org].allele[2].regulator[5] = 1;
lin.generation[0].organism[org].allele[2].regulator[6] = 2;
lin.generation[0].organism[org].allele[2].regulator[7] = 0;
lin.generation[0].organism[org].allele[2].regulator[8] = 0;
lin.generation[0].organism[org].allele[2].regulator[9] = 0;

lin.generation[0].organism[org].allele[3].regulator[0] = 1; 
lin.generation[0].organism[org].allele[3].regulator[1] = 0;
lin.generation[0].organism[org].allele[3].regulator[2] = 2;
lin.generation[0].organism[org].allele[3].regulator[3] = 1; 
lin.generation[0].organism[org].allele[3].regulator[4] = 3;
lin.generation[0].organism[org].allele[3].regulator[5] = 2;
lin.generation[0].organism[org].allele[3].regulator[6] = 2;
lin.generation[0].organism[org].allele[3].regulator[7] = 1;
lin.generation[0].organism[org].allele[3].regulator[8] = 1;
lin.generation[0].organism[org].allele[3].regulator[9] = 0;

lin.generation[0].organism[org].allele[4].regulator[0] = 1; 
lin.generation[0].organism[org].allele[4].regulator[1] = 0;
lin.generation[0].organism[org].allele[4].regulator[2] = 1;
lin.generation[0].organism[org].allele[4].regulator[3] = 1;
lin.generation[0].organism[org].allele[4].regulator[4] = 2;
lin.generation[0].organism[org].allele[4].regulator[5] = 2;
lin.generation[0].organism[org].allele[4].regulator[6] = 2;
lin.generation[0].organism[org].allele[4].regulator[7] = 0;
lin.generation[0].organism[org].allele[4].regulator[8] = 0;
lin.generation[0].organism[org].allele[4].regulator[9] = 0;

lin.generation[0].organism[org].allele[0].protein[0] = 2;
lin.generation[0].organism[org].allele[0].protein[1] = 1;
lin.generation[0].organism[org].allele[0].protein[2] = 3;
lin.generation[0].organism[org].allele[0].protein[3] = 2;
lin.generation[0].organism[org].allele[0].protein[4] = 1;
lin.generation[0].organism[org].allele[0].protein[5] = 3;
lin.generation[0].organism[org].allele[0].protein[6] = 1;
lin.generation[0].organism[org].allele[0].protein[7] = 2;
lin.generation[0].organism[org].allele[0].protein[8] = 2;
lin.generation[0].organism[org].allele[0].protein[9] = 3;

lin.generation[0].organism[org].allele[1].protein[0] = 2;
lin.generation[0].organism[org].allele[1].protein[1] = 1;
lin.generation[0].organism[org].allele[1].protein[2] = 0;
lin.generation[0].organism[org].allele[1].protein[3] = 2;
lin.generation[0].organism[org].allele[1].protein[4] = 0;
lin.generation[0].organism[org].allele[1].protein[5] = 3;
lin.generation[0].organism[org].allele[1].protein[6] = 3;
lin.generation[0].organism[org].allele[1].protein[7] = 3;
lin.generation[0].organism[org].allele[1].protein[8] = 3;
lin.generation[0].organism[org].allele[1].protein[9] = 3;

lin.generation[0].organism[org].allele[2].protein[0] = 0;
lin.generation[0].organism[org].allele[2].protein[1] = 1;
lin.generation[0].organism[org].allele[2].protein[2] = 0;
lin.generation[0].organism[org].allele[2].protein[3] = 2;
lin.generation[0].organism[org].allele[2].protein[4] = 1;
lin.generation[0].organism[org].allele[2].protein[5] = 3;
lin.generation[0].organism[org].allele[2].protein[6] = 0;
lin.generation[0].organism[org].allele[2].protein[7] = 1;
lin.generation[0].organism[org].allele[2].protein[8] = 3;
lin.generation[0].organism[org].allele[2].protein[9] = 2;

lin.generation[0].organism[org].allele[3].protein[0] = 3;
lin.generation[0].organism[org].allele[3].protein[1] = 1;
lin.generation[0].organism[org].allele[3].protein[2] = 3; 
lin.generation[0].organism[org].allele[3].protein[3] = 2;
lin.generation[0].organism[org].allele[3].protein[4] = 2;
lin.generation[0].organism[org].allele[3].protein[5] = 0;
lin.generation[0].organism[org].allele[3].protein[6] = 0;
lin.generation[0].organism[org].allele[3].protein[7] = 3;
lin.generation[0].organism[org].allele[3].protein[8] = 2;
lin.generation[0].organism[org].allele[3].protein[9] = 2;

lin.generation[0].organism[org].allele[4].protein[0] = 2;
lin.generation[0].organism[org].allele[4].protein[1] = 1;
lin.generation[0].organism[org].allele[4].protein[2] = 0;
lin.generation[0].organism[org].allele[4].protein[3] = 0;
lin.generation[0].organism[org].allele[4].protein[4] = 0;
lin.generation[0].organism[org].allele[4].protein[5] = 0;
lin.generation[0].organism[org].allele[4].protein[6] = 3;
lin.generation[0].organism[org].allele[4].protein[7] = 3;
lin.generation[0].organism[org].allele[4].protein[8] = 2;
lin.generation[0].organism[org].allele[4].protein[9] = 1;
 
      for (i = 0; i < 10; i++) {
   /*   p_rand[i] = rand()%4;
      r_rand[i] = rand()%4;
      lin.generation[0].organism[org].allele[count].regulator[i] = r_rand[i];
      lin.generation[0].organism[org].allele[count].protein[i] = p_rand[i];	
   */	
      printf ("%d\t%d\n", lin.generation[0].organism[org].allele[count].regulator[i], lin.generation[0].organism[org].allele[count].protein[i] );
	
      }
  }
  int h;	
  int j; 
  int k; 
  for (h = 0; h < 5; h++) {
    for (j = 0; j < 5; j++) {
      for (k = 0; k < 10; k++) {
        if (lin.generation[0].organism[org].allele[h].regulator[k] == lin.generation[0].organism[org].allele[j].protein[k]) {
         lin.generation[0].organism[org].GRN[h][j] = (lin.generation[0].organism[org].GRN[h][j] + 1);
/*        if (lin.generation[0].organism[org].allele[h].reg_direction == 1) {
         lin.generation[0].organism[org].GRN[h][j] = (lin.generation[0].organism[org].GRN[h][j] * (-1));
        }
  */      }
      }
/*       if ((lin.generation[0].organism[org].allele[h].reg_direction % 2) == (lin.generation[0].organism[org].allele[j].pro_direction % 2)) {
         lin.generation[0].organism[org].GRN[h][j] = (lin.generation[0].organism[org].GRN[h][j] * (-1)); 
       }
  */  }
	}
	
  int q, r; 
  for (q = 0; q < 5; q++) {
    for (r = 0; r < 5; r++) {
    printf ("%f ", lin.generation[0].organism[org].GRN[q][r]);
    }
  printf ("\n"); 
  }


 // double *Mat[] = {lin.generation[0].organism[org].GRN[0], lin.generation[0].organism[org].GRN[1], lin.generation[0].organism[org].GRN[2], lin.generation[0].organism[org].GRN[3], lin.generation[0].organism[org].GRN[4]};


  int i; 
/* double *ans =  matrix_vector_mult (Mat, y, 5, 5);
  printf ("\n"); 
  for (i = 0; i < 5; i++) {
    printf ("%f\n", ans[i]); 
  }
*/

  printf("\nMatrix iteration:\n");
  lin.generation[0].organism[org].phenotype = mat_power(lin.generation[0].organism[org].GRN, y, 5, 5, 2);
  for (i = 0; i < 5; i++) {
    printf ("%f\n", lin.generation[0].organism[org].phenotype[i]);
  }

  double euc_dist = sqrt (vectors_dot_prod (lin.generation[0].organism[org].phenotype, lin.generation[0].organism[org].phenotype, 5) + vectors_dot_prod (optimal_phenotype, optimal_phenotype, 5) - (2 * vectors_dot_prod (optimal_phenotype, lin.generation[0].organism[org].phenotype, 5) ) ); 
  printf ("norm = %f\n", euc_dist); 
  
  lin.generation[0].organism[org].fitness = exp ((-1) * (euc_dist));

  printf ("fitness-%d = %f\n", org, lin.generation[0].organism[org].fitness);    

 // free(ans); 
  }

for (count = 0; count < 5; count ++){
  printf( "copy gene %d\n", count); 
  for (int i = 0; i < 10; i++) {
    printf ("%d\t%d\n", lin.generation[0].organism[1].allele[count].regulator[i], lin.generation[0].organism[org].allele[count].protein[i] );
  }
}
/* END OF GEN-0 creation --> Next mutate and recombine to make GEN-1 through GEN-N */


//  float sum_of_weight = 0;
//  for (int i = 0; i < 10; i++) {
//     sum_of_weight += lin.generation[0].organism[i].fitness;
//     printf ("sum of weight = %f\n" , sum_of_weight);
//  }
//    float rnd = fmod((double)rand()/((double)RAND_MAX), sum_of_weight);
//  printf ("rnd = %f\n", rnd);
//  for (int i = 0; i < 10; i++) {
//    if (rnd < lin.generation[0].organism[i].fitness){
//      printf ("%d is fit to reproduce\n", i);
//      return i;
 //     break;
 //     }
  //    rnd -= lin.generation[0].organism[i].fitness;
//  }

  int gen;
  int hap; 

  for (gen = 1; gen < 100000; gen ++) {
    float fitnesses[100]; 
      for (org = 0; org < 100; org++) {
        fitnesses[org] = lin.generation[gen-1].organism[org].fitness;
      }
      for (org = 0; org < 100; org++) {
        int parent1 = weight_rand(fitnesses);
        int parent2 = weight_rand(fitnesses);
  //      printf ("organism %d has parent 1 = %d and parent 2 = %d\n" , org, parent1, parent2);     
        for (hap = 0; hap < 5; hap++){
          if (hap == 0 || hap == 2 || hap == 3) {
            lin.generation[gen].organism[org].allele[hap] = lin.generation[gen-1].organism[parent1].allele[hap]; 
        }
          if (hap == 1 || hap == 4) {
            lin.generation[gen].organism[org].allele[hap] = lin.generation[gen-1].organism[parent2].allele[hap]; 
          }
          for (int nuc = 0; nuc < 10; nuc++) {
            int mut_reg1 = rand()%1000;
            int mut_reg2 = rand()%4; 
            int mut_pro1 = rand()%1000;
            int mut_pro2 = rand()%4; 
            
            if (mut_reg1 == 1 && mut_reg2 == 0) {  
              lin.generation[gen].organism[org].allele[hap].regulator[nuc] = 0; 
            } 
            if (mut_reg1 == 1 && mut_reg2 == 1) {
              lin.generation[gen].organism[org].allele[hap].regulator[nuc] = 1; 
            }
            if (mut_reg1 == 1 && mut_reg2 == 2) {
              lin.generation[gen].organism[org].allele[hap].regulator[nuc] = 2; 
            }
            if (mut_reg1 == 1 && mut_reg2 == 3) {
              lin.generation[gen].organism[org].allele[hap].regulator[nuc] = 3;
            }

            if (mut_pro1 == 1 && mut_pro2 == 0) {
              lin.generation[gen].organism[org].allele[hap].protein[nuc] = 0; 
            }
            if (mut_pro1 == 1 && mut_pro2 == 1) {
              lin.generation[gen].organism[org].allele[hap].protein[nuc] = 1; 
            }
            if (mut_pro1 == 1 && mut_pro2 == 2) {
              lin.generation[gen].organism[org].allele[hap].protein[nuc] = 2;
            }
            if (mut_pro1 == 1 && mut_pro2 == 3) {
              lin.generation[gen].organism[org].allele[hap].protein[nuc] = 3;
            }

//      printf ("%d\t%d\n", lin.generation[0].organism[0].allele[hap].protein[nuc], lin.generation[gen].organism[org].allele[hap].protein[nuc] );
          }
//      printf ("\n"); 
  /*        int mut_dir = rand()%10000;
            int mut_dir2 = rand()%10000;  
          if (mut_dir == 1 && lin.generation[gen].organism[org].allele[hap].reg_direction %2 == 1) {
            lin.generation[gen].organism[org].allele[hap].reg_direction = 0; 
          }
          if (mut_dir == 1 && lin.generation[gen].organism[org].allele[hap].reg_direction %2 == 0) {
            lin.generation[gen].organism[org].allele[hap].reg_direction = 1;
          }
          if (mut_dir2 == 1 && lin.generation[gen].organism[org].allele[hap].pro_direction %2 == 1) {
            lin.generation[gen].organism[org].allele[hap].reg_direction = 0;
          }
          if (mut_dir2 == 1 && lin.generation[gen].organism[org].allele[hap].pro_direction %2 == 0) {
            lin.generation[gen].organism[org].allele[hap].reg_direction = 1;
          }
    */   

        }
      
        int h, j, k; 
        for (h = 0; h < 5; h++) {
          for (j = 0; j < 5; j++) {
            for (k = 0; k < 10; k++) {
              if (lin.generation[gen].organism[org].allele[h].regulator[k] == lin.generation[gen].organism[org].allele[j].protein[k]) {
                lin.generation[gen].organism[org].GRN[h][j] = (lin.generation[gen].organism[org].GRN[h][j] + 1);
   /*           if (lin.generation[gen].organism[org].allele[h].reg_direction == 1) {
                lin.generation[gen].organism[org].GRN[h][j] = (abs (lin.generation[gen].organism[org].GRN[h][j]) * (-1));
              }   
     */         }
            }    
      /*    if ((lin.generation[gen].organism[org].allele[h].reg_direction) != (lin.generation[gen].organism[org].allele[j].pro_direction)) {
            lin.generation[gen].organism[org].GRN[h][j] = (lin.generation[gen].organism[org].GRN[h][j] * (-1));
          }
      */  }   
       }
      /* don't need pmat now that matrix_vec_mult has mat[5][5] instead **mat now */
  //       double *pmat[] = {lin.generation[gen].organism[org].GRN[0], lin.generation[gen].organism[org].GRN[1], lin.generation[gen].organism[org].GRN[2], lin.generation[gen].organism[org].GRN[3], lin.generation[gen].organism[org].GRN[4]};
       lin.generation[gen].organism[org].phenotype = mat_power (lin.generation[gen].organism[org].GRN, y, 5, 5, 10);  

       double euc_dist = sqrt (vectors_dot_prod (lin.generation[gen].organism[org].phenotype, lin.generation[gen].organism[org].phenotype, 5) + vectors_dot_prod (optimal_phenotype, optimal_phenotype, 5) - (2 * vectors_dot_prod (optimal_phenotype, lin.generation[gen].organism[org].phenotype, 5) ) );
//  printf ("norm = %f\n", euc_dist);

       lin.generation[gen].organism[org].fitness = exp ((-1) * (euc_dist));
       if ( gen % 1000 == 0  ){
       printf ("GENERATION %d fitness-%d = %f\n", gen, org, lin.generation[gen].organism[org].fitness);  
         int q, r;
          for (q = 0; q < 5; q++) {
            for (r = 0; r < 5; r++) {
              printf ("%f ", lin.generation[gen].organism[org].GRN[q][r]);
            }
            printf ("\n");
          }
   /*   for (hap = 0; hap < 5; hap++) {
        printf ("Gene %d\n", hap); 
        for (int i = 0; i < 10; i++) {

          printf ("%d\t%d\n", lin.generation[gen].organism[org].allele[hap].regulator[i], lin.generation[gen].organism[org].allele[hap].protein[i] );

          }
       } */ 
     }
    }
  }  
free (lin.generation); 
}  



	
