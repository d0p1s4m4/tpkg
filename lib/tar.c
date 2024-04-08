#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "tar.h"

int
tar_extract(const char *name, const char sysroot)
{
  FILE *fp;

  fp = fopen(name, "rb");
  if (fp == NULL)
    {
      return (-1);
    }

  return (0);
}
