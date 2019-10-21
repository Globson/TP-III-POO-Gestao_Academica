#include "../Headers/Professor.hpp"
Professor::Professor(string Nome,string Area){
  this->Nome = Nome;
  this->Area = Area;
}
void Professor::Set_Endereco(string endereco){
  this->Endereco = endereco;
}
bool Professor::Set_Salario(double Salario){
  if(Salario>0){
    this->SalarioPHora = Salario;
    return true;
  }
  return false;
}
string Professor::Get_Nome(){
  return Nome;
}
string Professor::Get_Endereco(){
  return Endereco;
}
string Professor::Get_Area(){
  return Area;
}
double Professor::Get_Salario(){
  return SalarioPHora;
}
