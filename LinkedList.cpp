#include <iostream>


template <typename T>
struct Node {
    T val {};
    Node* next { nullptr };
};

template <typename T>
class LinkedList {

public:
    LinkedList() {}

    LinkedList(T array[], int length) : m_length { length } 
    {
        Node<T>* currNode {};
        for (int i = 0; i < length; i++) {
            if (i == 0) {
                Node<T>* newHead {};
                newHead->val = array[i];
                newHead->next = nullptr;

                m_head = newHead;
                currNode = m_head;
            }
            else if (i == length - 1) {
                Node<T>* newTail {};
                newTail->val = array[i];
                newTail->next = nullptr;
                m_tail = newTail;
            }
            else {
                Node<T>* nextNode {};
                nextNode->val = array[i];
                nextNode->next = nullptr;
                currNode->next = nextNode;
                currNode = currNode->next;
            }
        }
    }

    const void addHead(T val) {
        Node<T>* newHead = { val, m_head };
        m_head = newHead;
        if (m_tail == nullptr) m_tail = newHead;
        m_length++;
    } 

    const void addTail(T val) {
        Node<T>* newTail = { val };
        m_tail->next = newTail;
        m_tail = newTail;
        if (m_head == nullptr) m_head = newTail;
        m_length++;
    } 

    const void printLinkedList() {
        std::cout << "[ ";
        Node<T>* iterator { m_head };
        while (iterator != nullptr) {
            std::cout << iterator->val << " ";
            iterator = iterator->next;
        }
        std::cout << "]\n";
    }

private:
    Node<T>* m_head {};
    Node<T>* m_tail {};
    int m_length {};

};


int main() {
    int array[5] {1, 2, 3, 4, 5};
    LinkedList<int> myList = {array, 5};
    myList.printLinkedList();
    return 0;
}