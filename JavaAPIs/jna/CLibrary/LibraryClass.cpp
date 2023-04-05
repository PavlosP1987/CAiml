#include "LibraryClass.h"

LibraryClass* m = new LibraryClass();
int value = 10;

extern "C" void callme(callback func) {
	return m->callme(func);
}

extern "C" int calc(int i) {
	return m->calc(i);
}

extern "C" const char* getname(void) {
	return strdup( m->getname().c_str() );
}

extern "C" void log(char* s) {
	return m->log(s);
}

LibraryClass::LibraryClass() {}

LibraryClass::~LibraryClass() {}

int LibraryClass::calc(int i) {
	return i * 2;
}

string LibraryClass::getname() {
	return "C++ API";
}

void LibraryClass::callme(callback func) {
	if ( func ) {
		func( ++value );
	}
}

void LibraryClass::log(string s) {
	cout << s;
	cout << "\n";
}