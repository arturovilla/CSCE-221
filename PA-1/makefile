all: test

test: Stress_ball.o collection.o collection_test.o
    c++ -std=c++11 Stress_ball.o collection.o collection_test.o -o test

Stress_ball.o: Stress_ball.cpp Stress_ball.h
    c++ -std=c++11 -c Stress_ball.cpp

collection.o: collection.cpp Collection.h
    c++ -std=c++11 -c collection.cpp

collection_test.o collection_test.cpp
    c++ -std=c++11 -c collection_test.cpp

clean:
	rm -f *.o test
