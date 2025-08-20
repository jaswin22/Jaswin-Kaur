#include<stdio.h>
int main()
{
	int n,a[n],i,j,k;
	printf("Enter the number of elements in the array:-");
	scanf("%d",&n);
	printf("Enter the elements in the array:-");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("The elements of the array are:-");
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);
	printf("\n");
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]==a[j])
			{
				for(k=j;k<n-1;k++)
				{
					a[k]=a[k+1];
				}
				n=n-1;
				j=j-1;
			}
		}
	}
	printf("The elements of the array after deletion of duplicate elements are:-");
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);
	return 0;
}
