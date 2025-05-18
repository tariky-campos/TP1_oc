#include "Entrada.h"
#include "../ConverterInstrucoes/Converte_Instrucoes.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void LerEscrever(char f[], char s[]){
    FILE *file = fopen(f, "r");
    FILE *outputFile = fopen(s, "w");

    if(file && outputFile){
        char linha[50]; 
        while (fgets(linha, sizeof(linha), file)){
            char tipo[12];
            sscanf(linha, "%s", tipo);  
            TipoR instrucao; TipoI instrucaoo; TipoS instrucaooo; TipoSB instrucaoooo; TipoUJ instrucaooooo;
            char r1[10], r2[10], r3[10];
            int re1, re2, re3;  
            char j = IdentificarTipo(tipo);
            switch (j) {
            case 'R':
                sscanf(linha, "%s %[^,], %[^,], %s", tipo, r1, r2, r3);
                re1 = ConverterNumero(r1);
                re2 = ConverterNumero(r2);
                re3 = ConverterNumero(r3);
                CabecarioR(&instrucao, tipo, re1, re2, re3, outputFile);
                break;

            case 'I':
            if (strchr(linha, '(')) {  
                sscanf(linha, "%s %[^,], %d(%[^)])", tipo, r1, &re3, r2);  
                re1 = ConverterNumero(r1);  
                re2 = ConverterNumero(r2);  
                CabecarioI(&instrucaoo, tipo, re1, re2, re3, outputFile);
            } else {  
                sscanf(linha, "%s %[^,], %[^,], %s", tipo, r1, r2, r3);  
                re1 = ConverterNumero(r1);  
                re2 = ConverterNumero(r2); 
                re3 = ConverterNumero(r3);  
                CabecarioI(&instrucaoo, tipo, re1, re2, re3, outputFile);
            }
            break;
            case 'S':
            if (strchr(linha, '(')) {  
                sscanf(linha, "%s %[^,], %d(%[^)])", tipo, r1, &re3, r2);  
                re1 = ConverterNumero(r1);  
                re2 = ConverterNumero(r2);  
                CabecarioS(&instrucaooo, tipo, re1, re2, re3, outputFile);
            } else {  
                sscanf(linha, "%s %[^,], %[^,], %s", tipo, r1, r2, r3);  
                re1 = ConverterNumero(r1);  
                re2 = ConverterNumero(r2); 
                re3 = ConverterNumero(r3);  
                CabecarioS(&instrucaooo, tipo, re1, re2, re3, outputFile);
            }
            break;
            case 'B':
            if (strchr(linha, '(')) {  
                sscanf(linha, "%s %[^,], %d(%[^)])", tipo, r1, &re3, r2);  
                re1 = ConverterNumero(r1);  
                re2 = ConverterNumero(r2);  
                CabecarioSB(&instrucaoooo, tipo, re1, re2, re3, outputFile);
            } else {  
                sscanf(linha, "%s %[^,], %[^,], %s", tipo, r1, r2, r3);  
                re1 = ConverterNumero(r1);  
                re2 = ConverterNumero(r2); 
                re3 = ConverterNumero(r3);  
                CabecarioSB(&instrucaoooo, tipo, re1, re2, re3, outputFile);
            }
            break;
            case 'P':
            if(tipo[0]=='j'){
                sscanf(linha, "%s %s", tipo, r1);
                re1 = ConverterNumero(r1);
                CabecarioUJ(&instrucaooooo, tipo, 0, re1, outputFile);
            }
            sscanf(linha, "%s %[^,], %s", tipo, r1, r2);
            re1 = ConverterNumero(r1);
            re2 = ConverterNumero(r2);
            CabecarioPseudo(&instrucaoo, tipo, re1, re2, outputFile);
            break;

            case 'J':
            sscanf(linha, "%s %[^,], %s", tipo, r1, r2);
            re1 = ConverterNumero(r1);
            re2 = ConverterNumero(r2);
            CabecarioUJ(&instrucaooooo, tipo, re1, re2, outputFile);
            break;
            default:
                break;
            }
        }
        
        fclose(file);
        fclose(outputFile);
    }
    else{
        printf("\nErro ao abrir o arquivo\n");
    }
}
