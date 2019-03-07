# pair_program_word_link


## Project structure

```
├─BIN       # Final Result 1: binary files
├─GUIBIN    # Final Result 2: GUI excutable file
├─core      # Project 1: Core library
├─wordlist  # Project 2: Command line program
│  ├─lib        # libraries
│  └─src        # source codes
├─gui       # Project 3: GUI program
│  ├─lib        # libraries
│  └─src        # source codes
```

## Compile


**Build wordlist command line program**

Environment:
* Windows 10
* Requires: mingw32-make, cmake, g++

In the `wordlist` folder, open a terminal, then enter the commands below:

```cmd
# generate Makefile using `cmake`
mkdir build && cd build
cmake .. -G "MinGW Makefiles"
# build project with mingw32-make
mingw32-make
```

If successful, you can get a `worldlist.exe` executable file in the `build/` folder.


**Build QT GUI program**

In the `gui` folder, open a terminal, then enter the commands below:

```cmd
```

## Libraries We Use

* [getoptpp](https://code.google.com/archive/p/getoptpp/wikis/Help.wiki) - A getopt C++ version for handling parameters

