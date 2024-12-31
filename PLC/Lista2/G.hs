data Ops = SUM | MUL | SUB
           deriving (Read, Eq)

data IntTree = Nilt Int |
               Node Ops IntTree IntTree
               deriving (Read)

evalTree :: IntTree -> Int
evalTree (Nilt x) = x 
evalTree (Node operation esq dir) | operation == SUM = (evalTree esq) + (evalTree dir)
                                 | operation == MUL = (evalTree esq) * (evalTree dir)
                                 | operation == SUB = (evalTree esq) - (evalTree dir)

main = do
    s <- getLine
    let result = evalTree (read s)
    print result
