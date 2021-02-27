/*

 * matmult.c
 *
 *  Created on: Nov 29, 2020
 *      Author: tuba


*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "cache_blocking_and_loop_unrolling.h"

void MatMatMult(double *A, double *B, double *C, int n)
{

	int i,j,k,m,l,p;
	double sum;
	int nb_of_blocks,block_size;
	block_size= 13;
	nb_of_blocks= n / block_size;
	transpose(B,n);

	for(i=0 ; i < nb_of_blocks; i++)
	{
		for ( j=0 ; j<nb_of_blocks ; j++)
		{
			for ( k=0; k < block_size ; k++)
			{
				for (m=0; m < block_size ; m++)
				{
					sum =0.0;
					for (l = 0 ; l < nb_of_blocks; l+=13)
					{
						for(p=0; p < block_size; p+=13)
						{
							sum += A[i*block_size*n + l*block_size + k*n +p] *
									B[j*block_size*n + l *block_size + m*n +p];
							sum += A[i*block_size*n + (l+1)*block_size + k*n +p+1] *
									B[j*block_size*n + (l+1) *block_size + m*n +p+1];
							sum += A[i*block_size*n + (l+2)*block_size + k*n +p+2] *
									B[j*block_size*n + (l+2) *block_size + m*n +p+2];
							sum += A[i*block_size*n + (l+3)*block_size + k*n +p+3] *
									B[j*block_size*n + (l+3) *block_size + m*n +p+3];
							sum += A[i*block_size*n + (l+4)*block_size + k*n +p+4] *
									B[j*block_size*n + (l+4) *block_size + m*n +p+4];
							sum += A[i*block_size*n + (l+5)*block_size + k*n +p+5] *
									B[j*block_size*n + (l+5) *block_size + m*n +p+5];
							sum += A[i*block_size*n + (l+6)*block_size + k*n +p+6] *
									B[j*block_size*n + (l+6) *block_size + m*n +p+6];
							sum += A[i*block_size*n + (l+7)*block_size + k*n +p+7] *
									B[j*block_size*n + (l+7) *block_size + m*n +p+7];
							sum += A[i*block_size*n + (l+8)*block_size + k*n +p+8] *
										B[j*block_size*n + (l+8) *block_size + m*n +p+8];
							sum += A[i*block_size*n + (l+9)*block_size + k*n +p+9] *
										B[j*block_size*n + (l+9) *block_size + m*n +p+9];
							sum += A[i*block_size*n + (l+10)*block_size + k*n +p+10] *
										B[j*block_size*n + (l+10) *block_size + m*n +p+10];
							sum += A[i*block_size*n + (l+11)*block_size + k*n +p+11] *
										B[j*block_size*n + (l+11) *block_size + m*n +p+11];
							sum += A[i*block_size*n + (l+12)*block_size + k*n +p+12] *
										B[j*block_size*n + (l+12) *block_size + m*n +p+12];

						}

					}
					C[i*block_size*n + j*block_size + k*n + m] = sum;

				}
			}
		}
	}
}
*/
