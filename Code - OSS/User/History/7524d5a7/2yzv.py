import chess
import pygame
import sys
import random

tablero = chess.board()

ancho = 700

ventana = pygame.display.set_mode((ancho, ancho))
pygame.display.set_caption("Chess")

blanco = (255, 255, 255)
gris = (128, 128, 128)
amarillo = (204, 204, 0)
azul = (50, 255, 255)
b = (0, 0, 0)