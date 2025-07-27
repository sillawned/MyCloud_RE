
undefined8 create_bin(PKG_INFO *pkg_info)

{
  FILE *__s;
  undefined8 res;
  long lVar1;
  undefined8 *puVar2;
  byte bVar3;
  undefined1 cmd [16];
  undefined8 local_428 [128];
  char *bin_filename;
  int model_index;
  
  bVar3 = 0;
  bin_filename = pkg_info->bin_filename;
  cmd = (undefined1  [16])0x0;
  puVar2 = local_428;
  for (lVar1 = 0x7e; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  model_index = pkg_info->model_index;
  *(undefined4 *)puVar2 = 0;
  snprintf(bin_filename,0x100,"../%s_%s_%s.bin(%s)",(&MODELS)[model_index].product_name,
           pkg_info->module_name,pkg_info->version,pkg_info->date_MMDDYYYY);
  printf("***[%s]\n",bin_filename);
  __s = fopen("../apkg_header_tmp","w+");
  res = 0;
  if (__s != (FILE *)0x0) {
    fwrite(pkg_info->code_name,0xcc,1,__s);
    fclose(__s);
    puVar2 = (undefined8 *)cmd;
    for (lVar1 = 0x80; lVar1 != 0; lVar1 = lVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + (ulong)bVar3 * -2 + 1;
    }
    *(undefined4 *)puVar2 = 0;
    remove(bin_filename);
    snprintf(cmd,0x404,"cat %s %s > \"%s\"","../apkg_header_tmp",pkg_info->apkg_temp,bin_filename);
    system(cmd);
    remove("../apkg_header_tmp");
    remove(pkg_info->apkg_temp);
    res = 1;
  }
  return res;
}

