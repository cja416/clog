#ifndef CLOG_H
#define CLOG_H

#include <iostream>
#include <string>
#include <sstream>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include "util.h"
 
using namespace std;
 
#define DEFAULT_LOG_FILE "./simplelog.log"

namespace clog{

static std::string LogFileName; 

class logger; 

#define LOG clog::logger(__FILE__,__LINE__).addinfo()

class logger{						
public:
	logger(const char* filename, int line);
	
public:
	
	 ostream& addinfo();
	
	 ~logger();

private:
	
	logger(const logger& another){};
	logger& operator=(const logger& another){return *this;}

	string filename;
	int line;
	ostringstream log;
};

void set_logdir(string dir);
void write_log(ostringstream& _log, FILE* _fp);

}//namespace clog
 
#endif //CLOG
