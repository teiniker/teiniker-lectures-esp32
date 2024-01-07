# Example: Message Authentication Code HMAC-SHA256

HMAC (Hash-based Message Authentication Code) is a specific 
construction for creating a message authentication code (MAC) 
involving a cryptographic hash function in combination with 
a secret key. It can be used to ensure both integrity and 
authenticity.

## HMAC Algorithm

Given:
* K is the secret key.
* m is the message to be authenticated.
* Hash is a cryptographic hash function, like SHA-256.
* ⊕ denotes the bitwise XOR operation.
* B is the block size of the hash function in bytes (e.g., 64 bytes for SHA-256).
* L is the output length of the hash function in bytes (e.g., 32 bytes for SHA-256).
* ipad is the inner padding constant, which is a block-sized value where every 
    byte is the value 0x36.
* opad is the outer padding constant, which is a block-sized value where every byte 
    is the value 0x5C.

Algorithm: 
* Key Preparation:
    * If K is longer than B bytes, hash it using Hash and use the resultant L bytes as the key. 
    K = Hash(K)
    * If K is shorter than B bytes, pad it with zeros on the right until it is B bytes long.
    * The result from the above two steps will be a B-byte long key.

* Inner Hash:
    * Compute K⊕ipad, which is the bitwise XOR of the B-byte key with ipad.
    * Hash the result of the XOR operation concatenated with the message m: 
    Hash((K⊕ipad)∣∣m).

* Outer Hash:
    * Compute K⊕opad, which is the bitwise XOR of the B-byte key with opad.
    * Hash the result of the XOR operation concatenated with the hash output 
    from step 2: Hash((K⊕opad)∣∣Hash((K⊕ipad)∣∣m)).

* Output: The result from step 3 is the HMAC value.

The reason for the dual use of the hash function with two different padded 
keys (inner and outer) is to ensure security. The design defends against 
certain attack vectors on hash functions and ensures that even if certain 
weaknesses are found in the underlying hash function, the HMAC construction 
remains secure.

## Security Considerations
HMAC is considered secure provided that:
* The underlying hash function is cryptographically secure.

* The secret key K is chosen randomly and kept confidential.

* The secret key is refreshed or rotated periodically, especially if used frequently.

In essence, HMAC provides a way to ensure both the authenticity and 
integrity of a message using a shared secret key and a cryptographic hash function.

## Important Characteristics

* Integrity: The HMAC value will change if even a single bit in the 
    original message changes. Since an attacker doesn't know the secret 
    key, they cannot produce the correct HMAC for a modified message.

* Authenticity: Since the HMAC value depends on the secret key, only 
    someone who knows the key can produce the correct HMAC. This allows 
    the receiver to verify that the message came from a sender possessing 
    the secret key.
