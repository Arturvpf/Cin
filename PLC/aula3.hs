double :: [Int] -> [Int]
double [] = []
double (x:xs) = (2*x) : double (xs)

member ::[Int] -> Int -> Bool
member [] numero = False
member (y:ys) numero | y== numero = True
                     | y/= numero = member ys numero

memberCh :: [Char] -> Char -> Bool
memberCh [] chr= False
memberCh (y:ys) chr | y == chr= True
                    | y /= chr = memberCh ys chr

digits :: String -> String
digits [] = []
digits (ch:chs) | memberCh "0123456789" ch = ch :digits chs
                | otherwise = digits chs

sumPairs :: [(Int,Int)] -> [Int]
sumPairs [] = []
sumPairs ((x,y) : ps) = (x+y) :sumPairs ps