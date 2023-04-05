#include "JNABootstrap.h"
#include "JavaAPI_C.h"
#include <jni.h>

////////////////////////////////////////////////////

typedef int (*calc_cb) (int); 
typedef jstring (*getName_cb) (void);
typedef void (*log_cb) (jstring);

calc_cb calc_cb_func = 0;
getName_cb getName_cb_func = 0;
log_cb log_cb_func = 0;

////////////////////////////////////////////////////
// Java Callback Registration

extern "C" void reg_calc_cb(calc_cb func) {
    // store callback
    calc_cb_func = func;
}

extern "C" void reg_getName_cb(getName_cb func) {
    // store callback
    getName_cb_func = func;
}

extern "C" void reg_log_cb(log_cb func) {
    // store callback
    log_cb_func = func;
}

////////////////////////////////////////////////////

// Native library classname
char* classname = (char* )"javalibrary_jna/JavaLibrary_JNA";

JavaAPI_C::JavaAPI_C() {
    if ( ! jvm ) {
        env = create_vm(&jvm, classname);
    }
}

JavaAPI_C::JavaAPI_C(const JavaAPI_C& orig) {
}

JavaAPI_C::~JavaAPI_C() {
    // clean up Java objects and JVM
    if ( jvm ) {
        printf("Closing JVM()\n");
        jvm->DestroyJavaVM();
    }
}

int JavaAPI_C::calc(int value) {
    return ::calc(value);
}

const char* JavaAPI_C::getName(void) {
    return ::getName();
}

void JavaAPI_C::log(char* msg) {
    ::log(msg);
}

////////////////////////////////////////////////////
// C API

extern "C" int calc(int value) {
    printf("In C++: calc(value=%d)\n",value);
    if ( ! jvm ) {
        env = create_vm(&jvm, classname);
    }
    if ( calc_cb_func ) {
        return calc_cb_func(value);
    }
    return -1;
}

extern "C" const char* getName(void) {
    printf("In C++: getName()\n");
    if ( ! jvm ) {
        env = create_vm(&jvm, classname);
    }

    if ( getName_cb_func ) {
        jstring jstr = getName_cb_func();
        return strdup( (char*)jstr );
    }
    return NULL;
}

extern "C" void log(char* msg) {
    printf("In C++: log(msg=%s)\n",msg);
    if ( ! jvm ) {
        env = create_vm(&jvm, classname);
    }

    if ( log_cb_func ) {
        jstring jstr = (jstring)msg;
        log_cb_func(jstr);
    }
}
