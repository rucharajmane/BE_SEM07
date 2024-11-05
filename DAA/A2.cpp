#include <bits/stdc++.h>

using namespace std;

class MinHeapNode
{
public:
    char data;
    int freq;
    MinHeapNode *left;
    MinHeapNode *right;

    MinHeapNode(char data, int freq)
    {
        this->data = data;
        this->freq = freq;
        left = right = nullptr;
    }
};

class HuffmanCoding
{
public:
    void printCodes(MinHeapNode *root, string str)
    {
        if (root == nullptr)
        {
            return;
        }
        if (root->data != '$')
        {
            cout << root->data << ": " << str << endl;
        }
        printCodes(root->left, str + "0");
        printCodes(root->right, str + "1");
    }

    void createHuffmanCode(char data[], int freq[], int size)
    {
        MinHeapNode *left, *right, *temp;

        priority_queue<MinHeapNode *, vector<MinHeapNode *>, Compare> minHeap;

        for (int i = 0; i < size; i++)
        {
            minHeap.push(new MinHeapNode(data[i], freq[i]));
        }

        while (minHeap.size() != 1)
        {
            left = minHeap.top();
            minHeap.pop();
            right = minHeap.top();
            minHeap.pop();

            temp = new MinHeapNode('$', left->freq + right->freq);
            temp->left = left;
            temp->right = right;

            minHeap.push(temp);
        }
        printCodes(minHeap.top(), "");
    }

private:
    class Compare
    {
    public:
        bool operator()(MinHeapNode *a, MinHeapNode *b)
        {
            return (a->freq > b->freq);
        }
    };
};

int main()
{
    char data[] = {'A', 'B', 'C', 'D'};
    int freq[] = {23, 12, 34, 10};

    HuffmanCoding huffman;
    huffman.createHuffmanCode(data, freq, 4);

    return 0;
}

/*
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
*/