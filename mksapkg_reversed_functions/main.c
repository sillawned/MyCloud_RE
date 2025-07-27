
int main(int argc,char **argv)

{
	bool bVar1;
	int getopt_ret;
	int model_index;
	int bParsed_apkgrc;
	undefined8 uVar3;
	undefined7 extraout_var;
	undefined7 extraout_var_00;
	long lVar4;
	size_t __n;
	PKG_INFO *pPVar1;
	char *apkg_archive_filename;
	char *__s1;
	byte bVar6;
	stat __stat_buf;
	PKG_INFO pkg_info;
	char *options;

	bVar6 = 0;
	basename = __xpg_basename(*argv);
	opterr = 0;
	pPVar1 = &pkg_info;
	for (lVar4 = 0x151; lVar4 != 0; lVar4 = lVar4 + -1) {
		pPVar1->module_name[0] = '\0';
		pPVar1->module_name[1] = '\0';
		pPVar1->module_name[2] = '\0';
		pPVar1->module_name[3] = '\0';
		pPVar1->module_name[4] = '\0';
		pPVar1->module_name[5] = '\0';
		pPVar1->module_name[6] = '\0';
		pPVar1->module_name[7] = '\0';
		pPVar1 = (PKG_INFO *)((long)pPVar1 + (ulong)bVar6 * -0x10 + 8);
	}
	pkg_info.model_index = -1;
	apkg_archive_filename = (char *)0x0;
	model_index = pkg_info.model_index;
LAB_0010237b:
	do {
		pkg_info.model_index = model_index;
		getopt_ret = getopt(argc,argv,"Ehsm:V");
		options = optarg;
		if (getopt_ret == -1) {
			if (apkg_archive_filename == (char *)0x0) {
				fwrite("ERROR: ",1,7,stderr);
				fwrite("model_name not specify\n",1,0x17,stderr);
			}
			else {
				if (pkg_info.model_index != -1) {
					puts("============================================");
					printf("\t%s version: %s\n",basename,"2.1");
					puts("============================================");
					uVar3 = verify_scripts(&pkg_info);
					if ((int)uVar3 == 1) {
						bParsed_apkgrc = parse_apkgrc(&pkg_info);
						if (bParsed_apkgrc == 1) {
							create_xml_config(&pkg_info);
							remove("apkg.sign");
							if ((pkg_info.signed == 0) ||
									(bVar1 = verify_apkg_signature(&pkg_info), (int)CONCAT71(extraout_var,bVar1) == 1))
							{
								bVar1 = create_apkg_temp_archive(&pkg_info);
								if ((int)CONCAT71(extraout_var_00,bVar1) == 1) {
									apkg_archive_filename = pkg_info.apkg_temp;
									__lxstat(1,apkg_archive_filename,&__stat_buf);
									pkg_info.header_length = (uint)__stat_buf.st_size;
									if ((pkg_info.apkg_temp[0] == '\0') ||
											(model_index = access(apkg_archive_filename,0), model_index != 0)) {
										pkg_info.header_checksum = 0;
									}
									else {
										pkg_info.header_checksum = read_file(apkg_archive_filename);
										if (pkg_info.header_checksum != 0) {
											uVar3 = create_bin(&pkg_info);
											if ((int)uVar3 != 1) {
												fwrite("ERROR: ",1,7,stderr);
												fprintf(stderr,"can\'t create %s ADD-ons!\n\n",pkg_info.module_name);
												fflush(stderr);
												/* WARNING: Subroutine does not return */
												exit(-1);
											}
											print_package_info(&pkg_info);
											return 0;
										}
									}
									fwrite("ERROR: ",1,7,stderr);
									__n = 0x1b;
									apkg_archive_filename = "can\'t calculate checksum!\n\n";
								}
								else {
									fwrite("ERROR: ",1,7,stderr);
									__n = 0x24;
									apkg_archive_filename = "tar command can\'t create tgz file!\n\n";
								}
							}
							else {
								fwrite("ERROR: ",1,7,stderr);
								__n = 0x19;
								apkg_archive_filename = "can\'t create apkg sign!\n\n";
							}
						}
						else {
							fwrite("ERROR: ",1,7,stderr);
							__n = 0x1c;
							apkg_archive_filename = "fail to read apkg.rc file!\n\n";
						}
					}
					else {
						fwrite("ERROR: ",1,7,stderr);
						__n = 0x21;
						apkg_archive_filename = "file missed or file path error!\n\n";
					}
					fwrite(apkg_archive_filename,1,__n,stderr);
					fflush(stderr);
					/* WARNING: Subroutine does not return */
					exit(-1);
				}
				fwrite("ERROR: ",1,7,stderr);
				fprintf(stderr,"unknown model_name: %s\n",apkg_archive_filename);
			}
			fflush(stderr);
LAB_00102631:
			print_usage();
			/* WARNING: Subroutine does not return */
			exit(-1);
		}
		model_index = pkg_info.model_index;
		if (getopt_ret != L'm') {
			if (getopt_ret < L'n') {
				if (getopt_ret != L'E') {
					if (getopt_ret == L'V') {
						puts("2.1");
						/* WARNING: Subroutine does not return */
						exit(0);
					}
					goto LAB_00102631;
				}
				pkg_info.enabled = 1;
			}
			else {
				if (getopt_ret != L's') goto LAB_00102631;
				pkg_info.signed = 1;
			}
			goto LAB_0010237b;
		}
		if ((optarg != (char *)0x0) && (*optarg != '\0')) {
			__s1 = MODELS.product_name;
			getopt_ret = 0;
			do {
				model_index = strcmp(__s1,options);
				apkg_archive_filename = options;
				if ((model_index == 0) && (model_index = getopt_ret, *(dword *)(__s1 + 0x24) == 1)) break;
				getopt_ret = getopt_ret + 1;
				__s1 = __s1 + 0x30;
				model_index = pkg_info.model_index;
			} while (getopt_ret != L'\r');
		}
	} while( true );
}

