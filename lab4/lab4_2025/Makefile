CXX = g++
CXXFLAGS = -std=c++11 -Iinclude -Wall -Wextra -g  

SRC = src/*.cpp

main: $(SRC)
	$(CXX) $(CXXFLAGS) -o main $(SRC) 
	valgrind --leak-check=full --show-leak-kinds=all ./main

clean:
	rm -f main