/*



 * procedure_inlining_and_loop_unrolling_and_devectorization_ikj.c
 *
 *  Created on: Nov 29, 2020
 *      Author: tuba





#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <math.h>
#define SIZE 10000

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


int main(int argc, char *argv[])
{
	double *A, *B, *C;
	struct timeval t;
	double time1, time2, wct;

	A = (double*)malloc(SIZE * SIZE * sizeof(double));
	B = (double*)malloc(SIZE * SIZE * sizeof(double));
	C = (double*)malloc(SIZE * SIZE * sizeof(double));

	//fill1dMat(A, SIZE,SIZE);
	int i,j,n;
	n=SIZE;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				A[i * n +j] = (i+1)*(j+1);
			}
		}
	//fill1dMat(B,SIZE,SIZE);
	for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				B[i * n +j] = (i+1)*(j+1);
			}
		}

	gettimeofday(&t, NULL);
	time1 = t.tv_sec + 1.0e-6*t.tv_usec;

	//MatMatMult(A,B,C,SIZE);

	int k,m,l,p;
	int nb_of_blocks,block_size;
	block_size= 13;
	nb_of_blocks= n / block_size;
	//transpose(B,n);
	double tmp;
				for(i = 0; i < n; i++)
				{
					for ( j = i+1; j < n; j++)
					{
						tmp = B[i * n + j];
						B[i * n + j]= B[j * n + i];
						B[j * n + i]=tmp;
					}
				}
	double r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,r13;

	for(i=0 ; i < nb_of_blocks; i++)
	{
		for (l = 0 ; l < nb_of_blocks; l+=13)
		{
			for ( j=0 ; j<nb_of_blocks ; j++)
			{
				for ( k=0; k < block_size ; k++)
				{

					for(p=0; p < block_size; p+=13)
					{
						r1=A[i*block_size*n + l*block_size + k*n +p];
						r2=A[i*block_size*n + (l+1)*block_size + k*n +p+1];
						r3=A[i*block_size*n + (l+2)*block_size + k*n +p+2];
						r4=A[i*block_size*n + (l+3)*block_size + k*n +p+3];
						r5=A[i*block_size*n + (l+4)*block_size + k*n +p+4];
						r6=A[i*block_size*n + (l+5)*block_size + k*n +p+5];
						r7=A[i*block_size*n + (l+6)*block_size + k*n +p+6];
						r8=A[i*block_size*n + (l+7)*block_size + k*n +p+7];
						r9=A[i*block_size*n + (l+8)*block_size + k*n +p+8];
						r10=A[i*block_size*n + (l+9)*block_size + k*n +p+9];
						r11=A[i*block_size*n + (l+10)*block_size + k*n +p+10];
						r12=A[i*block_size*n + (l+11)*block_size + k*n +p+11];
						r13=A[i*block_size*n + (l+12)*block_size + k*n +p+12];

						for (m=0; m < block_size ; m++)
						{

							//C[i*block_size*n + j*block_size + k*n + m] += r * B[j*block_size*n + l *block_size + m*n +p];
							C[i*block_size*n + j*block_size + k*n + m] += r1 * B[j*block_size*n + l *block_size + m*n +p];
							C[i*block_size*n + j*block_size + k*n + m] += r2 * B[j*block_size*n + (l+1) *block_size + m*n +p+1];
							C[i*block_size*n + j*block_size + k*n + m] += r3 * B[j*block_size*n + (l+2) *block_size + m*n +p+2];
							C[i*block_size*n + j*block_size + k*n + m] += r4 * B[j*block_size*n + (l+3) *block_size + m*n +p+3];
							C[i*block_size*n + j*block_size + k*n + m] += r5 * B[j*block_size*n + (l+4) *block_size + m*n +p+4];
							C[i*block_size*n + j*block_size + k*n + m] += r6 * B[j*block_size*n + (l+5) *block_size + m*n +p+5];
							C[i*block_size*n + j*block_size + k*n + m] += r7 * B[j*block_size*n + (l+6) *block_size + m*n +p+6];
							C[i*block_size*n + j*block_size + k*n + m] += r8 * B[j*block_size*n + (l+7) *block_size + m*n +p+7];
							C[i*block_size*n + j*block_size + k*n + m] += r9 * B[j*block_size*n + (l+8) *block_size + m*n +p+8];
							C[i*block_size*n + j*block_size + k*n + m] += r10 * B[j*block_size*n + (l+9) *block_size + m*n +p+9];
							C[i*block_size*n + j*block_size + k*n + m] += r11 * B[j*block_size*n + (l+10) *block_size + m*n +p+10];
							C[i*block_size*n + j*block_size + k*n + m] += r12 * B[j*block_size*n + (l+11) *block_size + m*n +p+11];
							C[i*block_size*n + j*block_size + k*n + m] += r13 * B[j*block_size*n + (l+12) *block_size + m*n +p+12];
						}

					}
					//C[i*block_size*n + j*block_size + k*n + m] = sum;

				}
			}
		}
	}


	sleep(5);

	gettimeofday(&t, NULL);
	time2 = t.tv_sec + 1.0e-6*t.tv_usec;

	wct = time2 - time1;

	printf("wct = %lf\n", wct);


	//printf("C\n");
	//print1dMat(C,SIZE,SIZE);



	free(B);
	free(C);
	free(A);

	return 0;

}










*/

