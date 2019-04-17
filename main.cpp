#include <iostream>
#include "function.h"

using namespace std;

int main()
{
    Implement inst = *(new Implement());
    string command;
    Node *root;
    string treeStr = "";
    while(cin>>treeStr){
        root = NULL;
        root = inst.constructTree(treeStr);
        inst.Inorder_traversal(root);
        cout<<endl;
        inst.Preorder_traversal(root);
        cout<<endl;
        inst.Postorder_traversal(root);
        cout<<endl;
        inst.Levelorder_traversal(root);
        cout<<endl;
        cout<<inst.TreeHeight(root)<<endl;
        cout<<inst.TreeWeightSum(root)<<endl;
        cout<<inst.MaximumPathSum(root)<<endl;
        inst.Invert(root);
        inst.Inorder_traversal(root);
        cout<<endl;
        inst.Preorder_traversal(root);
        cout<<endl;
        inst.Postorder_traversal(root);
        cout<<endl;
        inst.Levelorder_traversal(root);
        root = inst.deleteTree(root);
    }


    return 0;
}
