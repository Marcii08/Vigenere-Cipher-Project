#ifndef CRYPTANALYSIS_H
#define CRYPTANALYSIS_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class CryptAnalysis
{
    public:
        CryptAnalysis();
        string copyStr;

    protected:

    private:
        string Decrypt(string copyStr);
        string Encrypt(string copyStr);
};

#endif // CRYPTANALYSIS_H
