about
=====
This base64 implemention is borrowed from nginx source code, which are ngx_decode_base64 and ngx_encode_base64 in ngx_string.c

Usage
=====
1. encode_base64 

	unsigned char *src= "xxxxx";	
	int src_len = strlen(src);
	int dst_len = base64_encoded_length(src_len);
        unsigned char *dest = (unsigned char *)malloc(dst_len + 1);
        encode_base64(dest, src, src_len);
        dest[dst_len] = '\0';
	......
	free(dest);

2. decode_base64

	unsigned char *src = "xxxxxx";
	int src_len = strlen(src);
	int dst_len = base64_decoded_length(src_len);
        unsigned char *dest = (unsigned char *)malloc(dst_len + 1);
        decode_base64(dest, &dst_len, src, src_len);
        dest[dst_len] = '\0';
	......
	free(dest);

