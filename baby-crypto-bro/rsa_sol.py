# known information
N = 0x776b91
MESSAGE = 0x4e8f84
e = 0x314fb9

# first, we need to find the primes whose product make N
def find_primes(N):
  primes = [True] * (N + 1)
  primes[0], primes[1] = False, False
  for i in range(2, int(N ** 0.5) + 1):
    if primes[i]:
      for j in range(i * i, N + 1, i):
        primes[j] = False
  
  return [i for i in range(2, N + 1) if primes[i]]

def number_to_string(num: int) -> str:
  bin_str = bin(num)[2:]
  bin_str = bin_str.rjust(((len(bin_str) // 8) + 1) * 8, '0')
  return ''.join([ chr(int(bin_str[i:i+8], 2)) for i in range(0, len(bin_str), 8) ])

primes = find_primes(N // 2)
p, q = 0, 0
for x in primes:
  if N % x == 0:
    p = x
    q = N // p

# next, we find `d`
phi = (p - 1) * (q - 1)
d = pow(e, -1, phi)

print(number_to_string(pow(MESSAGE, d, N)))
