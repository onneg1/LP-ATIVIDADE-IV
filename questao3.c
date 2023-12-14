#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Desenvolva uma struct "Produto" que contenha informações como nome,
//preço e quantidade em estoque. Em seguida, desenvolva um menu 
//para facilitar a escolha das opções:
//1 - Realizar uma compra
//2 - Consultar estoque
//3 - Sair do programa. 

//Escreva funções necessárias para calcular o valor 
//total em estoque do produto e para atualizar a quantidade em 
//estoque com base em uma compra. Crie um programa que utiliza essas funções para um produto.

struct Produto {
    char nome[250];
    float preco;
    int quantidade;
};

void limpartela(){
	system("cls || clear");
}

float calcular_total(struct Produto produto) {
    return produto.preco * produto.quantidade;
}

void realizar_compra(struct Produto *produto) {
    int quantidade_comprada;
    
    printf("Digite a quantidade que quer comprar: ");
    scanf("%d", &quantidade_comprada);
    
    if (quantidade_comprada > 0) {
        if (quantidade_comprada <= produto->quantidade) {
            produto->quantidade -= quantidade_comprada;
            printf("Compra realizada!\n");
        } else {
            printf("Quantidade insuficiente em estoque!\n");
        }
    } else {
        printf("Quantidade inválida!\n");
    }
}

void consultar_estoque(struct Produto produto) {
    printf("Nome do Produto: %s\n", produto.nome);
    printf("Preço: R$ %.2f\n", produto.preco);
    printf("Quantidade em estoque: %d\n", produto.quantidade);
    printf("Valor total em estoque: R$ %.2f\n", calcular_total(produto));
}

int main() {
    setlocale(LC_ALL, "portuguese");

    struct Produto meu_produto;
    strcpy(meu_produto.nome, "Produto");  
    meu_produto.preco = 5.00;               
    meu_produto.quantidade = 100;            

    int opcao;

    do {
        printf("\n              MENU             \n");
        printf(" OPÇÃO   |        ESCOLHA       \n");
        printf("   1     | Realizar uma compra \n");
        printf("   2     | Consultar estoque   \n");
        printf("   3     | Sair do programa    \n");

        printf("\nEscolha a opção desejada: ");
        scanf("%d", &opcao);
        
        limpartela();

        switch (opcao) {
            case 1:
                realizar_compra(&meu_produto);
                break;

            case 2:
                consultar_estoque(meu_produto);
                break;

            case 3:
                printf("Finalizando o programa\n");
                break;

            default:
                printf("Opção inválida. Escolha uma opção válida!\n");
        }
    } while (opcao != 3);

    return 0;
}
