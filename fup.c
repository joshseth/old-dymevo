#include <stdio.h>
#include <stdlib.h>

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

double* mat_vec_mult(double **mat, double *vec, int n) {
  int i;
  double *result = (double*) malloc(n * sizeof(double));
  for(i = 0; i < n; i++) {
    result[i] = vectors_dot_prod(mat[i], vec, n);
    printf("Dot product of row %d and vector is %f", i, result[i]);
  }
  return result;
}

int main () {
  double vector1[] = {1, 2, 3, 4, 5};
  double vector2[] = {2, 2, 2, 3, 2};

  double result = vectors_dot_prod(vector1, vector2, 5);
  printf("I got: %f", result);

  double row1[] = {1, 3, 3, 4, 5};
  double row2[] = {3, 5, 3, 5, 6};
  double row3[] = {6, 4, 2, 3, 4};
  double row4[] = {1, 3, 2, 1, 2};
  double row5[] = {2, 2, 3, 2, 3};
  double *mat[] = {row1, row2, row3, row4, row5};
  double *result2 = mat_vec_mult(mat, vector1, 5);
  int i;
  for(i = 0; i < 5; i++) {
    printf("%f", result2[i]);
  }
  free(result2);
  return 0;
}
