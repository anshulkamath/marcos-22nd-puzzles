all: systemic-hell

systemic-hell: systemic-hell.c puzzle-1.o puzzle-2.o
	gcc -o $@ $^

puzzle-1.o: puzzle-1.c puzzle-1.h
	gcc -o $@ -c $<

# give minimal debug symbols
puzzle-2.o: puzzle-2.c puzzle-2.h
	gcc -g2 -o $@ -c $<

clean:
	rm -rf *.o *.dYSM systemic-hell
