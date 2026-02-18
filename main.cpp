#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Item class
class Item {
public:
    string name;
    int quantity;
    string rarity;

    Item(string n, int q, string r) {
        name = n;
        quantity = q;
        rarity = r;
    }

    void displayItem() {
        cout << "- " << name << " (Quantity: " << quantity << ", Rarity: " << rarity << ")" << endl;
    }
};

// Inventory class
class Inventory {
private:
    vector<Item> items;
    int capacity;

public:
    Inventory(int cap) {
        capacity = cap;
    }

    void addItem(Item newItem) {
        if (items.size() < capacity) {
            items.push_back(newItem);
            cout << newItem.name << " added to inventory!" << endl;
        } else {
            cout << "Inventory is full! " << newItem.name << " could not be added." << endl;
        }
    }

    void showInventory() {
        cout << "\n--- Current Inventory ---" << endl;
        if (items.empty()) {
            cout << "Inventory is empty." << endl;
            return;
        }
        for (int i = 0; i < items.size(); i++) {
            items[i].displayItem();
        }
        cout << "-------------------------" << endl;
    }
};

int main() {
    // Create an inventory with a capacity of 5
    Inventory myInventory(5);

    cout << "Welcome to the adventure! Gathering items..." << endl;

    // Creating items
    Item sword("Legendary Sword", 1, "Epic");
    Item healthKit("Health Kit", 3, "Common");
    Item shield("Steel Shield", 1, "Rare");

    // Adding items to inventory
    myInventory.addItem(sword);
    myInventory.addItem(healthKit);
    myInventory.addItem(shield);

    // Display inventory
    myInventory.showInventory();

    return 0;
}