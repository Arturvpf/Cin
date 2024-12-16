{-Problem Statement

Considere o seguinte tipo:

data Tree t = Node t (Tree t) (Tree t) 
              | Nilt
              deriving (Read)
Faça a função

alturaArvore :: Tree t -> Int
que retorne a altura de uma árvore dada. Lembrando que, a altura da árvore é definida por sua subárvore mais "alta".

Utilize a seguinte função main para chamar alturaArvore:

main = do
       a <- getLine
       let result = alturaArvore (read a::Tree Int)
       print result
Input

Um Tree

Output

Um Int

Examples

Case: 1

Input

Node 10 (Node 5 (Nilt) (Nilt)) (Nilt)

Output

2

Case: 2

Input

Nilt

Output

0-}

data Tree t = Node t (Tree t) (Tree t) 
              | Nilt
              deriving (Read)

alturaArvore :: Tree t -> Int
alturaArvore Nilt = 0
alturaArvore (Node value (tree1) (tree2)) = 1 + maxi (alturaArvore (tree1))(alturaArvore (tree2))

main = do
       a <- getLine
       let result = alturaArvore (read a::Tree Int)
       print result
