#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "base64.h"

unsigned char *encode_test_case[] = {
    "1",
    "a",
    "12",
    "ab",
    "123",
    "abc",
    "1234",
    "abcd",
    "123456789",
    "abcedfghi",
    "111111111",
    "vhotlx.video.qq.com",
    "vkplx.video.qq.com"
};

unsigned char *decode_test_case[] = {
    "MQ==",
    "YQ==",
    "MTI=",
    "YWI=",
    "MTIz",
    "YWJj",
    "MTIzNA==",
    "YWJjZA==",
    "MTIzNDU2Nzg5",
    "YWJjZWRmZ2hp",
    "MTExMTExMTEx",
    "dmhvdGx4LnZpZGVvLnFxLmNvbQ==",
    "dmtwbHgudmlkZW8ucXEuY29t",
};


int main(int argc, char **argv)
{
    int i;
    int src_len, dst_len;

    printf("%s\n", "test for base64 encode:");
    for(i = 0; i < (sizeof(encode_test_case)/sizeof(encode_test_case[0])); i++) {
        src_len = strlen(encode_test_case[i]);
        printf("%s\n", encode_test_case[i]);
    
        dst_len = base64_encoded_length(src_len);        
        unsigned char *dest = (unsigned char *)malloc(dst_len + 1);
        encode_base64(dest, encode_test_case[i], src_len);
        dest[dst_len] = '\0'; 
        printf("%s\n", dest);
        printf("%s\n", "----------------------------------------------------");
        free(dest);
    } 

    printf("\n");
    printf("%s\n", "test for base64 decode:");
    for(i = 0; i < (sizeof(decode_test_case)/sizeof(decode_test_case[0])); i++) {
        src_len = strlen(decode_test_case[i]);
        printf("%s\n", decode_test_case[i]);
    
        dst_len = base64_decoded_length(src_len);        
	printf("base64_decoded_length is %d\n", dst_len);
        unsigned char *dest = (unsigned char *)malloc(dst_len + 1);
        decode_base64(dest, &dst_len, decode_test_case[i], strlen(decode_test_case[i]));
	printf("real length is           %d\n", dst_len);
        dest[dst_len] = '\0'; 
        printf("%s\n", dest);
        printf("%s\n", "----------------------------------------------------");
        free(dest);
    }   

    return 0;
}
