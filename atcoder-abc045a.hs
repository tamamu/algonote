import Control.Monad

calc :: Int -> Int -> Int -> Int
calc a b h = (a + b) * h `div` 2

main :: IO ()
main = do
    [a,b,h] <- replicateM 3 readLn
    putStrLn $ show $ calc a b h
