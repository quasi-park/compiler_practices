# TODO and bug list
## known bugs
- spaces are not allowed in this program right now b.c. scanf cannot accept spaces as one 'letter'.
    - maybe use other functions like `fgets`?
    - use `getchar()` and loop until `\n` or EOF?
    - UPDATE: currently using `fgets` as input source (I dare say this is not a good idea... still have to think alittle bit more).
- when `(` or `)` token are used after/before any other operations, this program will stop b.c. it is currently not allowing operation token right after another operation token.
- there is (obviously) a maximmum BUFLEN right now. This is actually not that great...(although as long as Im using C, this problem is unsolveable...)

## Changes I might make
- currently using bi-directional list. might use linear list. 
- many many unneeded vars.
- currently using too much main. Should divide to seperate funcs.
