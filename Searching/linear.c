#include<stdio.h>
int main(){
int arr[] = {58,96,33,21,2,854};
int size = 6;
int data;
printf("Enter the data to search: ");
scanf("%d",&data);
int flag=1;
//linear search , time complexity O(n)
for(int i=0; i<size; i++){
	if(arr[i]==data){
		printf("%d is found",data);
		flag = 0;
		break;
	}
}
if(flag==1){
	printf("%d is not found\n",data);
}
return 0;
}