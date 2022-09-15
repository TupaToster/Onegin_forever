CC=g++

CFLAGS=-Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wmissing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=64000 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -D_DEBUG -D_EJUDGE_CLIENT_SIDE

all:Onegin_sort.exe

Onegin_sort.exe: main.o get_len.o read_text.o buffer.o
	$(CC) main.o get_len.o read_text.o buffer.o -o Onegin_sort.exe $(CFLAGS)

*.o: *.cpp
	$(CC) *.cpp -c $(CFLAGS)

clean:
	rm -rf *.o *.exe*
	clear

.PHONY: clean