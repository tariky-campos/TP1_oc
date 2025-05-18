#include "Formato_Instrucoes.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void TransformarBinario(int Numero, int QuantidadeBits, char* Transformado){
    unsigned int valor = (unsigned int)Numero;
    for(int i = QuantidadeBits-1; i >= 0; i--) {
        int r = valor >> i;
         if(r & 1) {
            Transformado[QuantidadeBits - 1 - i] = '1';
         }
        else{
            Transformado[QuantidadeBits - 1 - i] = '0';
         }
     }
    Transformado[QuantidadeBits] = '\0';
}

void PreencherInstrucaoR(TipoR* instrucao, int funct7, int rs2, int rs1, int funct3, int rd, int opcode){
    TransformarBinario(funct7, 7, instrucao->funct7);
    TransformarBinario(rs2, 5, instrucao->rs2);
    TransformarBinario(rs1, 5, instrucao->rs1);
    TransformarBinario(funct3, 3, instrucao->funct3);
    TransformarBinario(rd, 5, instrucao->rd);
    TransformarBinario(opcode, 7, instrucao->opcode);
}

void PreencherInstrucaoI(TipoI* instrucao, int immediate, int rs1, int funct3, int rd, int opcode){
    TransformarBinario(immediate, 12, instrucao->immediate);
    TransformarBinario(rs1, 5, instrucao->rs1);
    TransformarBinario(funct3, 3, instrucao->funct3);
    TransformarBinario(rd, 5, instrucao->rd);
    TransformarBinario(opcode, 7, instrucao->opcode);
}

void PreencherInstrucaoS(TipoS* instrucao, char imm11[], int rs2, int rs1, int funct, char imm4[], int opcode){
    strcpy(instrucao->imm11, imm11);
    TransformarBinario(rs2, 5, instrucao->rs2);
    TransformarBinario(rs1, 5, instrucao->rs1);
    TransformarBinario(funct, 3, instrucao->funct);
    strcpy(instrucao->imm4, imm4);
    TransformarBinario(opcode, 7, instrucao->opcode);
}

void PreencherInstrucaoSB(TipoSB* instrucao, char imm12[], char imm10[], int rs2, int rs1, int funct, char imm4[], char imm11[], int opcode) {
    strcpy(instrucao->imm12, imm12);
    strcpy(instrucao->imm10_5, imm10);
    TransformarBinario(rs2, 5, instrucao->rs2);
    TransformarBinario(rs1, 5, instrucao->rs1);
    TransformarBinario(funct, 3, instrucao->funct3);
    strcpy(instrucao->imm4_1, imm4);
    strcpy(instrucao->imm11, imm11);
    TransformarBinario(opcode, 7, instrucao->opcode);
}

void PreencherInstrucaoUJ(TipoUJ* instrucao, char imm1[], char imm10[], char imm1_2[], char imm8[], int rd, int opcode){
    strcpy(instrucao->imm1, imm1);
    strcpy(instrucao->imm10, imm10);
    strcpy(instrucao->imm1_2, imm1_2);
    strcpy(instrucao->imm8, imm8);
    TransformarBinario(rd, 5, instrucao->rd);
    TransformarBinario(opcode, 7, instrucao->opcode);
}

void ImprimirR(TipoR* instrucao, FILE *outputFile){
    printf("%s", instrucao->funct7);
    printf("%s", instrucao->rs2);
    printf("%s", instrucao->rs1);
    printf("%s", instrucao->funct3);
    printf("%s", instrucao->rd);
    printf("%s\n", instrucao->opcode);
    fprintf(outputFile,"%s", instrucao->funct7);
    fprintf(outputFile,"%s", instrucao->rs2);
    fprintf(outputFile,"%s", instrucao->rs1);
    fprintf(outputFile,"%s", instrucao->funct3);
    fprintf(outputFile,"%s", instrucao->rd);
    fprintf(outputFile,"%s\n", instrucao->opcode);
}

void ImprimirI(TipoI* instrucao, FILE *outputFile){
    printf("%s", instrucao->immediate);
    printf("%s", instrucao->rs1);
    printf("%s", instrucao->funct3);
    printf("%s", instrucao->rd);
    printf("%s\n", instrucao->opcode);
    fprintf(outputFile,"%s", instrucao->immediate);
    fprintf(outputFile,"%s", instrucao->rs1);
    fprintf(outputFile,"%s", instrucao->funct3);
    fprintf(outputFile,"%s", instrucao->rd);
    fprintf(outputFile,"%s\n", instrucao->opcode);    
}

void ImprimirS(TipoS* instrucao, FILE *outputFile){
    printf("%s", instrucao->imm11);
    printf("%s", instrucao->rs2);
    printf("%s", instrucao->rs1);
    printf("%s", instrucao->funct);
    printf("%s", instrucao->imm4);
    printf("%s\n", instrucao->opcode);
    fprintf(outputFile,"%s", instrucao->imm11);
    fprintf(outputFile,"%s", instrucao->rs2);
    fprintf(outputFile,"%s", instrucao->rs1);
    fprintf(outputFile,"%s", instrucao->funct);
    fprintf(outputFile,"%s", instrucao->imm4);
    fprintf(outputFile,"%s\n", instrucao->opcode);
}

void ImprimirSB(TipoSB* instrucao, FILE *outputFile){
    printf("%s", instrucao->imm12);
    printf("%s", instrucao->imm10_5);
    printf("%s", instrucao->rs2);
    printf("%s", instrucao->rs1);
    printf("%s", instrucao->funct3);
    printf("%s", instrucao->imm4_1);
    printf("%s", instrucao->imm11);
    printf("%s\n", instrucao->opcode);
    fprintf(outputFile,"%s", instrucao->imm12);
    fprintf(outputFile,"%s", instrucao->imm10_5);
    fprintf(outputFile,"%s", instrucao->rs2);
    fprintf(outputFile,"%s", instrucao->rs1);
    fprintf(outputFile,"%s", instrucao->funct3);
    fprintf(outputFile,"%s", instrucao->imm4_1);
    fprintf(outputFile,"%s", instrucao->imm11);
    fprintf(outputFile,"%s\n", instrucao->opcode);
}

void ImprimirUJ(TipoUJ* instrucao, FILE *outputFile){
    printf("%s", instrucao->imm1);
    printf("%s", instrucao->imm10);
    printf("%s", instrucao->imm1_2);
    printf("%s", instrucao->imm8);
    printf("%s", instrucao->rd);
    printf("%s\n", instrucao->opcode);
    fprintf(outputFile,"%s", instrucao->imm1);
    fprintf(outputFile,"%s", instrucao->imm10);
    fprintf(outputFile,"%s", instrucao->imm1_2);
    fprintf(outputFile,"%s", instrucao->imm8);
    fprintf(outputFile,"%s", instrucao->rd);
    fprintf(outputFile,"%s\n", instrucao->opcode);
}
