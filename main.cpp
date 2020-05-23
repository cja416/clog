#include <iostream>
#include "clog.h"
#include <pthread.h>


void *thread_func(void *arg){
	int num = *(int*)arg;
	for(int i=0;i<100;i++){
		LOG << "thread " << num << " write a message "
		    << "to test whether it will be an chaos" << endl; 
		usleep(1000);
	}
	return NULL;
}

int main(){
		
	LOG << "this is a hello world message." << endl;
	LOG << "create thread to write log" << endl;
	pthread_t t_id[3];
	int arg[3];
	for(int i=0; i<3 ;i++){
		arg[i] = i;
		if(0 != pthread_create(&t_id[i], NULL, thread_func, (void*)&arg[i])){
			LOG << "creata thread error" << endl;
		}
	}

	for(int i=0; i<3; i++){
		pthread_join(t_id[i],NULL);
	}
	
	LOG << "threads joined, LOG finish." << endl;

	return 0;
}
