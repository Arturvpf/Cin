{-Problem Statement

Considere os seguintes tipos:

data Command = Forward Int | Backward Int | TurnLeft | TurnRight 
               deriving (Eq, Show, Read)

data Direction = North | South | West | East
                 deriving (Read, Show)
Faça a função

faces :: Direction -> [Command] -> Direction
que recebe a direção inicial do robô e uma lista de comandos e retorna para qual direção o robô estará voltado depois de executar essa lista de comandos.

O robô é controlado por 4 comandos:

Left, para girar sua direção em 90 graus no sentido anti-horário.

Right, para girar sua direção em 90 graus no sentido horário.

Forward seguido de um número N, que indica um avanço de N metros.

Backward seguido de um número N, que indica um retrocesso de N metros.

Utilize a seguinte função main para chamar faces:

main = do
       a <- getLine
       b <- getLine
       let result = faces (read a) (read b)
       print result
Input

Um Direction e uma lista de Comands, um em cada linha

Output

Um Direction

Examples

Case: 1

Input

North
[Forward 2, TurnLeft, TurnLeft, Forward 1]

Output

South-}

data Command = Forward Int | Backward Int | TurnLeft | TurnRight 
               deriving (Eq, Show, Read)

data Direction = North | South | West | East
                 deriving (Eq, Read, Show)

frente :: Command -> Bool -- func auxiliar pra identificar se ta indo pra frente
frente (Forward _) = True
frente _           = False

tras :: Command -> Bool -- func auxiliar pra identificar se ta indo pra tras
tras (Backward _) = True
tras _            = False

faces :: Direction -> [Command] -> Direction
faces dir [] = dir
faces dir (a:as) | dir == North && a == TurnLeft    = faces West as 
                 | dir == North && a == TurnRight   = faces East as 
                 | dir == North && frente a         = faces North as
                 | dir == North && tras a           = faces North as
                 | dir == South && a == TurnLeft    = faces East as
                 | dir == South && a == TurnRight   = faces West as
                 | dir == South && frente a         = faces South as
                 | dir == South && tras a           = faces South as
                 | dir == East && a == TurnLeft     = faces North as
                 | dir == East && a == TurnRight    = faces South as
                 | dir == East && frente a          = faces East as
                 | dir == East && tras a            = faces East as
                 | dir == West && a == TurnLeft     = faces South as
                 | dir == West && a == TurnRight    = faces North as
                 | dir == West && frente a          = faces West as
                 | dir == West && tras a            = faces West as
                 | otherwise = dir

main = do
       a <- getLine
       b <- getLine
       let result = faces (read a) (read b)
       print result

-- se tiver olhando para norte e receber left olha pro oeste
-- se tiver olhando para norte e receber right olha pro leste
-- se tiver olhando para norte e receber forward continua olhando pra norte
-- se tiver olhando para norte e receber backward olha pro sul

-- se tiver olhando para o sul e receber left olha pro leste
-- se tiver olhando para o sul e receber right olha pro oeste
-- se tiver olhando para o sul e receber forward olha pro sul
-- se tiver olhando para o sul e receber backward olha pro norte

-- se tiver olhando para o leste e receber left olha pro norte
-- se tiver olhando para o leste e receber right olha pro sul
-- se tiver olhando para o leste e receber forward olha pro leste
-- se tiver olhando para o leste e receber backward olha pro oeste

-- se tiver olhando para o oeste e receber left olha pro sul
-- se tiver olhando para o oeste e receber right olha pro norte
-- se tiver olhando para o oeste e receber forward olha pro oeste
-- se tiver olhando para o oeste e receber backward olha pro leste
