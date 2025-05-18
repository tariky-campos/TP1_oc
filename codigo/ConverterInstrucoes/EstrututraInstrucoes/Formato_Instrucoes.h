#ifndef FORMATO_INSTRUCOES_H_
#define FORMATO_INSTRUCOES_H_
#include <stdio.h>

typedef struct{
    char funct7[8];
    char rs2[6];
    char rs1[6];
    char funct3[4];
    char rd[6];
    char opcode[8];
}TipoR;

typedef struct{
    char immediate[13];
    char rs1[6];
    char funct3[4];
    char rd[6];
    char opcode[8];
}TipoI;

typedef struct{
    char imm11[8];
    char rs2[6];
    char rs1[6];
    char funct[4];
    char imm4[6];
    char opcode[8];
}TipoS;

typedef struct {
    char imm12[2];    
    char imm10_5[7];  
    char rs2[6];      
    char rs1[6];      
    char funct3[4];   
    char imm4_1[5];   
    char imm11[2];    
    char opcode[8];   
} TipoSB;

typedef struct{
   char imm1[2];
   char imm10[11];
   char imm1_2[2];
   char imm8[9];
   char rd[6];
   char opcode[8];
}TipoUJ;

void TransformarBinario(int Numero, int QuantidadeBits, char* Transformado);

void PreencherInstrucaoR(TipoR* instrucao, int funct7, int rs2, int rs1, int funct3, int rd, int opcode);

void PreencherInstrucaoI(TipoI* instrucao, int immediate, int rs1, int funct3, int rd, int opcode);

void PreencherInstrucaoS(TipoS* instrucao, char imm11[], int rs2, int rs1, int funct, char imm4[], int opcode);

void PreencherInstrucaoSB(TipoSB* instrucao, char imm12[], char imm10[], int rs2, int rs1, int funct, char imm4[], char imm11[], int opcode);

void PreencherInstrucaoUJ(TipoUJ* instrucao, char imm1[], char imm10[], char imm1_2[], char imm8[], int rd, int opcode);

void ImprimirR(TipoR* instrucao, FILE *outputFile); 

void ImprimirI(TipoI* instrucao, FILE *outputFile);

void ImprimirS(TipoS* instrucao, FILE *outputFile);

void ImprimirSB(TipoSB* instrucao, FILE *outputFile);

void ImprimirUJ(TipoUJ* instrucao, FILE *outputFile);

#endif