{-Problem Statement

No contexto de análise de dados, suavizar os dados resulta numa sequência de pontos onde o ruído previamente existente é minimizado. Uma técnica básica de suavização é dada por trocar um ponto no meio da sequência pelo valor da média dele que é computada como (ponto predecessor + ponto atual + ponto sucessor)/3, implemente essa técnica.

OBS: note o termo "ponto no meio da sequência" isso implica que o ponto inicial e final não tem seus valores alterados

suaviza :: [Float] -> [Float]
Sugestão de Main

main = do
        lista <- getLine
        print $ suaviza (read lista :: [Float])
Input

Lista de Floats

Output

Lista de Floats

Examples

Case: 1

Input

[30,20,10]

Output

[30.0,20.0,10.0]

Case: 2

Input

[30,20,10,10,20]

Output

[30.0,20.0,13.333333,13.333333,20.0]-}

suaviza :: [Float] -> [Float]
suaviza [] = []
suaviza [x] = [x]
suaviza xs = head xs : [ (xs !! (i - 1) + xs !! i + xs !! (i + 1)) / 3 | i <- [1..length xs - 2] ] ++ [last xs]

main :: IO ()
main = do
  lista <- getLine
  print $ suaviza (read lista :: [Float])
