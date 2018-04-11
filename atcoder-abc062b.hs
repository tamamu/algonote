import Control.Monad

main :: IO ()
main = do
    [h,w] <- map read . words <$> getLine
    s <- replicateM h getLine
    putStrLn $ replicate (w + 2) '#'
    forM_ s $ \t -> do
        putStrLn $ ['#'] ++ t ++ ['#']
    putStrLn $ replicate (w + 2) '#'
