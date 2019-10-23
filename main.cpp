#include "Headers/Professor.hpp"
#include "Headers/Aluno.hpp"
#include "Headers/Turma.hpp"
#include "Headers/Escola.hpp"

int main(int argc, char const *argv[]) {

  /*Professor *ProfAux = new Professor("Jose");
  ProfAux->Set_Area("Exatas");
  ProfAux->Set_Salario(0.1);
  Aluno Saulim("Saulim");
  Saulim.Set_NumMatricula(24);
  Saulim.Set_DataNasc("AlgumDiade1999");
  Saulim.Set_NomePais("SaulimPai","SaulimMAe");
  Saulim.Set_Endereco("RUA ao lado do fim do mundo, onde judas perdeu as botas");
  Aluno Globson("Samuel");
  Globson.Set_DataNasc("02/07/1999");
  Globson.Set_NumMatricula(11);
  Globson.Set_NomePais("GlobsonPai","GlobsonMae");
  Globson.Set_Endereco("Rua proxima a lugar nenhum, na esquina com perdido em paris");
  Turma Turma1(*ProfAux,4,1432);
  Turma1.AdicionaAluno(Globson);
  Turma1.AdicionaAluno(Saulim);
  Turma1.AdicionaNotas();
  Turma1.ImprimeAlunos();
  Turma1.ImprimeProfessor();
  Turma1.Imprime_Boletim(0);
  Turma1.Imprime_Boletim(1);*/

  Escola Esc;
  Esc.AdicionaProfessor();
  Esc.AdicionaProfessor();
  Esc.AdicionaProfessor();
  Esc.CriaTurma();
  Esc.CriaTurma();
  cin.ignore(1);
  Esc.AdicionaAluno();
  Esc.AdicionaAluno();
  Esc.AdicionaAlunoEmTurma();
  return 0;
}
