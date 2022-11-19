#include <iostream>
using namespace std;

// Date : 1 November
// Binary search tree implementation

struct binarySearchTree
{
    int data;
    struct binarySearchTree *left;
    struct binarySearchTree *right;
};

typedef struct binarySearchTree node;
node *root = NULL, *temp = NULL;

void inorder(node *ptr)
{
    if (ptr != NULL)
    {
        inorder(ptr->left);
        cout << ptr->data << endl;
        inorder(ptr->right);
    }
}

void preorder(node *ptr)
{
    if (ptr != NULL)
    {
        cout << ptr->data << endl;
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void postorder(node *ptr)
{
    if (ptr != NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        cout << ptr->data << endl;
    }
}

void search(node *p)
{
    if (temp->data < p->data && p->left != NULL)
        search(p->left);
    if (temp->data < p->data && p->left == NULL)
        p->left = temp;
    if (temp->data > p->data && p->right != NULL)
        search(p->right);
    if (temp->data > p->data && p->right == NULL)
        p->right = temp;
}

void create()
{
    temp = new node;
    cout << "Enter data:" << endl;
    cin >> temp->data;
    temp->left = NULL;
    temp->right = NULL;
}

node *parent(node *ptr, int child)
{
    if (ptr->left != NULL || ptr->right != NULL)
    {
        if (root->data == child)
        {
            cout << "The child data is present in the root node, and it has no parent." << endl;
            return root;
        }
        else
        {
            if (child > ptr->data)
            {
                
            }
        }
    }
}

void insert()
{
    create();
    if (root == NULL)
        root = temp;
    else
        search(root);
}

int minimum(node *ptr)
{
    while (ptr->left != NULL)
    {
        ptr = ptr->left;
    }
    return ptr->data;
}

int maximum(node *ptr)
{
    while (ptr->right != NULL)
    {
        ptr = ptr->right;
    }
    return ptr->data;
}

void count(node *ptr, int *leaf, int *internal)
{
    if (ptr != NULL)
    {
        if (ptr->left == NULL && ptr->right == NULL)
            (*leaf)++;
        else
            (*internal)++;
        count(ptr->left, leaf, internal);
        count(ptr->right, leaf, internal);
    }
}

int main()
{
    int menu = 1, childData, leaf = 0, internal = 0;
    node *child = NULL;
    while (menu)
    {
        switch (menu)
        {
        case 1:
            insert();
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            cout << "The minimum value in the present BST is = " << minimum(root) << endl;
            break;
        case 4:
            cout << "The maximum value in the present BST is = " << maximum(root) << endl;
            break;
        case 5:
            cout << "Enter the data of the child whose parent must be found:" << endl;
            cin >> childData;
            cout << "Data in parent of parent node is " << parent(root, childData)->data << endl;
            break;
        case 6:
            count(root, &leaf, &internal);
            cout << "Number of leaf nodes is: " << leaf << endl;
            leaf = 0;
            internal = 0;
            break;
        case 7:
            count(root, &leaf, &internal);
            cout << "Number of internal nodes is: " << internal << endl;
            leaf = 0;
            internal = 0;
            break;
        default:
            break;
        }
        cout << "1. Insert node" << endl;
        cout << "2. Print BST in order" << endl;
        cout << "3. Minimum value in BST" << endl;
        cout << "4. Maximum value in BST" << endl;
        cout << "5. Parent of set node" << endl;
        cout << "6. Number of leaf nodes in present BST" << endl;
        cout << "7. Number of internal nodes in present BST" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter menu item: " << endl;
        cin >> menu;
    }
    return 0;
}