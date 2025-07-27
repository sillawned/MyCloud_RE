typedef unsigned char   undefined;

typedef unsigned char    bool;
typedef unsigned char    byte;
typedef unsigned char    dwfenc;
typedef unsigned int    dword;
typedef unsigned long    qword;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned char    undefined1;
typedef unsigned int    undefined4;
typedef unsigned long    undefined7;
typedef unsigned long    undefined8;
typedef unsigned short    ushort;
typedef unsigned short    word;
typedef struct PKG_INFO PKG_INFO, *PPKG_INFO;

struct PKG_INFO {
    char module_name[68];
    char apkg_temp[256];
    char bin_filename[256];
    int model_index;
    int signed;
    undefined field5_0x24c;
    undefined field6_0x24d;
    undefined field7_0x24e;
    undefined field8_0x24f;
    int product_id;
    int custom_id;
    int model_id;
    int app_id;
    int apkg_version;
    undefined field14_0x264;
    undefined field15_0x265;
    undefined field16_0x266;
    undefined field17_0x267;
    int enabled; /* Created by retype action */
    undefined field19_0x26c;
    undefined field20_0x26d;
    undefined field21_0x26e;
    undefined field22_0x26f;
    undefined field23_0x270;
    undefined field24_0x271;
    undefined field25_0x272;
    undefined field26_0x273;
    int user_control; /* Created by retype action */
    int center_type; /* Created by retype action */
    int individual_flag;
    undefined1 packager[36]; /* Created by retype action */
    undefined1 email[68]; /* Created by retype action */
    undefined1 homepage[68]; /* Created by retype action */
    undefined1 name[68]; /* Created by retype action */
    char show[68]; /* Created by retype action */
    char ps_name[68]; /* Created by retype action */
    char path[68]; /* Created by retype action */
    char version[36]; /* Created by retype action */
    char date-YYYYMMDD[20];
    char inst_date[20]; /* Created by retype action */
    undefined1 url[68]; /* Created by retype action */
    undefined1 url_port[20]; /* Created by retype action */
    char inst_depend[132]; /* Created by retype action */
    char inst_conflict[132]; /* Created by retype action */
    char start_depend[132]; /* Created by retype action */
    char start_conflict[132]; /* Created by retype action */
    undefined field46_0x6f0;
    undefined field47_0x6f1;
    undefined field48_0x6f2;
    undefined field49_0x6f3;
    undefined field50_0x6f4;
    undefined field51_0x6f5;
    undefined field52_0x6f6;
    undefined field53_0x6f7;
    undefined field54_0x6f8;
    undefined field55_0x6f9;
    undefined field56_0x6fa;
    undefined field57_0x6fb;
    undefined field58_0x6fc;
    undefined field59_0x6fd;
    undefined field60_0x6fe;
    undefined field61_0x6ff;
    undefined field62_0x700;
    undefined field63_0x701;
    undefined field64_0x702;
    undefined field65_0x703;
    undefined field66_0x704;
    undefined field67_0x705;
    undefined field68_0x706;
    undefined field69_0x707;
    undefined field70_0x708;
    undefined field71_0x709;
    undefined field72_0x70a;
    undefined field73_0x70b;
    undefined field74_0x70c;
    undefined field75_0x70d;
    undefined field76_0x70e;
    undefined field77_0x70f;
    undefined field78_0x710;
    undefined field79_0x711;
    undefined field80_0x712;
    undefined field81_0x713;
    undefined field82_0x714;
    undefined field83_0x715;
    undefined field84_0x716;
    undefined field85_0x717;
    undefined field86_0x718;
    undefined field87_0x719;
    undefined field88_0x71a;
    undefined field89_0x71b;
    undefined field90_0x71c;
    undefined field91_0x71d;
    undefined field92_0x71e;
    undefined field93_0x71f;
    undefined field94_0x720;
    undefined field95_0x721;
    undefined field96_0x722;
    undefined field97_0x723;
    undefined field98_0x724;
    undefined field99_0x725;
    undefined field100_0x726;
    undefined field101_0x727;
    undefined1 description[260]; /* Created by retype action */
    undefined1 icon[260]; /* Created by retype action */
    char date-MMDDYYYY[20];
    undefined1 MinFWVer[36]; /* Created by retype action */
    undefined1 MaxFWVer[36]; /* Created by retype action */
    undefined1 Hidden[36]; /* Created by retype action */
    undefined field108_0x9b0;
    undefined field109_0x9b1;
    undefined field110_0x9b2;
    undefined field111_0x9b3;
    undefined field112_0x9b4;
    undefined field113_0x9b5;
    undefined field114_0x9b6;
    undefined field115_0x9b7;
    char code_name[8];
    undefined1 Package2[68]; /* Created by retype action */
    undefined1 Version2[36]; /* Created by retype action */
    int field119_0xa28;
    qword field120_0xa2c;
    qword supported_flag;
    undefined4 pkg_signed;
    undefined field123_0xa40;
    undefined field124_0xa41;
    undefined field125_0xa42;
    undefined field126_0xa43;
    undefined field127_0xa44;
    undefined field128_0xa45;
    undefined field129_0xa46;
    undefined field130_0xa47;
    undefined field131_0xa48;
    undefined field132_0xa49;
    undefined field133_0xa4a;
    undefined field134_0xa4b;
    undefined field135_0xa4c;
    undefined field136_0xa4d;
    undefined field137_0xa4e;
    undefined field138_0xa4f;
    undefined field139_0xa50;
    undefined field140_0xa51;
    undefined field141_0xa52;
    undefined field142_0xa53;
    undefined field143_0xa54;
    undefined field144_0xa55;
    undefined field145_0xa56;
    undefined field146_0xa57;
    undefined field147_0xa58;
    undefined field148_0xa59;
    undefined field149_0xa5a;
    undefined field150_0xa5b;
    undefined field151_0xa5c;
    undefined field152_0xa5d;
    undefined field153_0xa5e;
    undefined field154_0xa5f;
    undefined field155_0xa60;
    undefined field156_0xa61;
    undefined field157_0xa62;
    undefined field158_0xa63;
    undefined field159_0xa64;
    undefined field160_0xa65;
    undefined field161_0xa66;
    undefined field162_0xa67;
    undefined field163_0xa68;
    undefined field164_0xa69;
    undefined field165_0xa6a;
    undefined field166_0xa6b;
    undefined field167_0xa6c;
    undefined field168_0xa6d;
    undefined field169_0xa6e;
    undefined field170_0xa6f;
    undefined field171_0xa70;
    undefined field172_0xa71;
    undefined field173_0xa72;
    undefined field174_0xa73;
    undefined field175_0xa74;
    undefined field176_0xa75;
    undefined field177_0xa76;
    undefined field178_0xa77;
    undefined field179_0xa78;
    undefined field180_0xa79;
    undefined field181_0xa7a;
    undefined field182_0xa7b;
    uint header_checksum;
    uint header_length;
    undefined field185_0xa84;
    undefined field186_0xa85;
    undefined field187_0xa86;
    undefined field188_0xa87;
};

typedef struct Elf64_Dyn Elf64_Dyn, *PElf64_Dyn;

typedef enum Elf64_DynTag {
    DT_NULL=0,
    DT_NEEDED=1,
    DT_PLTRELSZ=2,
    DT_PLTGOT=3,
    DT_HASH=4,
    DT_STRTAB=5,
    DT_SYMTAB=6,
    DT_RELA=7,
    DT_RELASZ=8,
    DT_RELAENT=9,
    DT_STRSZ=10,
    DT_SYMENT=11,
    DT_INIT=12,
    DT_FINI=13,
    DT_SONAME=14,
    DT_RPATH=15,
    DT_SYMBOLIC=16,
    DT_REL=17,
    DT_RELSZ=18,
    DT_RELENT=19,
    DT_PLTREL=20,
    DT_DEBUG=21,
    DT_TEXTREL=22,
    DT_JMPREL=23,
    DT_BIND_NOW=24,
    DT_INIT_ARRAY=25,
    DT_FINI_ARRAY=26,
    DT_INIT_ARRAYSZ=27,
    DT_FINI_ARRAYSZ=28,
    DT_RUNPATH=29,
    DT_FLAGS=30,
    DT_PREINIT_ARRAY=32,
    DT_PREINIT_ARRAYSZ=33,
    DT_RELRSZ=35,
    DT_RELR=36,
    DT_RELRENT=37,
    DT_ANDROID_REL=1610612751,
    DT_ANDROID_RELSZ=1610612752,
    DT_ANDROID_RELA=1610612753,
    DT_ANDROID_RELASZ=1610612754,
    DT_ANDROID_RELR=1879040000,
    DT_ANDROID_RELRSZ=1879040001,
    DT_ANDROID_RELRENT=1879040003,
    DT_GNU_PRELINKED=1879047669,
    DT_GNU_CONFLICTSZ=1879047670,
    DT_GNU_LIBLISTSZ=1879047671,
    DT_CHECKSUM=1879047672,
    DT_PLTPADSZ=1879047673,
    DT_MOVEENT=1879047674,
    DT_MOVESZ=1879047675,
    DT_FEATURE_1=1879047676,
    DT_POSFLAG_1=1879047677,
    DT_SYMINSZ=1879047678,
    DT_SYMINENT=1879047679,
    DT_GNU_XHASH=1879047924,
    DT_GNU_HASH=1879047925,
    DT_TLSDESC_PLT=1879047926,
    DT_TLSDESC_GOT=1879047927,
    DT_GNU_CONFLICT=1879047928,
    DT_GNU_LIBLIST=1879047929,
    DT_CONFIG=1879047930,
    DT_DEPAUDIT=1879047931,
    DT_AUDIT=1879047932,
    DT_PLTPAD=1879047933,
    DT_MOVETAB=1879047934,
    DT_SYMINFO=1879047935,
    DT_VERSYM=1879048176,
    DT_RELACOUNT=1879048185,
    DT_RELCOUNT=1879048186,
    DT_FLAGS_1=1879048187,
    DT_VERDEF=1879048188,
    DT_VERDEFNUM=1879048189,
    DT_VERNEED=1879048190,
    DT_VERNEEDNUM=1879048191,
    DT_AUXILIARY=2147483645,
    DT_FILTER=2147483647
} Elf64_DynTag;

struct Elf64_Dyn {
    enum Elf64_DynTag d_tag;
    qword d_val;
};

typedef struct Elf64_Ehdr Elf64_Ehdr, *PElf64_Ehdr;

struct Elf64_Ehdr {
    byte e_ident_magic_num;
    char e_ident_magic_str[3];
    byte e_ident_class;
    byte e_ident_data;
    byte e_ident_version;
    byte e_ident_osabi;
    byte e_ident_abiversion;
    byte e_ident_pad[7];
    word e_type;
    word e_machine;
    dword e_version;
    qword e_entry;
    qword e_phoff;
    qword e_shoff;
    dword e_flags;
    word e_ehsize;
    word e_phentsize;
    word e_phnum;
    word e_shentsize;
    word e_shnum;
    word e_shstrndx;
};

typedef struct Elf64_Phdr Elf64_Phdr, *PElf64_Phdr;

typedef enum Elf_ProgramHeaderType {
    PT_NULL=0,
    PT_LOAD=1,
    PT_DYNAMIC=2,
    PT_INTERP=3,
    PT_NOTE=4,
    PT_SHLIB=5,
    PT_PHDR=6,
    PT_TLS=7,
    PT_GNU_EH_FRAME=1685382480,
    PT_GNU_STACK=1685382481,
    PT_GNU_RELRO=1685382482
} Elf_ProgramHeaderType;

struct Elf64_Phdr {
    enum Elf_ProgramHeaderType p_type;
    dword p_flags;
    qword p_offset;
    qword p_vaddr;
    qword p_paddr;
    qword p_filesz;
    qword p_memsz;
    qword p_align;
};

typedef struct Elf64_Rela Elf64_Rela, *PElf64_Rela;

struct Elf64_Rela {
    qword r_offset; /* location to apply the relocation action */
    qword r_info; /* the symbol table index and the type of relocation */
    qword r_addend; /* a constant addend used to compute the relocatable field value */
};

typedef struct Elf64_Shdr Elf64_Shdr, *PElf64_Shdr;

typedef enum Elf_SectionHeaderType {
    SHT_NULL=0,
    SHT_PROGBITS=1,
    SHT_SYMTAB=2,
    SHT_STRTAB=3,
    SHT_RELA=4,
    SHT_HASH=5,
    SHT_DYNAMIC=6,
    SHT_NOTE=7,
    SHT_NOBITS=8,
    SHT_REL=9,
    SHT_SHLIB=10,
    SHT_DYNSYM=11,
    SHT_INIT_ARRAY=14,
    SHT_FINI_ARRAY=15,
    SHT_PREINIT_ARRAY=16,
    SHT_GROUP=17,
    SHT_SYMTAB_SHNDX=18,
    SHT_ANDROID_REL=1610612737,
    SHT_ANDROID_RELA=1610612738,
    SHT_GNU_ATTRIBUTES=1879048181,
    SHT_GNU_HASH=1879048182,
    SHT_GNU_LIBLIST=1879048183,
    SHT_CHECKSUM=1879048184,
    SHT_SUNW_move=1879048186,
    SHT_SUNW_COMDAT=1879048187,
    SHT_SUNW_syminfo=1879048188,
    SHT_GNU_verdef=1879048189,
    SHT_GNU_verneed=1879048190,
    SHT_GNU_versym=1879048191
} Elf_SectionHeaderType;

struct Elf64_Shdr {
    dword sh_name;
    enum Elf_SectionHeaderType sh_type;
    qword sh_flags;
    qword sh_addr;
    qword sh_offset;
    qword sh_size;
    dword sh_link;
    dword sh_info;
    qword sh_addralign;
    qword sh_entsize;
};

typedef struct Elf64_Sym Elf64_Sym, *PElf64_Sym;

struct Elf64_Sym {
    dword st_name;
    byte st_info;
    byte st_other;
    word st_shndx;
    qword st_value;
    qword st_size;
};

typedef struct GnuBuildId GnuBuildId, *PGnuBuildId;

struct GnuBuildId {
    dword namesz; /* Length of name field */
    dword descsz; /* Length of description field */
    dword type; /* Vendor specific type */
    char name[4]; /* Vendor name */
    byte hash[20];
};

typedef struct NoteAbiTag NoteAbiTag, *PNoteAbiTag;

struct NoteAbiTag {
    dword namesz; /* Length of name field */
    dword descsz; /* Length of description field */
    dword type; /* Vendor specific type */
    char name[4]; /* Vendor name */
    dword abiType; /* 0 == Linux */
    dword requiredKernelVersion[3]; /* Major.minor.patch */
};

typedef void _IO_lock_t;

typedef struct _IO_marker _IO_marker, *P_IO_marker;

typedef struct _IO_FILE _IO_FILE, *P_IO_FILE;

typedef long __off_t;

typedef long __off64_t;

typedef ulong size_t;

struct _IO_FILE {
    int _flags;
    char *_IO_read_ptr;
    char *_IO_read_end;
    char *_IO_read_base;
    char *_IO_write_base;
    char *_IO_write_ptr;
    char *_IO_write_end;
    char *_IO_buf_base;
    char *_IO_buf_end;
    char *_IO_save_base;
    char *_IO_backup_base;
    char *_IO_save_end;
    struct _IO_marker *_markers;
    struct _IO_FILE *_chain;
    int _fileno;
    int _flags2;
    __off_t _old_offset;
    ushort _cur_column;
    char _vtable_offset;
    char _shortbuf[1];
    _IO_lock_t *_lock;
    __off64_t _offset;
    void *__pad1;
    void *__pad2;
    void *__pad3;
    void *__pad4;
    size_t __pad5;
    int _mode;
    char _unused2[20];
};

struct _IO_marker {
    struct _IO_marker *_next;
    struct _IO_FILE *_sbuf;
    int _pos;
};

typedef struct _xmlDoc _xmlDoc, *P_xmlDoc;

typedef enum xmlElementType {
    XML_ELEMENT_NODE=0,
    XML_ATTRIBUTE_NODE=1,
    XML_TEXT_NODE=2
} xmlElementType;

typedef struct _xmlNode _xmlNode, *P_xmlNode;

typedef struct _xmlDtd _xmlDtd, *P_xmlDtd;

typedef struct _xmlNs _xmlNs, *P_xmlNs;

typedef uchar xmlChar;

struct _xmlDoc {
    void *_private;
    enum xmlElementType type;
    char *name;
    struct _xmlNode *children;
    struct _xmlNode *last;
    struct _xmlNode *parent;
    struct _xmlNode *next;
    struct _xmlNode *prev;
    struct _xmlDoc *doc; /* Ref to itself */
    int compression;
    int standalone;
    struct _xmlDtd *intSubset;
    struct _xmlDtd *extSubset;
    struct _xmlNs *oldNs;
    xmlChar *version;
    xmlChar *encoding;
    void *ids;
    void *refs;
    xmlChar *URL;
    int charset;
};

struct _xmlNs {
    undefined field0_0x0;
};

struct _xmlNode {
    undefined field0_0x0;
};

struct _xmlDtd {
    undefined field0_0x0;
};

typedef struct _xmlDoc xmlDoc;

typedef struct stat stat, *Pstat;

typedef ulong __dev_t;

typedef ulong __ino_t;

typedef ulong __nlink_t;

typedef uint __mode_t;

typedef uint __uid_t;

typedef uint __gid_t;

typedef long __blksize_t;

typedef long __blkcnt_t;

typedef struct timespec timespec, *Ptimespec;

typedef long __time_t;

struct timespec {
    __time_t tv_sec;
    long tv_nsec;
};

struct stat {
    __dev_t st_dev;
    __ino_t st_ino;
    __nlink_t st_nlink;
    __mode_t st_mode;
    __uid_t st_uid;
    __gid_t st_gid;
    int __pad0;
    __dev_t st_rdev;
    __off_t st_size;
    __blksize_t st_blksize;
    __blkcnt_t st_blocks;
    struct timespec st_atim;
    struct timespec st_mtim;
    struct timespec st_ctim;
    long __unused[3];
};

typedef struct _IO_FILE FILE;

typedef __time_t time_t;

typedef struct tm tm, *Ptm;

struct tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
    long tm_gmtoff;
    char *tm_zone;
};

typedef long __ssize_t;

typedef long int64_t;

typedef __ssize_t ssize_t;

typedef struct eh_frame_hdr eh_frame_hdr, *Peh_frame_hdr;

struct eh_frame_hdr {
    byte eh_frame_hdr_version; /* Exception Handler Frame Header Version */
    dwfenc eh_frame_pointer_encoding; /* Exception Handler Frame Pointer Encoding */
    dwfenc eh_frame_desc_entry_count_encoding; /* Encoding of # of Exception Handler FDEs */
    dwfenc eh_frame_table_encoding; /* Exception Handler Table Encoding */
};

typedef struct fde_table_entry fde_table_entry, *Pfde_table_entry;

struct fde_table_entry {
    dword initial_loc; /* Initial Location */
    dword data_loc; /* Data location */
};

typedef unsigned short    wchar16;
typedef struct wd_models wd_models, *Pwd_models;

struct wd_models {
    char code_name[8];
    char product_name[16];
    dword field2_0x18;
    qword field3_0x1c;
    qword supported_flag;
    dword field5_0x2c;
};

