# Example: Counter mode Deterministic Random Byte Generator (CTR_DRBG)

CTR_DRBG is based on block cipher algorithms in counter mode. The
"deterministic" part of the name indicates that given the same initial 
seed and the same sequence of inputs, it will always produce the same 
sequence of outputs. This deterministic behavior is a desired property 
for many cryptographic operations, as it allows for reproducibility in 
controlled conditions.

It's important to note that while the Pseudorandom Number Generator (PRNG) 
itself is deterministic, it's seeded with entropy from an entropy source 
(in this case, the mbedtls_entropy module), making the actual generated 
random numbers unpredictable in practice. 
The ESP32 hardware provides this entropy source.

CTR_DRBG, when properly seeded with sufficient entropy and used within 
its operational limits, is considered cryptographically secure and suitable 
for cryptographic operations.


## References
