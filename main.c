#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"
#include <math.h>

int main() {

  //testing matrix functions

  struct matrix *mat;

  //put some values in mat to see that it works
  mat = new_matrix(4, 5);
  mat->m[0][0] = 1.1;
  mat->m[1][0] = 1.1;

  //prints it out
  printf("Testing print_matrix\n");
  print_matrix(mat);

  //make test an identity matrix
  struct matrix *test = new_matrix(5, 5);
  printf("\nTesting ident\n");
  ident(test);
  print_matrix(test);
  
  //free test matrices
  free_matrix(test);
  free_matrix( mat );
  
  struct matrix *uwu = new_matrix(3, 3);
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
 
  struct matrix *owo = new_matrix(3, 3);
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



  //image generation
  screen s;
  color c;

  clear_screen(s);
  struct matrix *edges;

  c.red = 100;
  c.green = 0;
  c.blue = 255;

  edges = new_matrix(4, 1);

  for(int i = 0; i < 1000; i++)
  {
	 int x0 = 100 + (400 * sin(M_PI * i / 100));
	 int y0 = 200 + (300 * cos(M_PI * i / 1000));
	 int x1 = 100 + (300 * cos(M_PI * i / 100));
	 int y1 = 200 + (300 * sin(M_PI * i / 100));

	 add_edge(edges, x0, y0, 0, x1, y1, 0);
  }
  draw_lines( edges, s, c );
  free_matrix( edges);

  save_extension(s, "matrix.png");
  display(s); 
} 
