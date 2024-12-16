-- Verifica se uma função é crescente no intervalo de 0 a n
isCrescent :: (Int -> Int) -> Int -> Bool
isCrescent f n
  | n <= 0    = True  -- Caso base: intervalos vazios ou com um único elemento
  | otherwise = all (\i -> f i <= f (i + 1)) [0 .. n - 1]

--Exemplos

double :: [Int] -> [Int]
double [] = []
double (a:xs) = (2*a) : double xs

sqrList :: [Int] -> [Int]
sqrList [] = []
sqrList (a:xs)= (a*a) : sqrList xs

--Funções de mapeamento (mapping)

times2 :: Int -> Int

times2 n = 2 * n

sqr :: Int -> Int
sqr n = n * n

--Funções de transformação dos elementos

{-A função de mapeamento

• Recebe como argumentos
– a transformação a ser aplicada a cada elemento
da lista
• uma função
– a lista de entrada-}

--map

map :: (t -> u) -> [t] -> [u]
map f [] = []
map f (a:as) = f a : map f as

doubleList xs = map times2 xs
sqrList xs = map sqr xs

snds :: [(t,u)] -> [u]
snds xs = map snd xs

--map length [“abc“,“defg“] = ?
--Outra definição para map

map f l = [f a | a <- l]

--Exemplo: folding
sumList :: [Int] -> Int
sumList [] = 0
sumList (a:as) = a + sumList as
--e1 + e2 + ... + em

foldr1 :: (t -> t -> t) -> [t] -> t
foldr1 f [a] = a
foldr1 f (a:as) = f a (foldr1 f as)

sumList l = foldr1 (+) l

--Exemplo: folding

and :: [Bool] -> Bool
and xs = foldr1 (&&) xs

concat :: [[t]] -> [t]
concat xs = foldr1 (++) xs

maximum :: [Int] -> Int
maximum xs = foldr1 maxi xs

--Exemplo: folding

--foldr1 (||) [False, True, True]

--foldr1 (++) [“Bom“
--,
--“ “
--,
--“Dia“]
--foldr1 min [6]
--foldr1 (*) [1..6]

--foldr

foldr f s [] = s
foldr f s (a:as)
= f a (foldr f s as)

foldl1 f [x] = x
foldl1 f (x:xs) = foldl f x xs

concat :: [[t]] -> [t]
concat xs = foldr (++) [] xs

and :: [Bool] -> Bool
and bs = foldr (&&) True bs

--foldl

foldl f z [] = z
foldl f z (x:xs) = foldl f (f z x) xs

foldl1 f [x] = x
foldl1 f (x:xs) = foldl f x xs

--Exemplo: filtrando

digits, letters :: String -> String

filter :: (t -> Bool) -> [t] -> [t]
filter p [] = []
filter p (a:as)
| p a = a : filter p as
| otherwise = filter p as

digits st = filter isDigit st

letters st = filter isLetter st

evens xs = filter isEven xs
where isEven n = (n ‘mod‘ 2 == 0)

-- Eleva os itens de uma lista ao quadrado
squares :: [Int] -> [Int]
squares xs = map (^2) xs

-- Soma os quadrados dos itens de uma lista
sumOfSquares :: [Int] -> Int
sumOfSquares xs = foldr (\x acc -> x^2 + acc) 0 xs

-- Filtra apenas os itens maiores que zero
positives :: [Int] -> [Int]
positives xs = filter (>0) xs

{-Exemplo: Biblioteca

livros :: BancoDados -> Pessoa -> [Livro]
livros bd pes = map snd (filter isPess bd)
where isPess (p,l) = (p == pes)

devolver :: BancoDados -> Pessoa
-> Livro -> BancoDados
devolver bd p l = filter notPL bd
where notPL t = (t /= (p,l))-}
