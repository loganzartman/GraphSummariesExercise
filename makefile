CC = gcc -std=c99 -O3
objects = summaries.o graph.o

summaries: $(objects)
	$(CC) -o summaries $(objects)

$(objects): summaries.h graph.h

.PHONY: clean
clean:
	rm summaries summaries.exe $(objects)