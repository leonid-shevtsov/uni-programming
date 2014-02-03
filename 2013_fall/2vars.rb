def f(u)
  x=u[0]
  y=u[1]
  x*x+16*y*y
end

def df(u)
  x=u[0]
  y=u[1]
  [ 2*x, 32*y ]
end

def g(u, a)
  gr = df(u)
  (u[0] - gr[0]*a)**2 + (u[1]-gr[0]*a)**2
end

def lm(a,b)
  [(a+b-0.01)/2, (a+b+0.01)/2]
end

def maximum(a,b)
  while (b-a)>0.02
    l, m = lm(a, b)
    fl, fm = yield(l), yield(m)
    if fl > fm
      a = l
    else
      b = m
    end
  end
  return (a+b)/2
end

u = [5.0, 3.0]

3.times do
  u = u - maximum(0, 100)df(u)


end