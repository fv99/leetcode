/*

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Example 2:

Input: root = [1]
Output: [[1]]

Example 3:

Input: root = []
Output: []

Constraints:

    The number of nodes in the tree is in the range [0, 2000].
    -1000 <= Node.val <= 1000
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    if (!root) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    struct TreeNode *queue[1001];
    *returnSize = 0;

    int head = 0;
    int tail = 0;

    int **ret_arr = malloc(sizeof *ret_arr * 2000);
    *returnColumnSizes = malloc(sizeof(int) * 2000);

    queue[tail++] = root;
    // tail - head % 1001 gives us size of queue
    while ((tail - head) % 1001)
    {
        int size = (*returnColumnSizes)[*returnSize] = (tail - head) % 1001;

        ret_arr[*returnSize] = malloc(sizeof **ret_arr * size);
        for (int i = 0; i < size; i++)
        {
            // circular buffer - if we reach position 1001, % 1001 will set index to 0 again
            struct TreeNode *branch = queue[head++ % 1001];
            ret_arr[*returnSize][i] = branch->val;
            if (branch->left)
                queue[tail++ % 1001] = branch->left;
            if (branch->right)
                queue[tail++ % 1001] = branch->right;
        }
        (*returnSize)++;
    }
    return ret_arr;
}
