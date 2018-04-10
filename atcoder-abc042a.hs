count p  = length . filter p

rInt :: String -> Int
rInt str = read str :: Int

main :: IO ()
main = do
    s <- map read . words <$> getLine
    let five = count (\ x -> x == 5) s
    let seven = count (\ x -> x == 7) s
    if five == 2 && seven == 1 then
        putStrLn "YES"
    else
        putStrLn "NO"
