#ifndef _BASE64_H
#define _BASE64_H

#define base64_encoded_length(len) (((len + 2) / 3) * 4)
#define base64_decoded_length(len) (((len + 3) / 4) * 3)

void encode_base64(unsigned char *dst, unsigned char *src, unsigned int src_len);
int decode_base64(unsigned char *dst, unsigned int *dest_len, unsigned char *src, unsigned int src_len);

#endif

