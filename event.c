#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* input_thread_procedure(void* arg)
{
	pthread_mutex_lock(&lock);
	int* ctr_ptr = (int*)arg;
	printf("input_thread: pre event counter = %d\n", *ctr_ptr);
	*ctr_ptr+=1;
	printf("input_thread: post event counter = %d\n", *ctr_ptr);
	pthread_mutex_unlock(&lock);
	return NULL;
}

void* timer_thread_procedure(void* arg)
{
	pthread_mutex_lock(&lock);
	int* ctr_ptr = (int*)arg;
	printf("timer_thread: pre event counter = %d\n", *ctr_ptr);
	*ctr_ptr+=1;
	printf("timer_thread: post event counter = %d\n", *ctr_ptr);
	pthread_mutex_unlock(&lock);
	return NULL;
}

void* dispatcher_thread_procedure(void* arg)
{
	printf("Hello from dispatcher\n");
	return NULL;
}

int main()
{
	// CORE
	// initialize input thread for reporting user input events
	pthread_t input_thread;
	pthread_t timer_thread;
	pthread_t dispatcher_thread;
	int res;

	// shared memory
	int event_counter = 0;

	void* arg = (void*)&event_counter;
	res = pthread_create(&input_thread, NULL, input_thread_procedure, arg);
	res = pthread_create(&timer_thread, NULL, timer_thread_procedure, arg);

	res = pthread_create(
		&dispatcher_thread,
	       	NULL,
	       	dispatcher_thread_procedure,
	       	NULL
	);

	pthread_join(input_thread, NULL);
	pthread_join(timer_thread, NULL);
	pthread_join(dispatcher_thread, NULL);

	return 0;

	// initialize shared memory ( event queue ) for events to write to
	// initialize dispatcher thread for reading from the event queue and 
	// calling relevnat callbacks
	
	// APP
	// allow user to subscribe to events from dispatchers catalog with
	// custom callback functions
}

