
--[[
print("Hello World.")
--]]



--[[
function factorial(n)
    if n <= 1 then
        return 1
    else
        return n * factorial(n - 1)
    end
end
print("Please input a number:")
-- How to use read? *n ?
n = io.read("*n")       -- reads a number
print(factorial(n))
--]]



--[[
function norm(x, y)
    return (x^2 + y^2)^0.5
end

function twice(x)
    return 2*x
end

print(arg[0])
--]]



--[=[
s1 = "one string"
s2 = string.gsub(s1, "one", "another")
print(s1); print(#s1)
print(s2); print(#s2)

print("one line\nnext line\n\"in quotes\", 'in quotes'")
print('a backslash inside quotes: \'\\\'')
print("a simple way: '\\'")
print('alo\n123"')
print('\97lo\10\04923"')
print("\x61\x6c\x6f\x0a\x31\x32\x33\x22")

page = [[
<html>
<head>
    <title> An Html Page</title>
</head>
<body>
    <a href="http://www.lua.org">Lua</a>
</body>
</html>
]]

io.write(page)
--]=]



--[[
line = io.read()
n = tonumber(line)
if n == nil then
    error(line .. " is not a number.")
else
    print(2*n)
end

print(tostring(10) == "10")
print(10 .. "" == "10")
--]]


--[[
a = {}
for i=1,1000 do
    a[i] = 2 * i
end
print(a[9])
a["x"] = 10
print(a["x"])
print(a["y"])
print(a.x)
a.y = 20
print(a.y)
print(a["y"])
--]]



--[[
days = {"Sun","Mon", "Tue", "Wed", "Thu", "Fri", "Sat"}
print(days[1])
print(days[4])
color ={red=0, yellow=1, green=2}
print(color.red)
print(color.yellow)
print(color.green)

polyline = {color="blue",
            thickness=2,
            npoints=4,
            {x=0, y=0},         -- polyline[1]
            {x=-10, y=0},       -- polyline[2]
            {x=-10, y=1},       -- polyline[3]
            {x=0, y=1},         -- polyline[4]
}

print("polyline 2x:", polyline[2].x)
print("polyline 2y:", polyline[2].y)
print("color", polyline.color)

opnames = {["+"]="Add", ["-"]="Sub", ["*"]="Mul", ["/"]="Div"}

i = 20; s = "-"
a = {[i+0]=s, [i+1]=s .. s, [i+2]=s .. s .. s}
print(a[22])
print(opnames[s])
--]]



--[[
function polynomial1(a, x)
    sum = 0
    for i = 1, #a do
        sum = sum + a[i] * (x ^ (i - 1))
    end
    return sum
end

function polynomial2(a, x)
    sum = 0
    for i = 1, #a do
        sum = sum * x + a[#a - i + 1]
    end
    return sum
end

function isboolean(value)
    return value == true or value == false or false
end
--]]




--[[
a, b, c = 1, 2
d, e, f = 4, 5, 6, 7
print(a,b,c,d,e,f)
--]]



--[[
if true then
    x = 10
end
print(x)
--]]



--[[
days = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"}
revDays = {}
for k, v in pairs(days) do
    revDays[v] = k
end
print(revDays["Tue"])
--]]



--[[
function f(a, b)
    print(a, b)
end

f(3); f(3, 4); f(3, 4, 5)
--]]



--[[
function unpack(t, i, n)
    i = i or 1
    n = n or #t

    if i <= n then
        return t[i], unpack(t, i + 1, n)
    end
end

print(unpack({1,2,3,4}))

function Add(...)
    local sum = 0
    for i, v in ipairs{...} do
        sum = sum + v
    end
    return sum
end

print(Add(3, 4, 10,25, 12))

function fwrite(format, ...)
    return io.write(string.format(format, ...))
end

--fwrite()
fwrite("a\n")
fwrite("%d%d\n", 4, 5)

function nonils(...)
    local arg = table.pack(...)
    for i = 1, arg.n do
        if arg[i] == nil then return false end
    end

    return true
end

print(nonils(2, 3, nil))
print(nonils(2, 3))
print(nonils())
print(nonils(nil))

function rename(arg)
    return os.rename(arg.old, arg.new)
end

rename{old="1", new="2"}

function cat(...)
    local str = ""
    local arg = {...}
    for i = 1, #arg do
        str = str .. arg[i]
    end
    return str
end

print(cat())
print(cat("a"))
print(cat("a", "b"))
print(cat("a", "b", "c"))
print("---")

function print_array(args)
    print(table.unpack(args))
end

print_array({})
print_array({1})
print_array({1, 2, 3})
print_array({1, 2, nil, 4})
--]]



--[[
function derivative(f, delta)
    delta = delta or 1e-4
    return
        function (x)
            return (f(x + delta) - f(x)) / delta
        end
end

f = derivative(math.sin)
print(math.cos(5.2), f(5.2))

function sortgrade(names, grades)
    return table.sort(names, function (n1, n2) return grades[n1] < grades[n2] end)
end

names = {"Peter", "Paul", "Mary"}
grades = {Mary = 10, Paul = 7, Peter = 8}

sortgrade(names, grades)
print(table.unpack(names))

function newCounter()
    local i = 0
    f = function () i = i + 1; return i end
    return f
end

c1 = newCounter()
print(c1(), c1(), c1())

do
    local oldSin = math.sin
    local k = math.pi / 180
    math.sin = function (x) return oldSin(k * x) end
end

print(math.sin(90), math.sin(0))
--]]



--[[
function value(t)
    local i = 0
    return function () i = i + 1; return t[i] end
end

t = {10, 20, 30}
iter = value(t)
while true do
    local elem = iter()
    if elem == nil then
        break
    else
        print(elem)
    end
end

for elem in value(t) do
    print(elem)
end
--]]



--[[
function allwords()
    local line = io.read()
    local pos = 1
    return function ()
        while line ~= nil do
            local s, e = string.find(line, "%w+", pos)
            if s == nil then
                line = io.read()
                pos = 1
            else
                pos = e + 1
                return string.sub(line, s, e)
            end
        end

        return nil
    end
end

for word in allwords() do
    print(word)
end
--]]



--[[
local function iter(a, i)
    i = i + 1
    local v = a[i]
    if v then
        return i, v
    end
end

function myipairs(a)
    return iter, a, 0
end

a = {3, 6, 9, 12}
for i, v in myipairs(a) do
    print(i, v)
end
--]]



--[[
local function iter(t, i)
    if i < t[1] then
        return i + t[2]
    end
end

function fromto(n, m, s)
    return iter, {m, s}, n - s
end

for i in fromto(1, 5, 2) do
    print(i)
end
print("---")
for i=1, 5, 2 do
    print(i)
end
--]]



--[[
i = 32
local i = 0
f = load("i = i + 1; print(i)")
g = function () i = i + 1; print(i) end

f()
g()
--]]


--[[ Basic coroutine function
co = coroutine.create(function () print("hi") end)
print(co, coroutine.status(co))
coroutine.resume(co)
print(coroutine.status(co))
--]]



--[[ Basic yield
co = coroutine.create(function ()
        for i = 1, 10 do
            print("co", i)
            coroutine.yield()
        end
    end)

for i = 1, 12 do
coroutine.resume(co)
print(coroutine.status(co))
end
--]]


--[[
-- 1.
co = coroutine.create(function (a, b, c)
        print(a, b, c + 2)
    end)

coroutine.resume(co, 1, 2, 3)

-- 2.
co = coroutine.create(function (a, b)
        coroutine.yield(a + b, a - b)
    end)
print(coroutine.resume(co, 20, 10))


co = coroutine.create(function (x)
        print("co1", x)
        print("co2", coroutine.yield())
    end)

coroutine.resume(co, 1)
coroutine.resume(co, 4, 5)

-- 3.
co = coroutine.create(function ()
        return 6, 7
    end)

print(coroutine.resume(co))
--]]



--[[
--producer/consumer
function send(x)
    coroutine.yield(x)
end

function receive(producer)
    local ok, x = coroutine.resume(producer)
    if ok then return x end
end

producer = coroutine.create(function ()
            while true do
                local x = io.read()
                print("producer:", x)
                if x then
                    send(x)
                else
                    break
                end
            end
        end)

function consumer()
    while true do
        local x = receive(producer)
        print("consumer:", x)
        if not x then break end
    end
end

consumer()
--]]



--[[
function receive(producer)
    local ok, x = coroutine.resume(producer)
    return x
end

function send(x)
    coroutine.yield(x)
end

function producer()
    producer = coroutine.create(function ()
                while true do
                    local x = io.read()
                    send(x)
                end
            end)
    return producer
end

function filter(producer)
    filter = coroutine.create(function ()
                for i = 1, math.huge do
                    local x = receive(producer)
                    x = string.format("%5d %s", i, x)
                    send(x)
                end
            end)
    return filter
end

function consumer(filter)
    while true do
        local x = receive(filter)
        print(x)
        if not x then break end
    end
end

consumer(filter(producer()))
--]]



--[[
function permgen(a, n)
    n = n or #a
    if n <= 1 then
        printResult(a)
    else
        for i = 1, n do
            a[i], a[n] = a[n], a[i]
            permgen(a, n - 1)
            a[i], a[n] = a[n], a[i]
        end
    end
end

function printResult(a)
    for i = 1, #a do
        io.write(a[i], " ")
    end
    io.write("\n")
end

permgen({1,2,3})

print("----")

function permgenco(a, n)
    n = n or #a
    if n <= 1 then
        coroutine.yield(a)
    else
        for i = 1, n do
            a[i], a[n] = a[n], a[i]
            permgen(a, n - 1)
            a[i], a[n] = a[n], a[i]
        end
    end
end

function permutation(a)
    local co = coroutine.create(function () permgen(a) end)
    return function () local ok, x = coroutine.resume(co); return x end
end

for p in permutation({1,2,3}) do
    printResult(p)
end

print("---")

function permutationwrap(a)
    return coroutine.wrap(function () permgen(a) end)
end

for p in permutationwrap({1, 2, 3}) do
    printResult(p)
end
--]]



--[[
local N = 8

local function ispaceok1(a, r, c)
    for i = 1, #a do
        if i == r then io.write("row equal\n");return false
        elseif a[i] == c then io.write("coloum equal\n");return false
        elseif i + a[i] == r + c then io.write("++++\n");return false
        elseif a[i] - i == c - r then io.write("-----\n");return false
        end
    end

    return true
end

local function isspaceok(a, n, c)
    for i = 1, n - 1 do
        if (a[i] == c) or
            (a[i] - i == c - n) or
            (a[i] + i == c + n) then
            return false
        end
    end
    return true
end

local i = 0

local function queen(a, n)
    if n > N then
        i = i + 1
    else
        for i = 1, N do
            if isspaceok(a, n, i) then
                a[n] = i
                queen(a, n + 1)
            end
        end
    end
end

queen({}, 1)
print(i)
--]]



List = {}
function List.new()
    List.first = 0; List.last = -1
end
