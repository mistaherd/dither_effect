import numpy as np 
import cv2 
import matplotlib.pylab as plt
def define_colour_palette(data):
    data=data[::-1]
    data_rgb=np.zeros((len(data),3),dtype=np.uint8)
    data_rgb[:,0]= (data >>16) & 0xFF 
    data_rgb[:,1]=(data >>8) &0xFF 
    data_rgb[:,2]=data &0xFF 
    return data_rgb
filepath="dog.jpeg"
src=cv2.imread(filepath)
width,height,channels=np.shape(src)
src_f=np.array(src).astype(np.float32)

M2=np.array([[0,2],[3,1]])
M2=(1/4.0)*M2
M4=np.array([[0,8,2,10],
             [12,4,14,6],
             [3,11,1,9],
             [15,7,13,5]])
M4= 1/16 *M4
N=4
palette = np.array([0x92215F , 0x590C68,0x000828 ],dtype=np.uint32)#RGB 

palette_rgb=define_colour_palette(palette)
for i in range(width-1):
    for j in range(height-1):
        c=src_f[i,j]
        r=255/N
        thres=M4[i%N,j%N]
        res=c+r*(thres-1/2)
        dist=np.sum((palette_rgb-res)**2,axis=1)
        new=palette_rgb[np.argmin(dist)]
        src_f[i,j]=new
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

