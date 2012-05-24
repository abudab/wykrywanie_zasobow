
----------[ Global Cache ]----------

Wymagania:

     * Baza danych PostgreSQL (PostgreSQL 9.1)
     * Biblioteka do obslugi PostgreSQL w C++ (pqxx)
     * Boost - regex (libboost-regex)

Opis Dzialania:

     * Bufor globalny (global_cache) przyjmuje zapytania w formie "drzewa zapytania".
     * W celu jego przetworzenia, drzewo przesylane jest do modulu rozwiazywania zapytan
       (query_dispatcher) z ktorego zwracane jest zapytanie w formie SQL dla bazy danych.
     * (global_cache) odpytuje poprzez modul zarzadzania baza danych (database_storage) o
       wartosci statyczne po czym zwraca otrzymane wyniki przez interfejs zewnetrzny

Architektura:


		+----------------+	      +-----------------+	  
		|                |	      |                 +<----------------+
		|  Querry        |	      |   Database      |	          |
		|  Dispatcher    |	      |   Storage       |	          V
		|                +--\         |                 |	        -------
		+----------------+   \        +----+--------+---+	     --/       \--
		        ^ 	      \		   ^	    |		    /             \
			 \ 	  [const char*]	   |	    |		    |             |
			  | 	       \	 getData()  |		    \             /
			  \  	        \	   |	    |		    |--\       /--|
			   \  	         \	   |   	  [???]		    |   -------   |
			dispatch()       |	   |   	    |		    |  DATABASE   |
			     | 		  V	   |   	    /		    \    PG 9.1   /
			     \ 	    +--------------+-+ 	  -/		     --\       /--
			      \     |                |   /		        -------
			       \----+   Global       |  /
				    |   Cache        |<			    [postgres.dump]
				    |                +----------------+
				    +----+------+----+		      |
					 |	^		*implements*
					 |	|		      |
		                	 |	|		     \-/
	          <-------- [response] --+	|		      V
	       					|		+-----+-----------+
	       					|		|                 |
	          --------- getData() ----------+		|      Global     |
	       	            [search]				|      Cache      |
								|    Interface    |
								|                 |
								+-----------------+
