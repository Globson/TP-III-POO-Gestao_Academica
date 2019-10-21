#include "../Headers/Aluno.hpp"

Aluno::Aluno(string Nome,string DataNasc,int Num){
  this->Nome = Nome;
  this->DataNasc = DataNasc;
  this->N_Matricula = Num;
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
