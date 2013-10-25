# BIN
A collection of simple Linux/Darwin command line utilities I've written and used
for years but never formalized, until now.

## Purpose
The purpose of this repository is part archival and part expository.  They are
not the most efficient ways of doing things but, certainly one of the most
instructive.  The code is endowed with generous amount of comments and
explanations.

## Structure
The repository is split into two directories: `slow` and `fast`.  `slow`
directory contains utilities written primarily in bash and Perl, harnessing the
standard Linux/Darwin commands and software. ``fast`` directory contains
utilities of identical function but written in C, trading the elegance of the
shell code for performance.  Not all utilities have *fast* versions.

Some files have `_n` (where `n` is an integer) after their name, which implies
a different implementation of the same function, typically faster or simpler or
both.

Some utilities in this package are interdependent.  It is best for all to reside
in a directory within $PATH.

## Utilities
### randomhex
```bash
randomhex [ number of bytes ]
```
Return a random hexadecimal number.  Default number of bytes is 10.
___
### randomhex_2
```bash
randomhex_2 [ number of bytes ]
```
A faster, OpenSSL-driven version of the above.
___
### randomtext
```bash
randomtext [ number of bytes ]
```
Return random text using digits and letters of both capitalizations.
___
### randomtext_2
```bash
randomtext_2 [ number of bytes ]
```
A faster, OpenSSL-driven version of the above.
___
### randomdec
```bash
randomdec [ number of digits ]
```
Return a random integer.
___ 
### randomdec_2
```bash
randomdec_2 [ number of digits ]
```
A much faster version of the above.
___
### randomline
```bash
randomline hostnames.txt
ls | randomline
randomline < hostanames.txt
```
Return a random line from a supplied file.
If the file is not readable, e.g. not supplied, an attempt to
read from the STDIN is made.
___
### randommac
```bash
randommac [ interface ]
randommac eth1
```
Change the MAC address of a given
interface to a random sequence and the hostname of the machine to `UNKNOWN`.
___
### min, max, mode, mean, add
```bash
min < numbers.txt
ls -l | awk '{print $5}' | max
ls -l | awk '{print $5}' | add
last | awk '{print $1}' | mode
mean < numbers.txt
```
Compute the corresponding statistic of a list of numbers taken from the standard
input.  The numbers can be separated by a mixture of spaces, tabs, and newlines.

`mode` takes any data, not just numbers.

