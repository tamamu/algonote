toBool :: String -> Bool
toBool "H" = True
toBool _ = False

main :: IO ()
main = do
    [a,b] <- map toBool . words <$> getLine
    if a == b then
        putStrLn "H"
    else
        putStrLn "D"
{-    
a b c
H H H
H D D
D H D
D D H
-}
