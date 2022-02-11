# Przydatne algorytmy C++ pod OI 

Powrzucam tu jakieś kody algorytmów z kółek itp.
Może się przyda na oi, też może będzie dobrze poprzypominać.

## Dostępność

Postaram się jakoś poszukać jak zrobić dostęp np. tylko z linka, czy coś.
Jakby ktoś coś chciał tu coś dorzucić to niech napisze do mnie gdziekolwiek.

## Dodawanie/edytowanie
### Mdyfikować treści można jedynie będąć do tego uprawnionym, więc aby coś poprawić/dodać trzeba wspomnieć o dodanie się do repo

1. Na stronie
    Aby dodać plik jest opcja na górze Add File
    Aby edytować istniejący plik jest ikonka pisaka, najlepiej opisać na dole co się zmieniło
   
2. Lokalnie
    Aby coś zmieniać najpierw trzeba wykonać następujące kroki:
    - profil -> settings -> Developer settings -> Personal acces tokens -> Generate new token i zaznaczyć opcję repo, token zachować
    - Linux ``sudo apt install git`` i ``git clone  https://github.com/JohnThePenguin/algorithms.cpp``, jako hasła użyć tokenu
    - Na Windows trzeba pobrać gita z ich strony
    
  Gdy się zrobi/zedytuje plik/folder ``git add <nazwa>``.
  Gdy skończy się robić jakąś konkretną rzecz można ``git commit -m "<opisać co się zrobiło>"``
  Gdy chce się wrzucić zmiany to ``git push``
  

## Foldery

Zamierzam przygotować następujące kategorie, żeby szybko móc znaleźć co trzeba
- Podstawy
- Grafy
  - Drzewa
- Drzewa_przedzialow
- Teskstowe
- Teoria_liczb
- inne

## Pobieranie

Na górze po prawej powinniście mieć zielone code, i tam można pobrać sobie zipa, lub
```bash
wget https://github.com/JohnThePenguin/algorithms.cpp
``` 
albo 
```bash
git clone https://github.com/JohnThePenguin/algorithms.cpp
``` 
## ❗BUGI❗

Jeżeli znajdzie się buga w kodzie, to prosiłbym o wybranie 1 z 3 opcji:
- poprawić go
- zgłosić go jakimś sposobem
- napisać na gorze kodu widoczny komentarz o bugu

Miłego korzystania, zachęcam do wrzucania. Powodzenia na OI!
