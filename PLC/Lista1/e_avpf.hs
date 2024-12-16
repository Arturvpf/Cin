{-Problem Statement

Crie a função

type Comando = String
type Valor = Int

executa :: [(Comando, Valor)] -> Int
que recebe uma lista de tuplas com comandos e valores.

A função deve começar pelo valor 0. Por exemplo, caso a sequência de comandos seja

[("Multiplica", 2), ("Soma", 5), ("Subtrai", 3)]
a função deve pegar 0 e efetuar as seguintes operações: (((0 * 2) + 5) - 3).

Esses comandos podem ser "Multiplica", "Soma", "Subtrai" ou "Divide". Para o caso de uma divisão por 0, a função deve retornar o valor -666 independente de quanto tenha calculado até essa divisão.

Utilize a seguinte função main para chamar executa

main = do
    a <- getLine
    let result = executa (read a)
    print result
Input

Lista de tuplas contendo uma String e um Inteiro

Output

Um Inteiro

Examples

Case: 1

Input

[("Multiplica", 2), ("Soma", 5), ("Subtrai", 3)]

Output

2

Case: 2

Input

[("Multiplica", 2), ("Soma", 5), ("Divide", 0)]

Output

-666-}

type Comando = String
type Valor = Int

-- Define a funcao executa
executa :: [(String, Int)] -> Int
executa comandos = processa comandos 0
  where
    processa [] acc = acc
    processa ((cmd, val):xs) acc =
      let accAtualizado = calcula acc (cmd, val)
      in if accAtualizado == -666
            then -666
            else processa xs accAtualizado

    calcula :: Int -> (String, Int) -> Int
    calcula i ("Multiplica", x) = i * x
    calcula i ("Soma", x)       = i + x
    calcula i ("Subtrai", x)    = i - x
    calcula i ("Divide", 0)     = -666
    calcula i ("Divide", x)     = i `div` x
    calcula _ _                 = error "Comando invalido"

-- Define a funcao main
main :: IO ()
main = do
    a <- getLine
    let parsedInput = reads a :: [([(String, Int)], String)]
    let result = case parsedInput of
                    [(comandos, "")] -> executa comandos
                    _ -> -666  
    print result
