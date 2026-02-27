import cv2 
import numpy as np 
import matplotlib.pylab as plt
#plt.style.use('dark_background')
def dither(src,src_f,width:int,height:int,channels:int):
    palette = np.array([0x92215F , 0x590C68,0x000828 ],dtype=np.uint32)#RGB 
    palette = palette[::-1]
    palette_rgb = np.zeros((len(palette), 3), dtype=np.uint8)
    palette_rgb[:, 2] = (palette >> 16) & 0xFF  # Red
    palette_rgb[:, 1] = (palette >> 8) & 0xFF   # Green
    palette_rgb[:, 0] = palette & 0xFF          # Blue
    print(palette_rgb)
    for i in range(width-1):
        for j in range(height-1):
                old=src_f[i,j]
                dist=np.sum((palette_rgb -old)**2,axis=1) 
                new=palette_rgb[np.argmin(dist)]
                src_f[i,j]=new
                error=old-new
                src_f[i,j+1]+=error *7/16
                src_f[i+1,j-1]+=error*3/16
                src_f[i+1,j]+=error*5/16
                src_f[i+1,j+1]+=error *1/16
                
filepath ="dog.jpeg"
src=cv2.imread(filepath)#bgr 
width,height,channels = np.shape(np.array(src)) 
src_f=np.array(src).astype(np.float32)
dither(src,src_f,width,height,channels)
src =cv2.cvtColor(src,cv2.COLOR_BGR2RGB)
src_f=cv2.cvtColor(src_f,cv2.COLOR_BGR2RGB)
fig,ax=plt.subplots(1,2)
ax[0].grid(False)
ax[0].axis('off')
ax[0].imshow(src)
ax[0].set_title("Original Image")
ax[1].grid(False)
ax[1].axis('off')
ax[1].imshow(src_f)
ax[1].set_title("Dithered Image")
plt.show()

