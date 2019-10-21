#ifndef ALUNO_HPP
#define ALUNO_HPP
#include <iostream>
#include <ctime>
using namespace std;

class Aluno{
private:
  string Nome;
  int N_Matricula;
  string NomePai;
  string NomeMae;
  string DataNasc;
  string Endereco;
public:
  Aluno(string Nome,string DataNasc,int Num); //Matriculas serao incrementadas//
  virtual ~Aluno();
  void Set_NomePais(string nomepai,string nomemae);
  void Set_Endereco(string endereco);
  int GetMatricula();
  string Get_NomeMae();
  string Get_NomePai();
  string Get_Nome();
  string Get_Endereco();
  string Get_DataNasc();
};
#endif
