import Data.List.Split (splitOn)
import Data.Maybe (mapMaybe)

-- Função para extrair os valores numéricos da string
extractValues :: String -> [Double]
extractValues input =
  let items = splitOn ";" input
      parseValue item = case reverse (splitOn "," item) of
        (v:_) -> Just (read v :: Double)
        _     -> Nothing
  in mapMaybe parseValue items

-- Função principal para encontrar o menor e maior valor
minMaxCartao :: String -> (Double, Double)
minMaxCartao input =
  let values = extractValues input
  in (minimum values, maximum values)

-- Função main para testar
main :: IO ()
main = do
  a <- getLine
  let result = minMaxCartao a
  print result
----Wrong-----
