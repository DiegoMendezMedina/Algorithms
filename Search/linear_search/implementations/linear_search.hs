-- | linear_search: Searchs on a non ordered list.
linear_search :: (Eq a) => [a] -> a ->  Maybe Integer
linear_search [] _ =  Nothing
linear_search (x:xs) r
     | x == r =  Just 1
     | otherwise = fmap(+1)(linear_search xs r)
