battleResult :: Int -> String
battleResult cp
  | (ab - cd)^2 < abcd = "Charmander vitorioso"
  | otherwise          = "Charmander derrotado"
  where
    digits = map (read . (:[])) (show cp) -- Converte o número em uma lista de dígitos
    [a, b, c, d] = digits                 -- Extrai os dígitos
    ab = 10 * a + b                       -- Calcula AB
    cd = 10 * c + d                       -- Calcula CD
    abcd = cp                             -- ABCD é o próprio CP

main :: IO ()
main = do
  input <- getLine
  let cp = read input :: Int
  putStrLn $ battleResult cp
