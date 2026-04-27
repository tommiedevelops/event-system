#include <stdio.h>

void callback()
{
	printf("callback\n");
}



// Event handlers execute non-sequentially
// Special care is needed to ensure event handlers are executed in the correct
// order

int main()
{
	printf("Hello, world!\n");

	// Event Loop (Listen for Events)
	// Not the same as "Message Driven Programming"
	while(true)
	{
		// Callback Functions
		callback();
	}
}

