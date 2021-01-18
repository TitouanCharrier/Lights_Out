main : main.c lib/geometrie_SDL2.c lib/SDL2_menu.c src/mainfunc.c
	gcc -c lib/geometrie_SDL2.c -lSDL2 -lm -o geometrie.o
	gcc -c src/mainfunc.c -lSDL2 -lSDL2_ttf -o mainfunc.o
	gcc -c lib/SDL2_menu.c -lSDL2 -lSDL2_ttf -lm -o menu.o
	gcc main.c -o main geometrie.o menu.o mainfunc.o -lSDL2 -lSDL2_ttf -lm -Wall
	rm geometrie.o menu.o mainfunc.o
	./main
window : main.c
	x86_64-w64-mingw32-gcc main.c -o window.exe -I/usr/x86_64-w64-mingw32/include/SDL2 -lm -L/usr/x86_64-w64-mingw32 */*.c *.c
	echo "hello"
