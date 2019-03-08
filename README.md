# Longest Word Chain

Giving a list of englist words, find out the longest word chain.

For more detailed infomation, see [结对项目-最长单词链](https://edu.cnblogs.com/campus/buaa/BUAA_SE_2019_LJ/homework/2638).

Similar posts: 
* [stackoverflow - Longest word chain from a list of words](https://stackoverflow.com/questions/53485052/)
* [Last letter-first letter](https://rosettacode.org/wiki/Last_letter-first_letter)

## Project Structure

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

## Compile & Run


**Build Wordlist command line app**

Environment:
* Windows 10
* Requires: mingw32-make, cmake, g++

> 关于环境变量的配置，可以看[这篇文章](https://www.cnblogs.com/fondoger/p/using-qt5-on-windows-without-qtcreator-or-visual-studio.html)，你只需要完成配置环境变量这一小节就好了。
> (PS：cmake需要自己另外安装)

In the `wordlist` folder, open a terminal, then enter the commands below:

```cmd
# generate Makefile using `cmake`
mkdir build && cd build
cmake .. -G "MinGW Makefiles"
# build project with mingw32-make
mingw32-make
```

If successful, you can get a `worldlist.exe` executable file in the `build/` folder.


**Build Wordlist QT GUI app**

In the `gui` folder, open a terminal, then enter the commands below:

```cmd
# generate Makefile using `cmake`
mkdir build && cd build
cmake .. -G "MinGW Makefiles"
# build project with mingw32-make
mingw32-make
```
If successful, you can get a `GUIApp.exe` executable file in the `build/` folder.

## Libraries We Use

* [getoptpp](https://code.google.com/archive/p/getoptpp/wikis/Help.wiki) - A getopt C++ version for handling parameters
