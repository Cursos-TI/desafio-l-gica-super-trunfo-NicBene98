#include <stdio.h>

// Estrutura que representa uma carta do Super Trunfo
struct Carta {
    char estado[3];
    char codigo[5];
    char nomePais[30];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
    float pibPerCapita;
};

// Função para exibir o menu de atributos
void exibirMenu(int atributoBloqueado) {
    printf("\nEscolha um atributo para comparar:\n");
    if (atributoBloqueado != 1) printf("1 - População\n");
    if (atributoBloqueado != 2) printf("2 - Área\n");
    if (atributoBloqueado != 3) printf("3 - PIB\n");
    if (atributoBloqueado != 4) printf("4 - Pontos Turísticos\n");
    if (atributoBloqueado != 5) printf("5 - Densidade Demográfica\n");
    printf("Opção: ");
}

// Função que retorna o valor numérico do atributo selecionado
float obterValorAtributo(struct Carta carta, int atributo) {
    switch (atributo) {
        case 1: return carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return carta.pontosTuristicos;
        case 5: return carta.densidadeDemografica;
        default: return 0;
    }
}

// Função para comparar um atributo individual
float compararAtributo(struct Carta c1, struct Carta c2, int atributo) {
    float valor1 = obterValorAtributo(c1, atributo);
    float valor2 = obterValorAtributo(c2, atributo);

    printf("\nComparando atributo: ");
    switch (atributo) {
        case 1: printf("População\n"); break;
        case 2: printf("Área\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Pontos Turísticos\n"); break;
        case 5: printf("Densidade Demográfica\n"); break;
    }

    printf("%s: %.2f\n", c1.nomePais, valor1);
    printf("%s: %.2f\n", c2.nomePais, valor2);

    // Regra geral: maior vence. Exceção: densidade demográfica (menor vence)
    if (atributo == 5) {
        return (valor1 < valor2) ? 1 : (valor2 < valor1) ? 2 : 0; // operador ternário
    } else {
        return (valor1 > valor2) ? 1 : (valor2 > valor1) ? 2 : 0;
    }
}

int main() {
    struct Carta carta1 = {"BR", "A01", "Brasil", 214000000, 8515767.0, 22000.0, 25};
    struct Carta carta2 = {"AR", "A02", "Argentina", 46000000, 2780400.0, 6400.0, 18};

    // Cálculo dos atributos derivados
    carta1.densidadeDemografica = carta1.populacao / carta1.area;
    carta2.densidadeDemografica = carta2.populacao / carta2.area;

    carta1.pibPerCapita = carta1.pib / carta1.populacao;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    int atributo1, atributo2;

    printf("===== SUPER TRUNFO - NÍVEL MESTRE =====\n");
    printf("Comparação entre:\n1. %s (%s)\n2. %s (%s)\n\n",
           carta1.nomePais, carta1.estado, carta2.nomePais, carta2.estado);

    // Escolha do primeiro atributo
    exibirMenu(0);
    scanf("%d", &atributo1);

    // Validação do primeiro atributo
    if (atributo1 < 1 || atributo1 > 5) {
        printf("\nOpção inválida! Encerrando o programa.\n");
        return 0;
    }

    // Escolha do segundo atributo (menu dinâmico)
    do {
        exibirMenu(atributo1);
        scanf("%d", &atributo2);
        if (atributo2 == atributo1)
            printf("Você já escolheu esse atributo! Escolha outro.\n");
    } while (atributo2 == atributo1 || atributo2 < 1 || atributo2 > 5);

    printf("\n=== COMPARAÇÃO MULTI-ATRIBUTOS ===\n");

    // Comparação individual dos dois atributos
    float resultado1 = compararAtributo(carta1, carta2, atributo1);
    float resultado2 = compararAtributo(carta1, carta2, atributo2);

    // Obtenção dos valores numéricos dos atributos
    float valor1_c1 = obterValorAtributo(carta1, atributo1);
    float valor1_c2 = obterValorAtributo(carta2, atributo1);
    float valor2_c1 = obterValorAtributo(carta1, atributo2);
    float valor2_c2 = obterValorAtributo(carta2, atributo2);

    // Soma dos atributos (inversão de sinal para densidade demográfica)
    float soma1 = (atributo1 == 5 ? -valor1_c1 : valor1_c1) +
                  (atributo2 == 5 ? -valor2_c1 : valor2_c1);
    float soma2 = (atributo1 == 5 ? -valor1_c2 : valor1_c2) +
                  (atributo2 == 5 ? -valor2_c2 : valor2_c2);

    printf("\nSoma ponderada dos atributos:\n");
    printf("%s: %.2f\n", carta1.nomePais, soma1);
    printf("%s: %.2f\n", carta2.nomePais, soma2);

    // Determinação final do vencedor (ou empate)
    printf("\n=== RESULTADO FINAL ===\n");
    if (soma1 > soma2) {
        printf("%s venceu a rodada!\n", carta1.nomePais);
    } else if (soma2 > soma1) {
        printf("%s venceu a rodada!\n", carta2.nomePais);
    } else {
        printf("Empate!\n");
    }

    printf("\n=== Fim da rodada ===\n");
    return 0;
}