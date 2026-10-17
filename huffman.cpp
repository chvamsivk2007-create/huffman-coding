#include <iostream>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
};

Node* createNode(char ch, int freq) {
    Node *n = new Node;
    n->ch = ch;
    n->freq = freq;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void sortNodes(Node* arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j]->freq > arr[j + 1]->freq) {
                Node* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void generateCodes(Node* root, char code[], int top) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL) {
        if (top == 0)
            cout << root->ch << " : 0" << endl;
        else {
            cout << root->ch << " : ";
            for (int i = 0; i < top; i++)
                cout << code[i];
            cout << endl;
        }
        return;
    }

    code[top] = '0';
    generateCodes(root->left, code, top + 1);

    code[top] = '1';
    generateCodes(root->right, code, top + 1);
}

void huffman(char chars[], int freq[], int n) {
    Node* arr[100];

    for (int i = 0; i < n; i++)
        arr[i] = createNode(chars[i], freq[i]);

    int size = n;

    while (size > 1) {
        sortNodes(arr, size);

        Node* left = arr[0];
        Node* right = arr[1];

        Node* parent = createNode('\0', left->freq + right->freq);

        parent->left = left;
        parent->right = right;

        for (int i = 2; i < size; i++)
            arr[i - 2] = arr[i];

        size -= 2;
        arr[size] = parent;
        size++;
    }

    char code[100];

    cout << "Character : Huffman Code" << endl;
    generateCodes(arr[0], code, 0);
}

int main() {
    char chars[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int n = 6;

    huffman(chars, freq, n);

    return 0;
}
