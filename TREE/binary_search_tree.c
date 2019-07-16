#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
}*root,*max,*min;

struct node* insert(int a,struct node* root)
{
    if(root==NULL)
    {
        root = (struct node*)malloc(sizeof(struct node));
        root->data = a;
        root->left=root->right=NULL;
    }
    else if(a<root->data)
        root->left=insert(a,root->left);
    else if(a>root->data)
        root->right= insert(a,root->right);
    return root;
}

void inorder(struct node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void postorder(struct node *root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

void preorder(struct node *root)
{
    if(root==NULL)
        return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

struct node* max_value(struct node *root)
{
    if(root==NULL)
        return 0;
    else if(root->right==NULL)
        return root;
    else
        return max_value(root->right);
}

struct node* min_value(struct node *root)
{
    if(root==NULL)
        return 0;
    else if(root->left==NULL)
        return root;
    else
        return min_value(root->left);
}

int main()
{
    int ch,ele;
    while(1)
    {
        printf("1.insert\n");
        printf("2.inorder\n");
        printf("3.postorder\n");
        printf("4.preorder\n");
        printf("5.find max value\n");
        printf("6.find min value\n");
        printf("7.height of BST\n");
        printf("8.check BST is balanced or not\n");
        printf("9.remove/delete node\n");
        printf("10.empty the tree\n");
        printf("11.search element\n");
        printf("12.exit\n");
        printf("enter your choice = ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: 
                printf("enter element to insert into the tree = ");
                scanf("%d",&ele);
                root = insert(ele,root);
                printf("\n");
                break;
            case 2:
                inorder(root);
                printf("\n");
                break;
            case 3:
                postorder(root);
                printf("\n");
                break;
            case 4:
                preorder(root);
                printf("\n");
                break;
            case 5:
                max = max_value(root);
                printf("max value is = %d\n",max->data);
                break;
            case 6:
                min = min_value(root);
                printf("min value is = %d\n",min->data);
                break;
            case 7:
                exit(0);
            default:
                printf("..........INVALID CHOICE..........\n");
        }
    }
}
