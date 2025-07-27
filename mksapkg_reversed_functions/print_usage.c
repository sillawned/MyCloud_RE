
void print_usage(void)

{
  wd_models *ptr;
  wd_models *tmp_ptr;
  
  ptr = (wd_models *)MODELS.product_name;
  printf("\nUsage: %s -E -s -m [model_name]\n\n",basename);
  puts("\nSupported model_name:");
  while (ptr = ptr + 1, ptr != (wd_models *)0x104918) {
    while ((int)ptr->supported_flag == 1) {
      tmp_ptr = ptr + 1;
      printf("\t\t%s\n",ptr->code_name);
      ptr = tmp_ptr;
      if (tmp_ptr == (wd_models *)0x104918) goto LAB_00103e25;
    }
  }
LAB_00103e25:
  putchar(10);
  return;
}

