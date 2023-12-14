#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

struct Conta {
    int numero;
    char titular_nome[50];
    float saldo;
    char tipo[20];
};

void limpar_tela() {
    system("cls || clear");
}

bool validar_valor(float valor) {
    return valor > 0;
}

void realizar_deposito(struct Conta *conta) {
    float valor;
    printf("Digite o valor a ser depositado: R$ ");
    
    if (scanf("%f", &valor) == 1 && validar_valor(valor)) {
        conta->saldo += valor;
        printf("Depósito de R$ %.2f realizado com sucesso!\n", valor);
    } else {
        printf("Valor de depósito inválido!\n");
    }
}

void realizar_saque(struct Conta *conta) {
    float valor;
    printf("Digite o valor a ser sacado: R$ ");
    
    if (scanf("%f", &valor) == 1 && validar_valor(valor) && valor <= conta->saldo) {
        conta->saldo -= valor;
        printf("Saque de R$ %.2f realizado com sucesso!\n", valor);
    } else {
        printf("Valor de saque inválido ou saldo insuficiente!\n");
    }
}

void consultar_saldo(struct Conta conta) {
    printf("Número da Conta: %d\n", conta.numero);
    printf("Nome do Titular: %s\n", conta.titular_nome);
    printf("Tipo de Conta: %s\n", conta.tipo);
    printf("Saldo Atual: R$ %.2f\n", conta.saldo);
}

int main() {
    setlocale(LC_ALL, "portuguese");

    struct Conta minha_conta = {12345678, "Maria", 13000, "Corrente"};

    int opcao;

    do {
        printf("\n              MENU             \n");
        printf(" OPÇÃO   |        FUNÇÃO       \n");
        printf("   1     | Depositar           \n");
        printf("   2     | Sacar               \n");
        printf("   3     | Consultar saldo     \n");
        printf("   4     | Sair do programa    \n");

        printf("\nEscolha a opção desejada: ");
        
        if (scanf("%d", &opcao) != 1) {
            limpar_tela();
            printf("Opção inválida. Tente novamente!\n");
            continue;
        }

        limpar_tela();

        switch (opcao) {
            case 1:
                realizar_deposito(&minha_conta);
                break;

            case 2:
                realizar_saque(&minha_conta);
                break;

            case 3:
                consultar_saldo(minha_conta);
                break;

            case 4:
                printf("Finalizando o programa...\n");
                break;

            default:
                printf("Opção inválida. Escolha uma opção válida!\n");
        }
    } while (opcao != 4);

    return 0;
}
