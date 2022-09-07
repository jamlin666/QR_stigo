#ifndef MD5_H
#define MD5_H

#include <QMainWindow>
typedef unsigned int MD5_u32plus;
typedef struct {
        MD5_u32plus lo, hi;
        MD5_u32plus a, b, c, d;
        unsigned char buffer[64];
        MD5_u32plus block[16];
    } MD5_CTX;
class MD5
{
public:
    MD5();

  void MD5_Init(MD5_CTX *ctx);
  void MD5_Update(MD5_CTX *ctx, const void *data, unsigned long size);
  void MD5_Final(unsigned char *result, MD5_CTX *ctx);
   const unsigned char *body(MD5_CTX *ctx, const void *data, unsigned long size);
};

#endif // MD5_H
