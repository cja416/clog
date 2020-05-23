#include "clog.h"
#include <sys/time.h>
#include <ctime>

namespace clog{

thread_local char log_buf[1024 * 10] = {0};

#define DEFAULT_LOG_FILE "./simplelog.log"

FILE* __attribute__((weak)) log_fp = fopen(DEFAULT_LOG_FILE,"a+");

logger::logger(const char* filename, int line)
: filename(filename),
  line(line)
{}

ostream& logger::addinfo(){
	time_t cur_time = time(NULL) + 28800;	//+8 hour
	struct tm gm_time;
	if(NULL == gmtime_r(&cur_time,&gm_time)){
		log << "failed to convert time by gmtime_r" << endl;
	}
	log << "[" << gm_time.tm_year+1900 << "-" << gm_time.tm_mon+1 	//year and mon should be dealed with 
		<< "-" << gm_time.tm_mday << " " << gm_time.tm_hour
		<< ":" << gm_time.tm_min  << ":" << gm_time.tm_sec << "] ";
	
	log << filename << ' ' << line << ' ';
	return log;
}


logger::~logger(){
	write_log(this->log, log_fp);
}

void set_logdir(string dir){
	if(log_fp != NULL)
		fclose(log_fp);
	string log_dir = dir;
	log_fp = fopen(log_dir.c_str(),"a+");
}

//TODO
void write_log(ostringstream& _log, FILE* _fp){
	string tmp = _log.str();
	//write to __threadlocal
	fwrite(tmp.c_str(), 1, tmp.size(), _fp);
	_log.str("");
}

}//namespace clog
