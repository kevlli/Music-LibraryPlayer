#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct song_node{  // struct
	char name[100];
	char artist[100];
	struct song_node *next;
};

//functions
int songcmp(struct song_node *a, struct song_node *b);

struct song_node * createnode(char *n, char *a);

struct song_node * insertfront(struct song_node * s, char *n, char *a);

struct song_node * insertordered(struct song_node * s, char *n, char *a);

void print_node(struct song_node *s);

void print_list(struct song_node *s);

struct song_node * find_node_helper(struct song_node * s, char *n, char *a);

struct song_node * find_node(struct song_node * s, char *n, char *a);

struct song_node * findartist_helper(struct song_node *s, char *a);

struct song_node * findartist(struct song_node * s, char *a);

int listlen(struct song_node * s);

struct song_node * randomnode(struct song_node * s);

struct song_node * removenode(struct song_node * s, char *n, char *a);

struct song_node * free_list (struct song_node * s);

int listlen(struct song_node * s);
