#include <algorithm>
#include <iostream>

template<typename Object>
class MyVector {
public:
    explicit MyVector(int initSize = 0) : m_size{initSize}, m_capacity{initSize + SPARE_CAPACITY} {
        m_objects = new Object[m_capacity];
    }

    MyVector(const MyVector& rhs) : m_size(rhs.m_size), m_capacity(rhs.m_capacity), m_objects(nullptr) {
        m_objects = new Object[m_capacity];
        for (int k = 0; k < m_size; k++) {
            m_objects[k] = rhs.m_objects[k];
        }
    }

    MyVector& operator=(const MyVector& rhs) {
        MyVector copy = rhs;
        std::swap(*this, copy);
        return *this;
    }

    ~MyVector() {
        delete[] m_objects;
    }

    MyVector(MyVector&& rhs) : m_size(rhs.m_size), m_capacity(rhs.m_capacity), m_objects(rhs.m_objects) {
        rhs.m_objects = nullptr;
        rhs.m_size = 0;
        rhs.m_capacity = 0;
    }

    MyVector& operator=(MyVector&& rhs) {
        std::swap(m_size, rhs.m_size);
        std::swap(m_capacity, rhs.m_capacity);
        std::swap(m_objects, rhs.m_objects);

        return *this;
    }

    void resize(int newSize) {
        if (newSize > m_capacity)
            reserve(newSize * 2);
        m_size = newSize;
    }    

    void reserve(int newCapacity) {
        if (newCapacity < m_size) 
            return;

        Object* newArray = new Object[newCapacity];
        for (int k = 0; k < m_size; k++)
            newArray[k] = std::move(m_objects[k]);

        m_capacity = newCapacity;
        std::swap(m_objects, newArray);
        delete[] newArray;
    }

    Object& operator[](int index) {
        return m_objects[index];
    }

    const Object& operator[](int index) const {
        return m_objects[index];
    }

    bool empty() const {
        return size() == 0;
    }

    int size() const {
        return m_size;
    }

    int capacity() const {
        return m_capacity;
    } 

    void push_back(const Object& x) {
        if (m_size == m_capacity)
            reserve(2 * m_capacity + 1);
        m_objects[m_size++] = x;
    }

    void push_back(Object&& x) {
        if (m_size == m_capacity)
            reserve(2 * m_capacity + 1);
        m_objects[m_size++] = std::move(x);
    }

    void pop_back() {
        --m_size;
    }

    const Object& back() const {
        return m_objects[m_size - 1];
    }

    typedef Object* iterator;
    typedef const Object* const_iterator;

    iterator begin() {
        return &m_objects[0];
    }

    const_iterator begin() const {
        return &m_objects[0];
    }

    iterator end() {
        return &m_objects[size()];
    }

    const_iterator end() const {
        return &m_objects[size()];
    }

    static const int SPARE_CAPACITY = 16;
private:
    int m_size;
    int m_capacity;
    Object* m_objects;
};

template<typename Container>
void print(const Container& c, std::ostream& out = std::cout) {
    if (c.empty()) {
        out << "(empty)";
    }
    else {
        auto itr = begin(c);
        
        out << "[" << *itr++;

        while (itr != end(c)) {
            out << ", " << *itr++;
        }
        out << "]" << std::endl;
    }
}

template<typename Container>
auto begin(Container& c) -> decltype(c.begin()) {
    return c.begin();
}

template<typename Container>
auto begin(const Container& c) -> decltype(c.begin()) {
    return c.begin();
}

template<typename Container>
auto end(Container& c) -> decltype(c.end()) {
    return c.end();
}

template<typename Container>
auto end(const Container& c) -> decltype(c.end()) {
    return c.end();
} 