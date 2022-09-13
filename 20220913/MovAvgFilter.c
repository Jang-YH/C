#include <stdio.h>
#include <stdlib.h>
#define n 10

double data[n+1] = {0, };

double movAvg(double p_avg, double n_data)
{
	double avg = 0;
	
	data[n] = n_data;
	
	avg = p_avg + data[n] / n - data[0] / n;
	
	for(int i = 1; i < n+1; i++)
	{
		data[i-1] = data[i];
	}
	data[n]=0;
	
	return avg;
}
	
	
	

int main()
{
	double p_avg = 0;
	double n_data = 0;
	
	while(1)
	{
		printf("데이터 입력 : ");
		scanf("%lf", &n_data);
		p_avg = movAvg(p_avg, n_data);
		
		printf("평균값 : %.2f\n", p_avg);
	}
	
	return 0;
}