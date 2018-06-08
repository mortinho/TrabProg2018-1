


Aluno autoCadastro(char nome[40],char mat[9],int faltas,Avaliacao av){
    Aluno a;
    a.Resultado = NAOCALCULADO;
    strcpy(a.Nome,nome);
    strcpy(a.matricula,mat);
    a.faltas = faltas;
    
    return a;
}

Avaliacao novaAvaliacao
    (float p1,
    float trabalho,
    float exercicio,
    float VS){
    int i;
    Avaliacao av;
    av.p1 = p1;
    av.p2 = p1;
    av.trabalho = trabalho;
    for (i = 0;i<6;i++) av.exercicios[i] = 0;
    av.exercicios[0] = exercicio;
    av.VS = VS;
    return av;
}
void gerarTurma(Aluno t[40]){
    Avaliacao passou,passounavs,naopassou,naopassounavs,fezvsdeotario;
    passou = novaAvaliacao(6,4,6,0);
    passounavs = novaAvaliacao(5,4,1,6);
    naopassou = novaAvaliacao(3,3,0,0);
    naopassounavs = novaAvaliacao(5,4,1,4);
    fezvsdeotario = naopassou; fezvsdeotario.VS = 10;
    
    t[tamanhoTurma] = autoCadastro("zeTurista","1",40,passou); tamanhoTurma++;
    t[tamanhoTurma] = autoCadastro("nerdao","2",0,passou); tamanhoTurma++;
    t[tamanhoTurma] = autoCadastro("joaoVS","3",14,passounavs); tamanhoTurma++;
    t[tamanhoTurma] = autoCadastro("tentouDaSilva","4",10,naopassounavs); tamanhoTurma++;
    t[tamanhoTurma] = autoCadastro("largouDeMao","5",16,naopassou); tamanhoTurma++;
    t[tamanhoTurma] = autoCadastro("otarioOliveira","6",14,fezvsdeotario); tamanhoTurma++;
    printf("%i",tamanhoTurma);
}