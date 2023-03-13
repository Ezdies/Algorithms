//warunek stopu, nie mamy jak dojść do dalszego wierzchołka, a pole ma kolor zielony
//jak przejdziemy przez cały graf i nie zakończymy na kolorze zielonym, to przegrywamy
//przechodzimy bfsem - musimy wykryć cykle
//wierzchołek początkowy zawsze będzie kolorem zielonym
//wszystkie kolejne muszą mieć kolor czerwony
//dwie tablice odwiedzone - kolorem czerwonym i kolorem zielonym
//jak w jednym przejściu będzie zielony, a w innym czerwony, to będą to dwa zupełnie inne stany
//dodając kolejny wierzchołek do kolejki zapisujemy skąd ten wierzchołek przyszedł
//jeżeli wejdziemy na jakiś wierzchołek który został odwiedzony, to możemy zaznaczyć, że znaleźliśmy tam cykl
//jeśli przejdziemy przez graf i nie znajdziemy odpowiedzi, to sprawdzamy jeszcze raz czy nie ma tam cykli
//jak dfsem wrócimy do wierzchołka w którym już byliśmy, to znaczy, że znaleźliśmy cykl

//TO DO: nauka szybkiego pisania DFSa i BFSa
//na kursie sprawdzarkowym uważanie na złożoność pamięciową, co jest overkill na konkursach
//można spróbować podczas grafów stosować macierze sąsiedztwa

