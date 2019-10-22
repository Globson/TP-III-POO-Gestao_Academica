#ifndef TURMA_HPP
#define TURMA_HPP
#include <iostream>
#include <ctime>
#include <vector>
#include "Aluno.hpp"
#include "Professor.hpp"
using namespace std;

class Turma{
private:
  std::vector<Professor> ProfessorResponsavel;
  //Professor* ProfessorResponsavel;
  std::vector<Aluno> Alunos;
  int Ano;
  int Codigo;
public:
  Turma(Professor profResp, int Codigo, int Ano);
  //virtual ~Turma();
  void AdicionaAluno(Aluno aluno);
  void ImprimeAlunos();
  void ImprimeProfessor();
  int GetAno();
  int GetCodigo();
};

#endif
