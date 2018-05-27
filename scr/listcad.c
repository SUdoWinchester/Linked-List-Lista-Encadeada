#include <stdlib.h>
#include <stdio.h>
#include "listcad.h"

linked_list *new_linked_list(int size) {
	linked_list *l = (linked_list*) malloc(sizeof(linked_list));
	l->count = 0;
	l->max = size;
	l->first = NULL;

	return l;
}

int is_empty(linked_list *l) {
	return l == NULL || l->first == NULL;
}

int is_full(linked_list *l) {
	return l == NULL || l->max == -1 ? 0 : l->count == l->max;
}

node *create_node(int x) {
	node *new_node = (node*) malloc(sizeof(node));
	new_node->x = x;
	new_node->next = NULL;
	return new_node;
}

void print(linked_list *l) {
	if (is_empty(l))
		return;

	node *aux = l->first;
	int i=0;
	while(aux != NULL) {
		printf("l[%d] = %d\n", i, aux->x);
		aux=aux->next;
		i++;
	}
}

void remove_first(linked_list *l) {
	if(is_empty(l) || l==NULL) return ;

	removeat(l, 0);
}

void removeat(linked_list *l, int x) {
	if(is_empty(l) || l==NULL) return ;

	if(x == 0) {
		l->first = l->first->next;
		l->count--;
		return;
	}

	int i=0;
	node *aux = l->first;
	while(i < x-1) {
		aux=aux->next;
		i++;
	}
	node *aux2 = aux->next;
	aux->next=aux2->next;
	l->count--;
}


void remove_last(linked_list *l) {
	if(is_empty(l) || l==NULL) return ;

	removeat(l, l->count-1);
} 

void insert_first(int x, linked_list *l) {
	if(l == NULL || is_full(l)) return;

	node *new_node = create_node(x);
	if(is_empty(l)) {
		l->first = new_node;
	} else {
		new_node->next = l->first;
		l->first = new_node;
	}
	l->count++;
}

void insertat(linked_list *l, int x, int posicao) {
	if(l==NULL || is_full(l) || (posicao > l->count-1 && posicao > 0)) return ;
	if(is_empty(l)) {
		insert_first(x, l);
		return ;
	}

	if(posicao == 0) { 
		insert_first(x, l);
		return;
	}
	if(posicao == l->count - 1) {
		insert_last(l, x);
		return;
	}

	int i=0;
	node *aux = l->first;
	while(i < posicao - 1) {
		aux=aux->next;
		i++;
	}

	node *new_node = create_node(x);
	new_node->next = aux->next;
	aux->next = new_node;
	l->count++;
}

void insert_last(linked_list *l, int x) {
	if(l==NULL || is_full(l)) return ;

	node *aux = l->first;
	while(aux->next != NULL) {
		aux = aux->next;
	}

	node *new_node = create_node(x);
	aux->next = new_node;
	l->count++;
}

void destroy_linked_list(linked_list **l) {
	if (is_empty(*l)) return;

	node *aux = (*l)->first;
	while(aux != NULL) {
		node *del = aux;
		aux=aux->next;
		free(del);
	}
	free(*l);
	*l = NULL;
}
