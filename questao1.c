#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define tam 3

// Crie uma struct Contato para representar informações de contatos, incluindo nome, número de telefone e email.
// Solicite que o usuário cadastre 3 contatos. Escreva uma função que recebe um nome como parâmetro,
// e retorna o número de telefone correspondente a esse nome.
// Em seguida, implemente um programa que utiliza essa função para buscar e imprimir o número de telefone de um contato específico.

struct Contato {
    char nome[250];
    char telefone[250];
    char email[250];
};

void limpatela() {
    system("cls || clear");
}

void verificador(struct Contato contatos[], char nomeBusca[]) {
    for (int i = 0; i < tam; i++) {
        if (strcmp(contatos[i].nome, nomeBusca) == 0) {
        	printf ("Exibindo dados do nome escolhido...\n");
            printf("Nome: %s\n", nomeBusca);
            printf("Telefone: %s\n", contatos[i].telefone);
            return;
        }
    }
    printf("Contato não encontrado para o nome: %s\n", nomeBusca);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    struct Contato contatos[3];
    int i;

    for (i = 0; i < 3; i++) {
        printf("Digite o %dº nome:\n", i + 1);
        fgets(contatos[i].nome, 250, stdin);

        printf("Digite o %dº telefone:\n", i + 1);
        fgets(contatos[i].telefone, 250, stdin);

        printf("Digite o %dº e-mail:\n", i + 1);
        fgets(contatos[i].email, 250, stdin);
        limpatela();
    }

    char nomeBusca[250];
    printf("Digite o nome do contato para buscar o numero de telefone: ");
    fgets(nomeBusca, 250, stdin);

    verificador(contatos, nomeBusca);

    return 0;
}
