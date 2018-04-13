all: wc bank

wc : wc.c wcfunc.c
	gcc -o wc wc.c wcfunc.c
bank : bank.c bankfunc.c
	gcc -o bank bank.c bankfunc.c
clean:
	rm -f bank wc

