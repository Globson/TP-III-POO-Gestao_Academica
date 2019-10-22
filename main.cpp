#include "Headers/Professor.hpp"
#include "Headers/Aluno.hpp"
#include "Headers/Turma.hpp"

int main(int argc, char const *argv[]) {

  Professor *ProfAux = new Professor("Jose");
  ProfAux->Set_Area("Exatas");
  ProfAux->Set_Salario(0.1);
  Aluno Saulim("Saulim","14/14/1023",24);
  Saulim.Set_NomePais("SaulimPai","SaulimMAe");
  Saulim.Set_Endereco("RUA ao lado do fim do mundo, onde judas perdeu as botas");
  Aluno Globson("Samuel","02/07/1999",11);
  Globson.Set_NomePais("GlobsonPai","GlobsonMae");
  Globson.Set_Endereco("Rua proxima a lugar nenhum, na esquina com perdido em paris");
  Turma Turma1(*ProfAux,4,1432);
  Turma1.AdicionaAluno(Globson);
  Turma1.AdicionaAluno(Saulim);
  Turma1.ImprimeAlunos();
  Turma1.ImprimeProfessor();
  return 0;
}
