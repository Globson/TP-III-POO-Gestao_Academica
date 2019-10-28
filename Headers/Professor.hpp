#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP
#include <iostream>
using namespace std;

class Professor{
private:
  string Nome;
  string Endereco;
  string Area;
  double SalarioPHora;
public:
  Professor(string Nome); //Vamos ter q mudar
  void Set_Area(string area);
  void Set_Endereco(string endereco);
  bool Set_Salario(double Salario);
  void ModificaNome(string Nome);
  string Get_Nome();
  string Get_Endereco();
  string Get_Area();
  double Get_Salario();
};

#endif
