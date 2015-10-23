#include <stdio.h>
#include <stdlib.h>

#define MAX_ARR 100

typedef struct TreeNode {
    int content;
    struct TreeNode *right;
    struct TreeNode *left;
} treenode;

treenode *binary_tree();
treenode *flatten(treenode *root);

int main()
{
    int i=1;
    treenode *root;
    root = binary_tree();
    flatten(root);
    while(root->right != NULL) {
        printf("%d ", root->content);
        root = root->right;
        i++;
    }
    printf("\n%d\n", i);
    return 0;
}


treenode *flatten(treenode *root)
{
    if(root == NULL)
        return NULL;
    treenode *o_root;
    o_root = root;
    treenode *right_most;
    right_most = root;
    while(1) {
        while(right_most->right != NULL) {
            right_most = right_most->right;
        }
        right_most->right = root->left;
        root->left = NULL;
        root = root->right;
        if(root == right_most && right_most->left == NULL)
            break;
    }
    return o_root;
}

treenode *binary_tree()
{
    int array[MAX_ARR];
    int i;
    FILE *fp = fopen("test.txt", "r+");
    treenode *root;
    treenode *next;
    treenode *r_root;
    for(i = 0; i < MAX_ARR; i++) {
        fscanf(fp, "%d", &array[i]);
    }
    root = (treenode *) malloc(sizeof(treenode));
    root->right = NULL;
    root->left = NULL;
    next = (treenode *) malloc(sizeof(treenode));
    next->right = NULL;
    next->left = NULL;
    root->content = array[0];
    r_root = root;
    for(i = 1; i < MAX_ARR; i++ ) {
        next = (treenode *) malloc(sizeof(treenode));
        next->right = NULL;
        next->left = NULL;
        next->content = array[i];
        while(1) {
            if(array[i] >= root->content) {
                if(root->right == NULL) {
                    root->right = next;
                    next = NULL;
                    break;
                } else {
                    root = root->right;
                }
            } else if(array[i] < root->content) {
                if(root->left == NULL) {
                    root->left = next;
                    next = NULL;
                    break;
                } else {
                    root = root->left;
                }
            }
        }
        root = r_root;
    }
    return r_root;
}
