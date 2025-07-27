
int parse_apkgrc(PKG_INFO *pkg_info)

{
  int access_apkg_rc;
  FILE *__stream;
  char *fgets_res;
  size_t __s_len;
  ushort **traits_of_apkg;
  char *index;
  char *strstr_res;
  long i;
  long flag_index;
  undefined8 *pBuf;
  byte bVar9;
  int res;
  char flags_container [8];
  undefined4 local_43c;
  char __s [16];
  undefined8 buf [127];
  int __s_len_int;
  char *flags;
  char cVar1;
  ushort *puVar2;
  
  bVar9 = 0;
  local_43c = 0;
  pBuf = buf;
  for (i = uVar1; i != 0; i = i + -1) {
    *pBuf = 0;
    pBuf = pBuf + 1;
  }
  __s[0] = '\0';
  __s[1] = '\0';
  __s[2] = '\0';
  __s[3] = '\0';
  __s[4] = '\0';
  __s[5] = '\0';
  __s[6] = '\0';
  __s[7] = '\0';
  __s[8] = '\0';
  __s[9] = '\0';
  __s[10] = '\0';
  __s[0xb] = '\0';
  __s[0xc] = '\0';
  __s[0xd] = '\0';
  __s[0xe] = '\0';
  __s[0xf] = '\0';
  flags_container[0] = '\0';
  flags_container[1] = '\0';
  flags_container[2] = '\0';
  flags_container[3] = '\0';
  flags_container[4] = '\0';
  flags_container[5] = '\0';
  flags_container[6] = '\0';
  flags_container[7] = '\0';
  if (((pkg_info == (PKG_INFO *)0x0) || (access_apkg_rc = access("apkg.rc",0), access_apkg_rc != 0))
     || (__stream = fopen("apkg.rc","r"), __stream == (FILE *)0x0)) {
    res = 0;
  }
  else {
    while (fgets_res = fgets(__s,0x400,__stream), fgets_res != (char *)0x0) {
      if (__s[0] != '\0') {
        __s_len = strlen(__s);
        __s_len_int = (int)__s_len;
        if (__s_len_int != 0) {
          traits_of_apkg = __ctype_b_loc();
          puVar2 = *traits_of_apkg;
          index = __s + (int)(__s_len_int - 1U);
          do {
                    /* Will check if the current character is a control char (0x0A - 0x0D : '\f',
                       '\v', '\n', '\r') */
            if ((puVar2[*index] & uVar2) == 0) break;
            *index = '\0';
            index = index + -1;
          } while (index != __s + ((long)__s_len_int - (ulong)(__s_len_int - 1U)) + -2);
        }
      }
      strstr_res = strstr(__s,"Package:");
      if (strstr_res == (char *)0x0) {
        fgets_res = strstr(__s,"Version:");
        if (fgets_res == (char *)0x0) {
          fgets_res = strstr(__s,"Packager:");
          if (fgets_res == (char *)0x0) {
            fgets_res = strstr(__s,"Email:");
            if (fgets_res == (char *)0x0) {
              fgets_res = strstr(__s,"Homepage:");
              if (fgets_res == (char *)0x0) {
                fgets_res = strstr(__s,"AddonShowName:");
                if (fgets_res != (char *)0x0) {
                  populate_pkg_info(__s,"AddonShowName:",pkg_info->show,0x44);
                  cVar1 = pkg_info->show[0];
                  goto joined_r0x001036e6;
                }
                fgets_res = strstr(__s,"AddonIndexPage:");
                if (fgets_res == (char *)0x0) {
                  fgets_res = strstr(__s,"AddonUsedPort:");
                  if (fgets_res == (char *)0x0) {
                    fgets_res = strstr(__s,"InstDepend:");
                    if (fgets_res == (char *)0x0) {
                      fgets_res = strstr(__s,"InstConflict:");
                      if (fgets_res == (char *)0x0) {
                        fgets_res = strstr(__s,"StartDepend:");
                        if (fgets_res == (char *)0x0) {
                          fgets_res = strstr(__s,"StartConflict:");
                          if (fgets_res == (char *)0x0) {
                            fgets_res = strstr(__s,"Description:");
                            if (fgets_res == (char *)0x0) {
                              fgets_res = strstr(__s,"Icon:");
                              if (fgets_res == (char *)0x0) {
                                fgets_res = strstr(__s,"CenterType:");
                                if (fgets_res == (char *)0x0) {
                                  fgets_res = strstr(__s,"UserControl:");
                                  if (fgets_res == (char *)0x0) {
                                    fgets_res = strstr(__s,"IndividualFlag:");
                                    if (fgets_res == (char *)0x0) {
                                      fgets_res = strstr(__s,"MinFWVer:");
                                      if (fgets_res == (char *)0x0) {
                                        fgets_res = strstr(__s,"MaxFWVer:");
                                        if (fgets_res == (char *)0x0) {
                                          fgets_res = strstr(__s,"Hidden:");
                                          if (fgets_res != (char *)0x0) {
                                            populate_pkg_info(__s,"Hidden:",pkg_info->Hidden,0x24);
                                            printf("Hidden: [%s]\n",pkg_info->Hidden);
                                          }
                                        }
                                        else {
                                          populate_pkg_info(__s,"MaxFWVer:",pkg_info->MaxFWVer,0x24)
                                          ;
                                          printf("MaxFWVer: [%s]\n",pkg_info->MaxFWVer);
                                        }
                                      }
                                      else {
                                        populate_pkg_info(__s,"MinFWVer:",pkg_info->MinFWVer,0x24);
                                        printf("MinFWVer: [%s]\n",pkg_info->MinFWVer);
                                      }
                                    }
                                    else {
                                      flags = flags_container;
                                      for (flag_index = 3; flag_index != 0;
                                          flag_index = flag_index + -1) {
                                        flags[0] = '\0';
                                        flags[1] = '\0';
                                        flags[2] = '\0';
                                        flags[3] = '\0';
                                        flags = flags + (ulong)bVar9 * -8 + 4;
                                      }
                                      populate_pkg_info(__s,"IndividualFlag:",flags_container,0xc);
                                      i = strtol(flags_container,(char **)0x0,10);
                                      pkg_info->individual_flag = (int)i;
                                    }
                                  }
                                  else {
                                    fgets_res = flags_container;
                                    for (i = 3; i != 0; i = i + -1) {
                                      fgets_res[0] = '\0';
                                      fgets_res[1] = '\0';
                                      fgets_res[2] = '\0';
                                      fgets_res[3] = '\0';
                                      fgets_res = fgets_res + (ulong)bVar9 * -8 + 4;
                                    }
                                    populate_pkg_info(__s,"UserControl:",flags_container,0xc);
                                    i = strtol(flags_container,(char **)0x0,10);
                                    pkg_info->user_control = (int)i;
                                  }
                                }
                                else {
                                  populate_pkg_info(__s,"CenterType:",flags_container,0xc);
                                  i = strtol(flags_container,(char **)0x0,10);
                                  pkg_info->center_type = (int)i;
                                }
                              }
                              else {
                                populate_pkg_info(__s,"Icon:",pkg_info->icon,0x104);
                              }
                            }
                            else {
                              populate_pkg_info(__s,"Description:",pkg_info->description,0x104);
                            }
                          }
                          else {
                            populate_pkg_info(__s,"StartConflict:",pkg_info->start_conflict,0x84);
                          }
                        }
                        else {
                          populate_pkg_info(__s,"StartDepend:",pkg_info->start_depend,0x84);
                        }
                      }
                      else {
                        populate_pkg_info(__s,"InstConflict:",pkg_info->inst_conflict,0x84);
                      }
                    }
                    else {
                      populate_pkg_info(__s,"InstDepend:",pkg_info->inst_depend,0x84);
                    }
                  }
                  else {
                    populate_pkg_info(__s,"AddonUsedPort:",pkg_info->url_port,0x14);
                  }
                }
                else {
                  populate_pkg_info(__s,"AddonIndexPage:",pkg_info->url,0x44);
                }
              }
              else {
                populate_pkg_info(__s,"Homepage:",pkg_info->homepage,0x44);
              }
            }
            else {
              populate_pkg_info(__s,"Email:",pkg_info->email,0x44);
            }
            goto LAB_00103653;
          }
          populate_pkg_info(__s,"Packager:",pkg_info->packager,0x44);
          cVar1 = pkg_info->packager[0];
        }
        else {
          populate_pkg_info(__s,"Version:",pkg_info->version,0x24);
          cVar1 = pkg_info->version[0];
        }
joined_r0x001036e6:
        if (cVar1 == '\0') {
LAB_001036a0:
          fclose(__stream);
          return 0;
        }
      }
      else {
        populate_pkg_info(__s,"Package:",pkg_info->name,0x44);
        if (pkg_info->name[0] == '\0') goto LAB_001036a0;
        strncpy(pkg_info->module_name,pkg_info->name,0x44);
      }
LAB_00103653:
      fgets_res = __s;
      for (i = 0x80; i != 0; i = i + -1) {
        fgets_res[0] = '\0';
        fgets_res[1] = '\0';
        fgets_res[2] = '\0';
        fgets_res[3] = '\0';
        fgets_res[4] = '\0';
        fgets_res[5] = '\0';
        fgets_res[6] = '\0';
        fgets_res[7] = '\0';
        fgets_res = fgets_res + (ulong)bVar9 * -0x10 + 8;
      }
    }
    fclose(__stream);
    strncpy(pkg_info->Package2,pkg_info->name,0x44);
    strncpy(pkg_info->Version2,pkg_info->version,0x24);
    res = 1;
    pkg_info->field119_0xa28 = 2;
  }
  return res;
}

