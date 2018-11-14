# Projekt1
PRPR Project1 C

Projekt č. 1 – Práca s jednorozmerným poľom

Napíšte program, ktorý bude pracovať so záznamami zapísanými v súbore priestupky.txt obsahujúci záznamy o priestupkoch vodičov áut.
Záznamy o priestupkoch v súbore budú vyzerať takto:

meno priezvisko:(medzera) meno vodiča (max. 50znakový reťazec, ktorý obsahuje písmená a medzery)
pohlavie:(medzera) pohlavie vodiča (M – muž, Z – žena)
rok narodenia:(medzera) celé číslo
SPZ: (medzera) štátna poznávacia značka, sedemmiestny znakový reťazec tvaru AACCCBB, kde AA sú dva abecedné znaky reprezentujúce skratku okresu, CCC sú tri číselné znaky a BB sú dva abecedné znaky (napr. BA354SC)
typ priestupku: (medzera) booleovská hodnota (1 pre malý priestupok (pokuta), 0 veľký priestupok (odňatie VP))
vyska pokuty: (medzera) celé číslo z intervalu <10, 2000>
datum priestupku: (medzera) osemmiestne celé číslo v tvare rrrrmmdd 20181024 (24.10.2018)
(prázdny riadok)

Súbor bude obsahovať iba hodnoty, nie typy (názvy) položiek. Za každým záznamom bude prázdny riadok.

Predpokladajte, že záznamy sú v súbore usporiadané podľa položky meno priezvisko.
