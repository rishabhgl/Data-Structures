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

int min(int a, int b) { return (a < b) ? a : b; }
int max(int a, int b) { return (a > b) ? a : b; }

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

void insert()
{
    create();
    if (root == NULL)
        root = temp;
    else
        search(root);
}

node *minimum(node *ptr)
{
    while (ptr->left != NULL)
    {
        ptr = ptr->left;
    }
    return ptr;
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

node *parent(node *child)
{
    if (child != root)
    {
        node *ptr = root;
        while (ptr != NULL && (ptr->left != child && ptr->right != child))
        {
            if (ptr->data < child->data)
                ptr = ptr->right;
            else
                ptr = ptr->left;
        }
        return ptr;
    }
    else
        return NULL;
}

node *dataToPointer(int num)
{
    node *ptr = root;
    while (ptr != NULL && ptr->data != num)
    {
        if (ptr->data > num)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    return ptr;
}

node *findSuccessor(node *);

void deleteNode(node *ptr)
{
    node *tempParent = parent(ptr);
    node *successor;
    if (ptr->left == NULL && ptr->right == NULL)
    {
        if (tempParent->left == ptr)
            tempParent->left = NULL;
        else
            tempParent->right = NULL;
        delete ptr;
    }
    else if (ptr->left != NULL && ptr->right != NULL)
    {
        successor = findSuccessor(ptr);
        ptr->data = successor->data;
        deleteNode(successor);
    }
    else
    {
        if (ptr->right != NULL)
        {
            if (tempParent->left == ptr)
                tempParent->left = ptr->right;
            else
                tempParent->right = ptr->right;
        }
        else
        {
            if (tempParent->left == ptr)
                tempParent->left = ptr->left;
            else
                tempParent->right = ptr->left;
        }
        delete ptr;
    }
}

int min_depth(node *root)
{
    if (root->left != NULL && root->right != NULL)
    {
        return 1 + min(min_depth(root->left), min_depth(root->right));
    }
    else if (root->left != NULL)
    {
        return 1 + min_depth(root->left);
    }
    else if (root->right != NULL)
    {
        return 1 + min_depth(root->right);
    }
    else
        return 0;
}

int max_depth(node *root)
{
    if (root->left != NULL && root->right != NULL)
    {
        return 1 + max(max_depth(root->left), max_depth(root->right));
    }
    else if (root->left != NULL)
    {
        return 1 + max_depth(root->left);
    }
    else if (root->right != NULL)
    {
        return 1 + max_depth(root->right);
    }
    else
        return 0;
}

node *findSuccessor(node *pre)
{
    node *tempParent;
    if (pre->right != NULL)
        return minimum(pre->right);
    else
    {
        tempParent = parent(pre);
        while (tempParent != NULL && tempParent->left != pre)
        {
            pre = tempParent;
            tempParent = parent(pre);
        }
        return tempParent;
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
            // cout << "The minimum value in the present BST is = " << minimum(root) << endl;
            preorder(root);
            break;
        case 4:
            // cout << "The maximum value in the present BST is = " << maximum(root) << endl;
            postorder(root);
            break;
        case 5:
            cout << "Enter the data of the child whose parent must be found:" << endl;
            cin >> childData;
            child = dataToPointer(childData);
            if (child != NULL)
            {
                child = parent(child);
                cout << "Data in parent node is " << child->data << endl;
            }
            break;
        case 6:
            // count(root, &leaf, &internal);
            // cout << "Number of leaf nodes is: " << leaf << endl;
            // leaf = 0;
            // internal = 0;
            cout << "Enter the data of the item that must be deleted: " << endl;
            cin >> childData;
            child = dataToPointer(childData);
            deleteNode(child);
            break;
        case 7:
            // count(root, &leaf, &internal);
            // cout << "Number of internal nodes is: " << internal << endl;
            // leaf = 0;
            // internal = 0;
            cout << "The minimum depth of the BST is " << min_depth(root) << endl;
            break;
        case 8:
            cout << "The maximum depth of the BST is " << max_depth(root) << endl;
            break;
        default:
            break;
        }
        cout << "1. Insert node" << endl;
        cout << "2. Print BST in order" << endl;
        cout << "3. Print BST pre order" << endl;
        cout << "4. Print BST post order" << endl;
        // cout << "3. Minimum value in BST" << endl;
        // cout << "4. Maximum value in BST" << endl;
        cout << "5. Parent of given node" << endl;
        // cout << "6. Number of leaf nodes in present BST" << endl;
        // cout << "7. Number of internal nodes in present BST" << endl;
        cout << "6. Delete a node" << endl;
        cout << "7. Minimum depth of the BST" << endl;
        cout << "8. Maximum depth of the BST" << endl;
        cout << "0. Exit" << endl;
        cout << endl
             << "Enter menu item: " << endl;
        cin >> menu;
    }
    return 0;
}