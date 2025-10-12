#include<stdio.h>
int n;
void createarray(int n,int a[])
{
	printf("Enter the number of elements in the array:-");
	scanf("%d",&n);
	printf("Enter the elements in the array:-");
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
}
	
void displayarray(int a[])
{
	printf("The elements of the array are:-");
	for(int i=0;i<n;i++)
	printf("%d",a[i]);
	printf("\n");
}
	
void insertelement(int a[],int n)
{
	int pos,value;
	printf("The position of element to be inserted is:-");
	scanf("%d",&pos);
	printf("Element to be inserted:-");
	scanf("%d",&value);
	for(int i=pos;i<n;i++)
	a[i]=a[i+1];
	a[pos]=value;
	n++;
}
	
void deleteelement(int a[],int n)
{
	int pos;
	printf("Enter the position of element to be deleted:-");
	scanf("%d",&pos);
	for(int i=pos;i<n-1;i++)
	a[i]=a[i-1];
	n--;
}
	
void linearsearch(int a[],int n)
{
	int ele;
	printf("Enter the element to be searched:-");
	scanf("%d",&ele);
	for(int i=0;i<n;i++)
	if (a[i]==ele)
	printf("Element is found at %d\n",i);
	else
	printf("Element not found");
}
int main()
{
	int a[n],n,choice;
	printf("1.CREATE\n");
	printf("2.DISPLAY\n");
	printf("3.INSERT\n");
	printf("4.DELETE\n");
	printf("5.LINEAR SEARCH\n");
	printf("6.EXIT\n");
	printf("Enter your choice:");
	scanf("%d",&choice);
	
	switch(choice){
	case 1: createarray(n,a);
	break;
	case 2: displayarray(a);
	break;
	case 3: insertelement(a,n);
	break;
	case 4: deleteelement(a,n);
	break;
	case 5: linearsearch(a,n);
	break;
	case 6: printf("Exiting program\n");
	break;
	default:printf("Invalid choice\n");
}
return 0;
}
