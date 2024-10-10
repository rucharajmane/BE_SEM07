#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct Node
{
    int val;
    char symbol;
    string huffman;
    Node *left;
    Node *right;

    Node(int v, char s) : val(v), symbol(s), huffman(""), left(nullptr), right(nullptr) {}

    bool operator<(const Node &next) const
    {
        return val > next.val; 
    }
};

void printNodes(Node *node, string val = "")
{
    string newVal = val + node->huffman;

    if (node->left)
    {
        printNodes(node->left, newVal);
    }

    if (node->right)
    {
        printNodes(node->right, newVal);
    }

    if (!node->left && !node->right)
    {
        cout << node->symbol << " -> " << newVal << endl;
    }
}

int main()
{
    vector<char> charList = {'a', 'b', 'c', 'd', 'e'};
    vector<int> freq = {100, 12, 24, 105, 38};

    priority_queue<Node> nodes;

    for (int i = 0; i < charList.size(); i++)
    {
        nodes.push(Node(freq[i], charList[i]));
    }

    while (nodes.size() > 1)
    {
        Node left = nodes.top();
        nodes.pop();
        Node right = nodes.top();
        nodes.pop();

        left.huffman = "0";
        right.huffman = "1";

        Node newNode(left.val + right.val, '\0'); 
        newNode.left = new Node(left);
        newNode.right = new Node(right);

        nodes.push(newNode);
    }

    Node *root = new Node(nodes.top());

    printNodes(root);

    delete root;

    return 0;
}
