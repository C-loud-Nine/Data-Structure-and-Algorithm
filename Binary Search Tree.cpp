#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

void insert(Node** root, int data) {
    Node* new_node = new Node(data);

    if (*root == nullptr) {
        *root = new_node;
        return;
    }

    Node* current = *root;
    while (true) {
        if (data < current->data) {
            if (current->left == nullptr) {
                current->left = new_node;
                return;
            }
            else {
                current = current->left;
            }
        }
        else {
            if (current->right == nullptr) {
                current->right = new_node;
                return;
            }
            else {
                current = current->right;
            }
        }
    }
}

Node* search(Node* root, int data) {
    Node* current = root;
    while (current != nullptr) {
        if (data == current->data) {
            return current;
        }
        else if (data < current->data) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }
    return nullptr;
}

int findMin(Node* root) {
    if (root == nullptr) {
        throw runtime_error("Error: tree is empty");
    }

    Node* current = root;
    while (current->left != nullptr) {
        current = current->left;
    }

    return current->data;
}

int findMax(Node* root) {
    if (root == nullptr) {
        throw runtime_error("Error: tree is empty");
    }

    Node* current = root;
    while (current->right != nullptr) {
        current = current->right;
    }

    return current->data;
}

Node* findMaxNode(Node* node) {
    Node* current = node;
    while (current && current->right != nullptr) {
        current = current->right;
    }
    return current;
}

Node* findMinNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

Node* findSuccessor(Node* root, int data) {
    Node* current = search(root, data);

    if (current == nullptr) {
        return nullptr;
    }

    // Case 1: Node has a right subtree
    if (current->right != nullptr) {
        return findMinNode(current->right);
    }

    // Case 2: Node doesn't have a right subtree
    Node* successor = nullptr;
    Node* ancestor = root;

    while (ancestor != current) {
        if (current->data < ancestor->data) {
            successor = ancestor;
            ancestor = ancestor->left;
        } else {
            ancestor = ancestor->right;
        }
    }

    return successor;
}

Node* findPredecessor(Node* root, int data) {
    Node* current = search(root, data);

    if (current == nullptr) {
        return nullptr;
    }

    // Case 1: Node has a left subtree
    if (current->left != nullptr) {
        return findMaxNode(current->left);
    }

    // Case 2: Node doesn't have a left subtree
    Node* predecessor = nullptr;
    Node* ancestor = root;

    while (ancestor != current) {
        if (current->data > ancestor->data) {
            predecessor = ancestor;
            ancestor = ancestor->right;
        } else {
            ancestor = ancestor->left;
        }
    }

    return predecessor;
}

Node* deleteNode(Node* root, int data) {
    if (root == nullptr) {
        return nullptr;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    else {
        // Case 1: No child or 1 child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 2: 2 children
        Node* minValueNode = findMinNode(root->right);
        root->data = minValueNode->data;
        root->right = deleteNode(root->right, minValueNode->data);
    }

    return root;
}

int height(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight) + 1;
}


void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = nullptr;

    insert(&root, 5);
    insert(&root, 3);
    insert(&root, 7);
    insert(&root, 1);
    insert(&root, 4);

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}
