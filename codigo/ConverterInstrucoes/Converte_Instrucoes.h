#ifndef CONVERTE_INSTRUCOES_H
#define CONVERTE_INSTRUCOES_H_
#include "EstrututraInstrucoes/Formato_Instrucoes.h"

int ConverterNumero(char r1[10]);

char IdentificarTipo(char tipo[6]);

void CabecarioR(TipoR *instrucao, char tipo[6], int r1, int r2, int r3, FILE *outputFile);

void CabecarioI(TipoI *instrucao, char tipo[6], int r1, int r2, int r3, FILE *outputFile);

void CabecarioS(TipoS *instrucao, char tipo[6], int r1, int r2, int r3, FILE *outputFile);

void CabecarioSB(TipoSB *instrucao, char tipo[6], int r1, int r2, int r3, FILE *outputFile);

void CabecarioPseudo(TipoI *instrucao, char tipo[6], int r1, int r2, FILE *outputFile);

void CabecarioUJ(TipoUJ* instrucao, char tipo[6], int r1, int r2, FILE *outputFile);

#endif