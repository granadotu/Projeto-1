// Nome: Artur Granado Novaes        TIA: 32336901
// Nome: Marcelo Luis Simone Lucas   TIA: 32340370

#include <stdio.h>
#include <math.h>


void imprimirPolinomio(int polinomio[], int grau) {
  printf("P(x) = ");
  for (int i = grau; i >= 0; i-- ) {
    if(polinomio[i] != 0) {
      if(i == grau) {
        printf("%dx^%d", polinomio[i], i);
      } else {
        if(polinomio[i] > 0) {
          printf(" + %dx^%d", polinomio[i], i);
        } else {
          printf(" %dx^%d", polinomio[i], i);
        }
      }
    }
  }
  printf("\n");
}


int calcularPolinomios(int polinomio[], int grau, int x) {
  int resultado = 0;
  for(int i = grau; i >= 0; i--) {
    resultado += polinomio[i] * pow(x, i);
  }
  return resultado;
}


void somarPolinomios(int polinomio1[], int grau1, int polinomio2[], int grau2, int resultado[]) {
  int grauResultado;
  if(grau1 > grau2) {
    grauResultado = grau1;
  } else {
    grauResultado = grau2;
  }

  for(int i = 0; i <= grauResultado; i++) {
    if(i <= grau1 && i <= grau2) {
      resultado[i] = polinomio1[i] + polinomio2[i];
    } else if (i <= grau1) {
      resultado[i] = polinomio1[i];
    } else {
    resultado[i] = polinomio2[i];
    }
  }
}


void multiplicarPolinomios(int polinomio1[], int grau1, int polinomio2[], int grau2, int resultado[]) {
  int grauResultado = grau1 + grau2;

  for(int i = 0; i <= grauResultado; i++) {
    resultado[i] = 0.0;
  }

  for(int i = 0; i <= grau1; i++) {
    for(int j = 0; j <= grau2; j++) {
      resultado[i + j] += polinomio1[i] * polinomio2[j];
    }
  }
}


int main() {
  int grau1, grau2;
  int x;
  
  printf("*****************************************\n");
  printf("  Bem vindo a calculadora de Polinômios  \n");
  printf("*****************************************\n");
  printf("\n");

  printf("Digite o grau do primeiro polinomio: ");
  scanf("%d", &grau1);
  int polinomio1[grau1 + 1];
  printf("\n");

  printf("Digite os coeficientes do primeiro polinomio (do maior grau para o menor):\n");
  for (int i = grau1; i >= 0; i--) {
    scanf("%d", &polinomio1[i]);
    }

    printf("Digite o grau do segundo polinomio: ");
    scanf("%d", &grau2);
    int polinomio2[grau2 + 1];
    printf("\n");
    printf("Digite os coeficientes do segundo polinomio (do maior grau para o menor):\n");
    for (int i = grau2; i >= 0; i--) {
        scanf("%d", &polinomio2[i]);
      
    }
  printf("\n");
  printf("Primeiro polinômio: ");
  imprimirPolinomio(polinomio1, grau1);
      
  printf("Segundo polinômio: ");
  imprimirPolinomio(polinomio2, grau2);

  while(1) {
    printf("\n");
    printf(" -----------------------------------------------\n");
    printf("| Digite um número para selecionar alguma opção |\n");
    printf(" -----------------------------------------------\n");
    printf("\n");
    printf(" ------------------------------------\n");
    printf("|  1. Calcular o Valor do Polinômio  |\n");      
    printf("|  2. Somar os Polinômios            |\n");
    printf("|  3. Multiplicar os Polinômios      |\n");
    printf("|  4. Sair                           |\n");
    printf(" ------------------------------------\n");

      int numUser;
      scanf("%d", &numUser);
      
      switch(numUser){
        case 1:
            {
             printf("Digite o valor de x: ");
                scanf("%d", &x);
                printf("Resultado do primeiro polinomio: %d\n", calcularPolinomios(polinomio1, grau1, x));
                printf("Resultado do segundo polinomio: %d\n", calcularPolinomios(polinomio2, grau2, x));
                break;
            }
        case 2:
          {
            int grauResultado;
                    if (grau1 > grau2) {
                        grauResultado = grau1;
                    } else {
                        grauResultado = grau2;
                    }
                    int resultado[grauResultado + 1];
                    somarPolinomios(polinomio1, grau1, polinomio2, grau2, resultado);
                    printf("Resultado da soma dos polinomios:\n");
                    imprimirPolinomio(resultado, grauResultado);
          }
          break;
        case 3:
          {
            int grauResultado = grau1 + grau2;
            int resultado[grauResultado + 1];
            multiplicarPolinomios(polinomio1, grau1, polinomio2, grau2, resultado);
            printf("Resultado da multiplicacao dos polinomios:\n");
            imprimirPolinomio(resultado, grauResultado);
          }
          break;
        
        case 4:
            return 0;
      }
  }
  return 0;
  }
