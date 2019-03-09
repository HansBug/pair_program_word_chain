# Longest Word Chain

Giving a list of english words, find out the longest word chain.

For more detailed infomation, see [结对项目-最长单词链](https://edu.cnblogs.com/campus/buaa/BUAA_SE_2019_LJ/homework/2638).

Related posts: 
* [stackoverflow - Longest word chain from a list of words](https://stackoverflow.com/questions/53485052/)
* [Talk:Last letter-first letter](https://rosettacode.org/wiki/Talk:Last_letter-first_letter)
* [Solutions - Last letter-first letter](https://rosettacode.org/wiki/Last_letter-first_letter)
* [Github Gist - C++ solution](https://gist.github.com/authuir/9f8ec4b907264a9922fc0b3ff5b41749)

## Project Structure

```
├─BIN       # Final Result 1: binary files
├─GUIBIN    # Final Result 2: GUI excutable file
├─core      # Project 1: Core dll library
├─wordlist  # Project 2: Command line App
│  ├─lib        # libraries
│  └─src        # source codes
└─gui       # Project 3: GUI App
   ├─lib        # libraries
   └─src        # source codes
```

## Compile & Run

Environment:
* Windows 10
* Requires: `cmake`, MinGW(with `migw32-make` and `gcc`)
* (PS: `ming32-make` is same as `make`)

> Don't know how to configure the environment ? You can have a look at [this article](https://www.cnblogs.com/fondoger/p/using-qt5-on-windows-without-qtcreator-or-visual-studio.html)。
>
> PS: you still need to install `cmake` manually(and don't forget to put `cmake` into your path environment).

## 1. Build Core Dynamic Linking Library

In the `core` folder, open a terminal, then enter the commands below:

```cmd
# generate Makefile using `cmake`
mkdir build && cd build
cmake .. -G "MinGW Makefiles"
# build project with mingw32-make
mingw32-make
```

If successful, you can get a `libCore_LIB.dll` DLL file in the `build/` folder.

## 2. Build Wordlist command line App

In the `wordlist` folder, open a terminal, then enter the commands below:

```cmd
# generate Makefile using `cmake`
mkdir build && cd build
cmake .. -G "MinGW Makefiles"
# build project with mingw32-make
mingw32-make
```

If successful, you can get a `worldlist.exe` executable file in the `build/` folder.



## 3. Build Wordlist QT GUI App

In the `gui` folder, open a terminal, then enter the commands below:

```cmd
# generate Makefile using `cmake`
mkdir build && cd build
cmake .. -G "MinGW Makefiles"
# build project with mingw32-make
mingw32-make
```
If successful, you can get a `GUIApp.exe` executable file in the `build/` folder.

This is what our app looks like:

<img title="GUI App" src="http://ww1.sinaimg.cn/large/0070O95Yly1g0x2fibasdj30mw0h9dgx.jpg" width="500">


## Libraries We Use

* [getoptpp](https://code.google.com/archive/p/getoptpp/wikis/Help.wiki) - A getopt C++ version for handling parameters

## TODO:

* Disable `assert` in release version