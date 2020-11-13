

linear_search :: (Eq a) => [a] -> a -> String
linear_search [] _ =  "N"
linear_search (x:xs) r
     | x == r = "Si"
     | otherwise = linear_search xs r