Exercicios:
sqrList :: [Int] -> [Int]
sqrList lista = map sqr lista 
    where sqr x = x*x

sumSquares :: [Int] -> [Int] 
sumSquares foldr1 (+) 0(sqrList lista)

filterGT :: Int -> [Int] -> [Int]
filterGT n lista = filter (maiorqueN lista)
    where maiorqueN x = x > n

 
 merge :: [Int] -> [Int] -> [Int]
    
merge [] ys = ys
merge xs [] = xs
merge (x:xs) (y:ys) = | x<= y = x : merge lista1 (y:lista2)
                      | x > y = x: merge (x:lista1) lista2

mergesort :: [Int] -> [Int]
mergesort [] = []
mergesort [x] = [x]
mergesort xs = merge (mergesort (take n xs)) (mergesort (drop n xs))
    where n = length xs `div` 2
  
