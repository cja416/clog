#include <iostream>
#include "clog.h"
#include <pthread.h>
#include <sys/types.h>
#include <sys/syscall.h>

#define thread_number 3

pthread_mutex_t _mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_func(void *arg){
	//int num = *(int*)arg;
	for(int i=0;i<100;i++){
		LOG << "thread " << syscall(SYS_gettid) << " write a message "
		    << "to test whether it will be an chaos" << std::endl;
		usleep(100);
	}
	return NULL;
}

int main(){
	
	pthread_mutex_init(&_mutex,NULL);	
	
	LOG << "this is a hello world message." << std::endl;
	LOG << "create thread to write log" << std::endl;
	pthread_t t_id[3];
	int arg[3];
	for(int i=0; i < thread_number ;i++){
		arg[i] = i;
		if(0 != pthread_create(&t_id[i], NULL, thread_func, (void*)&arg[i])){
			LOG << "create thread error" << std::endl;
		}
	}

	for(int i=0; i<3; i++){
		pthread_join(t_id[i],NULL);
	}
	
	LOG << "threads joined, LOG finish." << std::endl;

	return 0;
}
