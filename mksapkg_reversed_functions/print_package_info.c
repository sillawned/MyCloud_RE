
void print_package_info(PKG_INFO *pkg_info)

{
  printf("\nNAS type:\t\t%s\n",(&MODELS)[pkg_info->model_index].product_name);
  printf("module name:\t\t%s\n",pkg_info->module_name);
  printf("module versioin:\t%s\n",pkg_info->version);
  printf("packager:\t\t%s\n",pkg_info->packager);
  printf("\nheader length:\t\t%ld\n",(ulong)pkg_info->header_length);
  printf("header checksum:\t%lX\n",(ulong)pkg_info->header_checksum);
  printf("\nAdd-ons \"%s\" create!\n\n",pkg_info->bin_filename);
  if (pkg_info->signed != 0) {
    return;
  }
  putchar(10);
  printf("\x1b[31;1m");
  puts("WARNING: Addon has not been SIGNED for official release! Use \'-s\'.");
  printf("\x1b[0m");
  puts("\n");
  return;
}

