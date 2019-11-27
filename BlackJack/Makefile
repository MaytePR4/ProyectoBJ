blackjack.o: blackjack.c
	gcc blackjack.c -c
main.o: main.c
	gcc main.c -c

a.out: main.o blackjack.o
	gcc main.o blackjack.o

run: a.out
	./a.out

clean:
	rm -f a.out main.o blackjack.o
