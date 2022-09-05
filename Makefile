CC=g++

CFLAGS=-Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wmissing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=64000 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -D_DEBUG -D_EJUDGE_CLIENT_SIDE

all: oneg_sort.exe

oneg_sort.exe: main.o mergesort.o read_lines.o print_lines.o calc_file_len.o
	$(CC) $(CFLAGS) main.o mergesort.o read_lines.o print_lines.o calc_file_len.o -o oneg_sort.exe

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -c

mergesort.o: mergesort.cpp
	$(CC) $(CFLAGS) mergesort.cpp -c

print_lines.o: print_lines.cpp
	$(CC) $(CFLAGS) print_lines.cpp -c

read_lines.o: read_lines.cpp
	$(CC) $(CFLAGS) read_lines.cpp -c

calc_file_len.o: calc_file_len.cpp
	$(CC) $(CFLAGS) calc_file_len.cpp -c

clean:
	rm -rf *.o *.exe* 

.PHONY: clean