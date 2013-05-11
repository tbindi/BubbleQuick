a.out : sort1.o timer_nrp.o makefile
	gcc -g sort1.o timer_nrp.o

sort1.o : sort1.c
	gcc -g -c sort1.c

timer_nrp.o: timer_nrp.c timer_nrp.h
	gcc -g -c timer_nrp.c

profile:
	make a.out
	for i in 10000 20000 30000 40000 50000; do ./a.out "$$i" ;done 
plot:
	make profile
	gnuplot sort1.gnu
clean:
	rm -f a.out *ata.txt *.o *.jpg *.aux *.log *.pdf
report : sourcefile.tex
	make clean
	make plot
	pdflatex sourcefile.tex
	evince sourcefile.pdf
   
