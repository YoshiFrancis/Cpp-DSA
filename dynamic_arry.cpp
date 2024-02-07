#include <iostream>
#include <cassert>

template <typename T>
class DynamicArray {

public:
    DynamicArray(int length) : m_length {length}, m_capacity{ length } {
        assert(length > 1);
        m_data = { new T[length] };
    }

    DynamicArray(T array[], int length) : DynamicArray(length) {
        assert(length > 1);
        for (int i = 0; i < length; i++) {
            m_data[i] = array[i];
        }
    }

    ~DynamicArray() {
        delete[] m_data;
    }

    const void push(T val) {
        m_length++;
        if (m_length > m_capacity) {
            m_capacity *= 2;
            T* tmpStor = { new T[m_capacity] };
            for (int i = 0; i < m_length - 1; i++)  {
                tmpStor[i] = m_data[i];
            }
            tmpStor[m_length - 1] = val;
            m_data = tmpStor;
        }
        else {
            m_data[m_length - 1] = val;
        }
    }

    const void pop() {
        m_length--;
    }

    const T peek() const {
        return m_data[m_length - 1];
    }

    const void printArray() const {
        std::cout << "[ ";
        for (int i = 0; i < m_length; i++) {
            std::cout << m_data[i] << " ";
        }
        std::cout << "]\n";
    }

    const int getCapacity() const { return m_capacity; }
    const int getLength() const { return m_length; }
private:
    int m_capacity {};
    int m_length {};
    T* m_data;
};

int main() {
    DynamicArray<int> array {5};
    array.printArray();
    int array2[5] = {1, 2, 3, 4, 5};
    DynamicArray<int> dynArray2 {array2, 5};
    dynArray2.printArray();
    dynArray2.push(5);
    dynArray2.push(1000);
    dynArray2.printArray();
    dynArray2.pop();
    dynArray2.printArray();
    std::cout << dynArray2.getLength() << " " << dynArray2.getCapacity() << "\n";
}