#include<stdio.h>
void main()
{
	int sum[50][50],c[50][50],d[50][50],i,j,r,col,k;
	printf("Enter the no of rows and columns of 1st triplet: \n");
	scanf("%d%d",&r,&col);
	printf("Enter the elements : \n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<col;j++)
		{
			scanf("%d",&c[i][j]);
		}
	}
	printf("The entered triplet 1 is :\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%d\t",c[i][j]);
		}
		printf("\n");
	}
	printf("Enter the no of rows and columns of 2st triplet: \n");
	scanf("%d%d",&r,&c);
	printf("Enter the elements : \n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<col;j++)
		{
			scanf("%d",&d[i][j]);
		}
	}
	printf("The entered triplet 2 is :\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%d\t",d[i][j]);
		}
		printf("\n");
	}
	int count=0;
    i=1,j=1;
    if(c[0][0]==d[0][0] && c[0][1]==d[0][1])
    {
        while(i<=c[0][2] || j<=d[0][2])
        {
            if(c[i][0]==d[j][0] && c[i][1]==d[j][1])
            {
                count++;
                sum[count][0]=c[i][0];
                sum[count][1]=c[i][1];
                sum[count][2]=c[i][2]+d[j][2];
                i++;
                j++;
            }
            else if(c[i][0]==d[j][0])
            {
                if(c[i][1]<d[j][1])
                {
                    count++;
                    sum[count][0]=c[i][0];
                    sum[count][1]=c[i][1];
                    sum[count][2]=c[i][2];
                    i++;
                }
                else
                {
                    count++;
                    sum[count][0]=d[j][0];
                    sum[count][1]=d[j][1];
                    sum[count][2]=d[j][2];
                    j++;
                }
            }
        }
        sum[0][0]=c[0][0];
        sum[0][1]=c[0][1];
        sum[0][2]=count;
    }
    
    else
    {
        printf("Error!! : Addition is not possible");
    }
    printf("The Sum triplet is :\n");
    for(i=0;i<sum[0][2]+1;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d  ",sum[i][j]);
        }
        printf("\n");
    }
   }
