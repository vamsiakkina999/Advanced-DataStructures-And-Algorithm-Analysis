#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};

struct node* root=NULL;
int ch,x;

int max(int a,int b)
{
    if(a>b) return a;
    return b;
}

int height(struct node* n)
{
    if(n==NULL) return 0;
    return n->height;
}

struct node* newNode(int key)
{
    struct node* node=(struct node*)malloc(sizeof(struct node));
    node->key=key;
    node->left=NULL;
    node->right=NULL;
    node->height=1;
    return node;
}

struct node* rightRotate(struct node* y)
{
    struct node* x=y->left;
    struct node* t2=x->right;

    x->right=y;
    y->left=t2;

    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;

    return x;
}

struct node* leftRotate(struct node* x)
{
    struct node* y=x->right;
    struct node* t2=y->left;

    y->left=x;
    x->right=t2;

    x->height=max(height(x->left),height(x->right))+1;
    y->height=max(height(y->left),height(y->right))+1;

    return y;
}

int getBalance(struct node* n)
{
    if(n==NULL) return 0;
    return height(n->left)-height(n->right);
}

struct node* insert(struct node* node,int key)
{
    int balance;

    if(node==NULL)
        return newNode(key);

    if(key<node->key)
        node->left=insert(node->left,key);
    else if(key>node->key)
        node->right=insert(node->right,key);
    else
        return node;

    node->height=1+max(height(node->left),height(node->right));
    balance=getBalance(node);

    if(balance>1 && key<node->left->key)
        return rightRotate(node);

    if(balance<-1 && key>node->right->key)
        return leftRotate(node);

    if(balance>1 && key>node->left->key)
    {
        node->left=leftRotate(node->left);
        return rightRotate(node);
    }

    if(balance<-1 && key<node->right->key)
    {
        node->right=rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

struct node* minValue(struct node* node)
{
    struct node* current=node;
    while(current->left!=NULL)
        current=current->left;
    return current;
}

struct node* deleteNode(struct node* root,int key)
{
    int balance;

    if(root==NULL)
        return root;

    if(key<root->key)
        root->left=deleteNode(root->left,key);
    else if(key>root->key)
        root->right=deleteNode(root->right,key);
    else
    {
        if(root->left==NULL || root->right==NULL)
        {
            struct node* temp;

            if(root->left!=NULL)
                temp=root->left;
            else
                temp=root->right;

            if(temp==NULL)
            {
                temp=root;
                root=NULL;
            }
            else
                *root=*temp;

            free(temp);
        }
        else
        {
            struct node* temp=minValue(root->right);
            root->key=temp->key;
            root->right=deleteNode(root->right,temp->key);
        }
    }

    if(root==NULL)
        return root;

    root->height=1+max(height(root->left),height(root->right));
    balance=getBalance(root);

    if(balance>1 && getBalance(root->left)>=0)
        return rightRotate(root);

    if(balance>1 && getBalance(root->left)<0)
    {
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }

    if(balance<-1 && getBalance(root->right)<=0)
        return leftRotate(root);

    if(balance<-1 && getBalance(root->right)>0)
    {
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

struct node* search(struct node* root,int key)
{
    if(root==NULL || root->key==key)
        return root;

    if(key<root->key)
        return search(root->left,key);

    return search(root->right,key);
}

void inorder(struct node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->key);
        inorder(root->right);
    }
}

int main()
{
    while(1)
    {
        printf("\n");
        printf("AVL TREE OPERATIONS\n");
        printf("-------------------\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display (Inorder)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d",&x);
                root=insert(root,x);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d",&x);
                root=deleteNode(root,x);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d",&x);
                if(search(root,x))
                    printf("Element Found\n");
                else
                    printf("Element Not Found\n");
                break;

            case 4:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                exit(0);
        }
    }
}
