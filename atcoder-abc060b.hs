solve :: Int -> Int -> Int -> Int -> Bool
solve a b c n =
    if n == b then
        False
    else
        a * n `mod` b == c || solve a b c (n + 1)

main :: IO ()
main = do
    [a,b,c] <- map read . words <$> getLine
    if solve a b c 1 then
        putStrLn "YES"
    else
        putStrLn "NO"
