#include "../Headers/Notas.hpp"

Notas::Notas(){}
void Notas::AdicionaNota(double Nota){
  NotasAlunos.push_back(Nota);
}
void Notas::ModificaNota(double NovaNota,int indexNota){
  //fico devendo acabar esse, TENHO Q LER DOCUMENTACAO DA VECTOR
}
void Notas::ListaNotas(){
  if(NotasAlunos.size()>0){
  cout<<"--Inicio de notas do Aluno--"<<endl;
  for(unsigned int k=0;k<NotasAlunos.size();k++){
    cout<<"Nota "<<k+1<<":"<<NotasAlunos.at(k)<<endl;
  }cout<<"--Fim de notas do Aluno--"<<endl;}
  else{
    cout<<"Nao ha notas cadastradas!"<<endl;
  }
}
