#include <iostream>
using namespace std;

int hashFunction(int key, int size) {
    return key % size;
}

void insertKey(int table[], int size, int key) {
    int index = hashFunction(key, size);

    if (table[index] == -1) {
        table[index] = key;
        cout << "Inserted " << key << " at index " << index << endl;
    } else {
        cout << "Collision occurred for key " << key
             << " at index " << index << endl;
    }
}

int searchKey(int table[], int size, int key) {
    int index = hashFunction(key, size);
    if (table[index] == key)
        return index;
    return -1;
}

void deleteKey(int table[], int size, int key) {
    int index = hashFunction(key, size);
    if (table[index] == key) {
        table[index] = -1;
        cout << "Deleted " << key << " from index " << index << endl;
    } else {
        cout << "Key not found!\n";
    }
}

void displayTable(int table[], int size) {
    cout << "\nHash Table:\n";
    for (int i = 0; i < size; i++) {
        cout << i << " : ";
        if (table[i] == -1)
            cout << "EMPTY\n";
        else
            cout << table[i] << "\n";
    }
}

int main() {
    int size;
    cout << "Enter hash table size: ";
    cin >> size;
    int table[size];
    for (int i = 0; i < size; i++)
        table[i] = -1;
    int choice, key;
    while (true) {
        cout << "\n1.Insert  2.Search  3.Delete  4.Display  5.Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                insertKey(table, size, key);
                break;
            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                int pos;
                pos = searchKey(table, size, key);
                if (pos != -1)
                    cout << "Key found at index " << pos << endl;
                else
                    cout << "Key not found!\n";
                break;
            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                deleteKey(table, size, key);
                break;
            case 4:
                displayTable(table, size);
                break;
            case 5:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
    return 0;
}


