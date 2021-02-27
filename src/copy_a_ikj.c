/*

 * copy_a_ikj.c
 *
 *  Created on: Nov 26, 2020
 *      Author: tuba



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#define SIZE 1000

void fill1dMat(double *A, int n)
{
	int i,j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			A[i * n +j] = (i+1)*(j+1);
		}
	}
}

void MatMatMult(double *A, double *B, double *C, int n)
{
	int i,j,k;
	double r;
	for(i = 0; i< n; i++)
	{
		for( k = 0; k < n; k++)
		{
			r = A[i * n + k];
			for (j = 0; j < n; j++)
			{
				C[i * n + j] += r* B[k * n + j];
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

	fill1dMat(A, SIZE);
	fill1dMat(B,SIZE);

	gettimeofday(&t, NULL);
	time1 = t.tv_sec + 1.0e-6*t.tv_usec;

	MatMatMult(A,B,C,SIZE);

	sleep(5);

	gettimeofday(&t, NULL);
	time2 = t.tv_sec + 1.0e-6*t.tv_usec;

	wct = time2 - time1;

	printf("wct = %lf\n", wct);

	//print1dMat(C,SIZE,SIZE);

	free(B);
	free(C);
	free(A);

	return 0;

}







*/
