#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include "Bank.h"
using namespace std;

class FileManager {
public:
    static void saveAllAccounts(const Bank& bank);
    static void loadAllAccounts(Bank& bank);
    
private:
    static const string DATA_FILE;
};

#endif