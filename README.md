# Double-Linked-List
## Polish instructions
Celem projekt jest zaimplementowanie listy dwukierunkowej.

Dane przechowywane to liczby 8 bajtowe -- type unsigned long long int wystarczy do przechowywania ich i obsługi wejścia-wyjścia.
Lista ma dodatkowo do 10 iteratorów: iterator wskazuje na poszczególny element na liście. 
Są dwa stałe iteratory BEG i END, wskazujące odpowiednio na początek i koniec listy.

Interfejs:
Operacje które będą podawane na wejściu to:
- I <br/>
Inicjalizacja listy.
- i x y <br/>
Zainicjuj iterator o numerz x na pozycję y. Wartość y to albo [BEG], albo [END], albo numer. Jeżeli to numer i' to element wskazywany powinien zostać skopiowany z iteratora i'. Iterator może zostać inicjowany wiele razy i oczywiście nie powinno to robić problemów typu wycieki pamięci. Iteratory (poza BEG i END) są etykietowane od 0 do 9.
- \+ x <br/>
Przesuń iterator numer x do przodu. Jeżeli przesunięcie jest to niemożliwe to iterator powinien wskazywać na ostatni element.
- \- x <br/>
Cofnij iterator o numerze x. Jeżeli to niemożliwe, to iterator powinien zacząć wskazywać na I element.
- .A x y <br/>
Dodaj liczbę y przed pozycję wskazywaną przez x. X może być albo [BEG] albo [END], albo numerem iteratora. W przypadku pustej listy dodaj liczbę y i zainicjuj BEG i END odpowiednio.
- A. x y <br/>
Dodaj liczbę y za pozycję x. Jak poprzednio x może być równy [BEG] lub [END] lub numerem iteratora. W przypadku pustej listy dodaj liczbę y i zainicjuj BEG i END odpowiednio.
- R x <br/>
Usuń element wskazywany przez x. X może być równy [BEG] lub [END] lub numerowi iteratora. Jeżeli element został usunięty, to wszystkie iteratory uprzednio wskacujące na niego powinny zacząć wskazywać na kolejny element. Jeżeli to niemożliwe (usunięto ostatni element na liście), to powinny wskazywać na koniec listy. Jeżeli to niemożliwe (usunięto ostatnie element z listy), to powinny być niezainicjowane.
- P p <br/>
Wypisz elementy. Jeżeli wartość parametru p to [ALL] to wypisz wszystkie od początku do końca. Jeżeli p jest numerem, to wypisz element wskazywany przez p-ty iterator.

Przykładowe dane:

Wejście 1:
- I
- .A BEG 10
- P ALL
- .A BEG 9
- P ALL
- .A BEG 8
- P ALL
- .A BEG 7
- P ALL
- .A BEG 6
- P ALL
- R BEG
- P ALL
- R BEG 
- P ALL
- R BEG
- P ALL
- R BEG
- P ALL
- .A BEG 5
- P ALL
- .A BEG 4
- P ALL
- .A BEG 3
- P ALL
- .A BEG 2
- P ALL
- .A BEG 1
- P ALL

Wyjście:
- 10 
- 9 10 
- 8 9 10 
- 7 8 9 10 
- 6 7 8 9 10 
- 7 8 9 10 
- 8 9 10 
- 9 10 
- 10 
- 5 10 
- 4 5 10 
- 3 4 5 10 
- 2 3 4 5 10 
- 1 2 3 4 5 10 

Wejście 2:
- I
- A. BEG 1
- A. END 2
- A. END 3
- A. END 4
- A. END 6
- P ALL
- i 0 BEG
- \+ 0
- \+ 0
- R 0 
- P ALL
- A. 0 5
- P ALL
- .A 0 3
- P ALL

Wyjście:
- 1 2 3 4 6 
- 1 2 4 6 
- 1 2 4 5 6 
- 1 2 3 4 5 6 

## English instructions
The aim of the project is to implement a double linked list.

The data stored on the list are positive integer numbers (8B) -- unsigned long long int type suffices to store them. 
A list can have up to 10 iterators; an iterator point to a particular numbers on the list.
There are two "fixed" iterators BEG and END, pointing to the first and last element, respectively.

Interface:
The operations to implement are:
- I <br/>
List initialization.
- i x y <br/>
Initialize the x-th iterator to the position y. The value of y can be either [BEG]inning, or [END], or a number. If it is a number i', then the iterator should be a copy of the i'-th iterator. An iterator can be initialized many times and there should be no memory leaks. The iterators (except BEG and END) are labeled from 0 to 9.
- \+ x <br/>
Move the x-th iterator forward. If moving forward is impossible, then the iterator should point to the last element.
- \- x <br/>
Move the x-th iterator backward. If moving backward is impossible, then the iterator should point to the first element.
- .A x y <br/>
Add the number y before the position x. As previously, x can be either [BEG]inning, [END], or a number of iterator. In the case of an empty list, add the number to the list and initialize BEG and END appropriately.
- A. x y <br/>
Add the number y after the position x. As previously, x can be either [BEG]inning, [END], or a number of iterator. In the case of an empty list, add the number to the list and initialize BEG and END appropriately.
- R x <br/>
Remove an element given by the position x. Similarly, x can either [BEG]inning or [END] of list, or a number of iterator. If an element is removed, then all iterators pointing at it should start pointing to the next element. If this is not possible (the element at the end was removed) they should point to the new last element. If this is also not possible (the last element was removed) the pointer should become uninitialized.
- P p <br/>
Print the number on the position given by p. The parameter p can be of two types. It can be [ALL] which means to print from head to tail. Or it may be a number of iterator -- in the last case print the value pointed.

Sample Data:

Sample Input 1:
- I
- .A BEG 10
- P ALL
- .A BEG 9
- P ALL
- .A BEG 8
- P ALL
- .A BEG 7
- P ALL
- .A BEG 6
- P ALL
- R BEG
- P ALL
- R BEG 
- P ALL
- R BEG
- P ALL
- R BEG
- P ALL
- .A BEG 5
- P ALL
- .A BEG 4
- P ALL
- .A BEG 3
- P ALL
- .A BEG 2
- P ALL
- .A BEG 1
- P ALL

Corresponding output:
- 10 
- 9 10 
- 8 9 10 
- 7 8 9 10 
- 6 7 8 9 10 
- 7 8 9 10 
- 8 9 10 
- 9 10 
- 10 
- 5 10 
- 4 5 10 
- 3 4 5 10 
- 2 3 4 5 10 
- 1 2 3 4 5 10 

Sample Input 2:
- I
- A. BEG 1
- A. END 2
- A. END 3
- A. END 4
- A. END 6
- P ALL
- i 0 BEG
- \+ 0
- \+ 0
- R 0 
- P ALL
- A. 0 5
- P ALL
- .A 0 3
- P ALL

Corresponding output:
- 1 2 3 4 6 
- 1 2 4 6 
- 1 2 4 5 6 
- 1 2 3 4 5 6 
