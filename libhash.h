// estrutura de hash base do meu codigo
typedef struct hash_base_ {
	int* chaves;
	int* marca_vazio;
} hash_base;
// chaves contera as chaves
// 
// marca_vazio servira para indicar se a posicao eh vazia
// 
// a marca_vazio pode ser considerada desnecessaria,
// porem como nao ha um valor numerico definido padrao, 
// eu nao posso assumir que 0, por exemplo, nunca sera adicionado,
// logo ela apenas indica a ausencia de um numero significante, o meu NULL.
// 
// marca remocao servira para indicar quando um valor foi removido


// cria e alloca memoria de uma hash
hash_base* criar_hash(int tam);

// limpa a memoria de uma hash
hash_base* destroi_hash(hash_base* hash);

// funcao da insercao de uma chave
int hash_insere(int chave, int tam, hash_base* T1, hash_base* T2);

// funcao de remocao de uma chave
int hash_remove(int chave, int tam, hash_base* T1, hash_base* T2);