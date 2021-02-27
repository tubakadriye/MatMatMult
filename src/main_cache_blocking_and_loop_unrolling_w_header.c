/*
 * cache_blocking_and_loop_unrolling_w_header.c
 *
 *  Created on: Nov 29, 2020
 *      Author: tuba
 */
/*

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <math.h>
#include "cache_blocking_and_loop_unrolling.h"

#define SIZE 10000

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
	gettimeofday(&t, NULL);
	time1 = t.tv_sec + 1.0e-6*t.tv_usec;

	MatMatMult(A,B,C,SIZE);
	//transpose(A,SIZE);

	sleep(5);

	gettimeofday(&t, NULL);
	time2 = t.tv_sec + 1.0e-6*t.tv_usec;

	wct = time2 - time1;

	printf("wct = %lf\n", wct);

	//print1dMat(A,SIZE,SIZE);
	//printf("B\n");
	//print1dMat(B,SIZE,SIZE);
	//printf("C\n");
	//print1dMat(C,SIZE,SIZE);



	free(B);
	free(C);
	free(A);

	return 0;

}



*/












