#include <iostream>
#include <string>

struct Node {
    std::string data;
    int counter = 0;
    Node *left{};
    Node *right{};
};

class BinaryTree {
private:
    Node *root;

public:
    BinaryTree() {
        root = nullptr;
    }

    void add(Node *&node, const std::string &data);

    Node *&getRoot();
};

Node *&BinaryTree::getRoot() {
    return root;
}

void BinaryTree::add(Node *&node, const std::string &data) {
    if (!node) {
        Node *newNode = new Node;
        newNode->left = newNode->right = nullptr;
        newNode->data = data;
        node = newNode;
        return;
    }
    if (data < node->data) {
        add(node->left, data);
    } else if (data > node->data) {
        add(node->right, data);
    } else {
        node->counter++;
    }
}

void print(Node *node) {
    if (node) {
        print(node->left);
        for (int i = 0; i < node->counter; i++) {
            std::cout << node->data << '\n';
        }
        std::cout << node->data << '\n';

        print(node->right);
    }
}

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n;
    std::string data;

    std::cin >> n;

    BinaryTree binaryTree;

    for (int i = 0; i < n; i++) {
        std::cin >> data;
        binaryTree.add(binaryTree.getRoot(), data);
    }
    print(binaryTree.getRoot());

    return 0;
}