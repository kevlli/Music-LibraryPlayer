#include "song.h"

int songcmp(struct song_node *a, struct song_node *b) {
	if (strcmp(a->artist, b->artist))
		return strcmp(a->artist, b->artist);
	return strcmp(a->name, b->name);
}

struct song_node * createnode(char *n, char *a) { // creates node in heap memory
	struct song_node *s = malloc(sizeof(struct song_node));
	strcpy(s->name, n);
	strcpy(s->artist, a);
	s->next = 0;
	
	return s;
}
struct song_node * insertfront(struct song_node * s, char *n, char *a) { // inserts node to front of list
	struct song_node *new = createnode(n, a);
	new->next = s;
	return new;
}


struct song_node * insertordered(struct song_node * s, char *n, char *a) { // inserts node in alphabetical order
	struct song_node *start = s;
	struct song_node *new = createnode(n, a);

	//special case when node should be inserted in front
	if (songcmp(new, s) < 0) {
		new -> next = s;
		return new;
	}

	// case when node is inserted in middle of list
	while (s->next) {
		if ( (songcmp(s,new) < 0) && (songcmp(new, s->next) < 0) )  {
			struct song_node *temp = s->next;
			s->next = new;
			new->next = temp;
			return start;
		}
		s = s->next;
	}

	// case when node is inserted at the end of list
	if (songcmp(s, new) < 0)
		s->next = new;
	return start;
}

void print_node(struct song_node *s) { // prints node
	if (s)
		printf("{%s, %s}", s->artist, s->name);
}

void print_list(struct song_node *s) { // prints entire list
	printf("[ ");

	while (s) {
		print_node(s);
		printf(" | ");
		s = s->next;
	}
	printf("]");
}

struct song_node * find_node_helper(struct song_node * s, char *n, char *a) {
	while (s) {
		if ( !strcmp(s->name,n) && !strcmp(s->artist,a) ) {
			return s;
		}
		s = s->next;
	}
	return 0;
}	

struct song_node * find_node(struct song_node * s, char *n, char *a) {
	struct song_node *z = find_node_helper(s, n, a);
	if (!z)
		printf("node not found");
	else
		printf("node found! ");
	return z;
}

struct song_node * findartist_helper(struct song_node *s, char *a) {

	while (s) { 
		if ( !strcmp(s->artist,a) ) {
			return s;
		}
		s = s->next;
	}
	return 0;
}


struct song_node * findartist(struct song_node * s, char *a) {
	struct song_node *z = findartist_helper(s, a);
	if (z)
		printf("\n\tartist found! ");
	else
		printf("\n\tartist not found");
	return z;
}

int listlen(struct song_node * s) {
	int sum = 0;
	while (s) {
		sum++;
		s = s -> next;
	}
	return sum;
}


int initialized = 0;
struct song_node * randomnode(struct song_node * s) { 
	if (!initialized) {
		srand( time(NULL) );
		initialized = 1;
	}
	int x;
	x = rand();
	x %= listlen(s);
	int i;
	for (int i = 0; i < x; i++)
		s = s->next;
	return s;
}


struct song_node * removenode(struct song_node * s, char *n, char *a) {
	struct song_node *temp = createnode(n,a);
	struct song_node *start = s;
	if ( !songcmp(s,temp) ) {
    	start = s->next;
		free(s);
		free(temp);
    	return start;
  	}
	while (s->next) {
    	if ( !songcmp(s->next,temp) ) {
			free(s->next);
    		s->next = s->next->next;
			free(temp);
    		return start;
    	}
    	s = s->next;
	}
  	print_node(s);
	printf(" not found\n");
	free(temp);
	return start;
}

struct song_node * free_list (struct song_node * s) {
	struct song_node * temp;
	while (s) {
		temp = s;
		printf("\n\tfreeing_node: ");
		print_node(s);

		s = s->next;
		free(temp);
	}
	return temp->next;
}