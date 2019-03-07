# pair_program_word_link


## Project structure

```
├─BIN       # Final Result 1: binary files
├─GUIBIN    # Final Result 2: GUI excutable file
├─core      # Project 1: Core library
├─cmd       # Project 2: Command line program
│  ├─lib        # libraries
│  ├─src        # sources
├─gui       # Project 3: GUI program
│  ├─lib        # libraries
│  └─src        # sources
```

## Compile

**Using Cmake on Windows**

In the project root folder:

```bash
# generate Makefile using `cmake`
mkdir build && cd build
cmake .. -G "MinGW Makefiles"
# build project with mingw32-make
mingw32-make
```


## Libraries We Use

* [getoptpp](https://code.google.com/archive/p/getoptpp/wikis/Help.wiki) - A getopt C++ version for handling parameters

