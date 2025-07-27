
void create_xml_config(PKG_INFO *pkg_info)

{
  xmlDoc *xml_doc;
  _xmlNode *cfg_node;
  _xmlNode *apkg;
  _xmlNode *item;
  undefined1 *product_id;
  undefined1 *custom_id;
  undefined1 *model_id;
  undefined1 *app_id;
  undefined1 *user_control;
  undefined1 *center_type;
  undefined1 *individual_flag;
  undefined1 *enabled;
  undefined1 *apkg_version;
  
  xml_doc = xmlNewDoc("1.0");
  *(undefined4 *)((long)&xml_doc[1]._private + 3) = 1;
  cfg_node = xmlNewNode((_xmlNs *)0x0,(xmlChar *)"config");
  xmlDocSetRootElement(xml_doc,cfg_node);
  apkg = xmlNewNode((_xmlNs *)0x0,"apkg");
  xmlAddChild(cfg_node,apkg);
  item = xmlNewNode((_xmlNs *)0x0,"item");
  xmlAddChild(apkg,item);
  product_id = int_to_decimal_string(pkg_info->product_id);
  xmlNewChild(item,0,"procudt_id",product_id);
  custom_id = int_to_decimal_string(pkg_info->custom_id);
  xmlNewChild(item,0,"custom_id",custom_id);
  model_id = int_to_decimal_string(pkg_info->model_id);
  xmlNewChild(item,0,"model_id",model_id);
  app_id = int_to_decimal_string(pkg_info->app_id);
  xmlNewChild(item,0,"app_id",app_id);
  user_control = int_to_decimal_string(pkg_info->user_control);
  xmlNewChild(item,0,"user_control",user_control);
  center_type = int_to_decimal_string(pkg_info->center_type);
  xmlNewChild(item,0,"center_type",center_type);
  individual_flag = int_to_decimal_string(pkg_info->individual_flag);
  xmlNewChild(item,0,"individual_flag",individual_flag);
  xmlNewChild(item,0,"name",pkg_info->name);
  xmlNewChild(item,0,"show",pkg_info->show);
  enabled = int_to_decimal_string(pkg_info->enabled);
  xmlNewChild(item,0,"enable",enabled);
  xmlNewChild(item,0,"version",pkg_info->version);
  xmlNewChild(item,0,"date",pkg_info->date_YYYYMMDD);
  xmlNewChild(item,0,"inst_date",pkg_info->inst_date);
  xmlNewChild(item,0,"path",pkg_info->path);
  xmlNewChild(item,0,"ps_name",pkg_info->ps_name);
  xmlNewChild(item,0,"url",pkg_info->url);
  xmlNewChild(item,0,"url_port",pkg_info->url_port);
  apkg_version = int_to_decimal_string(pkg_info->apkg_version);
  xmlNewChild(item,0,"apkg_version",apkg_version);
  xmlNewChild(item,0,"packager",pkg_info->packager);
  xmlNewChild(item,0,"email",pkg_info->email);
  xmlNewChild(item,0,"homepage",pkg_info->homepage);
  xmlNewChild(item,0,"inst_depend",pkg_info->inst_depend);
  xmlNewChild(item,0,"inst_conflict",pkg_info->inst_conflict);
  xmlNewChild(item,0,"start_depend",pkg_info->start_depend);
  xmlNewChild(item,0,"start_conflict",pkg_info->start_conflict);
  xmlNewChild(item,0,"description",pkg_info->description);
  xmlNewChild(item,0,"icon",pkg_info->icon);
  xmlNewChild(item,0,"MinFWVer",pkg_info->MinFWVer);
  xmlNewChild(item,0,"MaxFWVer",pkg_info->MaxFWVer);
  xmlNewChild(item,0,"Hidden",pkg_info->Hidden);
  xmlSaveFormatFileEnc("apkg.xml",xml_doc,"UTF-8",1);
  xmlFreeDoc(xml_doc);
  xmlCleanupParser();
  xmlMemoryDump();
  return;
}

