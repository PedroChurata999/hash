#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "libhash.h"

// calcula a coordenada na T1
static int h1(int chave, int tam) {
	return chave % tam;
}

// calcula a coordenada na T2
static int h2(int chave, int tam) {
	return (int)(floor(tam * (chave * 0.9 - floor(chave * 0.9))));
}

//-----------------------------------------------------------

// cria e alloca memoria de uma hash
hash_base* criar_hash(int tam) {
	hash_base* hash_result = malloc(sizeof(hash_base));
	
	hash_result->chaves = malloc(tam * sizeof(int));
	
	hash_result->marca_vazio = malloc(tam * sizeof(int));
	for (int i = 0; i < tam; i++) {
		hash_result->marca_vazio[i] = 1;
	}
	
	return hash_result;
}

// limpa a memoria de uma hash
hash_base* destroi_hash(hash_base* hash) {
	free(hash->chaves);
	free(hash->marca_vazio);

	free(hash);
	return NULL;
}

//-----------------------------------------------------------

// funcao da insercao de uma chave
int hash_insere(int chave, int tam, hash_base* T1, hash_base* T2) {
	int coord = h1(chave, tam);
	
	if (T1->marca_vazio[coord]) {
		T1->chaves[coord] = chave;
		T1->marca_vazio[coord] = 0;

		return 0;
	}

	if (T1->chaves[coord] == chave) {
		fprintf(stderr, "encontrada chave duplicada em T1\n");
		return 1;
	}

	int valor_antigo = T1->chaves[coord];
	T1->chaves[coord] = chave;

	coord = h2(valor_antigo, tam);

	if (T2->marca_vazio[coord]) {
		T2->chaves[coord] = valor_antigo;
		T2->marca_vazio[coord] = 0;

		return 0;
	}
	else {
		if (T2->chaves[coord] == valor_antigo) {
			fprintf(stderr, "encontrada chave duplicada em T2\n");
			return 1;
		}

		fprintf(stderr, "conflito em T2\nsupostamente impossivel...\n");
		return 2;
	}
}

// funcao de remocao de uma chave
int hash_remove(int chave, int tam, hash_base* T1, hash_base* T2) {
	int coord = h1(chave, tam);

	if (T1->chaves[coord] == chave) {
		T1->marca_vazio[coord] = 1;

		return 0;
	}

	coord = h2(chave, tam);

	if (T2->chaves[coord] == chave) {
		T2->marca_vazio[coord] = 1;

		return 0;
	}

	fprintf(stderr, "remocao de uma chave nao encontrada\n");
	return 1;
}