#ifndef TURMA_HPP
#define TURMA_HPP
#include <iostream>
#include <ctime>
#include <vector>
#include <sstream>
#include "Aluno.hpp"
#include "Professor.hpp"
#include "Notas.hpp"
using namespace std;

class Turma{
private:
  //std::vector<Professor*> ProfessorResponsavel;
  Professor* ProfessorResponsavel;
  std::vector<Aluno*> Alunos;
  std::vector<Notas> NotasAlunos;
  int Ano;
  int Codigo;
  friend class Escola;
public:
  Turma(Professor* profResp, int Codigo, int Ano);
  void AdicionaAluno(Aluno* aluno);
  void AdicionaNotas();
  bool ImprimeAlunos();
  void ImprimeProfessor();
  int GetAno();
  int GetCodigo();
  string GetProfessor();
  void Imprime_Boletim(int indexAluno);
  bool AlunoPresente(int Matricula);
  //int SizeAlunos();
  //int MatriculaAlunoAt(int i);
};

#endif
