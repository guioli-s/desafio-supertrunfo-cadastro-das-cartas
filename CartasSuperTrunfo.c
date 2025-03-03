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
    printf("Digite o PIB: ");
    scanf("%f", &carta->pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    // Calcular densidade populacional e PIB per capita
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib * 1000000000 / carta->populacao;

    // Calcular Super Poder
    carta->superPoder = carta->populacao + carta->area + carta->pib + carta->pontosTuristicos + carta->pibPerCapita + (1 / carta->densidadePopulacional);
}

void exibirCarta(Carta carta) {
    printf("\nInformações da Carta:\n");
    printf("Estado: %c\n", carta.estado);
    printf("Código da Carta: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %lu\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per Capita: %.2f\n", carta.pibPerCapita);
    printf("Super Poder: %.2f\n", carta.superPoder);
}

void compararCartas(Carta carta1, Carta carta2) {
    printf("\nComparação de Cartas:\n");

    printf("População: Carta %d ganhou\n", carta1.populacao > carta2.populacao ? 1 : 2);
    printf("Área: Carta %d ganhou\n", carta1.area > carta2.area ? 1 : 2);
    printf("PIB: Carta %d ganhou\n", carta1.pib > carta2.pib ? 1 : 2);
    printf("Número de Pontos Turísticos: Carta %d ganhou\n", carta1.pontosTuristicos > carta2.pontosTuristicos ? 1 : 2);
    printf("Densidade Populacional: Carta %d ganhou\n", carta1.densidadePopulacional < carta2.densidadePopulacional ? 1 : 2);
    printf("PIB per Capita: Carta %d ganhou\n", carta1.pibPerCapita > carta2.pibPerCapita ? 1 : 2);
    printf("Super Poder: Carta %d ganhou\n", carta1.superPoder > carta2.superPoder ? 1 : 2);
}

int main() {
    Carta carta1, carta2;

    printf("Insira os dados da primeira carta:\n");
    lerCarta(&carta1);
    printf("Insira os dados da segunda carta:\n");
    lerCarta(&carta2);

    printf("\nDados da primeira carta:");
    exibirCarta(carta1);
    printf("\nDados da segunda carta:");
    exibirCarta(carta2);

    compararCartas(carta1, carta2);

    return 0;
}
