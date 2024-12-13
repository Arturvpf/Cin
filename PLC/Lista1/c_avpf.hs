-- Função para suavizar uma lista de floats
suaviza :: [Float] -> [Float]
suaviza xs = head xs : [ (xs !! (i - 1) + xs !! i + xs !! (i + 1)) / 3 | i <- [1..length xs - 2] ] ++ [last xs]

-- Função principal para interagir com entrada e saída
main :: IO ()
main = do
  lista <- getLine
  print $ suaviza (read lista :: [Float])
