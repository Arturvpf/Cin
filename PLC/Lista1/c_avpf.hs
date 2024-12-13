suaviza :: [Float] -> [Float]
suaviza [] = []
suaviza [x] = [x]
suaviza xs = head xs : [ (xs !! (i - 1) + xs !! i + xs !! (i + 1)) / 3 | i <- [1..length xs - 2] ] ++ [last xs]

main :: IO ()
main = do
  lista <- getLine
  print $ suaviza (read lista :: [Float])
