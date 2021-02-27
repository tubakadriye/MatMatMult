/*

 * blocking3_ijk.c
 *
 *  Created on: Nov 28, 2020
 *      Author: tuba



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <math.h>
#define SIZE 1000

void fill1dMat(double *A, int row, int col)
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

void MatMatMult(double *A, double *B, double *C, int n)
{


	int i,j,k,i1,j1,k1,blocking_factor;
	blocking_factor = 10;
	double sum;
	transpose(B,n);

	for(i=0; i<n; i+=blocking_factor)
	{

		for(j=0; j<n;j+=blocking_factor)
		{

			for(k=0;k<n;k+=blocking_factor)
			{

				// blocking_factor x blocking_factor mini matrix multiplication
				for(i1 = i; i+blocking_factor; i++)
				{

					for(j1 = j; j1 < j+blocking_factor; j1++)
					{

						sum=0.0;
						for(k1 = k; k1 < k+blocking_factor; k1++)
						{

							sum += A[i1 * n + k1] * B[k1 * n + j1];
							C[i1 * n + j1] = sum;
							//C[i1 * n + j1]=A[i1 * n + k1] * B[k1 * n + j1];
						}
					}
				}
			}
		}
	}

					//

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

	gettimeofday(&t, NULL);
	time1 = t.tv_sec + 1.0e-6*t.tv_usec;

	MatMatMult(A,B,C,SIZE);

	sleep(5);

	gettimeofday(&t, NULL);
	time2 = t.tv_sec + 1.0e-6*t.tv_usec;

	wct = time2 - time1;

	printf("wct = %lf\n", wct);

	//print1dMat(A,SIZE,SIZE);
	//print1dMat(B,SIZE,SIZE);
	//print1dMat(C,SIZE,SIZE);

	free(B);
	free(C);
	free(A);

	return 0;

}










*/
