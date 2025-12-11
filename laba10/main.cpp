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
        explicit Node(const T& k): key(k), left(nullptr), right(nullptr) {}
    };
    Node* root = nullptr;



    // поворот вправо
    void rotateRight(Node*& y) {
        auto x = y->left;
        y->left = x->right;
        x->right = y;
        y = x;
    }

    // поворот влево
    void rotateLeft(Node*& x) {
        auto y = x->right;
        x->right = y->left;
        y->left = x;
        x = y;
    }

    // основная операция Splay
    void splay(Node*& root, const T& key) {
        if (!root || root->key == key) return;

        if (key < root->key) {
            if (!root->left) return;
            // левый левый случай (zig-zig)
            if (key < root->left->key) {
                splay(root->left->left, key);
                rotateRight(root);
            }
            // левый правый случай (zig-zag)
            else if (key > root->left->key) {
                splay(root->left->right, key);
                if (root->left->right)
                    rotateLeft(root->left);
            }
            if (root->left) rotateRight(root);

        } else {
            if (!root->right) return;
            // Правый правый случай (Zag-Zag)
            if (key > root->right->key) {
                splay(root->right->right, key);
                rotateLeft(root);
            }
            // Правый левый случай (Zag-Zig)
            else if (key < root->right->key) {
                splay(root->right->left, key);
                if (root->right->left)
                    rotateRight(root->right);
            }
            if (root->right) rotateLeft(root);
            
        }
    }

    // очистка 
    void clear(Node* node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

    // представление дерева в строке
    void toString(const Node* node, ostringstream& os) const {
        if (!node) return;
        toString(node->left, os);
        os << node->key << " ";
        toString(node->right, os);
    }

    // вставка нового элемента
    void insert(Node*& root, const T& key) {
        if (!root) {
            root = new Node(key);
            return;
        }

        splay(root, key);
        if (key == root->key) return;
        auto newNode = new Node(key);

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

    // удаление элемента
    auto remove(Node*& root, const T& key) -> Node* {
        if (!root) return nullptr;
        splay(root, key);
        if (key != root->key) return root;
        auto temp = root;

        if (!root->left) root = root->right;
        else {
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
        while (is >> value) tree.insert(value);
        return is;
    }
};





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


