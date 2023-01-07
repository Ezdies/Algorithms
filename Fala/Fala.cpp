#include <iostream>

struct Node {
    int data;
    bool isLeft;
    Node *prev;
    Node *next;

    Node() {
        prev = this;
        next = this;
    }

    Node(int data, bool isLeft) {
        prev = this;
        next = this;
        this->data = data;
        this->isLeft = isLeft;
    }
};

class DoublyLinkedList {
private:
    Node *curr;
    int size;

public:
    DoublyLinkedList() {
        curr = nullptr;
        size = 0;
    }

    Node *getCurr();

    void add(int data, bool isLeft);

    int getSize() const;

    void setStartingCurrNode(int moveStep, bool isMovingBackWards);

    void setNewCurrNode(int numberOfMoves, bool isTurningOpposite);

    void deleteCurrentHead();

    void setCurr(Node *node);
};

void DoublyLinkedList::deleteCurrentHead() {
//    if (!curr) return;
//    Node *tmp = curr;
//    curr = curr->next;
//    curr->prev = tmp->prev;
//    tmp->prev->next = curr;
//    delete tmp;

//    Node *tmp = curr;
//    if (!curr) {
//        return;
//    } else if (curr->next == curr) {
//        curr = nullptr;
//        delete curr;
//    } else {
//        tmp = curr;
//        while (tmp->next != curr) {
//            tmp = tmp->next;
//        }
//        tmp->next = curr->next;
//        curr->next->prev = tmp;
//        delete curr;
//        curr = tmp->next;
//    }
    
    size--;
}

void DoublyLinkedList::setNewCurrNode(int numberOfMoves, bool isTurningOpposite) {
    for (int i = 0; i < numberOfMoves; i++) {
        if (isTurningOpposite) {
            curr = curr->prev;
        } else {
            curr = curr->next;
        }
    }
}

void DoublyLinkedList::setStartingCurrNode(int moveStep, bool isMovingBackWards) {
    for (int i = 0; i < moveStep * 2; i++) {
        if (isMovingBackWards) {
            curr = curr->prev;
        } else {
            curr = curr->next;
        }
    }
}

int DoublyLinkedList::getSize() const {
    return size;
}

void DoublyLinkedList::add(int data, bool isLeft) {
    Node *newNode = new Node(data, isLeft);
    if (!curr) {
        curr = newNode;
    } else {
        newNode->next = curr->next;
        curr->next->prev = newNode;
        curr->next = newNode;
        newNode->prev = curr;
    }
    size++;
}

Node *DoublyLinkedList::getCurr() {
    return curr;
}

void DoublyLinkedList::setCurr(Node *node) {
    curr = node;
}

void printList(DoublyLinkedList &list) {
    int i = 0;
    while (list.getCurr()->next && i < list.getSize()) {
        std::cout << list.getCurr()->data << ' ';
        list.setCurr(list.getCurr()->next);
        i++;
    }
    std::cout << '\n';
}

void fillList(DoublyLinkedList &doublyLinkedList, int numberOfPairs) {
    for (int i = 0; i < numberOfPairs; i++) {
        doublyLinkedList.add(i, false);
        if (i == 0) {
            doublyLinkedList.add(numberOfPairs - 1 + i, true);
        } else {
            doublyLinkedList.add(i - 1, true);
        }
    }
}

int main() {
    DoublyLinkedList doublyLinkedList;

    int numberOfPairs;
    int startingNodeIndex;
    int isTurningOpposite;
    bool isComingBack;

    int currentMode;
    int numberOfOperations;
    int numberOfMoves;

    std::cin >> numberOfPairs >> startingNodeIndex >> isTurningOpposite;
    std::cin >> numberOfOperations;

    fillList(doublyLinkedList, numberOfPairs);
    doublyLinkedList.setStartingCurrNode(startingNodeIndex, isTurningOpposite);

    for (int i = 0; i < numberOfOperations; i++) {
        std::cin >> currentMode;

        if (currentMode == 0) {
            std::cin >> numberOfMoves;
            doublyLinkedList.setNewCurrNode(numberOfMoves, isTurningOpposite);
            printList(doublyLinkedList);
        }

        if (currentMode == 1) {
            std::cin >> numberOfMoves;
            doublyLinkedList.setNewCurrNode(numberOfMoves, isTurningOpposite);
            doublyLinkedList.deleteCurrentHead();
            std::cin >> isComingBack;
        }

        if (currentMode == 2) {
            std::cin >> numberOfMoves;
            doublyLinkedList.setNewCurrNode(numberOfMoves, isTurningOpposite);
            isTurningOpposite = !isTurningOpposite;
        }
    }

    return 0;
}