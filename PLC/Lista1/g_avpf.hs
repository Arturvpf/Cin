btoi :: String -> Int
btoi bin = foldl (\acc x -> acc * 2 + read [x]) 0 bin

main :: IO()
main = do
  s <- getLine
  let result = btoi s
  print result

--Correct?---
