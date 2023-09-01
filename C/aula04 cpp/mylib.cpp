#ifndef _MYLIB_CPP_
#define _MYLIB_CPP_
#include <iostream>
#include <string>

using namespace std;

string leStr()
{
    string txt;
    getline(cin, txt);
    if (txt[0] == '\0')
        getline(cin, txt);
    return txt;
}

#endif