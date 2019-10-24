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
  int ContMatricula;
  int CodigoTurma;
  std::vector<Professor> Professores;
  std::vector<Aluno> Alunos;
  std::vector<Turma> Turmas;
public:  //Nenhuma deve ter parametro, para poder ser totalmente interativo apartir desse nivel
  Escola();
  void AdicionaProfessor();
  void AdicionaAluno();
  void CriaTurma();
  void AdicionaAlunoEmTurma();
  void AdicionaNota();
  void ImprimeBoletim();
  void ImprimeProfessores();
  void ImprimeAlunos();
  void ImprimeTurmas();
  void ImprimeAlunosDeTurma();
};
#endif
