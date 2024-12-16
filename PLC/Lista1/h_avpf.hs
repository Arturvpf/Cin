{-Problem Statement

Crie a função

isReplica :: String -> Int -> Char -> Bool
que recebe uma string, um inteiro x e um char e verifica se essa string é exatamente a repetição do char x vezes seguidas.

Por exemplo, a string "aaaaa" repete 'a' 5 vezes seguidas.

Utilize a seguinte função main para chamar isReplica

main = do
    a <- getLine
    b <- getLine
    c <- getChar
    let result = isReplica a (read b) c
    print result
Input

Uma String um Inteiro e um Char, cada um em uma linha

Output

Um booleano

Examples

Case: 1

Input

ee
2
e

Output

True

Case: 2

Input

uruu
3
u

Output

False

Case: 3

Input

xxx
3
y

Output

False-}
import Data.Char (digitToInt)

isReplica :: String -> Int -> Char -> Bool
isReplica str x ch = str == replicate x ch

main :: IO()
main = do
  a <- getLine
  b <- getLine
  c <- getChar
  let result = isReplica a (read b) c
  print result

  --Correct but take a look-----
