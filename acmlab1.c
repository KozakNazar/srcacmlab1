//to measure time it is better to run with Linux
/*******************************************************************************************************
* N.Kozak // Lviv'2018 // ACM // Time Complexity(by examples of computing the Greatest Common Divisor) *
*    file: acmlab3.c                                                                                   *
********************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N1  18
#define N2  27

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#define REPEAT_COUNT 1000000
#define REPEATOR(count, code) \
for (unsigned int indexIteration = (count); indexIteration--;){ code; }
#define TWO_VALUES_SELECTOR(variable, firstValue, secondValue) \
	(variable) = indexIteration % 2 ? (firstValue) : (secondValue);

double getCurrentTime(){
	clock_t time = clock();
	if (time != (clock_t)-1) { 
		return ((double)time / (double)CLOCKS_PER_SEC); 
	}
	return 0.; // else 	
}

unsigned long long int f1_GCD(unsigned long long int variableN1, unsigned long long int variableN2){
    unsigned long long int returnValue = 1;	

	for(unsigned long long int i = 1, k = MIN(variableN1, variableN2); i <= k; i++){	
	    if(!(variableN1 % i || variableN2 % i)){
	        returnValue = i;
	    }	
	} 
    
	return returnValue;		
}

unsigned long long int f2_GCD(unsigned long long int a, unsigned long long int b){
	for(unsigned long long int aModB; 
		aModB = a % b, 
		a = b, 
		b = aModB;
	);
	
	return a;
}

unsigned long long int f3_GCD(unsigned long long int a, unsigned long long int b){
    if(!b){
	    return a;
	}

	return f3_GCD(b, a % b); // else
}

int main() {
    unsigned long long int vN1 = N1, vN2 = N2, a = MAX(vN1, vN2), b = MIN(vN1, vN2), 
	vN1_ = vN1, vN2_ = vN2, a_ = a, b_ = b,
	returnValue;

	double startTime, endTime;

	// f1_GCD 
	startTime = getCurrentTime();
	REPEATOR(REPEAT_COUNT, 
	    TWO_VALUES_SELECTOR(vN1, 16, vN1_); 
	    TWO_VALUES_SELECTOR(vN2, 4, vN2_);
	    returnValue = f1_GCD(a, b);
	)	
	endTime = getCurrentTime();
	printf("f1_GCD return %lld \r\nrun time: %dns\r\n\r\n", 
	returnValue, 
    (unsigned int)((endTime - startTime) * (double)(1000000000 / REPEAT_COUNT)));

	// f2_GCD 
	startTime = getCurrentTime();
	REPEATOR(REPEAT_COUNT, 
	    TWO_VALUES_SELECTOR(a, 16, a_); 
	    TWO_VALUES_SELECTOR(b, 4, b_);
	    returnValue = f2_GCD(a, b);
	)	
	endTime = getCurrentTime();
	printf("f2_GCD return %lld \r\nrun time: %dns\r\n\r\n", 
	returnValue, 
	(unsigned int)((endTime - startTime) * (double)(1000000000 / REPEAT_COUNT)));
	
	// f3_GCD 
	startTime = getCurrentTime();
	REPEATOR(REPEAT_COUNT, 
	    TWO_VALUES_SELECTOR(a, 16, a_); 
	    TWO_VALUES_SELECTOR(b, 4, b_);
	    returnValue = f3_GCD(a, b);
	)	
	endTime = getCurrentTime();
	printf("f3_GCD return %lld \r\nrun time: %dns\r\n\r\n", 
	returnValue,
	(unsigned int)((endTime - startTime) * (double)(1000000000 / REPEAT_COUNT)));

	printf("Press any key to continue . . .");
	getchar();
	
	return 0;
}