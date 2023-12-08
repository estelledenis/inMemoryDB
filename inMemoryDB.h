#pragma once
#include <string>
#include <map>

#ifndef INMEMORYDB_H
#define INMEMORYDB_H


struct inMemoryDB {

    std::map<std::string, int> m;
    bool transactionBegun;

    inMemoryDB();
    int get(std::string key);
    void put(std::string key, int val);
    void begin_transaction();
    void commit();
    void rollback();
};

#endif
