run: compile
	./SortedList

compile: SortedList.cpp Student.cpp SortedListDr.cpp
	g++ -Wall -std=c++11 -pedantic-errors -o SortedList SortedList.cpp Student.cpp SortedListDr.cpp

clean:
	rm SortedList
