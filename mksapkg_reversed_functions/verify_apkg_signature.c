
bool verify_apkg_signature(PKG_INFO *pkg_info)

{
  int cmd_res;
  FILE *__stream;
  long lVar1;
  undefined8 *puVar2;
  bool res;
  undefined1 openssl_version [16];
  undefined1 local_148 [16];
  undefined4 local_138;
  char *cmd;
  undefined8 local_118 [33];
  
  local_138 = 0;
  puVar2 = local_118;
  for (lVar1 = 0x1e; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  openssl_version = (undefined1  [16])0x0;
  local_148 = (undefined1  [16])0x0;
  _cmd = (undefined1  [16])0x0;
  *(undefined4 *)puVar2 = 0;
  __stream = popen("openssl version | awk {\'print $2\'} | awk -F \".\" {\'print $1\'}","r");
  res = false;
  if (__stream != (FILE *)0x0) {
    fgets(openssl_version,0x24,__stream);
    fclose(__stream);
    if (openssl_version[0] == '3') {
      snprintf((char *)&cmd,0x104,
               "echo \"%s\" | openssl bf-cbc -md sha256 -out apkg.sign -k \"%s\" -provider legacy -provider default"
               ,pkg_info->name,"Lidho.mdk3K3h");
    }
    else {
      snprintf((char *)&cmd,0x104,"echo \"%s\" | openssl bf-cbc -md sha256 -out apkg.sign -k \"%s\""
               ,pkg_info->name,"Lidho.mdk3K3h");
    }
    cmd_res = system((char *)&cmd);
    res = cmd_res == 0;
  }
  return res;
}

