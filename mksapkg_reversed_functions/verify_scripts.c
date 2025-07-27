
undefined8 verify_scripts(PKG_INFO *pkg_info)

{
  int script_present;
  tm *datetime;
  long i;
  char **pShell_scripts;
  char *pcVar1;
  byte bVar2;
  time_t __timer;
  char *shell_scripts [7];
  char *local_130;
  char script_filename [256];
  dword app_id;
  dword app_id2;
  dword custom_id2;
  char *__src;
  dword custom_id;
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
      pcVar1 = script_filename;
      for (i = uVar3; i != 0; i = i + -1) {
        pcVar1[0] = '\0';
        pcVar1[1] = '\0';
        pcVar1[2] = '\0';
        pcVar1[3] = '\0';
        pcVar1[4] = '\0';
        pcVar1[5] = '\0';
        pcVar1[6] = '\0';
        pcVar1[7] = '\0';
        pcVar1 = pcVar1 + (ulong)bVar2 * -0x10 + 8;
      }
      strcpy(script_filename,__src);
      script_present = access(script_filename,0);
      if (script_present != 0) break;
      pShell_scripts = pShell_scripts + 1;
      if (pShell_scripts == &local_130) {
        snprintf(pkg_info->apkg_temp,0x100,"../%s","apkg_tar_tmp.tgz");
        pkg_info->apkg_version = 2;
        custom_id = (&MODELS)[pkg_info->model_index].custom_id;
        pkg_info->product_id = (&MODELS)[pkg_info->model_index].product_id;
        pkg_info->custom_id = custom_id;
        app_id = (&MODELS)[pkg_info->model_index].app_id;
        pkg_info->model_id = (&MODELS)[pkg_info->model_index].model_id;
        pkg_info->app_id = app_id;

        time(&__timer);
        datetime = localtime(&__timer);
        snprintf(pkg_info->date_YYYYMMDD,0x14,"%04d%02d%02d",datetime->tm_year + 0x76c,
                 datetime->tm_mon + 1,datetime->tm_mday);
        snprintf(pkg_info->date_MMDDYYYY,0x14,"%02d%02d%04d",datetime->tm_mon + 1,datetime->tm_mday,
                 datetime->tm_year + 0x76c);

        model_index = pkg_info->model_index;
        *(undefined8 *)pkg_info->code_name = *(undefined8 *)(&MODELS)[model_index].code_name;
        custom_id2 = (&MODELS)[model_index].custom_id;
        pkg_info->product_id_2 = (&MODELS)[model_index].product_id;
        pkg_info->custom_id_2 = custom_id2;
        app_id2 = (&MODELS)[model_index].app_id;
        pkg_info->model_id_2 = (&MODELS)[model_index].model_id;
        pkg_info->app_id_2 = app_id2;

        if (pkg_info->signed != 0) {
          pkg_info->pkg_signed = 1;
        }
        return 1;
      }
    }
  }
  return 0;
}

