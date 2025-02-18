#include "VectorTemplate.cpp"

int main() {
    MyVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    print(vec);

    return 0;
}