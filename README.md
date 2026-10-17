# Huffman Coding 🗜️

Implementation of **Huffman Coding** for text compression.

---

## 📖 Description
- Huffman Coding is a greedy algorithm used for lossless data compression.
- It assigns variable-length codes to characters based on frequency.
- More frequent characters get shorter codes, reducing overall storage size.

---

## 📂 Features
- Builds a frequency table from input text
- Constructs a Huffman Tree
- Generates prefix codes for each character
- Encodes and decodes text using Huffman codes

---

## ▶️ Compilation & Run
For C++:
```bash
g++ huffman.cpp -o huffman
./huffman
