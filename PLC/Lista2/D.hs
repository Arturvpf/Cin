
lowChar :: Char -> Char
lowChar c
    | 'A' <= c && c <= 'Z' = toEnum (fromEnum c + 32)
    | otherwise            = c
    
lowString :: String -> String
lowString = map lowChar

bSort :: [String] -> [String]
bSort []     = []
bSort (x:xs) = bSort [y | y <- xs , y < x] ++ [x] ++ bSort [y | y <- xs, y >= x]

uncommonFromTwoSentences :: String -> String -> [String]
uncommonFromTwoSentences [][] = []
uncommonFromTwoSentences [] str2 = bSort (unicWord(words (lowString str2))) -- se a string 1 for vazia
uncommonFromTwoSentences str1 [] = bSort (unicWord(words (lowString str1))) -- se a string 2 for vazia 
uncommonFromTwoSentences str1 str2 = bSort (unicWord ((words (lowString str2)) ++ (words (lowString str1))) )

contaOcorrencias:: String -> [String] -> Int
contaOcorrencias palavra lista = length (filter (== palavra) lista)

unicWord :: [String] -> [String]
unicWord [] = []
unicWord lista = [palavra | palavra <- lista, contaOcorrencias palavra lista == 1] 

main = do
sentence_1 <- getLine
sentence_2 <- getLine
let result = uncommonFromTwoSentences sentence_1 sentence_2
print result
