#include "../Headers/Escola.hpp"
Escola::Escola(){
  this->ContMatricula = 3000; // numero de matricula inicial
  this->CodigoTurma = 100; //Codigo de turma inicial
}
void Escola::AdicionaProfessor(){
  system("clear");
  string Nome,Area,Endereco;
  double salario;

  cout<<"Entre com o nome do professor:";
  cin.ignore(1);
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
  cout<<"Professor adicionado com sucesso!"<<endl;
  system("read -p 'Pressione Enter para continuar...' var");
}
void Escola::AdicionaAluno(){
  system("clear");
  string Nome,NomePai,NomeMae,DataNasc,Endereco;
  //int N_Matricula; A matricula sera criada apartir da propria classe escola//
  cout<<"Entre com o nome do aluno:";
  cin.ignore(1);
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
  cout<<"Aluno Adicionado com sucesso!"<<endl;
  system("read -p 'Pressione Enter para continuar...' var");
}

void Escola::CriaTurma(){
  system("clear");
  int indexprof,ano,SizeProfs;
  if(Professores.size()>0){
    cout<<"Escolha um professor abaixo para ser responsavel pela turma:"<<endl;
  for(unsigned int k=0;k<Professores.size();k++){
    cout<<"->Professor numero "<<k+1<<": "<<endl;
    cout<<"Nome: "<<Professores.at(k).Get_Nome()<<endl;
    cout<<"Area: "<<Professores.at(k).Get_Area()<<endl;
    cout<<"Salario: "<<Professores.at(k).Get_Salario()<<endl;
    cout<<"-----------------------------------------"<<endl;
  }
  cout<<"Entre com o numero do professor escolhido:";
  cin>>indexprof;
  SizeProfs = Professores.size();
  if((indexprof-1)<0 || indexprof>SizeProfs){
    cout<<"Erro! Professor nao existe!"<<endl;
    return;
  }
}else{
  cout<<"Erro! Cadastre pelo menos um professor!";
  return;
}
cout<<"Entre com o ano da turma:";
cin>>ano;
Turma TurmaAux(&Professores.at(indexprof-1),CodigoTurma,ano);
this->CodigoTurma++;
Turmas.push_back(TurmaAux);
cout<<"Turma criada com sucesso!"<<endl;
system("read -p 'Pressione Enter para continuar...' var");
}


void Escola::AdicionaAlunoEmTurma(){
  system("clear");
  int Matricula,Codigoturma,indexturma;
  bool Verifica = false,Verifica2 = false;
  if(Turmas.size()>0){
    for(unsigned int k=0;k<Turmas.size();k++){
      cout<<"-----Turma-----"<<endl;
      cout<<"Codigo da turma: "<<Turmas.at(k).GetCodigo()<<endl;
      cout<<"Ano da turma: "<<Turmas.at(k).GetAno()<<endl;
      cout<<"Professor responsavel pela turma: "<<Turmas.at(k).GetProfessor()<<endl;
      cout<<"----------------"<<endl;
    }
  cout<<"Entre com o codigo da turma que deseja adicionar alunos:";
  cin>>Codigoturma;
  for(unsigned int x=0;x<Turmas.size();x++){
    if(Codigoturma == Turmas.at(x).GetCodigo()){
      indexturma = x;
      Verifica2 = true;
      cout<<"Turma selecionada com sucesso!"<<endl;
    }
  }
  if(!Verifica2){
    cout<<"Erro! Turma nao encontrada!"<<endl;
    return;
  }

  }
  else{
    cout<<"Erro! Crie pelo menos uma turma!"<<endl;
    return;
  }
  if(Alunos.size()>0){
    for(unsigned int i=0;i<Alunos.size();i++){
      cout<<"---------------Aluno "<<i+1<<" -----------------"<<endl;
      cout<<"Nome:"<<Alunos.at(i).Get_Nome()<<endl;
      cout<<"Matricula: "<<Alunos.at(i).GetMatricula()<<endl;
      cout<<"Endereco: "<<Alunos.at(i).Get_Endereco()<<endl;
      cout<<"----------------------------------------"<<endl;
    }
    cout<<"Digite a matricula do aluno que deseja adicionar:";
    cin>>Matricula;
    for(unsigned int j=0;j<Alunos.size();j++){
      if(Alunos.at(j).GetMatricula() == Matricula){
        Verifica = true;
        if(!Turmas.at(indexturma).AlunoPresente(Matricula)){
          Turmas.at(indexturma).AdicionaAluno(&Alunos.at(j));
          cout<<"Aluno adicionado com sucesso a turma!"<<endl;
        }
        else{
          cout<<"Erro!Aluno ja presente na turma!"<<endl;
        }
      }
    }
    if(!Verifica){
      cout<<"Erro!Aluno nao encontrado!"<<endl;
    }
  }
  else{
    cout<<"Erro! Nenhum aluno foi cadastrado!"<<endl;
    return;
  }
  system("read -p 'Pressione Enter para continuar...' var");
}


void Escola::AdicionaNota(){
  system("clear");
  int Codigoturma,indexturma;
  bool Verifica = false;
  if(Turmas.size()>0){
    for(unsigned int k=0;k<Turmas.size();k++){
      cout<<"-----Turma-----"<<endl;
      cout<<"Codigo da turma: "<<Turmas.at(k).GetCodigo()<<endl;
      cout<<"Ano da turma: "<<Turmas.at(k).GetAno()<<endl;
      cout<<"Professor responsavel pela turma: "<<Turmas.at(k).GetProfessor()<<endl;
      cout<<"----------------"<<endl;
    }
    cout<<"Entre com o codigo da turma que deseja adicionar notas dos alunos:";
    cin>>Codigoturma;
    for(unsigned int x=0;x<Turmas.size();x++){
      if(Codigoturma == Turmas.at(x).GetCodigo()){
        indexturma = x;
        Verifica = true;
        cout<<"Turma selecionada com sucesso!"<<endl;
      }
    }
    if(!Verifica){
      cout<<"Erro! Turma nao encontrada!"<<endl;
      return;
    }
    Turmas.at(indexturma).AdicionaNotas();
  }
  system("read -p 'Pressione Enter para continuar...' var");
}


void Escola::ImprimeBoletim(){
  system("clear");
  int Codigoturma,indexturma,indexaluno,MatriculaAluno;
  bool Verifica = false,Verifica2 = false;
  if(Turmas.size()>0){
    for(unsigned int k=0;k<Turmas.size();k++){
      cout<<"-----Turma-----"<<endl;
      cout<<"Codigo da turma: "<<Turmas.at(k).GetCodigo()<<endl;
      cout<<"Ano da turma: "<<Turmas.at(k).GetAno()<<endl;
      cout<<"Professor responsavel pela turma: "<<Turmas.at(k).GetProfessor()<<endl;
      cout<<"----------------"<<endl;
    }
    cout<<"Entre com o codigo da turma que deseja imprimir o boletim do aluno:";
    cin>>Codigoturma;
    for(unsigned int x=0;x<Turmas.size();x++){
      if(Codigoturma == Turmas.at(x).GetCodigo()){
        indexturma = x;
        Verifica = true;
        cout<<"Turma selecionada com sucesso!"<<endl;
      }
    }
    if(!Verifica){
      cout<<"Erro! Turma nao encontrada!"<<endl;
      return;
    }
    Turmas.at(indexturma).ImprimeAlunos();
    cout<<"Entre com a matricula do aluno que quer imprimir o boletim:";
    cin>>MatriculaAluno;
    for(unsigned int x=0;x<Turmas.at(indexturma).Alunos.size();x++){
      if(MatriculaAluno == Turmas.at(indexturma).Alunos.at(x)->GetMatricula()){
        Verifica2 = true;
        indexaluno = x;
      }
    }
    if(!Verifica2){
      cout<<"Erro! Aluno nao cadastrado em turma escolhida!"<<endl;
    }
    Turmas.at(indexturma).Imprime_Boletim(indexaluno);

  }
  else{
    cout<<"Erro! Crie pelo menos uma turma!"<<endl;
    return;
  }
  system("read -p 'Pressione Enter para continuar...' var");
}



void Escola::ImprimeProfessores(){
  system("clear");
  for(unsigned int k=0;k<Professores.size();k++){
    cout<<"------------Professor "<<k+1<<" --------------"<<endl;
    cout<<"Nome: "<<Professores.at(k).Get_Nome()<<endl;
    cout<<"Area: "<<Professores.at(k).Get_Area()<<endl;
    cout<<"Salario: "<<Professores.at(k).Get_Salario()<<endl;
    cout<<"Endereco: "<<Professores.at(k).Get_Endereco()<<endl;
    cout<<"--------------------------------------"<<endl;
  }
  system("read -p 'Pressione Enter para continuar...' var");
}

void Escola::ImprimeAlunos(){
  system("clear");
  for(unsigned int k=0;k<Alunos.size();k++){
    cout<<"---------------Aluno "<<k+1<<" -----------------"<<endl;
    cout<<"Nome:"<<Alunos.at(k).Get_Nome()<<endl;
    cout<<"Matricula: "<<Alunos.at(k).GetMatricula()<<endl;
    cout<<"Nome da mae: "<<Alunos.at(k).Get_NomeMae()<<endl;
    cout<<"Nome do pai: "<<Alunos.at(k).Get_NomePai()<<endl;
    cout<<"Data de Nascimento: "<<Alunos.at(k).Get_DataNasc()<<endl;
    cout<<"Endereco: "<<Alunos.at(k).Get_Endereco()<<endl;
    cout<<"----------------------------------------"<<endl;
  }
  system("read -p 'Pressione Enter para continuar...' var");
}

void Escola::ImprimeTurmas(){
  system("clear");
  for(unsigned int k=0;k<Turmas.size();k++){
    cout<<"-----Turma "<<k+1<<" -----"<<endl;
    cout<<"Codigo da turma: "<<Turmas.at(k).GetCodigo()<<endl;
    cout<<"Ano da turma: "<<Turmas.at(k).GetAno()<<endl;
    cout<<"Professor responsavel pela turma: "<<Turmas.at(k).GetProfessor()<<endl;
    cout<<"------------------"<<endl;
  }
  system("read -p 'Pressione Enter para continuar...' var");
}
void Escola::ImprimeAlunosDeTurma(){
  system("clear");
  int Codigoturma,indexturma;
  bool Verifica = false;
  if(Turmas.size()>0){
    for(unsigned int k=0;k<Turmas.size();k++){
      cout<<"-----Turma-----"<<endl;
      cout<<"Codigo da turma: "<<Turmas.at(k).GetCodigo()<<endl;
      cout<<"Ano da turma: "<<Turmas.at(k).GetAno()<<endl;
      cout<<"Professor responsavel pela turma: "<<Turmas.at(k).GetProfessor()<<endl;
      cout<<"----------------"<<endl;
    }
    cout<<"Entre com o codigo da turma que deseja imprimir os alunos:";
    cin>>Codigoturma;
    for(unsigned int x=0;x<Turmas.size();x++){
      if(Codigoturma == Turmas.at(x).GetCodigo()){
        indexturma = x;
        Verifica = true;
        cout<<"Turma selecionada com sucesso!"<<endl;
      }
    }
    if(!Verifica){
      cout<<"Erro! Turma nao encontrada!"<<endl;
      return;
    }
    Turmas.at(indexturma).ImprimeAlunos();
  }
  else{
    cout<<"Erro! Crie pelo menos uma turma!"<<endl;
    return;
  }
  system("read -p 'Pressione Enter para continuar...' var");
}

void Escola::ModificaProfessor(){
  system("clear");
  int indexprof,SizeProfs;
  string Nome,Area,Endereco;
  double salario;
  if(Professores.size()>0){
    cout<<"Escolha um professor para modificar:"<<endl;
    for(unsigned int k=0;k<Professores.size();k++){
      cout<<"-->Professor numero "<<k+1<<": "<<endl;
      cout<<"Nome: "<<Professores.at(k).Get_Nome()<<endl;
      cout<<"Area: "<<Professores.at(k).Get_Area()<<endl;
      cout<<"Salario: "<<Professores.at(k).Get_Salario()<<endl;
      cout<<"-----------------------------------------"<<endl;
    }
    cout<<"Entre com o numero do professor escolhido:";
    cin>>indexprof;
    SizeProfs = Professores.size();
    if((indexprof-1)<0 || indexprof>SizeProfs){
      cout<<"Erro! Professor nao existe!"<<endl;
      return;
    }
  }
    else{
      cout<<"Erro! Cadastre pelo menos um professor!";
      return;
    }
    cin.ignore(1);
    cout<<"Entre com o nome do professor:";
    getline(cin,Nome);
    cout<<"Entre com a area do professor:";
    getline(cin,Area);
    cout<<"Entre com o salario do professor:";
    cin>>salario;
    cin.ignore(1);
    cout<<"Entre com o endereco do professor:";
    getline(cin,Endereco);
    Professores.at(indexprof-1).ModificaNome(Nome);
    Professores.at(indexprof-1).Set_Area(Area);
    Professores.at(indexprof-1).Set_Endereco(Endereco);
    Professores.at(indexprof-1).Set_Salario(salario);
    cout<<"Professor modificado com sucesso!"<<endl;
    system("read -p 'Pressione Enter para continuar...' var");
    //return true;
}


void Escola::ModificaAluno(){
  system("clear");
  int Matricula;
  bool Verifica = false;
  string Nome,NomePai,NomeMae,DataNasc,Endereco;
  if(Alunos.size()>0){
    for(unsigned int i=0;i<Alunos.size();i++){
      cout<<"----------------Aluno---------------"<<endl;
      cout<<"Nome:"<<Alunos.at(i).Get_Nome()<<endl;
      cout<<"Matricula: "<<Alunos.at(i).GetMatricula()<<endl;
      cout<<"Endereco: "<<Alunos.at(i).Get_Endereco()<<endl;
      cout<<"------------------------------------"<<endl;
    }
    cout<<"Digite a matricula do aluno que deseja modificar:";
    cin>>Matricula;
    for(unsigned int j=0;j<Alunos.size();j++){
      if(Alunos.at(j).GetMatricula() == Matricula){
        cin.ignore(1);
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

        Alunos.at(j).ModificaNome(Nome);
        Alunos.at(j).Set_NomePais(NomePai,NomeMae);
        Alunos.at(j).Set_DataNasc(DataNasc);
        Alunos.at(j).Set_Endereco(Endereco);


        Verifica = true;
        cout<<"Aluno modificado com sucesso!"<<endl;
      }
    }
    if(!Verifica){
      cout<<"Erro! Aluno nao encontrado!"<<endl;
      return;
    }
  }
  else{
    cout<<"Erro! Nenhum aluno foi cadastrado!"<<endl;
    return;
  }
  system("read -p 'Pressione Enter para continuar...' var");
}
int Menu_Principal(){
  int a=0;
  system("clear");
  cout<<"----------Gestao-Academica----------"<<endl;
  cout<<"1 - Professores ->"<<endl;
  cout<<"2 - Alunos ->"<<endl;
  cout<<"3 - Turmas ->"<<endl;
  cout<<"4 - Finalizar programa"<<endl;
  while(a!=1 && a!=2 && a!=3 && a!=4){
    cout<<"Entre com a opcao desejada:";
    cin>>a;
    if(a!=1 && a!=2 && a!=3 && a!=4){
      cout<<"Opcao invalida!"<<endl;
    }
  }
  return a;
}
int Menu_Aluno(){
  int b=0;
  system("clear");
  cout<<"-------------Aluno--------------"<<endl;
  cout<<"1 - Cadastrar Aluno"<<endl;
  cout<<"2 - Listar Alunos"<<endl;
  cout<<"3 - Alterar cadastro de Aluno"<<endl;
  cout<<"4 - Voltar ao menu anterior"<<endl;
  while(b!=1 && b!=2 && b!=3 && b!=4){
    cout<<"Entre com a opcao desejada:";
    cin>>b;
    if(b!=1 && b!=2 && b!=3 && b!=4){
      cout<<"Opcao invalida!"<<endl;
    }
  }
  return b;
}
int Menu_Professor(){
  int b=0;
  system("clear");
  cout<<"-------------Professor--------------"<<endl;
  cout<<"1 - Cadastrar professor"<<endl;
  cout<<"2 - Listar professores"<<endl;
  cout<<"3 - Alterar cadastro de professor"<<endl;
  cout<<"4 - Voltar ao menu anterior"<<endl;
  while(b!=1 && b!=2 && b!=3 && b!=4){
    cout<<"Entre com a opcao desejada:";
    cin>>b;
    if(b!=1 && b!=2 && b!=3 && b!=4){
      cout<<"Opcao invalida!"<<endl;
    }
  }
  return b;
}
int Menu_Turma(){
  int b=0;
  system("clear");
  cout<<"-------------Turma--------------"<<endl;
  cout<<"1 - Criar Turma"<<endl;
  cout<<"2 - Adicionar Aluno em turma"<<endl;
  cout<<"3 - Listar Alunos de Turma"<<endl;
  cout<<"4 - Adicionar Notas a Turma"<<endl;
  cout<<"5 - Imprimir boletim"<<endl;
  cout<<"6 - Imprime Turmas"<<endl;
  cout<<"7 - Voltar ao menu anterior"<<endl;
  while(b!=1 && b!=2 && b!=3 && b!=4 && b!=5 && b!=6 && b!=7){
    cout<<"Entre com a opcao desejada:";
    cin>>b;
    if(b!=1 && b!=2 && b!=3 && b!=4 && b!=5 && b!=6 && b!=7){
      cout<<"Opcao invalida!"<<endl;
    }
  }
  return b;
}
