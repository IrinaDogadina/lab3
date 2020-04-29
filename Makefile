
all: lab3
lab3: main_lab3.o add_lab3.o deleteANDsearch_lab3.o
	g++ -o lab3  main_lab3.o add_lab3.o deleteANDsearch_lab3.o
 
main_lab3.o: main_lab3.cpp
	g++ -c main_lab3.cpp
 
add_lab3.o: add_lab3.cpp
	g++ -c add_lab3.cpp
 
deleteANDsearch_lab3.o: deleteANDsearch_lab3.cpp
	g++ -c deleteANDsearch_lab3.cpp  
