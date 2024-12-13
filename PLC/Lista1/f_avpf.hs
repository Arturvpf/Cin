-- Função que soma os múltiplos de um número na lista
somarMultiplos :: [Int] -> Int -> [Int]
somarMultiplos lista m
  | m <= 0 = replicate (length lista) 0 -- Se m for menor ou igual a 0, retorna uma lista de zeros
  | otherwise = map (\x -> sum [y | y <- lista, y `mod` m == 0, y < x]) lista

-- Função main para entrada e saída
main :: IO ()
main = do
  lista <- getLine
  num <- getLine
  let readList = read lista :: [Int]
  let readNum = read num :: Int
  let result = somarMultiplos readList readNum
  print result
