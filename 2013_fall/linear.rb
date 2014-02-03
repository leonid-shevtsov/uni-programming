def f(x)
  x*x+2*x
end

def lm(a,b)
  [(a+b-0.1)/2, (a+b+0.1)/2]
end

a = -3
b = 5

while (b-a)>0.2
  l, m = lm(a, b)
  fl, fm = f(l), f(m)
  puts "%0.3f %0.3f %0.3f %0.3f %0.3f %0.3f" % [a, b, l, m, fl, fm]
  if fl > fm
    a = l
  else
    b = m
  end
end

u = (a+b)/2
puts u
puts f(u)