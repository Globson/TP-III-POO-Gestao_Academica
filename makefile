all: main.cpp Sources/Professor.cpp Sources/Aluno.cpp Sources/Turma.cpp Sources/Notas.cpp Sources/Escola.cpp
	g++ main.cpp -o EXEC Sources/Professor.cpp Sources/Aluno.cpp Sources/Turma.cpp Sources/Notas.cpp Sources/Escola.cpp

run: EXEC
	./EXEC

clear: EXEC
	rm EXEC
