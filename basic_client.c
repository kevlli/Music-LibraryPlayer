#include "pipe_networking.h"


int main() {

  int to_server;
  int from_server;

  from_server = client_handshake( &to_server );

  char line[BUFFER_SIZE];

  while (1) {
    printf("\nWhat song would you like to add to the library? Format: song name-artist\n");
    fgets(line, BUFFER_SIZE, stdin);
    write(to_server, line, BUFFER_SIZE);
    read(from_server, line, BUFFER_SIZE);
    printf("From server: %s", line);
  }
}