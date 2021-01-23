#include <iostream>
#include <common.h>
#include <openssl/evp.h>

void pbkdf2(const EVP_MD *md, const char *secret, const int secret_len, const unsigned char *salt, const int salt_len, int key_len, const int iteration, unsigned char *key) {
  PKCS5_PBKDF2_HMAC(secret, secret_len, salt, salt_len, iteration, md, key_len, key);
}

int main(int argc, char* args[]) {
  if (argc != 6) {
    std::cout << "Usage: please set secret & salt & key length & iteration & hashType" << std::endl;
    exit(1);
  }
  const char *secret = args[1];
  const char *salt = args[2];
  const int key_len = atoi(args[3]);
  const int iteration = atoi(args[4]);
  const char *hash_type = args[5];

  OpenSSL_add_all_digests();

  const EVP_MD *md = EVP_get_digestbyname(hash_type);
  if (md == NULL) {
    std::cout << "Unsupported hash type: " << hash_type  << std::endl;
    exit(1);
  }

  unsigned char key[key_len];
  pbkdf2(md, secret, strlen(secret), (const unsigned char*)salt, strlen(salt), key_len, iteration, key);

  printBinary((const char *)key, key_len);
  
  return 0;
}

