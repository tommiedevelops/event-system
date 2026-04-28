#ifndef EVENT_H
#define EVENT_H

#include <pthread.h>

#define MAX_EVENTS (64)
#define MAX_HANDLERS (64)
typedef struct
{
	float x;
} Handler;

typedef enum EventType
{
	KeyPress,
	MousePress
} EventType;

typedef struct 
{
	EventType type;
	float e;	
} Event;


typedef struct 
{
	Event events[MAX_EVENTS];
	int num_events;
} EventQueue;

typedef struct 
{
	pthread_t    thread;
	atomic_int   running;
	EventQueue*  queue; // shared with other threads		    


	Handler    handlers[MAX_HANDLERS];
	int        handler_count;

} DispatcherThread;

typedef struct
{
	pthread_t thread;
	atomic_int running;

	EventQueue* queue;
} InputThread;


#endif
