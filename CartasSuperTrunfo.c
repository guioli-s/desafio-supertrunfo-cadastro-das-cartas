#include <stdio.h>

typedef struct {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
    float superPoder;
} Carta;

void lerCarta(Carta *carta) {
    printf("Digite o estado (A-H): ");
    scanf(" %c", &carta->estado);
    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", carta->codigo);
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta->nomeCidade);
    printf("Digite a população: ");
    scanf("%lu", &carta->populacao);
    printf("Digite a área (em km²): ");
    scanf("%f", &carta->area);
    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &carta->pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib * 1000000000 / carta->populacao;
    carta->superPoder = carta->populacao + carta->area + carta->pib + carta->pontosTuristicos + carta->pibPerCapita + (1 / carta->densidadePopulacional);
}

void exibirCarta(Carta carta, int numero) {
    printf("\nCarta %d:\n", numero);
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %lu\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f habitantes/km²\n", carta.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", carta.pibPerCapita);
    printf("Super Poder: %.2f\n", carta.superPoder);
}

void compararCartas(Carta carta1, Carta carta2, int atributo) {
    printf("\nComparação das Cartas:\n");
    printf("Carta 1 - Nome da Cidade: %s\n", carta1.nomeCidade);
    printf("Carta 2 - Nome da Cidade: %s\n", carta2.nomeCidade);

    switch (atributo) {
        case 1:
            printf("Atributo: População\n");
            printf("População da Carta 1: %lu\n", carta1.populacao);
            printf("População da Carta 2: %lu\n", carta2.populacao);
            if (carta1.populacao > carta2.populacao) {
                printf("Carta 1 venceu!\n");
            } else if (carta1.populacao < carta2.populacao) {
                printf("Carta 2 venceu!\n");
            } else {
                printf("Empate!\n");
            }
            break;
        case 2:
            printf("Atributo: Área\n");
            printf("Área da Carta 1: %.2f km²\n", carta1.area);
            printf("Área da Carta 2: %.2f km²\n", carta2.area);
            if (carta1.area > carta2.area) {
                printf("Carta 1 venceu!\n");
            } else if (carta1.area < carta2.area) {
                printf("Carta 2 venceu!\n");
            } else {
                printf("Empate!\n");
            }
            break;
        case 3:
            printf("Atributo: PIB\n");
            printf("PIB da Carta 1: %.2f bilhões de reais\n", carta1.pib);
            printf("PIB da Carta 2: %.2f bilhões de reais\n", carta2.pib);
            if (carta1.pib > carta2.pib) {
                printf("Carta 1 venceu!\n");
            } else if (carta1.pib < carta2.pib) {
                printf("Carta 2 venceu!\n");
            } else {
                printf("Empate!\n");
            }
            break;
        case 4:
            printf("Atributo: Número de Pontos Turísticos\n");
            printf("Número de Pontos Turísticos da Carta 1: %d\n", carta1.pontosTuristicos);
            printf("Número de Pontos Turísticos da Carta 2: %d\n", carta2.pontosTuristicos);
            if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
                printf("Carta 1 venceu!\n");
            } else if (carta1.pontosTuristicos < carta2.pontosTuristicos) {
                printf("Carta 2 venceu!\n");
            } else {
                printf("Empate!\n");
            }
            break;
        case 5:
            printf("Atributo: Densidade Populacional\n");
            printf("Densidade Populacional da Carta 1: %.2f habitantes/km²\n", carta1.densidadePopulacional);
            printf("Densidade Populacional da Carta 2: %.2f habitantes/km²\n", carta2.densidadePopulacional);
            if (carta1.densidadePopulacional < carta2.densidadePopulacional) {
                printf("Carta 1 venceu!\n");
            } else if (carta1.densidadePopulacional > carta2.densidadePopulacional) {
                printf("Carta 2 venceu!\n");
            } else {
                printf("Empate!\n");
            }
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }
}

int main() {
    Carta carta1, carta2;
    int atributo;

    printf("Insira os dados da primeira carta:\n");
    lerCarta(&carta1);

    printf("\nInsira os dados da segunda carta:\n");
    lerCarta(&carta2);

    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    printf("\nEscolha o atributo para comparar:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Número de Pontos Turísticos\n");
    printf("5. Densidade Populacional\n");
    printf("Digite o número do atributo: ");
    scanf("%d", &atributo);

    compararCartas(carta1, carta2, atributo);

    return 0;
}