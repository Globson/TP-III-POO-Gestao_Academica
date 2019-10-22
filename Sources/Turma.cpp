#include "../Headers/Turma.hpp"

Turma::Turma(Professor profResp, int Codigo, int Ano){
  ProfessorResponsavel.push_back(profResp);
  //ProfessorResponsavel = &profResp;
  this->Codigo = Codigo;
  this->Ano = Ano;
}
void Turma::AdicionaAluno(Aluno aluno){
  Alunos.push_back(aluno);
}
void Turma::ImprimeAlunos(){
  cout<<"--Inicio de lista de alunos--"<<endl;
  for(unsigned int k=0;k<Alunos.size();k++){
      cout<<"--------------------Aluno:"<<k+1<<"------------------------"<<endl;
      cout<<"Nome: "<<Alunos.at(k).Get_Nome()<<endl;
      cout<<"Matricula: "<<Alunos.at(k).GetMatricula()<<endl;
      cout<<"Data Nascimento: "<<Alunos.at(k).Get_DataNasc()<<endl;
      cout<<"Nome da mae: "<<Alunos.at(k).Get_NomeMae()<<endl;
      cout<<"Nome do pai: "<<Alunos.at(k).Get_NomePai()<<endl;
      cout<<"Endereco: "<<Alunos.at(k).Get_Endereco()<<endl;
      cout<<"-------------------------------------------------------"<<endl;
  }
  cout<<"--Fim da lista de alunos--"<<endl;

}
void Turma::ImprimeProfessor(){
  cout<<"O professor responsvel é: "<<ProfessorResponsavel.at(0).Get_Nome()<<endl<<"Da Area de: "<< ProfessorResponsavel.at(0).Get_Area()<<endl;
  //cout<<"O professor responsvel é: "<<ProfessorResponsavel->Get_Nome()<<endl<<"Da Area de: "<< ProfessorResponsavel->Get_Area()<<endl;
}
int Turma::GetAno(){
  return Ano;
}
int Turma::GetCodigo(){
  return Codigo;
}
