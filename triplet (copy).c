#include<stdio.h>
void main()
{
	int a[50][50],r,c,i,j;
	printf("Enter the no of rows and columns : \n");
	scanf("%d%d",&r,&c);
	printf("Enter the elements : \n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("The entered matrix is :\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	int triplet[50][50],k=0;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(a[i][j]!=0)
			{
				k++;
				triplet[k][0]=i;
				triplet[k][1]=j;
				triplet[k][2]=a[i][j];
			}
		}
	}
	triplet[0][0]=r;
	triplet[0][1]=c;
	triplet[0][2]=k;
	printf("The triplet is : \n");
	for(i=0;i<triplet[0][2]+1;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t",triplet[i][j]);
		}
		printf("\n");
	}
	
	int transpose[50][50];
	k=0;
	for(i=0;i<triplet[0][1];i++)
	{
		for(j=1;j<=triplet[0][2];j++)
		{
			if(triplet[j][1]==i)
			{
				k++;
				transpose[k][0]=triplet[j][1];
				transpose[k][1]=triplet[j][0];
				transpose[k][2]=triplet[j][2];
			}
		}
	}
	transpose[0][0]=triplet[0][1];
	transpose[0][1]=triplet[0][0];
	transpose[0][2]=triplet[0][2];
	printf("The transpose is :\n");
	for(i=0;i<transpose[0][2]+1;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t",transpose[i][j]);
		}
		printf("\n");
	}
}
