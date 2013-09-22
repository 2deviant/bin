# BIN
A collection of simple Linux/Darwin command line utilities I've written and used
for years but never formalized, until now.

## Purpose
The purpose of this repository is part archival and part expository.  They are
not the most efficient ways of doing things but, certainly one of the most
instructive.

## Structure
The repository is split into two directories: `slow` and `fast`.  `slow`
directory contains utilities written primarily in bash, harnessing the standard
Linux/Darwin commands and software. ``fast`` directory contains utilities of
identical function but written in C, trading the elegance of the shell code for
performance.  Not all utilities have *fast* versions.

Some files have `_n` (where `n` is an integer) after their name, which implies
a different implementation of the same function.

The utilities in this package are interdependent.  It is best for them to reside
in a directory within $PATH.

## Utilities
### randomhex
```bash
randomhex [ number of bytes ]
```
Return random bytes in hex.  If the number of bytes argument is absent,
it is assumed to be 10.
___
### randomtext
```bash
randomtext [ number of bytes ]
```
Return random text using digits and letters of both capitalizations.  If
the number of bytes argument is
absent, it is assumed to be 10.
___
### randomdec
```bash
randomdec [ number of digits ]
```
Return a random integer. If the number of digits argument is
absent, it is assumed to be 10.
___ 
### randomdec_2
```bash
randomdec_2 [ number of digits ]
```
Faster version of `randomdec`.

Return a random integer. If
the number of digits argument is
absent, it is assumed to be 10.
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
interface to a random sequence and the hostname of the machine to UNKNOWN.

