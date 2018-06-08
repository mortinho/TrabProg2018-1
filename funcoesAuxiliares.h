

float getexercicios(float exercicios[6]){
    int i;
    float temp=0;

    for (i=0;i<6; i++){
        temp+=exercicios[i];
    }
    return temp;
}

void printresultado(int r){
    if(r == NAOCALCULADO){
        printf("Ainda Nao Calculado");
    }else if(r == APROVADO){
        printf("Aprovado");
    }else if(r == REPROVADONOTA){
        printf("Reprovado");
    }else if(r == ERROMISTICO)
        printf("Erro mistico");
}