#include <bits/stdc++.h>
using namespace std;

struct MinHeapNode
{
    char d;
    unsigned frequency;
    MinHeapNode *lChild, *rChild;

    MinHeapNode(char d, unsigned frequency)

    {

        lChild = rChild = NULL;
        this->d = d;
        this->frequency = frequency;
    }
};

// function to compare
struct compare
{
    bool operator()(MinHeapNode *l, MinHeapNode *r)
    {
        return (l->frequency > r->frequency);
    }
};

void printCodes(struct MinHeapNode *root, string str)
{
    if (!root)
        return;

    if (root->d != '$')
        cout << root->d << ": " << str << "\n";

    printCodes(root->lChild, str + "0");
    printCodes(root->rChild, str + "1");
}

void HuffmanCodes(char d[], int frequency[], int size)
{
    struct MinHeapNode *lChild, *rChild, *top;

    priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> minHeap;

    for (int i = 0; i < size; i++)
        minHeap.push(new MinHeapNode(d[i], frequency[i]));

    while (minHeap.size() != 1)
    {
        lChild = minHeap.top();
        minHeap.pop();

        rChild = minHeap.top();
        minHeap.pop();

        top = new MinHeapNode('$', lChild->frequency + rChild->frequency);

        top->lChild = lChild;
        top->rChild = rChild;

        minHeap.push(top);
    }
    printCodes(minHeap.top(), " ");
}

int main()
{
    int num;
    cout<<"\t\tHUFFMAN CODE\t\t"<<endl;
    
    cout << "Enter the number of characters : "<< " ";
    cin >> num;
    char A[num];
    int X[num];
    cout << "Enter the characters : ";
    for (int i = 0; i < num; i++)
    {
        
        cin >> A[i];
    }
    cout << "Enter the associated value : ";
    for (int i = 0; i < num; i++)
    {
       
        cin >> X[i];
    }

    int size = sizeof(A) / sizeof(A[0]);
    cout<<"\n\n";
    HuffmanCodes(A, X, size);

    return 0;
}