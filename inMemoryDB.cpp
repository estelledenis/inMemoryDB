#include "inMemoryDB.h"
#include <iostream>
#include <climits>

using namespace std;
map<string, int> temp;

inMemoryDB::inMemoryDB() {
    this->transactionBegun = false;
}

int inMemoryDB::get(string key) {
    if (this->m.find(key) == this->m.end()) {
        cout << "No value found." << endl;
        cout << endl;
        return INT_MIN;
    }
    else {
        cout << "Value: " << this->m[key] << endl;
        cout << endl;
        return this->m[key];
    }
}

void inMemoryDB::put(string key, int val) {
    if (this->transactionBegun == false) {
        throw runtime_error("Transaction not begun.");
    }
    
    temp = this->m;
    temp[key] = val;
    cout << endl;
}

void inMemoryDB::begin_transaction() {
    this->transactionBegun = true;
    temp = this->m;
    cout << "Transaction begun." << endl;
    cout << endl;
}

void inMemoryDB::commit() {
    if (this->transactionBegun == false) {
        throw runtime_error("No open transaction.");
    }
    this->m = temp;
    this->transactionBegun = false;
    cout << "Commit successful." << endl;
    cout << endl;
}

void inMemoryDB::rollback() {
    if (this->transactionBegun == false) {
        throw runtime_error("No open transaction.");
    }
    temp.clear();
    this->transactionBegun = false;
    cout << "Rollback successful." << endl;
    cout << endl;
}


int main() {

    inMemoryDB d;
    int val;
    string key;
    bool on = true;

    while(on) {

    cout << "Welcome to the in memory database" << endl;
    cout << "1. Begin transaction" << endl;
    cout << "2. Put a value" << endl;
    cout << "3. Get a value" << endl;
    cout << "4. Commit" << endl;
    cout << "5. Rollback" << endl;
    cout << "6. Exit database" << endl;

    int option;
    cin >> option;

    switch(option) {
        case 1:
        d.begin_transaction();
        break;

        case 2:
        cout << "Please enter a key followed by a value" << endl;
        cin >> key >> val;
        d.put(key, val);
        break;

        case 3:
        cout << "Please enter a key" << endl;
        cin >> key;
        d.get(key);
        break;

        case 4:
        d.commit();
        break;

        case 5:
        d.rollback();
        break;

        case 6:
        on = false;
        break;
        }
    }

    return 0;
}
