// Write a non recursive algorithm and program to find the preorder traversal of a
// binary tree.

void non_reccursive_preorder(struct node *root)
{
    if(root==NULL)
    {
        printf("The Binary tree is empty\n");
    }
    else
    {
        ptr = root;
        push(ptr);
        while(top!=-1)
        {
            ptr = pop();
            printf("%d\t",ptr->data);
            if(ptr->rchild!=NULL)
                push(ptr->rchild);
            if(ptr->lchild!=NULL)
                push(ptr->lchild);
        }
    }
}
