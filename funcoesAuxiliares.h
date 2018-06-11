
#ifndef FUNCOESAUXILIARES_H
#define FUNCOESAUXILIARES_H

#include "funcoesPrincipais.h"




void lerMatricula(char mat[9]){
/*interacao-auxiliar:
*pede a matricula ao usuario
*/
    
    printf("Digite a Matricula: ");
    fflush(stdin);
    scanf("%s",mat);
}

int acharAluno(char mat[9],Aluno t[40]){
/* auxiliar:
 * retorna o indice do primeiro aluno com matricula mat
 *    do vetor t
 * retorna -1  se nenhum foi encontrado 
 */

    int i;
    for(i=0;i<tamanhoTurma;i++){
            if(strcmp(mat, t[i].matricula) == 0)
                return i;
    }
    return -1;
}

Aluno novoAluno(char nome[40],char matricula[9]){
/* auxiliar:
 * inicializa e retorna um Aluno com os valores estaticos iniciais
 *     ,nome e matricula passados.
 */
    
    Aluno a;
    a.faltas = 0;
    a.Resultado = NAOCALCULADO;
    strcpy(a.Nome,nome);
    strcpy(a.matricula,matricula);
    return a;
}




float calcularExercicios(float exercicios[6]){
/*interno-auxiliar:
 * retorna a soma do exercicios guardados no vetor
 * ver calcularNF();
 */
    
    int i;
    float temp=0;

    for (i=0;i<6; i++){
        temp+=exercicios[i];
    }
    return temp;
}

float calcularNF(Avaliacao av){
/*auxiliar:
 * retona a nota final de uma struct de Avaliacoes
 * nao altera parametros
 */
    
    float NF;
    NF = 2*(av.p1+av.p2);
    NF+= calcularExercicios(av.exercicios);
    NF+= av.trabalho;
    return NF/5;
}

void mostrarResultado(int r){
/*interacao-auxiliar:
 * escreve na tela o resultado de acordo com o enum/
 *     resultado{APROVADO, REPROVADONOTA, REPROVADOFALTA, NAOCALCULADO}
 */
    
    if(r == NAOCALCULADO){
        printf("Ainda Nao Calculado");
    }else if(r == APROVADO){
        printf("Aprovado");
    }else if(r == REPROVADONOTA){
        printf("Reprovado");
    }else if(r == REPROVADOFALTA){
        printf("Reprovado por falta");
    }else if(r == ERROMISTICO)
        printf("Erro mistico");
}



#endif