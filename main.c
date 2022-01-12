#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "song.h"
#include "library.h"



int main() { 
	struct song_node *s = createnode("street spirit (fade out)", "radiohead");
	s = insertfront(s, "paranoid android", "radiohead");
	s = insertfront(s, "time", "pink floyd");
	s = insertfront(s, "yellow ledbetter", "pearl jam");
	s = insertfront(s, "even flow", "pearl jam");
	s = insertfront(s, "alive", "pearl jam");
	s = insertfront(s, "thunderstruck", "ac/dc");

	printf("LINKED LIST TESTS\n====================================\n\n");
	

	printf("Testing print_list:\n\t");
	print_list(s);
	printf("\n====================================\n\n");


	printf("Testing print_node:\n\t");
	print_node(s);
	printf("\n====================================\n\n");
	

	printf("Testing find_node:  \n");
	printf("looking for [pearl jam: even flow]\n\t");
	struct song_node *a = find_node(s, "even flow", "pearl jam");
	print_node(a);
	printf("\nlooking for [pearl jam: daughter]\n\t");
	struct song_node *b = find_node (s, "daughter", "pearl jam");
	print_node(b);
	printf("\n====================================\n\n");

    
    printf("Testing find_artist:\n");
    printf("looking for [pink floyd]");
    a = findartist(s, "pink floyd");
    print_node(a);
    printf("\nlooking for [pearl jam]");
    b = findartist(s,"pearl jam");
    print_node(b);
    printf("\nlooking for [presidents of the united states of america]");
    b = findartist(s,"presidents of the united states of america");
    print_node(b);
    printf("\n====================================\n\n");


	printf("Testing songcmp (helper function):\n");
	printf("Comparing [pearl jam: even flow] to [pearl jam: even flow]\n\t");
	printf("%d\n", songcmp(s->next->next,s->next->next));
	printf("Comparing [pearl jam: even flow] to [pearl jam: alive]\n\t");
	printf("%d\n", songcmp(s->next->next,s->next));
	printf("Comparing [pearl jam: alive] to [pearl jam: even flow]\n\t");
	printf("%d\n", songcmp(s->next,s->next->next));
	printf("Comparing [pearl jam: even flow] to [pink floyd: time]\n\t");
	printf("%d\n", songcmp(s->next->next,s->next->next->next->next));
	printf("====================================\n\n");

	
	printf("Testing random:\n");
	print_node(randomnode(s));
	printf("\n");
	print_node(randomnode(s));
	printf("\n");
	print_node(randomnode(s));
	printf("\n");
	print_node(randomnode(s));
	printf("\n");
	print_node(randomnode(s));
	printf("\n====================================\n\n");


	printf("Testing remove:\n");
	printf("Removing [ac/dc: thunderstruck]\n\t");
	s = removenode(s, "thunderstruck", "ac/dc");
	print_list(s);
	printf("\nRemoving [radiohead: street spirit (fade out)]\n\t");
	s = removenode(s, "street spirit (fade out)", "radiohead");
	print_list(s);
	printf("\nRemoving [pearl jam: yellow ledbetter]\n\t");
	s = removenode(s, "yellow ledbetter", "pearl jam");
	print_list(s);
	printf("\nRemoving [pearl jam: yellow ledbetter]\n\t");
	s = removenode(s, "yellow ledbetter", "pearl jam");
	print_list(s);
	printf("\n====================================\n\n");


	printf("Testing free_list");
	s = free_list(s);
	printf("\nlist aftering free_list:\n");
	print_list(s);
	printf("\n====================================\n\n");


    printf("MUSIC LIBRARY TESTS");
    printf("\n====================================\n\n");


    printf("Testing print_letter \n");
    struct song_node ** library = allocate();
    print_letter(library, 'd');
    printf("\n====================================\n\n");


    printf("Testing print_library");
    print_library(library);
    printf("\n====================================\n\n");


    library = add_song(library, "dna", "kendrick lamar");
    library = add_song(library, "alright", "kendrick lamar");
    library = add_song(library, "excuse me", "asap rocky");
    library = add_song(library, "long live asap", "asap rocky");
    library = add_song(library, "marvins room", "drake");
    library = add_song(library, "be my baby", "ariana grande");
    library = add_song(library, "everyday", "ariana grande");
    library = add_song(library, "a lot", "21 savage");


    printf("Testing print_letter \n");
    print_letter(library, 'a');
    printf("\n====================================\n\n");


    printf("Testing print_library ");
    print_library(library);
    printf("\n====================================\n\n");


    printf("Testing find:");
    printf("\nlooking for [kendrick lamar: alright]");
    a = search_song(library, "alright", "kendrick lamar");
    print_node(a);
    printf("\nlooking for [kendrick lamar: element]");
    a = search_song(library, "element", "kendrick lamar");
    print_node(a);
    printf("\n====================================\n\n");


    printf("Testing find artist:");
    printf("\nlooking for [kendrick lamar]");
    a = search_artist(library, "kendrick lamar");
    print_list(a);
    printf("\nlooking for [asap rocky]");
    a = search_artist(library, "asap rocky");
    print_list(a);
    printf("\nlooking for [j cole]");
    a = search_artist(library, "j cole");
    print_list(a);
    printf("\n====================================\n\n");


    printf("Testing remove_song");
    printf("\nremoving: [kendrick lamar: dna]");
    library = delete_song(library, "dna", "kendrick lamar");
    print_library(library);
    printf("\n\nremoving: [ariana grande: everyday]");
    library = delete_song(library, "everyday", "ariana grande");
    print_library(library);
    printf("\n====================================\n\n");


    printf("Testing clear_library:");
    clear_all(library);
    printf("\n\nLibrary after clear: ");
    print_library(library);
    printf("\n====================================\n\n");
	

    printf("Adding songs to empty library\n");
    library = add_song(library, "the less i know the better", "tame impala");
    library = add_song(library, "505", "arctic monkeys");
    library = add_song(library, "borderline", "tame impala");
    library = add_song(library, "red", "taylor swift");
    library = add_song(library, "the adults are talking", "the strokes");
    print_library(library);
    printf("\n====================================\n\n");


    printf("Testing print_artist:\n");
    printf("Printing [tame impala]\n");
    print_artist(library, "tame impala");
    printf("\nPrinting [arctic monkeys]\n");
    print_artist(library, "arctic monkeys");
    printf("\nPrinting [asap rocky]\n");
    print_artist(library, "asap rocky");
    printf("\n====================================\n\n");
    printf("Testing shuffle");
    shuffle(library);
    printf("\n====================================\n\n");

}