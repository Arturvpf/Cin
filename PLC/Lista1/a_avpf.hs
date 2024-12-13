import Data.List.Split (splitOn)
import Text.Printf (printf)

-- Função para calcular o total gasto em um mês específico
logMes :: String -> String -> Double
logMes mes fatura = 
  let
    -- Divide a fatura em linhas
    transacoes = splitOn ";" fatura
    -- Filtra as transações do mês especificado
    valoresMes = [read (last (splitOn "," t)) :: Double | t <- transacoes, mes `elem` words t]
  in
    sum valoresMes

-- Função principal para interagir com a entrada e saída
main :: IO ()
main = do
  mes <- getLine
  fatura <- getLine
  let resultado = logMes mes fatura
  printf "%.1f\n" resultado
-------WRONG----------
