import Data.List

main :: IO ()
main = do
    _ <- getLine
    l <- map read . words <$> getLine
    print $ sum $ zipWith (*) (cycle [0,1]) $ reverse $ sort l
