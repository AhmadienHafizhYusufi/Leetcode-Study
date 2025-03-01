# Height Checker

A school is trying to take an annual photo of all the students. The students are
asked to stand in a single file line in **non-decreasing** order by height. Let
this ordering be represented by the integer array `expected` where `expected[i]`
is the expected height of the i<sup>th</sup> student in line.

You are given an integer array `heights` representing the **current order** that
the students are standing in. Each `heights[i]` is the height of the
i<sup>th</sup> student in line **(0-indexed)**.

Return the **_number of indices_** where `heights[i]` != `expected[i]`.

### Example 1

```c++
Input: heights = [1,1,4,2,1,3]
Output: 3
Explanation:
heights:  [1,1,4,2,1,3]
expected: [1,1,1,2,3,4]
Indices 2, 4, and 5 do not match.
```

### Example 2

```c++
Input: heights = [5,1,2,3,4]
Output: 5
Explanation:
heights:  [5,1,2,3,4]
expected: [1,2,3,4,5]
All indices do not match.
```

### Example 3

```c++
Input: heights = [1,2,3,4,5]
Output: 0
Explanation:
heights:  [1,2,3,4,5]
expected: [1,2,3,4,5]
All indices match.
```

### Constraints

- `1 <= heights.length <= 100`
- `1 <= heights[i] <= 100`

## How To Solve

#### Memahami Soal

Diberikan array tidak urut, hitung jumlah indeks yang tidak urut dari bawah.

#### Cara Berpikir Algoritma

1. Buat fungsi `heightChecker()` dengan parameter `heights` yang merupakan array
   data, fungsi ini akan mengembalikan sebuah angka.
2. Buat variabel `jumlahIndeksTidakUrut` dan beri nilai awal 0.
3. Buat array `expected` yang merupakan salinan dari `heights` dan urutkan array
   tersebut.
4. Loop melalui seluruh indeks array `heights`:
   - Bandingkan elemen pada indeks saat ini di `heights` dengan elemen pada
     indeks yang sama di `expected`.
   - Jika elemen-elemen tersebut tidak sama, increment variabel
     `jumlahIndeksTidakUrut`.
5. Kembalikan nilai dari variabel `jumlahIndeksTidakUrut`.
