all: main.o stringset.o
	g++ -o pa2 main.o stringset.o

main.o: main.cpp stringset.h
	g++ -c main.cpp

stringset.o: stringset.cpp stringset.h
	g++ -c stringset.cpp

clean:
	rm main.o stringset.o pa2 output_*.txt
