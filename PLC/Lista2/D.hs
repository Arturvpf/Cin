
toLowerChar :: Char -> Char
toLowerChar c
    | 'A' <= c && c <= 'Z' = toEnum (fromEnum c + 32)
    | otherwise            = c
    
toLowerString :: String -> String
toLowerString = map toLowerChar

bSort :: [String] -> [String]
bSort []     = []
bSort (x:xs) = bSort [y | y <- xs , y < x] ++ [x] ++ bSort [y | y <- xs, y >= x]

uncommonFromTwoSentences :: String -> String -> [String]
uncommonFromTwoSentences [][] = []
uncommonFromTwoSentences [] str2 = bSort (palavrasUnicas(words (toLowerString str2))) -- se a string 1 for vazia
uncommonFromTwoSentences str1 [] = bSort (palavrasUnicas(words (toLowerString str1))) -- se a string 2 for vazia 
uncommonFromTwoSentences str1 str2 = bSort (palavrasUnicas ((words (toLowerString str2)) ++ (words (toLowerString str1))) )

contaOcorrencias:: String -> [String] -> Int
contaOcorrencias palavra lista = length (filter (== palavra) lista)

palavrasUnicas :: [String] -> [String]
palavrasUnicas [] = []
palavrasUnicas lista = [palavra | palavra <- lista, contaOcorrencias palavra lista == 1] 

main = do
sentence_1 <- getLine
sentence_2 <- getLine
let result = uncommonFromTwoSentences sentence_1 sentence_2
print result


