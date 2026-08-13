
#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

    int height(Node* root){
        if(root == nullptr)
            return -1;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return max(leftHeight, rightHeight) + 1;
    }

int main(){
    Node* root = new Node(100);

    root -> left = new Node(200);
    root -> right = new Node(300);
 
    root -> left -> left = new Node(400);
    root -> left -> right = new Node(500);

    root -> right -> left = new Node(600); 
    root -> right -> right = new Node(700);

    root ->left ->left ->left = new Node(800);

    Node* root1= new Node(10);

    root1 -> left = new Node(20);
    root1 -> right = new Node(30);

    root1 -> left -> left = new Node(40);
    root1 -> left -> right = new Node(50);

    Node* root2 = new Node(10);

    root2 -> left = new Node(20);
    root2 -> right = new Node(30);

    root2 -> left -> left = new Node(40);
    root2 -> left -> right = new Node(50);

    cout<<"height of Tree: "<<height(root);
    cout<<endl;

    return 0;
}