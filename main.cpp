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

            cout << localRoot->iData << " ";
            inOrder(localRoot->rightChild);
        }
    } //симметричный обход

    void preOrder(Node* localRoot)
    {
        if(localRoot != nullptr)
        {
            cout << localRoot->iData << " ";
            preOrder(localRoot->leftChild);

            preOrder(localRoot->rightChild);

        }
    } //прямой обход

    void revOrder(Node* localRoot)
    {
        if(localRoot != nullptr)
        {
            revOrder(localRoot->leftChild);

            revOrder(localRoot->rightChild);

            cout << localRoot->iData << " ";
        }
    } //обратный обход

    void deleteNode(Node* current)
    {
        current->rightChild = nullptr;
        current->leftChild = nullptr;
        delete current;
    }

public:
    Tree()
    {
        root = nullptr;
    }

    Node* find(int key)
    {
        Node* current = root;
        while(current->iData != key)
        {
            if (current->iData > key)
                current = current->leftChild;
            else
                current = current->rightChild;
            if (current == nullptr)
            {
                cout << "not find for delete wint key " << key << endl;
                return nullptr;
            }
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

    Node* minimum()
    {
        Node* current = root;
        Node* last;
        while (current != nullptr)
        {
            last = current;
            current = current->leftChild;
        }
        return last;
    }

    Node* maximum()
    {
        Node* current = root;
        Node* last;
        while(current != nullptr)
        {
            last = current;
            current = current->rightChild;
        }
        return last;
    }

    bool Delete(int key)
    {
        Node* current = root;
        Node* parent = root;
        bool isList;
        bool isOneParent;
        bool isTwoParent;

        while(current->iData != key)
        {
            parent = current;
            if(key < current->iData)
                current = current->leftChild;
            else
                current = current->rightChild;
            if (current == nullptr)
            {
                cout << "not find for delete with key " << key << endl;
                return false;
            }
        }

        if(current == root)
        {
            root = nullptr;
            return true;
        }

        if(current->leftChild == nullptr && current->rightChild == nullptr)
        {
            isList = true;
            isOneParent = false;
            isTwoParent = false;
        }

        if((current->leftChild != nullptr && current->rightChild == nullptr) ||
        (current->leftChild == nullptr && current->rightChild != nullptr))
        {
            isList = false;
            isOneParent = true;
            isTwoParent = false;
        }

        if(current->leftChild != nullptr && current->rightChild != nullptr)
        {
            isList = false;
            isOneParent = false;
            isTwoParent = true;
        }

        if(isList == true)
        {
            if(parent->leftChild == current)
            {
                parent->leftChild = nullptr;
                deleteNode(current);
                return true;
            }
            else
            {
                parent->rightChild = nullptr;
                deleteNode(current);
                return true;
            }
        }

        if (isOneParent == true)
        {}

        if (isTwoParent == true)
        {}
        
    }














};

int main() {

    Tree theTree;

    theTree.insert(0, 12.12);
    theTree.insert(6, 66.66);
    theTree.insert(2, 54.54);
    theTree.insert(3, 27.27);
    theTree.insert(1, 90.9);
    theTree.insert(10, 18.18);
    theTree.insert(5, 50.5);




    return 0;
}