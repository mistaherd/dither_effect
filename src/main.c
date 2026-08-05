#include <stdint.h>
#include <stdio.h>
#define IMAGE_PATH "dog.jpeg"
typedef struct {
  uint32_t RIFF;
  uint32_t File_size;
  uint32_t WEBP;
  uint32_t VP8X;
  uint32_t Chunk_size;
  uint32_t Flags_0;
  uint32_t Flags_1;
  uint32_t ALPH;
  uint32_t Alpha_Stream_Payload_Size;
  uint32_t Compressed_Alpha_Data;
  uint32_t VP8 ;
  uint32_t VP8_Bitsream_Payload_Size;
  uint32_t RAW_VP8_Video_Frame;
  uint32_t EXIF;
}WEBP;

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
