import matplotlib.pyplot as plt
import cv2
import numpy as np

portrait = True

##open fil##
f = open("image.txt", "r")
lines = f.read().split('\n\r')
lines_arr = []
img = []

# split into a list of characters. each character is one line
for l in lines:
    if len(l) > 0:
        lines_arr.append(list(l))

print(lines)
# maps all characters to integers
for l in lines_arr:
    img.append(map(int,l))

#changes 1s and 0s into right
m = len(img)
n = len(img[0])

##filtered image
new_img = np.zeros((m, n))

for l in range(len(img)):
    for c in range(len(img[0])):
        ## look at the pixels around it
        counter = 0
        for i in range(max(0, l-1), min(l+2, m)):
            for j in range(max(0, c-1), min(c+2, n)):
                if i != j and img[i][j] == 1:
                    counter += 1
        ## shows cuts out stuff
        if img[l][c] == 1 and counter > 3:
            new_img[l][c]  = 0
        # elif img[l][c] == 1 ands counter <= 1:
        #     new_img[l][c] = 100
        else:
            new_img[l][c] = 255


##change into numpy array##
# img_np = np.asarray(new_img, dtype = np.uint8)

##display image
cv2.namedWindow("image", cv2.WINDOW_NORMAL)
cv2.resizeWindow('image', 1000,1000)
cv2.imshow("image", new_img)
cv2.waitKey(0)
cv2.destroyAllWindows()
