#define ERROMISTICO -1

typedef struct Avaliacao {
    float p1,p2;
    float trabalho;
    float exercicios[6];
    float VS;
    float NF;
 } Avaliacao;

enum resultado{APROVADO, REPROVADONOTA, REPROVADOFALTA, NAOCALCULADO};

typedef struct Aluno {
    char Nome [40];
    char matricula[9];
    int faltas;
    Avaliacao avaliacao;
    int Resultado;
} Aluno;

#include "funcoesAuxiliares.h"

int tamanhoTurma = 0;

void cadastraAluno(Aluno turma[40]){
        turma[tamanhoTurma].faltas = 0;
        turma[tamanhoTurma].Resultado = NAOCALCULADO;
        printf("Digite o Nome do Aluno: ");
        scanf("%s",turma[tamanhoTurma].Nome);
        printf("Digite a Matricula do Aluno: ");
        scanf("%s",turma[tamanhoTurma].matricula);
        printf("Aluno e Matricula Cadastrados.\n\n");
        tamanhoTurma++;
}

void mostraAluno(Aluno turma[40]){
    char matricula[9];
    int i;

    printf("Digite a matricula do Aluno: ");
    fflush(stdin);
    scanf("%s",matricula);
    for(i=0;i<tamanhoTurma;i++){
        if(strcmp(matricula , turma[i].matricula) == 0){
            printf("\nNome: %s",turma[i].Nome);
            printf("\nNumeros de Falta: %d",turma[i].faltas);
            printf("\nResultado: ");
            printresultado(turma[i].Resultado);
            break;
        }
    }
}

void cadastraExames(Aluno turma[40]){
    char matricula[9];
    int i;
    int j;

    printf("Digite a Matricula: ");
    fflush(stdin);
    scanf("%s",matricula);
    for(i=0;i<tamanhoTurma;i++){
        if(strcmp(matricula, turma[i].matricula) == 0){
            printf("\nDigite a Nota da P1: ");
            scanf("%f",&turma[i].avaliacao.p1);
            printf("\nDigite a Nota da P2: ");
            scanf("%f",&turma[i].avaliacao.p2);
            printf("\nDigite a Nota do Trabalho: ");
            scanf("%f",&turma[i].avaliacao.trabalho);
            for (j=0; j<6;j++){
            printf("\nDigite a Nota do Exercicio %i:", j+1);
            scanf("%f",&turma[i].avaliacao.exercicios[j]);
            }
            printf("\nDigite o Numero de Faltas: ");
            scanf("%d",&turma[i].faltas);
            break;
        }
    }
}

void calculaNotaFinal(Aluno turma[40]){
    char matricula[9];
    int i;
    printf("Digite a Matricula: ");
    fflush(stdin);
    scanf("%s",matricula);
    for(i=0;i<tamanhoTurma;i++){
            if(strcmp(matricula, turma[i].matricula) == 0){
                turma[i].avaliacao.NF=(2*(turma[i].avaliacao.p1)+ 2* (turma[i].avaliacao.p2)+ getexercicios(turma[i].avaliacao.exercicios) +(turma[i].avaliacao.trabalho))/ 5;
                printf("Nota Final do Aluno: %.1f",turma[i].avaliacao.NF);
            }
    }
}

void cadastraVS(Aluno turma[40]){
    char matricula[9];
    int i;

    printf("Digite a Matricula: ");
    fflush(stdin);
    scanf("%s",matricula);
    for(i=0;i<tamanhoTurma;i++){
        if(strcmp(matricula, turma[i].matricula) == 0){
                    if (turma[i].avaliacao.NF >= 4 && turma[i].avaliacao.NF < 6 ){
                        printf("Digite a Nota da VS: ");
                        scanf("%f",&turma[i].avaliacao.VS);
                    }else
                    printf("Nao ha Possibilidade de Calcular a VS");
                    }
            }
}

void calculaMedia(Aluno turma[40]){
    char matricula[9];
    int i;

    printf("Digite a Matricula: ");
    fflush(stdin);
    scanf("%s",matricula);
    for(i=0;i<tamanhoTurma;i++){
        if(strcmp(matricula, turma[i].matricula) == 0){
                    if (turma[i].avaliacao.NF < 4 || turma[i].avaliacao.NF >= 6 ){
                        printf  ("Media do Aluno: %.1f",turma[i].avaliacao.NF);
                    }else if(turma[i].avaliacao.VS > 6){
                        printf("Media do Aluno: 6.0");
                    }else if(turma[i].avaliacao.VS < 6 && turma[i].avaliacao.VS < turma[i].avaliacao.NF){
                        printf ("Media do Aluno: %.1f", turma[i].avaliacao.NF);
                    }else
                    printf ("Media do Aluno: %.1f", turma[i].avaliacao.VS);
        }
    }
}

void calculaResultado(Aluno turma[40]){
    int i;

    for(i=0;i<tamanhoTurma;i++){
        if(turma[i].faltas > 16){
            turma[i].Resultado = REPROVADOFALTA;  /*incondicional*/
        }else if(turma[i].avaliacao.NF >= 6 || turma[i].avaliacao.VS >= 6){
            turma[i].Resultado = APROVADO; /* passou direto ou na VS*/
        }else if(turma[i].avaliacao.NF <4){
            turma[i].Resultado = REPROVADONOTA; /* nao pode fazer vs*/
        }else if(turma[i].avaliacao.VS < 6){
            turma[i].Resultado = NAOCALCULADO; /* nao fez VS -- desnecessaria a condicao*/
        }else
            turma[i].Resultado = ERROMISTICO; /* nao deveria chegar aqui*/
     }
    printf("Calculado Com Sucesso");
}

void MostraAprovados(Aluno turma[40]){
    int i;

    printf("\t-- Aprovados --\n\n");
    for(i=0;i<tamanhoTurma;i++){
            if(turma[i].Resultado == APROVADO){
                printf("\nNome: %s",turma[i].Nome);
                printf("\nMatricula: %s",turma[i].matricula);
                printf("\n---------------------------------------");
            }
    }
}

void MostraReprovados(Aluno turma[40]){
    int i;

    printf("\t-- Reprovados --\n\n");
    for(i=0;i<tamanhoTurma;i++){
            if(turma[i].Resultado == REPROVADONOTA || turma[i].Resultado == REPROVADOFALTA){
                printf("\nNome: %s",turma[i].Nome);
                printf("\nMatricula: %s",turma[i].matricula);
                printf("\n---------------------------------------");
            }
    }
}
