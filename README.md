# sysfinal

# Member(s): 
Kevin Li
# Period: 
4
# Project Idea: 
An expansion of the music library that incorporates a music player as well as import/export of libraries.
# User Interface:
The project will be entirely terminal based, so adding songs, importing, and playing music will be through terminal commands.
# Technical Design:
## Topics:
### Allocating memory -
To store the songs in the library proper memory allocation is required.
### Working with files -
To import and export music libraries to binary files. Use music files with music player
### Processes -
Forking to allow for exec of music player, or multiple, while still being able to view and edit music library.
### Pipes -
Allows for communication between forked music player and library, to queue songs for example.
## Responsibilities:
I am working alone.
## Data Structures and Algorithms:
I will be using arrays and linked lists for storage of the songs in the library. Using pipes, the parent will communicate with the music player to queue songs, shuffle play, or skip.
# Timeline:
1/15 - Get forked child process music player to work with mp3 files.
1/16 - Allow for saving/loading of the library with binary file.
1/18 - Add queue, shuffle and skip function to music player
1/20 - Enhance the music player so its more user friendly.