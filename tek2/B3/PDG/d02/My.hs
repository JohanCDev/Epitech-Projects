module My where
-- Task 1
mySucc :: Int -> Int
mySucc x = x + 1
-- Task 2
myIsNeg :: Int -> Bool
myIsNeg x = x < 0
-- Task 3
myAbs :: Int -> Int
myAbs x | myIsNeg x = x * (-1)
    | otherwise = x
-- Task 4
myMin :: Int -> Int -> Int
myMin x y | x < y = x
    | otherwise = y
-- Task 5
myMax :: Int -> Int -> Int
myMax x y | x > y = x
    | otherwise = y
-- Task 6
myTuple :: a -> b -> (a, b)
myTuple a b = (a, b)
-- Task 7
myTruple :: a -> b -> c -> (a, b, c)
myTruple a b c = (a, b, c)
-- Task 8
myFst :: (a, b) -> a
myFst (a, _) = a
-- Task 9
mySnd :: (a, b) -> b
mySnd (_, b) = b
-- Task 10
mySwap :: (a, b) -> (b, a)
mySwap (a, b) = (b, a)
-- Task 11
myHead :: [a] -> a
myHead (x:_) = x
myHead [] = error "The list is empty"
-- Task 12
myTail :: [a] -> [a]
myTail (_:xs) = xs
myTail [] = error "The list is empty"
-- Task 13
myLength :: [a] -> Int
myLength [] = 0
myLength (_:xs) = 1 + myLength xs
-- Task 14
myNth :: [a] -> Int -> a
myNth [] _ = error "The list is empty"
myNth (x:_) 0 = x 
myNth (x:xs) index | myIsNeg index = error "Your index is negative"
    | index > myLength (x:xs) = error "Your index is too high"
    | otherwise = myNth xs (index - 1)
-- Task 15
myTake :: Int -> [a] -> [a]
myTake _ [] = error "Your list is empty"
myTake 0 _ = []
myTake iterations (x:xs) | iterations < 0 = error "Your index is negative"
    | iterations >= myLength (x:xs) = (x:xs)
    | otherwise = x : myTake (iterations - 1) xs
-- Task 16
myDrop :: Int -> [a] -> [a]
myDrop _ [] = []
myDrop 0 xs = xs
myDrop index (_:xs) | myIsNeg index = error "Your index is negative"
    | otherwise = myDrop (index - 1) xs
-- Task 17
myAppend :: [a] -> [a] -> [a]
myAppend (x: xs) y = x : myAppend xs y
myAppend [] x = x
-- Task 18
myReverse :: [a] -> [a]
myReverse [] = []
myReverse (x:xs) = myAppend (myReverse xs) [x]
-- Task 19
myInit :: [a] -> [a]
myInit [] = error "Your list is empty"
myInit (x:xs) = myReverse (myTail (myReverse (x:xs)))
-- Task 21
myLast :: [a] -> a
myLast [] = error "Your list is empty"
myLast (x:xs) = myHead (myReverse (x:xs))
-- Task 22
myZip :: [a] -> [b] -> [(a , b)]
myZip [] _ = []
myZip _ [] = []
myZip (x:xs) (y:ys) = (x, y) : myZip xs ys
-- Task 22
myUnzip :: [(a, b)] -> ([a], [b])
myUnzip = help [] []
    where
        help :: [a] -> [b] -> [(a,b)] -> ([a], [b])
        help a b [] = (a, b)
        help a b (x:xs) = help (myAppend a [myFst x]) (myAppend b [mySnd x]) xs
-- Task 23
myMap :: (a -> b) -> [a] -> [b]
myMap _ [] = []
myMap f (x:xs) = f x : myMap f xs
-- Task 24
myFilter :: (a -> Bool) -> [a] -> [a]
myFilter _ [] = []
myFilter f (x:xs) | f x = x : myFilter f xs
    | otherwise = myFilter f xs
-- Task 25
myFoldl :: (b -> a -> b) -> b -> [a] -> b
myFoldl _ b [] = b
myFoldl f b (x:xs) = myFoldl f (f b x) xs
-- Task 26
myFoldr :: (a -> b -> b) -> b -> [a] -> b
myFoldr _ b [] = b
myFoldr f b x = myFoldr f (f (myLast x) b) (myInit x)
-- Task 27
myPartition :: (a -> Bool) -> [a] -> ([a], [a])
myPartition _ [] = ([], [])
myPartition f xs = (myFilter f xs, myFilter (myNot f) xs)
-- Task 28
myQuickSort :: (a -> a -> Bool) -> [a] -> [a]
myQuickSort _ [] = []
myQuickSort f (x:xs) = myAppend inf (myAppend [x] sup)
    where
        sort = f x
        inf = myQuickSort f (myFilter (myNot sort) xs)
        sup = myQuickSort f (myFilter sort xs)
-- Helpers
myNot :: (a -> Bool) -> a -> Bool
myNot f a | f a = False
    | otherwise = True