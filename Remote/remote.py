import socket
import pygame
import sys

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((sys.argv[1], 8080))

print "[A] Left  [D] Right  [W] Forward  [S] Backward"
print
print "Ctrl-C to quit"

pygame.init()

# to spam the pygame.KEYDOWN event every 100ms while key being pressed
pygame.key.set_repeat(100, 100)

while 1:
  for event in pygame.event.get():
    if event.type == pygame.KEYDOWN:
      if event.key == pygame.K_a:
        s.send(chr(100)+chr(95))
      if event.key == pygame.K_d:
        s.send(chr(95)+chr(90))
      if event.key == pygame.K_w:
        s.send(chr(100)+chr(90))
      if event.key == pygame.K_s:
        s.send(chr(90)+chr(100))
    if event.type == pygame.KEYUP:
      s.send(chr(95)+chr(95))
