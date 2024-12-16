{-Problem Statement

Você está trabalhando como estagiário/a no laboratório MKVI que é especializado no nicho de análise genética. Recentemente o laboratório recebeu uma amostra codificada de genes no formato de uma árvore parcialmente ordenada,nó esquerdo<nó atual< nó direito, (incompleta ou não) e sua tarefa é programar uma máquina para re-codificar numa lista de bases nitrogenadas.

Infelizmente o equipamento apresenta um problema no display e interpreta a base adenina pela letra E, timina pela letra M, guanina pela letra A, citosina pela letra C e quando o mapeamento não pode ser realizado com sucesso para um dos nós a letra S.

As regras para programar a máquina se encontram abaixo:

A árvore deve ser convertida numa lista de listas de inteiros, tal que cada lista não seja maior que 8 e que a conversão respeite o ordenamento parcial.

Dado o valo do nó mod 5 então:

0 -> 'E'

1 -> 'M'

2 -> 'A'

3 -> 'C'

4 -> 'S'

Exiba a lista de listas resultante após a conversão do passo 2.

OBS: Um nó nunca poderá ter mais do que dois filhos, isto é a árvore pode ser no máximo uma árvore binária completa.

Considere o seguinte tipo algébrico

data Tree t = Node t (Tree t) (Tree t) | Nilt
  deriving (Read, Show)
E assinatura

dna1 :: Tree Int -> [String]
OBS2: Sugestão de main

main :: IO ()
main = do

  input <- getLine

  let result = dna1 (read input :: Tree Int)

  print result
Input

Uma árvore de inteiros

Output

Uma lista de palavras, cada palavra pode ter no máximo 8 caracteres.

Examples

Case: 1

Input

Node 384 (Node 260 (Node 14 Nilt (Node 18 Nilt (Node 60 Nilt (Node 63 Nilt (Node 64 Nilt (Node 70 Nilt (Node 199 (Node 81 Nilt (Node 102 Nilt (Node 113 Nilt (Node 117 Nilt (Node 126 Nilt Nilt))))) (Node 207 Nilt (Node 248 (Node 232 Nilt (Node 233 Nilt Nilt)) (Node 252 Nilt Nilt)))))))))) (Node 264 Nilt (Node 291 Nilt (Node 342 Nilt Nilt)))) (Node 897 (Node 896 (Node 516 (Node 512 (Node 414 Nilt (Node 438 Nilt (Node 455 Nilt (Node 460 Nilt (Node 480 Nilt (Node 504 Nilt Nilt)))))) Nilt) (Node 522 Nilt (Node 783 (Node 657 (Node 530 Nilt (Node 558 Nilt (Node 561 Nilt (Node 581 Nilt (Node 616 Nilt Nilt))))) (Node 680 Nilt (Node 685 Nilt (Node 696 Nilt (Node 708 Nilt (Node 714 Nilt (Node 728 Nilt (Node 729 Nilt (Node 735 Nilt (Node 745 Nilt (Node 749 Nilt (Node 752 Nilt Nilt)))))))))))) (Node 785 Nilt (Node 798 Nilt (Node 804 Nilt (Node 805 Nilt (Node 812 Nilt (Node 826 Nilt (Node 837 Nilt (Node 880 Nilt (Node 890 Nilt Nilt)))))))))))) Nilt) (Node 898 Nilt (Node 966 Nilt (Node 978 Nilt Nilt))))

Output

["SCECSEMA","CAMSAACC","AESMASSC","EEESAMAE","CMMMAEEM","CSCSEESA","CECSEAMA","EEMACMC"]

Case: 2

Input

Node 960 (Node 228 (Node 102 Nilt (Node 222 Nilt Nilt)) (Node 456 (Node 244 Nilt Nilt) (Node 784 Nilt (Node 920 (Node 861 Nilt Nilt) (Node 952 Nilt Nilt))))) Nilt

Output

["AACSMSME","AE"]

Case: 3

Input

Node 432 (Node 5 Nilt (Node 378 Nilt Nilt)) (Node 698 Nilt Nilt)

Output

["ECAC"]

Case: 4

Input

Node 296 (Node 230 Nilt Nilt) Nilt

Output

["EM"]-}

-- recebe um vetor de arvores, entao tem que transformar essas arvores realmente em um vetor
-- criar funcao que tira o mod dos nos transformando em letra e colocando tudo em um vetor de strings, cada string correspondendo a um elemento do vetor de arvores

-- recebe as arvores
-- tira o mod dos elementos
-- divide a string resultante a cada 8 letras

data Tree t = Node t (Tree t) (Tree t) | Nilt
  deriving (Read, Show)

dna1 :: Tree Int -> [String]
dna1 Nilt = []
dna1 arvore = dividirStr (transformarEmLetras arvore)

transformarEmLetras :: Tree Int -> String
transformarEmLetras Nilt = []   
transformarEmLetras (Node atual esq dir) | atual `mod` 5 == 0 = transformarEmLetras esq ++ "E" ++ transformarEmLetras dir
                                         | atual `mod` 5 == 1 = transformarEmLetras esq ++ "M" ++ transformarEmLetras dir
                                         | atual `mod` 5 == 2 = transformarEmLetras esq ++ "A" ++ transformarEmLetras dir
                                         | atual `mod` 5 == 3 = transformarEmLetras esq ++ "C" ++ transformarEmLetras dir
                                         | atual `mod` 5 == 4 = transformarEmLetras esq ++ "S" ++ transformarEmLetras dir
-- Node 432 (Node 5 Nilt (Node 378 Nilt Nilt)) (Node 698 Nilt Nilt)
{-    
       432 -- ele ta fazendo -> esquerda, direita, atual 
     /   \
    5    698
   / \    / \
 Nilt 378 Nilt Nilt
AECC 
-}
dividirStr :: String -> [String]
dividirStr []  = []
dividirStr str = take 8 str : dividirStr (drop 8 str) 
--Utiliza take 8 str para pegar os primeiros 8 caracteres da string e drop 8 str para remover os primeiros 8 caracteres, repetindo o processo recursivamente até que a string esteja vazia.

main :: IO ()
main = do
  input <- getLine
  let arvore = read input :: Tree Int
  let result = dna1 arvore
  print result
