{-Problem Statement

Faça a função

btoi :: String -> Int
que, dada uma string representando um número binário, retorna o inteiro na base 10 dessa string.

O bit menos significativo é o da direita.

Utilize a seguinte função main para chamar btoi

main = do
    s <- getLine
    let result = btoi s
    print result
Input

Uma String

Output

Um Inteiro

Examples

Case: 1

Input

1010

Output

10-}

btoi :: String -> Int
btoi bin = foldl (\acc x -> acc * 2 + read [x]) 0 bin

main :: IO()
main = do
  s <- getLine
  let result = btoi s
  print result

--Correct?---
