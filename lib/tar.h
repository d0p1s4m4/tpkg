#ifndef TPKG_TAR_H
# define TPKG_TAR_H 1

# include <stdint.h>

# define TAR_MAGIC "ustar"
# define TAR_VERSION "00"

# define TAR_TYPE_FLAG_REG     '0'
# define TAR_TYPE_FLAG_REG_ALT '\0'
# define TAR_TYPE_FLAG_LNK     '1'
# define TAR_TYPE_FLAG_CHR     '3'
# define TAR_TYPE_FLAG_BLK     '4'
# define TAR_TYPE_FLAG_DIR     '5'
# define TAR_TYPE_FLAG_FIFO    '6'

typedef struct
{
  uint8_t name[100];
  uint8_t mode[8];
  uint8_t uid[8];
  uint8_t gid[8];
  uint8_t size[12];
  uint8_t mtime[12];
  uint8_t chksum[8];
  uint8_t typeflag;
  uint8_t linkname[100];
  uint8_t magic[6];
  uint8_t uname[32];
  uint8_t gname[32];
  uint8_t devmajor[8];
  uint8_t devminor[8];
  uint8_t prefix[155];
  uint8_t pad[12];
} TarHdr;

int tar_extract(const char *name, const char sysroot);

#endif /* TPKG_TAR_H */
