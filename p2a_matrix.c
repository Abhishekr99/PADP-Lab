#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
//#define N 5
int main(int argc, char* argv[])
{
	int m,n,p,q,i,j,k;
	int sum=0;
	int N=atoi(argv[1]);
	//int first[N][N], second[N][N], result[N][N];
	double start,end;
	int num_thread=atoi(argv[2]);
	//printf("Enter num of threads: ");scanf("%d",&num_thread);
	
	int **arr1=(int **)malloc(N*sizeof(int *));
	//printf("\nC1");

	for(i=0; i<N; i++)
		arr1[i]=(int *)malloc(N*sizeof(int));
	//printf("\nC2");
	int **arr2=(int **)malloc(N*sizeof(int *));
	//printf("\nC3");
	for(i=0; i<N; i++)
		arr2[i]=(int *)malloc(N*sizeof(int));
	int **arr3=(int **)malloc(N*sizeof(int *));
	for(i=0; i<N; i++)
		arr3[i]=(int *)malloc(N*sizeof(int));

	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			arr1[i][j]=i+1;
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			arr2[i][j]=i+1;
	start=omp_get_wtime();
	
	#pragma omp parallel for private(j,k) 
	for(i=0 ;i<N; i++)
	{
		for(j=0 ;j<N; j++)
		{
			for(k=0 ;k<N; k++)
			{
				arr3[i][j]+=arr1[i][k]*arr2[j][k];//using arr2[j][k] cache friendly
			}
			/*arr3[i][j]=sum;
			sum=0;*/
		}
	}
	end=omp_get_wtime();
	
		printf("time: %lf\n",(end-start)); 																																   
	
	return 0;
}

