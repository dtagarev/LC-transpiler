globVar1 = 3;

function f(n, m, l)
	return 3
end

function g(n,m,l)
	if n == m then
		return n + l
	elseif m == l then
		return m + l
	else
		return n + l + m
	end
end

local a = 2;
local c = 5;

print(g(globVar1, a, c))
