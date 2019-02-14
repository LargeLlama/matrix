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

  //put some values in edges to see that it works
  edges = new_matrix(4, 5);
  edges->m[0][0] = 1.1;
  edges->m[1][0] = 1.1;

  //prints it out
  printf("Testing print_matrix\n");
  print_matrix(edges);

  //make test an identity matrix
  struct matrix *test = new_matrix(5, 5);
  printf("\nTesting ident\n");
  ident(test);
  print_matrix(test);
  
  //free test matrices
  free_matrix(test);
  free_matrix( edges );
  
  struct matrix *uwu = new_matrix(4, 3);
  int tmp = 0;

  for(int rows = 0; rows < uwu->rows; rows++)
  {
	  for (int cols = 0; cols < uwu->cols; cols++)
	  {
		  uwu->m[rows][cols] = tmp;
		  tmp++;
	  }
  }
  printf("\nPrinting matrix uwu\n");
  print_matrix(uwu);
 
  struct matrix *owo = new_matrix(3, 4);
  tmp = 0;

  for(int rows = 0; rows < owo->rows; rows++)
  {
	  for (int cols = 0; cols < owo->cols; cols++)
	  {
		  owo->m[rows][cols] = tmp;
		  tmp++;
	  }
  }

  printf("\nPrinting matrix owo\n");
  print_matrix(owo);

  matrix_mult(uwu, owo);

  printf("\nPrinting uwu * owo\n");
  print_matrix(owo);

  struct matrix *identity = new_matrix(3, 3);
  ident(identity);

  matrix_mult(owo, identity);
  printf("\nTesting multiplication with ident\nowo * IDENTITY\n");
  print_matrix(identity); 
} 
