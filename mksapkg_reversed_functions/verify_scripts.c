
undefined8 verify_scripts(PKG_INFO *pkg_info)

{
  undefined4 uVar1;
  int script_present;
  tm *datetime;
  long i;
  char **pShell_scripts;
  char *pcVar2;
  byte bVar2;
  time_t __timer;
  char *shell_scripts [7];
  char *local_130;
  char script_filename [256];
  char *__src;
  int model_index;
  
  bVar2 = 0;
  shell_scripts[0] = "preinst.sh";
  shell_scripts[1] = "install.sh";
  shell_scripts[2] = "remove.sh";
  shell_scripts[3] = "init.sh";
  shell_scripts[4] = "clean.sh";
  shell_scripts[5] = "start.sh";
  shell_scripts[6] = "stop.sh";
  if (pkg_info != (PKG_INFO *)0x0) {
    pShell_scripts = shell_scripts;
    while( true ) {
      __src = *pShell_scripts;
      pcVar2 = script_filename;
      for (i = uVar3; i != 0; i = i + -1) {
        pcVar2[0] = '\0';
        pcVar2[1] = '\0';
        pcVar2[2] = '\0';
        pcVar2[3] = '\0';
        pcVar2[4] = '\0';
        pcVar2[5] = '\0';
        pcVar2[6] = '\0';
        pcVar2[7] = '\0';
        pcVar2 = pcVar2 + (ulong)bVar2 * -0x10 + 8;
      }
      strcpy(script_filename,__src);
      script_present = access(script_filename,0);
      if (script_present != 0) break;
      pShell_scripts = pShell_scripts + 1;
      if (pShell_scripts == &local_130) {
        snprintf(pkg_info->apkg_temp,0x100,"../%s","apkg_tar_tmp.tgz");
        pkg_info->apkg_version = 2;
        uVar1 = *(undefined4 *)((long)&(&MODELS)[pkg_info->model_index].field3_0x1c + 4);
        pkg_info->product_id = *(undefined4 *)&(&MODELS)[pkg_info->model_index].field3_0x1c;
        pkg_info->custom_id = uVar1;
        uVar1 = *(undefined4 *)((long)&(&MODELS)[pkg_info->model_index].supported_flag + 4);
        pkg_info->model_id = *(undefined4 *)&(&MODELS)[pkg_info->model_index].supported_flag;
        pkg_info->app_id = uVar1;
        time(&__timer);
        datetime = localtime(&__timer);
        snprintf(pkg_info->date_YYYYMMDD,0x14,"%04d%02d%02d",datetime->tm_year + 0x76c,
                 datetime->tm_mon + 1,datetime->tm_mday);
        snprintf(pkg_info->date_MMDDYYYY,0x14,"%02d%02d%04d",datetime->tm_mon + 1,datetime->tm_mday,
                 datetime->tm_year + 0x76c);
        model_index = pkg_info->model_index;
        *(undefined8 *)pkg_info->code_name = *(undefined8 *)(&MODELS)[model_index].code_name;
        pkg_info->field120_0xa2c = (&MODELS)[model_index].field3_0x1c;
        pkg_info->supported_flag = (&MODELS)[model_index].supported_flag;
        if (pkg_info->signed != 0) {
          pkg_info->pkg_signed = 1;
        }
        return 1;
      }
    }
  }
  return 0;
}

