#ifndef JAVAAPI_C_H
#define JAVAAPI_C_H

#include <iostream>

using namespace std;

extern "C" int calc(int value);
extern "C" const char* getName(void);
extern "C" void log(char* msg);

class JavaAPI_C {
public:
    JavaAPI_C();
    JavaAPI_C(const JavaAPI_C& orig);
    virtual ~JavaAPI_C();
    
    // API
    int calc(int value);
    const char* getName(void);
    void log(char* msg);
private:
    
};

#endif

