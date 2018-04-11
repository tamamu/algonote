main :: IO ()
main = do
    a <- readLn :: IO Integer
    b <- readLn :: IO Integer
    if a > b then
        putStrLn "GREATER"
    else if a < b then
        putStrLn "LESS"
    else
        putStrLn "EQUAL"
