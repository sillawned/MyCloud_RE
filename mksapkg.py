import argparse
import sys
import os
import xml.etree.ElementTree as ET
from xml.dom import minidom
import subprocess

from dataclasses import dataclass

@dataclass
class WDModel:
    code_name: str = ""
    product_name: str = ""
    field2_0x18: int = 0
    product_id: int = 0
    custom_id: int = 0
    model_id: int = 0
    app_id: int = 0
    supported: int = 0

# List of supported models
models = [
    WDModel(code_name="LightniZ", product_name="WDMyCloudEX4", field2_0x18=0x0, product_id=0x0, custom_id=0x14, model_id=0x0, app_id=0x0, supported=0),
    WDModel(code_name="KingsCaZ", product_name="WDMyCloudEX2", field2_0x18=0x0, product_id=0x0, custom_id=0x14, model_id=0x1, app_id=0x1, supported=0),
    WDModel(code_name="KingsCaZ", product_name="WDMyCloudMirror", field2_0x18=0x0, product_id=0x0, custom_id=0x14, model_id=0x1, app_id=0x2, supported=0),
    WDModel(code_name="GlacierZ", product_name="WDMyCloud", field2_0x18=0x0, product_id=0x0, custom_id=0x14, model_id=0x2, app_id=0x3, supported=1),
    WDModel(code_name="Yellow", product_name="WDMyCloudEX4100", field2_0x18=0x0, product_id=0x0, custom_id=0x14, model_id=0x3, app_id=0x4, supported=1),
    WDModel(code_name="Sprite", product_name="WDMyCloudDL4100", field2_0x18=0x0, product_id=0x0, custom_id=0x14, model_id=0x5, app_id=0x6, supported=1),
    WDModel(code_name="YosemitZ", product_name="WDMyCloudEX2100", field2_0x18=0x0, product_id=0x0, custom_id=0x14, model_id=0x4, app_id=0x5, supported=1),
    WDModel(code_name="Aurora", product_name="WDMyCloudDL2100", field2_0x18=0x0, product_id=0x0, custom_id=0x14, model_id=0x6, app_id=0x7, supported=1),
    WDModel(code_name="GrandTeZ", product_name="WDMyCloudMirror", field2_0x18=0x0, product_id=0x0, custom_id=0x14, model_id=0x1, app_id=0x8, supported=1),
    WDModel(code_name="GrandTeZ", product_name="MyCloudEX2Ultra", field2_0x18=0x0, product_id=0x0, custom_id=0x14, model_id=0x1, app_id=0x9, supported=1),
    WDModel(code_name="BlackCyZ", product_name="MyCloudPR4100", field2_0x18=0x0, product_id=0x0, custom_id=0x14, model_id=0x7, app_id=0xA, supported=1),
    WDModel(code_name="BryceCyZ", product_name="MyCloudPR2100", field2_0x18=0x0, product_id=0x0, custom_id=0x14, model_id=0x8, app_id=0xB, supported=1),
    WDModel(code_name="GlacierZ", product_name="WDCloud", field2_0x18=0x0, product_id=0x0, custom_id=0x14, model_id=0x2, app_id=0xC, supported=1),
]

def get_model_index_by_product_name(product_name):
    """
    Returns the index of the model with the given product name.
    """
    for idx, model in enumerate(models):
        print(model)
        if model.product_name == product_name:
            print(f"Found model '{product_name}' at index {idx}\n")
            return idx
    print("Model not found\n")
    return -1

def verify_scripts(pkg_info):
    """
    Checks if all required shell scripts exist in the current directory.
    Initializes main fields in pkg_info if scripts are present.
    """
    shell_scripts = [
        "preinst.sh",
        "install.sh",
        "remove.sh",
        "init.sh",
        "clean.sh",
        "start.sh",
        "stop.sh"
    ]
    for script in shell_scripts:
        if not os.path.isfile(script):
            return 0

    # Initialize main fields
    pkg_info["apkg_temp"] = "../apkg_tar_tmp.tgz"
    pkg_info["apkg_version"] = 2

    model_index = pkg_info.get("model_index", -1)
    if model_index < 0 or model_index >= len(models):
        print("ERROR: Invalid model index!", file=sys.stderr)
        return 0
    pkg_info["product_id"] = models[model_index].product_id
    pkg_info["custom_id"] = models[model_index].custom_id
    pkg_info["model_id"] = models[model_index].model_id
    pkg_info["app_id"] = models[model_index].app_id

    from datetime import datetime
    now = datetime.now()
    pkg_info["date"] = now.strftime("%Y%m%d")
    pkg_info["inst_date"] = now.strftime("%m%d%Y")

    pkg_info["code_name"] = models[model_index].code_name
    
    # Used during binary creation
    pkg_info["product_id_2"] = models[model_index].product_id
    pkg_info["custom_id_2"] = models[model_index].custom_id
    pkg_info["model_id_2"] = models[model_index].model_id
    pkg_info["app_id_2"] = models[model_index].app_id

    if pkg_info.get("signed", 0) != 0:
        pkg_info["pkg_signed"] = 1
    return 1

def parse_apkgrc(pkg_info):
    """
    Parses the apkg.rc file and fills pkg_info with package metadata.
    """
    if not os.path.isfile("apkg.rc"):
        return 0

    with open("apkg.rc", "r", encoding="utf-8") as f:
        for line in f:
            line = line.strip()
            if not line:
                continue
            if line.startswith("Package:"):
                pkg_info["name"] = line[len("Package:"):].strip()
                if not pkg_info["name"]:
                    print("ERROR: Package name is empty!", file=sys.stderr)
                    return 0
            elif line.startswith("Version:"):
                pkg_info["version"] = line[len("Version:"):].strip()
            elif line.startswith("Packager:"):
                pkg_info["packager"] = line[len("Packager:"):].strip()
            elif line.startswith("Email:"):
                pkg_info["email"] = line[len("Email:"):].strip()
            elif line.startswith("Homepage:"):
                pkg_info["homepage"] = line[len("Homepage:"):].strip()
            elif line.startswith("Description:"):
                pkg_info["description"] = line[len("Description:"):].strip()
            elif line.startswith("Icon:"):
                pkg_info["icon"] = line[len("Icon:"):].strip()
            elif line.startswith("AddonShowName:"):
                pkg_info["show"] = line[len("AddonShowName:"):].strip()
            elif line.startswith("AddonIndexPage:"):
                pkg_info["url"] = line[len("AddonIndexPage:"):].strip()
            elif line.startswith("AddonUsedPort:"):
                pkg_info["url_port"] = line[len("AddonUsedPort:"):].strip()
            elif line.startswith("InstDepend:"):
                pkg_info["inst_depend"] = line[len("InstDepend:"):].strip()
            elif line.startswith("InstConflict:"):
                pkg_info["inst_conflict"] = line[len("InstConflict:"):].strip()
            elif line.startswith("StartDepend:"):
                pkg_info["start_depend"] = line[len("StartDepend:"):].strip()
            elif line.startswith("StartConflict:"):
                pkg_info["start_conflict"] = line[len("StartConflict:"):].strip()
            elif line.startswith("CenterType:"):
                pkg_info["center_type"] = int(line[len("CenterType:"):].strip())
            elif line.startswith("MinFWVer:"):
                pkg_info["MinFWVer"] = line[len("MinFWVer:"):].strip()
            elif line.startswith("MaxFWVer:"):
                pkg_info["MaxFWVer"] = line[len("MaxFWVer:"):].strip()
            elif line.startswith("Hidden:"):
                pkg_info["Hidden"] = line[len("Hidden:"):].strip()
            elif line.startswith("IndividualFlag:"):
                pkg_info["individual_flag"] = int(line[len("IndividualFlag:"):].strip())
            elif line.startswith("UserControl:"):
                pkg_info["user_control"] = int(line[len("UserControl:"):].strip())
            else:
                # Ignore unknown lines
                continue

    # Set default names and versions
    pkg_info["module_name"] = pkg_info.get("name")
    pkg_info["package_name"] = pkg_info.get("name", "")
    pkg_info["package_version"] = pkg_info.get("version", "")
    pkg_info["parsed_apkgrc"] = 2
    return 1

def create_xml_config(pkg_info):
    """
    Creates an XML configuration file (apkg.xml) from pkg_info.
    """
    config = ET.Element("config")
    apkg = ET.SubElement(config, "apkg")
    item = ET.SubElement(apkg, "item")

    def add_int_field(name, xml_name=None):
        if xml_name is None:
            xml_name = name
        ET.SubElement(item, xml_name).text = str(pkg_info.get(name, 0))

    def add_str_field(name, xml_name=None):
        if xml_name is None:
            xml_name = name
        ET.SubElement(item, xml_name).text = str(pkg_info.get(name, ""))

    # Add fields to XML in the required order
    add_int_field("product_id", "procudt_id")  # typo from C
    add_int_field("custom_id")
    add_int_field("model_id")
    add_int_field("app_id")
    add_int_field("user_control")
    add_int_field("center_type")
    add_int_field("individual_flag")
    add_str_field("name")
    add_str_field("show")
    add_int_field("enabled", "enable")  # "enable" in XML
    add_str_field("version")
    add_str_field("date")
    add_str_field("inst_date")
    add_str_field("path")
    add_str_field("ps_name")
    add_str_field("url")
    add_str_field("url_port")
    add_int_field("apkg_version")
    add_str_field("packager")
    add_str_field("email")
    add_str_field("homepage")
    add_str_field("inst_depend")
    add_str_field("inst_conflict")
    add_str_field("start_depend")
    add_str_field("start_conflict")
    add_str_field("description")
    add_str_field("icon")
    add_str_field("MinFWVer")
    add_str_field("MaxFWVer")
    add_str_field("Hidden")

    # Write XML with correct header encoding
    xml_str = ET.tostring(config, encoding="utf-8")
    parsed_xml = minidom.parseString(xml_str)
    with open("apkg.xml", "w", encoding="UTF-8") as f:
        f.write(parsed_xml.toprettyxml(indent="  ", encoding="UTF-8").decode("UTF-8"))

def create_pkg_info(model_name=None):
    """
    Initializes and returns a pkg_info dictionary for the given model name.
    """
    return {
        "module_name": "",
        "apkg_temp": "",
        "bin_filename": "",
        "model_index": get_model_index_by_product_name(model_name),
        "signed": 0,
        "product_id": 0,
        "custom_id": 0,
        "model_id": 0,
        "app_id": 0,
        "apkg_version": 0,
        "enabled": 0,
        "user_control": 0,
        "center_type": 0,
        "individual_flag": 0,
        "packager": "",
        "email": "",
        "homepage": "",
        "name": "",
        "show": "",
        "ps_name": "",
        "path": "",
        "version": "",
        "date": "",
        "inst_date": "",
        "url": "",
        "url_port": "",
        "inst_depend": "",
        "inst_conflict": "",
        "start_depend": "",
        "start_conflict": "",
        "header_length": 0,
        "header_checksum": 0,
        "model_name": model_name,
    }

def verify_apkg_signature(pkg_info):
    """
    Creates a signature file using openssl for the package.
    """
    try:
        result = subprocess.run(
            "openssl version", shell=True, capture_output=True, text=True
        )
        openssl_version = result.stdout.strip().split()[1]
        major_version = openssl_version.split(".")[0]
    except Exception:
        major_version = "1"
        return 0

    name = pkg_info.get("name", "")
    key = "Lidho.mdk3K3h"
    if major_version == "3":
        cmd = f'echo "{name}" | openssl bf-cbc -md sha256 -out apkg.sign -k "{key}" -provider legacy -provider default'
    else:
        cmd = f'echo "{name}" | openssl bf-cbc -md sha256 -out apkg.sign -k "{key}"'

    print(f"***Running [{cmd}]")
    res = subprocess.run(cmd, shell=True)
    return (res.returncode == 0)

def create_apkg_temp_archive(pkg_info):
    """
    Creates a temporary tar.gz archive of the package folder.
    """
    temp_archive = pkg_info.get("apkg_temp", "../apkg_tar_tmp.tgz")
    try:
        os.remove(temp_archive)
    except FileNotFoundError:
        pass

    package_folder = os.path.basename(os.getcwd())
    cmd = f'cd ..; tar zcvf apkg_tar_tmp.tgz "{package_folder}"; cd "{package_folder}"'
    res = subprocess.run(cmd, shell=True)
    return os.path.isfile(temp_archive)

def read_file_checksum(file_path):
    """
    Calculates a XOR checksum of a file by reading blocks of 64KB.
    Only complete 4-byte groups are processed.
    Returns 0 on error.
    """
    try:
        with open(file_path, 'rb') as file:
            res = 0
            while True:
                chunk = file.read(0x10000)  # Read 64KB
                if not chunk:
                    break
                num_uints = len(chunk) // 4
                if num_uints == 0:
                    break
                for i in range(num_uints):
                    uint_val = int.from_bytes(chunk[i*4:(i+1)*4], byteorder='little')
                    res ^= uint_val
                if len(chunk) < 0x10000:
                    break
            return res & 0xFFFFFFFF  # Return 32-bit result
    except IOError as e:
        print(f"Error: Can't open {file_path} file !")
        return 0
    except Exception as e:
        print(f"Error reading file: {e}")
        return 0

def create_bin(pkg_info):
    """
    Creates the final binary package file by concatenating the header and archive.
    """
    import struct
    import subprocess

    bin_filename = f"../{pkg_info.get('model_name', 'model')}_{pkg_info.get('module_name', '')}_{pkg_info.get('version', '')}.bin({pkg_info.get('inst_date', '')})"
    pkg_info["bin_filename"] = bin_filename
    print(f"***[{bin_filename}]")

    header_tmp = "../apkg_header_tmp"
    try:
        with open(header_tmp, "wb") as f:
            # Write header fields with fixed sizes
            f.write(pkg_info.get("code_name", "").encode("utf-8").ljust(8, b"\x00"))
            f.write(pkg_info.get("package_name", "").encode("utf-8").ljust(68, b"\x00"))
            f.write(pkg_info.get("package_version", "").encode("utf-8").ljust(36, b"\x00"))
            f.write(struct.pack("<I", int(pkg_info.get("parsed_apkgrc", 0))))
            f.write(struct.pack("<I", int(pkg_info.get("product_id_2", 0))))
            f.write(struct.pack("<I", int(pkg_info.get("custom_id_2", 0))))
            f.write(struct.pack("<I", int(pkg_info.get("model_id_2", 0))))
            f.write(struct.pack("<I", int(pkg_info.get("app_id_2", 0))))
            f.write(struct.pack("<I", int(pkg_info.get("pkg_signed", 0))))
            f.write(b"\x00" * 0x3c)  # Padding
            f.write(struct.pack("<I", int(pkg_info.get("header_checksum", 0))))
            f.write(struct.pack("<I", int(pkg_info.get("header_length", 0))))
    except Exception as e:
        print(f"ERROR: can't create header file! ({e})", file=sys.stderr)
        return 0

    try:
        os.remove(bin_filename)
    except FileNotFoundError:
        pass

    cmd = f'cat {header_tmp} {pkg_info.get("apkg_temp", "../apkg_tar_tmp.tgz")} > "{bin_filename}"'
    res = subprocess.run(cmd, shell=True)
    try:
        os.remove(header_tmp)
    except FileNotFoundError:
        pass
    try:
        os.remove(pkg_info.get("apkg_temp", "../apkg_tar_tmp.tgz"))
    except FileNotFoundError:
        pass

    return 1 if res.returncode == 0 else 0

def print_package_info(pkg_info):
    """
    Prints summary information about the created package.
    """
    print()
    print(f"NAS type:\t\t{pkg_info.get('model_name', '')}")
    print(f"module name:\t\t{pkg_info.get('module_name', '')}")
    print(f"module version:\t\t{pkg_info.get('version', '')}")
    print(f"packager:\t\t{pkg_info.get('packager', '')}")
    print()
    print(f"header length:\t\t{pkg_info.get('header_length', 0)}")
    print(f"header checksum:\t{pkg_info.get('header_checksum', 0):X}")
    print()
    print(f"Add-ons \"{pkg_info.get('bin_filename', '')}\" create!\n")
    if pkg_info.get('signed', 0) == 0:
        print("\033[31;1m")
        print("WARNING: Addon has not been SIGNED for official release! Use '-s'.")
        print("\033[0m\n")

def main():
    """
    Main entry point for the package creation script.
    Parses arguments and runs the package creation steps.
    """
    parser = argparse.ArgumentParser(description="WD Package creation script")
    parser.add_argument('-E', action='store_true', help='Enabled package')
    parser.add_argument('-s', action='store_true', help='Signed package')
    parser.add_argument('-m', metavar='MODEL', type=str, help='Specify model name', required=True)
    parser.add_argument('-V', action='version', help='Show version and exit', version='%(prog)s 2.1')
    args = parser.parse_args()

    if not args.m:
        print("ERROR: model_name not specified", file=sys.stderr)
        sys.exit(1)

    # Initialize pkg_info
    pkg_info = create_pkg_info(model_name=args.m)
    if args.E:
        pkg_info["enabled"] = 1
    if args.s:
        pkg_info["signed"] = 1

    print("============================================")
    print(f"\t{sys.argv[0]} version: 2.1")
    print("============================================")

    # Main process
    if verify_scripts(pkg_info) == 1:
        if parse_apkgrc(pkg_info) == 1:
            create_xml_config(pkg_info)
            try:
                os.remove("apkg.sign")
            except FileNotFoundError:
                pass

            if pkg_info.get("signed", 0) == 0 or verify_apkg_signature(pkg_info) == 1:
                if create_apkg_temp_archive(pkg_info) == 1:
                    apkg_archive_filename = pkg_info.get("apkg_temp", "")
                    try:
                        pkg_info["header_length"] = os.path.getsize(apkg_archive_filename)
                    except (OSError, TypeError):
                        pkg_info["header_length"] = 0

                    if not apkg_archive_filename or not os.path.exists(apkg_archive_filename):
                        pkg_info["header_checksum"] = 0
                    else:
                        pkg_info["header_checksum"] = read_file_checksum(apkg_archive_filename)
                        if pkg_info["header_checksum"] != 0:
                            if create_bin(pkg_info) != 1:
                                print("ERROR: can't create ADD-ons!", file=sys.stderr)
                                sys.exit(-1)
                            print_package_info(pkg_info)
                            sys.exit(0)
                    print("ERROR: can't calculate checksum!", file=sys.stderr)
                    sys.exit(-1)
                else:
                    print("ERROR: tar command can't create tgz file!", file=sys.stderr)
                    sys.exit(-1)
            else:
                print("ERROR: can't create apkg sign!", file=sys.stderr)
                sys.exit(-1)
        else:
            print("ERROR: fail to read apkg.rc file!", file=sys.stderr)
            sys.exit(-1)
    else:
        print("ERROR: file missed or file path error!", file=sys.stderr)
        sys.exit(-1)


if __name__ == "__main__":
    main()