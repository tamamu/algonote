rInt :: String -> Int
rInt str = read str :: Int

main :: IO ()
main = do
    [a,b,c,d] <- map rInt . words <$> getLine
    let ab = a * b
    let cd = c * d
    if ab > cd then
        putStrLn $ show ab
    else if ab < cd then
        putStrLn $ show cd
    else
        putStrLn $ show ab
