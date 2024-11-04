DeleteXthNodeFromListEnd: DeleteXthNodeFromListEnd.o
	g++ -g -o DeleteXthNodeFromListEnd.exe DeleteXthNodeFromListEnd.o -pthread    

DeleteXthNodeFromListEnd.o: DeleteXthNodeFromListEnd/DeleteXthNodeFromListEnd.cpp
	g++ -g  -c -pthread DeleteXthNodeFromListEnd/DeleteXthNodeFromListEnd.cpp
