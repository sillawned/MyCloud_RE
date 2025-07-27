
uint read_file_checksum(char *__file)

{
  int __fd;
  uint *__ptr;
  ssize_t byte_read;
  uint *current_char;
  uint uVar1;
  uint res;
  ulong __offset;
  
  __ptr = (uint *)calloc(1,0x10000);
  if (__ptr == (uint *)0x0) {
    res = 0;
  }
  else {
    __fd = open(__file,0);
    __offset = 0;
    res = 0;
    if (__fd == -1) {
      free(__ptr);
      printf("Error: Can\'t open %s file !\n",__file);
    }
    else {
      do {
        lseek(__fd,__offset,0);
        memset(__ptr,0,0x10000);
        byte_read = read(__fd,__ptr,0x10000);
        uVar1 = (uint)byte_read;
        if (uVar1 >> 2 == 0) break;
        current_char = __ptr;
        do {
          res = res ^ *current_char;
          current_char = current_char + 1;
        } while (current_char != __ptr + (ulong)((uVar1 >> 2) - 1) + 1);
        __offset = (ulong)((int)__offset + uVar1);
      } while (uVar1 == 0x10000);
      close(__fd);
      free(__ptr);
    }
  }
  return res;
}

