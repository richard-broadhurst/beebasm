# beebasm
My version of beebasm that I use for my games.

Origanally written By RichTW and main version is https://github.com/stardot/beebasm

VS2010 actually contains a VS2017 project that uses the XP compatible toolchain.

If you don't have this, it should be easy to change to whichever vs2010+ version you have.

It builds with statically linked libs, so no need to ship the redistributables (AFAIK)


Main command line option changes:


-d and -dd

dump labels and scoped labels


-writes

sets the number of disc writes in the generated .SSD

useful if you are using the number of writes to a disc as some sort of catalogue number


Main directive changes:


PRINT CALLSTACK$

dumps the start of each scope leading to the current line,

useful for showing errors in macros


INCBASIC "file.bas"

includes the tokenised version of the file at the current address,

useful for appending code or data to the end of BASIC programs


PRINT "text_",~&CODE

prints text_CODE without any spaces where the commas are,

this is useful if you are concatenating variable for outputing to a later build stage
