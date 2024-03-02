import chess
import pygame
import sys
import random

tablero = chess.board()

ancho = 700

ventana = pygame.display.set_mode(ancho, ancho)
pygame.display.set_caption("Chess")