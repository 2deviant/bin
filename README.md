# BIN
A collection of simple Linux/Darwin command line utilities I've written and used for
years but never formalized, until now.

## Purpose
The purpose of this repository is part archival and part expository.

## Structure
The repository is split into two directories: `slow` and `fast`.  `slow` directory
contains utilities written primarily in bash, harnessing the standard Linux/Darwin commands
and software. ``fast`` directory contains utilities of identical function but written in C,
trading the elegance of the shell code for performance.  Not all utilities have *fast* versions.

## Utilities

* **`randomhex [ number of bytes ]`**

    Return random bytes in hex.  If the
    number of bytes argument is absent,
    it is assumed to be 10.

* **`randomtext [ number of bytes ]`**

    Return random text using digits and
    letters of both capitalizations.  If
    the number of bytes argument is
    absent, it is assumed to be 10.

* **`randommac [ interface ]`**

    Change the MAC address of a given
    interface to a random sequence.
    
    **Example:**
    ```bash
    randommac eth1
    ```
