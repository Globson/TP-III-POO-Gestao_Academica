#include "../Headers/Escola.hpp"
void Escola::AdicionaProfessor(){
  string Nome,Area,Endereco;
  double salario;

  cout<<"Entre com o nome do professor:";
  getline(cin,Nome);

  cout<<"Entre com a area do professor:";
  getline(cin,Area);

  cout<<"Entre com o salario do professor:";
  cin>>salario;
  cin.ignore(1);
  cout<<"Entre com o endereco do professor:";
  getline(cin,Endereco);

  Professor ProfAux(Nome);
  ProfAux.Set_Area(Area);
  ProfAux.Set_Endereco(Endereco);
  ProfAux.Set_Salario(salario);
  Professores.push_back(ProfAux);
}
void Escola::AdicionaAluno(){
  string Nome,NomePai,NomeMae,DataNasc,Endereco;
  //int N_Matricula; A matricula sera criada apartir da propria classe escola//
  cout<<"Entre com o nome do aluno:";
  getline(cin,Nome);
  cout<<"Entre com o nome do pai do aluno:";
  getline(cin,NomePai);
  cout<<"Entre com o nome da mae do aluno:";
  getline(cin,NomeMae);
  cout<<"Entre com a data de nascimento do aluno:";
  getline(cin,DataNasc);
  cout<<"Entre com o endereco do aluno:";
  getline(cin,Endereco);

  Aluno AlunoAux(Nome);
  AlunoAux.Set_NomePais(NomePai,NomeMae);
  AlunoAux.Set_DataNasc(DataNasc);
  AlunoAux.Set_Endereco(Endereco);
  AlunoAux.Set_NumMatricula(ContMatricula);
  this->ContMatricula++;
  Alunos.push_back(AlunoAux);
}

void Escola::CriaTurma(){
  int indexprof,ano;
  if(Professores.size()>0){
    cout<<"Escolha um professor abaixo para ser responsavel pela turma:"<<endl;
  for(unsigned int k=0;k<Professores.size();k++){
    cout<<"Professor numero "<<k+1<<": "<<endl;
    cout<<"Nome: "<<Professores.at(k).Get_Nome()<<endl;
    cout<<"Area: "<<Professores.at(k).Get_Area()<<endl;
    cout<<"Salario: "<<Professores.at(k).Get_Salario()<<endl;
  }
  cout<<"Entre com o numero do professor escolhido:";
  cin>>indexprof;
}else{
  cout<<"Erro! Cadastre pelo menos um professor!";
  return;
}
cout<<"Entre com o ano da turma:";
cin>>ano;
Turma TurmaAux(Professores.at(indexprof-1),CodigoTurma,ano);
this->CodigoTurma++;
Turmas.push_back(TurmaAux);
}


void Escola::AdicionaAlunoEmTurma(){
  int Matricula,indexturma;
  bool Verifica = false;
  if(Turmas.size()>0){
    for(unsigned int k=0;k<Turmas.size();k++){
      cout<<"-----Turma "<<k<<"-----"<<endl;
      cout<<"Codigo da turma: "<<Turmas.at(k).GetCodigo()<<endl;
      cout<<"Ano da turma: "<<Turmas.at(k).GetAno()<<endl;
      cout<<"Professor responsavel pela turma: "<<Turmas.at(k).GetProfessor()<<endl;
      cout<<"----------------"<<endl;
    }
  cout<<"Entre com o numero da turma que deseja adicionar alunos:";
  cin>>indexturma;
  }
  else{
    cout<<"Erro! Crie pelo menos uma turma!"<<endl;
    return;
  }
  if(Alunos.size()>0){
    for(unsigned int i=0;i<Alunos.size();i++){
      cout<<"----------------Aluno---------------"<<endl;
      cout<<"Nome:"<<Alunos.at(i).Get_Nome()<<endl;
      cout<<"Matricula: "<<Alunos.at(i).GetMatricula()<<endl;
      cout<<"Endereco: "<<Alunos.at(i).Get_Endereco()<<endl;
      cout<<"------------------------------------"<<endl;
    }
  cout<<"Digite a matricula do aluno que deseja adicionar:";
  cin>>Matricula;
  for(unsigned int j=0;j<Alunos.size();j++){
    if(Alunos.at(j).GetMatricula() == Matricula){
      Turmas.at(indexturma).AdicionaAluno(Alunos.at(j));
      Verifica = true;
    }
  }
  if(!Verifica){
    cout<<"Aluno nao encontrado!"<<endl;
  }
  }
  else{
    cout<<"Erro! Nenhum aluno foi cadastrado!"<<endl;
    return;
  }
}


void Escola::AdicionaNota(){}
void Escola::ImprimeBoletim(){}

void Escola::ImprimeProfessores(){
  for(unsigned int k=0;k<Professores.size();k++){
    cout<<"Nome: "<<Professores.at(k).Get_Nome()<<endl;
    cout<<"Area: "<<Professores.at(k).Get_Area()<<endl;
    cout<<"Salario: "<<Professores.at(k).Get_Salario()<<endl;
    cout<<"Endereco: "<<Professores.at(k).Get_Endereco()<<endl;
  }
}

void Escola::ImprimeAlunos(){
  for(unsigned int k=0;k<Alunos.size();k++){
    cout<<"Nome:"<<Alunos.at(k).Get_Nome()<<endl;
    cout<<"Matricula: "<<Alunos.at(k).GetMatricula()<<endl;
    cout<<"Nome da mae: "<<Alunos.at(k).Get_NomeMae()<<endl;
    cout<<"Nome do pai: "<<Alunos.at(k).Get_NomePai()<<endl;
    cout<<"Data de Nascimento: "<<Alunos.at(k).Get_DataNasc()<<endl;
    cout<<"Endereco: "<<Alunos.at(k).Get_Endereco()<<endl;
  }
}

void Escola::ImprimeTurmas(){
  for(unsigned int k=0;k<Turmas.size();k++){
    cout<<"-----Turma "<<k<<"-----"<<endl;
    cout<<"Codigo da turma: "<<Turmas.at(k).GetCodigo()<<endl;
    cout<<"Ano da turma: "<<Turmas.at(k).GetAno()<<endl;
    cout<<"Professor responsavel pela turma: "<<Turmas.at(k).GetProfessor()<<endl;
    cout<<"----------------"<<endl;
  }
}
