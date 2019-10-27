#include "../Headers/Escola.hpp"
Escola::Escola(){
  this->ContMatricula = 3000; // numero de matricula inicial
  this->CodigoTurma = 100; //Codigo de turma inicial
}
void Escola::AdicionaProfessor(){
  system("clear");
  string Nome,Area,Endereco, SalarioString;
  double salario;
  int TemLetra = -1;
  stringstream ss;

  cout<<"Entre com o nome do professor:";
  cin.ignore(1);
  getline(cin,Nome);

  cout<<"Entre com a área do professor:";
  getline(cin,Area);

  while (TemLetra!=0)
  { 
    cout<<"Entre com o salário do professor:(Apenas números)";
    cin>>SalarioString;
    TemLetra=0;
    for (int i = 0; i < SalarioString.size(); i++)
    {
      if(isalpha(SalarioString[i])){
        TemLetra++;
      }
    }
  }
  ss << SalarioString;
  ss >> salario;
  ss.clear();
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
  cout<<"Entre com o nome da mãe do aluno:";
  getline(cin,NomeMae);
  cout<<"Entre com a data de nascimento do aluno:";
  getline(cin,DataNasc);
  cout<<"Entre com o endereço do aluno:";
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
  int indexprof,ano,SizeProfs,TemLetra = -1;
  string AnoString,IndexString;
  stringstream ss;
  if(Professores.size()>0){
    cout<<"Escolha um professor abaixo para ser responsável pela turma:"<<endl;
  for(unsigned int k=0;k<Professores.size();k++){
    cout<<"->Professor número "<<k+1<<": "<<endl;
    cout<<"Nome: "<<Professores.at(k).Get_Nome()<<endl;
    cout<<"Área: "<<Professores.at(k).Get_Area()<<endl;
    cout<<"Salário: "<<Professores.at(k).Get_Salario()<<endl;
    cout<<"-----------------------------------------"<<endl;
  }
  
  while (TemLetra!=0)
  { 
    cout<<"Entre com o número do professor escolhido:";
    cin>>IndexString;
    TemLetra=0;
    for (int i = 0; i < IndexString.size(); i++)
    {
      if(isalpha(IndexString[i])){
        TemLetra++;
      }
    }
  }
  ss << IndexString;
  ss >> indexprof;
  ss.clear();


  
  SizeProfs = Professores.size();
  if((indexprof-1)<0 || indexprof>SizeProfs){
    cout<<"Erro! Professor não existe!"<<endl;
    system("read -p 'Pressione Enter para continuar...' var");
    return;
  }
}else{
  cout<<"Erro! Cadastre pelo menos um professor!"<<endl;
  system("read -p 'Pressione Enter para continuar...' var");
  return;
}
TemLetra = -1;
while (TemLetra!=0)
  { 
    cout<<"Entre com o ano da turma:(Apenas números)";
    cin>>AnoString;
    TemLetra=0;
    for (int i = 0; i < AnoString.size(); i++)
    {
      if(isalpha(AnoString[i])){
        TemLetra++;
      }
    }
  }
ss << AnoString;
ss >> ano;
ss.clear();

Turma TurmaAux(&Professores.at(indexprof-1),CodigoTurma,ano);
this->CodigoTurma++;
Turmas.push_back(TurmaAux);
cout<<"Turma criada com sucesso!"<<endl;
system("read -p 'Pressione Enter para continuar...' var");
}


void Escola::AdicionaAlunoEmTurma(){
  system("clear");
  int Matricula,Codigoturma,indexturma,TemLetra =-1;
  bool Verifica = false,Verifica2 = false;
  string MatriculaString,TurmaString;
  stringstream ss;
  if(Turmas.size()>0){
    for(unsigned int k=0;k<Turmas.size();k++){
      cout<<"-----Turma-----"<<endl;
      cout<<"Código da turma: "<<Turmas.at(k).GetCodigo()<<endl;
      cout<<"Ano da turma: "<<Turmas.at(k).GetAno()<<endl;
      cout<<"Professor responsável pela turma: "<<Turmas.at(k).GetProfessor()<<endl;
      cout<<"----------------"<<endl;
    }
  while (TemLetra!=0)
    { 
      cout<<"Entre com o código da turma que deseja adicionar alunos:";
      cin>>TurmaString;
      TemLetra=0;
      for (int i = 0; i < TurmaString.size(); i++)
      {
        if(isalpha(TurmaString[i])){
          TemLetra++;
        }
      }
    }
    ss << TurmaString;
    ss >> Codigoturma;
    ss.clear();
  
  for(unsigned int x=0;x<Turmas.size();x++){
    if(Codigoturma == Turmas.at(x).GetCodigo()){
      indexturma = x;
      Verifica2 = true;
      cout<<"Turma selecionada com sucesso!"<<endl;
    }
  }
  if(!Verifica2){
    cout<<"Erro! Turma não encontrada!"<<endl;
    system("read -p 'Pressione Enter para continuar...' var");
    return;
  }

  }
  else{
    cout<<"Erro! Crie pelo menos uma turma!"<<endl;
    system("read -p 'Pressione Enter para continuar...' var");
    return;
  }
  if(Alunos.size()>0){
    for(unsigned int i=0;i<Alunos.size();i++){
      cout<<"---------------Aluno "<<i+1<<" -----------------"<<endl;
      cout<<"Nome:"<<Alunos.at(i).Get_Nome()<<endl;
      cout<<"Matrícula: "<<Alunos.at(i).GetMatricula()<<endl;
      cout<<"Endereço: "<<Alunos.at(i).Get_Endereco()<<endl;
      cout<<"----------------------------------------"<<endl;
    }
    TemLetra=-1;
    while (TemLetra!=0)
    { 
      cout<<"Digite a matrícula do aluno que deseja adicionar:";
      cin>>MatriculaString;
      TemLetra=0;
      for (int i = 0; i < MatriculaString.size(); i++)
      {
        if(isalpha(MatriculaString[i])){
          TemLetra++;
        }
      }
    }
    ss << MatriculaString;
    ss >> Matricula;
    ss.clear();
    for(unsigned int j=0;j<Alunos.size();j++){
      if(Alunos.at(j).GetMatricula() == Matricula){
        Verifica = true;
        if(!Turmas.at(indexturma).AlunoPresente(Matricula)){
          Turmas.at(indexturma).AdicionaAluno(&Alunos.at(j));
          cout<<"Aluno adicionado com sucesso a turma!"<<endl;
        }
        else{
          cout<<"Erro!Aluno já presente na turma!"<<endl;
        }
      }
    }
    if(!Verifica){
      cout<<"Erro!Aluno não encontrado!"<<endl;
    }
  }
  else{
    cout<<"Erro! Nenhum aluno foi cadastrado!"<<endl;
    system("read -p 'Pressione Enter para continuar...' var");
    return;
  }
  system("read -p 'Pressione Enter para continuar...' var");
}


void Escola::AdicionaNota(){
  system("clear");
  int Codigoturma,indexturma,TemLetra = -1;
  string TurmaString;
  bool Verifica = false;
  stringstream ss;
  if(Turmas.size()>0){
    for(unsigned int k=0;k<Turmas.size();k++){
      cout<<"-----Turma-----"<<endl;
      cout<<"Código da turma: "<<Turmas.at(k).GetCodigo()<<endl;
      cout<<"Ano da turma: "<<Turmas.at(k).GetAno()<<endl;
      cout<<"Professor responsável pela turma: "<<Turmas.at(k).GetProfessor()<<endl;
      cout<<"----------------"<<endl;
    }
   
    while (TemLetra!=0)
    { 
      cout<<"Entre com o código da turma que deseja adicionar notas dos alunos:";
      cin>>TurmaString;
      TemLetra=0;
      for (int i = 0; i < TurmaString.size(); i++)
      {
        if(isalpha(TurmaString[i])){
          TemLetra++;
        }
      }
    }
    ss << TurmaString;
    ss >> Codigoturma;
    ss.clear();
    for(unsigned int x=0;x<Turmas.size();x++){
      if(Codigoturma == Turmas.at(x).GetCodigo()){
        indexturma = x;
        Verifica = true;
        cout<<"Turma selecionada com sucesso!"<<endl;
      }
    }
    if(!Verifica){
      cout<<"Erro! Turma não encontrada!"<<endl;
      system("read -p 'Pressione Enter para continuar...' var");
      return;
    }
    Turmas.at(indexturma).AdicionaNotas();
  }
  else{
    cout<<"Nenhuma turma encontrada!"<<endl;
  }
  system("read -p 'Pressione Enter para continuar...' var");
}


void Escola::ImprimeBoletim(){
  system("clear");
  int Codigoturma,indexturma,indexaluno,MatriculaAluno,TemLetra=-1;
  bool Verifica = false,Verifica2 = false;
  string MatriculaString,TurmaString;
  stringstream ss;
  if(Turmas.size()>0){
    for(unsigned int k=0;k<Turmas.size();k++){
      cout<<"-----Turma-----"<<endl;
      cout<<"Coódigo da turma: "<<Turmas.at(k).GetCodigo()<<endl;
      cout<<"Ano da turma: "<<Turmas.at(k).GetAno()<<endl;
      cout<<"Professor responsável pela turma: "<<Turmas.at(k).GetProfessor()<<endl;
      cout<<"----------------"<<endl;
    }
    
    while (TemLetra!=0)
        { 
          cout<<"Entre com o código da turma que deseja imprimir o boletim do aluno:";
          cin>>TurmaString;
          TemLetra=0;
          for (int i = 0; i < TurmaString.size(); i++)
          {
            if(isalpha(TurmaString[i])){
              TemLetra++;
            }
          }
        }
    ss << TurmaString;
    ss >> Codigoturma;
    ss.clear();
    TemLetra=-1;
    for(unsigned int x=0;x<Turmas.size();x++){
      if(Codigoturma == Turmas.at(x).GetCodigo()){
        indexturma = x;
        Verifica = true;
        cout<<"Turma selecionada com sucesso!"<<endl;
      }
    }
    if(!Verifica){
      cout<<"Erro! Turma não encontrada!"<<endl;
      system("read -p 'Pressione Enter para continuar...' var");
      return;
    }
    if(Turmas.at(indexturma).ImprimeAlunos()){
      while (TemLetra!=0)
        { 
          cout<<"Entre com a matrícula do aluno que quer imprimir o boletim:";
          cin>>MatriculaString;
          TemLetra=0;
          for (int i = 0; i < MatriculaString.size(); i++)
          {
            if(isalpha(MatriculaString[i])){
              TemLetra++;
            }
          }
        }
      ss << MatriculaString;
      ss >> MatriculaAluno;
      ss.clear();
    }
    else{
      system("read -p 'Pressione Enter para continuar...' var");
      return;
    }
    for(unsigned int x=0;x<Turmas.at(indexturma).Alunos.size();x++){
      if(MatriculaAluno == Turmas.at(indexturma).Alunos.at(x)->GetMatricula()){
        Verifica2 = true;
        indexaluno = x;
      }
    }
    if(!Verifica2){
      cout<<"Erro! Aluno não cadastrado em turma escolhida!"<<endl;
      system("read -p 'Pressione Enter para continuar...' var");
      return;
    }
    Turmas.at(indexturma).Imprime_Boletim(indexaluno);

  }
  else{
    cout<<"Erro! Crie pelo menos uma turma!"<<endl;
    system("read -p 'Pressione Enter para continuar...' var");
    return;
  }
  system("read -p 'Pressione Enter para continuar...' var");
}



void Escola::ImprimeProfessores(){
  system("clear");
  for(unsigned int k=0;k<Professores.size();k++){
    cout<<"------------Professor "<<k+1<<" --------------"<<endl;
    cout<<"Nome: "<<Professores.at(k).Get_Nome()<<endl;
    cout<<"Área: "<<Professores.at(k).Get_Area()<<endl;
    cout<<"Salário: "<<Professores.at(k).Get_Salario()<<endl;
    cout<<"Endereço: "<<Professores.at(k).Get_Endereco()<<endl;
    cout<<"--------------------------------------"<<endl;
  }
  if(Professores.size()==0){
    cout<<"Nenhum professor cadastrado!"<<endl;
  }
  system("read -p 'Pressione Enter para continuar...' var");
}

void Escola::ImprimeAlunos(){
  system("clear");
  for(unsigned int k=0;k<Alunos.size();k++){
    cout<<"---------------Aluno "<<k+1<<" -----------------"<<endl;
    cout<<"Nome:"<<Alunos.at(k).Get_Nome()<<endl;
    cout<<"Matrícula: "<<Alunos.at(k).GetMatricula()<<endl;
    cout<<"Nome da mãe: "<<Alunos.at(k).Get_NomeMae()<<endl;
    cout<<"Nome do pai: "<<Alunos.at(k).Get_NomePai()<<endl;
    cout<<"Data de Nascimento: "<<Alunos.at(k).Get_DataNasc()<<endl;
    cout<<"Endereco: "<<Alunos.at(k).Get_Endereco()<<endl;
    cout<<"----------------------------------------"<<endl;
  }
  if(Alunos.size()==0){
    cout<<"Nenhum aluno cadastrado!"<<endl;
  }
  system("read -p 'Pressione Enter para continuar...' var");
}

void Escola::ImprimeTurmas(){
  system("clear");
  for(unsigned int k=0;k<Turmas.size();k++){
    cout<<"-----Turma "<<k+1<<" -----"<<endl;
    cout<<"Código da turma: "<<Turmas.at(k).GetCodigo()<<endl;
    cout<<"Ano da turma: "<<Turmas.at(k).GetAno()<<endl;
    cout<<"Professor responsável pela turma: "<<Turmas.at(k).GetProfessor()<<endl;
    cout<<"------------------"<<endl;
  }
  if(Turmas.size()==0){
    cout<<"Erro! Nenhuma turma cadastrada!"<<endl;
  }
  system("read -p 'Pressione Enter para continuar...' var");
}
void Escola::ImprimeAlunosDeTurma(){
  system("clear");
  int Codigoturma,indexturma,TemLetra=-1;
  bool Verifica = false;
  string TurmaString;
  stringstream ss;
  if(Turmas.size()>0){
    for(unsigned int k=0;k<Turmas.size();k++){
      cout<<"-----Turma-----"<<endl;
      cout<<"Código da turma: "<<Turmas.at(k).GetCodigo()<<endl;
      cout<<"Ano da turma: "<<Turmas.at(k).GetAno()<<endl;
      cout<<"Professor responsável pela turma: "<<Turmas.at(k).GetProfessor()<<endl;
      cout<<"----------------"<<endl;
    }
    while (TemLetra!=0)
        { 
          cout<<"Entre com o código da turma que deseja imprimir os alunos:";
          cin>>TurmaString;
          TemLetra=0;
          for (int i = 0; i < TurmaString.size(); i++)
          {
            if(isalpha(TurmaString[i])){
              TemLetra++;
            }
          }
        }
      ss << TurmaString;
      ss >> Codigoturma;
      ss.clear();
    for(unsigned int x=0;x<Turmas.size();x++){
      if(Codigoturma == Turmas.at(x).GetCodigo()){
        indexturma = x;
        Verifica = true;
        cout<<"Turma selecionada com sucesso!"<<endl;
      }
    }
    if(!Verifica){
      cout<<"Erro! Turma nao encontrada!"<<endl;
      system("read -p 'Pressione Enter para continuar...' var");
      return;
    }
    Turmas.at(indexturma).ImprimeAlunos();
  }
  else{
    cout<<"Erro! Crie pelo menos uma turma!"<<endl;
    system("read -p 'Pressione Enter para continuar...' var");
    return;
  }
  system("read -p 'Pressione Enter para continuar...' var");
}

void Escola::ModificaProfessor(){
  system("clear");
  int indexprof,SizeProfs;
  string Nome,Area,Endereco,SalarioString,IndexString;
  double salario;
  int TemLetra = -1;
  stringstream ss;
  if(Professores.size()>0){
    cout<<"Escolha um professor para modificar:"<<endl;
    for(unsigned int k=0;k<Professores.size();k++){
      cout<<"-->Professor numero "<<k+1<<": "<<endl;
      cout<<"Nome: "<<Professores.at(k).Get_Nome()<<endl;
      cout<<"Área: "<<Professores.at(k).Get_Area()<<endl;
      cout<<"Salário: "<<Professores.at(k).Get_Salario()<<endl;
      cout<<"-----------------------------------------"<<endl;
    }
    while (TemLetra!=0)
    { 
      cout<<"Entre com o número do professor escolhido:";
      cin>>IndexString;
      TemLetra=0;
      for (int i = 0; i < IndexString.size(); i++)
      {
        if(isalpha(IndexString[i])){
          TemLetra++;
        }
      }
    }
    ss << IndexString;
    ss >> indexprof;
    ss.clear();
    SizeProfs = Professores.size();
    if((indexprof-1)<0 || indexprof>SizeProfs){
      cout<<"Erro! Professor não existe!"<<endl;
      system("read -p 'Pressione Enter para continuar...' var");
      return;
    }
  }
    else{
      cout<<"Erro! Cadastre pelo menos um professor!"<<endl;
      system("read -p 'Pressione Enter para continuar...' var");
      return;
    }
    cin.ignore(1);
    cout<<"Entre com o nome do professor:";
    getline(cin,Nome);
    cout<<"Entre com a área do professor:";
    getline(cin,Area);
    //cout<<"Entre com o salário do professor:";
    TemLetra=0;
    while (TemLetra!=0)
    { 
      cout<<"Entre com o salário do professor:(Apenas números)";
      cin>>SalarioString;
      TemLetra=0;
      for (int i = 0; i < SalarioString.size(); i++)
      {
        if(isalpha(SalarioString[i])){
          TemLetra++;
        }
      }
    }
    ss << SalarioString;
    ss >> salario;
    ss.clear();
    cin.ignore(1);
    cout<<"Entre com o endereço do professor:";
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
  int Matricula,TemLetra=-1;
  bool Verifica = false;
  string Nome,NomePai,NomeMae,DataNasc,Endereco,MatriculaString;
  stringstream ss;
  if(Alunos.size()>0){
    for(unsigned int i=0;i<Alunos.size();i++){
      cout<<"----------------Aluno---------------"<<endl;
      cout<<"Nome:"<<Alunos.at(i).Get_Nome()<<endl;
      cout<<"Matrícula: "<<Alunos.at(i).GetMatricula()<<endl;
      cout<<"Endereço: "<<Alunos.at(i).Get_Endereco()<<endl;
      cout<<"------------------------------------"<<endl;
    }
    
    while (TemLetra!=0)
    { 
      cout<<"Digite a matrícula do aluno que deseja modificar:";
      cin>>MatriculaString;
      TemLetra=0;
      for (int i = 0; i < MatriculaString.size(); i++)
      {
        if(isalpha(MatriculaString[i])){
          TemLetra++;
        }
      }
    }
    ss << MatriculaString;
    ss >> Matricula;
    ss.clear();
  
    for(unsigned int j=0;j<Alunos.size();j++){
      if(Alunos.at(j).GetMatricula() == Matricula){
        cin.ignore(1);
        cout<<"Entre com o nome do aluno:";
        getline(cin,Nome);
        cout<<"Entre com o nome do pai do aluno:";
        getline(cin,NomePai);
        cout<<"Entre com o nome da mãe do aluno:";
        getline(cin,NomeMae);
        cout<<"Entre com a data de nascimento do aluno:";
        getline(cin,DataNasc);
        cout<<"Entre com o endereço do aluno:";
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
      cout<<"Erro! Aluno não encontrado!"<<endl;
      system("read -p 'Pressione Enter para continuar...' var");
      return;
    }
  }
  else{
    cout<<"Erro! Nenhum aluno foi cadastrado!"<<endl;
    system("read -p 'Pressione Enter para continuar...' var");
    return;
  }
  system("read -p 'Pressione Enter para continuar...' var");
}
int Menu_Principal(){
  int a=0,TemLetra = -1;
  string aString;
  stringstream ss;
  system("clear");
  cout<<"----------Gestão-Acadêmica----------"<<endl;
  cout<<"1 - Professores ->"<<endl;
  cout<<"2 - Alunos ->"<<endl;
  cout<<"3 - Turmas ->"<<endl;
  cout<<"4 - Finalizar programa:"<<endl;
  while(a!=1 && a!=2 && a!=3 && a!=4){
    //TemLetra=-1;
    while (TemLetra!=0)
    { 
      cout<<"Entre com a opção desejada:";
      cin>>aString;
      TemLetra=0;
      for (int i = 0; i < aString.size(); i++)
      {
        if(isalpha(aString[i])){
          TemLetra++;
        }
      }
    }
  ss << aString;
  ss >> a;
  ss.clear();
     
    if(a!=1 && a!=2 && a!=3 && a!=4){
      cout<<"Opção inválida!"<<endl;
      TemLetra=-1;
    }
  }
  return a;
}
int Menu_Aluno(){
  int b=0,TemLetra = -1;
  string bString;
  stringstream ss;
  system("clear");
  cout<<"-------------Aluno--------------"<<endl;
  cout<<"1 - Cadastrar Aluno:"<<endl;
  cout<<"2 - Listar Alunos:"<<endl;
  cout<<"3 - Alterar cadastro de Aluno:"<<endl;
  cout<<"4 - Voltar ao menu anterior:"<<endl;
  while(b!=1 && b!=2 && b!=3 && b!=4){
    
    while (TemLetra!=0)
    { 
      cout<<"Entre com a opção desejada:";
      cin>>bString;
      TemLetra=0;
      for (int i = 0; i < bString.size(); i++)
      {
        if(isalpha(bString[i])){
          TemLetra++;
        }
      }
    }
    ss << bString;
    ss >> b;
    ss.clear();
    if(b!=1 && b!=2 && b!=3 && b!=4){
      cout<<"Opção inválida!"<<endl;
      TemLetra=-1;
    }
  }
  return b;
}
int Menu_Professor(){
  int b=0,TemLetra=-1;
  string bString;
  stringstream ss;
  system("clear");
  cout<<"-------------Professor--------------"<<endl;
  cout<<"1 - Cadastrar professor:"<<endl;
  cout<<"2 - Listar professores:"<<endl;
  cout<<"3 - Alterar cadastro de professor:"<<endl;
  cout<<"4 - Voltar ao menu anterior:"<<endl;
  while(b!=1 && b!=2 && b!=3 && b!=4){
    
    while (TemLetra!=0)
    { 
      cout<<"Entre com a opção desejada:";
      cin>>bString;
      TemLetra=0;
      for (int i = 0; i < bString.size(); i++)
      {
        if(isalpha(bString[i])){
          TemLetra++;
        }
      }
    }
    ss << bString;
    ss >> b;
    ss.clear();

    if(b!=1 && b!=2 && b!=3 && b!=4){
      TemLetra=-1;
      cout<<"Opção inválida!"<<endl;
    }
  }
  return b;
}
int Menu_Turma(){
  int b=0,TemLetra=-1;
  string bString;
  stringstream ss;
  system("clear");
  cout<<"-------------Turma--------------"<<endl;
  cout<<"1 - Criar turma:"<<endl;
  cout<<"2 - Adicionar aluno em turma:"<<endl;
  cout<<"3 - Listar alunos de turma:"<<endl;
  cout<<"4 - Adicionar notas a turma:"<<endl;
  cout<<"5 - Imprimir boletim:"<<endl;
  cout<<"6 - Imprimir turmas:"<<endl;
  cout<<"7 - Voltar ao menu anterior:"<<endl;
  while(b!=1 && b!=2 && b!=3 && b!=4 && b!=5 && b!=6 && b!=7){
    
    while (TemLetra!=0)
    { 
      cout<<"Entre com a opção desejada:";
      cin>>bString;
      TemLetra=0;
      for (int i = 0; i < bString.size(); i++)
      {
        if(isalpha(bString[i])){
          TemLetra++;
        }
      }
    }
    ss << bString;
    ss >> b;
    ss.clear();
    if(b!=1 && b!=2 && b!=3 && b!=4 && b!=5 && b!=6 && b!=7){
      cout<<"Opcao inválida!"<<endl;
      TemLetra=-1;
    }
  }
  return b;
}
int Menu_Finalizar(){
  int b=0,TemLetra=-1;
  string bString;
  stringstream ss;
  system("clear");
  cout<<"-------------Finalizar--------------"<<endl;
  cout<<"Deseja realmente finalizar a execução do programa?"<<endl;
  cout<<"\t1 - Sim"<<endl;
  cout<<"\t2 - Não"<<endl;
  while(b!=1 && b!=2){
    while (TemLetra!=0)
    { 
      cout<<"Entre com a opção desejada:";
      cin>>bString;
      TemLetra=0;
      for (int i = 0; i < bString.size(); i++)
      {
        if(isalpha(bString[i])){
          TemLetra++;
        }
      }
    }
    ss << bString;
    ss >> b;
    ss.clear();
    if(b!=1 && b!=2 ){
      cout<<"Opção inválida!"<<endl;
      TemLetra=-1;
    }
  }
  return b;
}
