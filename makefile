all: main.cpp Sources/Professor.cpp Sources/Aluno.cpp Sources/Turma.cpp
	g++ main.cpp -o EXEC Sources/Professor.cpp Sources/Aluno.cpp Sources/Turma.cpp

run: EXEC
	./EXEC

clear: EXEC
	rm EXEC
