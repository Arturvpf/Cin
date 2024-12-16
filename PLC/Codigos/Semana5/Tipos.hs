{-Tipos algébricos

• representar meses: Janeiro, ..., Dezembro
• representar um tipo cujos elementos podem
ser um inteiro ou uma string
• representar o tipo árvore
– Tipos-sinônimo não podem ser recursivos!-}

{-Tipos Enumerados

• Criar novos tipos de dados e novos
construtores de tipos e valores:

data Bool = True | False
data Estacao = Inverno | Verao |
Outono | Primavera
data Temp = Frio | Quente-}

{-Tipos Enumerados

• Funções usam casamento de padrões

clima :: Estacao -> Temp
clima Inverno = Frio
clima _ = Quente

• Relembrando: casamento de padrões utiliza
construtores de dados (listas, tuplas, etc.)-}

{-Produtos

type Nome = String
type Idade = Int
data Pessoas = Pessoa Nome Idade

Pessoa ”José” 22
Pessoa ”Maria” 23

showPerson :: Pessoas -> String
showPerson (Pessoa n a) = n ++ ” -- ” ++ show a

Pessoa :: Nome -> Idade -> Pessoas-}

{-por que não usar tuplas?

type Pessoas = (Nome, Idade)
• Com tuplas
– elementos mais compactos, definições
mais curtas
– maior probabilidade de reusar funções
polimórficas-}

{-por que não usar tuplas?

data Pessoas = Pessoa Nome Idade
• Com tipos algébricos
– cada objeto do tipo tem um rótulo explícito
– não se pode confundir um tipo com outro,
devido ao construtor (definições
fortemente tipadas)
– tipos recursivos e enumerados

Alternativas

• Construtores com argumentos
data Shape = Circle Float
| Rectangle Float Float
Circle 4.9 :: Shape
Rectangle 4.2 2.0 :: Shape
isRound :: Shape -> Bool
isRound (Circle _) = True
isRound (Rectangle _ _) = False

Como definir a função abaixo?

area :: Shape -> Float

Forma geral

• data Nome_do_Tipo
= Construtor1 t11 ... t1k1
| Construtor2 t21 ... t2k2
....
| Construtorn tn1 ... Tnkn
• O tipo pode ser recursivo
• A definição pode ser polimórfica,
adicionando argumentos ao Nome_do_Tipo

Tipos recursivos

• Tipos de dados recursivos
data Expr = Lit Int |
Add Expr Expr |
Sub Expr Expr
• Funções definidas recursivamente
eval :: Expr -> Int
eval (Lit n) = n
eval (Add e1 e2) = (eval e1) + (eval e2)
eval (Sub e1 e2) = (eval e1) - (eval e2)

Tipos polimórficos

• Tipos de dados polimórficos:
data Pairs t = Pair t t
Pair 6 8 :: Pairs Int
Pair True True :: Pairs Bool
Pair [] [1,3] :: Pair [Int]
• Listas
data List t = Nil | Cons t (List t)
• Árvores
data Tree t = NilT |
Node t (Tree t) (Tree t)

Instâncias e tipos algébricos

• É possível criar um tipo algébrico como
instância de algumas classes. Por exemplo:
data Tree t = NilT |
Node t (Tree t) (Tree t)
deriving (Eq, Show)

Comportamento padrão. Nem sempre faz sentido.
Se necessário, é possível especificar uma
instância.

Defina as seguintes funções

showExpr :: Expr -> String
toList :: List t -> [t]
fromList :: [t] -> List t
depth :: Tree t -> Int
collapse :: Tree t -> [t]
mapTree :: (t -> u) -> Tree t -> Tree u

data Expr = Val Int | Add Expr Expr | Mul Expr Expr deriving (Show)

data List t = Empty | Cons t (List t) deriving (Show)

data Tree t = Leaf t | Node (Tree t) (Tree t) deriving (Show)

showExpr :: Expr -> String
showExpr (Val n)     = show n
showExpr (Add e1 e2) = "(" ++ showExpr e1 ++ " + " ++ showExpr e2 ++ ")"
showExpr (Mul e1 e2) = "(" ++ showExpr e1 ++ " * " ++ showExpr e2 ++ ")"

toList :: List t -> [t]
toList Empty        = []
toList (Cons x xs)  = x : toList xs

fromList :: [t] -> List t
fromList []     = Empty
fromList (x:xs) = Cons x (fromList xs)

depth :: Tree t -> Int
depth (Leaf _)     = 1
depth (Node l r) = 1 + max (depth l) (depth r)

collapse :: Tree t -> [t]
collapse (Leaf x)     = [x]
collapse (Node l r) = collapse l ++ collapse r

mapTree :: (t -> u) -> Tree t -> Tree u
mapTree f (Leaf x)     = Leaf (f x)
mapTree f (Node l r) = Node (mapTree f l) (mapTree f r)
