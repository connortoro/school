import random

# f(x) = 2 - x^2
def func1(x):
  return 2 - abs(x ** 2)

# g(x) = (0.0051x^5) - (0.1367x^4) + (1.24x^3) - (4.456x^2) + (5.66x) - 0.287
def func2(x):
  return (0.0051 * (x ** 5)) - (0.1367 * (x ** 4)) + (1.24 * (x ** 3)) - (4.456 * (x ** 2)) + (5.66 * x) - 0.287

def hill_climb(f, start, step_size):
  x = start
  while(True):
    l =  x - step_size
    r = x + step_size
    if(f(l) > f(x)):
      x = l
    elif(f(r) > f(x)):
      x = r
    else:
      return f(x)
    
def hill_climb_restart(f):
  res = float('-inf')
  for i in range(20):
    x = random.randint(0, int(20)) * .5
    res = max(hill_climb(f, x, .5), res)      
  return res


print(hill_climb(func1, 0, 0.5))
print(hill_climb(func1, 0, 0.01))

print(hill_climb_restart(func2))

