#include<stdio.h>
void main()
{
    int a[50][50],b[50][50],c[50][50],pt1=1,pt2=1,f1=0;
    int r1,c1,n1,r2,c2,n2,i,j;
    printf("Enter the no of rows of first triplet: ");
    scanf("%d",&r1);
    printf("Enter the no of cols of first triplet: ");
    scanf("%d",&c1);
    printf("Enter the no of non zero elements of the first triplet: ");
    scanf("%d",&n1);
    printf("Enter the triplet:\n");
    for(i=1;i<=n1;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    a[0][0]=r1;
    a[0][1]=c1;
    a[0][2]=n1;
    printf("Enter the no of rows of second triplet: ");
    scanf("%d",&r2);
    printf("Enter the no of cols of second triplet: ");
    scanf("%d",&c2);
    printf("Enter the no of non zero elements of the second triplet: ");
    scanf("%d",&n2);
    printf("Enter the triplet:\n");
    for(i=1;i<=n2;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    b[0][0]=r2;
    b[0][1]=c2;
    b[0][2]=n2;
    printf("The triplet 1 is : \n");
    for(i=0;i<n1;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    printf("The triplet 2 is : \n");
    for(i=0;i<n2;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d\t",b[i][j]);
        }
        printf("\n");
    }
    if(r1==r2 && c1==c2)
    {
        while(pt1<=n1 && pt2<=n2)
        {
            if(a[pt1][0]==b[pt2][0])
            {
                if(a[pt1][1]==b[pt2][1])
                {
                    f1++;
                    c[f1][0]=a[pt1][0];
                    c[f1][1]=a[pt1][1];
                    c[f1][2]=a[pt1][2]+b[pt2][2];
                    pt1++;
                    pt2++;
                }
                else if(a[pt1][1]<b[pt2][1])
                {
                    f1++;
                    c[f1][0]=a[pt1][0];
                    c[f1][1]=a[pt1][1];
                    c[f1][2]=a[pt1][2];
                    pt1++;
                }
                else
                {
                    f1++;
                    c[f1][0]=b[pt2][0];
                    c[f1][1]=b[pt2][1];
                    c[f1][2]=b[pt2][2];
                    pt2++;
                }
            }
            else if(a[pt1][0]<b[pt2][0])
            {
                f1++;
                c[f1][0]=a[pt1][0];
                c[f1][1]=a[pt1][1];
                c[f1][2]=a[pt1][2];
                pt1++;
            }
            else
            {
                f1++;
                c[f1][0]=b[pt2][0];
                c[f1][1]=b[pt2][1];
                c[f1][2]=b[pt2][2];
                pt2++;
            }
        }
        while(pt1<=n1)
        {
            f1++;
            c[f1][0]=a[pt1][0];
            c[f1][1]=a[pt1][1];
            c[f1][2]=a[pt1][2];
            pt1++;
        }
        while(pt2<=n2)
        {
            f1++;
            c[f1][0]=b[pt2][0];
            c[f1][1]=b[pt2][1];
            c[f1][2]=b[pt2][2];
            pt2++;
        }
        c[0][0]=r1;
        c[0][1]=r2;
        c[0][2]=f1;
        printf("The added triplet is : \n");
        for(i=0;i<=f1;i++)
        {
            for(j=0;j<3;j++)
            {
                printf("%d\t",c[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Addition is not possible!!");
    }
}