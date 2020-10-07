CXX=g++
CXXFLAGS=-std=c++17 -pedantic -Wall -Wextra -Werror


solution: main.cpp radix.h record.h vector.h
	$(CXX) $(CXXFLAGS) $< -o $@
	
bench: bench.cpp radix.h record.h vector.h
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f solution bench
	
