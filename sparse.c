#include<stdio.h>
void main()
{
    int row,col,a[50][50],i,j;
    printf("Enter the no of rows and columns\n");
    scanf("%d%d",&row,&col);
    printf("Enter the elements of the matrix:\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("The matrix is :\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d  ",a[i][j]);
        }
        printf("\n");
    }
    int k=0,c[50][50];
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(a[i][j]!=0)
            {
                k++;
                c[k][0]=i;
                c[k][1]=j;
                c[k][2]=a[i][j];
            }
        }  
    }
    c[0][0]=row;
    c[0][1]=col;
    c[0][2]=k;
    printf("The triplet is :\n");
    for(i=0;i<c[0][2]+1;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d  ",c[i][j]);
        }
        printf("\n");
    }
    int d[50][50],kd;
    row=c[0][0];
    col=c[0][1];
    k=c[0][2];
    kd=0;
    for(i=0;i<col;i++)
    {
        for(j=1;j<=k;j++)
        {
            if(c[j][1]==i)
            {
                kd++;
                d[kd][0]=c[j][1];
                d[kd][1]=c[j][0];
                d[kd][2]=c[j][2];
            }
        }
    }
    d[0][0]=c[0][1];
    d[0][1]=c[0][0];
    d[0][2]=c[0][2];
    printf("The transposed triplet is :\n");
    for(i=0;i<c[0][2]+1;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d  ",d[i][j]);
        }
        printf("\n");
    }
    int sum[50][50],count=0;
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