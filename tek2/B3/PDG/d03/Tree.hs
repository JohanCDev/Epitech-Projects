module Tree where
data Tree a = Empty | Node (Tree a) a (Tree a)
    deriving (Show)

addInTree :: Ord a => a -> Tree a -> Tree a
addInTree x Empty = Node Empty x Empty
addInTree x (Node tr1 v tr2) | v > x = Node (addInTree x tr1) v tr2
    | otherwise = Node tr1 v (addInTree x tr2)

instance Functor Tree where
    fmap _ Empty = Empty
    fmap f (Node l v r) = Node (fmap f l) (f v) (fmap f r)

listToTree :: Ord a => [a] -> Tree a
listToTree = foldr addInTree Empty

treeToList :: Ord a => Tree a -> [a]
treeToList Empty = []
treeToList (Node l v r) = treeToList l ++ [v] ++ treeToList r

treeSort :: Ord a => [a] -> [a]
treeSort xs = treeToList (listToTree xs)

instance Foldable Tree where
    foldr _ v Empty = v
    foldr f baseV (Node l val r) = foldr f (f val (foldr f baseV r)) l