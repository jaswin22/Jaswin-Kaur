#include<stdio.h>
int main() 
{
	int a [10][10],b[10],c[10],m,n,i,j;
	printf("Enter the dimensions of the matrix:-");
	scanf("%d%d",&m,&n);
	printf("Enter the elements into the matrix");
	for(i=0;i<m;i++)
	for(j=0;j<n;j++)
	scanf("%d",&a[i][j]);
	for(i=0;i<m;i++)
	{
		b[i]=0;
		for(j=0;j<n;j++)
		b[i]=b[i]=a[i][j];
	}
	for(i=0;i<n;i++)
	{
		c[i]=0;
		for(j=0;j<m;j++)
		c[i]=c[i]+a[j][i];
	}
	printf("Sum of rows\n");
	for(i=0;i<m;i++)
	printf("%d\t",b[i]);
	printf("\n");
	printf("Sum of columns\n");
	for(j=0;j<n;j++)
	printf("%d\t",c[j]);
	return 0;
}
