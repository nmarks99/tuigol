# Terminal UI (tui) Game of Life (gol)
Neither the first nor the last implementation of Conway's Game of Life in your terminal.

![tuigol-demo.mp4](https://raw.githubusercontent.com/nmarks99/tuigol/main/assets/tuigol-demo.mp4)

## Dependencies

The only real dependencies are `ncurses`, a C++ compiler, cmake, and make.
To install ncurses on Ubuntu, run 
```
sudo apt install libncurses5-dev libncursesw5-dev
```
If you are using another Linux distribution besides Ubuntu, look up how to install 
ncurses with you package manager. On Linux you should have GCC preinstalled with cmake and make.
If you are on Mac or Windows ¯\_(ツ)_/¯.

Technically another dependecy is a terminal emulator capable of displaying ncurses stuff 
but every modern terminal should be more than capable of running this program properly.

## Usage
1. Clone the repo
```
git clone https://github.com/nmarks99/tuigol.git
```
2. Run the following in the root directory of the project to build it 
```
mkdir build 
cd build
cmake ..
make
```
3. In the newly created build directory there should be an executable called `tuigol`
which you can run to start the program.

