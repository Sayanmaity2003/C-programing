#include<stdio.h>

int main(){
int arr[] = {4,9,65,100,150,200};
int size = 6;
int data;
printf("Enter the data to search: ");
scanf("%d",&data);
//Binary Search, Time complexity: O(log n)
	       //Space Complexity: O(1)
int flag = 1;
int lb = 0, ub = 5;
while(lb<=ub){
	int mid = (lb+ub)/2;
	if(arr[mid]==data){
		printf("%d is found",data);
		flag = 0;
		break;
	}else if(data>arr[mid]){
		lb = mid+1;
	}else if(data<arr[mid]){
		ub = mid-1;
	}
}
if (flag==1){
	printf("%d is not found\n",data);
}
return 0;
}
