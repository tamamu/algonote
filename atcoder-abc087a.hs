import Control.Monad

rInt :: String -> Int
rInt str = read str :: Int

main :: IO ()
main = do
    [x,a,b] <- map rInt <$> replicateM 3 getLine
    putStrLn $ show $ (x - a) `mod` b
