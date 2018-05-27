#include <stdio.h>
#include <stdlib.h>
#include "listcad.h"

void main(){
	linked_list *l = new_linked_list(-1);

	printf("\ninsert_first:\n");
	insert_first(10, l);
	insert_first(20, l);
	insert_first(30, l);
	insert_first(40, l);
	insert_first(50, l);
	insert_first(60, l);
	insert_first(70, l);
	insert_first(80, l);
	insert_first(90, l);
	insert_first(100, l);
	print(l);
	
	printf("\ninsertat l[5] = 1000\n");
	insertat(l, 1000, 5);
	print(l);

	printf("\ninsertat l[8] = 2000\n");
	insertat(l, 2000, 8);
	print(l);

	printf("\ninsertat l[2] = 3000\n");
	insertat(l, 3000, 2);
	print(l);

	printf("\ninsert_last:\n");
	insert_last(l, 200);
	print(l);

	printf("\ninsert_last:\n");
	insert_last(l, 500);
	print(l);

	printf("\nremove_first:\n");
	remove_first(l);
	print(l);

	printf("\nremove_first:\n");
	remove_first(l);
	print(l);

	printf("\nremove posicao [1]:\n");
	removeat(l, 1);
	print(l);
	printf("\nremove posicao [5]:\n");
	removeat(l, 5);
	print(l);

	printf("\nremove_last:\n");
	remove_last(l);
	print(l);
	
	printf("\nremove_last:\n");
	remove_last(l);
	print(l);
}
