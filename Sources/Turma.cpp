#include "../Headers/Turma.hpp"

Turma::Turma(Professor* profResp, int Codigo, int Ano){
  //ProfessorResponsavel.push_back(&profResp);
  ProfessorResponsavel = profResp;
  this->Codigo = Codigo;
  this->Ano = Ano;
}
void Turma::AdicionaAluno(Aluno* aluno){
  Alunos.push_back(aluno);
}
bool Turma::ImprimeAlunos(){
  if(Alunos.size()>0){
  cout<<"--Inicio de lista de alunos--"<<endl;
  for(unsigned int k=0;k<Alunos.size();k++){
      cout<<"--------------------Aluno:"<<k+1<<"----------------------------"<<endl;
      cout<<"Nome: "<<Alunos.at(k)->Get_Nome()<<endl;
      cout<<"Matricula: "<<Alunos.at(k)->GetMatricula()<<endl;
      cout<<"Data Nascimento: "<<Alunos.at(k)->Get_DataNasc()<<endl;
      cout<<"Nome da mae: "<<Alunos.at(k)->Get_NomeMae()<<endl;
      cout<<"Nome do pai: "<<Alunos.at(k)->Get_NomePai()<<endl;
      cout<<"Endereco: "<<Alunos.at(k)->Get_Endereco()<<endl;
      cout<<"-------------------------------------------------------"<<endl;
  }
  cout<<"--Fim da lista de alunos--"<<endl;}
  else{
    cout<<"Nao ha alunos cadastrados na turma!"<<endl;
    return false;
  }
  return true;
}
void Turma::ImprimeProfessor(){
  //cout<<"O professor responsvel é: "<<ProfessorResponsavel.at(0).Get_Nome()<<endl<<"Da Area de: "<< ProfessorResponsavel.at(0).Get_Area()<<endl;
  cout<<"O professor responsavel é: "<<ProfessorResponsavel->Get_Nome()<<endl<<"Da Area de: "<< ProfessorResponsavel->Get_Area()<<endl;
}
string Turma::GetProfessor(){
  return ProfessorResponsavel->Get_Nome();
}
int Turma::GetAno(){
  return Ano;
}
int Turma::GetCodigo(){
  return Codigo;
}
void Turma::AdicionaNotas(){
  if(NotasAlunos.size()>0){
    int a=0;
    cout<<"Erro! As notas da turma já foram adicionadas! Deseja apagar e readicionar as notas da turma?"<<endl<<"\t1-Sim"<<endl<<"\t2-Nao"<<endl<<"Entre:";;
    while(a!=1 && a!=2){
      
      cin>>a;
      if(a!=1 && a!=2){
        cout<<"Entrada inválida!"<<endl;
      }
    }
    if(a==1){
      NotasAlunos.clear();
    }
    else{
      cout<<"Adicionamento de notas cancelado!"<<endl;
      return;
    }
  }
  int trava,TemLetra;
  double notatemp;
  Notas *NotaTemp;
  stringstream ss;
  string NotaString, OpcaoString;
  for(unsigned int i=0;i<Alunos.size();i++){
    NotaTemp = new Notas();
    while(true){
      trava=0;
      TemLetra=-1;
      while (TemLetra!=0)
      { 
        cout<<"Entre com a nota do aluno de matricula "<<Alunos.at(i)->GetMatricula()<< ": ";
        cin>>NotaString;
        TemLetra=0;
        for (int i = 0; i < NotaString.size(); i++)
        {
          if(isalpha(NotaString[i])){
            TemLetra++;
          }
        }
      }
      ss << NotaString;
      ss >> notatemp;
      ss.clear();
      
      NotaTemp->AdicionaNota(notatemp);
      while(trava!=1 && trava!=2){
        TemLetra=-1;
        while (TemLetra!=0)
        { 
          cout<<"Deseja entrar com mais notas desse mesmo aluno?"<<endl<<"\t1-Sim"<<endl<<"\t2-Nao"<<endl<<"Entre:";
          cin>>OpcaoString;
          TemLetra=0;
          for (int i = 0; i < OpcaoString.size(); i++)
          {
            if(isalpha(OpcaoString[i])){
              TemLetra++;
            }
          }
        }
        ss << OpcaoString;
        ss >> trava;
        ss.clear();
        
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
  if(Alunos.size()==0){
    cout<<"Erro! Nenhum aluno cadastrado!"<<endl;
  }else{
    cout<<"Nota(s) adicionada(s) com sucesso!"<<endl;
  }

}
void Turma::Imprime_Boletim(int indexAluno){
  unsigned int index = indexAluno;
  if(index>=0 && index<NotasAlunos.size()){
    cout<<"\t---Boletim do aluno---"<<endl;
    cout<<"Nome: "<<Alunos.at(index)->Get_Nome()<<endl;
    cout<<"Matricula: "<<Alunos.at(index)->GetMatricula()<<endl;
    NotasAlunos.at(index).ListaNotas();
    NotasAlunos.at(index).ImprimeMediaNotas();
    cout<<"\t---Fim do Boletim---"<<endl;
    return;
  }
  if(NotasAlunos.size()==0){
    cout<<"Erro! Nenhuma nota cadastrada!"<<endl;
    return;
  }
  if(index>=NotasAlunos.size()){
    cout<<"Erro! Este aluno nao possui notas cadastradas!"<<endl;
    return;
  }
}
bool Turma::AlunoPresente(int Matricula){
  bool Verifica = false;
  for(unsigned int k=0;k<Alunos.size();k++){
    if(Alunos.at(k)->GetMatricula() == Matricula){
      Verifica = true;
    }
  }
  return Verifica;
}
