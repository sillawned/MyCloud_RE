
bool create_apkg_temp_archive(PKG_INFO *pkg_info)

{
  int access_res;
  undefined8 uVar1;
  long lVar2;
  undefined8 *puVar3;
  undefined1 package_folder [16];
  undefined1 local_518 [16];
  undefined1 local_508 [16];
  undefined1 local_4f8 [16];
  undefined1 local_4e8 [16];
  undefined1 local_4d8 [16];
  undefined1 local_4c8 [16];
  undefined1 local_4b8 [16];
  undefined1 local_4a8 [16];
  undefined1 local_498 [16];
  undefined1 local_488 [16];
  undefined1 local_478 [16];
  undefined1 local_468 [16];
  undefined1 local_458 [16];
  undefined1 local_448 [16];
  undefined1 local_438 [16];
  undefined1 cmd [16];
  undefined8 local_418 [128];
  
  package_folder = (undefined1  [16])0x0;
  puVar3 = local_418;
  for (lVar2 = 0x7e; lVar2 != 0; lVar2 = lVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  local_518 = (undefined1  [16])0x0;
  local_508 = (undefined1  [16])0x0;
  local_4f8 = (undefined1  [16])0x0;
  local_4e8 = (undefined1  [16])0x0;
  local_4d8 = (undefined1  [16])0x0;
  local_4c8 = (undefined1  [16])0x0;
  *(undefined4 *)puVar3 = 0;
  local_4b8 = (undefined1  [16])0x0;
  local_4a8 = (undefined1  [16])0x0;
  local_498 = (undefined1  [16])0x0;
  local_488 = (undefined1  [16])0x0;
  local_478 = (undefined1  [16])0x0;
  local_468 = (undefined1  [16])0x0;
  local_458 = (undefined1  [16])0x0;
  local_448 = (undefined1  [16])0x0;
  local_438 = (undefined1  [16])0x0;
  cmd = (undefined1  [16])0x0;
  if (pkg_info != (PKG_INFO *)0x0) {
    remove(pkg_info->apkg_temp);
    uVar1 = set_cwd(package_folder,0x100);
    if ((int)uVar1 == 1) {
      snprintf(cmd,0x404,"cd ..; tar zcvf %s \"%s\"; cd \"%s\"","apkg_tar_tmp.tgz",package_folder,
               package_folder);
      system(cmd);
      access_res = access(pkg_info->apkg_temp,0);
      return access_res == 0;
    }
  }
  return false;
}

