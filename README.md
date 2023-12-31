Ensure C++ extensions are installed before beginning.

To get started, compile the .cpp file by using the following command:
**g++ -o program inMemoryDB.cpp**

After compilation, run the program using the following: 
**./program**

A menu will then display on the terminal asking whether you want to:
1. Begin a transaction.
2. Put a value.
3. Get a value.
4. Commit changes made to database.
5. Rollback changes made to database.
6. Exit the database.

Input which command you would like to execute and hit ENTER.
For putting key value pairs, first put the key, press ENTER, then put the value and press ENTER.

**Further clarifications to assignment:**
Since the "int" data type is not nullable in C++ for example, clarify what this could mean for those that code in C++. For example, we use some like INT_MIN, like I did. Further, I would clarify point 11 in the document because it is worded a bit confusingly. Namely, re-write to something like: "commit() applies changes made within the transaction to the main state. This allows any future get() command to see the changes that were made within the transaction just committed." Another method that could be added is to delete a key-value pair from the in memory database. 

