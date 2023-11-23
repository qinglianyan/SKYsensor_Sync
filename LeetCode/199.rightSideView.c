#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool queEmpty(struct TreeNode ** queue, int * queTop, int *queEnd){
    return (*queTop)==(*queEnd);
}
void pushQue(struct TreeNode ** queue, int * queTop, int *queEnd, struct TreeNode * in){
    if((*queEnd)>=100){
        printf("push Error\n");
    }
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rightSideView(struct TreeNode* root, int* returnSize) {
    struct TreeNode ** queue=(struct TreeNode **)malloc(sizeof(struct TreeNode *)*100);
    int queTop=0, queEnd=0;
    int *out=(int *)malloc(sizeof(int)*100);

}

int main(){
    int i, j;
    int * out;
    int *returnSize=(int *)malloc(sizeof(int));
    struct TreeNode *node1, *node2, *node3, *node4, *node5, *root;
    node1=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node2=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node3=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node4=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node5=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node1->val=1;node1->left=node2;node1->right=node3;
    node2->val=2;node2->left=NULL;node2->right=node5;
    node3->val=3;node3->left=NULL;node3->right=node4;
    node4->val=4;node4->left=NULL;node4->right=NULL;
    node5->val=5;node5->left=NULL;node5->right=NULL;
    root=node1;
    out=rightSideView(root, returnSize);
    for(i=0;i<*returnSize;i++){
        printf("%d ", out[i]);
    }printf("\n");
    return 0;
}