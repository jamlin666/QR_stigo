#ifndef HMAC_H
#define HMAC_H

#include <QMainWindow>
#include <stdint.h>
#include <stddef.h>
#include"md5.h"
#define MD5_MAC_LEN 16
class hmac
{
public:
    hmac();
    MD5 md5;

     void concatenate_and_md5(const void *data_1, size_t len_1, const void *data_2, size_t len_2, uint8_t *mac);
    void hmac_md5(const uint8_t *key, size_t key_len, const uint8_t *data, size_t data_len, uint8_t *mac);

};

#endif // HMAC_H
