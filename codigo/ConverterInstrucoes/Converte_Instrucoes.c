#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Converte_Instrucoes.h"

int ConverterNumero(char r1[10]) {
    int numero;
    if (strncmp(r1, "0x", 2) == 0 || strncmp(r1, "0X", 2) == 0) {
        numero = (int)strtol(r1 + 2, NULL, 16);
    } else if (strncmp(r1, "0b", 2) == 0 || strncmp(r1, "0B", 2) == 0) {
        numero = (int)strtol(r1 + 2, NULL, 2);
    } else if (r1[0] == 'x') {
        numero = atoi(r1 + 1);
    } else {
        numero = atoi(r1);
    }
    return numero;
}

char IdentificarTipo (char tipo[6]){
    if (strcmp(tipo, "add")==0 
    || strcmp(tipo, "sub")==0 || strcmp(tipo, "sll")==0 
    || strcmp(tipo, "xor")==0|| strcmp(tipo, "srl")==0
    || strcmp(tipo, "sra")==0|| strcmp(tipo, "or")==0
    || strcmp(tipo, "and")==0|| strcmp(tipo, "lr.d")==0
    || strcmp(tipo, "sc.d")==0){ 
        return 'R';
      
    }
    else if(strcmp(tipo, "lb")==0 
    || strcmp(tipo, "lh")==0 || strcmp(tipo, "lw")==0 
    || strcmp(tipo, "ld")==0|| strcmp(tipo, "lbu")==0
    || strcmp(tipo, "lhu")==0|| strcmp(tipo, "lwu")==0
    || strcmp(tipo, "addi")==0|| strcmp(tipo, "slli")==0
    || strcmp(tipo, "xori")==0 ||strcmp(tipo, "srli")==0 
    || strcmp(tipo, "srai")==0 || strcmp(tipo, "ori")==0 
    || strcmp(tipo, "andi")==0|| strcmp(tipo, "jalr")==0){
        return 'I';
        
    }
    else if(strcmp(tipo, "sb")==0 || strcmp(tipo, "sh")==0
    || strcmp(tipo, "sw")==0 || strcmp(tipo, "sd")==0){ 
        return 'S';
      
    }
    else if(strcmp(tipo, "beq")==0 || strcmp(tipo, "bne")==0
    || strcmp(tipo, "blt")==0 || strcmp(tipo, "bge")==0 
    ||strcmp(tipo, "bltu")==0 || strcmp(tipo, "bgeu")==0){
        return 'B';
    }

    else if(strcmp(tipo, "mv")==0 || strcmp(tipo, "li")==0
    || strcmp(tipo, "j")==0 || strcmp(tipo, "la")==0){
        return 'P';
    }

    else if(strcmp(tipo, "jal")==0){
        return 'J';
    }
}

void CabecarioR(TipoR* instrucao, char tipo[6], int r1, int r2, int r3, FILE *outputFile){
    if (strcmp(tipo, "add")==0){
        PreencherInstrucaoR(instrucao, 0, r3, r2, 0, r1, 51);
        ImprimirR(instrucao, outputFile);
    }
    if(strcmp(tipo, "sub")==0){
        PreencherInstrucaoR(instrucao, 32, r3, r2, 0, r1, 51);
         ImprimirR(instrucao, outputFile);
    }   
    if(strcmp(tipo, "sll")==0){
        PreencherInstrucaoR(instrucao, 0, r3, r2, 1, r1, 51);
         ImprimirR(instrucao, outputFile);
    } 
    if(strcmp(tipo, "xor")==0){
        PreencherInstrucaoR(instrucao, 0, r3, r2, 4, r1, 51);
         ImprimirR(instrucao, outputFile);
    }  
    if(strcmp(tipo, "srl")==0){
        PreencherInstrucaoR(instrucao, 0, r3, r2, 5, r1, 51);
         ImprimirR(instrucao, outputFile);
    }
    if(strcmp(tipo, "sra")==0){
        PreencherInstrucaoR(instrucao, 0, r3, r2, 5, r1, 51);
         ImprimirR(instrucao, outputFile);
    }  
    if(strcmp(tipo, "or")==0){
        PreencherInstrucaoR(instrucao, 0, r3, r2, 6, r1, 51);
         ImprimirR(instrucao, outputFile);
    }
    if(strcmp(tipo, "and")==0){
        PreencherInstrucaoR(instrucao, 0, r3, r2, 7, r1, 51);
         ImprimirR(instrucao, outputFile);
    }  
    if(strcmp(tipo, "lr.d")==0){
        PreencherInstrucaoR(instrucao, 6, r3, r2, 3, r1, 51);
         ImprimirR(instrucao, outputFile);
    }
    if(strcmp(tipo, "sc.d")==0){
        PreencherInstrucaoR(instrucao, 12, r3, r2, 3, r1, 51);
         ImprimirR(instrucao, outputFile);
    }
}

void CabecarioI(TipoI* instrucao, char tipo[6], int r1, int r2, int r3, FILE *outputFile){
    if(strcmp(tipo, "lb")==0){
        PreencherInstrucaoI(instrucao, r3, r2 , 0, r1, 3);
        ImprimirI(instrucao, outputFile);
    }
    if(strcmp(tipo, "lh")==0){
        PreencherInstrucaoI(instrucao, r3, r2 , 1, r1, 3);
        ImprimirI(instrucao, outputFile);
    }  
    if(strcmp(tipo, "lw")==0){
        PreencherInstrucaoI(instrucao, r3, r2 , 2, r1, 3);
        ImprimirI(instrucao, outputFile);
    } 
    if(strcmp(tipo, "ld")==0){
        PreencherInstrucaoI(instrucao, r3, r2 , 3, r1, 3);
        ImprimirI(instrucao, outputFile);
    } 
    if(strcmp(tipo, "lbu")==0){
        PreencherInstrucaoI(instrucao, r3, r2 , 4, r1, 3);
        ImprimirI(instrucao, outputFile);
    }
    if(strcmp(tipo, "lhu")==0){
        PreencherInstrucaoI(instrucao, r3, r2 , 5, r1, 3);
        ImprimirI(instrucao, outputFile);
    } 
    if(strcmp(tipo, "lwu")==0){
        PreencherInstrucaoI(instrucao, r3, r2 , 6, r1, 3);
        ImprimirI(instrucao, outputFile);
    }
    if(strcmp(tipo, "addi")==0){
        PreencherInstrucaoI(instrucao, r3, r2 , 0, r1, 19);
        ImprimirI(instrucao, outputFile);
    } 
    if(strcmp(tipo, "slli")==0){
        char funct7[] = "0000000";
        char shamt[6];
        char imediatoCompleto[13];
        TransformarBinario(r3, 5, shamt);
        strcpy(imediatoCompleto, funct7);        
        strcat(imediatoCompleto, shamt);         
        strcpy(instrucao->immediate, imediatoCompleto);
        TransformarBinario(r2, 5, instrucao->rs1);
        TransformarBinario(1, 3, instrucao->funct3);
        TransformarBinario(r1, 5, instrucao->rd);
        TransformarBinario(19, 7, instrucao->opcode);
        ImprimirI(instrucao, outputFile);
    }
    if(strcmp(tipo, "xori")==0){
        PreencherInstrucaoI(instrucao, r3, r2 , 4, r1, 19);
        ImprimirI(instrucao, outputFile);
    } 
    if(strcmp(tipo, "srli")==0){
        char funct7[] = "0000000";
        char shamt[6];
        char imediatoCompleto[13];
        TransformarBinario(r3, 5, shamt);
        strcpy(imediatoCompleto, funct7);        
        strcat(imediatoCompleto, shamt);         
        strcpy(instrucao->immediate, imediatoCompleto);
        TransformarBinario(r2, 5, instrucao->rs1);
        TransformarBinario(5, 3, instrucao->funct3);
        TransformarBinario(r1, 5, instrucao->rd);
        TransformarBinario(19, 7, instrucao->opcode);
        ImprimirI(instrucao, outputFile);
    } 
    if(strcmp(tipo, "srai")==0){
        char funct7[] = "0100000";
        char shamt[6];
        char imediatoCompleto[13];
        TransformarBinario(r3, 5, shamt);
        strcpy(imediatoCompleto, funct7);        
        strcat(imediatoCompleto, shamt);         
        strcpy(instrucao->immediate, imediatoCompleto);
        TransformarBinario(r2, 5, instrucao->rs1);
        TransformarBinario(5, 3, instrucao->funct3);
        TransformarBinario(r1, 5, instrucao->rd);
        TransformarBinario(19, 7, instrucao->opcode);
        ImprimirI(instrucao, outputFile);
    }  
    if(strcmp(tipo, "ori")==0){
        PreencherInstrucaoI(instrucao, r3, r2 , 6, r1, 19);
        ImprimirI(instrucao, outputFile);
    } 
    if(strcmp(tipo, "andi")==0){
        PreencherInstrucaoI(instrucao, r3, r2 , 7, r1, 19);
        ImprimirI(instrucao, outputFile);
    } 
    if(strcmp(tipo, "jalr")==0){
        PreencherInstrucaoI(instrucao, r3, r2 , 0, r1, 103);
        ImprimirI(instrucao, outputFile);
    }
}

void CabecarioS(TipoS* instrucao, char tipo[6], int r1, int r2, int r3, FILE *outputFile){
    if(strcmp(tipo, "sb")==0){
        char imediatoCompleto[13]; 
        char imm11[8], imm4[6];
        TransformarBinario(r3, 12, imediatoCompleto); 
        strncpy(imm11, imediatoCompleto, 7);    
        imm11[7] = '\0';
        strncpy(imm4, imediatoCompleto + 7, 5); 
        imm4[5] = '\0';
        PreencherInstrucaoS(instrucao, imm11, r1, r2, 0, imm4, 35);
        ImprimirS(instrucao, outputFile);
    }
    if(strcmp(tipo, "sh")==0){
        char imediatoCompleto[13]; 
        char imm11[8], imm4[6];
        TransformarBinario(r3, 12, imediatoCompleto); 
        strncpy(imm11, imediatoCompleto, 7);    
        imm11[7] = '\0';
        strncpy(imm4, imediatoCompleto + 7, 5); 
        imm4[5] = '\0';
        PreencherInstrucaoS(instrucao, imm11, r1, r2, 1, imm4, 35);
        ImprimirS(instrucao, outputFile);
    }
    if(strcmp(tipo, "sw")==0){
        char imediatoCompleto[13]; 
        char imm11[8], imm4[6];
        TransformarBinario(r3, 12, imediatoCompleto); 
        strncpy(imm11, imediatoCompleto, 7);    
        imm11[7] = '\0';
        strncpy(imm4, imediatoCompleto + 7, 5); 
        imm4[5] = '\0';
        PreencherInstrucaoS(instrucao, imm11, r1, r2, 2, imm4, 35);
        ImprimirS(instrucao, outputFile);
    } 
    if(strcmp(tipo, "sd")==0){
        char imediatoCompleto[13]; 
        char imm11[8], imm4[6];
        TransformarBinario(r3, 12, imediatoCompleto); 
        strncpy(imm11, imediatoCompleto, 7);    
        imm11[7] = '\0';
        strncpy(imm4, imediatoCompleto + 7, 5); 
        imm4[5] = '\0';
        PreencherInstrucaoS(instrucao, imm11, r1, r2, 7, imm4, 35);
        ImprimirS(instrucao, outputFile);
    }
}

void CabecarioSB(TipoSB* instrucao, char tipo[6], int r1, int r2, int r3, FILE *outputFile){
    if(strcmp(tipo, "beq") == 0){
        char imediatoCompleto[13];  
        char imm12[2], imm11[2], imm10_5[7], imm4_1[5];
        TransformarBinario(r3, 12, imediatoCompleto);  
        imm12[0] = imediatoCompleto[0]; 
        imm12[1] = '\0';
        strncpy(imm10_5, imediatoCompleto + 1, 6); 
        imm10_5[6] = '\0';
        strncpy(imm4_1, imediatoCompleto + 7, 4); 
        imm4_1[4] = '\0';
        imm11[0] = imediatoCompleto[11]; 
        imm11[1] = '\0';
        PreencherInstrucaoSB(instrucao, imm12, imm10_5, r2, r1, 0, imm4_1, imm11, 103);
        ImprimirSB(instrucao, outputFile);
    }
    if(strcmp(tipo, "bne")==0){
        char imediatoCompleto[13];  
        char imm12[2], imm11[2], imm10_5[7], imm4_1[5];
        TransformarBinario(r3, 12, imediatoCompleto);  
        imm12[0] = imediatoCompleto[0]; 
        imm12[1] = '\0';
        strncpy(imm10_5, imediatoCompleto + 1, 6); 
        imm10_5[6] = '\0';
        strncpy(imm4_1, imediatoCompleto + 7, 4); 
        imm4_1[4] = '\0';
        imm11[0] = imediatoCompleto[11]; 
        imm11[1] = '\0';
        PreencherInstrucaoSB(instrucao, imm12, imm10_5, r2, r1, 1, imm4_1, imm11, 103);
        ImprimirSB(instrucao, outputFile);
    }
    if(strcmp(tipo, "blt")==0){
        char imediatoCompleto[13];  
        char imm12[2], imm11[2], imm10_5[7], imm4_1[5];
        TransformarBinario(r3, 12, imediatoCompleto);  
        imm12[0] = imediatoCompleto[0]; 
        imm12[1] = '\0';
        strncpy(imm10_5, imediatoCompleto + 1, 6); 
        imm10_5[6] = '\0';
        strncpy(imm4_1, imediatoCompleto + 7, 4); 
        imm4_1[4] = '\0';
        imm11[0] = imediatoCompleto[11]; 
        imm11[1] = '\0';
        PreencherInstrucaoSB(instrucao, imm12, imm10_5, r2, r1, 4, imm4_1, imm11, 103);
        ImprimirSB(instrucao, outputFile);
    } 
    if(strcmp(tipo, "bge")==0){
        char imediatoCompleto[13];  
        char imm12[2], imm11[2], imm10_5[7], imm4_1[5];
        TransformarBinario(r3, 12, imediatoCompleto);  
        imm12[0] = imediatoCompleto[0]; 
        imm12[1] = '\0';
        strncpy(imm10_5, imediatoCompleto + 1, 6); 
        imm10_5[6] = '\0';
        strncpy(imm4_1, imediatoCompleto + 7, 4); 
        imm4_1[4] = '\0';
        imm11[0] = imediatoCompleto[11]; 
        imm11[1] = '\0';
        PreencherInstrucaoSB(instrucao, imm12, imm10_5, r2, r1, 5, imm4_1, imm11, 103);
        ImprimirSB(instrucao, outputFile);
    } 
    if(strcmp(tipo, "bltu")==0){
        char imediatoCompleto[13];  
        char imm12[2], imm11[2], imm10_5[7], imm4_1[5];
        TransformarBinario(r3, 12, imediatoCompleto);  
        imm12[0] = imediatoCompleto[0]; 
        imm12[1] = '\0';
        strncpy(imm10_5, imediatoCompleto + 1, 6); 
        imm10_5[6] = '\0';
        strncpy(imm4_1, imediatoCompleto + 7, 4); 
        imm4_1[4] = '\0';
        imm11[0] = imediatoCompleto[11]; 
        imm11[1] = '\0';
        PreencherInstrucaoSB(instrucao, imm12, imm10_5, r2, r1, 6, imm4_1, imm11, 103);
        ImprimirSB(instrucao, outputFile);
    } 
    if(strcmp(tipo, "bgeu")==0){
        char imediatoCompleto[13];  
        char imm12[2], imm11[2], imm10_5[7], imm4_1[5];
        TransformarBinario(r3, 12, imediatoCompleto);  
        imm12[0] = imediatoCompleto[0]; 
        imm12[1] = '\0';
        strncpy(imm10_5, imediatoCompleto + 1, 6); 
        imm10_5[6] = '\0';
        strncpy(imm4_1, imediatoCompleto + 7, 4); 
        imm4_1[4] = '\0';
        imm11[0] = imediatoCompleto[11]; 
        imm11[1] = '\0';
        PreencherInstrucaoSB(instrucao, imm12, imm10_5, r2, r1, 7, imm4_1, imm11, 103);
        ImprimirSB(instrucao, outputFile);
    }
}

void CabecarioUJ(TipoUJ* instrucao, char tipo[6], int r1, int r2, FILE *outputFile) {
    if (strcmp(tipo, "jal") == 0) {
        char imediatoCompleto[21];
        char imm10[2], imm1_2[11], imm11[2], imm8[9];
        TransformarBinario(r2, 21, imediatoCompleto);
        imm10[0] = imediatoCompleto[20];
        imm10[1] = '\0';
        strncpy(imm1_2, imediatoCompleto + 10, 10);
        imm1_2[10] = '\0';
        imm11[0] = imediatoCompleto[9];
        imm11[1] = '\0';
        strncpy(imm8, imediatoCompleto+1, 8);
        imm8[8] = '\0';
        PreencherInstrucaoUJ(instrucao, imm10, imm1_2, imm11, imm8, r1, 111);
        ImprimirUJ(instrucao, outputFile);
    }
    if (tipo[0]=='j') {
        char imediatoCompleto[21];
        char imm10[2], imm1_2[11], imm11[2], imm8[9];
        TransformarBinario(r2, 21, imediatoCompleto);
        imm10[0] = imediatoCompleto[20];
        imm10[1] = '\0';
        strncpy(imm1_2, imediatoCompleto + 10, 10);
        imm1_2[10] = '\0';
        imm11[0] = imediatoCompleto[9];
        imm11[1] = '\0';
        strncpy(imm8, imediatoCompleto+1, 8);
        imm8[8] = '\0';
        PreencherInstrucaoUJ(instrucao, imm10, imm1_2, imm11, imm8, 0, 111);
        ImprimirUJ(instrucao, outputFile);
    }
}

void CabecarioPseudo(TipoI *instrucao, char tipo[6], int r1, int r2, FILE *outputFile){
    if(strcmp(tipo, "mv")==0){
        PreencherInstrucaoI(instrucao, 0, r2 , 0, r1, 19);
        ImprimirI(instrucao, outputFile);
    }
    else if(strcmp(tipo, "li")==0){
        PreencherInstrucaoI(instrucao, r2, 0 , 0, r1, 19);
        ImprimirI(instrucao, outputFile);
    }
}

