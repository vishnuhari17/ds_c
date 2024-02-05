#include<stdio.h>
void non_recursive_postorder(struct node *root)
{
    ptr = root;
    while (ptr != NULL && top != -1)
    {
        if(ptr!=NULL)
        {
            push(ptr);
            ptr=ptr->lchild;
        }
        else
        {
            ptr = pop();
            ptr=ptr->rptr;
            printf("%d",ptr->data);
        }
    }
    
}