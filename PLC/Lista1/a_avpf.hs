{-Problem Statement

Considere a fatura anual de um cartão

----------------------------------------
Data;Tipo;Compra;Valor;
14 JAN;Amazon;40.32;
15 JAN;Uber;14.84;
25 JAN;Uber;34.24;
02 FEV;Spotify;8.50;
06 FEV;Uber;6.94;
05 MAR;Burger;29.90;
10 MAR;Burger;24.99;
15 MAR;UCI;19.00;
08 ABR;Itunes;3.50;
13 ABR;Picpay;20.00;
----------------------------------------
Essa fatura é representada pela String:

"14 JAN;Amazon;40.32;15 JAN;Uber;14.84;25 JAN;Uber;34.24;02 FEV;Spotify;8.50;06 FEV;Uber;6.94;05 MAR;Burger;29.90;10 MAR;Burger;24.99;15 MAR;UCI;19.00;08 ABR;Itunes;3.50;13 ABR;Picpay;20.00;"
Escreva a função

logMes :: String -> String -> Double
que recebe uma String JAN, FEV, MAR ou ABR e uma String referente a uma fatura anual e retorna o total gasto no mês em questão.

ATENÇÃO: Vários alunos reportaram problemas com a precisão da saída (já que está sendo utilizado um Double). Se estiver tendo problemas com a precisão do resultado, considere utilizar a função foldl.

Utilize a seguinte função main para chamar logCartao

main = do
    a <- getLine
    b <- getLine
    let result = logMes a b
    print result
Input

Duas strings, uma em cada linha

Output

Um Double

Examples

Case: 1

Input

JAN
14 JAN;Amazon;40.32;15 JAN;Uber;14.84;25 JAN;Uber;34.24;02 FEV;Spotify;8.50;06 FEV;Uber;6.94;05 MAR;Burger;29.90;10 MAR;Burger;24.99;15 MAR;UCI;19.00;08 ABR;Itunes;3.50;13 ABR;Picpay;20.00;

Output

89.4-}

changeChar :: String -> String 
changeChar [] = []
changeChar (x:xs) | x == ';' = ' ' : changeChar xs
                       | otherwise = x : changeChar xs

divStr :: String -> [String] 
divStr []  = []
divStr str = words str

tupla :: [String] -> [(String, Double)] 
tupla [] = []
tupla (a:b:c:d:xs) = (b, read d) : tupla xs

verif :: String -> [(String, Double)] -> [Double]
verif y [] = []
verif sigla ((a,b):xs) | a == sigla = b : verif sigla xs
                              | otherwise  = verif sigla xs

logMes :: String -> String -> Double
logMes sigla frase | null sigla || null frase = 0.0
                                                | otherwise = foldl (+) 0 (verif sigla (tupla (divStr (changeChar frase))))

main = do
    a <- getLine
    b <- getLine
    let result = logMes a b
    print result

--JAN
--14 JAN;Amazon;40.32;15 JAN;Uber;14.84;25 JAN;Uber;34.24;02 FEV;Spotify;8.50;06 FEV;Uber;6.94;05 MAR;Burger;29.90;10 MAR;Burger;24.99;15 MAR;Uci;19.00;08 ABR;Itunes;3.50;13 ABR;Picpay;20.00;
