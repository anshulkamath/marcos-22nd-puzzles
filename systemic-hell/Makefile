ARCH = arch -arm64

all: systemic-hell

# Directory targets
obj:
	@mkdir obj

systemic-hell: obj/systemic-hell.o obj/puzzle-1.o obj/puzzle-2.o obj/puzzle-3.o | obj
	$(ARCH) gcc -o $@ $^

obj/systemic-hell.o: systemic-hell.c | obj
	$(ARCH) gcc -o $@ -c $<

obj/puzzle-1.o: puzzle-1.c puzzle-1.h | obj
	$(ARCH) gcc -o $@ -c $<

# give minimal debug symbols
obj/puzzle-2.o: puzzle-2.c puzzle-2.h | obj
	$(ARCH) gcc -g2 -o $@ -c $<

obj/puzzle-3.o: puzzle-3.c puzzle-3.h | obj
	$(ARCH) gcc -g -o $@ -c $<

clean:
	rm -rf *.o *.dYSM systemic-hell *.zip
	@rm -rf obj

zip: ARCH = arch -x86_64
zip: systemic-hell
	@mkdir out
	@cp -r puzzle-3* Makefile-2 obj README.md docker-compose.yml out
	@mv out/Makefile-2 out/Makefile
	@zip -r out.zip out > /dev/null
	@rm -rf out
