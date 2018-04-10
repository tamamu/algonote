import Data.List

rInt :: String -> Int
rInt str = read str :: Int

main :: IO ()
main = do
    abc <- map rInt . words <$> getLine
    putStrLn $ show $ length $ nub abc
