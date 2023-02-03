globVar1 = 3;

local function f(n, m, l)
	return 3
end

function g(n,m,l)
	local var = 5;
	if n == m then
		return n + l
	elseif m == l then
		return m + l
	elseif m == 3 then
		return 3
	elseif l == 100 then
		return 100
	end
	
	while var == 8 do
		var = var + 1;
		break;
	end

	return var
end

local a = 2;
local c = 5;

print(g(globVar1, a, c))
