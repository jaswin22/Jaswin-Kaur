#include<stdio.h>
int main()
{
	int n,a[n],i,t;
	printf("Enter the number of elements in the array:-");
	scanf("%d",&n);
	printf("Enter the elements in the array:-");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	//printf("The elements of the array are:-");
	//for(i=0;i<n;i++){
	    //printf("%d\t",a[i]);}
	//printf("\n");
	for(i=0;i<n/2;i++)
	{
		t=a[i];
		a[i]=a[n-1-i];
		a[n-1-i]=t;
	}
	printf("Reversed array elements are:-");
	for(i=0;i<n;i++){
	    printf("%d\t",a[i]);}
	return 0;
}
