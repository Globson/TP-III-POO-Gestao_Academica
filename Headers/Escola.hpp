#ifndef ESCOLA_HPP
#define ESCOLA_HPP
#include <iostream>
#include <ctime>
#include <vector>
#include "Aluno.hpp"
#include "Professor.hpp"
#include "Turma.hpp"
#include "Notas.hpp"
using namespace std;

class Escola{
private:
  bool ProfessorSetado = false;
  std::vector<Professor> Professores;
  std::vector<Aluno> Alunos;
  std::vector<Turma> Turmas;
public:  //Nenhuma deve ter parametro, para poder ser totalmente interativo apartir desse nivel
  bool AdicionaProfessor();
  void AdicionaAluno();
  void AdicionaAlunosEmTurma();
  void AdicionaProfEmTurma();
  void AdicionaNota();
  void ImprimeBoletim();
};
#endif
