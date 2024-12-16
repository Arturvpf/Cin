{-Aplicações parciais

• multiply :: Int -> Int -> Int
multiply a b = a*b
• doubleList :: [Int] -> [Int]
doubleList = map (multiply 2)
• (multiply 2) :: Int -> Int
• map (multiply 2) :: [Int] -> [Int]

Aplicações parciais

• whiteSpace = “ ”
• elem :: Char -> [Char] -> Bool
• elem ch whiteSpace
• \ch -> elem ch whiteSpace
• filter (\ch -> not(elem ch whitespace))
Qual o tipo da função acima?

A função de composição

(revisitada)

(.) :: (u -> v) -> (t -> u) ->
(t -> v)
(.) f g x = f (g x)
==
(.) f g = \x->f (g x)
:type (.)
(.)::(b->c)->(a->b)->a->c

A função iter
(revisitada)

iter :: Int -> (t -> t) -> (t -> t)
iter 0 f = id
iter n f = (iter (n-1) f).f

(iter 10 double) 3

Revisitando iter

iter 10 double 3 ==
iter 10 ((*) 2) 3 ==
iter 10 (2 (*)) 3 ==
iter 10 (2 *) 3 ==
iter 10 (* 2) 3 ?

iter 10 (/ 2) 2000 ==
iter 10 ((/) 2) 2000 ?

Quantos argumentos
uma função tem?

• multiply :: Int -> Int -> Int
• multiply :: Int -> (Int -> Int)
• multiply 4
• (multiply 4) 5

mais aplicações parciais

• dropSpace
= dropWhile (member whitespace)
• dropWord
= dropWhile (not.(member whitespace))
• getWord
= takeWhile (not . member whitespace)

• member ::[t]->t->Bool
• member st x = elem x st

Mais exemplos ...

• (+2)
• (>2)
• (3:)
• (++ “\n“)
• filter (>0).map (+1)
• double = map (*2)
• dificil = map.filter
• maisdificil = map.foldr
• maisainda = foldr.map-}
