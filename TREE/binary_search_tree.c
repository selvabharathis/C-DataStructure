// SELVABHARATHI S B.Tech(IT)
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

int height_BST(struct node* root)
{
  int max;
  if(!root)
    return -1;
  int leftHeight = height_BST(root->left);   //line 1
  int rightHeight = height_BST(root->right); //line 2
  if(leftHeight > rightHeight)
    max = leftHeight;
  else
    max = rightHeight;
  return (1 + max);  //line 1 and 2 can be optimized as "return (1 + max(height_BST(root->left),height_BST(root->right)));"
}

int balanced_Or_Not(struct node* root)
{
  if(!root)
    return 0;
  int leftheight = height_BST(root->left);
  int rightheight = height_BST(root->right);
  if(abs(leftheight-rightheight) > 1)
    return 0;
  return 1;
}

struct node* search(struct node* root,int element)
{
  if(!root)
    return 0;
  else if(element < root->data)
    return search(root->left,element);
  else if(element > root->data)
    return search(root->right,element);
  else
    return root;
}

struct node* delete_Node(struct node* root,int key)  // WRONG
{
  struct node *temp;
  if(root == NULL)
    return NULL;
  else if(key < root->data)
    root->left = delete_Node(root->left,key);
  else if(key > root->data)
    root->right = delete_Node(root->right,key);
  else if(root->left && root->right)
  {
    temp = min_value(root->right);
    root->data = temp->data;
    root->right = delete_Node(root->right,root->data);
  }
  else
  {
    temp = root;
    if(root->left == NULL)
      root = root->right;
    else if(root->right == NULL)
      root = root->left;
    free(temp);
  }
}

struct node* empty(struct node *root) // WRONG
{
    if(root==NULL)
        return NULL;
    else
    {
      empty(root->left);
      empty(root->right);
      free(root->data);
    }
    return NULL;
}

int main()
{
    int ch,ele;
    while(1)
    {
        printf("\n");
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
        printf("12.depth of given node\n");
        printf("13.exit\n");
        printf("\tenter your choice = ");
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
                printf("height of the BST is = %d\n",height_BST(root));
                break;
            case 8:
                if(balanced_Or_Not(root))
                  printf("the tree is balanced\n");
                else
                  printf("the tree is not balanced\n");
                break;
            case 9:
                printf("enter node to delete = ");
                scanf("%d",&ele);
                delete_Node(root,ele);
                printf("\n");
                break;
            case 10:
                root = empty(root);
                break;
            case 11:
                printf("enter element to search = ");
                scanf("%d",&ele);
                if(search(root,ele) != NULL)
                  printf("element found\n");
                else
                  printf("element not found\n");
                break;
            case 13:
                exit(0);
            default:
                printf("..........INVALID CHOICE..........\n");
        }
    }
}


/****************************************************************************************************************

TREE
    a tree is a non linear two dimension data structure, which represent hierachical relationship between two
    data item.
TYPES OF TREE
    >Binary search tree
    >AVL tree
    >Splay tree
    >B tree
    >Binary Heap or heap
    >Binomial Heap
    >Fibonacci Heap
    >Red-Black tree

NODE
    each data item in a tree.

EDGE
    the link between two node.

DEGREE
    the total number of sub-tree attached to the node.

LEAVES
    terminal node or bottom most node, which has no more childreen.

PARENT NODE
    node which has further sub-tree.

INTERNAL NODE
    node other than leaf and root node.

PREDECESSOR
    node occur previous to some other node.

SUCCESSOR
    node occur next to some other node.

BINARY TREE
    it can have atmost two childreen

TYPES OF BINARY TREE
    > strict/proper binary tree
    > complete binary tree
    > perfect binary tree
    > balanced binary tree

STRICT BINARY TREE
    If each node has either 2 or 0 children is called as strict binary tree.

COMPLETE BINARY TREE
    A binary tree is called as complete binary tree if all the level except the last level are,
   completely full and the last level has all its nodes to its left.

PERFECT BINARY TREE
    If the all the levels are completely filled, such a tree is called as perfect binary tree.
    Hence the total number of nodes in a perfect binary tree will be 2^(num of level) -1;

REPRESENTATION OF A BINARY TREE
    >Linear representation (using array)
    >Linked representation (using pointer)

EXPRESSION TREE
    it is a binary tree in which the leaf node are operand and the iternal node are operator.

TREE TRAVERSAL
  BREADTH FIRST TRAVERSAL
    we should start from level 1,then cover all nodes in that level, then go to the next level.
  DEPTH FIRST TRAVERSAL
    in this, once we get a child we would complete the while sub tree of that child before going to the next child.
    depending on our traversal we have 6 permutation. but we commonly use these three, they are:-
    >inorder(left->data->right)
    >preorder(data->left->right)
    >postorder(left->right->data)

BINARY SEARCH TREE
    a binary search tree is a binary tree, in which key value in the left node is less than root and key value of right node
    is greater than root.

BALANCED BINARY SEARCH TREE
    balance factor(BF) = height of left subtree - height of right subtree.
    when BF is -1,0,1 then the tree is a balanced binary search tree.

HEIGHT
    the height of a node/root is the longest downward path(i.e number of edges) from node/root to a leaf node.
    the height of a binary tree is the height of the root node.

DEPTH
    the depth of a node is the longest upward path from the node to the root node.
    depth of root is 0.
NOTE:: height and depth of a tree is equal.
       but, height and depth of a node is not equal.

LEVEL
    the level of a node is defined by,
    (1 + the number of connection between the node and root)
    level = depth + 1;
    level of root is 1.





***************************************************************************************************************/
