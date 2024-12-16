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

minMaxCartao :: String -> (Double, Double)
que recebe uma String referente a fatura anual e retorna uma tupla com o menor e o maior dos valores gastos.

Utilize a seguinte função main para chamar minMaxCartao

main = do
    a <- getLine
    let result = minMaxCartao a
    print result
Input

Uma string

Output

Uma tupla com dois Double

Examples

Case: 1

Input

14 JAN;Amazon;40.32;15 JAN;Uber;14.84;25 JAN;Uber;34.24;02 FEV;Spotify;8.50;06 FEV;Uber;6.94;05 MAR;Burger;29.90;10 MAR;Burger;24.99;15 MAR;UCI;19.00;08 ABR;Itunes;3.50;13 ABR;Picpay;20.00;

Output

(3.5,40.32)-}

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
logMes sigla f | null sigla || null f = 0.0
                                                | otherwise = foldl (+) 0 (verif sigla (tupla (divStr (changeChar f))))
                                                
minMaxCartao :: String -> (Double, Double)
minMaxCartao fatura = (minimum valores, maximum valores)
  where
    valores = map snd (tupla (divStr (changeChar fatura)))

main = do
    a <- getLine
    let result = minMaxCartao a
    print result

--JAN
--14 JAN;Amazon;40.32;15 JAN;Uber;14.84;25 JAN;Uber;34.24;02 FEV;Spotify;8.50;06 FEV;Uber;6.94;05 MAR;Burger;29.90;10 MAR;Burger;24.99;15 MAR;Uci;19.00;08 ABR;Itunes;3.50;13 ABR;Picpay;20.00;
