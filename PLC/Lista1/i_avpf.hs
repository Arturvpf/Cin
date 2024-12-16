{-Problem Statement

Biu capturou um Charmander! Ele descobriu que seu pokemón tem uma habilidade especial, depois de algumas batalhas que ele leva vantagem contra pokemóns que possui CPs(Combat Power) determinados. Para o Charmander vencer a batalha, seu oponente deve ter CP com seguintes características:

CP deve possuir 4 dígitos; Sendo o CP representado pelas letras ABCD, onde cada letra representa um dígito, O Charmander só vencerá a partida caso (AB - CD)^2 < (ABCD) essas características estiverem presentes.

Sua tarefa é escrever um programa que ajude Biu a escolher melhor os oponentes para que seu Charmander saia sempre vitorioso.

Input

C - número inteiro positivo.

A linha única de entrada é composta pelo CP do oponente.

Output

R - string

A linha única de saída é composta pelo resultado da batalha, com uma das mensagens:

"Charmander vitorioso" "Charmander derrotado"

Examples

Case: 1

Input

5321

Output

"Charmander derrotado"-}

import Data.Char (digitToInt)

result :: Char -> Char -> Char -> Char -> String
result x y z a 
    | (charToi x * charToi y - charToi z * charToi a)^2 < charToi x * charToi y * charToi z * charToi a = "Charmander vitorioso"
    | otherwise = "Charmander derrotado"
    where 
        charToi c = digitToInt c

main :: IO ()
main = do
    a <- getChar
    b <- getChar
    c <- getChar
    d <- getChar
    let resultado = result a b c d
    print resultado
