vendas :: Int -> Int
vendas 0 = 550
vendas 1 = 99
vendas 2 = 130
vendas 3 = 600
vendas 4 = 700
vendas 5 = 800
vendas n = 0

-- vendas n | n == 0 = 550
--          | n == 1 = 99


totalVendas :: Int -> Int
totalVendas 0 = vendas 0
totalVendas n = totalVendas (n-1) + vendas n

maxVendas :: Int -> Int
maxVendas 0 = vendas 0
maxVendas n = max (vendas n) (maxVendas (n-1))

square :: Int -> Int
square x = x * x

allEqual :: Int -> Int -> Int -> Bool
allEqual m n p = (m == n) && (n == p)



maxi :: Int -> Int -> Int
maxi n m | n >= m = n
         | otherwise = m

paraDireita :: Int -> String -> String
paraDireita n str = addEspacos n ++ str

addEspacos :: Int -> String
addEspacos 0 = ""
addEspacos n = " " ++ addEspacos (n-1)

cabecalho :: String
cabecalho = "Semana venda\n"

imprimeTotal :: Int -> String
imprimeTotal n = "Total " ++ show (totalVendas n ) ++ "\n"

imprimeMedia :: Int -> String
imprimeMedia n = "Media " ++ show (fromIntegral (totalVendas n) / fromIntegral (n+1)) ++ "\n"

--imprimeSemana :: Int -> String
--imprimeSemana 0 = show 0 ++ " " ++ show (vendas 0)
--imprimeSemana n = show n ++ " " ++ show (vendas n)


imprimeSemanas :: Int -> String
imprimeSemanas 0 = paraDireita 3 (show 0) ++ " " ++ paraDireita 5 (show (vendas 0)) ++ "\n"
imprimeSemanas n = imprimeSemanas(n-1) ++paraDireita 3 (show n) ++ paraDireita 5 (show(vendas n)) ++ "\n"

imprimeTabela :: Int -> IO()
imprimeTabela n = putStr(cabecalho 
                    ++ imprimeSemanas n 
                    ++ imprimeTotal n 
                    ++ imprimeMedia n
                    )           







    