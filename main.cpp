#include <iostream>

using namespace std;

class Node
{
public:

    int    iData; //key
    double dData;
    Node* leftChild;
    Node* rightChild;

    void displayNode()
    {
        cout << "{ " << iData  << "," <<  dData << "}" << endl;
    }

};

class Tree
{
private:
    Node* root;

    void inOrder(Node* localRoot)
    {
        if (localRoot != nullptr)
        {
            inOrder(localRoot->leftChild);

            cout << localRoot->iData;
            inOrder(localRoot->rightChild);
        }
    }

public:
    Tree()
    {
        root = nullptr;
    }

    Node* finde(int key)
    {
        Node* current = root;
        while(current->iData != key)
        {
            if (current->iData < key)
                current = current->leftChild;
            else
                current = current->rightChild;
            if (current == nullptr)
                return nullptr;
        }
        return current;
    }

    void insert(int key ,double dData)
    {
        Node* newNode = new Node;
        newNode->iData = key;
        newNode->dData = dData;
        if (root == nullptr)
        {
            root = newNode;
            return;
        }
        else
        {
            Node* current;
            Node* parent;
            current = root;
            while (true)
            {
                parent = current;
                if (key < current->iData)
                {
                    current = current->leftChild;
                    if (current == nullptr)
                    {
                        parent->leftChild = newNode;
                        return;
                    }
                }
                else
                {
                    current = current->rightChild;
                    if (current == nullptr)
                    {
                        parent->rightChild = newNode;
                        return;
                    }
                }
            }
        }
    }








};

int main() {


    return 0;
}