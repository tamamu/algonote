fn :: Bool -> (String, String) -> Bool
fn f pair =
    f && last (fst pair) == head (snd pair)

main :: IO ()
main = do
    abc <- words <$> getLine
    let pairs = zip (init abc) (tail abc)
    if foldl fn True pairs then
        putStrLn "YES"
    else
        putStrLn "NO"
