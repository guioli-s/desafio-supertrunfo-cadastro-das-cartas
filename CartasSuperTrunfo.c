#include <stdio.h>

// Estrutura que representa uma carta do jogo Super Trunfo
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

// Função para ler os dados de uma carta
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

    // Calcula a densidade populacional, PIB per capita e super poder da carta
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib * 1000000000 / carta->populacao;
    carta->superPoder = carta->populacao + carta->area + carta->pib + carta->pontosTuristicos + carta->pibPerCapita + (1 / carta->densidadePopulacional);
}

// Função para exibir os dados de uma carta
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

// Função para obter o valor de um atributo específico de uma carta
float obterValorAtributo(Carta carta, int atributo) {
    switch (atributo) {
        case 1: return carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return carta.pontosTuristicos;
        case 5: return carta.densidadePopulacional;
        default: return 0;
    }
}

// Função para comparar dois atributos de duas cartas
void compararCartas(Carta carta1, Carta carta2, int atributo1, int atributo2) {
    float valor1Carta1 = obterValorAtributo(carta1, atributo1);
    float valor1Carta2 = obterValorAtributo(carta2, atributo1);
    float valor2Carta1 = obterValorAtributo(carta1, atributo2);
    float valor2Carta2 = obterValorAtributo(carta2, atributo2);

    printf("\nComparação das Cartas:\n");
    printf("Carta 1 - Nome da Cidade: %s\n", carta1.nomeCidade);
    printf("Carta 2 - Nome da Cidade: %s\n", carta2.nomeCidade);

    // Exibe o primeiro atributo escolhido para comparação
    printf("Atributo 1: ");
    switch (atributo1) {
        case 1: printf("População\n"); break;
        case 2: printf("Área\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Número de Pontos Turísticos\n"); break;
        case 5: printf("Densidade Populacional\n"); break;
    }
    printf("Carta 1: %.2f\n", valor1Carta1);
    printf("Carta 2: %.2f\n", valor1Carta2);

    // Exibe o segundo atributo escolhido para comparação
    printf("Atributo 2: ");
    switch (atributo2) {
        case 1: printf("População\n"); break;
        case 2: printf("Área\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Número de Pontos Turísticos\n"); break;
        case 5: printf("Densidade Populacional\n"); break;
    }
    printf("Carta 1: %.2f\n", valor2Carta1);
    printf("Carta 2: %.2f\n", valor2Carta2);

    // Calcula a soma dos valores dos atributos escolhidos para cada carta
    float somaCarta1 = valor1Carta1 + valor2Carta1;
    float somaCarta2 = valor1Carta2 + valor2Carta2;

    printf("Soma dos Atributos:\n");
    printf("Carta 1: %.2f\n", somaCarta1);
    printf("Carta 2: %.2f\n", somaCarta2);

    // Determina a carta vencedora com base na soma dos atributos
    if (somaCarta1 > somaCarta2) {
        printf("Carta 1 venceu!\n");
    } else if (somaCarta1 < somaCarta2) {
        printf("Carta 2 venceu!\n");
    } else {
        printf("Empate!\n");
    }
}

// Função para exibir o menu de atributos disponíveis para comparação
void exibirMenuAtributos(int atributoEscolhido) {
    printf("\nEscolha um atributo para comparar:\n");
    if (atributoEscolhido != 1) printf("1. População\n");
    if (atributoEscolhido != 2) printf("2. Área\n");
    if (atributoEscolhido != 3) printf("3. PIB\n");
    if (atributoEscolhido != 4) printf("4. Número de Pontos Turísticos\n");
    if (atributoEscolhido != 5) printf("5. Densidade Populacional\n");
    printf("Digite o número do atributo: ");
}

int main() {
    Carta carta1, carta2;
    int atributo1, atributo2;

    // Lê os dados da primeira carta
    printf("Insira os dados da primeira carta:\n");
    lerCarta(&carta1);

    // Lê os dados da segunda carta
    printf("\nInsira os dados da segunda carta:\n");
    lerCarta(&carta2);

    // Exibe os dados das cartas
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    // Exibe o menu de atributos e lê o primeiro atributo escolhido
    exibirMenuAtributos(0);
    scanf("%d", &atributo1);

    // Exibe o menu de atributos e lê o segundo atributo escolhido, garantindo que seja diferente do primeiro
    do {
        exibirMenuAtributos(atributo1);
        scanf("%d", &atributo2);
    } while (atributo2 == atributo1);

    // Compara as cartas com base nos atributos escolhidos
    compararCartas(carta1, carta2, atributo1, atributo2);

    return 0;
}
