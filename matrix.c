/*==========================================
  A matrix will be a 4xN array of doubles
  Each column will represent an [x, y, z, 1] point.
  For multiplication purposes, consider the rows like so:
  x0  x1      xn
  y0  y1      yn
  z0  z1  ... zn
  1   1       1
  ==========================================*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "matrix.h"


/*-------------- void print_matrix() --------------
Inputs:  struct matrix *m

print the matrix such that it looks like
the template in the top comment
*/
//works as intended
void print_matrix(struct matrix *m) 
{
	for(int rows = 0; rows < m->rows; rows++)
	{
		for(int cols = 0; cols < m->cols; cols++)
		{
			printf("%f  ", m->m[rows][cols]); 
		}
		printf("\n");
	}
}

/*-------------- void ident() --------------
Inputs:  struct matrix *m <-- assumes m is a square matrix

turns m in to an identity matrix
*/
//works as intended
void ident(struct matrix *m)
{
	for(int rows = 0; rows < m->rows; rows++)
	{
		for(int cols = 0; cols < m->cols; cols++)
		{
			//if the row number is equal to the column number
			//then it is a diagonal so we set it equal to 0, otherwise its 1
			if(cols == rows)
				m->m[rows][cols] = 1;
			else
				m->m[rows][cols] = 0;
		}
	}
}


/*-------------- void matrix_mult() --------------
Inputs:  struct matrix *a
         struct matrix *b

multiply a by b, modifying b to be the product
a*b -> b
*/
//works for square matrices
void matrix_mult(struct matrix *a, struct matrix *b)
{
	//make a new matrix, with the rows of a and cols of b
	struct matrix *tmp = new_matrix(a->rows, b->cols); 

	//loop thru the rows and cols of the tmp matrix
	for(int rows = 0; rows < tmp->rows; rows++)
	{
		for (int cols = 0; cols < tmp->cols; cols++)
		{
			//loop thru the rows and cols of the other matrices and perform the operation
			for (int new = 0; new < tmp->rows; new++)
			{
				tmp->m[rows][cols] += a->m[rows][new] * b->m[new][cols];
			}
		}
	}
	//assign the new values of b to the values of tmp and free tmp
	copy_matrix(tmp, b);
	free_matrix(tmp);
}



/*===============================================
  These Functions do not need to be modified
  ===============================================*/

/*-------------- struct matrix *new_matrix() --------------
Inputs:  int rows
         int cols

Once allocated, access the matrix as follows:
m->m[r][c]=something;
if (m->lastcol)...
*/
struct matrix *new_matrix(int rows, int cols) {
  double **tmp;
  int i;
  struct matrix *m;

  tmp = (double **)malloc(rows * sizeof(double *));
  for (i=0;i<rows;i++) 
  {
      tmp[i]=(double *)malloc(cols * sizeof(double));
  }

  m=(struct matrix *)malloc(sizeof(struct matrix));
  m->m=tmp;
  m->rows = rows;
  m->cols = cols;
  m->lastcol = 0;

  return m;
}


/*-------------- void free_matrix() --------------
Inputs:  struct matrix *m
Returns:

1. free individual rows
2. free array holding row pointers
3. free actual matrix
*/
void free_matrix(struct matrix *m) {

  int i;
  for (i=0;i<m->rows;i++) {
      free(m->m[i]);
    }
  free(m->m);
  free(m);
}


/*======== void grow_matrix() ==========
Inputs:  struct matrix *m
         int newcols 
Returns: 

Reallocates the memory for m->m such that it now has
newcols number of collumns
====================*/
void grow_matrix(struct matrix *m, int newcols) {
  
  int i;
  for (i=0;i<m->rows;i++) {
      m->m[i] = realloc(m->m[i],newcols*sizeof(double));
  }
  m->cols = newcols;
}


/*-------------- void copy_matrix() --------------
Inputs:  struct matrix *a
         struct matrix *b 
Returns: 

copy matrix a to matrix b
*/
void copy_matrix(struct matrix *a, struct matrix *b) {

  int r, c;

  for (r=0; r < a->rows; r++) 
    for (c=0; c < a->cols; c++)  
      b->m[r][c] = a->m[r][c];  
}
