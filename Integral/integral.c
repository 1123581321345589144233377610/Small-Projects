#include "integral.h"

long double integral(long double lowerBound, long double upperBound, unsigned int numberOfIterations, long double (*function)(long double)){
	long double sum = 0;
	long double step = (upperBound - lowerBound) / (numberOfIterations);
	for(int index = 0; index < numberOfIterations; ++index){
		sum += function(lowerBound + index * step);
	}
	return sum * step;
}
