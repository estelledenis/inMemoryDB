#include "C:\Users\estel\projects\helloworld\.vscode\inMemoryDB.h"
#include <iostream>
#include <climits>

using namespace std;
map<string, int> temp;

inMemoryDB::inMemoryDB() {
    this->transactionBegun = false;
}

int inMemoryDB::get(string key) {
    if (this->m[key] == 0) {
        return INT_MIN;
    }
    else {
        return this->m[key];
    }
}

void inMemoryDB::put(string key, int val) {
    if (this->transactionBegun == false) {
        throw runtime_error("Transaction not begun.");
    }
    
    temp = this->m;
    temp[key] = val;
}

void inMemoryDB::begin_transaction() {
    this->transactionBegun = true;
    temp = this->m;
}

void inMemoryDB::commit() {
    this->m = temp;
    this->transactionBegun = false;
}

void inMemoryDB::rollback() {
    if (this->transactionBegun == false) {
        throw runtime_error("No open transaction.");
    }
    temp.clear();
    this->transactionBegun = false;
}


int main() {

    inMemoryDB d;
 //   d.get("A");
 //   d.put("A", 5);
    d.begin_transaction();
    d.put("A", 5);
    cout << d.get("A");
    d.put("A", 6);
    d.commit();
 //   d.rollback();
    cout << d.get("B");
    d.begin_transaction();
    d.put("B", 10);
    d.commit();
    cout << d.get("B");

    return 0;
}
