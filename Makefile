all:
	g++ main.c hero.c position.c key.c -o sg_run -lSDL2
clean:
	rm -f 7g

