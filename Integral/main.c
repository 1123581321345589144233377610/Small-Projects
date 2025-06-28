#include <math.h>
#include <stdio.h>
#include "integral.h"
#define ACCURACY (1e-6)

long double function(long double x){
	return x * x * x;
}

int main(){
	long double lowerBound, upperBound, difference, firstIntegral, secondIntegral;
	printf("> Enter the lower limit of the interval: ");
	scanf("%Lf", &lowerBound);
	printf("\n> Enter the upper limit of the interval: ");
	scanf("%Lf", &upperBound);
	for(int index = 1; ; index *= 2){
		firstIntegral = integral(lowerBound, upperBound, index, function);
		secondIntegral = integral(lowerBound, upperBound, 2 * index, function);
		difference = fabs(firstIntegral - secondIntegral);
		if(difference < ACCURACY){
			break;
		}
	}
	printf("\nThe integral of this function is: %Lf\n", secondIntegral); 
	return 0;
}
