ChangeMaking: Este algoritmo é usado quando você tem um valor n e um conjunto de denominações de moedas, e você precisa encontrar o número mínimo de moedas que somam n. É útil em situações do mundo real, como máquinas de venda automática ou caixas eletrônicos, onde você precisa dar troco com o menor número de moedas ou notas possível.

CoinRow: Este algoritmo é usado quando você tem uma linha de moedas com diferentes valores e você precisa pegar o máximo de valor possível, mas a restrição é que você não pode pegar duas moedas adjacentes. Este é um problema de otimização que pode ser aplicado em várias situações do mundo real, como jogos de estratégia ou planejamento de investimentos.

MFKnapsack: Este é uma variação do problema da mochila que usa memoização para melhorar a eficiência. É usado quando você tem um conjunto de itens, cada um com um peso e um valor, e uma mochila com uma capacidade de peso limitada. O objetivo é determinar o conjunto mais valioso de itens para incluir na mochila sem exceder a capacidade de peso. Este problema é comum em situações de otimização de recursos, como planejamento de carga de caminhões ou planejamento de investimentos.

Knapsack: Este é o problema da mochila clássico, semelhante ao MFKnapsack, mas sem o uso de memoização. É usado nas mesmas situações que o MFKnapsack, mas pode ser menos eficiente para grandes conjuntos de dados ou capacidades de mochila grandes.


TSP neighb
O algoritmo do vizinho mais próximo para o problema do caixeiro viajante (TSP) pode ser usado quando você precisa encontrar uma solução rápida e boa o suficiente, mas não necessariamente a melhor, para o problema do TSP.

Este algoritmo é útil em situações onde:

O número de cidades (nós) é grande, tornando outras abordagens como a força bruta ou a programação dinâmica impraticáveis devido ao seu alto custo computacional.
Uma solução aproximada é aceitável. O algoritmo do vizinho mais próximo não garante a solução ótima, mas geralmente produz uma solução razoavelmente boa.
O tempo é uma consideração importante. O algoritmo do vizinho mais próximo tem uma complexidade de tempo O(n^2), o que é significativamente melhor do que a força bruta (O(n!)) ou a programação dinâmica (O(n^2 * 2^n)) para o TSP.
Por exemplo, este algoritmo pode ser usado em logística para planejar rotas de entrega, em redes de telecomunicações para roteamento de dados, ou em planejamento de viagens para encontrar uma rota razoável para visitar várias cidades.


TSP MST
Este algoritmo é uma implementação do problema do Caixeiro Viajante (TSP - Traveling Salesman Problem) usando a Árvore de Extensão Mínima (MST - Minimum Spanning Tree).

O problema do Caixeiro Viajante é um problema clássico em ciência da computação. Ele pede a rota mais curta que visita um conjunto de cidades e retorna à cidade de origem. É um problema NP-difícil, o que significa que não existe uma solução eficiente conhecida para todos os casos.

Este algoritmo específico usa a Árvore de Extensão Mínima como uma heurística para o problema. Primeiro, ele constrói a MST do grafo usando o algoritmo de Kruskal. Em seguida, realiza uma caminhada de pré-ordem na MST para obter um ciclo hamiltoniano, que é uma possível solução para o TSP.