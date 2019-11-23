#include <stdio.h>

void radixSort(int* array, int length){
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

int main(){
	int test[]={3,8,3785,53464,7,89,70,74,535,4,53,4245,25,2,12,7,17,5};
	radixSort(test,18);
	for (int i=0;i<18;i++){
		printf("%d ",test[i]);
	}
	printf("\n");
}
