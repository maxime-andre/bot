all: bot
bot: main.o connection.o
	g++ main.o connection.o -o bot
connection.o: connection.cpp connection.h
main.o: main.cpp

clean:
	rm -rf *.o
	rm -rf bot

debug:
	g++ main.cpp connection.cpp -o bot -ggdb
