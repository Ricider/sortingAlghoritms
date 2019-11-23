#include <stdio.h>
#define INCREMENT 2746
#define MULTIPLY 6437

void radixSort(int *array, int length){
	for (int nibbleIndex=0; nibbleIndex<8; nibbleIndex++){
	
		int newArray[length];
		int temporary[length];
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
	int arrayLen=600000;
	int test[arrayLen];
	randomGen(test,arrayLen);
	radixSort(test,arrayLen);
	for (int i=0;i<arrayLen;i++){
		printf("%d \n",test[i]);
	}
}
