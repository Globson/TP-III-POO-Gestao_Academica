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
  if(Alunos.size()>0){
  cout<<"--Inicio de lista de alunos--"<<endl;
  for(unsigned int k=0;k<Alunos.size();k++){
      cout<<"--------------------Aluno:"<<k+1<<"----------------------------"<<endl;
      cout<<"Nome: "<<Alunos.at(k).Get_Nome()<<endl;
      cout<<"Matricula: "<<Alunos.at(k).GetMatricula()<<endl;
      cout<<"Data Nascimento: "<<Alunos.at(k).Get_DataNasc()<<endl;
      cout<<"Nome da mae: "<<Alunos.at(k).Get_NomeMae()<<endl;
      cout<<"Nome do pai: "<<Alunos.at(k).Get_NomePai()<<endl;
      cout<<"Endereco: "<<Alunos.at(k).Get_Endereco()<<endl;
      cout<<"-------------------------------------------------------"<<endl;
  }
  cout<<"--Fim da lista de alunos--"<<endl;}
  else{
    cout<<"Nao ha alunos cadastrados na turma!"<<endl;
  }

}
void Turma::ImprimeProfessor(){
  cout<<"O professor responsvel é: "<<ProfessorResponsavel.at(0).Get_Nome()<<endl<<"Da Area de: "<< ProfessorResponsavel.at(0).Get_Area()<<endl;
  //cout<<"O professor responsvel é: "<<ProfessorResponsavel->Get_Nome()<<endl<<"Da Area de: "<< ProfessorResponsavel->Get_Area()<<endl;
}
string Turma::GetProfessor(){
  return ProfessorResponsavel.at(0).Get_Nome();
}
int Turma::GetAno(){
  return Ano;
}
int Turma::GetCodigo(){
  return Codigo;
}
void Turma::AdicionaNotas(){
  int trava;
  double notatemp;
  Notas *NotaTemp;
  for(unsigned int i=0;i<Alunos.size();i++){
    NotaTemp = new Notas();
    while(true){
      trava=0;
      cout<<"Entre com a nota do aluno de matricula "<<Alunos.at(i).GetMatricula()<< ": ";
      cin>>notatemp;
      NotaTemp->AdicionaNota(notatemp);
      while(trava!=1 && trava!=2){
        cout<<"Deseja entrar com mais notas desse mesmo aluno?"<<endl<<"\t1-Sim"<<endl<<"\t2-Nao"<<endl<<"Entre:";
        cin>>trava;
        if(trava!=1 && trava!=2){
          cout<<"Entrada invalida!"<<endl;
        }
      }
      if(trava==2){
        break;
      }
    }
    NotasAlunos.push_back(*NotaTemp);
  }
}
void Turma::Imprime_Boletim(int indexAluno){
  unsigned int index = indexAluno;
  if(index>=0 && index<=NotasAlunos.size()){
    cout<<"\t---Boletim do aluno---"<<endl;
    cout<<"Nome: "<<Alunos.at(index).Get_Nome()<<endl;
    cout<<"Matricula: "<<Alunos.at(index).GetMatricula()<<endl;
    NotasAlunos.at(index).ListaNotas();
    NotasAlunos.at(index).ImprimeMediaNotas();
  }
}

int Turma::SizeAlunos(){
  int a = Alunos.size();
  return a;
}
int Turma::MatriculaAlunoAt(int i){
  return Alunos.at(i).GetMatricula();
}
