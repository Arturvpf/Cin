--Estruturas de dados - Tuplas

intP :: (Int, Int)
intP = (33,43)

(True,'x') :: (Bool, Char)
(34, 22,'b') :: (Int, Int, Char)

addPair :: (Int,Int) -> Int
addPair (x,y) = x+y

shift :: ((Int,Int),Int) -> (Int,(Int,Int))
shift ((x,y),z) = (x,(y,z))

--Sinônimos de Tipos

type Name = String
type Age = Int
type Phone = Int
type Person = (Name, Age, Phone)

name :: Person -> Name
name (n,a,p) = n

--Resolução bottom-up

--• Definir as funções auxiliares
oneRoot :: Float -> Float -> Float -> Float
oneRoot a b c = -b/(2.0*a)

twoRoots :: Float -> Float -> Float ->
(Float, Float)
twoRoots a b c = (d-e, d+e)
where
  d = -b/(2.0*a)
  e = sqrt(b^2-4.0*a*c)/(2.0*a)

 -- Definir a função principal
roots :: Float -> Float -> Float -> String
roots a b c
| b^2 == 4.0*a*c = show (oneRoot a b c)
| b^2 > 4.0*a*c = show f ++ " " ++ show s
| otherwise = "no roots"
where (f,s) = twoRoots a b c
--ou
f = fst(twoRoots a b c)
s = snd(twoRoots a b c)

{-Defina a função menorMaior que recebe
três inteiros e retorna uma tupla com o
menor e o maior deles, respectivamente.

• Defina a função ordenaTripla que
recebe uma tripla de inteiros e ordena a
mesma.-}

-- Função que retorna o menor e o maior de três números
menorMaior :: Int -> Int -> Int -> (Int, Int)
menorMaior x y z = (minimum [x, y, z], maximum [x, y, z])

-- Exemplos:
-- menorMaior 3 1 2 --> (1, 3)
-- menorMaior 5 8 7 --> (5, 8)
-- Função que ordena uma tripla
ordenaTripla :: (Int, Int, Int) -> (Int, Int, Int)
ordenaTripla (x, y, z) = let [a, b, c] = sort [x, y, z] in (a, b, c)

-- Exemplos:
-- ordenaTripla (3, 1, 2) --> (1, 2, 3)
-- ordenaTripla (5, 8, 7) --> (5, 7, 8)

-- Função para inserir um elemento na posição correta em uma lista ordenada
insereOrdenado :: Int -> [Int] -> [Int]
insereOrdenado x [] = [x]
insereOrdenado x (y:ys)
  | x <= y    = x : y : ys
  | otherwise = y : insereOrdenado x ys

-- Função principal: ordenação por inserção
Sort :: [Int] -> [Int]
Sort [] = []
Sort (x:xs) = insereOrdenado x (Sort xs)
