# Joc X și 0 (Tic-Tac-Toe) în C

Un joc clasic de X și 0 dezvoltat în limbajul C, rulat direct în terminal. Proiectul este structurat modular și folosește un `MakeFile` pentru automatizarea compilării.

## Caracteristici
* **Meniu principal:** Permite utilizatorului să aleagă modul de joc sau să iasă din program.
* **Două moduri de joc:**
  1. Jucător vs Jucător (1v1 local, de la aceeași tastatură).
  2. Jucător vs Calculator (Modul Singleplayer, unde calculatorul alege poziții libere în mod aleatoriu).
* **Interfață colorată:** Folosește coduri ANSI pentru evidențierea pieselor (X este roșu, 0 este albastru), a cifrelor ghid (galben) și a mesajului de câștig (verde).
* **Validare automată:** Programul curăță buffer-ul în caz de input greșit (litere în loc de cifre) și nu permite suprascrierea căsuțelor deja ocupate.

## Structura Fișierelor
* `main.c` - Conține meniul principal, gestionarea rundelor și logica celor două moduri de joc.
* `joc.c` - Implementarea funcțiilor pentru desenarea tablei, marcarea casetelor, mutarea aleatorie a PC-ului și verificarea condiției de câștig.
* `joc.h` - Declarațiile funcțiilor și definițiile macro-urilor pentru culorile din terminal.
* `MakeFile` - Fișierul de configurare pentru compilarea rapidă a proiectului.

## Compilare și Rulare

### Compilare
Pentru a compila toate fișierele automat, deschide terminalul în folderul proiectului și rulează:
```bash
mingw32-make
