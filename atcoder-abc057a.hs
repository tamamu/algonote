main :: IO ()
main = do
    [a,b] <- map read . words <$> getLine
    let c = a + b
    if c >= 24 then
        putStrLn $ show (c - 24)
    else
        putStrLn $ show c
