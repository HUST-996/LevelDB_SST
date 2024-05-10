#include <iostream>
#include <string>
#include <leveldb/db.h>
using namespace std;


int main()
{
    leveldb::DB *db;
    leveldb::Options options;
    leveldb::ReadOptions readOptions;
    leveldb::Status status = leveldb::DB::Open(options, "/tmp/testdb", &db);
    
    string get;

    string key = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefgh000000000";
    
    if (status.ok()) {
        status = db->Get(readOptions, key, &get);
    }
        
    if (status.ok())
        cout << "key:" << key << "\nget value:" << get << std::endl;
    else
        cout << "error occurred!" << endl;

    delete db;

    return 0;
}