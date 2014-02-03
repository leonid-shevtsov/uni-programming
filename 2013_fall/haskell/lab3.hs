list = [1,2,3,4,5]
list2 = [1, -1, 2, -3, 5]

geometricAverage(xs) = product(xs) ** (1/fromIntegral(length(xs))) :: Float
scalarProduct(xs, ys) = sum(zipWith (*) xs ys) :: Float
countNegat(xs) = length( filter (\x -> x<0)  xs) :: Int

-- Не будет работать при повторяющихся элементах
quickSort [] = []
quickSort(a:xs) =
  quickSort( filter (\x -> x<a) xs ) ++
  [a] ++
  quickSort( filter (\x -> x>a) xs) :: [Float]

quickSort2 f [] = []
quickSort2 f  (a:xs) =
  quickSort2(f)(filter (\x -> f x a) xs ) ++
  [a] ++
  quickSort2(f)(filter (\x -> f a x) xs) :: [Float]

main = do
  print(geometricAverage(list))
  print(scalarProduct(list, list2))
  print(countNegat(list2))
  print(quickSort(list2))
  print(quickSort2(\x y -> x<y)(list2))
