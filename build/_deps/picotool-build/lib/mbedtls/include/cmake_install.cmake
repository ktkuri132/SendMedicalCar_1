# Install script for directory: E:/pico-sdk/lib/mbedtls/include

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "E:/SendMedicalCar_1/build/_deps")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "E:/mingw64/bin/objdump.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/mbedtls" TYPE FILE MESSAGE_NEVER PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ FILES
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/aes.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/aesni.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/arc4.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/aria.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/asn1.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/asn1write.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/base64.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/bignum.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/blowfish.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/bn_mul.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/camellia.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/ccm.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/certs.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/chacha20.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/chachapoly.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/check_config.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/cipher.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/cipher_internal.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/cmac.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/compat-1.3.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/config.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/config_psa.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/constant_time.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/ctr_drbg.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/debug.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/des.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/dhm.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/ecdh.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/ecdsa.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/ecjpake.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/ecp.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/ecp_internal.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/entropy.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/entropy_poll.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/error.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/gcm.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/havege.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/hkdf.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/hmac_drbg.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/md.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/md2.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/md4.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/md5.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/md_internal.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/memory_buffer_alloc.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/net.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/net_sockets.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/nist_kw.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/oid.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/padlock.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/pem.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/pk.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/pk_internal.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/pkcs11.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/pkcs12.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/pkcs5.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/platform.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/platform_time.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/platform_util.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/poly1305.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/psa_util.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/ripemd160.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/rsa.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/rsa_internal.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/sha1.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/sha256.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/sha512.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/ssl.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/ssl_cache.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/ssl_ciphersuites.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/ssl_cookie.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/ssl_internal.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/ssl_ticket.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/threading.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/timing.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/version.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/x509.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/x509_crl.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/x509_crt.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/x509_csr.h"
    "E:/pico-sdk/lib/mbedtls/include/mbedtls/xtea.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/psa" TYPE FILE MESSAGE_NEVER PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ FILES
    "E:/pico-sdk/lib/mbedtls/include/psa/crypto.h"
    "E:/pico-sdk/lib/mbedtls/include/psa/crypto_builtin_composites.h"
    "E:/pico-sdk/lib/mbedtls/include/psa/crypto_builtin_primitives.h"
    "E:/pico-sdk/lib/mbedtls/include/psa/crypto_compat.h"
    "E:/pico-sdk/lib/mbedtls/include/psa/crypto_config.h"
    "E:/pico-sdk/lib/mbedtls/include/psa/crypto_driver_common.h"
    "E:/pico-sdk/lib/mbedtls/include/psa/crypto_driver_contexts_composites.h"
    "E:/pico-sdk/lib/mbedtls/include/psa/crypto_driver_contexts_primitives.h"
    "E:/pico-sdk/lib/mbedtls/include/psa/crypto_extra.h"
    "E:/pico-sdk/lib/mbedtls/include/psa/crypto_platform.h"
    "E:/pico-sdk/lib/mbedtls/include/psa/crypto_se_driver.h"
    "E:/pico-sdk/lib/mbedtls/include/psa/crypto_sizes.h"
    "E:/pico-sdk/lib/mbedtls/include/psa/crypto_struct.h"
    "E:/pico-sdk/lib/mbedtls/include/psa/crypto_types.h"
    "E:/pico-sdk/lib/mbedtls/include/psa/crypto_values.h"
    )
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "E:/SendMedicalCar_1/build/_deps/picotool-build/lib/mbedtls/include/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()