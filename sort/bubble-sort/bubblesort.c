#include <stdio.h>
#include <stdlib.h> 
#define N 11
//total 10 element, 0 for temp
int data[N];

void bubble_in(){
	int i,j;
	for(i = 1; i < N; i++){
		for(j = 1; j < N; j++){
			if(data.[j] < data[j+1]){
				data[0] = data[j+1];
				data[j+1] = data[j];
				data[j] = data[0];
			}
		}
	}
}

void  display(){
	for(i = 1; i < N; i++){
		printf("%d\t",data[i]);
	}
	printf("\n");
}

void bubble_de(){
	int i,j;
	for(i = N; i > 1; i--){
		for(j = N-1; j >  
	}
}
