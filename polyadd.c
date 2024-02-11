#include <stdio.h>
#include <stdlib.h>

int n;

struct poly
{
    int exp;
    int coeff;
    struct poly *link;
} *poly1, *poly2, *poly3, *poly4, *new, *ptr, *head;

struct poly *read_poly()
{
    head = NULL;
    printf("Enter the highest degree of the polynomial : ");
    scanf("%d", &n);
    for (int i = n; i >= 0; i--)
    {
        new = (struct poly *)malloc(sizeof(struct poly));
        printf("Enter the coefficient of x^%d : ", i);
        scanf("%d", &new->coeff);
        new->exp = i;
        new->link = NULL;
        if (head == NULL)
        {
            head = new;
            ptr = head;
        }
        else
        {
            ptr->link = new;
            ptr = ptr->link;
        }
    }
    return head;
}

struct poly *add_poly(struct poly *p1, struct poly *p2)
{
    head = NULL;
    poly1 = p1;
    poly2 = p2;
    while (poly1 != NULL && poly2 != NULL)
    {
        new = (struct poly *)malloc(sizeof(struct poly));
        if (poly1->exp > poly2->exp)
        {
            new->coeff = poly1->coeff;
            new->exp = poly1->exp;
            new->link = NULL;
            poly1 = poly1->link;
        }
        else if (poly1->exp < poly2->exp)
        {
            new->coeff = poly2->coeff;
            new->exp = poly2->exp;
            new->link = NULL;
            poly2 = poly2->link;
        }
        else
        {
            new->coeff = poly1->coeff + poly2->coeff;
            new->exp = poly2->exp;
            new->link = NULL;
            poly1 = poly1->link;
            poly2 = poly2->link;
        }
        if (head == NULL)
        {
            head = new;
            ptr = head;
        }
        else
        {
            ptr->link = new;
            ptr = ptr->link;
        }
    }
    while (poly1 != NULL)
    {
        new = (struct poly *)malloc(sizeof(struct poly));
        new->coeff = poly1->coeff;
        new->exp = poly1->exp;
        new->link = NULL;
        ptr->link = new;
        ptr = ptr->link;
        poly1 = poly1->link;
    }
    while (poly2 != NULL)
    {
        new = (struct poly *)malloc(sizeof(struct poly));
        new->coeff = poly2->coeff;
        new->exp = poly2->exp;
        new->link = NULL;
        ptr->link = new;
        ptr = ptr->link;
        poly2 = poly2->link;
    }
    return head;
}

struct poly *multi_poly(struct poly *p1, struct poly *p2)
{
    head = NULL;
    poly1 = p1;
    poly2 = p2;

    while (poly1 != NULL)
    {
        poly2 = p2;
        while (poly2 != NULL)
        {
            new = (struct poly *)malloc(sizeof(struct poly));
            new->coeff = poly2->coeff * poly2->coeff;
            new->exp = poly2->exp + poly1->exp;
            new->link = NULL;
            poly2 = poly2->link;
            if (head == NULL)
            {
                head = new;
                ptr = head;
            }
            else
            {
                ptr->link = new;
                ptr = ptr->link;
            }
        }
        poly1 = poly1->link;
    }
    return head;
}

// void display_poly(struct poly *head)
// {
//     ptr = head;
//     while (ptr != NULL)
//     {
//         if (ptr->exp == 0)
//         {
//             printf("%d\t", ptr->coeff);
//         }
//         else if (ptr->exp == 1)
//         {
//             printf("%dx\t", ptr->coeff);
//         }
//         else
//         {
//             printf("%dx^%d\t", ptr->coeff, ptr->exp);
//         }
//         if (ptr->link != NULL)
//         {
//             printf(" + ");
//         }
//         ptr = ptr->link;
//     }
// }


void display_poly(struct poly *head)
{
    ptr = head;
    while (ptr != NULL)
    {
        if (ptr->exp == 0)
        {
            printf("%d", ptr->coeff);
        }
        else if(ptr->exp == 1)
        {
            printf("%dx",ptr->coeff);
        }
        else
        {
            printf("%dx^%d",ptr->coeff,ptr->exp);
        }
        if(ptr->link!=NULL)
        {
            printf(" + ");
        }
        ptr = ptr ->link;
    }
    printf("\n");
}


void main()
{
    printf("Enter the first poly\n");
    poly1 = read_poly();
    printf("Enter the second poly\n");
    poly2 = read_poly();
    // poly3 = add_poly(poly1, poly2);
    // display_poly(poly3);
    poly4 = multi_poly(poly1, poly2);
    display_poly(poly4);
}