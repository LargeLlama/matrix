#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  struct matrix *edges;

  edges = new_matrix(4, 5);
  edges->m[0][0] = 1.1;
  edges->m[1][0] = 1.1;

  printf("Testing print_matrix\n");
  print_matrix(edges);

  struct matrix *test = new_matrix(5, 5);
  printf("\nTesting ident\n");
  ident(test);
  print_matrix(test);

  free_matrix( edges );
  free_matrix( test );
}  
