/*


 * blocking2_ijk.c
 *
 *  Created on: Nov 28, 2020
 *      Author: tuba



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <math.h>
#define SIZE 500

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

int min(int num1,int num2)
{
	return (num1>num2) ? num1 : num2;
}

void MatMatMult(double *A, double *B, double *C, int n)
{


	int i,j,k,jj,kk,b_size;
	b_size = 10;
	double sum;

	for(jj=0; jj<n; jj+=b_size)
	{
	for(i=0;i<n;i++)
		for(j = jj; j < min(jj+b_size,n);j++)

		for(kk=0; kk<n;kk+=b_size)
		{
			for(i=0;i<n;i++)
			{
				for(j = jj; j < min(jj+b_size,n); j++)
				{
					sum=0.0;
					for(k = kk; k < min(kk+b_size,n); k++)
					{
						sum += A[i * n + k] * B[k * n + j];
					}
					C[i * n + j] = sum;
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
