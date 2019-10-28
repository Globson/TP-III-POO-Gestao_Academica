#include "../Headers/Notas.hpp"

Notas::Notas(){}
void Notas::AdicionaNota(double Nota){
  if(Nota>=0){
  NotasAlunos.push_back(Nota);}
}
void Notas::ListaNotas(){
  if(NotasAlunos.size()>0){
  cout<<"--Inicio de notas do Aluno--"<<endl;
  for(unsigned int k=0;k<NotasAlunos.size();k++){
    cout<<"Nota "<<k+1<<":  "<<NotasAlunos.at(k)<<endl;
  }cout<<"--Fim de notas do Aluno--"<<endl;}
  else{
    cout<<"Nao ha notas cadastradas!"<<endl;
  }
}

void Notas::ImprimeMediaNotas(){
  if(NotasAlunos.size()>0){
    double soma = 0;
    int tam = 0;
    for(unsigned int k=0;k<NotasAlunos.size();k++){
      soma+=NotasAlunos.at(k);
      tam++;
    }
    double Media = soma/tam;
    //double Media = soma; // caso nao precise dividir pela quantidade, comentar linha acima e descomentar essa
    if(Media>=60){
      cout<<"Media = "<<Media<<" -> APROVADO!"<<endl;
    }
    else{
      cout<<"Media = "<<Media<<" -> REPROVADO!"<<endl;
    }
  }
}
