-- Função para multiplicar duas listas elemento a elemento
-- Quando as listas têm tamanhos diferentes, usa-se 0 para os elementos extras
mul2 :: [Int] -> [Int] -> [Int]
mul2 xs ys = zipWith (*) xs' ys'
  where
    maxLength = max (length xs) (length ys)
    xs' = take maxLength (xs ++ repeat 0)
    ys' = take maxLength (ys ++ repeat 0)

-- Função principal para interagir com a entrada e saída
main :: IO ()
main = do
  sa <- getLine
  sb <- getLine
  let a = read sa :: [Int]
  let b = read sb :: [Int]
  let result = mul2 a b
  print result


---Correct-----
