//to measure time it is better to run with Linux
/*******************************************************************************************************
* N.Kozak // Lviv'2018 // ACM // Time Complexity(by examples of computing the Greatest Common Divisor) *
*    file: acmlab1.cpp                                                                                 *
********************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DATA_TYPE volatile unsigned long long int 

#define N1 18
#define N2 27

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#define REPEAT_COUNT 1000000
#define REPEATOR(count, code) \
for (unsigned int indexIteration = (count); indexIteration--;){ code; }

double getCurrentTime(){
	clock_t time = clock();
	if (time != (clock_t)-1) { 
		return ((double)time / (double)CLOCKS_PER_SEC); 
	}
	return 0.; // else 	
}

DATA_TYPE f1_GCD(DATA_TYPE variableN1, DATA_TYPE variableN2){
	DATA_TYPE returnValue = 1;

	for(DATA_TYPE i = 1, k = MIN(variableN1, variableN2); i <= k; i++){
	    if(!(variableN1 % i || variableN2 % i)){
	        returnValue = i;
	    }	
	} 
    
	return returnValue;		
}

DATA_TYPE f2_GCD(DATA_TYPE a, DATA_TYPE b){
	for(DATA_TYPE aModB;
		aModB = a % b, 
		a = b, 
		b = aModB;
	);
	
	return a;
}

DATA_TYPE f3_GCD(DATA_TYPE a, DATA_TYPE b){
    if(!b){
	    return a;
	}

	return f3_GCD(b, a % b); // else
}

int main() {
	DATA_TYPE a = MAX(N1, N2), b = MIN(N1, N2),	returnValue;

	double startTime, endTime;

	// f1_GCD 
	startTime = getCurrentTime();
	REPEATOR(REPEAT_COUNT, returnValue = f1_GCD(a, b););
	endTime = getCurrentTime();
	printf("f1_GCD return %lld \r\nrun time: %dns\r\n\r\n", 
	returnValue, 
    (unsigned int)((endTime - startTime) * (double)(1000000000 / REPEAT_COUNT)));

	// f2_GCD 
	startTime = getCurrentTime();
	REPEATOR(REPEAT_COUNT, returnValue = f2_GCD(a, b););
	endTime = getCurrentTime();
	printf("f2_GCD return %lld \r\nrun time: %dns\r\n\r\n", 
	returnValue, 
	(unsigned int)((endTime - startTime) * (double)(1000000000 / REPEAT_COUNT)));
	
	// f3_GCD 
	startTime = getCurrentTime();
	REPEATOR(REPEAT_COUNT, returnValue = f3_GCD(a, b););
	endTime = getCurrentTime();
	printf("f3_GCD return %lld \r\nrun time: %dns\r\n\r\n", 
	returnValue,
	(unsigned int)((endTime - startTime) * (double)(1000000000 / REPEAT_COUNT)));

	printf("Press Enter to continue . . .");
	(void)getchar();
	
	return 0;
}
