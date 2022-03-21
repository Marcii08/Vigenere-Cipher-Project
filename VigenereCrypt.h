#ifndef VIGENERECRYPT_H
#define VIGENERECRYPT_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class VigenereCrypt
{
    public:
        VigenereCrypt();
        string copyStr;

    protected:

    private:
        string Decrypt(string copyStr);
        string Encrypt(string copyStr);
};

#endif // VIGENERECRYPT_H
