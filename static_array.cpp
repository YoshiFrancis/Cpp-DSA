#include <iostream>
#include <cassert>
template <typename T>
class StaticArray {
public:
    StaticArray(T array[], int length)
    { 
        m_array = array;
        m_length = length;
        assert(length > 0); 
    }

    StaticArray(int length) : m_array { new T[length] }, m_length { length }
    { assert(length > 0); }

    ~StaticArray () {
        delete[] m_array;
    }

    const int getLength() const { return m_length; }

    const T getIndex(int idx) const { 
            assert(idx < m_length && idx >= 0);
            return m_array[idx]; 
        }
    void setIndex(int idx, T item) { m_array[idx] = item; }

    const void printArray() const {
        std::cout << "[ ";
        for (int i = 0; i < m_length; i++) {
            std::cout << m_array[i] << " ";
        }
        std::cout << "]\n"; 
    }

private:
    int m_length = 0;
    T* m_array = nullptr;
};

int main() {
    int array[] {1, 2, 3, 4, 5};
    StaticArray<int> myStaticArray(array, 5);
    myStaticArray.printArray();
}