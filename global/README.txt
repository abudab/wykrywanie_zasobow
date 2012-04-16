
----------[ Global Cache ]----------

Opis Dzialania:

     * Bufor globalny (global_cache) przyjmuje zapytania w formie "drzewa zapytania".
     * W celu jego przetworzenia, drzewo przesylane jest do modulu rozwiazywania zapytan
       (query_dispatcher) z ktorego zwracane jest zapytanie w formie SQL dla bazy danych.
     * (global_cache) odpytuje poprzez modul zarzadzania baza danych (database_storage) o
       wartosci statyczne po czym zwraca otrzymane wyniki przez interfejs zewnetrzny


