
#ifndef FUNCOESAUXILIARES_H
#define FUNCOESAUXILIARES_H






void lerMatricula(char mat[9]){
    printf("Digite a Matricula: ");
    fflush(stdin);
    scanf("%s",mat);
}

int acharAluno(char mat[9],Aluno t[40]){
    int i;
    for(i=0;i<tamanhoTurma;i++){
            if(strcmp(mat, t[i].matricula) == 0)
                return i;
    }
    return -1;
}

Aluno novoAluno(char nome[40],char matricula[9]){
    Aluno a;
    a.faltas = 0;
    a.Resultado = NAOCALCULADO;
    strcpy(a.Nome,nome);
    strcpy(a.matricula,matricula);
    return a;
}




float calcularExercicios(float exercicios[6]){
    int i;
    float temp=0;

    for (i=0;i<6; i++){
        temp+=exercicios[i];
    }
    return temp;
}

float calcularNF(Avaliacao av){
    float NF;
    NF = 2*(av.p1+av.p2);
    NF+= calcularExercicios(av.exercicios);
    NF+= av.trabalho;
    return NF/5;
}

void mostrarResultado(int r){
    if(r == NAOCALCULADO){
        printf("Ainda Nao Calculado");
    }else if(r == APROVADO){
        printf("Aprovado");
    }else if(r == REPROVADONOTA){
        printf("Reprovado");
    }else if(r == ERROMISTICO)
        printf("Erro mistico");
}

void calcularTudo(Aluno t[40]){
    int i;
    for (i=0;i<tamanhoTurma;i++){
        t[i].avaliacao.NF=(2*(t[i].avaliacao.p1)+ 
                2* (t[i].avaliacao.p2)
                + calcularExercicios(t[i].avaliacao.exercicios) 
                +(t[i].avaliacao.trabalho))/ 5;
    }
    calculaResultado(t);
}


#endif