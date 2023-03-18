from PIL import Image
import numpy as np

grey_img = Image.open('./puzzle-1/interrogation.png').convert('L')
byte_arr = grey_img.tobytes()
w, h = grey_img.size
new_img = []
idx = 0

# for every character in the ascii art
with open('./puzzle-1/ascii-art.txt', 'rb') as file:
  while (byte := file.read(1)):
    # read it as a byte
    byte = bin(ord(byte.decode()))[2:]

    # pad as necessary to get all 8 bits
    if len(byte) < 8:
      byte = (8 - len(byte)) * '0' + byte

    # for each bit, add 1 or 0 to the pixel to ensure that its LSB matches
    # the corresponding ascii bit
    for bit in byte:
      new_byte = byte_arr[idx]
      if new_byte % 2 != int(bit):
        new_byte += 1 if new_byte != 255 else -1

      # add this new byte to our image  
      new_img.append(new_byte)
      idx += 1

  # pad the rest of the space (after the ascii art is done) with newlines
  newline = '00001010'
  for i in range(idx, len(byte_arr), 8):
    for j in range(8):
      new_byte = byte_arr[i + j] + int(byte_arr[i + j] % 2 != int(newline[j]))
      new_img.append(new_byte)

# save the image
new_img = np.array(new_img).reshape((h, w))
bw_img = Image.fromarray(new_img.astype('uint8'))
bw_img.save('./puzzle-1/bw_img.png')
