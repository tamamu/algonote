factorial :: Int -> Int
factorial 1 = 1
factorial n = n + factorial (n - 1)

rInt :: String -> Int
rInt str = read str :: Int

main :: IO ()
main = do
    n <- rInt <$> getLine
    putStrLn $ show $ factorial n
