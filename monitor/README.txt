--------[ CEL ]--------

	  Monitor laczy sie z lokalnym indeksem i okresowo przesyla
	  do niego dane z hosta.

--------[ WYMAGANIA ]--------

	  * Python w wersji >= 2.6
	  * Biblioteki Pythona:
		- ( chyba tylko standardowe )

--------[ JAK UZYWAC ]--------

	  Najpierw uruchamiamy serwer na porcie np. 5488:

	  	   $ nc -l 127.0.0.1 -p 5488

	  Potem uruchamiamy monitor:
	  
		   $ ./r2d2_agent.py

--------[ WYNIK DZIALANIA ]--------

	  * Serwer powinien wyswietlac aktualna date przeslana z agenta
	  * W pliku "application.log" powinny sie pojawiac wpisy, odnosnie
	    dzialania aplikacji.
