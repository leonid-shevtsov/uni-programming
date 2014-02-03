naturals 1 = [1]
naturals n = naturals(n-1) ++ [n]

odds 1 = [1]
odds n = odds(n-1) ++ [2*n-1]

evens 1 = [2]
evens n = evens(n-1) ++ [2*n]

cubes 1 = [1]
cubes n = cubes(n-1) ++ [n^3]

factorial 1 = 1
factorial n = factorial(n-1)*n
factorials 1 = [1]
factorials n = factorials(n-1) ++ [factorial n]

tenpowers 1 = [10]
tenpowers n = tenpowers(n-1) ++ [10^n]

trianglenumber 1 = 1
trianglenumber n = trianglenumber(n-1)+n
trianglenumbers 1 = [1]
trianglenumbers n = trianglenumbers(n-1) ++ [trianglenumber n]

invertPositiveNumbers xs = [-abs(x) | x <- xs]

deleteChar char string = filter (/=char) string

main = do
  putStr("Naturals: ")
  print(naturals(5))
  putStr("Odds: ")
  print(odds(5))
  putStr("Evens: ")
  print(evens(5))
  putStr("Cubes: ")
  print(cubes(5))
  putStr("Factorials: ")
  print(factorials(5))
  putStr("Powers of ten: ")
  print(tenpowers(5))
  putStr("Triangle numbers: ")
  print(trianglenumbers(5))
  putStrLn("-------")
  putStr("invertPositiveNumbers of ")
  print([-1, 0, 5, -10, -20])
  putStr("is ")
  print(invertPositiveNumbers([-1, 0, 5, -10, -20]))
  putStrLn("--------")
  putStr("Deleting L from Hello World: ")
  print(deleteChar 'l' "Hello, World")