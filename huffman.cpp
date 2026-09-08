#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

struct Node
{
    char ch;
    int freq;
    Node *left;
    Node *right;
};

Node* createNode(char ch, int freq)
{
    Node* newNode = new Node();

    newNode->ch = ch;
    newNode->freq = freq;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void printCodes(Node* root, string code)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        cout << root->ch << " : " << code << endl;
        return;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main()
{
    // Create nodes
    Node* A = createNode('A', 5);
    Node* B = createNode('B', 9);
    Node* C = createNode('C', 12);
    Node* D = createNode('D', 13);
    Node* E = createNode('E', 16);

    // Create Huffman tree manually
    Node* AB = createNode('*', 14);
    AB->left = A;
    AB->right = B;

    Node* CD = createNode('*', 25);
    CD->left = C;
    CD->right = D;

    Node* ABCD = createNode('*', 39);
    ABCD->left = AB;
    ABCD->right = CD;

    Node* root = createNode('*', 55);
    root->left = ABCD;
    root->right = E;

    // Print codes
    cout << "Huffman Codes:" << endl;
    printCodes(root, "");

    /*
       Expected Output:

       Huffman Codes:
       A : 000
       B : 001
       C : 010
       D : 011
       E : 1

       Time Complexity: O(n)
       Space Complexity: O(n)
    */

    return 0;
}