#include <iostream>
#include <string>

struct Node
{
    std::string m_name;
    int m_crabs = 0;
    int m_traps = 0;
    Node *next = nullptr;
    Node() = default;
    Node(std::string name, int crabs, int traps) : m_name(name), m_crabs(crabs), m_traps(traps) {}

    Node &operator=(int val)
    {
        m_crabs = val;
        return *this;
    }

    Node &operator=(std::string val)
    {
        m_name = val;
        return *this;
    }
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void insert(const std::string &name, const int crabs, const int traps)
    {
        Node *newNode = new Node(name, crabs, traps);
        newNode->next = head;
        head = newNode;
    }

    void printList()
    {
        Node *temp = head;
        while (temp)
        {
            std::cout << temp->m_name << " " << temp->m_crabs << " " << temp->m_traps << '\n';
            temp = temp->next;
        }
    }

    void deleteHead()
    {
        delete head;
    }

    Node *getNodeAtIndex(int index)
    {
        Node *temp = head;
        for (int i = 0; i < index; i++)
        {
            if (!temp)
                return NULL;
            temp = temp->next;
        }
        return temp;
    }
};

void solve(LinkedList &results, Node *crabsTotal, int n)
{
    for (int i = 0; i < n; i++)
    {
        crabsTotal[results.getNodeAtIndex(i)->m_crabs].m_name = results.getNodeAtIndex(i)->m_name;
        crabsTotal[results.getNodeAtIndex(i)->m_crabs].m_crabs = results.getNodeAtIndex(i)->m_crabs;
    }
}

void printNames(Node *crabsTotal, const int N = 100)
{
    for (int i = N - 1; i >= 0; i--)
    {
        if(crabsTotal[i].m_name != "")
            std::cout << crabsTotal[i].m_name << ' ';
    }
    std::cout << '\n';
}

void getInput(LinkedList &results, int n)
{
    std::string name;
    int crab, trap;
    for (int i = 0; i < n; i++)
    {
        std::cin >> name >> crab >> trap;
        results.insert(name, crab, trap);
    }
}

void freeMemory(std::string *names, int *crabs, int *traps)
{
    delete[] names;
    delete[] crabs;
    delete[] traps;
}

int main()
{
    int n;
    std::cin >> n;

    std::string *names = new std::string[n];

    const int totalCrabsNumber = 100;
    const int totalTrapsNumber = 9;

    int *crabs = new int[n];
    int *traps = new int[n];
    LinkedList results;

    Node crabsTotal[totalCrabsNumber]{};

    int possibilitiesTotal[totalCrabsNumber * totalTrapsNumber];

    getInput(results, n);
    results.printList();
    printNames(crabsTotal);
    

    results.deleteHead();
    freeMemory(names, crabs, traps);
}