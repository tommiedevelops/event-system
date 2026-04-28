CC = gcc
CFLAGS = -g -Wall -O0 -std=c99
LDFLAGS = -lpthread
SOURCES = core/*.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = program

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : clean

clean:
	@rm -f $(TARGET) $(OBJECTS)

