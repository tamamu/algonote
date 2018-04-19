countLetters :: String -> Char -> Int
countLetters str c = length $ filter (== c) str

main :: IO ()
main = do
    s <- getLine
    let
        north = countLetters s 'N'
        west = countLetters s 'W'
        south = countLetters s 'S'
        east = countLetters s 'E'
        a = if north > 0 then south > 0 else True
        b = if west > 0 then east > 0 else True
        c = if south > 0 then north > 0 else True
        d = if east > 0 then west > 0 else True
    putStrLn $ if a && b && c && d then
        "Yes"
        else
        "No"
