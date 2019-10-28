#ifndef ESCOLA_HPP
#define ESCOLA_HPP
#include <iostream>
#include <ctime>
#include <vector>
#include <sstream>
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
public:
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
  void ModificaProfessor();
  void ModificaAluno();
};

int Menu_Principal();
int Menu_Aluno();
int Menu_Professor();
int Menu_Turma();
int Menu_Finalizar();
#endif
