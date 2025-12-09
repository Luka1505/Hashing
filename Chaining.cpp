#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class HashTable {
private:
    int size;
    Node** table;

public:
    HashTable(int s) {
        size = s;
        table = new Node*[size];
        for (int i = 0; i < size; i++)
            table[i] = NULL;
    }

    int hashFunction(int key) {
        return key % size;
    }

    void insertChaining(int key) {
        int index = hashFunction(key);
        Node* newNode = new Node();
        newNode->data = key;
        newNode->next = table[index];
        table[index] = newNode;
        cout << "Inserted " << key << " at index " << index << endl;
    }

    bool searchChaining(int key) {
        int index = hashFunction(key);
        Node* temp = table[index];
        while (temp != NULL) {
            if (temp->data == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void deleteChaining(int key) {
        int index = hashFunction(key);
        Node* temp = table[index];
        Node* prev = NULL;
        while (temp != NULL) {
            if (temp->data == key) {
                if (prev == NULL)
                    table[index] = temp->next;
                else
                    prev->next = temp->next;
                delete temp;
                cout << "Deleted " << key << " from index " << index << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "Element not found!" << endl;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << " --> ";
            Node* temp = table[i];
            while (temp != NULL) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    int size;
    cout << "Enter hash table size: ";
    cin >> size;
    HashTable h(size);
    int choice, key;
    while (true) {
        cout << "\n1. Insert 2. Search 3. Delete 4. Display 5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                h.insertChaining(key);
                break;
            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                if (h.searchChaining(key))
                    cout << "Found!\n";
                else
                    cout << "Not Found!\n";
                break;
            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                h.deleteChaining(key);
                break;
            case 4:
                h.display();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}

