import Control.Monad
main :: IO ()
main = do
    [n,x] <- map read . words <$> getLine
    m <- map read <$> replicateM n getLine
    let
      remain = x - (foldl (+) 0 m)
      am = minimum m
    print ((remain `div` am) + n)
