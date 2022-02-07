# wordle-solver
An approach to wordle which is definitely not cheating.
## Prerequisites
- cURL
- GNU Make
- c++ compiler (can be changed in makefile)
## Building
```
git clone --recursive https://github.com/linuxnoodle/wordle-solver #FMT is a git submodule, so make sure to use the --recursive flag!
cd wordle-solver
make clean all
./wordle-solver
```
## TODO
- [ ] Use huffman encoding (think that's the right term) to choose the best word out of a list
- [ ] Allow for entering in a board
- [ ] Fix bug with (somewhat?) random segfaults
- [ ] Implement CLI version of game
