// Traversal of nodes of TREE (all types of Traversal)
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

    void inorder(Node* root){
        if(root == nullptr)
            return;

        inorder(root -> left);
        cout << root -> data <<" ";
        inorder(root -> right);
    }

    void preorder(Node* root){
        if(root == nullptr)
            return;

        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node* root){
        if(root == nullptr)
            return;

        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }

    int height(Node* root){
        if(root == nullptr)
            return -1;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return max(leftHeight, rightHeight) + 1;
    }

    void levelorder(Node* root){

        if(root == nullptr)
            return;
        
        queue<Node*> q;
        q.push(root);

        while (!q.empty())
        {
            Node* current = q.front();
            q.pop();

            cout<<current -> data<<" ";

            if(current->left != nullptr)
                q.push(current->left);

            if(current->right != nullptr)
                q.push(current->right);
        }
    }

    int countNodes(Node* root){
        if (root==nullptr){
            return 0;
        }

        int leftNodes = countNodes(root->left);
        int rightNodes = countNodes(root->right);

        return leftNodes + rightNodes +1;
    }

    int sumNodes(Node* root){
        if (root==nullptr){
            return 0;
        }

        int leftsum = sumNodes(root->left);
        int rightsum = sumNodes(root->right);
        
        return leftsum + rightsum + root->data;
    }

    int countLeafNode(Node* root){
        if(root == nullptr){
            return 0;
        }
        if(root->left==nullptr && root->right==nullptr){
            return 1;
        }
        int left = countLeafNode(root->left);
        int right = countLeafNode(root->right);

        return left + right;
    }

    int countNonLeafNode(Node* root){
        if(root == nullptr){
            return 0;
        }
        if(root->left==nullptr && root->right==nullptr){
            return 0;
        }

        int left = countNonLeafNode(root->left);
        int right = countNonLeafNode(root->right);

        return left + right + 1;
    }

    int countSingleChildNode(Node* root){
        if(root == nullptr){
            return 0;
        }

        int left = countSingleChildNode(root->left);
        int right = countSingleChildNode(root->right);

        if((root->left != nullptr && root->right == nullptr) || (root->left == nullptr && root->right != nullptr)){
            return left + right + 1;
        }

        return left + right;
    }

    int diameter(Node* root, int &dia){
        if(root == nullptr){
            return -1;
        }

        int leftHeight = diameter(root->left, dia);
        int rightHeight = diameter(root->right, dia);

        dia = max(dia, leftHeight + rightHeight + 2);

        return 1 + max(leftHeight, rightHeight);
    }

    int isBalanced(Node* root, bool &balanced){
        if(root == nullptr){
            return -1;
        }

        int leftHeight = isBalanced(root->left, balanced);
        int rightHeight = isBalanced(root->right, balanced);

        if(abs(leftHeight - rightHeight) > 1){
            balanced = false;
        }

        return 1 + max(leftHeight, rightHeight);
    }

    bool identical(Node* root1, Node* root2){
        if (root1 == nullptr && root2 == nullptr){
            return true;
        }
        else if ((root1 == nullptr && root2 != nullptr) || (root1 != nullptr && root2 == nullptr)){
            return false;
        }
        
        bool left = identical(root1->left, root2->left);
        bool right = identical(root1->right, root2->right);

        return (root1->data == root2->data) && left && right;
    }

    void mirror(Node* root){
        if(root == nullptr)
            return;

        swap(root->left, root->right);

        mirror(root->left);
        mirror(root->right);
    }

    Node* lca(Node* root, Node* p, Node* q){
        if(root == nullptr)
            return nullptr;

        if(root == p || root == q)
            return root;

        Node* left = lca(root->left, p, q);
        Node* right = lca(root->right, p, q);

        if(left != nullptr && right != nullptr)
            return root;

        if(left != nullptr)
            return left;

        return right;

    }

    // int diameter(Node* root){
    //     if(root == nullptr)
    //         return 0;

    //     int leftHeight = height(root->left);
    //     int rightHeight = height(root->right);

    //     int currentDiameter = leftHeight + rightHeight + 2;

    //     int leftDiameter = diameter(root->left);
    //     int rightDiameter = diameter(root->right);

    //     return max(currentDiameter,
    //            max(leftDiameter, roightDiameter));
    // }

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

    cout<<"Before Mirroring the Tree: "<<endl;
 
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    levelorder(root);
    cout<<endl;

    cout<<endl<<height(root)<<endl;
    cout<<countNodes(root)<<endl;
    cout<<sumNodes(root)<<endl;
    cout<<sumNodes(root)<<endl;
    cout<<"No. of Leaf Nodes are "<<countLeafNode(root)<<endl;
    cout<<"No. of Non-Leaf Nodes are "<<countNonLeafNode(root)<<endl;
    cout<<"No. of Single Child Nodes is/are "<<countSingleChildNode(root)<<endl;

    int dia = 0;
    diameter(root, dia);
    cout<<"Diameter is "<<dia<<endl;

    bool balanced = true;
    isBalanced(root, balanced);
    cout<<balanced<<endl;

    cout<<identical(root1, root2)<<endl;

    cout<<"After Mirroring the Tree: "<<endl;

    mirror(root);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    levelorder(root);
    cout<<endl;

    return 0;
}



// 🌟 This is the Recursive Template
// Almost every Binary Tree recursive problem follows this pattern:
// ReturnType function(Node* root){

//     if(root == nullptr)
//         return BASE_VALUE;

//     auto left = function(root->left);
//     auto right = function(root->right);

//     return COMBINE(left, right, root);
// }

