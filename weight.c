#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main () {
  time_t t; 
  srand ((unsigned) (&t));   
  int num_choices = 5; 
  float choice_weight[5] = {0.1, 0.1, 0.1, 0.1, 0.1}; 

 
  float sum_of_weight = 0;
  for (int i = 0; i < num_choices; i++) {
     sum_of_weight += choice_weight[i];
     printf ("sum of weight = %f\n" , sum_of_weight); 
  }
    float rnd = fmod((double)rand()/((double)RAND_MAX), sum_of_weight);
  printf ("rnd = %f\n", rnd); 
  for (int i = 0; i < num_choices; i++) {
    if (rnd < choice_weight[i]){
      printf ("%d\n", i); 
      break; 
      }  
      rnd -= choice_weight[i];
    
  
  }
}
