#include<stdio.h>
int main()
{
    int a[50][50],b[50][50],tr1[50][50],tr2[50][50],i,j,r1,r2,c1,c2,m,n,k;
    int add[50][50];
    printf("Enter no of rows and columns of matrix A\n");
    scanf("%d %d",&r1,&c1);
    printf("Enter the sparce elements of matrix A\n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("The entered sparce A is\n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    m=0;
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            if(a[i][j]!=0)
            {
                m++;
                tr1[m][0]=i;
                tr1[m][1]=j;
                tr1[m][2]=a[i][j];
            }
        }
    }
    tr1[0][0]=r1;
    tr1[0][1]=c1;
    tr1[0][2]=m;
    printf("The triplet representation of sparce A is\n");
    for(i=0;i<=m;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",tr1[i][j]);
        }
        printf("\n");
    }
    printf("Enter the no of rows and columns of matrix B\n");
    scanf("%d %d",&r2,&c2);
    printf("Enter the sparce elements of matrix B\n");
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    printf("The entered sparce B is\n");
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    n=0;
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            if(b[i][j]!=0)
            {
                n++;
                tr2[n][0]=i;
                tr2[n][1]=j;
                tr2[n][2]=b[i][j];
            }
        }
    }
    tr2[0][0]=r2;
    tr2[0][1]=c2;
    tr2[0][2]=n;
    printf("The triplet representation of sparce B is\n");
    for(i=0;i<=n;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",tr2[i][j]);
        }
        printf("\n");
    }
    i=1;
    j=1;
    k=1;
    if(tr1[0][0]==tr2[0][0] && tr1[0][1]==tr2[0][1])
    {
        while(i<=tr1[0][2] && j<=tr2[0][2])
        {
            if(tr1[i][0]==tr2[j][0] && tr1[i][1]==tr2[j][1])
            {
                add[k][0]=tr1[i][0];
                add[k][1]=tr1[i][1];
                add[k][2]=tr1[i][2]+tr2[j][2];
                i++,j++,k++;
            }
            else if(tr1[i][0]==tr2[j][0])
            {
                if(tr1[i][1]<tr2[j][1])
                {
                    add[k][0]=tr1[i][0];
                    add[k][1]=tr1[i][1];
                    add[k][2]=tr1[i][2];
                    i++,k++;
                }
                else
                {
                    add[k][0]=tr2[j][0];
                    add[k][1]=tr2[j][1];
                    add[k][2]=tr2[j][2];
                    j++,k++;
                }
            }
            else
            {
                if(tr1[i][0]<tr2[j][0])
                {
                    add[k][0]=tr1[i][0];
                    add[k][1]=tr1[i][1];
                    add[k][2]=tr1[i][2];
                    i++,k++;
                }
                else
                {
                    add[k][0]=tr2[j][0];
                    add[k][1]=tr2[j][1];
                    add[k][2]=tr2[j][2];
                    j++,k++;
                }
            }
        }
        while(i<=tr1[0][2])
        {
            add[k][0]=tr1[i][0];
            add[k][1]=tr1[i][1];
            add[k][2]=tr1[i][2];
            i++,k++;
        }
        while(j<=tr2[0][2])
        {
            add[k][0]=tr2[j][0];
            add[k][1]=tr2[j][1];
            add[k][2]=tr2[j][2];
            j++,k++;
        }
        add[0][0]=tr1[0][0];
        add[0][1]=tr1[0][1];
        add[0][2]=k-1;
        printf("The added matrix is\n");
        for(i=0;i<=add[0][2];i++)
        {
            for(j=0;j<3;j++)
            {
                printf("%d ",add[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Addition not possible\n");
    }
}



