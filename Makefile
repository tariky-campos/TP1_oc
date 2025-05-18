compile:
	gcc codigo/main.c codigo/EntradaArquivo/Entrada.c codigo/ConverterInstrucoes/Converte_Instrucoes.c codigo/ConverterInstrucoes/EstrututraInstrucoes/Formato_Instrucoes.c -o programa

run:
	./programa