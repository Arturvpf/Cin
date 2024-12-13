import Data.Char (digitToInt)

isReplica :: String -> Int -> Char -> Bool
isReplica str x ch = str == replicate x ch

main :: IO()
main = do
  a <- getLine
  b <- getLine
  c <- getChar
  let result = isReplica a (read b) c
  print result

  --Correct but take a look-----
