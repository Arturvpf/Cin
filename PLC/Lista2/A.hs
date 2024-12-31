import Data.List (elemIndex)
import Data.Maybe (fromJust)

notaParaNumerico :: String -> Float
notaParaNumerico nota = case nota of
    "A+" -> 9.7
    "A"  -> 9.3
    "A-" -> 9.0
    "B+" -> 8.7
    "B"  -> 8.3
    "B-" -> 8.0
    "C+" -> 7.7
    "C"  -> 7.3
    "C-" -> 7.0
    "D+" -> 6.7
    "D"  -> 6.3
    "D-" -> 6.0
    "F"  -> 5.9
    _     -> error "Nota inválida"

numericoParaNota :: Float -> String
numericoParaNota valor
    | valor >= 9.7 = "A+"
    | valor >= 9.3 = "A"
    | valor >= 9.0 = "A-"
    | valor >= 8.7 = "B+"
    | valor >= 8.3 = "B"
    | valor >= 8.0 = "B-"
    | valor >= 7.7 = "C+"
    | valor >= 7.3 = "C"
    | valor >= 7.0 = "C-"
    | valor >= 6.7 = "D+"
    | valor >= 6.3 = "D"
    | valor >= 6.0 = "D-"
    | otherwise    = "F"

ordemNotas :: [String]
ordemNotas = ["A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D+", "D", "D-", "F"]

calcularMedia :: [String] -> Float
calcularMedia notas = sum valores / fromIntegral (length valores)
  where
    valores = map notaParaNumerico notas

contagemNotas :: [String] -> [String] -> Int
contagemNotas notasJeff notasFaculdades = length $ filter (\notaCorte -> compareNotas mediaJeff notaCorte) notasFaculdades
  where
    mediaJeff = numericoParaNota (calcularMedia notasJeff)
    compareNotas nota1 nota2 = fromJust (elemIndex nota1 ordemNotas) <= fromJust (elemIndex nota2 ordemNotas)

main :: IO ()
main = do
    a <- getLine
    b <- getLine
    let notasJeff = read a :: [String]
    let notasFaculdades = read b :: [String]
    print (contagemNotas notasJeff notasFaculdades)
