#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <unistd.h>
#include <pthread.h>

namespace clog{

//pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
//pthread_mutex_init(&mutex, NULL);

class lock_guard{
public:
	lock_guard(pthread_mutex_t _mutex)
	:mutex(_mutex)
	{
		//pthread_mutex_init(&mutex, NULL);
		pthread_mutex_lock(&mutex);
	}

	~lock_guard(){
		pthread_mutex_unlock(&mutex);
		//pthread_mutex_destroy(&mutex);
	}

private:
	pthread_mutex_t mutex;
};//lock_guard


};//namespace clog
#endif
