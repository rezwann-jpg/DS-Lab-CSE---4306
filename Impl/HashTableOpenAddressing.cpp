#include <iostream>
#include <vector>
#include <cmath>

bool isPrime(int n) {
    if (n < 2)
        return false;

    if (n == 2)
        return true;

    for (int i = 2; i < std::ceil(std::sqrt(n)); i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

int nearestPrimeNum(int n) {
    for (int i = n - 1; i > 1; i++) {
        if (isPrime(i))
            return i;
    }

    return -1;
}

class HashTable {
private:
    std::vector<int> table;
    int choice;
    int numOfItems;
    int tableSize;

    int hashFunction(int key) {
        return key % tableSize;
    }

    int hashFunction2(int key) {
        int R = nearestPrimeNum(key);
        return R - (key % R);
    }

    float loadFactor() {
        return static_cast<float>(numOfItems) / tableSize;
    }

    int getProbeIndex(int index, int i) {
        if (choice == 1) {
            return (index + i) % tableSize;
        }
        else if (choice == 2) {
            return (index + i * i) % tableSize;
        }
        else if (choice == 3) {
            return (index + i * hashFunction2(index)) % tableSize; 
        }

        return -1;
    }
    
public:
    HashTable(int choice, int size) : table(size, -1), tableSize(size), choice(choice), numOfItems(0) { }

    void Insert(int key) {
        int index = hashFunction(key);
        int i = 0;

        while (i < 6) {
            int newIndex = getProbeIndex(index, i);
            if (table[newIndex] == -1) {
                table[newIndex] = key;
                numOfItems++;
                std::cout << "Inserted : Index-" << newIndex << " (L.F = " 
                          << loadFactor() << ")\n";

                return;     
            }
            else {
                std::cout << "Collision: Index-" << newIndex << "\n";
                i++;
            }
        }

        std::cout << "input Abandoned\n";
    }
};

int main() {
    int choice, N, Q;
    std::cin >> choice >> N >> Q;

    HashTable hashTable(choice, N);

    int num;
    while (Q--) {
        std::cin >> num;
        hashTable.Insert(num);
    } 

    return 0;
}