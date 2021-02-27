/*







ok


 * cache_blocking_ijk.c
 *
 *  Created on: Nov 27, 2020
 *      Author: tuba

*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <math.h>
#define SIZE 10000

void fill1dMat(double *A, int row,int col)
{
	int i,j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			A[i * row +j] = (i+1)*(j+1);
		}
	}
}
void print1dMat(double *A, int row, int col)
{
	int i,j;
	for(i = 0; i < row ; i++)
	{
		for(j = 0; j < col; j++)
		{
			printf("%6.4lf\t", A[i * row + j]);
		}
		printf("\n");
	}
}

void transpose(double *A,int n)
{
	int i,j;
	double tmp;
	for(i = 0; i < n; i++)
	{
		for ( j = i+1; j < n; j++)
		{
			tmp = A[i * n + j];
			A[i * n + j]= A[j * n + i];
			A[j * n + i]=tmp;
		}
	}

}

void MatMatMult(double *A, double *B, double *C, int n)
{

	int i,j,k,m,l,p;
	//double sum;
	double r;
	int nb_of_blocks,block_size;
	//block_size= 2;
	block_size= 13;
	nb_of_blocks= n / block_size;
	//take transpose and do the calculation
	//transpose(B,n);

	for(i=0 ; i < nb_of_blocks; i++)
	{
		for (l = 0 ; l < nb_of_blocks; l++)
		{
			for ( k=0; k < block_size ; k++)
			{
				for(p=0; p < block_size; p++)
				{
					r= A[i*block_size*n + l*block_size + k*n +p];
					for ( j=0 ; j<nb_of_blocks ; j++)
						{
						for (m=0; m < block_size ; m++)
						{
							//printf("%f\n",B[j*block_size*n + l *block_size + m*n +p]);
						C[i*block_size*n + j*block_size + k*n + m] += r *
									B[l*block_size*n + j *block_size + p*n +m];

						}
						//printf("\n");
					}
					//printf("\n");
					//C[i*block_size*n + j*block_size + k*n + m] = sum;
				}
			}
		}
	}
}

int main(int argc, char *argv[])
{
	double *A, *B, *C;
	struct timeval t;
	double time1, time2, wct;

	A = (double*)malloc(SIZE * SIZE * sizeof(double));
	B = (double*)malloc(SIZE * SIZE * sizeof(double));
	C = (double*)malloc(SIZE * SIZE * sizeof(double));

	fill1dMat(A, SIZE,SIZE);
	fill1dMat(B,SIZE,SIZE);

	//print1dMat(A,SIZE,SIZE);
	//printf("B\n");
	//print1dMat(B,SIZE,SIZE);

	gettimeofday(&t, NULL);
	time1 = t.tv_sec + 1.0e-6*t.tv_usec;

	MatMatMult(A,B,C,SIZE);
	//transpose(A,SIZE);

	sleep(5);

	gettimeofday(&t, NULL);
	time2 = t.tv_sec + 1.0e-6*t.tv_usec;

	wct = time2 - time1;

	printf("wct = %lf\n", wct);

	//printf("BT\n");
	//print1dMat(B,SIZE,SIZE);

	//printf("C\n");
	//print1dMat(C,SIZE,SIZE);



	free(B);
	free(C);
	free(A);

	return 0;

}




















