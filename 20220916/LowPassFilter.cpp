#include <stdio.h>

double alpha;
double prevX = 0;

float Low_Pass_Filter(float prev, float x) {
	float x_lpf;

	x_lpf = alpha * prevX + (1 - alpha) * x;
	// 이전 스텝 값 갱신
	prevX = x_lpf;
	return x_lpf;
}

int main(void) {
	double num;
	printf("weight : ");
	scanf_s("%lf", &alpha);

	while (1) {
		printf("input : ");
		scanf_s("%lf", &num);
		printf("%.2lf\n", Low_Pass_Filter(prevX, num));
	}
}