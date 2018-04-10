commaToSpace :: Char -> Char
commaToSpace a =
    if a == ',' then
        ' '
    else
        a

main :: IO ()
main = do
    s <- getLine
    putStrLn $ map commaToSpace s
