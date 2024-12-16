{-Problem Statement

Dados os seguintes tipos algébricos

data Ops = SUM | MUL | SUB
           deriving (Read)

data IntTree = Nilt Int |
               Node Ops IntTree IntTree
               deriving (Read)
Escreva a função

evalTree :: IntTree -> Int
que calcula o valor resultante das operações na árvore dada.

As operações podem ser:

SUM = Soma

SUB = Subtração

MUL = Multiplicação

Utilize a seguinte função main para chamar evalTree:

main = do
    s <- getLine
    let result = evalTree (read s)
    print result
Input

Um IntTree

Output

Um Int

Examples

Case: 1

Input

(Node SUM (Node MUL (Nilt 5) (Nilt 3)) (Node SUB (Nilt 10) (Nilt 5)))

Output

20-}
data Ops = SUM | MUL | SUB
           deriving (Read, Eq)

data IntTree = Nilt Int |
               Node Ops IntTree IntTree
               deriving (Read)

evalTree :: IntTree -> Int
evalTree (Nilt x) = x -- se so tiver um valor retorna ele 
evalTree (Node operacao esq dir) | operacao == SUM = (evalTree esq) + (evalTree dir)
                                 | operacao == MUL = (evalTree esq) * (evalTree dir)
                                 | operacao == SUB = (evalTree esq) - (evalTree dir)

main = do
    s <- getLine
    let result = evalTree (read s)
    print result


-- precisa comecar a fazer as operacoes das folhas para a raiz
-- faz a op do primeiro ramo
-- depois faz do segundo
-- depois faz dos resultados

-- precisa fazer um percurso pos ordem e ir fazendo as operacoes
