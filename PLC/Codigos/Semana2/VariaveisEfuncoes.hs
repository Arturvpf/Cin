{-Números Inteiros

• 1,2,3,...:: Int

• +, *, -, ^, div, mod :: Int -> Int -> Int
• >, >=, ==, /=, <=, < :: Int -> Int -> Bool-

Integer: precisão arbitrária
• Int: precisão fixa (bounded)

Operadores e funções

• +, *, ^, -, div, mod, abs,negate
• Relacionais: >, >=, ==, /=,
<=, <

> 2^3
8
> div 14 3
4
> 14 `div` 3
4
> mod 14 3
2
> 14 `mod` 3
2
}



greater :: Int -> Int -> Bool
greater x y = x > y

square :: Int -> Int
square x = x * x

allEqual :: Int -> Int -> Int -> Bool
allEqual n m p = (n == m) && (m == p)

maxi :: Int -> Int -> Int
maxi n m | n >= m = n
         | otherwise = m

         --Exemplo

--Em um sistema de controle de vendas:
--• suponha vendas semanais dadas pela função
vendas :: Int -> Int
--• total de vendas da semana 0 à semana n?
--vendas 0 + vendas 1 + ... + vendas (n-1) + vendas n
totalVendas :: Int -> Int
totalVendas n| n == 0 = vendas 0
             | otherwise = totalVendas (n-1) + vendas n

             --Recursão

--• Definir caso base, i.e. valor para fun 0
--• Definir o valor para fun n
--usando o valor de fun (n-1)
--Este é o caso recursivo.

maxVendas :: Int -> Int
maxVendas n  | n == 0 = vendas 0
             | otherwise = maxi (maxVendas (n-1))(vendas n)



            -- Casamento de Padrões

--• Permite usar padrões no lugar de variáveis, na
--definição de funções:

maxVendas :: Int -> Int
maxVendas 0 = vendas 0
maxVendas n = maxi (maxVendas (n-1))(vendas n)

totalVendas :: Int -> Int
totalVendas 0 = vendas 0
totalVendas n = totalVendas (n-1) + vendas n

--Regras para Padrões

--• Todos os padrões (esquerda) devem ter tipos
--compatíveis
--– Não necessariamente iguais
--• Os casos devem ser exaustivos
--– não é obrigatório è funções parciais
--Não deve haver ambiguidade
--– ordem dos padrões usada para resolver conflitos

--Notação

--• Maiúsculas:
--– Tipos e Construtores (para tipos algébricos)
--• Minúsculas:
--– Funções, constantes e parâmetros
--• Case sensitive
--• comentários:
--isso é um comentario de uma linha
{- comentario de varias linhas... -}

{-Erros comuns

square x = x
*x
parse error on input '*'

funny x = x +
1
parse error (possibly incorrect indentation)

Funny x = x+1
Not in scope: data constructor `Funny'-}

--Definições Locais

sumSquares :: Int -> Int -> Int

sumSquares x y = sqX + sqY
  where sqX = x * x
  sqY = y * y

sumSquares x y = sq x + sq y
  where sq z = z * z

sumSquares x y = let sqX = x * x
  sqY = y * y
  in sqX + sqY

maxThreeOccurs :: Int -> Int -> Int -> (Int,Int)
  maxThreeOccurs m n p = (mx, eqCount)
  where mx = maxiThree m n p
  
  eqCount = equalCount mx m n p

--• let definições in expressão
--• definições where definições

{-Exercícios

• Defina uma função que, dados dois números
inteiros x e y, determina se esses números
são primos entre si*:-}



-- Função para calcular o MDC (Máximo Divisor Comum) usando o algoritmo de Euclides
mdc :: Int -> Int -> Int
mdc x 0 = abs x  --abs eh o valor absoluto de um numero
mdc x y = mdc y (x `mod` y)

-- Função para verificar se dois números são primos entre si
primosEntreSi :: Int -> Int -> Bool
primosEntreSi x y = mdc x y == 1

-- Exemplos de uso:
-- primosEntreSi 20 21  --> True
-- primosEntreSi 400 30 --> False

{-Exercícios

• Defina uma função que, dado um valor inteiro s e
um número de semanas n, retorna quantas
semanas de 0 a n tiveram vendas iguais a s. Para
resolver esta questão, primeiro construa uma
definição simples para vendas.

• Defina uma função que, dado um número inteiro,
determina se ele é primo ou não.-}

-- Função para contar o número de semanas com vendas iguais a s
semanasComVendas :: Int -> [Int] -> Int
semanasComVendas s vendas = length (filter (== s) vendas)

-- Função principal que recebe o valor s, número de semanas n, e retorna a contagem
contaSemanas :: Int -> Int -> [Int] -> Int
contaSemanas s n vendas = semanasComVendas s (take n vendas)

-- Exemplos de uso:
-- Para vendas registradas [5, 10, 5, 20, 5] e buscando o valor 5 em 3 semanas:
-- contaSemanas 5 3 [5, 10, 5, 20, 5] --> 2 (semanas 1 e 3)


{-Exercícios

• Defina as seguintes funções:
– fatorial
fat :: Int -> Int
– compara se quatro números são iguais
all4Equal :: Int -> Int -> Int -> Int -> Bool
– Defina all4Equal usando allEqual
– retorna quantos parâmetros são iguais
equalCount :: Int -> Int -> Int -> Int-}


-- Função para calcular o fatorial
fat :: Int -> Int
fat 0 = 1
fat n = n * fat (n - 1)

-- Exemplos:
-- fat 5 --> 120
-- fat 0 --> 1

-- Função auxiliar para verificar se todos os elementos de uma lista são iguais
allEqual :: [Int] -> Bool
allEqual []     = True
allEqual (x:xs) = all (== x) xs

-- Redefinindo all4Equal usando allEqual
all4Equal' :: Int -> Int -> Int -> Int -> Bool
all4Equal' a b c d = allEqual [a, b, c, d]

-- Exemplos:
-- all4Equal' 1 1 1 1 --> True
-- all4Equal' 1 2 1 1 --> False
