module SelectionSort where

import Data.List

-- | Finds and returns the smallest element on the received list.
smallest :: (Ord a) => [a] -> a
smallest (x:[]) = x
smallest (x:y:xs)
  | x <= y = smallest (x:xs)
  | otherwise = smallest (y:xs)

-- | Sorts the list by finding the smallest element on it.
selection_sort :: (Ord a) => [a] -> [a]
selection_sort (x:[]) = x:[]
selection_sort (x:xs) = a : selection_sort (remove a (x:xs))
  where a = smallest (x:xs)

-- | Returns the same list without the element received. Doesn't removes
--   repetitions.
remove :: (Eq a) => a -> [a] -> [a]
remove _ [] = []
remove a (x:xs)
  | a == x = xs
  | otherwise = x : remove a xs
