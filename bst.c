#include <stdio.h>
#include <stdlib.h>
struct bst
{
    int data;
    struct bst *left, *right;
};
typedef struct bst bst;
int in[100], pre[100], post[100], index = 0;
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
        printf("%d  ", root->data);
        inorder_Traversal(root->right);
    }
}
void preorder_Traversal(bst *root)
{
    if (root != NULL)
    {
        printf("%d  ", root->data);
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
        printf("%d  ", root->data);
    }
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
        return root->left = deleteNode(root->left, value);
    else if (value > root->data)
        return root->right = deleteNode(root->right, value);
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
            printf("\n%d\n", temp->data);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }
}
int main()
{
    bst *root;
    /*root = create(25);
    insert(root, 22);
    insert(root, 35);
    insert(root, 32);
    insert(root, 30);
    insert(root, 38);
    inorder_Traversal(root);
    printf("\n");
    preorder_Traversal(root);
    printf("\n");
    postorder_Traversal(root);
    bst *temp = find_minimum(root);
    // printf("\nMinimum element is:%d", temp->data);
    deleteNode(root, 35);
    printf("\n");
    inorder_Traversal(root);
    printf("\n");
    preorder_Traversal(root);
    printf("\n");
    postorder_Traversal(root);*/
    int flag = 0, ch, value, n;
    while (1)
    {
        printf("\n1-Insert\n2-Delete Node\n3-Inorder Traversal\n4-Preorder Traversal\n5-Postorder Taversal\n6-Minimum elemnt\nEnter your choice:");
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
            break;
        case 4:
            printf("\nPreorder Traversal:");
            preorder_Traversal(root);
            break;
        case 5:
            printf("\nPostorder Traversal:");
            postorder_Traversal(root);
            break;
        case 6:
            printf("\nMininmum Element:");
            bst *temp = find_minimum(root);
            printf("%d", temp->data);
            break;
        default:
            printf("You Entered wrong choice :(");
            exit(0);
        }
    }
    return 0;
}