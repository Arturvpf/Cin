data Animal = Cisnal | Iguanoide | Narvale | Null deriving (Eq, Show)

dotProduct :: String -> String -> Float
dotProduct str1 str2 = sum [if a == b then 1.0 else 0.0 | (a, b) <- zip str1 str2]

similarityIndex :: String -> String -> Float
similarityIndex str1 str2 = dotProduct str1 str2 / fromIntegral (max (length str1) (length str2))

classify :: Float -> Animal
classify i
  | i >= 0.1 && i <= 0.3 = Cisnal
  | i >= 0.4 && i <= 0.7 = Iguanoide
  | i >= 0.8            = Narvale
  | otherwise           = Null

dna2 :: [String] -> [String] -> [Int]
dna2 str1 str2 = [count Cisnal, count Iguanoide, count Narvale]
  where
    similarities = [classify (similarityIndex a b) | (a, b) <- zip str1 str2]
    count animal = length (filter (== animal) similarities)

main :: IO ()
main = do
  firstExtract <- words <$> getLine
  secondExtract <- words <$> getLine
  let result = dna2 firstExtract secondExtract
  print result
