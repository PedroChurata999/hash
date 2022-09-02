#include <stdio.h>

#include "libhash.h"
#include "parser.h"

// obtem e processa a proxima ordem da stdin
int proxima_ordem(hash_base* T1, hash_base* T2, int tam) {
	char ordem_tipo;
	char buffer[BUFSIZ];
	int val;

	if (fscanf(stdin, "%c ", &ordem_tipo) <= 0) {
		return 1;
	}

	fscanf(stdin, "%d", &val);
	fgets(buffer, BUFSIZ, stdin);

	if (ordem_tipo == 'i') {
		hash_insere(val, tam, T1, T2);

		return 0;
	}
	if (ordem_tipo == 'r') {
		hash_remove(val, tam, T1, T2);

		return 0;
	}

	fprintf(stderr, "ordem nao reconhecida\n");
	return 2;
}

// imprime todos os valores das 2 hash s, em ordem crescente
// essa funcao estraga as hash s, deixando elas inusaveis apos sua funcionalidade
void imprimir_tudo(hash_base* T1, hash_base* T2, int tam) {
	int val, tabela, coord;
	int i;

	int check = 1;
	while (check) {
		check = 0;

		val = 0;
		tabela = 0;
		coord = 0;

		for (i = 0; i < tam; i++) {
			if (T1->marca_vazio[i] == 0) {
				if (T1->chaves[i] < val || tabela == 0) {
					check = 1;

					val = T1->chaves[i];
					tabela = 1;
					coord = i;
				}
			}
		}
		for (i = 0; i < tam; i++) {
			if (T2->marca_vazio[i] == 0) {
				if (T2->chaves[i] < val || tabela == 0) {
					check = 1;

					val = T2->chaves[i];
					tabela = 2;
					coord = i;
				}
			}
		}

		if (tabela == 1) {
			fprintf(stdout, "%d,T1,%d\n", val, coord);
			T1->marca_vazio[coord] = 1;
		}
		if (tabela == 2) {
			fprintf(stdout, "%d,T2,%d\n", val, coord);
			T2->marca_vazio[coord] = 1;
		}
	}
}