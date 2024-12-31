data Command = Forward Int | Backward Int | TurnLeft | TurnRight 
               deriving (Eq, Show, Read)

data Direction = North | South | West | East
                 deriving (Eq, Read, Show)

front :: Command -> Bool 
front (Forward _) = True
front _           = False

back :: Command -> Bool 
back (Backward _) = True
back _            = False

faces :: Direction -> [Command] -> Direction
faces dir [] = dir
faces dir (a:as) | dir == North && a == TurnLeft    = faces West as 
                 | dir == North && a == TurnRight   = faces East as 
                 | dir == North && front a         = faces North as
                 | dir == North && back a           = faces North as
                 | dir == South && a == TurnLeft    = faces East as
                 | dir == South && a == TurnRight   = faces West as
                 | dir == South && front a         = faces South as
                 | dir == South && back a           = faces South as
                 | dir == East && a == TurnLeft     = faces North as
                 | dir == East && a == TurnRight    = faces South as
                 | dir == East && front a          = faces East as
                 | dir == East && back a            = faces East as
                 | dir == West && a == TurnLeft     = faces South as
                 | dir == West && a == TurnRight    = faces North as
                 | dir == West && front a          = faces West as
                 | dir == West && back a            = faces West as
                 | otherwise = dir

main = do
       a <- getLine
       b <- getLine
       let result = faces (read a) (read b)
       print result
