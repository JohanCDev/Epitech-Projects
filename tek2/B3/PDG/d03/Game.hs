module Game where
import Data.Maybe
data Item = Sword | Bow | MagicWand
    deriving (Eq)

data Mob = Mummy | Skeleton Item | Witch (Maybe Item)
    deriving (Eq)

class HasItem object where
    getItem :: object -> Maybe Item
    hasItem :: object -> Bool
    hasItem object = isJust (getItem object)

instance Show Item where
    show Sword = "sword"
    show Bow = "bow"
    show MagicWand = "magic wand"

createMummy :: Mob
createMummy = Mummy

createArcher :: Mob
createArcher = Skeleton Bow

createKnight :: Mob
createKnight = Skeleton Sword

createWitch :: Mob
createWitch = Witch Nothing

createSorceress :: Mob
createSorceress = Witch (Just MagicWand)

create :: String -> Maybe Mob
create "mummy" = Just createMummy
create "doomed archer" = Just createArcher
create "dead knight" = Just createKnight
create "witch" = Just createWitch
create "sorceress" = Just createSorceress
create _ = Nothing

equip :: Item -> Mob -> Maybe Mob
equip _ Mummy = Nothing
equip item (Witch itemWi) = Just (Witch (Just item))
equip item (Skeleton itemSk) = Just (Skeleton item)

instance Show Mob where
    show Mummy = "mummy"
    show (Skeleton Bow) = "doomed archer"
    show (Skeleton Sword) = "dead knight"
    show (Skeleton item) = "skeleton holding a " ++ show item
    show (Witch Nothing) = "witch"
    show (Witch (Just MagicWand)) = "sorceress"
    show (Witch (Just item)) = "witch holding a " ++ show item

instance HasItem Mob where
    getItem (Skeleton itemSk) = Just itemSk
    getItem (Witch itemWi) = itemWi
    getItem _ = Nothing
    hasItem (Skeleton itemSk) = True
    hasItem (Witch itemWi) = isJust itemWi
    hasItem _ = False
