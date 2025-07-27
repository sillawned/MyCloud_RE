
void populate_pkg_info(char *__s,char *name,void *pkginfo_attribute,int size)

{
  char *pcVar1;
  int strcmp_res;
  size_t __s_len;
  size_t name_len;
  ushort **traits;
  char *__src;
  
  strcmp_res = strcmp(__s,name);
  if (strcmp_res != 0) {
    __s_len = strlen(__s);
    name_len = strlen(name);
    if (name_len <= __s_len) {
      traits = __ctype_b_loc();
      pcVar1 = __s + name_len;
      do {
        __src = pcVar1;
        pcVar1 = __src + 1;
      } while (((*traits)[*__src] & 0x2002) != 0);
      strncpy((char *)pkginfo_attribute,__src,(long)size);
      return;
    }
  }
  memset(pkginfo_attribute,0,(long)size);
  return;
}

