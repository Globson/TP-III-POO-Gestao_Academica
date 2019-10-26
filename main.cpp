#include "Headers/Professor.hpp"
#include "Headers/Aluno.hpp"
#include "Headers/Turma.hpp"
#include "Headers/Escola.hpp"

int main(int argc, char const *argv[]) {
  Escola Escola1;
  while(true){
    int a = Menu_Principal();
    if(a==1){
        int b = Menu_Professor();
          if(b==1){
            Escola1.AdicionaProfessor();
          }
          if(b==2){
            Escola1.ImprimeProfessores();
          }
          if(b==3){
            Escola1.ModificaProfessor();
          }
          if(b==4){
            continue;
          }}
      if(a==2){
        int b = Menu_Aluno();
        if(b==1){
          Escola1.AdicionaAluno();
        }
        if(b==2){
          Escola1.ImprimeAlunos();
        }
        if(b==3){
          Escola1.ModificaAluno();
        }
        if(b==4){
          continue;
        }
     }
     if(a==3){
       int b = Menu_Turma();
       if(b==1){
         Escola1.CriaTurma();}
       if(b==2){
         Escola1.AdicionaAlunoEmTurma();
       }
       if(b==3){
         Escola1.ImprimeAlunosDeTurma();
       }
       if(b==4){
         Escola1.AdicionaNota();
       }
       if(b==5){
         Escola1.ImprimeBoletim();
       }
       if(b==6){
         Escola1.ImprimeTurmas();
       }
       if(b==7){
       continue;
       }
     }
     if(a==4){
       break;
     }
  }
  return 0;
}
