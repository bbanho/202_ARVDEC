# 202_ARVDEC

Decision tree using non-linear chained lists from Backes' literature

---

Inserir recursivamente nodos na forma

    ref esq dir
    
    a b c <- nodo com ramo filho+filho
    b s x <- nodo com ramo saida+folha
    s x x <- nodo saida
    x x x <- nodo folha
