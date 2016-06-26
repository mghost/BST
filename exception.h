#ifndef __exception_h__
#define __exception_h__

#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

// no more memory exception
class NoMoreMemory { };

// bad stream exception
class BadStream { };

// no such element exception
class NoSuchElement {
public:
	NoSuchElement() {
		this->msg = 0;
	}

	NoSuchElement(const char* msg) {
		this->msg = (char*)malloc(strlen(msg)*sizeof(char));
		if(!this->msg)
			throw NoMoreMemory();
		for(int i=0; i<strlen(msg); i++)
			this->msg[i] = msg[i];
	}

	void printMessageTrace(ofstream& ofs) {
		if(!ofs)
			throw BadStream();

		ofs << "  -> ";
		for(int i=0; i<strlen(this->msg); i++)
			ofs << msg[i];
		ofs << endl;
		ofs.flush();
	}

private:
	char* msg;
};

#endif
