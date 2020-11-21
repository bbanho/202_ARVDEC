# 202_ARVDEC

Decision tree using non-linear chained lists from Backes' literature

---

Inserir recursivamente nodos na forma

    ref esq dir
    
    a b c <- nodo com ramo filho+filho
    a b s <- nodo com ramo filho+saida
    a s s <- nodo com ramo saida+saida
    a s x <- nodo com ramo saida+folha
    s x x <- nodo saida
    x x x <- nodo folha
    
    
    buscar ref
      se vazio, nova arvore
      cc
        // ignorar nodos folha
        buscar nodo (recursao) (busca ordenada?)
          ate folha
          se nodo existir
            inserir filhos
          senao
            inserir nodo e filhos
