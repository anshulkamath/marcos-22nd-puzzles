import random

random.seed(0)

MESSAGE_0 = 'pog'
MESSAGE_1 = 'who'
MESSAGE_2 = 'me?'

def string_to_bits(message: str, debug = False) -> str:
  return (debug * ' ').join([bin(ord(c))[2:].rjust(8, '0') for c in message])

def bits_to_number(bits: str) -> int:
  if ' ' in bits:
    bits = ''.join(bits.split(' '))
  
  return int(bits, 2)

def number_to_string(num: int) -> str:
  bin_str = bin(num)[2:]
  bin_str = bin_str.rjust(((len(bin_str) // 8) + 1) * 8, '0')
  return ''.join([ chr(int(bin_str[i:i+8], 2)) for i in range(0, len(bin_str), 8) ])

def get_primes(N):
  primes = [True] * (N + 1)
  primes[0], primes[1] = False, False
  for i in range(2, int(N ** 0.5) + 1):
    if primes[i]:
      for j in range(i * i, N + 1, i):
        primes[j] = False
  return [i for i in range(2, N + 1) if primes[i]]

def generate_primes(bound_1, bound_2 = 0):
  prime_limit = max(bound_1, bound_2)

  # guarantee that our MESSAGES can fit in the residue class of `n`
  primes = get_primes(prime_limit // 2)

  p = random.choice(primes[100:1000])
  q = -1
  for x in primes:
    if x * p > prime_limit:
      q = x
      break

  return p, q

def generate_pub_priv_keys(p, q):
  phi = (p - 1) * (q - 1)
  
  while True:
    try:
      # generate public key
      e = random.randint(2, phi)
      # while (e % p == 0 or e % q == 0):
      #   e = random.randint(2, phi)
      
      # generate private key
      d = pow(e, -1, phi)
      break
    except:
      pass

  return e, d

def encrypt_message(message, pub_key, n):
  return pow(message, pub_key, n)

def decrypt_message(enc_message, priv_key, n):
  return pow(enc_message, priv_key, n)

message_0 = bits_to_number(string_to_bits(MESSAGE_0))
message_1 = bits_to_number(string_to_bits(MESSAGE_1))
message_2 = bits_to_number(string_to_bits(MESSAGE_2))

p, q = generate_primes(message_1, message_2)
N = p * q
pub_key, priv_key = generate_pub_priv_keys(p, q)

print(f'N: {hex(N)}')
print(f'p: {hex(p)}; q: {hex(q)}')
print(f'Public key: {hex(pub_key)}')
print(f'Private key: {hex(priv_key)}')
for i, message in enumerate((message_0, message_1, message_2)):
  encrypted = encrypt_message(message, pub_key, N)
  decrypted = decrypt_message(encrypted, priv_key, N)

  print(f'message {i + 1}: {hex(encrypted)}')

  if (decrypted != message):
    raise Exception(f'RSA Encryption broken. {decrypted} computed but {message} expected')
