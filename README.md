Ensure C++ extensions are installed before beginning.

To get started, compile the .cpp file by using the following command:
**g++ -o program inMemoryDB.cpp**

After compilation, run the program using the following: 
**./program**

Notice that the program compiles but then terminates due to runtime error caused by main() calling put() before begin_transaction(). You can comment out and change main() to reflect the changes you wish to make to the in memory database.

Further clarifications to assignment: Since the "int" data type is not nullable in C++ for example, clarify what this could mean for those that code in C++. For example, we use some like INT_MIN, like I did. Further, I would clarify point 11 in the document because it is worded a bit confusingly. Namely, re-write to something like: "commit() applies changes made within the transaction to the main state. This allows any future get() command to see the changes that were made within the transaction just committed." Another method that could be added is to delete a key-value pair from the in memory database. 

