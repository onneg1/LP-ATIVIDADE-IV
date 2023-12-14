#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Crie uma função chamada "calcularMedia" que recebe como parâmetro uma struct "Aluno", 
//esta struct terá informações como: nome, data de nascimento, duas notas e média e retorna a média das notas.
//Em seguida, crie um programa que declare um array de 5 alunos e utilize a função "calcularMedia" para imprimir a média de cada aluno. 
//Também crie uma função para verificar se um aluno está aprovado ou reprovado sendo necessário média maior ou igual a 7,0 para aprovação.


struct ficha_alunos
{
    char nome_aluno[250];
    char data_nascimento[250];
    float notas[2];
    float media;
};

void calcular_media(struct ficha_alunos *alunos)
{
    int i, j;

    for (i = 0; i < 5; i++)
    {
        float soma = 0;
        for (j = 0; j < 2; j++)
        {
            soma += alunos[i].notas[j];
        }

        alunos[i].media = soma / 2; // Corrigido para dividir pelo número correto de notas (2).
    }
}

void verificar_aprovacao(struct ficha_alunos aluno)
{
    if (aluno.media >= 7.0)
    {
        printf("Aprovado!\n");
    }
    else
    {
        printf("Reprovado!\n");
    }
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    struct ficha_alunos alunos[5];
    int i, j;

    for (i = 0; i < 5; i++)
    {
        printf("Informações do %d° aluno:\n\n", i + 1);

        printf("Nome: ");
        fgets(alunos[i].nome_aluno, 250, stdin);
    
        printf("Data de nascimento: ");
        fgets(alunos[i].data_nascimento, 250, stdin);
     
        for (j = 0; j < 2; j++)
        {
            printf("%dª nota: ", j + 1);
            scanf("%f", &alunos[i].notas[j]);
        }

        calcular_media(alunos);
        fflush(stdin);
        system("cls || clear");
    }

    for (i = 0; i < 5; i++)
    {
        printf("\nInformações do %d° aluno:\n", i + 1);
        printf("Nome: %s \n", alunos[i].nome_aluno);
        printf("Data de nascimento: %s\n", alunos[i].data_nascimento);
        for (j = 0; j < 2; j++)
        {
            printf("%d° nota: %.2f \n", j + 1, alunos[i].notas[j]);
        }
        printf("Média: %.2f\n", alunos[i].media);

        verificar_aprovacao(alunos[i]);
    }

    return 0;
}
