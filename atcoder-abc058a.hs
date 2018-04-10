main :: IO ()
main = do
    [a,b,c] <- map read . words <$> getLine
    if b - a == c - b then
        putStrLn "YES"
    else
        putStrLn "NO"
