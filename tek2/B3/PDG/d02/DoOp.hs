-- module DoOp where
import My
import Data.Char
import Control.Monad.State
import System.Directory.Internal.Prelude
import Data.Maybe
import Distribution.Simple.Utils (xargs)
import System.Exit (exitWith, ExitCode (ExitFailure))

myElem :: Eq a => a -> [a] -> Bool
myElem _ [] = False
myElem n xs | n == head xs = True
    | otherwise = myElem n (tail xs)

safeDiv :: Int -> Int -> Maybe Int
safeDiv x 0  = Nothing
safeDiv x y = Just (x `div` y)

safeNth :: [a] -> Int -> Maybe a
safeNth [] _ = Nothing
safeNth (x:xs) 0 = Just x
safeNth (x:xs) y
    | myIsNeg y = Nothing
    | y > length (x:xs) = Nothing
    | otherwise = safeNth xs (y - 1)

safeSucc :: Maybe Int -> Maybe Int
safeSucc Nothing = Nothing
safeSucc x = fmap succ x

myLookup :: Eq a => a -> [(a,b)] -> Maybe b
myLookup _ [] = Nothing
myLookup search (x:xs)
    | search == fst x = Just (snd x)
    | otherwise = myLookup search xs

maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo _ _ Nothing = Nothing
maybeDo _ Nothing _ = Nothing
maybeDo f x y = Just f <*> x <*> y

myIsDigit :: Char -> Bool
myIsDigit c = myElem c ['-','0','1','2','3','4','5','6','7','8','9']

readNegativeInt :: [Char] -> Maybe Int
readNegativeInt [] = Nothing
readNegativeInt (x:xs) | length (x:xs) == 1 = Nothing
    | not (all isDigit xs) = Nothing
    | otherwise = Just (read (x:xs) :: Int)

readInt :: [Char] -> Maybe Int
readInt [] = Nothing
readInt xs | head xs == '-' = readNegativeInt xs
    | not (all isDigit xs) = Nothing
    | otherwise = Just (read xs :: Int)

-- STEP 02 --

getLineLength :: IO Int
getLineLength = fmap length getLine

printAndGetLength :: String -> IO Int
printAndGetLength str = putStrLn str >> return (length str)

-- TASK 10 --

--Get char to print into List
buildLine :: Int -> [Char]
buildLine 1 = ['+']
buildLine 2 = ['-']
buildLine 3 = ['|']
buildLine _ = [' ']

--Get char to print into char
getCar :: Int -> Char
getCar 1 = '+'
getCar 2 = '-'
getCar 3 = '|'
getCar _ = ' '

makeLine :: Int -> Int -> [Char]
makeLine 0 _ = []
makeLine l s = buildLine s ++ replicate l (getCar (s+1)) ++ buildLine s

-- Print all the line    
printLine :: Int -> Int -> IO ()
printLine l s = putStrLn (makeLine (l*2-2) s)

-- Print the type of line needed
getLineToPrint :: Int -> Int -> IO ()
getLineToPrint x l = if x == 1 || x == l then printLine l 1 else printLine l 3

-- Print all the square
printAllLines :: Int -> Int -> IO ()
printAllLines _ 0 = return ()
printAllLines l n = getLineToPrint n l >> printAllLines l (n-1)

printBox :: Int -> IO ()
printBox 1 = putStrLn "++"
printBox x | myIsNeg x = return ()
    | otherwise = printAllLines x x

-- End Task 10

concatLines :: Int -> IO String
concatLines iterations = concat <$> replicateM iterations getLine

getInt :: IO (Maybe Int)
getInt = readInt <$> getLine

-- DOOP

printResult :: Maybe Int -> IO ()
printResult = print

getReturnResult :: Maybe Int -> Int
getReturnResult x | isNothing x = 84
    | otherwise = 0

applyFunc :: [Char] -> Int -> Int -> Maybe Int
applyFunc "*" x y = Just (x * y)
applyFunc "-" x y = Just (x - y)
applyFunc "+" x y = Just (x + y)
applyFunc "/" x y = safeDiv x y
applyFunc "%" x y = Just (x `mod` y)
applyFunc _ _ _ = Nothing

checkNbArgs :: [String] -> Bool
checkNbArgs xs = length xs == 3

checkValidSingleArg :: [String] -> Int -> Bool
checkValidSingleArg xs y = case readInt(xs!!y) of
    Just x -> True
    Nothing -> False

checkValidAllArg :: [String] -> Bool
checkValidAllArg xs = checkValidSingleArg xs 0 && checkValidSingleArg xs 2

main :: IO Int
main = do
    args <- getArgs
    let ver = checkNbArgs args && checkValidAllArg args
    let m = if ver 
        then applyFunc (args!!1) (read (head args)) (read (args!!2)) 
        else Nothing
    case m of
        Just m -> print m >> return 0
        Nothing -> exitWith (ExitFailure 84)
