all: who-dun-it

who-dun-it: who-dun-it.c names.o keyphrase.o
	gcc -g -o $@ $^

names.o: names.c names.h
	gcc -o $@ -c $<

keyphrase.o: keyphrase.c keyphrase.h
	gcc -g -o $@ -c $<

clean:
	rm -rf *.o *.dSYM who-dun-it

zip: clean all
	zip who-dun-it.zip who-dun-it
