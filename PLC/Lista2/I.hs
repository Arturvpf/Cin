data Tree t = Node t (Tree t) (Tree t) | Nilt
  deriving (Read, Show)

dna1 :: Tree Int -> [String]
dna1 Nilt = []
dna1 arvore = divstr (toLetters arvore)

toLetters :: Tree Int -> String
toLetters Nilt = []   
toLetters (Node actual esq dir) | actual `mod` 5 == 0 = toLetters esq ++ "E" ++ toLetters dir
                                         | actual `mod` 5 == 1 = toLetters esq ++ "M" ++ toLetters dir
                                         | actual `mod` 5 == 2 = toLetters esq ++ "A" ++ toLetters dir
                                         | actual `mod` 5 == 3 = toLetters esq ++ "C" ++ toLetters dir
                                         | actual `mod` 5 == 4 = toLetters esq ++ "S" ++ toLetters dir

divstr :: String -> [String]
divstr []  = []
divstr str = take 8 str : divstr (drop 8 str) 

main :: IO ()
main = do
  input <- getLine
  let arvore = read input :: Tree Int
  let result = dna1 arvore
  print result
