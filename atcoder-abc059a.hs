import Data.Char

concatHead :: String -> String -> String
concatHead a b =
    a ++ [toUpper $ head b]

main :: IO ()
main = do
    ss <- words <$> getLine
    putStrLn $ foldl concatHead "" ss
