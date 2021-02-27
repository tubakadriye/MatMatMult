/*

 * loop_unrolling_jki.c
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
	double r1,r2,r3,r4,r5,r6,r7,r8;
	for(j = 0; j < n; j++)
	{
		for( k = 0; k < n; k+=8)
		{

			r1 = B[k * n + j];
			r2 = B[(k+1) * n + j];
			r3 = B[(k+2) * n + j];
			r4 = B[(k+3) * n + j];
			r5 = B[(k+4) * n + j];
			r6 = B[(k+5) * n + j];
			r7 = B[(k+6) * n + j];
			r8 = B[(k+7) * n + j];
			for (i = 0; i < n; i++)
			{
				C[i * n + j] += A[i * n + k] * r1;
				C[i * n + j] += A[i * n + k+1] * r2;
				C[i * n + j] += A[i * n + k+2] * r3;
				C[i * n + j] += A[i * n + k+3] * r4;
				C[i * n + j] += A[i * n + k+4] * r5;
				C[i * n + j] += A[i * n + k+5] * r6;
				C[i * n + j] += A[i * n + k+6] * r7;
				C[i * n + j] += A[i * n + k+7] * r8;

				//C[i * n + j] += A[i * n + k] * r;

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

	fill1dMat(A,SIZE);
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
