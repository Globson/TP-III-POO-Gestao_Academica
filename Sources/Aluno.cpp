#include "../Headers/Aluno.hpp"

Aluno::Aluno(string Nome){
  this->Nome = Nome;
}
void Aluno::ModificaNome(string Nome){
  this->Nome = Nome;
}
void Aluno::Set_DataNasc(string DataNasc){
  this->DataNasc = DataNasc;
}
void Aluno::Set_NumMatricula(int NumMatricula){
  this->N_Matricula = NumMatricula;
}
void Aluno::Set_NomePais(string nomepai,string nomemae){
  this->NomePai = nomepai;
  this->NomeMae = nomemae;
}
void Aluno::Set_Endereco(string endereco){
  this->Endereco = endereco;
}
int Aluno::GetMatricula(){
  return N_Matricula;
}
string Aluno::Get_NomeMae(){
  return NomeMae;
}
string Aluno::Get_NomePai(){
  return NomePai;
}
string Aluno::Get_Nome(){
  return Nome;
}
string Aluno::Get_Endereco(){
  return Endereco;
}
string Aluno::Get_DataNasc(){
  return DataNasc;
}
