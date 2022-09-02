#include "libhash.h"
#include "parser.h"

#define TAM 11

int main() {
	hash_base* T1 = criar_hash(TAM);
	hash_base* T2 = criar_hash(TAM);

	while (!proxima_ordem(T1, T2, TAM)) {

	}

	imprimir_tudo(T1, T2, TAM);

	destroi_hash(T1);
	destroi_hash(T2);
}