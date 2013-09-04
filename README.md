This is my take at http://www.yodlecareers.com/puzzles/jugglefest.html

Installation
------------

To compile the project run 

autoreconf --install

and then the usual 

./configure && make

This will build the main binary in the src/ subdir. 


Usage
-----

Type

src/driver inputfile


Requirements
------------

automake and autoconf are required to run autoreconf and setup the autotools configuration files. 
Check with your linux distribution how to install them.  On osx you can use homebrew. 
