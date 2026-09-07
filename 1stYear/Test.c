#include <stdio.h>
int main(){
	int n,sum=0;
	printf("Enter: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter elements:\n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<n;i++){
		sum+=arr[i];
	}
	printf("Sum: %d\n",sum);
	return 0;
}