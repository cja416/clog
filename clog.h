#ifndef CLOG_H
#define CLOG_H

#include <iostream>
#include <string>
#include <sstream>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
 
using namespace std;
 

namespace clog{

class logger; 

#define LOG clog::logger(__FILE__, __LINE__).addinfo()
class logger{
public:
	logger(const char* filename, int line);
	
     	
	 ostream& addinfo();
	 
	 ~logger();

private:
	 
	string filename;
	int line;
	ostringstream log;
	FILE* fp_;
};


}//namespace clog
 
#endif //CLOG
