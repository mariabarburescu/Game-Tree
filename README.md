# Game-Tree

Acest proiect este o introducere în vasta lume a jocurilor, implementând cele mai simple tehnici folosite, în inteligența artificială, pentru jocurile cu informație perfectă, ce au doi jucători.
Am implementat Algoritmul Minimax, care realizează o căutare în adâncime a arborelui de joc, unde nodurile reprezintă stări ale jocului. Frunzele sunt stările finale pentru joc.
În continuare am implementat Arborele ȘI/SAU, unde nodul SAU – selectarea unei mutări pentru jucător curent, iar nodul ȘI – considerarea tuturor mutărilor posibile ale adversarului. Frunzele se etichetează cu T sau F, în funcție de configurația jocului. Pentru nodurile interne de tip SAU, cu T dacă există cel puțin un nod fiu ce a fost etichetat cu T. Pentru nodurile interne de tip ȘI, cu T dacă toate nodurile fiu au fost etichetate cu T.
În final am aplicat Algoritmul Minimax pentru un arbore de joc pentru care cunoșteam valorile nodurilor frunze.
