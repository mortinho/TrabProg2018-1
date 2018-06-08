#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcoesPrincipais.h"

#define DEBUG
#ifdef DEBUG

#include "funcoesTeste.h"

#endif
Aluno turma[40];


int menuPrincipal(){

    int opcao;

    printf("\n\n\t -- Menu do Usuario --\n\n");
    printf("\t1 - Para Cadastar Aluno.\n");
    printf("\t2 - Para Mostrar Aluno.\n");
    printf("\t3 - Para Cadastar Exames.\n");
    printf("\t4 - Para Calcular Nota Final.\n");
    printf("\t5 - Para Cadastrar Nota da VS.\n");
    printf("\t6 - Para Calcular Media.\n");
    printf("\t7 - Para Calcular Resultado.\n");
    printf("\t8 - Para Mostrar Aprovados.\n");
    printf("\t9 - Para Mostrar Reprovados.\n");
    printf("\t10- Para Encerrar o Programa.\n");

    printf("\nSua Escolha: ");
    scanf("%d",&opcao);

    return opcao;
}

int main(){
    int opcao;

    do{
       opcao = menuPrincipal();
       printf("\n");
       system("@cls||clear");
       switch(opcao){
           case 1:{
               cadastraAluno(turma);
           }break;
           case 2:{
               mostraAluno(turma);
           }break;
           case 3:{
                cadastraExames(turma);
           }break;
           case 4:{
                calculaNotaFinal(turma);
           }break;
           case 5:{
                cadastraVS(turma);
           }break;
           case 6:{
                calculaMedia(turma);
           }break;
           case 7:{
                calculaResultado(turma);
           }break;
           case 8:{
                MostraAprovados(turma);
           }break;
           case 9:{
                MostraReprovados(turma);
           }break;
#ifdef DEBUG
           case 11:{
               gerarTurma(turma);
           }break;
#endif
       }
   }while(opcao != 10);

    printf("Programa finalizado.\n");
    return 0;
}
