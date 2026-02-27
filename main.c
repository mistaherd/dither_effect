#include <stdint.h>
#include <stdio.h>
#define IMAGE_PATH "dog.jpeg"
#define File_size_offset_webp 32 

void print_array(unsigned char *data,size_t size){
  printf("\n[%02x",data[0]);
  for (int8_t i=1;i<size;i++){
    if (i==size-1){
      printf("%02x]\n",data[i]);

    }
    else{
      printf(", %02x",data[i]);
    }
  }
}
int main(){
  size_t ret;
  // check if  the its really a file we  can open
  FILE *fptr =fopen(IMAGE_PATH,"rb");
  if (!fptr){
    perror("error while opening FILE");
    return 1;
  }
  // we define a jpegs file signature  this can be seen in a hex editor
  unsigned char *buffer[File_size_offset_webp];
  ret=fread(buffer,sizeof(*buffer),File_size_offset_webp,fptr);
  if (ret!= File_size_offset_webp) {
    perror("error while reading file Check if we arent in the end ");
    return 1;
  }
  print_array(*buffer,File_size_offset_webp);
  fclose(fptr);
  return 0;
}
