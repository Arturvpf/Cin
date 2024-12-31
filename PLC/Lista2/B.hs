palavrasFrequentes :: [String] -> [String]
palavrasFrequentes palavras =
  let
    counter [] = []
    counter (x:xs) =
      let freq = 1 + length [y | y <- xs, y == x]
          resto = [y | y <- xs, y /= x]
      in (x, freq) : counter resto

    sorting [] = []
    sorting (x:xs) =
      let lowers = [y | y <- xs, snd y > snd x || (snd y == snd x && length (fst y) < length (fst x))]
          biggers = [y | y <- xs, snd y < snd x || (snd y == snd x && length (fst y) >= length (fst x))]
      in sorting lowers ++ [x] ++ sorting biggers

    sorted = sorting (counter palavras)
  in
    take 3 [fst pair | pair <- sorted]

main :: IO ()
main = do
    lista <- getLine
    print $ palavrasFrequentes (read lista :: [String])
