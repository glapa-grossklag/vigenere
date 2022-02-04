# The Vigenère Cipher

```
bytes.h
	Bytes
	void bytes_print(Bytes bytes)
	Bytes slice(Bytes bytes, size_t start, size_t stop, size_t interval)

vigenere.h
	Bytes encrypt(Bytes plaintext, Bytes key)
	Bytes decrypt(Bytes ciphertext, Bytes key)

frequencies.h
	const double frequencies[256]

cryptanalysis.h
	size_t find_key_length(Bytes ciphertext)
```
