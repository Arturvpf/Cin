--Listas

--• Coleções de objetos de um mesmo tipo.
--• Exemplos:
--[1,2,3,4] :: [Int]
--[(5,True),(7,True)] :: [(Int,Bool)]
--[[4,2],[3,7,7,1],[],[9]] :: [[Int]]
--[’b’
--,
--’o’
--,
--’m’] :: [Char]
--
--”bom” :: [Char]
--• Sinônimos de tipos:
type String = [Char]
• [] é uma lista vazia de qualquer tipo
• Estruturas de dados recursivas!

{-O construtor de listas (:)

• Outra forma de escrever listas:
[5] é o mesmo que 5:[]
[4,5] é o mesmo que 4:(5:[])
[2,3,4,5] é o mesmo que 2:3:4:5:[]

• (:) é um construtor polimórfico:
(:) :: Int -> [Int] -> [Int]
(:) :: Bool -> [Bool] -> [Bool]
(:) :: t -> [t] -> [t]

[2..7] = [2,3,4,5,6,7]
• [-1..3] = [-1,0,1,2,3]
• ['a'..'d'] =
['a','b','c','d']
• [2.8..5.0] = [2.8,3.8,4.8]
• [7,5..0] = [7,5,3,1]
• [2.8,3.3..5.0]
= [2.8,3.3,3.8,4.3,4.8]
-}
quantosItens :: [a] -> Int
quantosItens lista = length lista

sumList :: [Int] -> Int
sumList [] = 0
sumList (a:as) = a + sumList as

double :: [Int] -> [Int]
double [] = [] -- Caso base explícito
double xs = [x * 2 | x <- xs]

member :: [Int] -> Int -> Bool
member [] _ = False
member (x:xs) n = (x == n) || member xs n

digits :: String -> String
digits [] = [] -- Caso base explícito
digits str = [c | c <- str, c >= '0' && c <= '9']


sumPairs :: [(Int,Int)]->[Int]
sumPairs [] = [] -- Caso base explícito
sumPairs pairs = [a + b | (a, b) <- pairs]

{-Expressão case

• Permite casamento de padrões com valores
arbitrários
– Não apenas argumentos da função

firstDigit :: String -> Char
firstDigit st = case (digits st) of
[] ->

 ́\0 ́
(a:as) -> a-}

{-Outras funções sobre listas

• Comprimento
length :: [t] -> Int
length [] = 0
length (a:as) = 1 + length as
• Concatenação
(++) :: [t] -> [t] -> [t]
[] ++ y = y
(x:xs) ++ y = x : (xs ++ y)
• Estas funções são polimórficas!-}

--Compreensões de listas

--• Usadas para definir listas em função de outras
--listas

doubleList xs = [2*a|a <- xs]
doubleIfEven xs = [2*a|a <- xs, isEven a]

sumPairs :: [(Int,Int)] -> [Int]
sumPairs lp = [a+b|(a,b) <- lp]

digits :: String -> String
digits st = [ch | ch <- st, isDigit ch]

{-Exemplo: Biblioteca

type Pessoa = String
type Livro = String
type BancoDados = [(Pessoa,Livro)]-}

{-Exercício: um banco de dados

baseExemplo :: BancoDados
baseExemplo =
[(”Sergio”
,
”O Senhor dos Aneis”),

(”Andre”
,
”Duna”),

(”Fernando”
,
”Jonathan Strange & Mr.

Norrell”),
(”Fernando”
,
”Duna”)]

-- livros emprestados-}

{-Funções sobre o banco
de dados - consultas

livros ::
BancoDados -> Pessoa -> [Livro]

emprestimos ::
BancoDados -> Livro ->[Pessoa]

emprestado ::
BancoDados -> Livro -> Bool

qtdEmprestimos ::
BancoDados -> Pessoa -> Int-}

{-Funções sobre o banco
de dados - atualizações
emprestar ::
BancoDados -> Pessoa -> Livro
-> BancoDados

devolver ::
BancoDados -> Pessoa -> Livro
-> BancoDados-}

qSort :: [Int] -> [Int]
qSort [] = []
qSort (x:xs) =qSort [y | y <- xs, y < x] ++[x] ++
qSort [y | y <- xs, y >= x]
