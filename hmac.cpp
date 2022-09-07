#include "hmac.h"
#include"md5.h"
hmac::hmac()
{

}
 void hmac::concatenate_and_md5(const void *data_1, size_t len_1, const void *data_2, size_t len_2, uint8_t *mac)
{
    MD5_CTX ctx;
    md5.MD5_Init(&ctx);
    md5.MD5_Update(&ctx, data_1, len_1);
    md5.MD5_Update(&ctx, data_2, len_2);
    md5.MD5_Final(mac, &ctx);
    memset(&ctx,0,sizeof(ctx));
}
void hmac::hmac_md5(const uint8_t *key, size_t key_len, const uint8_t *data, size_t data_len, uint8_t *mac)
{
    uint8_t padded_key[64] = {0};
      memcpy(padded_key, key, key_len);
      size_t i;
      for (i = 0; i < sizeof padded_key; ++i)
          padded_key[i] ^= 0x36;

      // Calculate the inner hash
      concatenate_and_md5(padded_key, sizeof padded_key, data, data_len, mac);

      // Calculate key ^ opad
      memset(padded_key, 0, sizeof padded_key);
      memcpy(padded_key, key, key_len);
      for (i = 0; i < sizeof padded_key; ++i)
          padded_key[i] ^= 0x5c;

      // Calculate the outer hash
      concatenate_and_md5(padded_key, sizeof padded_key, mac, MD5_MAC_LEN, mac);

      // Zero the stack memory used for keeping the key
     //explicit_bzero(padded_key, sizeof padded_key);
     memset(padded_key,0,sizeof(padded_key));
}
