#include <iostream>
using namespace std;

#define EMPTY -1
#define DELETED -2

class LinearProbingHash {
public:
    int *table;      // Dynamic table
    int size;        // User-defined size
    int probeCount;  // Count probes

    LinearProbingHash(int s) {
        size = s;
        table = new int[size];
        for (int i = 0; i < size; i++)
            table[i] = EMPTY;
        probeCount = 0;
    }

    int hash(int key) {
        return key % size;
    }

    void insertLP(int key) {
        int index = hash(key);
        probeCount = 0;

        for (int i = 0; i < size; i++) {
            int newIndex = (index + i) % size;
            probeCount++;

            if (table[newIndex] == EMPTY || table[newIndex] == DELETED) {
                table[newIndex] = key;
                cout << "Inserted " << key 
                     << " at index " << newIndex
                     << " (probes = " << probeCount << ")\n";
                return;
            }
        }
        cout << "Hash Table Full! Cannot insert.\n";
    }

    int searchLP(int key) {
        int index = hash(key);
        probeCount = 0;

        for (int i = 0; i < size; i++) {
            int newIndex = (index + i) % size;
            probeCount++;

            if (table[newIndex] == key) {
                cout << "Found " << key 
                     << " at index " << newIndex
                     << " (probes = " << probeCount << ")\n";
                return newIndex;
            }

            if (table[newIndex] == EMPTY) {
                break;
            }
        }

        cout << "Key " << key 
             << " not found! (probes = " << probeCount << ")\n";
        return -1;
    }

    // DELETE
    void deleteLP(int key) {
        int idx = searchLP(key);
        if (idx != -1) {
            table[idx] = DELETED;
            cout << "Deleted " << key << " at index " << idx << endl;
        }
    }

    void printTable() {
        cout << "\nCurrent Hash Table State:\n";
        for (int i = 0; i < size; i++) {
            cout << i << " : ";
            if (table[i] == EMPTY) cout << "EMPTY";
            else if (table[i] == DELETED) cout << "DELETED";
            else cout << table[i];
            cout << endl;
        }
        cout << endl;
    }
};


int main() {
    int size;
    cout << "Enter size of hash table: ";
    cin >> size;

    LinearProbingHash h(size);

    int choice, value;

    do {
        cout << "\n---- LINEAR PROBING HASH TABLE ----\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Print Table\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                h.insertLP(value);
                break;

            case 2:
                cout << "Enter value to search: ";
                cin >> value;
                h.searchLP(value);
                break;

            case 3:
                cout << "Enter value to delete: ";
                cin >> value;
                h.deleteLP(value);
                break;

            case 4:
                h.printTable();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}

