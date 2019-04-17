#include "function.h"
#include <string>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

void constructMyTree(Node **proot, std::string treeStr){
    if(treeStr[0] == '(' && treeStr[1] == ')')
    {
        *proot = NULL;
        return;
    }
    else
    {
        // Making
        int i, weight = 0;
        string num;
        bool neg = false;
        for(i=1 ; ; i++)
        {
            if(isdigit(treeStr[i]))     num.push_back(treeStr[i]);
            else if(treeStr[i] == '-')  neg = !neg;
            else    break;
        }
        for(int j=0 ; j<num.size() ; j++)
            weight = weight*10 + (num[j] - '0');
        if(neg) weight *= -1;
        *proot = new Node(weight);
        
        // Child
        string leftChild, rightChild;
        int leftNum, rightNum;
        for(i=i, leftNum = 0, rightNum = 0;  ; i++)
        {
            if(treeStr[i] == '(')   leftNum++;
            else if(treeStr[i] == ')')  rightNum++;
            leftChild.push_back(treeStr[i]);
            
            if(leftNum == rightNum) break;
        }
        for(i = i + 1, leftNum = 0, rightNum = 0; ; i++)
        {
            if(treeStr[i] == '(')   leftNum++;
            else if(treeStr[i] == ')')  rightNum++;
            rightChild.push_back(treeStr[i]);
            
            if(leftNum == rightNum) break;
        }
        constructMyTree( &((*proot)->left), leftChild);
        constructMyTree( &((*proot)->right), rightChild);
    }
}

Node* Implement::constructTree(std::string treeStr){
    Node *proot;
    constructMyTree(&proot, treeStr);
    return proot;
}

void Implement::Inorder_traversal(Node *root){
    if (root) {                          // if current != NULL
        Inorder_traversal(root->left);        // L
        std::cout << root->weight << " ";   // V
        Inorder_traversal(root->right);       // R
    }
}

void Implement::Preorder_traversal(Node *root){
    if (root) {                          // if current != NULL
        std::cout << root->weight << " ";   // V
        Preorder_traversal(root->left);       // L
        Preorder_traversal(root->right);      // R
    }
}

void Implement::Postorder_traversal(Node *root){
    if (root) {                         // if current != NULL
        Postorder_traversal(root->left);     // L
        Postorder_traversal(root->right);    // R
        std::cout << root->weight << " ";  // V
    }
}

void Implement::Levelorder_traversal(Node *root){
    if (!root) return;
    std::queue<Node*> q;
    q.push(root);                     // 把root作為level-order traversal之起點
    // 推進queue中
    while (!q.empty()){                     // 若queue不是空的, 表示還有node沒有visiting
        
        Node *current = q.front();      // 取出先進入queue的node
        q.pop();
        std::cout << current->weight << " ";   // 進行visiting
        
        if (current->left != NULL){    // 若leftchild有資料, 將其推進queue
            q.push(current->left);
        }
        if (current->right != NULL){   // 若rightchild有資料, 將其推進queue
            q.push(current->right);
        }
    }
}

void deleteMyTree(Node **proot){
    if(*proot == NULL)  return;
    deleteMyTree( &((*proot)->left));
    deleteMyTree( &((*proot)->right));
    delete *proot;
    *proot = NULL;
}

Node* Implement::deleteTree(Node *root){
    if(root == NULL) return root;
    deleteMyTree(&root);
    return root;
}

int Implement::TreeHeight( Node *root){
    if(root == NULL)    return 0;
    return 1 + max(TreeHeight(root->left), TreeHeight(root->right));
}

int Implement::TreeWeightSum( Node *root){
    if(root == NULL)    return 0;
    return root->weight + TreeWeightSum(root->left) + TreeWeightSum(root->right);
}

void sumOfLongRootToLeafPath(Node* root, int sum,
                             int len, int& maxLen, int& maxSum)
{
    // if true, then we have traversed a
    // root to leaf path
    if (!root) {
        // update maximum length and maximum sum
        // according to the given conditions
        if (maxLen < len) {
            maxLen = len;
            maxSum = sum;
        } else if (maxLen == len && maxSum < sum)
            maxSum = sum;
        return;
    }
    
    // recur for left subtree
    sumOfLongRootToLeafPath(root->left, sum + root->weight,
                            len + 1, maxLen, maxSum);
    
    // recur for right subtree
    sumOfLongRootToLeafPath(root->right, sum + root->weight,
                            len + 1, maxLen, maxSum);
}

int Implement::MaximumPathSum(Node *root){
    if (!root)
        return 0;
    
    int maxSum = -99999, maxLen = 0;
    
    // finding the maximum sum 'maxSum' for the
    // maximum length root to leaf path
    sumOfLongRootToLeafPath(root, 0, 0, maxLen, maxSum);
    
    // required maximum sum
    return maxSum;
}

Node* Implement::Invert(Node *root){
    if (!root) return NULL;
    Node *tmp = root->left;
    root->left = Invert(root->right);
    root->right = Invert(tmp);
    return root;
}

