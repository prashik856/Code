class vector2d:
 def __init__(self,x,y):
  self.x=x
  self.y=y
 def __add__(self,other):
  return vector2d(self.x + other.x, self.y + other.y)

first=vector2d(132,214)
second=vector2d(432,123)
result=first+second
print(result.x)
print(result.y)
