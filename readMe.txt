# MaszynaStosowa
Napisz program wykonujący następujące operacje na stosie liczb całkowitych. Stos zaimplementowany jako lista jednokierunkowa.

liczba
  włożenie na stos danej liczby
p
  wypisanie stosu (od wierzchołka do spodu)
s
  zamiana miejscami dwóch liczb na szczycie stosu
x
  usunięcie elementu ze szczytu stosu
+
  zdjęcie dwóch liczb ze stosu i włożenie na stos ich sumy
r
  zdjęcie ze stosu liczby n, przeniesienie liczby z wierzchołka stosu na n-te miejsce licząc od wierzchołka; 0 r oraz 1 r nic nie robi,
  2 r jest tożsame z s, 3 r zamienia 3 2 1 na 2 1 3 itd.
q
  zakończenie programu
  
Uwaga: operacje s i r mogą modyfikować jedynie wskaźniki.
Wejście

Na wyjściu zostanie podany ciąg poleceń. Każde polecenie będzie składało się z jednego znaku.
Wyjście

Na wyjście należy wypisać wynik poleceń p, rozdzielając je znakami nowej linii.
Przykład

Wejście

1 p

2 p

3 p

4 p

5 p

x p

x p

x p

x p

x p

1 2 3 4 5 p

+ p

+ p

+ p

+ p

x p

1 2 3 4 5 p

s p

s p

1 r p

2 r p

2 r p

3 r p

3 r p

3 r p

4 r p

4 r p

4 r p

4 r p

5 r p

5 r p

5 r p

5 r p

5 r p

q

Wyjście

1 

2 1 

3 2 1 

4 3 2 1 

5 4 3 2 1 

4 3 2 1 

3 2 1 

2 1 

1 

5 4 3 2 1 

9 3 2 1 

12 2 1 

14 1 

15 


5 4 3 2 1 

4 5 3 2 1 

5 4 3 2 1 

5 4 3 2 1 

4 5 3 2 1 

5 4 3 2 1 

4 3 5 2 1 

3 5 4 2 1 

5 4 3 2 1 

4 3 2 5 1 

3 2 5 4 1 

2 5 4 3 1 

5 4 3 2 1 

4 3 2 1 5 

3 2 1 5 4 

2 1 5 4 3 

1 5 4 3 2 

5 4 3 2 1 
