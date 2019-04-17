#ifndef FUNCTION_H
#define FUNCTION_H

#include<string>

class Node
{
public:
    int weight;
    Node *left, *right;
    Node():weight(0),left(NULL),right(NULL){}
    Node(int d):weight(d),left(NULL),right(NULL){}
    Node(int d , Node *left_ , Node *right_){
        weight = d;
        left = left_;
        right = right_;
    }
};

class BinaryTree
{
public:

virtual Node* constructTree( std::string treeStr) = 0;

virtual void Inorder_traversal(Node *root) = 0;

virtual void Preorder_traversal(Node *root) = 0;

virtual void Postorder_traversal(Node *root) = 0;

virtual void Levelorder_traversal(Node *root) = 0;

virtual Node* deleteTree(Node *root) = 0;

virtual int TreeHeight( Node *root) = 0;

virtual int TreeWeightSum( Node *root) = 0;

virtual int MaximumPathSum( Node *root) = 0;

virtual Node* Invert(Node *root) = 0;

};

class Implement: public BinaryTree
{
public:
    Node* constructTree(std::string treeStr) ;

    void Inorder_traversal(Node *root);

    void Preorder_traversal(Node *root) ;

    void Postorder_traversal(Node *root) ;

    void Levelorder_traversal(Node *root);

    Node* deleteTree(Node *root) ;

    int TreeHeight( Node *root) ;

    int TreeWeightSum( Node *root) ;

    int MaximumPathSum(Node *root);

    Node* Invert(Node *root) ;


};





#endif
