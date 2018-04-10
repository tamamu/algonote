import Control.Monad

calc :: Int -> Int -> Int -> Int -> Int
calc n k x y =
    let z = n - k in
    if z > 0 then
        k * x + z * y
    else
        n * x

main :: IO ()
main = do
    [n,k,x,y] <- replicateM 4 readLn
    putStrLn $ show $ calc n k x y
