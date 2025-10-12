#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[10][10],b[10][10],c[10][10],i,k,j,m1,m2,n1,n2;
	printf("Enter the dimensions of a and b matrices:-");
	scanf("%d%d%d%d",&m1,&n1,&m2,&n2);
	if(n1!=m2)
	{
		printf("Multiplication is not possible");
		exit(1);
	}
	else
	{
		printf("Enter the first matrix");
		for(i=0;i<m1;i++)
		for(j=0;j<n1;j++)
		scanf("%d",&a[i][j]);
		printf("Enter the second matrix");
		for(i=0;i<m2;i++)
		for(j=0;j<n2;j++)
		scanf("%d",&b[i][j]);
	}
	for(i=0;i<m1;i++)
	{
		for(j=0;j<n2;j++)
		{
			c[i][j]=0;
			for(k=0;k<n1;k++)
			{
				c[i][j]=c[i][j]+a[i][k]*b[k][j];
			}
		}
	}
	printf("The resultant matrix is:-");
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		printf("%d\t",c[i][j]);
		printf("\n");
	}
	return 0;
}
