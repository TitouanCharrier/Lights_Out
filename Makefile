main : main.c lib/geometrie_SDL2.c
	gcc -c lib/geometrie_SDL2.c -lSDL2 -lm	-o geometrie.o
	gcc main.c -o main geometrie.o -lSDL2 -lm -Wall
	rm geometrie.o
	./main
window : main.c
	x86_64-w64-mingw32-gcc main.c -o window.exe -I/usr/x86_64-w64-mingw32/include/SDL2 -lm -L/usr/x86_64-w64-mingw32 */*.c *.c
	echo "hello"
