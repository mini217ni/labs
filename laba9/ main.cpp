#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>
using namespace std;


template <typename T>
class SplayTree {
private:
    struct Node {
        T key;
        Node* left;
        Node* right;
        Node(const T& k) : key(k), left(nullptr), right(nullptr) {}
    };
    Node* root = nullptr;


    void rotateRight(Node*& y) {
        Node* x = y->left;
        y->left = x->right;
        x->right = y;
        y = x;
    }
    void rotateLeft(Node*& x) {
        Node* y = x->right;
        x->right = y->left;
        y->left = x;
        x = y;
    }

    void splay(Node*& root, const T& key) {
        if (!root || root->key == key) return;

        if (key < root->key) {
            if (!root->left) return;
            if (key < root->left->key) {
                splay(root->left->left, key);
                rotateRight(root);
            } else if (key > root->left->key) {
                splay(root->left->right, key);
                if (root->left->right)
                    rotateLeft(root->left);
            }
            if (root->left)
                rotateRight(root);
        } else {
            if (!root->right) return;
            if (key > root->right->key) {
                splay(root->right->right, key);
                rotateLeft(root);
            } else if (key < root->right->key) {
                splay(root->right->left, key);
                if (root->right->left)
                    rotateRight(root->right);
            }
            if (root->right)
                rotateLeft(root);
        }
    }

    void clear(Node* node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

    void toString(Node* node, ostringstream& os) const {
        if (!node) return;
        toString(node->left, os);
        os << node->key << " ";
        toString(node->right, os);
    }

    void insert(Node*& root, const T& key) {
        if (!root) {
            root = new Node(key);
            return;
        }

        splay(root, key);
        if (key == root->key) return;
        Node* newNode = new Node(key);

        if (key < root->key) {
            newNode->right = root;
            newNode->left = root->left;
            root->left = nullptr;
        } else {
            newNode->left = root;
            newNode->right = root->right;
            root->right = nullptr;
        }

        root = newNode;
    }

    Node* remove(Node*& root, const T& key) {
        if (!root) return nullptr;
        splay(root, key);
        if (key != root->key) return root;

        Node* temp;
        if (!root->left) {
            temp = root;
            root = root->right;
        } else {
            temp = root;
            splay(root->left, key);
            root->left->right = root->right;
            root = root->left;
        }
        delete temp;
        return root;
    }

public:
    ~SplayTree() { clear(root); }

    void insert(const T& key) { insert(root, key); }
    void remove(const T& key) { root = remove(root, key); }

    bool find(const T& key) {
        splay(root, key);
        return root && root->key == key;
    }

    void clear() {
        clear(root);
        root = nullptr;
    }

    string toString() const {
        ostringstream os;
        toString(root, os);
        return os.str();
    }

    friend ostream& operator<<(ostream& os, const SplayTree<T>& tree) {
        os << tree.toString();
        return os;
    }

    friend istream& operator>>(istream& is, SplayTree<T>& tree) {
        tree.clear();
        T value;
        while (is >> value)
            tree.insert(value);
        return is;
    }
};





// пример использования
int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    SplayTree<int> tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(20);
    tree.insert(15);

    cout << "Дерево: " << tree << endl;

    cout << "Поиск 5: " << (tree.find(5) ? "найден" : "не найден") << endl;

    tree.remove(10);
    cout << "После удаления 10: " << tree << endl;
    return 0;
}
