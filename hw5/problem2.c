#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// struct for binary tree nodes
typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
} Node;

// prints preorder tree traversal
void preOrder(struct node* root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

// prints inorder tree traversal
void inOrder(struct node* root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

// prints postorder tree traversal
void postOrder(struct node* root)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

// mallocs and creates a new node with the given data
Node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// deletes a node from the binary tree
Node* deleteNode(Node* root, int value, bool* deletedPtr)
{
    // if no root, then just return root node/NULL
    if (root == NULL)
        return root;

    // if value is less than the root, recursively go left
    if (value < root->data)
        root->left = deleteNode(root->left, value, deletedPtr);
    // if the value is greater than the root, recursively go right
    else if (value > root->data)
        root->right = deleteNode(root->right, value, deletedPtr);
    // if equal to the current node
    else
    {
        *deletedPtr = true; // set dereferenced location of deletedPtr to true if a matching node data has been found and will be deleted
        
        // one or no children
        // if left node is null, then right node moves up
        if (root->left == NULL)
        {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        // if right node is null, then left node moves up
        else if (root->right == NULL)
        {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // node with two children
        // find the next suitable node, which is the smallest right subtree node
        Node* current = root->right;

        // find the smallest node in the right subtree
        while (current && current->left != NULL)
            current = current->left;

        // set current root node as the smallest node in the right subtree
        root->data = current->data;

        // delete the smallest node in the right subtree since it has been moved
        root->right = deleteNode(root->right, current->data, deletedPtr);
    }

    return root;
}

// problem2ec is the same as this problem since both use tree traversal printing to display results
void hw5p2(void)
{
    // creating a tree manually

    // Tree 1
    Node* root = newNode(10);

    Node* node1 = newNode(7);
    root->left = node1;

    Node* node2 = newNode(15);
    root->right = node2;

    Node* node3 = newNode(3);
    node1->left = node3;
    Node* node4 = newNode(8);
    node1->right = node4;

    Node* node5 = newNode(17);
    node2->right = node5;

    /* Resultant tree
                  10
                /    \
              7       15
            /   \       \
           3     8       17
        Preorder:   10 7 3 8 15 7
        Inorder:    3 7 8 10 15 17
        Postorder:  3 8 7 17 15 10
    */

    // Tree 2
    /*Node* root;*/

    /* Resultant tree
                 NULL
        Preorder:   
        Inorder:    
        Postorder:  
    */

    // Tree 3
    /*Node* root = newNode(6);

    Node* node1 = newNode(3);
    root->left = node1;

    Node* node3 = newNode(1);
    node1->left = node3;

    Node* node2 = newNode(7);
    root->right = node2;

    Node* node4 = newNode(10);
    node2->right = node4;*/

    /* Resultant Tree
                  6
                /   \
               3     7
              /       \
             1         10
        Preorder:   6 3 1 7 10
        Inorder:    1 3 6 7 10
        Postorder:  1 3 10 7 6
    */

    // prints the tree in each traversal type before node deletion
    printf("%s\n------------------------------------\n", "Before deletion");
    printf("%s\t", "Preorder traversal: ");
    preOrder(root);
    printf("\n%s\t", "Inorder traversal: ");
    inOrder(root);
    printf("\n%s\t", "Postorder traversal: ");
    postOrder(root);

    // deletes the node of the specified value
    int toDelete = 10; // CHANGE THIS VALUE TO TEST
    
    bool deleted = false; // bool for if the value to be deleted has been deleted from the tree
    bool* deletedPtr = &deleted; // pointer to the bool
    printf("\n\n%s %d\n", "Deleting value:", toDelete); // prints value being deleted
    deleteNode(root, toDelete, deletedPtr); // passes in root, value to delete, and the pointer to bool

    if (deleted)
        printf("%d %s\n", toDelete, "deleted successfully!"); // prints success message if node of given value is deleted
    else
        printf("%d %s\n", toDelete, "does not exist in this tree."); // prints error message if node of given value does not exist

    // prints the tree in each traversal type after node deletion
    printf("\n%s\n------------------------------------\n", "After deletion");
    printf("%s\t", "Preorder traversal: ");
    preOrder(root);
    printf("\n%s\t", "Inorder traversal: ");
    inOrder(root);
    printf("\n%s\t", "Postorder traversal: ");
    postOrder(root);
    puts("");

    /*
        sample test cases
        - using the given tree, change the value to be deleted above to test both deletion and printing traversals
        - feel free to use a different, commented-out tree, but be sure to have only one tree uncommented at a time!
    */
}

int main(void)
{
    hw5p2();
    return 0;
}