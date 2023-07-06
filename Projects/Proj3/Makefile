CXX = g++
CXXFLAGS = -Wall

proj3:	Sequencer.o Strand.o proj3.cpp
	$(CXX) $(CXXFLAGS) Sequencer.o Strand.o proj3.cpp -o proj3

Strand.o:	Sequencer.o Strand.cpp Strand.h
	$(CXX) $(CXXFLAGS) -c Strand.cpp

Sequencer.o:	Sequencer.h Sequencer.cpp
	$(CXX) $(CXXFLAGS) -c Sequencer.cpp

clean:
	rm *.o*
	rm *~

run:
	./proj3
