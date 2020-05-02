#include "clog.h"
#include <sys/time.h>
#include <ctime>

namespace clog{

logger::logger(const char* filename, int line)
:filename(filename),
 line(line)
{
	fp_ = fopen("./simplelog.log","a+");
}

ostream& logger::addinfo(){
	time_t cur_time = time(NULL) + 28800;
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
	string tmp = log.str();
	fwrite(tmp.c_str(), 1, tmp.size(), fp_);
	fclose(fp_);
    //cout<<"call ~logger()"<<endl;
}


}//namespace clog
