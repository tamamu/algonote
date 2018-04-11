import Control.Monad

main :: IO ()
main = do
    [n,m] <- map read . words <$> getLine
    ss <- map (map read . words) <$> replicateM m getLine
    let result = solve ss n
    forM_ result $ putStrLn . show

solve :: [[Int]] -> Int -> [Int]
solve e n = map (counter e) [1..n]

counter :: [[Int]] -> Int -> Int
counter e s =
    foldl (+) 0 $ map (length . filter (\x -> x == s)) e
