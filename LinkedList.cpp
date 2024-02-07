#include <iostream>
#include <cassert>

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
                m_head = new Node<T>{array[i], nullptr};
                currNode = m_head;
            }
            else if (i == length - 1) {
                m_tail = new Node<T>{array[i], nullptr};;
                currNode->next = m_tail;
            }
            else {
                currNode->next = new Node<T>{array[i], nullptr};;
                currNode = currNode->next;
            }
        }
    }

    const void addHead(T val) {
        m_head = new Node<T>{val, m_head};;
        if (m_tail == nullptr) m_tail = m_head;
        m_length++;
    } 

    const void addTail(T val) {
        m_tail->next = new Node<T>{val, nullptr};;
        m_tail = m_tail->next;
        if (m_head == nullptr) m_head = m_tail;
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

    const int getLength() const {
        return m_length;
    }

    const void insertAtIndex(int idx, T val) {
        assert(idx < m_length && idx >= 0);
        if (idx == 0) addHead(val);
        else if (idx == m_length - 1) addTail(val);
        else {
            // O(N) time to insert
            Node<T>* iterator { getNode(idx - 1) };
            Node<T>* newNode = new Node<T>{ val, iterator->next };
            iterator->next = newNode;
            m_length++;
        }
    }

    const void removeIndex(int idx) {
        assert(idx < m_length && idx >= 0);
        Node<T>* iterator { getNode(idx - 1) };
        Node<T>* removedNode { iterator->next };
        iterator->next = removedNode->next;
        delete removedNode;
    }

private:
    Node<T>* m_head {};
    Node<T>* m_tail {};
    int m_length {};

    Node<T>* getNode(int idx) const {
        assert(idx < m_length && idx >= 0);
        // O(N) time to find
        Node<T>* iterator { m_head };
        for (int i {0}; i < idx; i++) iterator = iterator->next;
        return iterator;
    }

};


int main() {
    int array[5] {1, 2, 3, 4, 5};
    LinkedList<int> myList = {array, 5};
    myList.printLinkedList();
    myList.addHead(1);
    myList.addHead(1);
    myList.addHead(1);
    myList.addHead(1);
    myList.addTail(0);
    myList.addTail(0);
    myList.addTail(0);
    myList.printLinkedList();
    myList.removeIndex(5);
    myList.insertAtIndex(5, 7);
    myList.insertAtIndex(5, 8);
    myList.insertAtIndex(5, 9);
    myList.printLinkedList();
    return 0;
}