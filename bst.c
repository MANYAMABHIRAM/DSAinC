#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct bst
{
    int data;
    struct bst *left, *right;
};
typedef struct bst bst;
int in[100], pre[100], post[100], inorder = 0,preorder=0,postorder=0;
bst *create(int value)
{
    bst *node;
    node = malloc(sizeof(bst));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}
bst *insert(bst *root, int value)
{
    if (root == NULL)
        return create(value);
    else if (root->data >= value)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}
void inorder_Traversal(bst *root)
{
    if (root != NULL)
    {
        inorder_Traversal(root->left);
        in[inorder]=root->data;
        inorder++;
        inorder_Traversal(root->right);
    }
}
void preorder_Traversal(bst *root)
{
    if (root != NULL)
    {
        pre[preorder]=root->data;
        preorder++;
        preorder_Traversal(root->left);
        preorder_Traversal(root->right);
    }
}
void postorder_Traversal(bst *root)
{
    if (root != NULL)
    {
        postorder_Traversal(root->left);
        postorder_Traversal(root->right);
        post[postorder]=root->data;
        postorder++;
    }
}
void display(int *arr,int n){
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
}
bst *find_minimum(bst *root)
{
    if (root == NULL)
        return NULL;
    else if (root->left != NULL)
        return find_minimum(root->left);
    return root;
}
bst *deleteNode(bst *root, int value)
{
    if (root == NULL)
        return NULL;
    else if (value < root->data)
         root->left = deleteNode(root->left, value);
    else if (value > root->data)
         root->right = deleteNode(root->right, value);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            bst *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL && root->left != NULL)
        {
            bst *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            bst *temp = find_minimum(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
     return root;
}
int lh,rh;
int height(bst* root){
    if(root==NULL)
        return 0;
    else{
        lh=height(root->left);
        rh=height(root->right);
    }
    return fmax(lh,rh)+1;
}
void level_order(bst* root){
    int h=height(root);
    for(int i=0;i<h;i++){
        level_print(root,i);
    }
}
void level_print(bst* root,int level){
    if(root==NULL)
        return;
    else if(level==0)
        printf("%d ",root->data);
    else{
        level_print(root->left,level-1);
        level_print(root->right,level-1);
    }
}
int main()
{
    bst *root;
    int flag = 0, ch, value, n;
    while (1)
    {
        printf("\n1-Insert\n2-Delete Node\n3-Inorder Traversal\n4-Preorder Traversal\n5-Postorder Taversal\n6-Minimum elemnt\n7-Height of the tree\n8-Levelorder Traversal\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter no.of nodes to insert:");
            scanf("%d", &n);
            printf("\nEnter values:");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &value);
                if (flag == 0)
                {
                    root = create(value);
                    flag++;
                }
                else
                {
                    insert(root, value);
                }
            }
            break;
        case 2:
            printf("\nEnter value to delete the node:");
            scanf("%d", &value);
            deleteNode(root, value);
            break;
        case 3:
            printf("\nInorder Traversal:");
            inorder_Traversal(root);
            display(in,inorder);
            break;
        case 4:
            printf("\nPreorder Traversal:");
            preorder_Traversal(root);
            display(pre,preorder);
            break;
        case 5:
            printf("\nPostorder Traversal:");
            postorder_Traversal(root);
            display(post,postorder);
            break;
        case 6:
            printf("\nMininmum Element:");
            bst *temp = find_minimum(root);
            printf("%d", temp->data);
            break;
        case 7:printf("\nHeight of tree:%d",height(root));
                break;
        case 8:printf("\nLevelorder Traversal:");
                level_order(root);
                break;
        default:
            printf("You Entered wrong choice :(");
            exit(0);
        }
    }
    return 0;
}
