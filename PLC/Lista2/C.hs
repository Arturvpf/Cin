data Tree t = Nilt | Node t (Tree t) (Tree t) deriving (Read, Show)

height :: Tree t -> Int
height Nilt = 0
height (Node _ left right) = 1 + max (height left) (height right)

diameter :: Tree t -> Int
diameter Nilt = 0
diameter (Node _ left right) = max (max (diameter left) (diameter right)) (height left + height right + 1)

maiorDiametro :: Tree t -> Int
maiorDiametro = diameter

main :: IO ()
main = do
  s <- getLine
  let result = maiorDiametro (read s :: Tree Int)
  print result
