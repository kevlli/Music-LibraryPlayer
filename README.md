## Project Idea: 
An expansion of the music library that incorporates a music player as well as import/export of libraries.
## User Interface:
The project will be entirely terminal based, so adding songs, importing, and playing music will be through terminal commands.
## Technical Design:
### Topics
#### Allocating memory -
To store the songs in the library proper memory allocation is required.
#### Working with files -
To import and export music libraries to binary files. Use music files with music player
#### Processes -
Forking to allow for exec of music player, or multiple, while still being able to view and edit music library.
#### Pipes -
Allows for communication between forked music player and library, to queue songs for example.
## Responsibilities:
I am working alone.
## Data Structures and Algorithms:
I will be using arrays and linked lists for storage of the songs in the library. Using pipes, the parent will communicate with the music player to queue songs, shuffle play, or skip.
## Timeline:
1/15 - Get forked child process music player to work with mp3 files.  
1/16 - Allow for saving/loading of the library with binary file.  
1/18 - Add queue, shuffle and skip function to music player  
1/20 - Enhance the music player so its more user friendly  
# Termibrary
## Members
Kevin Li period 4 
## Broad Project Description
Termibrary is a terminal mixed with a music library that incorporates a music player, binary files, forking subservers, linked lists, and more!
## Required Libraries
Only 1 library is needed, sox.  
To get it, run $ sudo apt install sox  
as well as $ sudo apt-get install libsox-fmt-all  
## How to Use Termibrary
To use the project, first compile everything using the $ make command. Then, input $ make run. You will be met with an constant input prompt as well as the available commands.  
All commands are case insensitive. The first two are the simplest, add and remove song. After typing > add song or > remove song, you'll be prompted to type the song you want to modify. Clear library and print library are also self explanatory.  
Next is > save library, which will save your current music library to a binary file called library.bin. Its corresponding function is > load library, which loads a binary file into your music library.  
After that is > play song, which will list all playable songs in the current directory, then play whichever one you choose using fork, exec and soX!  
Lastly, there is > allow connections, which turns the music library program into a forking subserver program, allowing clients to connect and add their songs to your library.
## Bugs and Drawbacks
Due to the signal handling that I incorporated to allow the user to exit the mp3 player without exiting the entire program, this made it difficult to exit the forking server. As a result, the forking server asks before every new connection if the user would like to exit. Additionally, on rare occasions there are private pipes left in the directory after exiting.  
I was unable to implement some aspects of the music player, such as pausing or skipping, because after forking then execing the child process is replaced by the soX process, so communication with that forked process is difficult.
For remove song, a correct input is expected.