#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int key;                
    struct Node *left;      
    struct Node *right;     
    int height;            
};


int getHeight(struct Node *n)
{
    if (n == NULL)
        return 0;           
    return n->height;
}


struct Node *createNode(int key)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;     
    return node;
}


int max(int a, int b)
{
    return (a > b) ? a : b;
}


// Balance factor = height(left subtree) - height(right subtree)
int getBalancedFactor(struct Node *n)
{
    if (n == NULL)
        return 0;
    return getHeight(n->left) - getHeight(n->right);
}


struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    
    return x;
}


struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    
    y->left = x;
    x->right = T2;

    
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    
    return y;
}


struct Node *insert(struct Node *node, int key)
{
    
    if (node == NULL)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; 

    
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    
    int bf = getBalancedFactor(node);

    

    // Left Left Case
    if (bf > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (bf < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (bf > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (bf < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the unchanged node pointer
    return node;
}

// Function to print preorder traversal of the tree
// Preorder traversal: Root -> Left -> Right
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    struct Node *root = NULL;

    
    root = insert(root, 10);
    root = insert(root, 11);
    root = insert(root, 12);

    printf("Preorder Traversal of AVL Tree:\n");
    preorder(root);
    printf("\n");

    return 0;
}
