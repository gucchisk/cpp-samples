#include <iostream>
#include <openssl/evp.h>
#include <openssl/kdf.h>
#include <common.h>

int hkdf(const EVP_MD *md, const char *secret, const int secret_len, const unsigned char *salt, const int salt_len, const unsigned char *info, const int info_len, size_t key_len, const int iteration, unsigned char *key) {
  EVP_PKEY_CTX *ctx = EVP_PKEY_CTX_new_id(EVP_PKEY_HKDF, NULL);
  int result = 0;
  result = EVP_PKEY_derive_init(ctx);
  if (result <= 0) {
    return result;
  }
  result = EVP_PKEY_CTX_set_hkdf_md(ctx, md);
  if (result <= 0) {
    return result;
  }
  result = EVP_PKEY_CTX_set1_hkdf_salt(ctx, salt, salt_len);
  if (result <= 0) {
    return result;
  }
  result = EVP_PKEY_CTX_set1_hkdf_key(ctx, secret, secret_len);
  if (result <= 0) {
    return result;
  }
  result = EVP_PKEY_CTX_add1_hkdf_info(ctx, info, info_len);
  if (result <= 0) {
    return result;
  }
  return EVP_PKEY_derive(ctx, key, &key_len);
}

int main(int argc, char* args[]) {
  if (argc != 7) {
    std::cout << "Usage: please set secret & salt & info & key length & iteration & hashType" << std::endl;
    exit(1);
  }
  const char *secret = args[1];
  const char *salt = args[2];
  const char *info = args[3];
  const int key_len = atoi(args[4]);
  const int iteration = atoi(args[5]);
  const char *hash_type = args[6];

  OpenSSL_add_all_digests();

  const EVP_MD *md = EVP_get_digestbyname(hash_type);
  if (md == NULL) {
    std::cout << "Unsupported hash type: " << hash_type  << std::endl;
    exit(1);
  }

  unsigned char key[key_len];
  hkdf(md, secret, strlen(secret), (const unsigned char*)salt, strlen(salt), (const unsigned char*)info, strlen(info), key_len, iteration, key);

  printBinary((const char *)key, key_len);
  
  return 0;
}
