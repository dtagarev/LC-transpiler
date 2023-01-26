function fact (n)
  if n == 0 then
    return 1
  else
    return n * fact(n-1.5)
  end
end


local a = 1
local b = a*2
print(fact(b + 3))
