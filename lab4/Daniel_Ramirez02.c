#include "omp.h" 
#include <stdio.h>

static long num_steps = 100000;
double step;

int main(int argc, char** argv){

	int i; 
	double x, pi, sum = 0.0;
	step = 1.0/(double) num_steps;
	double start = omp_get_wtime();

	int thread_count = 1;

	if(argc == 2){
		thread_count = atoi(argv[1]);
	}

	#pragma omp parallel for num_threads(thread_count) private(x, i) reduction(+:sum)
	{
		double temp = 0.0;

		for(i = 0; i < num_steps; i++){
			x = (i + 0.5)* step;
			temp = temp + 4.0/(1.0 + x*x);			
		}

		sum += temp;
	}
	double end =omp_get_wtime();
	pi = step * sum;

	printf("Pi is : %f\n" , pi);
	printf("Time spent: %f\n", end - start);

	return 0;
}

