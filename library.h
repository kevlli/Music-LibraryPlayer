#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


struct song_node ** allocate();

int letterindex(char c) ;

struct song_node ** add_song(struct song_node **s, char* n, char* a);

void print_letter(struct song_node **a, char c);

void print_library(struct song_node **a);

struct song_node * search_song(struct song_node **s, char* n, char* a);

struct song_node * search_artist(struct song_node **s, char* a);

void shuffle(struct song_node **s);

void print_artist(struct song_node **s, char *a);

struct song_node ** delete_song(struct song_node **s, char *n, char *a);

struct song_node ** clear_all(struct song_node **s) ;
