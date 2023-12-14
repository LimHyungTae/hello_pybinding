from PIL import Image
import numpy as np

import image

if __name__ == '__main__':
    with Image.open("data/cat.png", "r") as img:
        buf = np.array(img)

        image.to_red(buf)

        new_img = Image.fromarray(buf)
        new_img.show()
