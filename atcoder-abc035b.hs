move :: ((Int, Int), Int)-> Char -> ((Int, Int), Int)
move acc c =
    let
        pos = fst acc
        hatena = snd acc
        x = fst pos
        y = snd pos
    in
    case c of
        'L' -> ((x - 1, y), hatena)
        'R' -> ((x + 1, y), hatena)
        'U' -> ((x, y - 1), hatena)
        'D' -> ((x, y + 1), hatena)
        _ -> ((x, y), hatena + 1)

distance :: (Int, Int) -> Int
distance pos =
    abs (fst pos) + abs (snd pos)

main :: IO ()
main = do
    s <- getLine
    t <- readLn
    let
        acc = foldl move ((0, 0), 0) s
        pos = fst acc
        hatena = snd acc
    if t == 1 then
        print $ (distance pos) + hatena
    else
        print $ distance pos
