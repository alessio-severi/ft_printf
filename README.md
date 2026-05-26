*This project has been created as part of the 42 curriculum by aseveri.*

## Description

ft_printf è una reimplementazione della funzione `printf()` della libc in C. Il progetto introduce le **funzioni variadiche** — funzioni che accettano un numero variabile di argomenti — e richiede di gestire diversi formati di conversione senza reimplementare il buffer management dell'originale.

La libreria viene compilata come archivio statico `libftprintf.a` e può essere riutilizzata nei progetti successivi del cursus 42, integrandosi con libft.

## Instructions

```bash
make        # compila la libreria libftprintf.a
make clean  # rimuove i file oggetto (.o)
make fclean # rimuove i file oggetto e libftprintf.a
make re     # esegue fclean e ricompila da zero
```

Per usare la libreria in un progetto:
```c
#include "ft_printf.h"
```
```bash
# compilare con:
cc -Wall -Wextra -Werror main.c -L. -lftprintf
```

## Algorithm and Data Structure

### Struttura del progetto

Il codice è organizzato in tre file sorgente:

- `ft_printf.c` — funzione principale e dispatcher
- `ft_printf_utils.c` — funzioni di utilità (`ft_strlen`, `ft_strchr`, `ft_print_number`, `ft_putnbr`)
- `ft_print_text.c` — gestione delle conversioni `%c`, `%s`, `%%`
- `ft_print_number.c` — gestione delle conversioni `%d`, `%i`, `%u`, `%x`, `%X`, `%p`

### Algoritmo del dispatcher

Il cuore del progetto è il **dispatcher** implementato tramite un array di puntatori a funzione:

```c
static int (*ft_dispatcher(const char op))(va_list *opt_params, int *flag)
```

L'array `operators[]` contiene i puntatori alle funzioni di stampa, ognuno associato al carattere di formato corrispondente nella stringa `formats = "cspdiuXx%"`. Quando `ft_printf` incontra un `%` seguito da un carattere valido, `ft_dispatcher` cerca il carattere nell'array e restituisce il puntatore alla funzione corrispondente, che viene chiamata immediatamente.

**Perché questa scelta:** rispetto a una catena di `if/else` o uno `switch`, l'array di puntatori a funzione è più estensibile — aggiungere una nuova conversione richiede solo di aggiungere un elemento all'array e alla stringa dei formati, senza modificare la logica del dispatcher. È anche più leggibile perché la mappatura formato→funzione è esplicita e concentrata in un unico posto.

### Gestione degli errori

Ogni funzione di stampa riceve un puntatore a `flag` intero. Se `write()` fallisce, `flag` viene impostato a `-1` e la funzione restituisce 0. `ft_printf` controlla `flag` dopo ogni operazione e in caso di errore termina immediatamente restituendo `-1`, coerentemente con il comportamento dell'originale.

### Conversione numerica ricorsiva

`ft_print_number` usa la **ricorsione** per stampare numeri in qualsiasi base: divide il numero per la lunghezza della base, si chiama ricorsivamente finché il quoziente è minore della base, poi stampa le cifre nell'ordine corretto (dalla più significativa alla meno significativa). Questo evita di allocare buffer temporanei per invertire le cifre e rende la funzione riutilizzabile per qualsiasi base — decimale, esadecimale maiuscolo e minuscolo — senza duplicare la logica di stampa per diversi formati numerici.

## Resources

- [Linux Man Pages — printf](https://man7.org/linux/man-pages/man3/printf.3.html) — riferimento principale per il comportamento atteso
- [C stdarg.h documentation](https://en.cppreference.com/w/c/variadic) — documentazione sulle funzioni variadiche e `va_list`
- [Linux Man Pages](https://man7.org/linux/man-pages/) — riferimento generale per le funzioni libc


