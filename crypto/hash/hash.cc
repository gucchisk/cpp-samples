#include <iostream>
#include <iomanip>
#include <string>
#include <openssl/evp.h>

void printBinary(const char *ch, const int32_t len) {
  for (int i = 0; i < len; i++) {
    std::cout << std::hex << std::setfill('0') << std::setw(2)
	      << static_cast<int>(static_cast<unsigned char>(ch[i])) << " ";
  }
  std::cout << std::endl;
}

void hash(const EVP_MD *md, const char *data, const int data_len, const char *key, const int key_len, unsigned char *value, unsigned int *len) {
  EVP_MD_CTX *ctx = EVP_MD_CTX_create();
  EVP_DigestInit_ex(ctx, md, NULL);
  EVP_DigestUpdate(ctx, data, data_len);
  EVP_DigestUpdate(ctx, key, key_len);
  EVP_DigestFinal_ex(ctx, value, len);
  EVP_MD_CTX_destroy(ctx);
}

int main(int argc, char* args[]) {
  if (argc != 4) {
    std::cout << "Usage: please set data & key &hashType" << std::endl;
    exit(1);
  }

  const char *data = args[1];
  const char *key = args[2];
  const char *hash_type = args[3];

  OpenSSL_add_all_digests();
  
  const EVP_MD *md = EVP_get_digestbyname(hash_type);
  if (md == NULL) {
    std::cout << "Unsupported hash type: " << hash_type  << std::endl;
    exit(1);
  }
  unsigned int size = EVP_MD_size(md);
  unsigned char value[size];

  hash(md, data, strlen(data), key, strlen(key), value, &size);

  printBinary((const char*)value, (int32_t)size);
  return 0;
}
