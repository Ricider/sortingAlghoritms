#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INCREMENT 2746
#define MULTIPLY 6437

void radixSort(int *array, int length){
	for (int nibbleIndex=0; nibbleIndex<8; nibbleIndex++){
	
		int* temporary=(int*) calloc(length, sizeof(int));
		int* newArray=(int*) calloc(length, sizeof(int));
		int nextElement=0;
		
		for (int i=0;i<length;i++) {
			temporary[i]=array[i]>>(4*nibbleIndex);
			temporary[i]=temporary[i]%0x10;
		}
		
		for (int i=0;i<0x10;i++){
			for (int v=0;v<length;v++){
				if (temporary[v]==i) newArray[nextElement++]=array[v];
			}
		}
		for (int i=0;i<length;i++) array[i]=newArray[i];
		free(temporary);
		free(newArray);
	}
}

void randomGen(int *returnArray, int length){
	int seed=0xbeeeeeef;
	
	for (int i=0;i<length;i++){
		seed*=MULTIPLY;
		seed+=INCREMENT;
		if (seed<0) seed=seed*-1;
		returnArray[i]=seed;
	}
}

int main(){
	int arrayLen=100000000;
	int* test=(int*) calloc(arrayLen, sizeof(int));
	clock_t t;
    t = clock();
	randomGen(test,arrayLen);
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Number generation took %f seconds to execute for %d elements \n", time_taken, arrayLen); 
    t = clock(); 
	radixSort(test,arrayLen);
    t = clock() - t; 
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Radix sort took %f seconds to execute for %d elements \n", time_taken, arrayLen); 
	//for (int i=0;i<arrayLen;i++) printf("%d \n",test[i]);
	free(test);
}
