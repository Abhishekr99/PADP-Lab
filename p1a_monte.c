#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<math.h>
#include<time.h>

int main(int argc, char* argv[])
{
	double start,end;
	double cpu_time;
	int num;
	printf("Enter num of iterations for loop: ");scanf("%d",&num);
	double x,y,z,pi;
	int i,count=0,num_thread;
	printf("Enter num of threads: ");scanf("%d",&num_thread);
	
	start=omp_get_wtime();
	#pragma omp parallel firstprivate(x,y,z,i) shared(count) num_threads(num_thread)
	{
		srand((int)time(NULL) ^ omp_get_thread_num());
		for(i=0; i<num; i++)
		{
			x=(double)rand()/(double)RAND_MAX;
			y=(double)rand()/(double)RAND_MAX;
			z=pow((x*x+y*y),0.5);
			if(z<=1)
				count++;

		}
	}
	pi=((double)count/(double)(num*num_thread))*4;
	printf("\npi: %lf",pi);
	end=omp_get_wtime();
	cpu_time=(double)(end-start);
	printf("\ntime in sec: %lf\n",cpu_time);
	return 0;
}
