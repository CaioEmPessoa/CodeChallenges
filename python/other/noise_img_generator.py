from PIL import Image
import random

def generate_image(width, height):
    img = Image.new('RGB', (width, height), color='white')
    pixels = img.load()

    PIXEL_SIZE = 7
    CHANCE = 0.1
    COLOR_BG = (0, 0, 0)
    COLOR_ACCENT = (255, 255, 255)

    for x in range(0, width, PIXEL_SIZE):
        for y in range(0, height, PIXEL_SIZE):
            color = COLOR_ACCENT if random.random() < CHANCE else COLOR_BG
            for i in range(PIXEL_SIZE):
                for j in range(PIXEL_SIZE):
                    if x + i < width and y + j < height:
                        pixels[x + i, y + j] = color

    img.save('output_image.png')

# Example usage
generate_image(1920, 1080)