#include <stdio.h>
#include <string.h>

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

int main() {
    // Cadastro de duas cartas pré-definidas (você pode alterar os valores)
    struct Carta carta1 = {"BR", "A01", "Brasil", 214000000, 8515767.0, 22000.0, 25};
    struct Carta carta2 = {"AR", "A02", "Argentina", 46000000, 2780400.0, 6400.0, 18};

    // Cálculo dos atributos derivados
    carta1.densidadeDemografica = carta1.populacao / carta1.area;
    carta2.densidadeDemografica = carta2.populacao / carta2.area;

    carta1.pibPerCapita = carta1.pib / carta1.populacao;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    int opcao;

    // Menu interativo
    printf("===== SUPER TRUNFO - COMPARAÇÃO DE PAÍSES =====\n");
    printf("Cartas cadastradas:\n");
    printf("1. %s (%s)\n", carta1.nomePais, carta1.estado);
    printf("2. %s (%s)\n\n", carta2.nomePais, carta2.estado);

    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de pontos turísticos\n");
    printf("5 - Densidade demográfica\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");

    // Estrutura switch para tratar a escolha do usuário
    switch (opcao) {
        case 1:
            printf("Atributo escolhido: População\n");
            printf("%s: %d habitantes\n", carta1.nomePais, carta1.populacao);
            printf("%s: %d habitantes\n", carta2.nomePais, carta2.populacao);

            if (carta1.populacao > carta2.populacao) {
                printf("Resultado: %s venceu!\n", carta1.nomePais);
            } else if (carta2.populacao > carta1.populacao) {
                printf("Resultado: %s venceu!\n", carta2.nomePais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 2:
            printf("Atributo escolhido: Área\n");
            printf("%s: %.2f km²\n", carta1.nomePais, carta1.area);
            printf("%s: %.2f km²\n", carta2.nomePais, carta2.area);

            if (carta1.area > carta2.area) {
                printf("Resultado: %s venceu!\n", carta1.nomePais);
            } else if (carta2.area > carta1.area) {
                printf("Resultado: %s venceu!\n", carta2.nomePais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 3:
            printf("Atributo escolhido: PIB\n");
            printf("%s: %.2f bilhões de dólares\n", carta1.nomePais, carta1.pib);
            printf("%s: %.2f bilhões de dólares\n", carta2.nomePais, carta2.pib);

            if (carta1.pib > carta2.pib) {
                printf("Resultado: %s venceu!\n", carta1.nomePais);
            } else if (carta2.pib > carta1.pib) {
                printf("Resultado: %s venceu!\n", carta2.nomePais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 4:
            printf("Atributo escolhido: Número de pontos turísticos\n");
            printf("%s: %d pontos turísticos\n", carta1.nomePais, carta1.pontosTuristicos);
            printf("%s: %d pontos turísticos\n", carta2.nomePais, carta2.pontosTuristicos);

            if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
                printf("Resultado: %s venceu!\n", carta1.nomePais);
            } else if (carta2.pontosTuristicos > carta1.pontosTuristicos) {
                printf("Resultado: %s venceu!\n", carta2.nomePais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 5:
            printf("Atributo escolhido: Densidade demográfica\n");
            printf("%s: %.4f hab/km²\n", carta1.nomePais, carta1.densidadeDemografica);
            printf("%s: %.4f hab/km²\n", carta2.nomePais, carta2.densidadeDemografica);

            // Regra invertida: menor densidade vence
            if (carta1.densidadeDemografica < carta2.densidadeDemografica) {
                printf("Resultado: %s venceu! (menor densidade demográfica)\n", carta1.nomePais);
            } else if (carta2.densidadeDemografica < carta1.densidadeDemografica) {
                printf("Resultado: %s venceu! (menor densidade demográfica)\n", carta2.nomePais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        default:
            printf("Opção inválida! Tente novamente com um número entre 1 e 5.\n");
    }

    printf("\n=== Fim da rodada! ===\n");

    return 0;
}
