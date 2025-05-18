#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EntradaArquivo/Entrada.h"

int main() {
   char arquivo[50], entrada[100], saida[100];
   printf("Insira o nome do arquivo que deseja testar no montador RISC-V: ");
   scanf("%s", arquivo);
   sprintf(entrada, "arquivos/%s", arquivo);
   sprintf(saida, "output/output-%s", arquivo);

 LerEscrever(entrada, saida);

}
