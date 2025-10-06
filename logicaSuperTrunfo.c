#include <stdio.h>

// Estrutura que representa uma carta do Super Trunfo
struct Carta {
    char estado[3];
    char codigo[5];
    char nomeCidade[30];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

int main() {
    // Cadastro das cartas (pré-definidas)
    struct Carta carta1 = {"SP", "A01", "São Paulo", 12300000, 1521.11, 699.28, 50};
    struct Carta carta2 = {"RJ", "A02", "Rio de Janeiro", 6748000, 1182.30, 362.01, 45};

    // Cálculo dos atributos derivados
    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta2.densidadePopulacional = carta2.populacao / carta2.area;

    carta1.pibPerCapita = carta1.pib / carta1.populacao;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    // Exibição das cartas
    printf("===== CARTA 1 =====\n");
    printf("Estado: %s\nCódigo: %s\nCidade: %s\nPopulação: %d\nÁrea: %.2f km²\nPIB: %.2f bilhões\nPontos turísticos: %d\n",
           carta1.estado, carta1.codigo, carta1.nomeCidade, carta1.populacao, carta1.area, carta1.pib, carta1.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\nPIB per capita: %.6f bilhões/hab\n\n", carta1.densidadePopulacional, carta1.pibPerCapita);

    printf("===== CARTA 2 =====\n");
    printf("Estado: %s\nCódigo: %s\nCidade: %s\nPopulação: %d\nÁrea: %.2f km²\nPIB: %.2f bilhões\nPontos turísticos: %d\n",
           carta2.estado, carta2.codigo, carta2.nomeCidade, carta2.populacao, carta2.area, carta2.pib, carta2.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\nPIB per capita: %.6f bilhões/hab\n\n", carta2.densidadePopulacional, carta2.pibPerCapita);

    // Escolha do atributo para comparação
    // (Aqui, escolhemos População)
    printf("=== Comparação de cartas (Atributo: População) ===\n");
    printf("Carta 1 - %s (%s): %d\n", carta1.nomeCidade, carta1.estado, carta1.populacao);
    printf("Carta 2 - %s (%s): %d\n", carta2.nomeCidade, carta2.estado, carta2.populacao);

    // Comparação com if / else
    if (carta1.populacao > carta2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (carta2.populacao > carta1.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
