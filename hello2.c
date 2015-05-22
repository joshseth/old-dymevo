#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

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

  lineage lin;
  lin.generation = (population*) malloc (1000000 * sizeof(population));
  FILE *op = fopen ("lineage.dat", "rb"); 
  fread (lin.generation, sizeof(population), 10000, op);

  for (int i = 0; i < 10; i++) {
  printf ("%f\t%f\n", lin.generation[0].organism[1].fitness, lin.generation[9999].organism[1].fitness );
  } 

}
