#ifndef LIBRARYCLASS_H
#define LIBRARYCLASS_H

#include <iostream>

using namespace std;

typedef void (*callback) (int);

class LibraryClass {
	public:
		LibraryClass();
		virtual ~LibraryClass();
		
		int calc(int i);
		string getname(void);
		void callme(callback func);
		void log(string s);
};

#endif