all: main.cpp Sources/Professor.cpp Sources/Aluno.cpp Sources/Turma.cpp Sources/Notas.cpp
	g++ main.cpp -o EXEC Sources/Professor.cpp Sources/Aluno.cpp Sources/Turma.cpp Sources/Notas.cpp

run: EXEC
	./EXEC

clear: EXEC
	rm EXEC
