#pragma once
#include <string.h>

struct inMemoryDB {
    private:
    std::string key;
    int val;

    public:
    inMemoryDB();
    int get(std::string key);
    void put(std::string key, int val);
    void begin_transaction();
    void commit();
    void rollback();
};