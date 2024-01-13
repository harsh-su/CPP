#include <iostream>
#include <cstdlib>

#define MAX 6
#define HASHMAX 5

int h(int key) { return key % HASHMAX; }

class hashnode {
public:
    int key;
    hashnode* next;

    // Constructor
    hashnode(){
        key =0;
        next =NULL;
    }
    hashnode(int key ){
        this->key  = key;
        this->next = NULL;
    }
};

class hashtable {
public:
    hashnode hashtab[HASHMAX];

    hashtable() {
        for (int i = 0; i < HASHMAX; i++) {
            hashtab[i].next = nullptr;
        }
    }

    ~hashtable() {
        for (int i = 0; i < HASHMAX; i++) {
            hashnode* current = hashtab[i].next;
            while (current != nullptr) {
                hashnode* temp = current;
                current = current->next;
                delete temp;
            }
        }
    }

    void create_hashtable(int key) {
        int index = h(key);
        hashnode* new_hashnode = new hashnode(key);
        new_hashnode->next = hashtab[index].next;
        hashtab[index].next = new_hashnode;
    }

    int hash_search(int key, int* counter) {
        hashnode* pointer;
        int index = h(key);
        pointer = hashtab[index].next;

        std::cout << "data[" << index << "]: ";

        while (pointer != nullptr) {
            (*counter)++;
            std::cout << "data[" << pointer->key << "]: ";
            if (pointer->key == key)
                return 1;
            else
                pointer = pointer->next;
        }

        return 0;
    }
};

int main() {
    hashtable htable;
    int key, index, counter = 0;  // Key is the value to be found
    index = 0;

    int data[MAX] = {1, 10, 15, 5, 8, 7};  //!< test data

    // Construct hash table
    while (index < MAX) {
        htable.create_hashtable(data[index]);
        index++;
    }

    for (int i = 0; i < HASHMAX; i++) {
        std::cout << "hashtab [" << i << "]\n";

        hashnode* temp = htable.hashtab[i].next;

        while (temp != nullptr) {
            std::cout << "[" << temp->key << "] ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    while (key != -1) {
        // Get key from user input or use a test key
        std::cout << "Enter key to search (-1 to exit): ";
        std::cin >> key;

        if (key == -1)
            break;

        if (htable.hash_search(key, &counter)){
            std::cout << "Search time = " << counter << std::endl;
            counter=0;
        }else{
            std::cout << "Not found!\n";
        }
    }

    return 0;
}
