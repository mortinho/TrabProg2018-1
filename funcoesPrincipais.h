#ifndef FUNCOESPRINCIPAIS_H
#define FUNCOESPRINCIPAIS_H

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

int tamanhoTurma = 0;

#include "funcoesAuxiliares.h"


void cadastraAluno(Aluno turma[40]){
    char nome[40];
    char matricula[9];
    printf("Digite o Nome do Aluno: ");
    scanf("%s",nome);
    printf("Digite a Matricula do Aluno: ");
    scanf("%s",matricula);
    turma[tamanhoTurma] = novoAluno(nome,matricula);
    printf("Aluno e Matricula Cadastrados.\n\n");
    tamanhoTurma++;
}

void mostraAluno(Aluno turma[40]){
    char matricula[9];
    int i;

    lerMatricula(matricula);
    i = acharAluno(matricula,turma);
    if(i >= 0){
        printf("\nNome: %s",turma[i].Nome);
        printf("\nNumeros de Falta: %d",turma[i].faltas);
        printf("\nResultado: ");
        mostrarResultado(turma[i].Resultado);
    }else printf("aluno nao encontrado");
}

void cadastraExames(Aluno turma[40]){
    char matricula[9];
    int i;
    int j;

    lerMatricula(matricula);
    i = acharAluno(matricula,turma);
    if(i >= 0){
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
    }else printf("aluno nao encontrado");
}

void calculaNotaFinal(Aluno turma[40]){
    char matricula[9];
    int i;
    lerMatricula(matricula);
    i = acharAluno(matricula,turma);
    if(i >= 0){
        turma[i].avaliacao.NF = calcularNF(turma[i].avaliacao);
        printf("Nota Final do Aluno: %.1f",turma[i].avaliacao.NF);
    }else printf("aluno nao encontrado");
}

void cadastraVS(Aluno turma[40]){
    char matricula[9];
    int i;

    lerMatricula(matricula);
    i = acharAluno(matricula,turma);
    if(i >= 0){
        if (turma[i].avaliacao.NF >= 4 && turma[i].avaliacao.NF < 6 ){
            printf("Digite a Nota da VS: ");
            scanf("%f",&turma[i].avaliacao.VS);
        }else
        printf("Nao ha Possibilidade de Calcular a VS");
    }else printf("aluno nao encontrado");
}

void calculaMedia(Aluno turma[40]){
    char matricula[9];
    int i;

    lerMatricula(matricula);
    i = acharAluno(matricula,turma);
    if(i >= 0){
        if (turma[i].avaliacao.NF < 4 || turma[i].avaliacao.NF >= 6 ){
            printf  ("Media do Aluno: %.1f",turma[i].avaliacao.NF);
        }else if(turma[i].avaliacao.VS > 6){
            printf("Media do Aluno: 6.0");
        }else if(turma[i].avaliacao.VS < 6 && turma[i].avaliacao.VS < turma[i].avaliacao.NF){
            printf ("Media do Aluno: %.1f", turma[i].avaliacao.NF);
        }else
        printf ("Media do Aluno: %.1f", turma[i].avaliacao.VS);
    } else printf("aluno nao encontrado");
}

void calculaResultado(Aluno turma[40]){
    int i;

    for(i=0;i<tamanhoTurma;i++){
        if(turma[i].faltas > 16){
            turma[i].Resultado = REPROVADOFALTA;  /*incondicional*/
        }else if(turma[i].avaliacao.NF <4){
            turma[i].Resultado = REPROVADONOTA; /* nao pode fazer vs*/
        }else if(turma[i].avaliacao.NF >= 6 || turma[i].avaliacao.VS >= 6){
            turma[i].Resultado = APROVADO; /* passou direto ou na VS*/
        }else if(turma[i].avaliacao.VS < 6){
            turma[i].Resultado = REPROVADONOTA; /* nao passou na vs*/
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

#endif