#include<stdio.h>

void display(int arr[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int indInsertion(int arr[], int size,int elemant, int capacity , int index){
	if(size>=capacity){
		return -1;
	}
	int i;
	for(i = size -1; i >= index;i--){
		arr[i+1] = arr[i];
	}
	arr[index] = elemant;
	return 1;
}

void indDeletion(int arr[], int size,int elemant, int capacity , int index){
	if(size < index){
		return;
	}
	int i;
	for(i = index; i >= size -1;i++){
		arr[i] = arr[i+1];
	}
}

int main(){
	int arr[100] = {7,8,12,27,88};
	int size = 4 , elemant= 0 , index= 0;
	printf("Enetr the Where index you have insert the elemant (max capacity : 0 - %d ) : ",size);
	scanf("%d",&index);
	printf("enter the elemant which you have add : ");
	scanf("%d",&elemant);
	display(arr,size);
	
	// Insertion
	int temp = indInsertion(arr,size,elemant,100,index);
	int i = 0;
	if(temp == 1){
		size++;
		display(arr,size);
	}else{
		printf("size is Greater Then Capacity.");
	}
	
	// Deletion
	
	indDeletion(arr,size,elemant,100,index);
	size--;
	display(arr,size);
	
	return 0;
}
