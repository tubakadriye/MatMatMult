/*


 * loop_unrolling_jki.c
 *
 *  Created on: Nov 26, 2020
 *      Author: tuba


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#define SIZE 3000

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
	for(j = 0; j < n; j++)
	{
		for( k = 0; k < n; k+=8)
		{
			for (i = 0; i < n; i++)
			{
				C[i * n + j] += A[i * n + k] * B[k * n + j];
				C[i * n + j] += A[i * n + k+1] * B[(k+1) * n + j];
				C[i * n + j] += A[i * n + k+2] * B[(k+2) * n + j];
				C[i * n + j] += A[i * n + k+3] * B[(k+3) * n + j];
				C[i * n + j] += A[i * n + k+4] * B[(k+4) * n + j];
				C[i * n + j] += A[i * n + k+5] * B[(k+5) * n + j];
				C[i * n + j] += A[i * n + k+6] * B[(k+6) * n + j];
				C[i * n + j] += A[i * n + k+7] * B[(k+7) * n + j];
				C[i * n + j] += A[i * n + k+8] * B[(k+8) * n + j];
				C[i * n + j] += A[i * n + k+9] * B[(k+9) * n + j];
				C[i * n + j] += A[i * n + k+10] * B[(k+10) * n + j];
				C[i * n + j] += A[i * n + k+11] * B[(k+11) * n + j];
				C[i * n + j] += A[i * n + k+12] * B[(k+12) * n + j];
				C[i * n + j] += A[i * n + k] * r;

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
