# Cryptography with ESP32

The **mbed TLS library** (previously known as PolarSSL) provides a comprehensive set 
of cryptographic algorithms. As of my last update in September 2021, here are the primary cryptographic algorithms supported by mbed TLS:

* Symmetric-Key Algorithms (Block and Stream Ciphers):
    * AES (with support for 128, 192, and 256-bit keys and various modes like ECB, CBC, CTR, GCM, and CCM)
    * ARC4
    * Camellia
    * DES (and 3DES)
    * Blowfish
    * Chacha20 and Poly1305 (often used together for AEAD - Authenticated Encryption with Associated Data)

* Hash Algorithms:
    * SHA-224, SHA-256, SHA-384, SHA-512
    * MD2, MD4, MD5
    * RIPEMD-160

* Message Authentication Codes (MACs):
    * HMAC (with various hash algorithms)
    * CMAC

* Public-Key Cryptography:
    * RSA (with PKCS#1 v1.5, PKCS#1 OEAP, and PSS)
    * Elliptic Curve Cryptography (ECC):
    * ECDSA (for digital signatures)
    * ECDH (for key agreement)
    * Diffie-Hellman (DH and ECDH)
    * Curve25519 and Curve448 (for ECDH and EdDSA)

* Key Derivation and Password-Based Cryptography:
    * PBKDF2
    * HKDF

* Random Number Generation:
    * Various platform-specific entropy sources
    * CTR-DRBG (Deterministic Random Bit Generator based on AES-CTR)

* SSL/TLS:
    * Support for SSL v3.0 (though it's insecure and should be avoided), TLS v1.0, v1.1, v1.2, and initial support for TLS v1.3.

* X.509:
    * Certificate parsing and writing
    * CRL (Certificate Revocation List) and CSR (Certificate Signing Request) support

* Miscellaneous:
    * GCM (Galois/Counter Mode) and CCM (Counter with CBC-MAC) modes for authenticated encryption
    * Various padding schemes for block ciphers
    * Hardware acceleration for some algorithms, if supported by the platform.

    



## References

