#include "../Headers/Professor.hpp"
Professor::Professor(string Nome){
  this->Nome = Nome;
}
void Professor::ModificaNome(string Nome){
  this->Nome = Nome;
}
void Professor::Set_Area(string area){
  this->Area = area;
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
