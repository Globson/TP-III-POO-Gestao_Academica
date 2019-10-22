#ifndef NOTAS_HPP
#define NOTAS_HPP
#include <iostream>
#include <ctime>
#include <vector>
#include "Aluno.hpp"
using namespace std;

class Notas{
private:
  std::vector<double> NotasAlunos;
public:
  Notas();
  void AdicionaNota(double Nota);
  void ModificaNota(double NovaNota,int indexNota);
  void ListaNotas();

};

#endif
