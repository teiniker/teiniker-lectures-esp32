# Example: AES 256 using CBC Mode

Cipher Block Chaining (CBC) is a mode of operation for block ciphers. 
Unlike CTR mode, which turns a block cipher into a stream cipher, CBC mode 
continues to operate on blocks of plaintext and ciphertext. 

## Key Components
* Key: This is the secret key used for the encryption and decryption process.

* Initialization Vector (IV): This is a random value that's used to start off 
    the encryption process. It ensures that the same plaintext encrypted multiple 
    times under the same key will produce different ciphertexts.

## Encryption Process
* Initialization: Begin with an initialization vector (IV). The IV should be 
    random and unique for each encryption operation under the same key.

* Block Encryption:
    * For the first block:
        * XOR the plaintext block with the IV.
        * Encrypt the result using the block cipher with the secret key to produce 
            the first block of ciphertext.
    * For each subsequent block of plaintext:
        * XOR the plaintext block with the previous block of ciphertext.
        * Encrypt the result using the block cipher with the secret key to produce 
            the next block of ciphertext.
* Output: The concatenated blocks of ciphertext form the final encrypted data. 
    The IV must also be stored or sent alongside the ciphertext (but it doesn't 
    need to be kept secret).    

## Decryption Process
* Initialization: Begin with the same IV that was used for encryption.

* Block Decryption:
    * For the first block of ciphertext:
        * Decrypt the block using the block cipher with the secret key.
        * XOR the result with the IV to recover the first block of plaintext.
    * For each subsequent block of ciphertext:
        * Decrypt the block using the block cipher with the secret key.
        * XOR the result with the previous block of ciphertext to recover 
            the next block of plaintext.

* Output: The concatenated blocks of plaintext form the final decrypted data.    

## Security Considerations
* IV Uniqueness: The IV must be unique for each encryption operation under the same key. 
    While the IV does not need to be secret, it must be unpredictable. Often, it's 
    generated randomly for each encryption.

* Malleability: CBC mode is malleable, which means that without some form of authentication, 
    an attacker can modify the ciphertext in ways that produce predictable changes in the 
    decrypted plaintext.

* Padding: Since CBC operates on blocks, if the plaintext isn't a multiple of the block 
    size, it needs to be padded. This padding must be unambiguous and typically follows 
    a specific scheme, like PKCS#7 padding. Incorrect padding can introduce vulnerabilities.

To mitigate some of the security concerns of CBC, it's common to use it in conjunction with an authentication mode or construct, like HMAC, to ensure both confidentiality and integrity. 
This combined mode is often referred to as "Encrypt-then-MAC" (EtM), where the data is first 
encrypted and then an authentication tag is produced for the ciphertext.    

## Important Characteristics
* Chain Dependency: Each block of ciphertext depends on all the previous blocks of plaintext. 
    This means that a change in one block of plaintext will change all the following blocks of ciphertext.

* Error Propagation: If there's an error in one block of ciphertext, it will affect the 
    decryption of that block and the next block, but blocks after that will be correctly 
    decrypted.

* No Parallel Decryption: Due to the chaining nature, you can't decrypt block n without 
    first decrypting block n−1. However, encryption can be parallelized to some extent, 
    as you can precompute the XOR of each plaintext block with the previous ciphertext block.

## References
    