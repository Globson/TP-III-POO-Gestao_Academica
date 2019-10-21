all: main.cpp Sources/Professor.cpp Sources/Aluno.cpp
	g++ main.cpp -o EXEC Sources/Professor.cpp Sources/Aluno.cpp

run: EXEC
	./EXEC

clear: EXEC
	rm EXEC
