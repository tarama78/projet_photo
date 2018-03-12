import os

for img in os.listdir('.'):
    os.rename(img, ('_'.join(img.split('_')[1:])))

# move
# rm -rf photos_label/* photos_srcs/* trash/* && cp cpy_photos_srcs/* photos_srcs
